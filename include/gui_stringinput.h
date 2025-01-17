#ifndef GUI_STRINGINPUT_H
#define GUI_STRINGINPUT_H

#include <base.h>
#include <textid.h>
#include <gui.h>

typedef struct GUI GUI_STRINGINPUT;

enum INPUT_TYPES
{
	IT_REAL = 0,
	IT_STRING = 1,
	IT_INTEGER = 2,
	IT_PHONE_NUMBER = 3,
	IT_DIGITAL_PASS = 4,
	IT_DIGITAL_IP = 5,
	IT_URL = 6,
	IT_EMAIL = 7,
	IT_ABC_AND_DIGIT = 8,
	IT_UNSIGNED_DIGIT = 9,
	IT_EXTRA_DIGIT = 10,
	IT_ABC_OR_DIGIT = 11,
	IT_EXTRA_DIGIT_2 = 12,
	IT_ABC_OR_DIGIT_2 = 13,
};

typedef struct LANGUAGE
{
	uint8_t count;
	char *langs;
} LANGUAGE;

typedef struct DISP_OBJ_STRING_INPUT
{
	char dummy[0x424];
	LANGUAGE *lng;
	uint8_t cur_langID;
} DISP_OBJ_STRING_INPUT;

#endif // GUI_STRINGINPUT_H