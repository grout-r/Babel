#ifndef UTHREAD_H_
# define UTHREAD_H_

# ifdef __linux__

#include <thread>
#include "IThread.h"

class CUThread : public IThread
{
public:
	CUThread(IMutex *mutex);
	~CUThread();

private:
	IMutex		*_mutex;
	std::thread	*_thread;
	void		(*_routine)(IMutex *param);

public:
	bool		InitThread(void routine(IMutex *params));
	bool		StartThread();
	bool		WaitThread();
	void		DestroyThread(); 
};

# endif

#endif