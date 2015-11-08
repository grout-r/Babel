# include "ServerLink.h"

ServerLink::ServerLink()
{
	_net = getNetworkInstance();
	_serverSocket = -1;
}

ServerLink::~ServerLink()
{

}

bool ServerLink::connect(std::string ip, std::string port)
{
	_net->initNetwork();
	if ((_conData = _net->getAddr(ip.c_str(), port.c_str(),
		AF_UNSPEC, SOCK_STREAM, IPPROTO_TCP, 0)) == NULL)
		return false;
	if ((_serverSocket = _net->MySocketFunc(_conData)) == INVALID_SOCKET)
	{
		_serverSocket = -1;
		return false;
	}
	if ((_net->MyConnectFunc(_serverSocket, _conData)) == false)
	{
		_serverSocket = -1;
		return false;
	}
//	send(_serverSocket, "test", strlen("test"), 0);
	return true;
}

bool ServerLink::login(std::string login)
{
	ClientPacket *packet = new ClientPacket;

	if (_serverSocket)
	memset(packet, 0, sizeof(*packet));
	packet->command = AUTH;
	memset(packet->data.Auth.username, 0, sizeof(packet->data.Auth.username));
	strncpy(packet->data.Auth.username, login.c_str(), login.size());
	if (_net->sendMessage(packet, sizeof(*packet), _serverSocket) == false)
		return false;
	checkResponse();
	return true;
}

bool ServerLink::nickname(std::string login)
{
	ClientPacket *packet = new ClientPacket;

	memset(packet, 0, sizeof(*packet));
	packet->command = NICKNAME;
	memset(packet->data.Nick.nick, 0, sizeof(packet->data.Nick.nick));
	strncpy(packet->data.Nick.nick, login.c_str(), login.size());
	if (_net->sendMessage(packet, sizeof(*packet), _serverSocket) == false)
		return false;
	checkResponse();
	return true;
}

bool ServerLink::getContactList()
{
	ClientPacket *packet = new ClientPacket;

	memset(packet, 0, sizeof(*packet));
	packet->command = GETCLIST;
	if (_net->sendMessage(packet, sizeof(*packet), _serverSocket) == false)
		return false;
	return true;
}

bool ServerLink::requestCall(int id)
{
	ClientPacket *packet = new ClientPacket;

	memset(packet, 0, sizeof(*packet));
	packet->command = RQ_CALL;
	packet->data.rq_call.id = id;
	if (_net->sendMessage(packet, sizeof(*packet), _serverSocket) == false)
		return false;
	return true;
}

bool ServerLink::checkResponse()
{
	ServerPacket* pack = new ServerPacket;

	if (_serverSocket == -1)
		return false;
	memset(pack, 0, sizeof(*pack));
	_net->rcvMessage(_serverSocket, pack, sizeof(*pack));
	std::cout << pack->response << std::endl;
	return true;
}

bool ServerLink::sendResponseToCall(bool resp, std::string ip, std::string port, int id)
{
	ClientPacket *packet = new ClientPacket;

	memset(packet, 0, sizeof(*packet));
	if (resp == true)
	{
		packet->command = ACPT_CALL;
		strncpy(packet->data.acpt_call.ip, ip.c_str(), ip.size());
		strncpy(packet->data.acpt_call.port, port.c_str(), port.size());
		packet->data.acpt_call.id = id;
	}
	else
		packet->command = REFU_CALL;
	if (_net->sendMessage(packet, sizeof(*packet), _serverSocket) == false)
		return false;
	return true;
}

ServerPacket *ServerLink::checkMessage()
{
	fd_set			set;
	ServerPacket	*pack;
	struct timeval	tv;

	if (_serverSocket == -1)
		return NULL;
	tv.tv_sec = 0;
	tv.tv_usec = 1;
	_net->ZeroFD(set);
	_net->SetFD(_serverSocket, set);
	_net->MySelectFunc(_serverSocket, set, &tv);
	if (_net->CheckFdIsSet(_serverSocket, set))
	{
		std::cout << "MESSAGE FROM SERVER" << std::endl;
		pack = new ServerPacket;
		if (_net->rcvMessage(_serverSocket, pack, sizeof(*pack)) <= 0)
			_serverSocket = -1;
		else
			return pack;
	}
	return NULL;
}
