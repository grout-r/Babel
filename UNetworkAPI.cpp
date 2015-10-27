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
	}
	return false;
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



bool UNetworkAPI::sendMessage(const char * msg, MySocket socket)
{
	int iResult = send(socket, msg, (int)strlen(msg), 0);
	if (iResult == -1) {
		printf("send failed\n");
		close(socket);
		return 1;
	}
	return false;
}

std::string UNetworkAPI::rcvMessage(MySocket socket)
{
	char tmp[512];
	memset(tmp, 0, 512);
	int result = recv(socket, tmp, 512, 0);
	return std::string(tmp);
}

void		UNetworkAPI::MySelectFunc(MySocket socket, fd_set &fdSet)
{
	FD_ZERO(&fdSet);
	FD_SET(STDIN_FILENO, &fdSet);
	FD_SET(socket, &fdSet);
	if (select(socket + 1, &fdSet, NULL, NULL, NULL) == -1)
	{
		perror("select()");
		exit(0);
	}
}

static int		select_fd(t_data *data, fd_set fd_read)
{
	int			i;
	t_list		*tmp;

	i = 2;
	while (++i <= data->max_fd + 1)
	{
		if (FD_ISSET(i, &fd_read))
		{
			tmp = get_elem(data->root, i);
			if (tmp != data->root && tmp != data->root->next)
				tmp->read_f(data, tmp);
			else
				server_read(data, i);
	}
	}
	return (0);
}

bool UNetworkAPI::closeConnection()
{
	return false;
}

Network*						getNetworkInstance()
{
	return new UNetworkAPI;
}

#endif