#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include "data.h"

THUMB16
NEWCODE static inline int isspace(int c)
{
	return (c == ' ' || c >= '\t' && c <= '\r');
}

THUMB16
NEWCODE static inline int isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

THUMB16
NEWCODE static inline int isxdigit(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

THUMB16
NEWCODE int hex2int(const char *h)
{
	int res = 0;

	while (*h && *h != 'x')
		h++;
	if (*h == 'x')
		h++;

	while (*h && *h != ';')
	{
		char c = *h++;
		if (c >= '0' && c <= '9')
		{
			res = (res << 4) | (c - '0');
		}
		else if (c >= 'A' && c <= 'F')
		{
			res = (res << 4) | (c - 'A' + 10);
		}
		else if (c >= 'a' && c <= 'f')
		{
			res = (res << 4) | (c - 'a' + 10);
		}
	}
	return res;
}

THUMB16
NEWCODE int ascii2int(const char *s)
{
	int result = 0;

	while (isspace(*s))
		s++;

	while (isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}

	return result;
}
