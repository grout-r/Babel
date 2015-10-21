#include "SafeQueue.h"
#include "ScopedLock.h"
#include "Transformer.h"
#include <iostream>

SafeQueue::SafeQueue()
	: _inMutex(Transformer::MutexHandler()), _outMutex(Transformer::MutexHandler()), _inList(new std::deque<INFO>()), _outList(new std::deque<INFO>())
{
}

SafeQueue::~SafeQueue()
{
	delete _inMutex;
	delete _outMutex;
	delete _inList;
	delete _outList;
}

INFO SafeQueue::PopInList()
{
	ScopedLock		scope(_inMutex);
	INFO			ret;

	if (_inList->size() > 0)
	{
		std::cout << "inside" << std::endl;
		ret = _inList->front();
		_inList->pop_front();
		return (ret);
	}
	return ("");
}

void SafeQueue::FillInList(INFO const & str)
{
	ScopedLock		scope(_inMutex);

	_inList->push_back(str);
}

INFO SafeQueue::PopOutList()
{
	ScopedLock		scope(_outMutex);
	INFO			ret;

	if (_inList->size() > 0)
	{
		ret = _outList->front();
		_outList->pop_front();
		return (ret);
	}
	return (NULL);
}

void SafeQueue::FillOutList(INFO const & str)
{
	ScopedLock		scope(_outMutex);

	_outList->push_back(str);
}