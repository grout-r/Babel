#include "GUI.h"

#include "Windows.h"
#include <iostream>

GUI::GUI(SafeQueue &queue)
	: _queue(queue)
{
	std::cout << "arthurrr couillerre" << std::endl;
	Start();
}

GUI::~GUI()
{
}

void GUI::Start()
{
	int i = 0;
	std::string str;
	while (1)
	{/*
		std::cin >> str;
		str += '\n';*/
	std::cout << "before fill" << std::endl;
		_queue.FillInList("arthur la gentri\n");
//		str += rand() % 128;
		Sleep(500);
	}
}
