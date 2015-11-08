#ifdef __linux__

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
# include "UNetworkAPI.h"

UNetworkAPI::UNetworkAPI()
{
}

UNetworkAPI::~UNetworkAPI()
{
}

bool UNetworkAPI::initNetwork()
{
	return true;
}

MyConnectionData *UNetworkAPI::getAddr(const char * ip, const char * port, int family, int socktype, int protocol, int flags)
{
	struct addrinfo *addr = NULL, hints;
	int result;
	bzero(&hints, sizeof(hints));
	hints.ai_flags = flags;
	hints.ai_family = family;
	hints.ai_socktype = socktype;
	hints.ai_protocol = protocol;
	hints.ai_addr = INADDR_ANY;
	result = getaddrinfo(ip, port, &hints, &addr);
	if (result != 0)
	{
		printf("getaddrinfo failed: %d\n", result);
		return NULL;
	}
	return addr;
}

MySocket UNetworkAPI::MySocketFunc(MyConnectionData *addrInfo)
{
	MySocket Thatsocket = -1;
	Thatsocket = socket(addrInfo->ai_family, addrInfo->ai_socktype,
		addrInfo->ai_protocol);
	return Thatsocket;
}

bool UNetworkAPI::MyConnectFunc(MySocket socket, MyConnectionData *addrInfo)
{
	int iResult = connect(socket, addrInfo->ai_addr, (int)addrInfo->ai_addrlen);
	if (iResult == -1)
	{
		close(socket);
		socket = -1;
		return false;
	}
	return true;
}

bool UNetworkAPI::MyBindFunc(MySocket socket, MyConnectionData * conData)
{
	if (bind(socket, conData->ai_addr, (int)conData->ai_addrlen) == -1)
	{
		printf("bind failed with error\n");
		freeaddrinfo(conData);
		close(socket);
		return false;
	}
	return true;
}

bool UNetworkAPI::MyListenFunc(MySocket socket)
{
	if (listen(socket, SOMAXCONN) == -1) {
		printf("Listen failed\n");
		close(socket);
		return false;
	}
	return true;
}

MySocket UNetworkAPI::MyAcceptFunc(MySocket ListenSocket)
{
	MySocket ClientSocket = -1;
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == -1) {
		printf("accept failed\n");
		close(ListenSocket);
	}
	return ClientSocket;
}


bool UNetworkAPI::sendMessage( const void * buffer, int size, MySocket socket)
{
	int iResult = send(socket, buffer, size, 0);
	if (iResult == -1) {
		printf("send failed\n");
		close(socket);
		return false;
	}
	return true;
}

int UNetworkAPI::rcvMessage(MySocket socket, void* buffer, int size)
{
	return recv(socket, (char*)buffer, size, 0);
}

void		UNetworkAPI::MySelectFunc(MySocket socket, fd_set& readSet, struct timeval *to)
{
	if (select(socket + 1, &readSet, NULL, NULL, to) == -1)
	{
		perror("select()");
		exit(0);
	}
}

void		UNetworkAPI::ZeroFD(fd_set& fdSet)
{
	FD_ZERO(&fdSet);
}

void		UNetworkAPI::SetFD(MySocket socket, fd_set& fdSet)
{
	FD_SET(socket, &fdSet);
}

bool		UNetworkAPI::CheckFdIsSet(MySocket readSocket, fd_set &readSet)
{
	if (FD_ISSET(readSocket, &readSet))
		return true;
	return false;
}

bool		UNetworkAPI::CloseConnection(MySocket socket)
{
  close(socket);
	return true;
}

Network*						getNetworkInstance()
{
	return new UNetworkAPI;
}

#endif
