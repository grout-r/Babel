#include "InterClientCom.h"

InterClientCom::InterClientCom(std::string& ip, std::string& port)
	: _network(getNetworkInstance())
{
	if (Connect(ip, port))
		std::cout << "CLIENT CONNECTED" << std::endl;
	else
		std::cout << "CLIENT NOT CON" << std::endl;
}

InterClientCom::InterClientCom(std::string & port)
	: _network(getNetworkInstance())
{
	if (Accept(port))
		std::cout << "SERVER CONNECTED" << std::endl;
	else
		std::cout << "SERVER NOT CON" << std::endl;
}

InterClientCom::~InterClientCom()
{
}

bool			InterClientCom::Connect(std::string& ip, std::string& port)
{
	MyConnectionData*	conData;

	_network->initNetwork();
	if ((conData = _network->getAddr(ip.c_str(), port.c_str(), AF_INET, SOCK_STREAM, IPPROTO_TCP, 0)) == NULL)
		return false;
	std::cout << "1" << std::endl;
	if ((_peerSocket = _network->MySocketFunc(conData)) == INVALID_SOCKET)
		return false;
	std::cout << "2" << std::endl;
	if ((_network->MyConnectFunc(_peerSocket, conData)) == false)
		return false;
	std::cout << "3" << std::endl;
	return true;
}

bool InterClientCom::Accept(std::string & port)
{
	MyConnectionData*	conData;

	_network->initNetwork();
	if ((conData = _network->getAddr(NULL, port.c_str(), AF_INET, SOCK_STREAM, IPPROTO_TCP, AI_PASSIVE)) == NULL)
		return false;
	std::cout << "1" << std::endl;
	if ((_socket = _network->MySocketFunc(conData)) == INVALID_SOCKET)
		return false;
	std::cout << "2" << std::endl;
	if (!_network->MyBindFunc(_socket, conData))
		return false;
	std::cout << "3" << std::endl;
<<<<<<< HEAD:Server/src/InterClientCom.cpp
	//if (_network->MyListenFunc(_socket) == 0)
	//	return false;
	//std::cout << "4" << std::endl;
=======
	if (_network->MyListenFunc(_socket) == 0)
		return false;
	std::cout << "4" << std::endl;
>>>>>>> c98135fb72b8659de63c64a55df74ca814a2f87b:Client/src/InterClientCom.cpp
	return true;
}

bool			InterClientCom::TryAccept()
{
	return ((_peerSocket = _network->MyAcceptFunc(_socket)) != INVALID_SOCKET ? true : false);
}

bool			InterClientCom::SendData(InterCPacket* pack)
{
<<<<<<< HEAD:Server/src/InterClientCom.cpp
	memset(_packet, 0, sizeof(*_packet));
	strncpy_s(_packet->message, str.c_str(), str.size());
	if (_network->sendMessage(_packet, sizeof(*_packet), _peerSocket) == false)
=======
	if (_network->sendMessage(pack, sizeof(*pack), _peerSocket) == false)
>>>>>>> c98135fb72b8659de63c64a55df74ca814a2f87b:Client/src/InterClientCom.cpp
		return false;
	return true;
}

bool			InterClientCom::ReceiveData(InterCPacket* pack) const
{
<<<<<<< HEAD:Server/src/InterClientCom.cpp
	memset(_packet, 0, sizeof(*_packet));
	if (_network->rcvMessage(_peerSocket, _packet, sizeof(*_packet)) < 0)
		return nullptr;
	return _packet;
=======
	if (_network->rcvMessage(_peerSocket, pack, sizeof(*pack)) <= 0)
		return false;
	return true;
>>>>>>> c98135fb72b8659de63c64a55df74ca814a2f87b:Client/src/InterClientCom.cpp
}
