#include "Server.h"
#include <Windows.h>
#include <Algorithm>
#include <string>

Server::Server(std::string const & ip, std::string const & port)
	: _network(getNetworkInstance()), _cPacket(new ClientPacket()), _dataHandler(new ClientDataHandler("storage_file.xml", 0)), _ip(ip), _port(port)
{
	_baseID = 0;
	InitNetwork();
	InitFuncMap();
	Start();
}

Server::~Server()
{
}

bool				Server::InitNetwork()
{
	MyConnectionData*	conData;

	_network->initNetwork();
	if ((conData = _network->getAddr(NULL, _port.c_str(), AF_INET, SOCK_STREAM, IPPROTO_TCP, AI_PASSIVE)) == NULL)
		return false;
	if ((_listen = _network->MySocketFunc(conData)) == INVALID_SOCKET)
		return false;
	if (!_network->MyBindFunc(_listen, conData) || _network->MyListenFunc(_listen) == 0)
		return false;
	return true;
}

void				Server::InitFuncMap()
{
	_funcMap.emplace(AUTH, &Server::Login);
	_funcMap.emplace(NICKNAME, &Server::Nick);
	_funcMap.emplace(GETCLIST, &Server::GetCList);
	_funcMap.emplace(RQ_CALL, &Server::RequestCall);
	_funcMap.emplace(ACPT_CALL, &Server::AcceptCall);
	_funcMap.emplace(REFU_CALL, &Server::RefuseCall);
	_keyVector.push_back(AUTH);
	_keyVector.push_back(NICKNAME);
	_keyVector.push_back(GETCLIST);
	_keyVector.push_back(RQ_CALL);
	_keyVector.push_back(ACPT_CALL);
	_keyVector.push_back(REFU_CALL);
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
		{
			_network->rcvMessage((*it)->getSocket(), _cPacket, sizeof(*_cPacket));/*
			std::cout << "paquet " << _cPacket->data.Auth.username << std::endl;*/
			if (_cPacket == NULL)
				CloseClient((*it));
			CommandParser((*it));
		}
	}
}

void				Server::CloseClient(ClientRuntime* client)
{
	_network->CloseConnection(client->getSocket());
	_dataRuntime.erase(std::find(_dataRuntime.begin(), _dataRuntime.end(), client));
}

void				Server::CommandParser(ClientRuntime* client)
{
	if (CheckCommand(_cPacket->command))
		(this->*_funcMap[_cPacket->command])(client);
	else
	{
		_sPacket->response = 103;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
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

bool Server::CheckCommand(ClientNetworkCommand command)
{
	for (std::vector<ClientNetworkCommand>::iterator it = _keyVector.begin(); it != _keyVector.end(); ++it)
	{
		if ((*it) == command)
			return true;
	}
	return false;
}

void				Server::StartNewClient()
{
	MySocket		socket = TryAcceptClient();

	if (socket != -1)
		_dataRuntime.push_front(new ClientRuntime(socket));
	std::cout << "start new client , fd = " << socket << std::endl;
}

/* BUILTIN */

void Server::Login(ClientRuntime* client)
{
	_dataHandler->LoginIsSet(_cPacket->data.Auth.username, client, _dataBase);
	if (_dataHandler->IsRightPassword(_cPacket->data.Auth.password, client, _dataBase))
	{
		_sPacket->response = 200;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
		GetCInfo(client);
	}
	else
	{
		_sPacket->response = 201;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
}

void Server::Nick(ClientRuntime* client)
{
	if (!client->isLoggedIn())
	{
		_sPacket->response = 102;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
	else
	{
		client->getBase()->setNickname(_cPacket->data.Nick.nick);
		_sPacket->response = 100;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
}

void Server::GetCInfo(ClientRuntime* client)
{
	_sPacket->response = 300;
	_sPacket->data.GetCtInfo.id = client->getBase()->getId();
	strncpy_s(_sPacket->data.GetCtInfo.nickname, client->getBase()->getNickname().c_str(), client->getBase()->getNickname().size());
	_sPacket->data.GetCtInfo.status = client->getBase()->getClientStatus();
	_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
}

void Server::GetCList(ClientRuntime* client)
{
	if (!client->isLoggedIn())
	{
		_sPacket->response = 102;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
	else
	{
		_sPacket->response = 301;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
		for (std::deque<ClientRuntime*>::iterator it = _dataRuntime.begin(); it != _dataRuntime.end(); ++it)
			GetCInfo((*it));
		_sPacket->response = 302;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
}

void Server::RequestCall(ClientRuntime* client)
{
	if (!client->isLoggedIn())
	{
		_sPacket->response = 102;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
	else
	{
		_sPacket->response = 400;
		_sPacket->data.RequestCallerInfo.id = client->getBase()->getId();
		_network->sendMessage(_sPacket, sizeof(*_sPacket), _cPacket->data.rq_call.id);
	}
}

void Server::AcceptCall(ClientRuntime* client)
{
	if (!client->isLoggedIn())
	{
		_sPacket->response = 102;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
	else
	{
		_sPacket->response = 401;
		_sPacket->data.GetCallerInfo.id = _cPacket->data.acpt_call.id;
		strncpy_s(_sPacket->data.GetCallerInfo.ip, _cPacket->data.acpt_call.ip, strlen(_cPacket->data.acpt_call.ip));
		strncpy_s(_sPacket->data.GetCallerInfo.port, (char*)_cPacket->data.acpt_call.port, sizeof(int));
	}
}

void Server::RefuseCall(ClientRuntime* client)
{
	if (!client->isLoggedIn())
	{
		_sPacket->response = 102;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
	else
	{
		_sPacket->response = 402;
		_sPacket->data.GetCallerInfo.id = _cPacket->data.acpt_call.id;
		_network->sendMessage(_sPacket, sizeof(*_sPacket), client->getSocket());
	}
}
