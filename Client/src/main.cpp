#include "Core.h"

int main()
{

	Core core;
	core.start();
	return (0);

/*
	struct addrinfo *addr = NULL, hints;
	int result;
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_flags = AF_INET;
	hints.ai_family = SOCK_STREAM;
	hints.ai_socktype = IPPROTO_TCP;
	hints.ai_protocol = AI_PASSIVE;
	hints.ai_addr = INADDR_ANY;
	result = getaddrinfo(NULL, "4242", &hints, &addr);
	MySocket Thatsocket = INVALID_SOCKET;
	Thatsocket = socket(addr->ai_family, addr->ai_socktype,
		addr->ai_protocol);
	if (bind(Thatsocket, addr->ai_addr, (int)addr->ai_addrlen) == SOCKET_ERROR)
	{
		printf("bind failed with error: %d\n", WSAGetLastError());
		freeaddrinfo(addr);
		closesocket(Thatsocket);
		WSACleanup();
		return false;
	}
	MySocket sock;
	if ((sock = listen(Thatsocket, SOMAXCONN)) == SOCKET_ERROR) {
		printf("Listen failed with error: %ld\n", WSAGetLastError());
		closesocket(Thatsocket);
		WSACleanup();
		return 0;
	}
	fd_set readSet;
	FD_ZERO(readSet);
	SET_FD(listen, readSet);
	for (int i = 1; i < sock + 1; )
	{
		_network->SetFD(, _readSet);
	}
	while (1)
	{
		SetClientFD();
		_network->MySelectFunc(_listen, _readSet);
		if (_network->CheckFdIsSet(_listen, _readSet))
			StartNewClient();
		CheckClientQueue();
	}*/
}
