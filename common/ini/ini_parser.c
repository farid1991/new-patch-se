#include <base.h>

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

THUMB16
NEWCODE int ini_parse_value(const char *str)
{
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		return hex2int(str);

	return ascii2int(str);
}

THUMB16
NEWCODE int ini_parse_values(const char *input, int *output, int max_values)
{
	const char *p = input;
	int i = 0;

	// initialize output
	for (int j = 0; j < max_values; j++)
		output[j] = 0;

	while (*p && i < max_values)
	{
		// Skip leading spaces
		while (*p == ' ' || *p == '\t')
			p++;

		const char *end = p;
		while (*end && *end != ',')
			end++;

		int len = end - p;

		// Skip empty tokens
		if (len > 0)
		{
			char temp[32];

			if (len >= sizeof(temp))
				len = sizeof(temp) - 1;

			for (int j = 0; j < len; j++)
				temp[j] = p[j];

			temp[len] = '\0';

			output[i++] = ini_parse_value(temp);
		}

		// Move to next token
		if (*end == ',')
			p = end + 1;
		else
			break;
	}

	return i; // number of parsed values
}
