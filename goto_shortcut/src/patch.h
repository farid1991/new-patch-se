#ifndef _MAIN_H_
#define _MAIN_H_

static const wchar_t CONFIG_NAME[] = L"sc.bin";

enum MODES
{
	EDITING_MODE,
	ADDING_MODE
};

enum SHORTCUT_TYPE
{
	TYPE_SHORTCUT,
	TYPE_JAVA,
	TYPE_ELF,
	TYPE_FOLDER,
	TYPE_LAST
};

typedef struct
{
	wchar_t *name;
	wchar_t *fullpath;
	IMAGEID image_id;
} JAVA_LIST_ELEM;

#define SHORTCUT_TYPES_MAX_LEN 0x1D
#define CAPTION_MAX_LEN 0x1F

typedef struct
{
	char Type_f;
	wchar_t sData_f[SHORTCUT_TYPES_MAX_LEN];
	wchar_t Caption_f[CAPTION_MAX_LEN];
	int Icon_f;
} SHORTCUT_FILE;

typedef struct
{
	uint8_t ScType;
	wchar_t *ScLink;
	wchar_t *ScText;
	IMAGEID ScIcon;
} SC_LIST_ELEM;

typedef struct GotoShortcut_Book
{
	BOOK book;
	GUI_LIST *MainMenu;
	GUI_LIST *Editor;
	GUI_LIST *JavaMenu;
	GUI_LIST *Types;
	GUI *CaptionInput;
	GUI *YesNoQuestion;
	GUI *FolderInput;
	GUI_LIST *FSBrowser;
	LIST *ShortcutList;
	LIST *JavaList;
	SC_LIST_ELEM *ShortcutItem;
	void *fltop;
	uint8_t CurrentItem;
	uint8_t FType;
	int MainMenuID;
} GotoShortcut_Book;

int IsGotoShortcutBook(BOOK *bk);
int pg_Goto_Shortcut_AcceptEvent(void *data, BOOK *bk);
int pg_Goto_Shortcut_CancelEvent(void *data, BOOK *bk);
int pg_Goto_Shortcut_EnterEvent(void *data, BOOK *bk);

void ShortcutFree(void *Item);

void *malloc(int size);
void mfree(void *mem);

#endif
