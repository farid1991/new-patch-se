#include <base.h>

ARM32
NEWCODE int elfload_int(const wchar_t *filename, void *param1, void *param2, void *param3)
{
	register const wchar_t *r0 __asm__("r0") = filename;
	register void *r1 __asm__("r1") = param1;
	register void *r2 __asm__("r2") = param2;
	register void *r3 __asm__("r3") = param3;

	__asm__ volatile("svc 0x10D" : "+r"(r0) : "r"(r1), "r"(r2), "r"(r3) : "lr", "memory");

	return (int)r0;
}
