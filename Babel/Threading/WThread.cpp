#ifdef _WIN32

# include "WThread.h"

CWThread::CWThread(IMutex *mutex)
	: _mutex(mutex), _thread(NULL)
{
}

CWThread::~CWThread()
{
}

bool CWThread::InitThread(void routine(IMutex *params))
{
	return ((_thread = CreateThread(
		NULL,									// default security attributes
		0,										// use default stack size  
		(LPTHREAD_START_ROUTINE)routine,		// thread function name
		_mutex,									// argument to thread function 
		CREATE_SUSPENDED,						// use default creation flags 
		0										// returns the thread identifier 
		)) == NULL ? false : true);	
}

bool CWThread::StartThread()
{
	return (ResumeThread(_thread) == (DWORD)-1 ? false : true);
}

void CWThread::DestroyThread()
{
	CloseHandle(_thread);
}

bool CWThread::WaitThread()
{
	return (WaitForSingleObject(_thread, INFINITE) == WAIT_FAILED ? false : true);
}

#endif