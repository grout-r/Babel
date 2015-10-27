#ifndef TRANSFORMER_H_
# define TRANSFORMER_H_

# include "WThread.h"
# include "UThread.h"
# include "WMutex.h"
# include "UMutex.h"
# include "SafeQueue.h"

class Transformer
{
public:
	static IMutex*		MutexHandler();
	static IThread*		ThreadHandler(SafeQueue &queue);
};

#endif