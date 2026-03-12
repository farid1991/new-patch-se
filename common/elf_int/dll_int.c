#include <base.h>

#include "dll.h"

ARM32
NEWCODE void *LoadDLL_int(wchar_t *DllName)
{
	register wchar_t *r0 __asm__("r0") = DllName;

	__asm__ volatile("svc 0x10E" : "+r"(r0) : : "lr", "memory");

	return r0;
}

ARM32
NEWCODE int UnLoadDLL_int(void *DllData)
{
	register void *r0 __asm__("r0") = DllData;

	__asm__ volatile("svc 0x10F" : "+r"(r0) : : "lr", "memory");

	return (int)r0;
}
