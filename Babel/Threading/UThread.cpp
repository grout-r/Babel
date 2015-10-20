#ifdef __linux__

#include "UThread.h"
#include "..\Babel\UThread.h"

CUThread::CUThread(SafeQueue * safeStock)
{
}

CUThread::~CUThread()
{
}

bool CUThread::InitThread(void routine(IMutex *params))
{
	_routine = routine;
	return true;
}

bool CUThread::StartThread()
{
	_thread = new std::thread(_routine, _mutex);
	return true;
}

bool CUThread::WaitThread()
{
	_thread->join();
	return true;
}

void CUThread::DestroyThread()
{
	delete _thread();
}

#endif