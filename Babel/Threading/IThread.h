#ifndef ITHREAD_H_
# define ITHREAD_H_

# include "IMutex.h"

class IThread
{
public:
	virtual ~IThread() {}

public:
	virtual bool	InitThread(void routine(IMutex *params)) = 0;
	virtual bool	StartThread() = 0;
	virtual bool	WaitThread() = 0;
	virtual void	DestroyThread() = 0;
};

#endif