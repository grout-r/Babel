#pragma once
#include <deque>
#include <string>
#include "IMutex.h"

typedef std::string INFO;

class SafeQueue
{
public:
	SafeQueue();
	~SafeQueue();

private:
	IMutex*					_inMutex;
	IMutex*					_outMutex;
	std::deque<INFO>*		_inList;
	std::deque<INFO>*		_outList;

public:
	INFO		PopInList();
	void		FillInList(INFO const& str);
	INFO		PopOutList();
	void		FillOutList(INFO const& str);
};

