#include "Server.h"
#ifdef _WIN32
#include <Windows.h>
#endif
#include <string>

int main(int ac, char **av)
{
	Server *s = new Server("192.168.1.70", av[1]);
}
