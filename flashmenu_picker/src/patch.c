#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#endif

#include <libse.h>
#include <types/UIRichText_types.h>

#include "file_list.h"
#include "patch.h"

const wchar_t INTERNAL_PATH[] = INT_FLASH_PATH;
const wchar_t EXTERNAL_PATH[] = EXT_FLASH_PATH;

int pg_FlashMenuPicker_EnterEvent(void *data, BOOK *book);
int pg_FlashMenuPicker_ExitEvent(void *data, BOOK *book);
int pg_FlashMenuPicker_CancelEvent(void *data, BOOK *book);

int pg_FlashMenuPicker_Pick_EnterEvent(void *data, BOOK *book);
int pg_FlashMenuPicker_Pick_ExitEvent(void *data, BOOK *book);

// clang-format off

const PAGE_MSG bk_msglst_skin[] =
{
    PAGE_ENTER_EVENT, pg_FlashMenuPicker_Pick_EnterEvent,
    PAGE_EXIT_EVENT, pg_FlashMenuPicker_Pick_ExitEvent,
    NIL_EVENT, NULL
};

const PAGE_DESC FlashMenuPicker_Pick_Page = {FlashMenuPicker_Pick_Page_Name, NULL, bk_msglst_skin};

const PAGE_MSG bk_msglst_base[] =
{
    CANCEL_EVENT, pg_FlashMenuPicker_CancelEvent,
    RETURN_TO_STANDBY_EVENT, pg_FlashMenuPicker_CancelEvent,
    NIL_EVENT, NULL
};

const PAGE_DESC FlashMenuPicker_Base_Page = {FlashMenuPicker_Base_Page_Name, NULL, bk_msglst_base};

const PAGE_MSG bk_msglst_main[] =
{
    PAGE_ENTER_EVENT, pg_FlashMenuPicker_EnterEvent,
    PAGE_EXIT_EVENT, pg_FlashMenuPicker_ExitEvent,
    NIL_EVENT, NULL
};

const PAGE_DESC FlashMenuPicker_Main_Page = {FlashMenuPicker_Main_Page_Name, NULL, bk_msglst_main};

// clang-format on

THUMB16 NEWCODE void *malloc(int size)
{
#if defined(DB2020)
    return memalloc(0, size, 1, 5, MEM_NAME, NULL);
#elif defined(A2)
    return memalloc(0xFFFFFFFF, size, 1, 5, MEM_NAME, NULL);
#else
    return memalloc(size, 1, 5, MEM_NAME, NULL);
#endif
}

THUMB16 NEWCODE void mfree(void *mem)
{
    if (mem)
#if defined(DB2020)
        memfree(NULL, mem, MEM_NAME, NULL);
#elif defined(A2)
        memfree(NULL, mem, MEM_NAME, NULL);
#else
        memfree(mem, MEM_NAME, NULL);
#endif
}

#if defined(W550_R4CB020) || defined(W900_R5BC004)
THUMB16 NEWCODE BOOL FSX_IsFileExists(const wchar_t *fpath, const wchar_t *fname)
{
    FSTAT fs;
    return fstat(fpath, fname, &fs) == 0;
}
#endif

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
THUMB16 NEWCODE void _Set_SWF_AsFlashMenu(const wchar_t *fpath, const wchar_t *fname, int *error)
{
    FileDelete(SETTINGS_PATH, FD_IMAGE, NULL);
    ThemeImage_Apply(fpath, fname, SETTINGS_PATH, FD_IMAGE, NULL, NULL);
}
#endif

THUMB16 NEWCODE int FlashMenuPicker_Pick_OnMessage(GUI_MESSAGE *msg)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)GUIonMessage_GetBook(msg);
    switch (GUIonMessage_GetMsg(msg))
    {
    case LISTMSG_GetItem:
        int index = GUIonMessage_GetCreatedItemIndex(msg);
        FILELIST_ELEM *flist = (FILELIST_ELEM *)List_Get(fmbk->flist, index);
        TEXTID text_id = TextID_Create(flist->name, ENC_UCS2, TEXTID_ANY_LEN);
        GUIonMessage_SetMenuItemText(msg, text_id);
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, DB_FLASH_ICN);
        break;
    }
    return 1;
}

THUMB16 NEWCODE void FlashMenuPicker_Pick_Select(BOOK *book, GUI *gui)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    int item = ListMenu_GetSelectedItem(fmbk->sub_menu);
    TEXTID text_id;

    FILELIST_ELEM *flist = (FILELIST_ELEM *)List_Get(fmbk->flist, item);
    if (flist)
    {
        if (FSX_IsFileExists(DEFAULT_FLASH_PATH, CUSTOM_NAME))
            FileDelete(DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);

        if (fmbk->type == ITEM_SYS)
            FileCopy(DEFAULT_FLASH_PATH, flist->filename, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
        else if (fmbk->type == ITEM_INT)
            FileCopy(INTERNAL_PATH, flist->filename, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
#ifdef HAS_EXTERNAL
        else if (fmbk->type == ITEM_EXT)
            FileCopy(EXTERNAL_PATH, flist->filename, DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
#endif

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        _Set_SWF_AsFlashMenu(DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
#else
        Set_SWF_AsFlashMenu(DEFAULT_FLASH_PATH, CUSTOM_NAME, NULL);
#endif

#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
        MainMenu_SetFromUserTheme(TRUE);
#endif

        text_id = TextID_Create(flist->name, ENC_UCS2, TEXTID_ANY_LEN);
        MessageBox(EMPTY_TEXTID, text_id, DB_FLASH_ICN, 1, 1000, &fmbk->book);
    }
    else
    {
        text_id = STR(WARNING);
        MessageBox(EMPTY_TEXTID, text_id, DB_FLASH_ICN, 1, 1000, &fmbk->book);
    }
    FreeBook(&fmbk->book);
}

THUMB16 NEWCODE void FlashMenuPicker_Pick_Preview(BOOK *book, GUI *gui)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    int item = ListMenu_GetSelectedItem(fmbk->sub_menu);

    FILELIST_ELEM *flist = (FILELIST_ELEM *)List_Get(fmbk->flist, item);
    if (flist)
    {
        char *uri;
        char *uri_scheme = GetURIScheme(file);
        if (fmbk->type == ITEM_SYS)
            uri = CreateURI(DEFAULT_FLASH_PATH, flist->filename, uri_scheme);

        else if (fmbk->type == ITEM_INT)
            uri = CreateURI(INTERNAL_PATH, flist->filename, uri_scheme);

#ifdef HAS_EXTERNAL
        else if (fmbk->type == ITEM_EXT)
            uri = CreateURI(EXTERNAL_PATH, flist->filename, uri_scheme);

#endif
        if (Browser_OpenURI(NULL, uri, URI_MODE))
            BookObj_ReturnPage(&fmbk->book, PREVIOUS_EVENT);

        FreeURI(uri);
    }
}

THUMB16 NEWCODE void FlashMenuPicker_Pick_Exit(BOOK *book, GUI *gui)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    file_list_destroy(&fmbk->flist, file_list_remove_item);
    BookObj_ReturnPage(&fmbk->book, PREVIOUS_EVENT);
}

THUMB16 NEWCODE int pg_FlashMenuPicker_Pick_EnterEvent(void *data, BOOK *book)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    FREE_GUI(fmbk->sub_menu);

    if (fmbk->flist)
        file_list_destroy(&fmbk->flist, file_list_remove_item);

    if (fmbk->type == ITEM_SYS)
        fmbk->flist = file_list_create(DEFAULT_FLASH_PATH);
    else if (fmbk->type == ITEM_INT)
        fmbk->flist = file_list_create(INTERNAL_PATH);
#ifdef HAS_EXTERNAL
    else if (fmbk->type == ITEM_EXT)
        fmbk->flist = file_list_create(EXTERNAL_PATH);
#endif

    int count = List_GetCount(fmbk->flist);

    if (fmbk->sub_menu = CreateListMenu(&fmbk->book, UIDisplay_Main))
    {
        GUIObject_SetTitleText(fmbk->sub_menu, SUBMENU_TXT);
        ListMenu_SetItemCount(fmbk->sub_menu, count);
        ListMenu_SetCursorToItem(fmbk->sub_menu, 0);
        ListMenu_SetOnMessage(fmbk->sub_menu, FlashMenuPicker_Pick_OnMessage);
        ListMenu_SetHotkeyMode(fmbk->sub_menu, LKHM_SHORTCUT);
        ListMenu_SetItemTextScroll(fmbk->sub_menu, 1);
#if defined(DB2020) || defined(A2)
        ListMenu_SetNoItemText(fmbk->sub_menu, EMPTY_LIST_TXT);
#endif
        if (count)
        {
            GUIObject_SoftKeys_SetText(fmbk->sub_menu, 0, PREVIEW_SK_TXT);
            GUIObject_SoftKeys_SetAction(fmbk->sub_menu, 0, FlashMenuPicker_Pick_Preview);
            GUIObject_SoftKeys_SetAction(fmbk->sub_menu, ACTION_SELECT1, FlashMenuPicker_Pick_Select);
        }
        GUIObject_SoftKeys_SetAction(fmbk->sub_menu, ACTION_BACK, FlashMenuPicker_Pick_Exit);
        GUIObject_SoftKeys_SetAction(fmbk->sub_menu, ACTION_LONG_BACK, FlashMenuPicker_Pick_Exit);
        GUIObject_Show(fmbk->sub_menu);
    }
    return 1;
}

THUMB16 NEWCODE int pg_FlashMenuPicker_Pick_ExitEvent(void *data, BOOK *book)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    FREE_GUI(fmbk->sub_menu);
    return 1;
}

//--------------------------------------------------------------

THUMB16 NEWCODE void FlashMenuPicker_SelectAction(BOOK *book, GUI *gui)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    fmbk->type = ListMenu_GetSelectedItem(fmbk->main_menu);

    BookObj_CallPage(&fmbk->book, &FlashMenuPicker_Pick_Page);
}

THUMB16 NEWCODE void FlashMenuPicker_ExitAction(BOOK *book, GUI *gui)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    FreeBook(&fmbk->book);
}

THUMB16 NEWCODE int FlashMenuPicker_onMessage(GUI_MESSAGE *msg)
{
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == ITEM_SYS)
    {
        GUIonMessage_SetMenuItemText(msg, ITEM_SYS_TXT);
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ITEM_SYS_ICN);
    }
    else if (item == ITEM_INT)
    {
        GUIonMessage_SetMenuItemText(msg, ITEM_INT_TXT);
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ITEM_INT_ICN);
    }
#ifdef HAS_EXTERNAL
    else if (item == ITEM_EXT)
    {
        GUIonMessage_SetMenuItemText(msg, ITEM_EXT_TXT);
        GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ITEM_EXT_ICN);
    }
#endif
    return 1;
}

THUMB16 NEWCODE int pg_FlashMenuPicker_EnterEvent(void *data, BOOK *book)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    FREE_GUI(fmbk->main_menu);

    if (fmbk->main_menu = CreateListMenu(&fmbk->book, UIDisplay_Main))
    {
        GUIObject_SetTitleText(fmbk->main_menu, MAINMENU_TXT);
        ListMenu_SetItemCount(fmbk->main_menu, ITEM_LAST);
        ListMenu_SetOnMessage(fmbk->main_menu, FlashMenuPicker_onMessage);
        ListMenu_SetCursorToItem(fmbk->main_menu, ITEM_SYS);
        ListMenu_SetHotkeyMode(fmbk->main_menu, LKHM_SHORTCUT);

        GUIObject_SoftKeys_SetAction(fmbk->main_menu, ACTION_SELECT1, FlashMenuPicker_SelectAction);
        GUIObject_SoftKeys_SetAction(fmbk->main_menu, ACTION_BACK, FlashMenuPicker_ExitAction);
        GUIObject_SoftKeys_SetAction(fmbk->main_menu, ACTION_LONG_BACK, FlashMenuPicker_ExitAction);
        GUIObject_Show(fmbk->main_menu);
    }
    return 1;
}

THUMB16 NEWCODE int pg_FlashMenuPicker_ExitEvent(void *data, BOOK *book)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    FREE_GUI(fmbk->main_menu);
    return 1;
}

THUMB16 NEWCODE int pg_FlashMenuPicker_CancelEvent(void *data, BOOK *book)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    FreeBook(&fmbk->book);
    return 1;
}

THUMB16 NEWCODE void FlashMenuPicker_onClose(BOOK *book)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)book;
    FREE_GUI(fmbk->main_menu);
    FREE_GUI(fmbk->sub_menu);
    file_list_destroy(&fmbk->flist, file_list_remove_item);
}

THUMB16 NEWCODE BOOL IsFlashMenuPickerBook(BOOK *book)
{
    return (book->onClose == FlashMenuPicker_onClose);
}

THUMB16 NEWCODE FlashMenuPickerBook *Create_FlashMenuPickerBook()
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)malloc(sizeof(FlashMenuPickerBook));
    memset(fmbk, 0, sizeof(FlashMenuPickerBook));
    if (!CreateBook((BOOK *)fmbk, FlashMenuPicker_onClose, &FlashMenuPicker_Base_Page, BOOKNAME, NO_BOOK_ID, NULL))
    {
        mfree(fmbk);
        return 0;
    }
    fmbk->main_menu = 0;
    fmbk->sub_menu = 0;
    fmbk->flist = 0;
    fmbk->type = 0;
    return fmbk;
}

THUMB16 NEWCODE void FlashmenuPicker(BOOK *book, GUI *gui)
{
    FlashMenuPickerBook *fmbk = (FlashMenuPickerBook *)FindBook(IsFlashMenuPickerBook);
    if (fmbk)
        BookObj_SetFocus(&fmbk->book, UIDisplay_Main);
    else
    {
        fmbk = Create_FlashMenuPickerBook();
        BookObj_GotoPage(&fmbk->book, &FlashMenuPicker_Main_Page);
    }
#if defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
    FreeBook(book);
#endif
}
