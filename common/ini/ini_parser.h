#ifndef __INI_PARSER__
#define __INI_PARSER__

int ini_parse_value(const char *str);
int ini_parse_values(const char *input, int *output, int max_values);

#endif // __INI_PARSER__
