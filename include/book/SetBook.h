#ifndef SET_BOOK_H
#define SET_BOOK_H

#include <base.h>
#include <bookobj.h>
#include <gui.h>

typedef struct SetBook
{
	BOOK book;
	char unk_18[0x4];
	GUI *gui;
	char unk_20[0x1C];
	char brightness;
} SetBook;

#endif // SET_BOOK_H