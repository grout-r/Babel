#include <iostream>
#include "Transformer.h"

void routine(IMutex *lpParam);

int main()
{
	IMutex *mutx = Transformer::MutexHandler();
	IThread *thread = Transformer::ThreadHandler(mutx);
	IThread *thread2 = Transformer::ThreadHandler(mutx);
	thread->InitThread(routine);
	thread2->InitThread(routine);
	thread->StartThread();
	thread2->StartThread();
	thread->WaitThread();
	thread2->WaitThread();
	thread->DestroyThread();
	thread2->DestroyThread();
#ifdef _WIN32
	system("pause");
#elif __linux__
	while (1);
#endif
	return 0;
}

void	routine(IMutex *lpParam)
{
	lpParam->LockMutex();/*
	if (!lpParam->TrylockMutex())
		std::cout << "shit 1" << std::endl;*/
	std::cout << "START" << std::endl;
	for (int i = 0; i < 4; i++)
	{
		std::cout << i << std::endl;
	}
	std::cout << "END" << std::endl;
	lpParam->UnlockMutex();
}


//
//void ErrorHandler(LPTSTR lpszFunction)
//{
//	// Retrieve the system error message for the last-error code.
//
//	LPVOID lpMsgBuf;
//	LPVOID lpDisplayBuf;
//	DWORD dw = GetLastError();
//
//	FormatMessage(
//		FORMAT_MESSAGE_ALLOCATE_BUFFER |
//		FORMAT_MESSAGE_FROM_SYSTEM |
//		FORMAT_MESSAGE_IGNORE_INSERTS,
//		NULL,
//		dw,
//		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
//		(LPTSTR)&lpMsgBuf,
//		0, NULL);
//
//	// Display the error message.
//
//	lpDisplayBuf = (LPVOID)LocalAlloc(LMEM_ZEROINIT,
//		(lstrlen((LPCTSTR)lpMsgBuf) + lstrlen((LPCTSTR)lpszFunction) + 40) * sizeof(TCHAR));
//	StringCchPrintf((LPTSTR)lpDisplayBuf,
//		LocalSize(lpDisplayBuf) / sizeof(TCHAR),
//		TEXT("%s failed with error %d: %s"),
//		lpszFunction, dw, lpMsgBuf);
//	MessageBox(NULL, (LPCTSTR)lpDisplayBuf, TEXT("Error"), MB_OK);
//
//	// Free error-handling buffer allocations.
//
//	LocalFree(lpMsgBuf);
//	LocalFree(lpDisplayBuf);
//}