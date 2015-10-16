#ifndef WTHREAD_H_
# define WTHREAD_H_

# ifdef _WIN32

# include <Windows.h>
# include "IThread.h"
# include "WMutex.h"

class CWThread : public IThread
{
public:
	CWThread(IMutex *mutex);
	~CWThread();

private:
	IMutex		*_mutex;
	HANDLE		_thread;

public:
	bool	InitThread(void routine(IMutex *params));
	bool	StartThread();
	bool	WaitThread();
	void	DestroyThread();
};

# endif

#endif
