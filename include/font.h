#ifndef _FONT_H_
#define _FONT_H_

typedef struct __attribute__((packed, aligned(2)))
{
	uint16_t id;
	wchar_t name[10];
} FONT_DESC;

#endif // _FONT_H_
