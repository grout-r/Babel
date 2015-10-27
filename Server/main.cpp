#include "Server.h"
#include <Windows.h>

int main(int ac, char **av)
{
	Server *s = new Server("127.0.0.1", "4242");
	system("pause");
}