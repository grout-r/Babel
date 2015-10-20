#pragma once
#include <deque>
#include <string>

#include "SafeQueue.h"
#include "IThread.h"
#include "WindowsNetworkAPI.h"


class Core
{
public:
	Core();
	~Core();

private:
	SafeQueue*	_commandQueue;
	IThread*	_guiThread;

	bool		InitGui(SafeQueue& stock);
	void		StartClient();
	void		StartCom(Network *net);

public:

};

