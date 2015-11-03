#include <iostream>
#include "Core.h"
#include "InterClientCom.h"
#include "InterClientPacket.h"

int main()
{
	Core core;
	InterCPacket *pack = new InterCPacket;

	//core.start();
	InterClientCom com(std::string("4343"));
	
	com.TryAccept();
	while (1)
	{
		memset(pack, 0, sizeof(*pack));
		if (com.ReceiveData(pack) == true)
			std::cout << pack->message << std::endl;
		memset(pack, 0, sizeof(*pack));
		strncpy(pack->message,"salope", strlen("salope"));
		com.SendData(pack);
		std::cout << "pute" << std::endl;
	}

}
