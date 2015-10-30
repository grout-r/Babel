#include "Server.h"
#include "InterClientCom.h"
#include <Windows.h>


int main()
{
	Server *s = new Server("192.168.1.70", "4242");



	InterClientCom* com = new InterClientCom(std::string("4343"));
	//InterClientCom* com = new InterClientCom(std::string("127.0.0.1"), std::string("4343"));
	InterCPacket* packet = new InterCPacket;
	system("pause");
	std::string str;
	while (1)
	{
		//std::cin >> str;
		//com->SendData(str);
		//if ((packet = com->ReceiveData()) != NULL)
		//	std::cout << "MESSAGE: " << packet->message << std::endl;

		if ((packet = com->ReceiveData()) != NULL)
			std::cout << "MESSAGE: " << packet->message << std::endl;
		com->SendData(std::string("super"));
	}
	system("pause");
}
