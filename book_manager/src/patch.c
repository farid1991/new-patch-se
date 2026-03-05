#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <types/UIRichText_types.h>

#ifdef A1
#include <book/RightNowBook.h>
#else
#include <book/ActivityMenuBook.h>
#endif

#include "patch.h"

extern int isrsstickerbook(BOOK *book);

static const char MEM_NAME[] = "bm_mem";
static const char EMP_NAME[] = "bm_emp";

static const char BCFGEDIT_NOT_FOUND[] = "BcfgEdit.elf not found!";
static const char BCFGEDIT_NOT_SUPPORT[] = "ELF doesn't support BcfgConfigEvent";

static const wchar_t ELF_KILL_FMT[] = L"TerminateEvent not supported by %s";
static const wchar_t ELF_ACTIVE_FMT[] = L"Active ELFs: %d";
static const char ELF_CANT_FOCUS_WO_GUI[] = "Can't set focus to ELF without GUI...";
static const char ELF_CONFIG[] = "Config";
static const char ELF_AUTHOR[] = "Author";
static const char ELF_UNK_AUTHOR[] = "Unknown Author";
static const char ELF_EMPTY_LIST[] = "No ELF in memory";

static const char SC_TITLE[] = "My shortcut";
static const char SC_SHUTDOWN[] = "Shutdown";
static const char SC_RESTART[] = "Restart";
static const char SC_FLIGHT_UNAVAI[] = "Flightmode: not available";
static const char SC_FLIGHT_ON[] = "Flightmode: on";
static const char SC_FLIGHT_OFF[] = "Flightmode: off";
static const char SC_CLOSE_CONNECT[] = "Close connection";
static const wchar_t SC_BRIGHTNESS_FMT[] = L"Brightness: %d%%";

static const wchar_t HEAP_FMT[] = L"Heap: %dKB";
static const wchar_t NEW_EVENTS_FMT[] = L"New event: %d";

static const char SC_KEY_FMT[] = "[KEY_%d]:";
static const char ICON_PARAM[] = "ICON";

#ifdef DB2010
static const wchar_t JAVA_FOREIGN_APP[] = L"Foreign app";
static const wchar_t JAVA_STR[] = L"Java";
#endif

ARM32 NEWCODE int openWithBcfgEdit(const wchar_t *bcfgedit_path, const wchar_t *fpath, const wchar_t *fname)
{
    int ret;

    __asm__ volatile(
        "mov r0, %1\n"
        "mov r1, %2\n"
        "mov r2, %3\n"
        "mov r3, #0\n"
        "svc 0x10D\n"
        "mov %0, r0\n"
        : "=r"(ret)
        : "r"(bcfgedit_path), "r"(fpath), "r"(fname)
        : "r0", "r1", "r2", "r3", "lr", "memory");

    return ret;
}

THUMB16 NEWCODE void *malloc(int size)
{
#if defined(DB2020)
    return memalloc(0, size, 1, 5, MEM_NAME, 0);
#elif defined(A2)
    return memalloc(-1, size, 1, 5, MEM_NAME, 0);
#else
    return memalloc(size, 1, 5, MEM_NAME, 0);
#endif
}

THUMB16 NEWCODE void mfree(void *mem)
{
    if (mem)
#if defined(DB2020) || defined(A2)
        memfree(0, mem, MEM_NAME, 0);
#else
        memfree(mem, MEM_NAME, 0);
#endif
}

THUMB16 NEWCODE BOOK_MANAGER *CreateData()
{
    BOOK_MANAGER *data = (BOOK_MANAGER *)malloc(sizeof(BOOK_MANAGER));
    memset(data, 0, sizeof(BOOK_MANAGER));
    data->tab_pos = TAB_BOOKS;
    set_envp(NULL, EMP_NAME, (OSADDRESS)data);
    return data;
}

THUMB16 NEWCODE BOOK_MANAGER *GetData()
{
    BOOK_MANAGER *data = (BOOK_MANAGER *)get_envp(NULL, EMP_NAME);
    if (data)
        return data;
    return CreateData();
}

#if defined(A1) || defined(DB3150v1)
#define _ConnectionManager_Connection_GetState() ConnectionManager_Connection_GetState()
#else
THUMB16 NEWCODE int _ConnectionManager_Connection_GetState()
{
    char buf = 0;
    ConnectionManager_Connection_GetState_A2(&buf);
    return (buf ? TRUE : FALSE);
}
#endif

THUMB16 NEWCODE void win12512unicode(wchar_t *ws, char *s, int len)
{
    int c;
    while ((c = *s++) && ((len--) > 0))
    {
        if (c == 0xA8)
            c = 0x401;
        if (c == 0xAA)
            c = 0x404;
        if (c == 0xAF)
            c = 0x407;
        if (c == 0xB8)
            c = 0x451;
        if (c == 0xBA)
            c = 0x454;
        if (c == 0xBF)
            c = 0x457;
        if ((c >= 0xC0) && (c < 0x100))
            c += 0x350;
        *ws++ = c;
    }
    *ws = 0;
}

THUMB16 NEWCODE int wcharh2int(wchar_t n)
{
    int r = 0;
    if (n >= '0' && n <= '9')
        r = n - 0x30;
    if (n == 'a' || n == 'A')
        r = 10;
    if (n == 'b' || n == 'B')
        r = 11;
    if (n == 'c' || n == 'C')
        r = 12;
    if (n == 'd' || n == 'D')
        r = 13;
    if (n == 'e' || n == 'E')
        r = 14;
    if (n == 'f' || n == 'F')
        r = 15;
    return r;
}

THUMB16 NEWCODE void GetIconByName(wchar_t *name, int *imageid)
{
    if (name[0] == '0' && name[1] == 'x')
    {
        *imageid = 0;
        int N = 0x1000;
        for (int i = 0; i < 4; i++)
        {
            *imageid += wcharh2int(name[2 + i]) * N;
            N = N >> 4;
        }
    }
    else
    {
        iconidname2id(name, -1, imageid);
    }
}

THUMB16 NEWCODE TEXTID GetJavaName(BOOK *book)
{
#ifdef DB2010
    wchar_t ws[100];
    TextID_GetWString(BookObj_GetSession(book)->name, ws, MAXELEMS(ws));

    if (!wstrncmp(ws, JAVA_FOREIGN_APP, 11))
        return JavaSession_GetName();

    if (!wstrcmp(ws, JAVA_STR))
        return JavaSession_GetName();
#endif
    return EMPTY_TEXTID;
}

THUMB16 NEWCODE int read_ini_file(const wchar_t *filename, char **ini_data)
{
    char *data = NULL;
    int fsize = 0;
    FSTAT _fstat;
    if (!fstat(INI_PATH, filename, &_fstat))
    {
        int file = _fopen(INI_PATH, filename, FSX_O_RDONLY, FSX_S_IREAD, NULL);
        if (file != -1)
        {
            fsize = _fstat.fsize;
            data = (char *)malloc(fsize + 1);
            fread(file, data, fsize);
            fclose(file);
        }
    }
    *ini_data = data;
    return fsize;
}

THUMB16 NEWCODE void Load_booknames(BOOK_MANAGER *data)
{
    char *buffer;
    if (data->books_name_size = read_ini_file(BOOKMAN_INI, &buffer))
    {
        if (data->books_name_buf)
            mfree(data->books_name_buf);

        data->books_name_buf = buffer;
    }
}

THUMB16 NEWCODE void Load_shortcuts(BOOK_MANAGER *data)
{
    char *buffer;
    if (data->shortcut_size = read_ini_file(SHORTCUT_INI, &buffer))
    {
        if (data->shortcut_buf)
            mfree(data->shortcut_buf);

        data->shortcut_buf = buffer;
    }
}

THUMB16 NEWCODE int GetActiveTab(BOOK *book)
{
    ActivityMenuBook *mbk = (ActivityMenuBook *)book;
    return TabMenuBar_GetFocusedTab(mbk->main_tab);
}

THUMB16 NEWCODE BOOK_LIST_ELEM *GetBookListItem(int tab_num)
{
    BOOK_MANAGER *data = GetData();
    data->tab_pos = tab_num;

    BOOK_LIST_ELEM *elem;
    if (tab_num == TAB_BOOKS)
    {
        data->book_index = ListMenu_GetSelectedItem(data->books_menu);
        elem = (BOOK_LIST_ELEM *)List_Get(data->books_list, data->book_index);
    }
    else
    {
        if (data->elfs_count)
            elem = (BOOK_LIST_ELEM *)List_Get(data->elfs_list, data->elf_index);
        else
            return NULL;
    }
    return elem;
}

THUMB16 NEWCODE BOOK *GetBook(int tab_num)
{
    BOOK_LIST_ELEM *elem = GetBookListItem(tab_num);
    return (elem ? elem->book : NULL);
}

THUMB16 NEWCODE BOOL CheckEvent(BOOK *book, int event)
{
    if (book->base_page)
    {
        const PAGE_MSG *pm = book->base_page->msg_lst;
        if (pm)
        {
            while (pm->msg && pm->proc)
            {
                if (pm->msg == event)
                    return TRUE;
                pm++;
            }
        }
    }
    return FALSE;
}

THUMB16 NEWCODE void kill_book_and_elf(BOOK *book, GUI *gui)
{
    BOOK_MANAGER *data = GetData();
    int active_tab = GetActiveTab(book);
    data->tab_pos = active_tab;

    if (active_tab == TAB_BOOKS)
    {
        BOOK_LIST_ELEM *elem = GetBookListItem(TAB_BOOKS);
        if (!elem)
            return;

        BOOK *selected_book = elem->book;
        if (selected_book != Find_StandbyBook())
        {
            if (elem->isJava)
            {
                UI_Event_toBookID(TERMINATE_SESSION_EVENT, BookObj_GetBookID(selected_book));
            }
            else
            {
                if (CheckEvent(selected_book, TERMINATE_SESSION_EVENT))
                {
                    UI_Event_toBookID(TERMINATE_SESSION_EVENT,
                                      BookObj_GetBookID((BOOK *)List_Get(selected_book->xbook->app_session->listbook,
                                                                         List_GetCount(selected_book->xbook->app_session->listbook) - 1)));
                }
                else if (CheckEvent(selected_book, RETURN_TO_STANDBY_EVENT))
                {
                    UI_Event_toBookID(RETURN_TO_STANDBY_EVENT,
                                      BookObj_GetBookID((BOOK *)List_Get(selected_book->xbook->app_session->listbook,
                                                                         List_GetCount(selected_book->xbook->app_session->listbook) - 1)));
                }
            }
            UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
        }
    }
    else
    {
        if (!data->elfs_count)
            return;

        BOOK *selected_book = GetBook(TAB_ELFS);
        if (selected_book)
        {
            if (CheckEvent(selected_book, RETURN_TO_STANDBY_EVENT))
                UI_Event_toBookID(RETURN_TO_STANDBY_EVENT, BookObj_GetBookID(selected_book));
            else
            {
                if (CheckEvent(selected_book, ELF_TERMINATE_EVENT))
                    UI_Event_toBookID(ELF_TERMINATE_EVENT, BookObj_GetBookID(selected_book));
                else
                {
                    wchar_t buf[64];
                    snwprintf(buf, MAXELEMS(buf), ELF_KILL_FMT, selected_book->xbook->name);
                    MessageBox_NoImage(EMPTY_TEXTID, TextID_Create(buf, ENC_UCS2, MAXELEMS(buf)), 1, 0, selected_book);
                }
            }
            UI_Event(RESTARTED_ACTIVITY_MENU_EVENT);
        }
    }
}

THUMB16 NEWCODE void Close_Activitymenu(BOOK *book, GUI *gui)
{
    BOOK_MANAGER *data = GetData();
    data->tab_pos = GetActiveTab(book);

    FreeBook(book);
}

THUMB16 NEWCODE void Exit_to_Standby(BOOK *book, GUI *gui)
{
    BOOK_MANAGER *data = GetData();
    data->tab_pos = GetActiveTab(book);

    FreeBook(book);
    UI_Event(RETURN_TO_STANDBY_EVENT);
}

THUMB16 NEWCODE void onEnterPressed_Books(BOOK *book, GUI *gui)
{
    BOOK *selected_book = GetBook(TAB_BOOKS);
    if (selected_book)
    {
        BookObj_SetFocus(selected_book, UIDisplay_Main);
        FreeBook(book);
    }
}

THUMB16 NEWCODE void minimise_all_books(BOOK *book)
{
    BOOK *standbyBook = Find_StandbyBook();
    if (standbyBook)
    {
        BookObj_SetFocus(standbyBook, UIDisplay_Main);
        FreeBook(book);
    }
}

THUMB16 NEWCODE void close_all_books(BOOK *book)
{
    UI_Event(RETURN_TO_STANDBY_EVENT);
    FreeBook(book);
}

THUMB16 NEWCODE void parse_and_run_shorcut(BOOK_MANAGER *data, int key)
{
    if (!data->shortcut_buf)
        return;

    char mask[64];
    sprintf(mask, SC_KEY_FMT, key - KEY_DIGITAL_0);

    char *param = manifest_GetParam(data->shortcut_buf, mask, NULL);
    if (param)
    {
        wchar_t name[128];
        str2wstr(name, param);
        Shortcut_Run(name);

        mfree(param);
        FreeBook(data->ActivityMenu);
    }
}

THUMB16 NEWCODE void myOnKey_Unified(DISP_OBJ *disp_obj, int key, int count, int repeat, int mode)
{
    BOOK_MANAGER *data = GetData();

    data->oldOnKey(disp_obj, key, count, repeat, mode);

    if (mode == KBD_SHORT_RELEASE)
    {
        if (key == KEY_DIEZ)
            minimise_all_books(data->ActivityMenu);

        else if (key == KEY_STAR)
            close_all_books(data->ActivityMenu);

        else if (key == KEY_DEL)
            kill_book_and_elf(data->ActivityMenu, NULL);

        else if ((key - KEY_DIGITAL_0) <= 9)
            parse_and_run_shorcut(data, key);
    }
}

THUMB16 NEWCODE TEXTID Get_BookName(BOOK_MANAGER *data, char *book_name)
{
    wchar_t ws[MAX_BOOK_NAME_LEN];
    TEXTID ret = 0;

    if (data->books_name_buf)
    {
        char *param;
        if (param = manifest_GetParam(data->books_name_buf, book_name, NULL))
        {
            win12512unicode(ws, param, (MAX_BOOK_NAME_LEN - 1));
            ret = TextID_Create(ws, ENC_UCS2, TEXTID_ANY_LEN);
            mfree(param);
            return ret;
        }
    }
    if (!ret)
    {
        win12512unicode(ws, book_name, (MAX_BOOK_NAME_LEN - 1));
        ret = TextID_Create(ws, ENC_UCS2, wstrlen(ws));
    }
    return ret;
}

THUMB16 NEWCODE IMAGEID Get_BookIcon(BOOK_MANAGER *data, char *book_name, int iconid)
{
    char *pos;
    char *end_pos;
    wchar_t ws[MAX_BOOK_NAME_LEN];

    int ret = 0;

    if (data->books_name_buf)
    {
        char *param;
        pos = strstr(data->books_name_buf, book_name);
        end_pos = pos + strlen(book_name) + sizeof("\r\n") - sizeof("");
        if (param = manifest_GetParam(end_pos, ICON_PARAM, 0))
        {
            win12512unicode(ws, param, (MAX_BOOK_NAME_LEN - 1));
            GetIconByName(ws, &ret);
            mfree(param);
        }
    }

    if (!ret)
        ret = iconid;

    return ret;
}

THUMB16 NEWCODE int BookMenu_onMessage(GUI_MESSAGE *msg)
{
    BOOK_MANAGER *data = GetData();
    switch (GUIonMessage_GetMsg(msg))
    {
    case LISTMSG_GetItem:
        int index = GUIonMessage_GetCreatedItemIndex(msg);
        BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)List_Get(data->books_list, index);
        GUIonMessage_SetMenuItemText(msg, Get_BookName(data, elem->book_name));

        if (elem->isJava)
            GUIonMessage_SetMenuItemIcon(msg, AlignLeft, elem->book_icon);
        else
            GUIonMessage_SetMenuItemIcon(msg, AlignLeft, Get_BookIcon(data, elem->book_name, BOOK_ITEM_ICON));

        break;
    }
    return 1;
}

THUMB16 NEWCODE TEXTID Get_FreeHeap()
{
    wchar_t buf[32];
    snwprintf(buf, MAXELEMS(buf), HEAP_FMT, GetFreeBytesOnHeap() >> 10);
    return TextID_Create(buf, ENC_UCS2, MAXELEMS(buf));
}

THUMB16 NEWCODE void CreateBookMenu(BOOK *book, int tab_num)
{
    ActivityMenuBook *mbk = (ActivityMenuBook *)book;

    BOOK_MANAGER *data = GetData();
    data->ActivityMenu = book;

    if (data->book_index > data->books_count - 1)
        data->book_index = data->books_count - 1;

    data->books_menu = CreateListMenu(&mbk->book, UIDisplay_Main);
    ListMenu_SetOnMessage(data->books_menu, BookMenu_onMessage);
    ListMenu_SetItemCount(data->books_menu, data->books_count);
    ListMenu_SetCursorToItem(data->books_menu, data->book_index);
    GUIObject_SetStyle(data->books_menu, UI_OverlayStyle_PopupNoFrame);
    GUIObject_TabTitleRemove(data->books_menu, 1);
    GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_BACK, Close_Activitymenu);
    GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_LONG_BACK, Exit_to_Standby);
    GUIObject_SoftKeys_SetAction(data->books_menu, ACTION_SELECT1, onEnterPressed_Books);

    data->oldOnKey = DispObject_GetOnKey(GUIObject_GetDispObject(data->books_menu));
    DISP_DESC_SetOnKey(DispObject_GetDESC(GUIObject_GetDispObject(data->books_menu)), myOnKey_Unified);

    TabMenuBar_SetTabGui(mbk->main_tab, tab_num, data->books_menu);
    TabMenuBar_SetTabTitle(mbk->main_tab, tab_num, Get_FreeHeap());
}

THUMB16 NEWCODE void onEnterPressed_Elfs(BOOK *book, GUI *gui)
{
    BOOK *selected_book = GetBook(TAB_ELFS);
    if (selected_book)
    {
        BookObj_SetFocus(selected_book, UIDisplay_Main);
        FreeBook(book);
    }
}

THUMB16 NEWCODE void onAuthor(BOOK *book, GUI *gui)
{
    BOOK *selected_book = GetBook(TAB_ELFS);
    if (selected_book)
    {
        if (CheckEvent(selected_book, ELF_SHOW_INFO_EVENT))
        {
            MSG *msg = (MSG *)malloc(sizeof(MSG));
            msg->book = book;
            UI_Event_toBookIDwData(ELF_SHOW_INFO_EVENT, BookObj_GetBookID(selected_book), msg, (void (*)(void *))mfree_adr());
        }
        else
            MessageBox_NoImage(EMPTY_TEXTID, STR(ELF_UNK_AUTHOR), 1, 0, book);
    }
}

THUMB16 NEWCODE void RefreshElfSoftkeys(BOOK_MANAGER *data)
{
    if (data->elfs_count)
    {
        BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)List_Get(data->elfs_list, data->elf_index);
        if (!elem->gui_count)
            GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_SELECT1, FALSE);
        else
            GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_SELECT1, TRUE);

        GUIObject_SoftKeys_SetEnable(data->elf_menu, ACTION_DELETE, TRUE);
        GUIObject_SoftKeys_SetVisible(data->elf_menu, 0, TRUE);
        GUIObject_SoftKeys_SetVisible(data->elf_menu, 1, TRUE);
    }
    else
    {
        ListMenu_SetNoItemText(data->elf_menu, STR(ELF_EMPTY_LIST));
        GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_SELECT1, FALSE);
        GUIObject_SoftKeys_SetEnable(data->elf_menu, ACTION_DELETE, FALSE);
        GUIObject_SoftKeys_SetVisible(data->elf_menu, 0, FALSE);
        GUIObject_SoftKeys_SetVisible(data->elf_menu, 1, FALSE);
        data->elf_index = 0;
    }
}

THUMB16 NEWCODE int Elf_OpenFile(const wchar_t *filepath, const wchar_t *filename)
{
    W_FSTAT _wstat;
    if (!w_fstat(BCFGEDIT_PATH, &_wstat))
    {
    }
    else
        return BCFG_NOTFOUND; // BcfgEdit not found

    if (!filepath || !filename)
        return BCFG_SUCCESS; // success

    openWithBcfgEdit(BCFGEDIT_PATH, filepath, filename);
    return BCFG_NULL;
}

THUMB16 NEWCODE void onBcfgConfig(BOOK *book, GUI *lt)
{
    BOOK *selected_book = GetBook(TAB_ELFS);
    if (selected_book)
    {
        if (CheckEvent(selected_book, ELF_BCFG_CONFIG_EVENT))
        {
            int err = Elf_OpenFile(NULL, NULL);
            if (err == BCFG_SUCCESS)
            {
                wchar_t bcfg_path[256];
                wchar_t bcfg_name[256];

                MSG_BCFG *msg = (MSG_BCFG *)malloc(sizeof(MSG_BCFG));
                msg->book = book;
                msg->bcfg_p = bcfg_path;
                msg->bcfg_n = bcfg_name;
                UI_Event_toBookIDwData(ELF_BCFG_CONFIG_EVENT, BookObj_GetBookID(selected_book), msg, (void (*)(void *))mfree);
            }
            else if (err == BCFG_NOTFOUND)
                MessageBox_NoImage(EMPTY_TEXTID, STR(BCFGEDIT_NOT_FOUND), 1, 0, book);
        }
        else
            MessageBox_NoImage(EMPTY_TEXTID, STR(BCFGEDIT_NOT_SUPPORT), 1, 0, book);
    }
}

THUMB16 NEWCODE int ElfMenu_onMessage(GUI_MESSAGE *msg)
{
    BOOK_MANAGER *data = GetData();
    switch (GUIonMessage_GetMsg(msg))
    {
    case LISTMSG_GetItem:
        if (data->elfs_count)
        {
            int index = GUIonMessage_GetCreatedItemIndex(msg);
            BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)List_Get(data->elfs_list, index);
            GUIonMessage_SetMenuItemText(msg, Get_BookName(data, elem->book_name));
            GUIonMessage_SetMenuItemIcon(msg, AlignLeft, ELFS_ITEM_ICON);
            if (!elem->gui_count)
            {
                GUIonMessage_SetItemDisabled(msg, TRUE);
                GUIonMessage_SetMenuItemUnavailableText(msg, STR(ELF_CANT_FOCUS_WO_GUI));
            }
        }
        break;
    case LISTMSG_HighlightChanged:
        data->elf_index = GUIonMessage_GetSelectedItem(msg);
        RefreshElfSoftkeys(data);
        break;
    }
    return 1;
}

THUMB16 NEWCODE TEXTID GetElfCountTextID(BOOK_MANAGER *data)
{
    wchar_t buf[16];
    snwprintf(buf, MAXELEMS(buf), ELF_ACTIVE_FMT, data->elfs_count);
    return TextID_Create(buf, ENC_UCS2, MAXELEMS(buf));
}

THUMB16 NEWCODE void CreateElfMenu(BOOK *book, int tab_num)
{
    ActivityMenuBook *mbk = (ActivityMenuBook *)book;

    BOOK_MANAGER *data = GetData();

    if (data->elf_index > data->elfs_count - 1)
        data->elf_index = data->elfs_count - 1;

    data->elf_menu = CreateListMenu(&mbk->book, UIDisplay_Main);
    ListMenu_SetOnMessage(data->elf_menu, ElfMenu_onMessage);
    ListMenu_SetItemCount(data->elf_menu, data->elfs_count);
    ListMenu_SetCursorToItem(data->elf_menu, data->elf_index);
    GUIObject_SetStyle(data->elf_menu, UI_OverlayStyle_PopupNoFrame);
    GUIObject_TabTitleRemove(data->elf_menu, 1);
    GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_BACK, Close_Activitymenu);
    GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_LONG_BACK, Exit_to_Standby);
    GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_SELECT1, onEnterPressed_Elfs);

    GUIObject_SoftKeys_SetAction(data->elf_menu, ACTION_DELETE, kill_book_and_elf);
    GUIObject_SoftKeys_SetVisible(data->elf_menu, ACTION_DELETE, FALSE);
    GUIObject_SoftKeys_SetAction(data->elf_menu, 0, onBcfgConfig);
    GUIObject_SoftKeys_SetText(data->elf_menu, 0, STR(ELF_CONFIG));
    GUIObject_SoftKeys_SetAction(data->elf_menu, 1, onAuthor);
    GUIObject_SoftKeys_SetText(data->elf_menu, 1, STR(ELF_AUTHOR));

    RefreshElfSoftkeys(data);

    TabMenuBar_SetTabGui(mbk->main_tab, tab_num, data->elf_menu);
    TabMenuBar_SetTabTitle(mbk->main_tab, tab_num, GetElfCountTextID(data));
}

#ifndef DB2010
THUMB16 NEWCODE void ShortcutMenu_onEnterPressed(BOOK *book, GUI *gui)
{
    BOOK_MANAGER *data = GetData();
    int item = ListMenu_GetSelectedItem(data->sc_menu);
    if (item == SHC_ITEM_1)
        REQUEST_SYSTEM_SHUTDOWN();

    else if (item == SHC_ITEM_2)
        REQUEST_SYSTEM_RESTART();

    else if (item == SHC_ITEM_3)
        Shortcut_Run(BRIGHTNESS_SHC);

    else if (item == SHC_ITEM_4)
    {
        if (FlightMode_GetState())
            FlightMode_SetState(ON);
        else
            FlightMode_SetState(OFF);
    }
    else if (item == SHC_ITEM_5)
    {
        int _SYNC = 0;
        int *SYNC = &_SYNC;
        Request_ICA_ShutdownAllConnections(SYNC);
    }
    FreeBook(book);
}

THUMB16 NEWCODE int ShortcutMenu_onMessage(GUI_MESSAGE *msg)
{
    int item = GUIonMessage_GetCreatedItemIndex(msg);
    if (item == SHC_ITEM_1)
        GUIonMessage_SetMenuItemText(msg, STR(SC_SHUTDOWN));

    else if (item == SHC_ITEM_2)
        GUIonMessage_SetMenuItemText(msg, STR(SC_RESTART));

    else if (item == SHC_ITEM_3)
    {
        wchar_t buf[32];
        snwprintf(buf, MAXELEMS(buf), SC_BRIGHTNESS_FMT, Display_GetBrightness(UIDisplay_Main));
        GUIonMessage_SetMenuItemText(msg, TextID_Create(buf, ENC_UCS2, MAXELEMS(buf)));
    }
    else if (item == SHC_ITEM_4)
    {
        if (!FlightMode_GetState())
        {
            if (_ConnectionManager_Connection_GetState())
            {
                GUIonMessage_SetMenuItemText(msg, STR(SC_FLIGHT_UNAVAI));
                GUIonMessage_SetItemDisabled(msg, TRUE);
            }
            else
                GUIonMessage_SetMenuItemText(msg, STR(SC_FLIGHT_OFF));
        }
        else
            GUIonMessage_SetMenuItemText(msg, STR(SC_FLIGHT_ON));
    }
    else if (item == SHC_ITEM_5)
    {
        if (!_ConnectionManager_Connection_GetState())
            GUIonMessage_SetItemDisabled(msg, TRUE);
        GUIonMessage_SetMenuItemText(msg, STR(SC_CLOSE_CONNECT));
    }
    return 1;
}
THUMB16 NEWCODE void CreateShortcutMenu(BOOK *book, int tab_num)
{
    ActivityMenuBook *mbk = (ActivityMenuBook *)book;

    BOOK_MANAGER *data = GetData();
    data->sc_menu = CreateListMenu(&mbk->book, UIDisplay_Main);
    ListMenu_SetOnMessage(data->sc_menu, ShortcutMenu_onMessage);
    ListMenu_SetItemCount(data->sc_menu, SHC_ITEM_LAST);
    ListMenu_SetCursorToItem(data->sc_menu, SHC_ITEM_1);
    GUIObject_SetStyle(data->sc_menu, UI_OverlayStyle_PopupNoFrame);
    GUIObject_TabTitleRemove(data->sc_menu, 1);
    GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_BACK, Close_Activitymenu);
    GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_LONG_BACK, Exit_to_Standby);
    GUIObject_SoftKeys_SetAction(data->sc_menu, ACTION_SELECT1, ShortcutMenu_onEnterPressed);

    TabMenuBar_SetTabGui(mbk->main_tab, tab_num, data->sc_menu);
    TabMenuBar_SetTabTitle(mbk->main_tab, tab_num, STR(SC_TITLE));
}
#endif

THUMB16 NEWCODE int LIST_ELEM_Filter(void *elem)
{
    return (elem ? TRUE : FALSE);
}

THUMB16 NEWCODE void LIST_ELEM_Destroy(void *data)
{
    BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)data;
    if (elem)
    {
        mfree(elem->book_name);
        elem->book_name = 0;
        mfree(elem);
    }
}

THUMB16 NEWCODE void DestroyLists(BOOK_MANAGER *data)
{
    if (data->books_list)
    {
        List_DestroyElements(data->books_list, LIST_ELEM_Filter, LIST_ELEM_Destroy);
        List_Destroy(data->books_list);
        data->books_list = 0;
    }
    if (data->elfs_list)
    {
        List_DestroyElements(data->elfs_list, LIST_ELEM_Filter, LIST_ELEM_Destroy);
        List_Destroy(data->elfs_list);
        data->elfs_list = 0;
    }
}

THUMB16 NEWCODE void Destroy_ini_Buffer(BOOK_MANAGER *data)
{
    if (data->books_name_buf)
    {
        mfree(data->books_name_buf);
        data->books_name_buf = 0;
    }
    if (data->shortcut_buf)
    {
        mfree(data->shortcut_buf);
        data->shortcut_buf = 0;
    }
}

THUMB16 NEWCODE void CreateBookAndElfsLists()
{
    BOOK_MANAGER *data = GetData();

    Destroy_ini_Buffer(data);
    DestroyLists(data);

    Load_booknames(data);
    Load_shortcuts(data);

    int total_gui = 0;
    int books_count = 0;
    int elfs_count = 0;

    DB_EXT *LastExtDB = (DB_EXT *)LAST_EXTDB_PTR;
    int mask = ((int)LastExtDB) & FLASH_MASK;

    data->books_list = List_Create();
    data->elfs_list = List_Create();

    int total_session = root_list_get_session_count();

    for (int session_index = 0; session_index < total_session; session_index++)
    {
        UI_APP_SESSION *session = root_list_get_session(session_index);
        for (int listbook_index = 0; listbook_index < List_GetCount(session->listbook); listbook_index++)
        {
            BOOK *book = (BOOK *)List_Get(session->listbook, listbook_index);
            if ((total_gui = List_GetCount(book->xguilist->guilist)) || (((int)book->onClose) & FLASH_MASK) != mask)
            {
#ifdef DB2010
                if (!IsVolumeControllerBook(book) && !IsRightNowBook(book))
#else
                if (!IsVolumeControllerBook(book) && !IsRightNowBook(book) && !isrsstickerbook(book))
#endif
                {
                    char str_tmp[MAX_BOOK_NAME_LEN + 1];
                    BOOK_LIST_ELEM *elem = (BOOK_LIST_ELEM *)malloc(sizeof(BOOK_LIST_ELEM));
                    elem->book = book;
                    elem->gui_count = total_gui;
                    elem->isJava = FALSE;

                    if (strcmp(book->xbook->name, CUIDISPLAYABLE_BOOK))
                    {
                        char *bookname = (char *)malloc(strlen(book->xbook->name) + 1);
                        strcpy(bookname, book->xbook->name);
                        elem->book_name = bookname;
                    }
                    else
                    {
                        TextID_GetString(BookObj_GetSession(book)->name, str_tmp, MAXELEMS(str_tmp));
                        char *bookname = (char *)malloc(strlen(str_tmp) + 1);
                        strcpy(bookname, str_tmp);
                        elem->book_name = bookname;
                        elem->isJava = TRUE;
                    }

                    if (elem->isJava)
                    {
                        elem->book_icon = DB_LIST_JAVA_ICN;
                        void *JavaDesc;
                        char sp1;
                        JavaDialog_Open(0, &sp1, &JavaDesc);

                        if (!JavaAppDesc_GetFirstApp(JavaDesc))
                        {
                            int len = strlen(elem->book_name) + 1;
                            wchar_t *book_name = (wchar_t *)malloc(sizeof(wchar_t) * len);
                            str2wstr(book_name, elem->book_name);
                            BOOL next = TRUE;
                            while (next)
                            {
                                wchar_t *name;
                                JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVAAPP_NAME, &name);

                                if (!wstrncmp(book_name, name, 8))
                                {
                                    wchar_t *fullpath;
                                    JavaAppDesc_GetJavaAppInfo(JavaDesc, JAVAAPP_FULLPATH, &fullpath);
                                    JavaApp_LogoImageID_Get(fullpath, &elem->book_icon);
                                    mfree(fullpath);
                                    next = FALSE;
                                }
                                mfree(name);

                                if (JavaAppDesc_GetNextApp(JavaDesc))
                                    next = FALSE;
                            }
                            mfree(book_name);
                        }
                        JavaDialog_Close(sp1);
                    }

                    TEXTID javaname = GetJavaName(book);
                    if (javaname != EMPTY_TEXTID)
                    {
                        mfree(elem->book_name);
                        TextID_GetString(javaname, str_tmp, MAXELEMS(str_tmp));
                        int len = strlen(str_tmp) + 1;
                        char *java_name = (char *)malloc(len);
                        strcpy(java_name, str_tmp);
                        elem->book_name = java_name;
                        TextID_Destroy(javaname);
                    }

                    else if ((((int)book->onClose) & FLASH_MASK) == mask)
                    {
                        List_InsertFirst(data->books_list, elem);
                        books_count++;
                    }
                    else
                    {
                        List_InsertFirst(data->elfs_list, elem);
                        elfs_count++;
                    }
                }
            }
        }
    }
    data->books_count = books_count;
    data->elfs_count = elfs_count;
}

THUMB16 NEWCODE void DestroyAllGUIs(BOOK_MANAGER *data)
{
    FREE_GUI(data->books_menu);
    data->book_index = 0;
    FREE_GUI(data->elf_menu)
    data->elf_index = 0;
    FREE_GUI(data->sc_menu)
}

THUMB16 NEWCODE void ActivityBook_onClose()
{
    BOOK_MANAGER *data = GetData();
    Destroy_ini_Buffer(data);
    DestroyAllGUIs(data);
    DestroyLists(data);
}

THUMB16 NEWCODE TEXTID EventsTitleText()
{
    wchar_t buf[32];
    snwprintf(buf, MAXELEMS(buf), NEW_EVENTS_FMT, NewEvents_GetCount());
    return TextID_Create(buf, ENC_UCS2, MAXELEMS(buf));
}

THUMB16 NEWCODE int GetFocusTab()
{
    BOOK_MANAGER *data = GetData();
    return data->tab_pos;
}
