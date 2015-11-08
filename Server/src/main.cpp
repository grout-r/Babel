#include "Server.h"
#include <string>

int main()
{
	Server *s = new Server("192.168.1.70", "4242");

	/*
	//InterClientCom* com = new InterClientCom(std::string("4343"));
	InterClientCom* com = new InterClientCom(std::string("192.168.1.28"), std::string("4343"));
	InterCPacket* packet = new InterCPacket;
	system("pause");
	std::cout << "CLIENT START" << std::endl;
	//std::cout << "SERVER START" << std::endl;
	std::string str;
	while (1)
	{
		
		std::cin >> str;
		if (com->SendData(str))
		{
			std::cout << "before" << std::endl;
			if ((packet = com->ReceiveData()) != nullptr)
				std::cout << "MESSAGE: " << packet->message << std::endl;
			std::cout << "after" << std::endl;
		}
		else
			std::cout << "send failed" << std::endl;

		//if (com->TryAccept())
		//{
		//	if ((packet = com->ReceiveData()) < 0)
		//	{
		//		std::cout << "MESSAGE: " << packet->message << std::endl;
		//		com->SendData(std::string("super"));
		//	}
		//}
	}
	*/
}
