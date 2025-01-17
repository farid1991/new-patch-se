#ifndef JAVA_H
#define JAVA_H

#include <base.h>

typedef struct MIDP_DESC_ITEM
{
	uint16_t item_name_len;
	uint8_t const_2;
	wchar_t *item_name;
} MIDP_DESC_ITEM;

typedef struct MIDP_DESC
{
	MIDP_DESC_ITEM *name;
	MIDP_DESC_ITEM *vendor;
	MIDP_DESC_ITEM *point;
} MIDP_DESC;

typedef struct JavaAppDesc
{
    char unk[255];
} JavaAppDesc;

typedef struct JavaAppFullpath
{
	uint16_t fullpath_len;
	char unk_2;
	wchar_t *fullpath;
} JavaAppFullpath;

#endif // JAVA_H