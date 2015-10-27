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

/*
	if (mode == MODE_CLIENT)
	{
		hints.ai_family = AF_UNSPEC;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
	}
	else if (mode == MODE_SERVER)
	{
		hints.ai_family = AF_INET;
		hints.ai_socktype = SOCK_STREAM;
		hints.ai_protocol = IPPROTO_TCP;
		hints.ai_flags = AI_PASSIVE;
	}*/
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
	}
	return false;
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



bool WindowsNetworkAPI::sendMessage(const char * msg, MySocket socket)
{
	int iResult = send(socket, msg, (int)strlen(msg), 0);
	if (iResult == SOCKET_ERROR) {
		printf("send failed: %d\n", WSAGetLastError());
		closesocket(socket);
		WSACleanup();
		return 1;
	}

	return false;
}



void		WindowsNetworkAPI::MySelectFunc(MySocket socket, fd_set &fdSet)
{
	FD_ZERO(&fdSet);
	FD_SET(socket, &fdSet);
	if (select(socket + 1, &fdSet, NULL, NULL, NULL) == -1)
	{
		perror("select()");
		exit(0);
	}
}

std::string WindowsNetworkAPI::rcvMessage(MySocket socket)
{
	char tmp[512];
	memset(tmp, 0, 512);
	int result = recv(socket, tmp, 512, 0);
	return std::string(tmp);
}

bool WindowsNetworkAPI::closeConnection()
{
	return false;
}

Network*						getNetworkInstance()
{
	return new WindowsNetworkAPI;
}