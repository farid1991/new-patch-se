#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include "str_helper.h"

THUMB16
NEWCODE int parse_value(const char *str)
{
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		return hex2int(str);

	return ascii2int(str);
}

THUMB16
NEWCODE void parse_values(const char *input, int *output)
{
	const char *input_start = input;
	int i = 0;

	while (*input_start)
	{
		const char *end = input_start;
		while (*end && *end != ',')
			end++;

		char temp[32];
		int len = end - input_start;
		if (len >= sizeof(temp))
			len = sizeof(temp) - 1;

		memcpy(temp, input_start, len);
		temp[len] = '\0';

		output[i++] = parse_value(temp);

		if (*end == ',')
			input_start = end + 1;
		else
			break;
	}
}
