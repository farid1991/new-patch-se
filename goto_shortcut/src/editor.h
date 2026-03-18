#ifndef _EDITOR_H_
#define _EDITOR_H

// clang-format off

static const wchar_t ELF_EXT[] = L"*.elf";

static const char MENU_ITEM_STR[] = "Menu Item";
static const char JAVA_ITEM_STR[] = "Java";
static const char ELF_ITEM_STR[] = "Elf";
static const char BRW_ITEM_STR[] = "Folder";

static const char *TypesCaptions[TYPE_LAST] = 
{
	MENU_ITEM_STR, 
	JAVA_ITEM_STR, 
	ELF_ITEM_STR,
	BRW_ITEM_STR 
};

static const IMAGEID TypesIcons[TYPE_LAST] = 
{
	SHORTCUT_LIST_ICN, 
	DB_LIST_JAVA_ICN, 
	ENTERTAINMENT_ICN, 
	DB_LIST_FOLDER_ICN
};

static const IMAGEID EditorIcons[2] = {HPB_OTHER_ICN, MENU_SETTINGS_ICN};

// clang-format on

void *ShortcutDesc_Init(wchar_t *param);
int CreateCaptionInput(void *data, BOOK *book);
int CloseCaptionInput(void *data, BOOK *book);
int CreateTypesList(void *data, BOOK *book);
int CloseTypesList(void *data, BOOK *book);
void EditorRun(BOOK *book, int mode);
int pg_SC_Editor_Main_AcceptAction(void *data, BOOK *book);

#endif // _EDITOR_H_
