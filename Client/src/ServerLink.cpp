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
	return true;
}