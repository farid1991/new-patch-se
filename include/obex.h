#ifndef OBEX_H
#define OBEX_H

#include <base.h>
#include <textid.h>

typedef struct BT_FILE_2020
{
	wchar_t fname[255];
	wchar_t fpath[255];
} BT_FILE_2020;

typedef struct BT_FILE_2010
{
	wchar_t fname[252];
	wchar_t fpath[252];
} BT_FILE_2010;

typedef struct SEND_OBEX_STRUCT
{
	uint8_t is_multiple;
	uint32_t Book_ID;
	TEXTID send;
	TEXTID sent;
	uint16_t obex_flag;
	union
	{
		LIST *lst;
		union
		{
			BT_FILE_2020 btf2020;
			BT_FILE_2010 btf2010;
		};
	};
} SEND_OBEX_STRUCT;

#endif // OBEX_H