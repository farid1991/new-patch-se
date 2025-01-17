#ifndef TEXTID_H
#define TEXTID_H

#include <base.h>

typedef uint32_t TEXTID;

typedef struct TEXTID_DATA
{
	wchar_t lenght;
	char encoding;
	void *ptr;
} TEXTID_DATA;

typedef enum TEXT_ENCODING
{
	ENC_UCS2 = 0,
	ENC_GSM = 1,
	ENC_BCD = 2,
	ENC_FILE = 3,
	ENC_TEXTID = 5,
	ENC_LAT1 = 6,
	ENC_UT = 8,
	ENC_UTTF = 9,
} TEXT_ENCODING;

#define TEXTID_ANY_LEN 0xFFFF
#define EMPTY_TEXTID 0x6FFFFFFF

#define TEXT(__STR__) L##__STR__
#define _T(__STR__) L##__STR__
#define STR(__STR__) TextID_Create(_T(__STR__), ENC_UCS2, TEXTID_ANY_LEN)

#endif // TEXTID_H
