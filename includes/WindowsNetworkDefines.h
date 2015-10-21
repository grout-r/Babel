#pragma once

#include <string>
#include <winsock2.h>
#include <windows.h>
#include <ws2tcpip.h>
#include <iostream>

typedef SOCKET MySocket;
typedef addrinfo MyConnectionData;
#define MODE_SERVER 1
#define MODE_CLIENT 2
