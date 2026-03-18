#ifndef _FS_BROWSER_H_
#define _FS_BROWSER_H_

#define MAX_PATH_LEN 255

enum FILEFOLDERTYPES
{
	ITEM_PREV,
	ITEM_FOLDER,
	ITEM_FILE
};

enum SELF
{
	SEL_FOLDER,
	SEL_FILE
};

typedef struct FILELIST
{
	void *next;
	int is_folder;
	wchar_t *fullpath;
	wchar_t *str_name;
} FILELIST;

GUI_LIST *Create_FsBrowser(BOOK *book, wchar_t *path);

#endif // _FS_BROWSER_H_
