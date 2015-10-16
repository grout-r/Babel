#ifndef TRANSFORMER_H_
# define TRANSFORMER_H_

# include "WThread.h"
# include "UThread.h"
# include "WMutex.h"
# include "UMutex.h"

class Transformer
{
public:
	static IMutex*		MutexHandler();
	static IThread*		ThreadHandler(IMutex *mutex);
};

#endif