#ifndef COM_H
#define COM_H

#include <base.h>

typedef struct
{
	uint8_t data[16];
} UUID, *PUUID;

#ifdef __cplusplus
template <typename T>
void **PPINTERFACE(T **pp)
{
	return reinterpret_cast<void **>(pp);
}
#else
#define PPINTERFACE(v) (void **)v
#endif

#define SUCCEEDED(res) (res >= 0)

#endif // COM_H