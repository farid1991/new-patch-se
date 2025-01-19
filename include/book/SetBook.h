#ifndef SET_BOOK_H
#define SET_BOOK_H

#include <base.h>
#include <bookobj.h>
#include <gui.h>

typedef struct SetBook
{
  BOOK book;
  char dummy_1[0x4];
  GUI *gui;
  char dummy_2[0x1C];
  char *bright;
} SetBook;

#endif // SET_BOOK_H