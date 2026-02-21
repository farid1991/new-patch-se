#ifndef _MAIN_H_
#define _MAIN_H_

static const char MEM_NAME[] = "swf_mem";
// static char EMP_NAME[] = "swf_emp";

#if defined(DB2000) || defined(DB2010)
#define URI_MODE 1
#else
#define URI_MODE 2
#endif

static const wchar_t CUSTOM_NAME[] = L"Flash_Menu_Custom.swf";
static const char BOOKNAME[] = "FlashMenuPickerBook";
static const char WARNING[] = "Can not set SWF as Flash Menu";

static const char FlashMenuPicker_Pick_Page_Name[] = "FlashMenuPicker_Pick_Page";
static const char FlashMenuPicker_Base_Page_Name[] = "FlashMenuPicker_Base_Page";
static const char FlashMenuPicker_Main_Page_Name[] = "FlashMenuPicker_Main_Page";

enum
{
    ITEM_SYS,
    ITEM_INT,
#ifdef EXT_FLASH_PATH
    ITEM_EXT,
#endif
    ITEM_LAST
};

typedef struct FlashMenuPickerBook
{
    BOOK book;
    GUI_LIST *main_menu;
    GUI_LIST *sub_menu;
    LIST *flist;
    int type;
} FlashMenuPickerBook;

typedef struct FlashDesktopBook
{
    BOOK book;
    GUI *main_menu;
    IMAGEID img;
} FlashDesktopBook;

void *malloc(int size);
void mfree(void *mem);

#endif
