#include "Server.h"
#include "XMLParser.h"
#include <Windows.h>

int main(int ac, char **av)
{/*
	Server *s = new Server("192.168.1.70", "4242");
	system("pause");*/
	XMLParser *parse = new XMLParser("C:\\Users\\Arthur\\Documents\\GitHubVisualStudio\\Babel\\Server\\Debug\\ClientData.xml");
	system("pause");
}