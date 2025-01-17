#ifndef DATA_BROWSER_H
#define DATA_BROWSER_H

#include <base.h>
#include <bookobj.h>
#include <gui_feedback.h>
#include <imageid.h>
#include <textid.h>

struct SUB_EXECUTE;

typedef struct FILESUBROUTINE
{
	int cmd;
	union
	{
		int (*ON_CMD)(struct SUB_EXECUTE *);
		int (*ON_CMD_RUN)(struct SUB_EXECUTE *);
		int (*ON_CMD_ICON)(struct SUB_EXECUTE *, IMAGEID *iconid);
		int (*ON_CMD_TEXTID)(struct SUB_EXECUTE *, TEXTID *strid);
	};
	TEXTID StrID;
	union
	{
		int (*ON_CHECK)(struct SUB_EXECUTE *, void *);
		int (*ON_CMD_RUN_CHECK)(struct SUB_EXECUTE *);
	};
#ifdef DB3350
	TEXTID StrID_1;
#endif
} FILESUBROUTINE;

typedef struct FILEITEM
{
	wchar_t *__fname; // use FILEITEM_SetFname / FILEITEM_GetFname
	wchar_t *__path;  // use FILEITEM_SetPath / FILEITEM_GetPath
	char *MIME_type;
	wchar_t *extension;
	int *FSTAT;
	int *DRMHandle;
	uint8_t DRM_Flag;
} FILEITEM;

typedef struct DB_EXT_FOLDERS
{
	TEXTID StrID_FolderName;
	TEXTID StrID_SavedTo;
	wchar_t *Path;
	BOOL isInternal;
} DB_EXT_FOLDERS;

typedef struct DB_EXT
{
	char **content_type;
	wchar_t **ext_list;
	void (*GetMethods)(struct SUB_EXECUTE *);
	int sub_execute_size;
	const DB_EXT_FOLDERS *dbf;
	uint8_t type_group;
	int drm_flags;
	uint8_t unk2;
	uint8_t unk3;
} DB_EXT;

typedef struct DB_EXT_2010
{
	char **content_type;
	wchar_t **ext_list;
	void (*GetMethods)(struct SUB_EXECUTE *);
	int sub_execute_size;
	const DB_EXT_FOLDERS *dbf;
	int drm_flags;
	uint8_t unk2;
	uint8_t unk3;
} DB_EXT_2010;

typedef struct SUB_EXECUTE
{
	FILESUBROUTINE *filesub;
	FILEITEM *file_item;
	BOOK *BrowserItemBook;
	uint32_t DB_BookID;
	void *unk2;
	GUI *gui;
	GUI_FEEDBACK *gui_fb;
	void *strinp_struct;
	char dummy1[0x2D0];
#if defined(DB3150v1) || defined(DB3150v2)
	char dummy2[0x4];
#endif
	void *pIMMEPlayer;
} SUB_EXECUTE;

typedef int (*DB_FILE_FILTER)(const wchar_t *ExtList, const wchar_t *ItemPath, const wchar_t *ItemName);

#endif // DATA_BROWSER_H