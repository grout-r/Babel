#include <string>
#include <iostream>

#ifdef _WIN32
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
typedef SOCKET MySocket;

#else
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
typedef int MySocket;

#endif

typedef addrinfo MyConnectionData;