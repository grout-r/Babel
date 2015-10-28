# include "ServerLink.h"

ServerLink::ServerLink()
{
	_net = getNetworkInstance();
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
		return false;
	if ((_net->MyConnectFunc(_serverSocket, _conData)) == false)
		return false;
//	send(_serverSocket, "test", strlen("test"), 0);
	return true;
}

bool ServerLink::login(std::string login)
{
	ClientPacket *packet = new ClientPacket;

	memset(packet, 0, sizeof(*packet));
	packet->command = LOGIN;
	memset(packet->data.login.login, 0, sizeof(packet->data.login.login));
	strncpy_s(packet->data.login.login, login.c_str(), login.size());
	if (_net->sendMessage(packet, sizeof(*packet), _serverSocket) == false)
		return false;
	return true;
}

bool	ServerLink::sendTestMessage(std::string msg)
{
//	_net->sendMessage(msg.c_str(), _serverSocket);
	return true;
}