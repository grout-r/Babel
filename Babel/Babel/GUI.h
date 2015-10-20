#ifndef GUI_H_
# define GUI_H_

# include "SafeQueue.h"

class GUI
{
public:
	GUI(SafeQueue& queue);
	~GUI();

private:
	SafeQueue&	_queue;

public:
	void	Start();
};

#endif