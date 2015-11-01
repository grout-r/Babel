#include "WindowsNetworkAPI.h"

WindowsNetworkAPI::WindowsNetworkAPI()
{
}

WindowsNetworkAPI::~WindowsNetworkAPI()
{
}

bool WindowsNetworkAPI::initNetwork()
{
	WSADATA wsaData;
	int result;
	result = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (result != 0)
	{
		printf("WSAStartup failed: %d\n", result);
		return true;
	}
	return false;
}

MyConnectionData *WindowsNetworkAPI::getAddr(const char * ip, const char * port, int family, int socktype, int protocol, int flags)
{
	struct addrinfo *addr = NULL, hints;
	int result;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_flags = flags;
	hints.ai_family = family;
	hints.ai_socktype = socktype;
	hints.ai_protocol = protocol;
	result = getaddrinfo(ip, port, &hints, &addr);
	if (result != 0) {
		printf("getaddrinfo failed: %d\n", result);
		WSACleanup();
		return NULL;
	}
	return addr;
}

MySocket WindowsNetworkAPI::MySocketFunc(MyConnectionData *addrInfo)
{
	MySocket Thatsocket = INVALID_SOCKET;
	Thatsocket = socket(addrInfo->ai_family, addrInfo->ai_socktype,
		addrInfo->ai_protocol);
	return Thatsocket;
}

bool WindowsNetworkAPI::MyConnectFunc(MySocket socket, MyConnectionData *addrInfo)
{
	int iResult = connect(socket, addrInfo->ai_addr, (int)addrInfo->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		closesocket(socket);
		socket = INVALID_SOCKET;
		return false;
	}
	return true;
}

bool WindowsNetworkAPI::MyBindFunc(MySocket socket, MyConnectionData * conData)
{
	if (bind(socket, conData->ai_addr, (int)conData->ai_addrlen) == SOCKET_ERROR)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(conData);
		closesocket(socket);
		WSACleanup();
		return false;
	}
	return true;
}

bool WindowsNetworkAPI::MyListenFunc(MySocket socket)
{
	if (listen(socket, SOMAXCONN) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(socket);
		WSACleanup();
		return false;
	}
	return true;
}

MySocket WindowsNetworkAPI::MyAcceptFunc(MySocket ListenSocket)
{
	SOCKET ClientSocket = INVALID_SOCKET;
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		printf("accept failed: %d\n", WSAGetLastError());
		closesocket(ListenSocket);
		WSACleanup();
	}
	return ClientSocket;
}

bool WindowsNetworkAPI::sendMessage(const void *buffer, int size, MySocket socket)
{
	int iResult = send(socket, (char*)buffer, size, 0);
	if (iResult == -1) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(socket);
		WSACleanup();
		return false;
	}
	return true;
}

int WindowsNetworkAPI::rcvMessage(MySocket socket, void* buffer , int size)
{
	return recv(socket, (char*)buffer, size, 0);
}

bool WindowsNetworkAPI::closeConnection(MySocket socket)
{
	closesocket(socket);
	return false;
}

Network*						getNetworkInstance()
{
	return new WindowsNetworkAPI;
}