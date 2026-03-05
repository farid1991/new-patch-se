#ifndef _MAIN_H_
#define _MAIN_H_

#define ELF_BCFG_CONFIG_EVENT 994
#define ELF_SHOW_INFO_EVENT 998
#define ELF_TERMINATE_EVENT 997
#define ELF_RECONFIG_EVENT 996
#define SBY_REDRAW_RELEASE_EVENT 995

enum
{
    TAB_EVENTS,
    TAB_BOOKS,
    TAB_ELFS,
    TAB_SHORTCUTS
};

enum
{
    SHC_ITEM_1,
    SHC_ITEM_2,
    SHC_ITEM_3,
    SHC_ITEM_4,
    SHC_ITEM_5,
    SHC_ITEM_LAST,
};

enum
{
    BCFG_NULL,
    BCFG_NOTFOUND,
    BCFG_SUCCESS
};

#define ELF_BCFG_CONFIG_EVENT 994

#define FLASH_MASK 0xF8000000
#define MAX_BOOK_NAME_LEN 50

static const wchar_t INI_PATH[] = L"/usb/other/ini";
static const wchar_t BOOKMAN_INI[] = L"bookman.ini";
static const wchar_t SHORTCUT_INI[] = L"shortcut.ini";
static const wchar_t BCFGEDIT_PATH[] = L"/usb/other/ZBin/BcfgEdit.elf";

#define mfree_adr() mfree

typedef struct BOOK_MANAGER
{
    BOOK *ActivityMenu;
    DISP_OBJ_ONKEY_METHOD oldOnKey;
    GUI_LIST *books_menu;
    GUI_LIST *elf_menu;
    GUI_LIST *sc_menu;
    LIST *books_list;
    LIST *elfs_list;
    uint8_t book_index;
    uint8_t elf_index;
    uint8_t books_count;
    uint8_t elfs_count;
    uint8_t tab_pos;
    size_t books_name_size;
    char *books_name_buf;
    size_t shortcut_size;
    char *shortcut_buf;
} BOOK_MANAGER;

typedef struct
{
    BOOK *book;
    char *book_name;
    IMAGEID book_icon;
    uint8_t gui_count;
    bool isJava;
} BOOK_LIST_ELEM;

typedef struct
{
    BOOK *book;
} MSG;

typedef struct
{
    BOOK *book;
    wchar_t *bcfg_p;
    wchar_t *bcfg_n;
} MSG_BCFG;

#endif
