#ifndef DISPOBJ_H
#define DISPOBJ_H

#include <base.h>

#if defined(DB2000)
typedef struct DISP_OBJ // For DB2000 platform
{
	char dummy[0xC4];
} DISP_OBJ;
#elif defined(DB2010)
#ifdef OLD_PLAYER
typedef struct DISP_OBJ // For OLD DB2010 platform
{
	char dummy[0xBC];
} DISP_OBJ;
#else
typedef struct DISP_OBJ // For DB201X platform
{
	char dummy[0xB8];
} DISP_OBJ;
#endif
#elif defined(DB2020) || defined(PNX5230)
typedef struct DISP_OBJ // For DB2020 and PNX5230 platform
{
	char dummy[0xB4];
} DISP_OBJ;
#elif defined(DB3150v1)
typedef struct DISP_OBJ // For DB3150v1 platform
{
	char dummy[0x110];
} DISP_OBJ;
#elif defined(DB3150v2)
typedef struct DISP_OBJ // For DB3150v2 platform
{
	char dummy[0x120];
} DISP_OBJ;

#elif defined(DB3200)
typedef struct DISP_OBJ // For DB3200 platform
{
	char dummy[0x168];
} DISP_OBJ;

#elif defined(DB3210)
typedef struct DISP_OBJ // For DB3210 platform
{
	char dummy[0x16C];
} DISP_OBJ;
#elif defined(DB3350)
typedef struct DISP_OBJ // For DB3350 platform
{
	char dummy[0x200];
} DISP_OBJ;
#endif

typedef int (*DISP_OBJ_ONCREATE_METHOD)(DISP_OBJ *);
typedef void (*DISP_OBJ_ONCLOSE_METHOD)(DISP_OBJ *);
typedef void (*DISP_OBJ_ONREDRAW_METHOD)(DISP_OBJ *, int, int, int);
typedef void (*DISP_OBJ_ONKEY_METHOD)(DISP_OBJ *, int scan_code, int count, int repeat_num, int key_mode);
typedef void (*DISP_OBJ_ONCONFIG_METHOD)(DISP_OBJ *, int unk, int DisplayWidth, int DisplayHeight);
typedef void (*DISP_OBJ_ONLAYOUT_METHOD)(DISP_OBJ *, void *layoutstruct);
typedef void (*DISP_OBJ_METHOD)(DISP_OBJ *);

typedef struct DISP_DESC
{
	char *name;
	uint16_t DataSize;
	uint16_t field_6;
	DISP_OBJ_METHOD Constructor;
	DISP_OBJ_ONCREATE_METHOD onCreate;
	DISP_OBJ_ONCLOSE_METHOD onClose;
	DISP_OBJ_ONREDRAW_METHOD onRedraw;
	DISP_OBJ_METHOD onRefresh;
	DISP_OBJ_METHOD field_1C;
	DISP_OBJ_ONKEY_METHOD onKey;
	DISP_OBJ_METHOD field_24;
	DISP_OBJ_METHOD field_28;
	DISP_OBJ_ONLAYOUT_METHOD onLayout;
	DISP_OBJ_ONCONFIG_METHOD onConfig;
	DISP_OBJ_METHOD field_34;
	DISP_OBJ_METHOD field_38;
	DISP_OBJ_METHOD field_39;
	DISP_OBJ_METHOD field_3A;
	char field_3B;
} DISP_DESC;

#define EMPTY_REDRAW_METHOD (DISP_OBJ_ONREDRAW_METHOD) - 1

#endif // DISPOBJ_H