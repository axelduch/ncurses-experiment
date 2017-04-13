#include "main.h"
#include "string.h"
#ifdef _WIN32
#define OS_WINDOWS
#elif defined(WIN32)
#define OS_WINDOWS
#elif __unix__
#define OS_UNIX
#include "time.h"
#endif

#ifdef OS_WINDOWS
#include <windows.h>
#endif

void wait(int milliseconds) {
	#ifdef OS_UNIX
	struct timespec interval;
	interval.tv_sec = milliseconds / 1000;
	interval.tv_nsec = (milliseconds % 1000) * 1000000;

	nanosleep(&interval, NULL);
	#elif defined(OS_WINDOWS)
	Sleep(milliseconds);
	#else
	printw("Wait what... %s?\n", milliseconds);
	#endif
}

