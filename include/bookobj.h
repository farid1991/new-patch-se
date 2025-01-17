#ifndef BOOK_H
#define BOOK_H

#include <base.h>
#include <imageid.h>
#include <list.h>
#include <textid.h>

struct BOOK;

typedef struct UI_APP_SESSION
{
	LIST *listbook;
	TEXTID name;
	IMAGEID icon;
	int W2;
	int SessionID;
	int unk2;
	char unk3;
} UI_APP_SESSION;

typedef struct XBOOK
{
	char isDestroyed;
	char *name;
	UI_APP_SESSION *app_session;
	int parent_BookID;
	uint16_t unk2;
	int unk3;
	int unk4;
	char unk5;
	void *unk6;
	int unk7;
	uint16_t unk8;
	uint16_t unk9;
	char dummy7[0x8];
	char orientation;
} XBOOK;

typedef struct BOOK_SUBROUTINE
{
	const char *name;
	struct PAGE_DESC *page;
	void (*OnEnter)(void *, struct BOOK *);
	void (*OnExit)(void *, struct BOOK *);
} BOOK_SUBROUTINE;

typedef struct PAGE_MSG
{
	int msg;
	int (*proc)(void *, struct BOOK *);
} PAGE_MSG;

typedef struct PAGE_DESC
{
	const char *name;
	BOOK_SUBROUTINE *subr;
	const PAGE_MSG *msg_lst;
} PAGE_DESC;

typedef struct XGUILIST
{
	struct BOOK *book;
	LIST *guilist;
} XGUILIST;

typedef struct BOOK
{
	XBOOK *xbook;
	void (*onClose)(struct BOOK *);
	uint32_t BookID;
	struct PAGE_DESC *current_page;
	struct PAGE_DESC *base_page;
	XGUILIST *xguilist;
} BOOK;

typedef int (*IS_NEEDED_BOOK)(BOOK *);

#define NO_BOOK_ID 0xFFFFFFFF

#endif // BOOK_H