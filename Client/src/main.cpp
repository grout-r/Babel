#include <iostream>
#include "Core.h"
#include "InterClientCom.h"
#include "InterClientPacket.h"

int main()
{
	Core core;
	InterCPacket *pack = new InterCPacket;

	core.start();

}
