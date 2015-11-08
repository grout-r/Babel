#include "InterClientCom.h"

InterClientCom::InterClientCom()
{
	_network = getNetworkInstance();
}

InterClientCom::~InterClientCom()
{
}

bool			InterClientCom::Connect(std::string ip, std::string port)
{
	MyConnectionData*	conData;

	_network->initNetwork();
	if ((conData = _network->getAddr(ip.c_str(), port.c_str(), AF_INET, SOCK_STREAM, IPPROTO_TCP, 0)) == NULL)
		return false;
	if ((_peerSocket = _network->MySocketFunc(conData)) == INVALID_SOCKET)
		return false;
	if ((_network->MyConnectFunc(_peerSocket, conData)) == false)
		return false;
	std::cout << "Client Mode established" << std::endl;
	return true;
}

bool InterClientCom::Accept(std::string port)
{
	MyConnectionData*	conData;

	_network->initNetwork();
	if ((conData = _network->getAddr(NULL, port.c_str(), AF_INET, SOCK_STREAM, IPPROTO_TCP, AI_PASSIVE)) == NULL)
		return false;
	if ((_socket = _network->MySocketFunc(conData)) == INVALID_SOCKET)
		return false;
	if (!_network->MyBindFunc(_socket, conData))
		return false;
	if (_network->MyListenFunc(_socket) == 0)
		return false;
	std::cout << "Server Mode established" << std::endl;
	return true;
}

bool			InterClientCom::TryAccept()
{
	_peerSocket = _network->MyAcceptFunc(_socket);
	if (_peerSocket == INVALID_SOCKET)
		return false;
	return true;
}

bool			InterClientCom::SendData(Sound::Encoded* pack)
{
	if (_network->sendMessage(pack, sizeof(*pack), _peerSocket) == false)
		return false;
	return true;
}

bool			InterClientCom::ReceiveData(Sound::Encoded* pack) const
{
	struct timeval tv;
	fd_set			set;

	tv.tv_sec = 0;
	tv.tv_usec = 1;
	_network->ZeroFD(set);
	_network->SetFD(_peerSocket, set);
	_network->MySelectFunc(_peerSocket, set, &tv);
	if (_network->CheckFdIsSet(_peerSocket, set))
	{
		std::cout << "MESSAGE FROM ANOTHER CLIENT" << std::endl;
		if (_network->rcvMessage(_peerSocket, pack, sizeof(*pack)) <= 0)
			return false;
	}
	return true;
}

