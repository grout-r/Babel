#include <iostream>
#include "Core.h"
#include "Transformer.h"
#include "GUI.h"
void		routine(SafeQueue& queue);

Core::Core()
	: _commandQueue(new SafeQueue())
{
	std::cout << "Welcome to BABEL" << std::endl;
	InitGui(*_commandQueue);
	StartClient();
	/*
	StartCom();*/
	system("pause");
}

Core::~Core()
{
}

void	Core::StartClient()
{
	Network* net = getNetworkInstance();

	StartCom(net);
}

void Core::StartCom(Network *net)
{
	INFO	ret;

	MySocket			socket;
	MyConnectionData	*conData;

	net->initNetwork();

	conData = net->getAddr("127.0.0.1", "4242", MODE_CLIENT);
	socket = net->MySocketFunc(conData);
	net->MyConnectFunc(socket, conData);
	net->sendMessage("salut", socket);
	while (1)
	{
		ret = _commandQueue->PopInList();
		
		if (ret.size() != 0)
		{
			std::cout << ret << std::endl;
			net->sendMessage(ret.c_str(), socket);
		}
	}
}

bool Core::InitGui(SafeQueue &safeStock)
{
	_guiThread = Transformer::ThreadHandler(safeStock);
	_guiThread->InitThread(routine);
	_guiThread->StartThread();
	return true;
}

void		routine(SafeQueue& queue)
{
	std::cout << "start thread" << std::endl;
	GUI*	gui = new GUI(queue);
	std::cout << "finish" << std::endl;
}