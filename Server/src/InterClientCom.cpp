#include "InterClientCom.h"

InterClientCom::InterClientCom(std::string& ip, std::string& port)
	: _network(getNetworkInstance()), _packet(new InterCPacket)
{
	if (Connect(ip, port))
		std::cout << "CONNECTED" << std::endl;
	else
		std::cout << "NOT CON" << std::endl;
}

InterClientCom::InterClientCom(std::string & port)
	: _network(getNetworkInstance())
{
	if (Accept(port))
		std::cout << "CONNECTED" << std::endl;
	else
		std::cout << "NOT CON" << std::endl;
}

InterClientCom::~InterClientCom()
{
}

bool			InterClientCom::Connect(std::string& ip, std::string& port)
{
	MyConnectionData*	conData;

	_network->initNetwork();
	if ((conData = _network->getAddr(ip.c_str(), port.c_str(), AF_INET, SOCK_DGRAM, IPPROTO_UDP, 0)) == NULL)
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

	//MyConnectionData*	conData;

	//_network->initNetwork();
	//if ((conData = _network->getAddr(NULL, port.c_str(), AF_INET, SOCK_STREAM, IPPROTO_TCP, AI_PASSIVE)) == NULL)
	//	return false;
	//if ((_socket = _network->MySocketFunc(conData)) == INVALID_SOCKET)
	//	return false;
	//if (!_network->MyBindFunc(_socket, conData) || _network->MyListenFunc(_socket) == 0)
	//	return false;
	//return true;
	
	MyConnectionData*	conData;

	_network->initNetwork();
	if ((conData = _network->getAddr(NULL, port.c_str(), AF_INET, SOCK_DGRAM, IPPROTO_UDP, 0)) == NULL)
		return false;
	std::cout << "1" << std::endl;
	if ((_socket = _network->MySocketFunc(conData)) == INVALID_SOCKET)
		return false;
	std::cout << "2" << std::endl;
	if (!_network->MyBindFunc(_socket, conData))
		return false;
	_peerSocket = _socket;
	std::cout << "3" << std::endl;
	return true;
}

void			InterClientCom::SendData(std::string& str)
{
	strncpy_s(_packet->message, str.c_str(), str.size());
	if (_network->sendMessage(_packet, sizeof(*_packet), _peerSocket) == false)
		return ;
}

InterCPacket*	InterClientCom::ReceiveData() const
{
	_network->rcvMessage(_peerSocket, _packet, sizeof(*_packet));
	return _packet;
}

