#ifndef TIMER_H
#define TIMER_H

#include <base.h>

typedef void (*TIMERPROC)(uint16_t timerID, LPARAM lparam);

#ifdef __cplusplus
template <typename T>
TIMERPROC MKTIMERPROC(void (*param)(uint16_t, T *))
{
	return reinterpret_cast<TIMERPROC>(param);
}
#else
#define MKTIMERPROC(fn) (TIMERPROC) fn
#endif

#endif // TIMER_H