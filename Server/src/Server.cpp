#include "Server.h"
#include <Windows.h>

Server::Server(std::string const & ip, std::string const & port)
	: _network(getNetworkInstance()), _dataHandler(new ClientDataHandler("storage_file.xml", 0)), _ip(ip), _port(port)
{
	_baseID = 0;
	InitNetwork();
	InitFuncMap();
	Start();
}

Server::~Server()
{
}

void				Server::InitNetwork()
{
	MyConnectionData*	conData;

	_network->initNetwork();
	conData = _network->getAddr(_ip.c_str(), _port.c_str(), AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP, AI_PASSIVE);
	_listen = _network->MySocketFunc(conData);
	_network->MyBindFunc(_listen, conData);
	_network->MyListenFunc(_listen);
}

void				Server::InitFuncMap()
{
	_funcMap.emplace("LOGIN", &Server::Login);
	_funcMap.emplace("PASS", &Server::Password);
	_funcMap.emplace("NICK", &Server::Nick);
	_funcMap.emplace("GETCINFO", &Server::GetCInfo);
	_funcMap.emplace("GETCLIST", &Server::GetCList);
	_funcMap.emplace("RQ_CALL", &Server::RequestCall);
	_funcMap.emplace("ACPT_CALL", &Server::AcceptCall);
	_funcMap.emplace("REFU_CALL", &Server::RefuseCall);
	_keyVector.push_back("LOGIN");
	_keyVector.push_back("PASS");
	_keyVector.push_back("NICK");
	_keyVector.push_back("GETCINFO");
	_keyVector.push_back("GETCLIST");
	_keyVector.push_back("RQ_CALL");
	_keyVector.push_back("ACPT_CALL");
	_keyVector.push_back("REFU_CALL");
}

void				Server::Start(void)
{
	while (1)
	{
		SetClientFD();
		_network->MySelectFunc(_listen, _readSet);
		if (_network->CheckFdIsSet(_listen, _readSet))
			StartNewClient();
		CheckClientQueue();
	}
}
 
void				Server::SetClientFD()
{
	_network->ZeroFD(_readSet);
	_network->SetFD(_listen, _readSet);
	for (std::deque<ClientRuntime*>::iterator it = _dataRuntime.begin(); it != _dataRuntime.end(); ++it)
	{
		_network->SetFD((*it)->getSocket(), _readSet);
	}
}

void				Server::CheckClientQueue()
{
	for (std::deque<ClientRuntime*>::iterator it = _dataRuntime.begin(); it != _dataRuntime.end(); ++it)
	{
		if (_network->CheckFdIsSet((*it)->getSocket(), _readSet))
			CommandParser((*it), _network->rcvMessage((*it)->getSocket()));
	}
}

void				Server::CommandParser(ClientRuntime* client, std::string& input)
{
	std::string		command(input.substr(0, input.find(" ")));
	std::string		args;

	if (input.find(" ") != std::string::npos)
		args = (input.substr(input.find(" ") + 1, input.length() - input.find(" ") - 1));
	else
		args = "";

	if (CheckCommand(command))
		(this->*_funcMap[command])(client, args);
	else
		_network->sendMessage("103", client->getSocket());
}

MySocket Server::TryAcceptClient()
{
	MySocket			socket;
	struct sockaddr_in	client_sin;
	socklen_t			client_sin_len;

	client_sin_len = sizeof(client_sin);
	if ((socket = accept(_listen, (struct sockaddr*)&client_sin, &client_sin_len)) == -1)
	{
		std::cout << "Error accept :" << std::endl;
		return -1;
	}
	return socket;
}

bool Server::CheckCommand(std::string& str)
{
	for (std::vector<std::string>::iterator it = _keyVector.begin(); it != _keyVector.end(); ++it)
	{
		if ((*it) == str)
			return true;
	}
	return false;
}

void				Server::StartNewClient()
{
	MySocket		socket = TryAcceptClient();

	std::cout << "start" << std::endl;
	if (socket != -1)
		_dataRuntime.push_front(new ClientRuntime(socket));
}

/* BUILTIN */

void Server::Login(ClientRuntime* client, std::string& args)
{
	_dataHandler->LoginIsSet(args, client, _dataBase);
	_network->sendMessage("100", client->getSocket());
}

void Server::Password(ClientRuntime* client, std::string& args)
{
	if (_dataHandler->IsRightPassword(args, client, _dataBase))
	{
		std::string msg = "300 " + std::to_string(client->getBase()->getId()) + " " + client->getBase()->getNickname() + " " + std::to_string(client->getBase()->getStatus());
		_network->sendMessage("200", client->getSocket());
		_network->sendMessage(msg.c_str(), client->getSocket());
	}
	else
		_network->sendMessage("201", client->getSocket());
}

void Server::Nick(ClientRuntime* client, std::string& args)
{
	client->getBase()->setNickname(args);
	_network->sendMessage("100", client->getSocket());
}

void Server::GetCInfo(ClientRuntime* client, std::string& args)
{

	_network->sendMessage("INSIDE getcinfo", client->getSocket());
}

void Server::GetCList(ClientRuntime* client, std::string& args)
{
	_network->sendMessage("INSIDE getclist", client->getSocket());
}

void Server::RequestCall(ClientRuntime* client, std::string& args)
{
	_network->sendMessage("INSIDE requestcall", client->getSocket());
}

void Server::AcceptCall(ClientRuntime* client, std::string& args)
{
	_network->sendMessage("INSIDE lzodo", client->getSocket());
}

void Server::RefuseCall(ClientRuntime* client, std::string& args)
{
}
