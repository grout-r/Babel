#include "Server.h"
#include <Windows.h>


int main(int ac, char **av)
{
	Server *s = new Server("192.168.1.70", "4242");
	system("pause");
}
