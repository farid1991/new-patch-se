#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include "patch.h"

THUMB16
NEWCODE wchar_t *WStringAlloc(int lenght)
{
	size_t size = lenght * sizeof(wchar_t);
	wchar_t *wstr = (wchar_t *)malloc(size);
	if (!wstr)
		return NULL;
	memset(wstr, 0, size);
	return wstr;
}

THUMB16
NEWCODE void WStringAllocEx(wchar_t **wstr, int size)
{
	mfree((*wstr));
	(*wstr) = WStringAlloc(size);
}

THUMB16
NEWCODE void WStringReallocEx(wchar_t *src, wchar_t **dest, int size)
{
	WStringAllocEx(dest, size);
	wstrncpy((*dest), src, size);
}

THUMB16
NEWCODE void WStringRealloc(wchar_t *src, wchar_t **dest)
{
	WStringReallocEx(src, dest, wstrlen(src) + 1);
}

THUMB16
NEWCODE void WStringExtractFileName(wchar_t *str, wchar_t **name)
{
	wchar_t *pos = wstrrchr(str, '/');
	*pos = 0;
	WStringRealloc(pos + 1, name);
}

THUMB16
NEWCODE void WStringStripExt(wchar_t *s)
{
	wchar_t *p = wstrrchr(s, L'.');
	if (p && p != s)
		*p = 0;
}
