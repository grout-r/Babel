#include "Transformer.h"

IMutex * Transformer::MutexHandler()
{
#ifdef __linux__
	return new CUMutex();
#elif _WIN32
	return new CWMutex();
#endif
	return nullptr;
}

IThread * Transformer::ThreadHandler(IMutex *mutex)
{
#ifdef __linux__
	return new CUThread(mutex);
#elif _WIN32
	return new CWThread(mutex);
#endif
	return nullptr;
}
