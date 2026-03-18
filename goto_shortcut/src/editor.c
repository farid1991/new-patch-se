#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <elf_int.h>

#include <types/UIRichText_types.h>

#include "patch.h"
#include "editor.h"
#include "fs_browser.h"
#include "utils.h"
#include "wstr_helper.h"

static const char EDITOR_MAIN_BASEPAGE_NAME[] = "SCEdit_Main_Page";
static const char EDITOR_CAPTIONINPUT_BASEPAGE_NAME[] = "SCEdit_LabelInput_Page";
static const char EDITOR_TYPESLIST_BASEPAGE_NAME[] = "SCEdit_TypesList_Page";

static const char EDITOR_MAINMENU_BASEPAGE_NAME[] = "SCEdit_SelectShortcut_Page";
static const char EDITOR_JAVALIST_BASEPAGE_NAME[] = "SCEdit_SetJava_Page";
static const char EDITOR_DATABROWSER_BASEPAGE_NAME[] = "SCEdit_SelectElf_Page";
static const char EDITOR_SELECTFOLDER_BASEPAGE_NAME[] = "SCEdit_SelectFolder_Page";

static const char SELECT_ELF_STR[] = "ELFs";

THUMB16
NEWCODE void *ShortcutDesc_Init(wchar_t *param)
{
#if defined(A1)
	SHORTCUT_DESC *desc = (SHORTCUT_DESC *)malloc(sizeof(SHORTCUT_DESC));
	memset(desc, 0, sizeof(SHORTCUT_DESC));
	wstrcpy(desc->name, param);
	desc->shortcut_state = !wstrcmp(desc->name, MAINMENU_STR) ? SC_State_MainMenu : SC_State_Activated;
	return desc;
#elif defined(A2)
	SHORTCUT_DESC_A2 *desc = (SHORTCUT_DESC_A2 *)malloc(sizeof(SHORTCUT_DESC_A2));
	memset(desc, 0, sizeof(SHORTCUT_DESC_A2));
	wstrcpy(desc->name, param);
	desc->item_type = !wstrcmp(desc->name, MAINMENU_STR) ? SC_Type_MainMenu : SC_Type_Standard;
	return desc;
#endif
}

THUMB16
NEWCODE void Action_Back(BOOK *book, GUI *gui)
{
	BookObj_ReturnPage(book, NIL_EVENT);
}

THUMB16
NEWCODE void AcceptShortcut(BOOK *book)
{
	BookObj_ReturnPage(book, NIL_EVENT);
	BookObj_ReturnPage(book, ACCEPT_EVENT);
}

THUMB16
NEWCODE void Menu_SetMainMenu(BOOK *MenuBook, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsGotoShortcutBook);
	if (!mbk || !mbk->ShortcutItem)
		return;

	size_t len = wstrlen(MAINMENU_STR) + 1;

	mbk->ShortcutItem->ScLink = WStringAlloc(len);
	if (!mbk->ShortcutItem->ScLink)
		return;

	wstrcpy(mbk->ShortcutItem->ScLink, MAINMENU_STR);
	mbk->ShortcutItem->ScType = TYPE_SHORTCUT;

	void *ShortcutDesc = ShortcutDesc_Init(mbk->ShortcutItem->ScLink);
	if (ShortcutDesc)
	{
		mbk->ShortcutItem->ScIcon = Shortcut_Get_MenuItemIconID(ShortcutDesc);
		mfree(ShortcutDesc);
	}

	if (!mbk->ShortcutItem->ScText)
	{
		mbk->ShortcutItem->ScText = WStringAlloc(len);
		if (mbk->ShortcutItem->ScText)
			wstrcpy(mbk->ShortcutItem->ScText, MAINMENU_STR);
	}

	FreeBook(MenuBook);
	AcceptShortcut(&mbk->book);
}

THUMB16
NEWCODE void Menu_SetShortcut(BOOK *MenuBook, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsGotoShortcutBook);

	wchar_t *Data = MenuBook_Desktop_GetSelectedItemID(MenuBook);
	WStringRealloc(Data, &mbk->ShortcutItem->ScLink);
	mfree(Data);

	mbk->ShortcutItem->ScType = TYPE_SHORTCUT;

	void *ShortcutDesc = ShortcutDesc_Init(mbk->ShortcutItem->ScLink);

	mbk->ShortcutItem->ScIcon = Shortcut_Get_MenuItemIconID(ShortcutDesc);
	if (!mbk->ShortcutItem->ScText)
	{
		wchar_t text[64];
		TextID_GetWString(Shortcut_Get_MenuItemName(ShortcutDesc), text, MAXELEMS(text));
		mbk->ShortcutItem->ScText = WStringAlloc(wstrlen(text) + 1);
		wstrcpy(mbk->ShortcutItem->ScText, text);
	}
	mfree(ShortcutDesc);
	FreeBook(MenuBook);
	AcceptShortcut(&mbk->book);
}

THUMB16
NEWCODE int pg_SC_Editor_SelectShortcut_CancelAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	BookObj_ReturnPage(&mbk->book, NIL_EVENT);
	return 1;
}

THUMB16
NEWCODE int pg_SC_Editor_SelectShortcut_EnterAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	BOOK *MenuBook = MenuBook_Desktop(1, BookObj_GetBookID(&mbk->book));
	if (!MenuBook)
		return FALSE;

	mbk->MainMenuID = BookObj_GetBookID(MenuBook);
	BookObj_SoftKeys_SetAction(MenuBook, 0, Menu_SetShortcut);
	BookObj_SoftKeys_SetText(MenuBook, 0, SHC_SET_SHORTCUT_SK);
#ifndef DB2000
	BookObj_SoftKeys_SetAction(MenuBook, 1, Menu_SetMainMenu);
	BookObj_SoftKeys_SetText(MenuBook, 1, SHC_SET_MM);
#endif
	return TRUE;
}

// clang-format off

const PAGE_MSG Goto_Editor_MainMenu_PageEvents[] = 
{
	PAGE_ENTER_EVENT, pg_SC_Editor_SelectShortcut_EnterAction,
	PREVIOUS_EVENT, pg_SC_Editor_SelectShortcut_CancelAction,
	CANCEL_EVENT, pg_SC_Editor_SelectShortcut_CancelAction,
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Editor_MainMenu_PageDesc = 
{
	EDITOR_MAINMENU_BASEPAGE_NAME, NULL, Goto_Editor_MainMenu_PageEvents
};

// clang-format on

//------------------------------------------------------------------------------
THUMB16
NEWCODE int JavaMenu_Callback(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		GotoShortcut_Book *mbk = (GotoShortcut_Book *)GUIonMessage_GetBook(msg);
		JAVA_LIST_ELEM *elem = (JAVA_LIST_ELEM *)List_Get(mbk->JavaList, GUIonMessage_GetCreatedItemIndex(msg));
		GUIonMessage_SetMenuItemText(msg, WSTR(elem->name));
		GUIonMessage_SetMenuItemIcon(msg, AlignLeft, elem->image_id);
	}
	return 1;
}

THUMB16
NEWCODE void JavaMenu_Ok(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	JAVA_LIST_ELEM *elem = (JAVA_LIST_ELEM *)List_Get(mbk->JavaList, ListMenu_GetSelectedItem(mbk->JavaMenu));

	WStringRealloc(elem->name, &mbk->ShortcutItem->ScLink);
	mbk->ShortcutItem->ScIcon = DB_LIST_JAVA_ICN;
	mbk->ShortcutItem->ScType = TYPE_JAVA;

	if (!mbk->ShortcutItem->ScText)
		WStringRealloc(elem->name, &mbk->ShortcutItem->ScText);

	AcceptShortcut(&mbk->book);
}

THUMB16
NEWCODE int CreateJavaList(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	if (mbk->JavaList)
		list_destroy(&mbk->JavaList, java_list_free_item);

	mbk->JavaList = java_list_create();

	FREE_GUI(mbk->JavaMenu);

	if (mbk->JavaMenu = CreateListMenu(&mbk->book, UIDisplay_Main))
	{
		GUIObject_SetTitleText(mbk->JavaMenu, JAVA_APP_TXT);
		ListMenu_SetItemCount(mbk->JavaMenu, List_GetCount(mbk->JavaList));
		ListMenu_SetOnMessage(mbk->JavaMenu, JavaMenu_Callback);
		ListMenu_SetCursorToItem(mbk->JavaMenu, 0);
		GUIObject_SoftKeys_SetAction(mbk->JavaMenu, ACTION_BACK, Action_Back);
		GUIObject_SoftKeys_SetAction(mbk->JavaMenu, ACTION_SELECT1, JavaMenu_Ok);
		GUIObject_Show(mbk->JavaMenu);
	}

	return 1;
}

THUMB16
NEWCODE int CloseJavaList(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->JavaMenu);
	list_destroy(&mbk->JavaList, java_list_free_item);
	return 1;
}

// clang-format off

const PAGE_MSG Goto_Editor_JavaList_PageEvents[] = 
{
	PAGE_ENTER_EVENT, CreateJavaList, 
	PAGE_EXIT_EVENT, CloseJavaList, 
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Editor_JavaList_PageDesc = 
{
	EDITOR_JAVALIST_BASEPAGE_NAME, NULL, Goto_Editor_JavaList_PageEvents
};

// clang-format on

//------------------------------------------------------------------------------

THUMB16
NEWCODE int pg_SC_Editor_SelectElf_AcceptAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	FILEITEM *file_item = (FILEITEM *)data;
	wchar_t *fpath = FILEITEM_GetPath(file_item);
	wchar_t *fname = FILEITEM_GetFname(file_item);

	mbk->ShortcutItem->ScLink = FSX_MakeFullPath(fpath, fname);
	mbk->ShortcutItem->ScIcon = TypesIcons[TYPE_ELF];
	mbk->ShortcutItem->ScType = TYPE_ELF;

	if (!mbk->ShortcutItem->ScText)
	{
		WStringRealloc(fname, &mbk->ShortcutItem->ScText);
		WStringStripExt(mbk->ShortcutItem->ScText);
	}

	AcceptShortcut(&mbk->book);
	return 1;
}

THUMB16
NEWCODE int DB_Filter(const wchar_t *ext_list, const wchar_t *fpath, const wchar_t *fname)
{
	if (DataBrowser_isFileInListExt(ext_list, fpath, fname))
		return 1;

	FSTAT fs;
	fstat(fpath, fname, &fs);
	return 0 != (fs.st_mode & FSX_S_IFDIR);
}

static const wchar_t ELFS_INT_PATH[] = ZBIN_INT_PATH;

#ifdef ZBIN_EXT_PATH
static const wchar_t ELFS_EXT_PATH[] = ZBIN_EXT_PATH;
#endif

static const wchar_t *ELF_DIR_LIST[] = {
        ELFS_INT_PATH,
#ifdef ZBIN_EXT_PATH
        ELFS_EXT_PATH,
#else
        0
#endif
};

THUMB16
NEWCODE int pg_SC_Editor_SelectElf_EnterAction(void *data, BOOK *book)
{
	void *db_desc = DataBrowserDesc_Create();
	if (!db_desc)
		return 1;

	DataBrowserDesc_SetHeaderText(db_desc, STR(SELECT_ELF_STR));
	DataBrowserDesc_SetBookID(db_desc, BookObj_GetBookID(book));
	DataBrowserDesc_SetFolders(db_desc, ELF_DIR_LIST);
	DataBrowserDesc_SetFileExtList(db_desc, ELF_EXT);
	DataBrowserDesc_SetItemFilter(db_desc, DB_Filter);
	DataBrowserDesc_SetFoldersNumber(db_desc, DIR_ZBIN_CNT);
	DataBrowserDesc_SetSelectAction(db_desc, 1);
	DataBrowser_Create(db_desc);
	DataBrowserDesc_Destroy(db_desc);

	return 1;
}

// clang-format off

const PAGE_MSG Goto_Editor_DataBrowser_PageEvents[] = 
{
	PAGE_ENTER_EVENT, pg_SC_Editor_SelectElf_EnterAction,
	ACCEPT_EVENT, pg_SC_Editor_SelectElf_AcceptAction,
	PREVIOUS_EVENT,	 pg_SC_Editor_SelectShortcut_CancelAction,
	CANCEL_EVENT, pg_SC_Editor_SelectShortcut_CancelAction,
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Editor_DataBrowser_PageDesc = 
{
	EDITOR_DATABROWSER_BASEPAGE_NAME, NULL, Goto_Editor_DataBrowser_PageEvents
};

// clang-format on

//------------------------------------------------------------------------------

THUMB16
NEWCODE void SelFolder_Enter(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	mbk->FType = SEL_FOLDER;
	wchar_t *wstr;
	uint16_t len;
	StringInput_GetStringAndLen(mbk->FolderInput, &wstr, &len);
	mbk->FSBrowser = Create_FsBrowser(&mbk->book, wstr);
}

THUMB16
NEWCODE void SC_Editor_SelectFolder_onBack(BOOK *book, wchar_t *string, int len)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->FolderInput);
	BookObj_ReturnPage(&mbk->book, NIL_EVENT);
}

THUMB16
NEWCODE void SC_Editor_SelectFolder_onEnter(BOOK *book, wchar_t *string, int len)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	if (len)
	{
		WStringRealloc(string, &mbk->ShortcutItem->ScLink);
		mbk->ShortcutItem->ScIcon = TypesIcons[TYPE_FOLDER];
		mbk->ShortcutItem->ScType = TYPE_FOLDER;

		if (!mbk->ShortcutItem->ScText)
			WStringExtractFileName(string, &mbk->ShortcutItem->ScText);
	}
	AcceptShortcut(&mbk->book);
}

THUMB16
NEWCODE int pg_SC_Editor_SelectFolder_EnterAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->FolderInput);

#if defined(DB2000) || defined(DB2010)
	TEXTID input_text;
	if (mbk->ShortcutItem->ScLink && (mbk->ShortcutItem->ScType == TYPE_FOLDER))
		input_text = WSTR(mbk->ShortcutItem->ScLink);
	else
		input_text = EMPTY_TEXTID;

	// clang-format off

	mbk->FolderInput = CreateStringInputVA(0,
	                                       VAR_ARG_BOOK, mbk,
	                                       VAR_ARG_STRINP_MODE, IT_STRING,
	                                       VAR_ARG_STRINP_TEXT, input_text,
	                                       VAR_ARG_STRINP_EMPTY_STR_EN, FALSE,
	                                       VAR_ARG_STRINP_MAX_LEN, MAX_PATH_LEN,
	                                       VAR_ARG_STRINP_MIN_LEN, 1,
	                                       VAR_ARG_CALL_BACK_PREV_ACT, SC_Editor_SelectFolder_onBack,
	                                       VAR_ARG_CALL_BACK_LONG_BACK, SC_Editor_SelectFolder_onBack,
	                                       VAR_ARG_CALL_BACK_OK, SC_Editor_SelectFolder_onEnter,
	                                       0);

	// clang-format on

	GUIObject_SoftKeys_SetText(mbk->FolderInput, 0, SELECT_FOLDER_TXT);
	GUIObject_SoftKeys_SetAction(mbk->FolderInput, 0, SelFolder_Enter);
#ifndef K600_R2BB001
	StringInput_MenuItem_SetPriority(mbk->FolderInput, 0, 0);
#endif
#else
	if (mbk->FolderInput = CreateStringInput(&mbk->book))
	{
		StringInput_SetMode(mbk->FolderInput, IT_STRING);
		StringInput_SetEnableEmptyText(mbk->FolderInput, FALSE);

		if (mbk->ShortcutItem->ScLink && (mbk->ShortcutItem->ScType == TYPE_FOLDER))
			StringInput_SetText(mbk->FolderInput, WSTR(mbk->ShortcutItem->ScLink));

		StringInput_SetMinLen(mbk->FolderInput, 1);
		StringInput_SetMaxLen(mbk->FolderInput, MAX_PATH_LEN);
		StringInput_SetActionOK(mbk->FolderInput, SC_Editor_SelectFolder_onEnter);
		StringInput_SetActionBack(mbk->FolderInput, SC_Editor_SelectFolder_onBack);

		GUIObject_SoftKeys_SetText(mbk->FolderInput, 0, SELECT_FOLDER_TXT);
		GUIObject_SoftKeys_SetAction(mbk->FolderInput, 0, SelFolder_Enter);
		StringInput_MenuItem_SetPriority(mbk->FolderInput, 0, 0);

		GUIObject_Show(mbk->FolderInput);
	}
#endif
	return 1;
}

THUMB16
NEWCODE int pg_SC_Editor_SelectFolder_ExitAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->FSBrowser);
	return 1;
}

// clang-format off

const PAGE_MSG Goto_Editor_SelectFolder_PageEvents[] = 
{
	PAGE_ENTER_EVENT, pg_SC_Editor_SelectFolder_EnterAction,
	PAGE_EXIT_EVENT, pg_SC_Editor_SelectFolder_ExitAction,
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Editor_SelectFolder_PageDesc = 
{
	EDITOR_SELECTFOLDER_BASEPAGE_NAME, NULL, Goto_Editor_SelectFolder_PageEvents
};

// clang-format on

//------------------------------------------------------------------------------

static const char NO_ELFPACK[] = "Elfpack is not installed";
static const ose_func_t ose = {current_process, get_bid, get_envp};

THUMB16
NEWCODE TEXTID Get_SCTypes_Text(int item)
{
	return STR(TypesCaptions[item]);
}

THUMB16
NEWCODE void TypesList_onSelect(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	switch (ListMenu_GetSelectedItem(mbk->Types))
	{
	case TYPE_SHORTCUT: BookObj_CallPage(&mbk->book, &Goto_Editor_MainMenu_PageDesc); break;
	case TYPE_JAVA: BookObj_CallPage(&mbk->book, &Goto_Editor_JavaList_PageDesc); break;
	case TYPE_ELF:
		if (!is_elfpack_installed(&ose))
			MessageBox_NoImage(EMPTY_TEXTID, STR(NO_ELFPACK), 0, 2500, NULL);
		else
			BookObj_CallPage(&mbk->book, &Goto_Editor_DataBrowser_PageDesc);
		break;
	case TYPE_FOLDER: BookObj_CallPage(&mbk->book, &Goto_Editor_SelectFolder_PageDesc); break;
	}
}

THUMB16
NEWCODE int TypesList_onMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		int index = GUIonMessage_GetCreatedItemIndex(msg);
		GUIonMessage_SetMenuItemText(msg, Get_SCTypes_Text(index));
		GUIonMessage_SetMenuItemIcon(msg, AlignLeft, TypesIcons[index]);
		break;
	}
	return 1;
}

THUMB16
NEWCODE int pg_SC_Editor_TypesList_EnterAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	if (mbk->Types = CreateListMenu(&mbk->book, UIDisplay_Main))
	{
		GUIObject_SetTitleText(mbk->Types, TYPES_TITLE_TXT);
		ListMenu_SetItemCount(mbk->Types, TYPE_LAST);
		ListMenu_SetCursorToItem(mbk->Types, 0);
		ListMenu_SetOnMessage(mbk->Types, TypesList_onMessage);
		GUIObject_SoftKeys_SetAction(mbk->Types, ACTION_SELECT1, TypesList_onSelect);
		GUIObject_SoftKeys_SetAction(mbk->Types, ACTION_BACK, Action_Back);
		GUIObject_Show(mbk->Types);
	}
	return 1;
}

THUMB16
NEWCODE int pg_SC_Editor_TypesList_ExitAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->Types);
	if (mbk->MainMenuID != NO_BOOK_ID)
	{
		BOOK *MainMenu = FindBookByID(mbk->MainMenuID);
		if (MainMenu)
			FreeBook(MainMenu);
		mbk->MainMenuID = NO_BOOK_ID;
	}
	return 1;
}

// clang-format off

const PAGE_MSG Goto_Editor_TypesList_PageEvents[] = 
{
	PAGE_ENTER_EVENT, pg_SC_Editor_TypesList_EnterAction,
	PAGE_EXIT_EVENT, pg_SC_Editor_TypesList_ExitAction,
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Editor_TypesList_PageDesc = 
{
	EDITOR_TYPESLIST_BASEPAGE_NAME, NULL, Goto_Editor_TypesList_PageEvents
};

// clang-format on

//------------------------------------------------------------------------------

THUMB16
NEWCODE void OnOkCaptionInput(BOOK *book, wchar_t *string, int len)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	if (len)
		WStringReallocEx(string, &mbk->ShortcutItem->ScText, len);

	BookObj_ReturnPage(&mbk->book, ACCEPT_EVENT);
}

THUMB16
NEWCODE int pg_SC_Editor_LabelInput_EnterAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->CaptionInput);

#if defined(DB2000) || defined(DB2010)
	// clang-format off

	mbk->CaptionInput = CreateStringInputVA(0,
	                                        VAR_ARG_BOOK, mbk,
	                                        VAR_ARG_STRINP_MODE, IT_STRING,
	                                        VAR_ARG_STRINP_TEXT, WSTR(mbk->ShortcutItem->ScText),
	                                        VAR_ARG_STRINP_EMPTY_STR_EN, TRUE,
	                                        VAR_ARG_STRINP_MAX_LEN, 64,
	                                        VAR_ARG_STRINP_MIN_LEN, 1,
	                                        VAR_ARG_CALL_BACK_PREV_ACT, Action_Back,
	                                        VAR_ARG_CALL_BACK_LONG_BACK, Action_Back,
	                                        VAR_ARG_CALL_BACK_OK, OnOkCaptionInput,
	                                        0);

	// clang-format on

#else

	if (mbk->CaptionInput = CreateStringInput(&mbk->book))
	{
		StringInput_SetMode(mbk->CaptionInput, IT_STRING);
		StringInput_SetEnableEmptyText(mbk->CaptionInput, TRUE);
		StringInput_SetText(mbk->CaptionInput, WSTR(mbk->ShortcutItem->ScText));
		StringInput_SetMinLen(mbk->CaptionInput, 1);
		StringInput_SetMaxLen(mbk->CaptionInput, 64);
		StringInput_SetActionOK(mbk->CaptionInput, OnOkCaptionInput);
		GUIObject_SoftKeys_SetAction(mbk->CaptionInput, ACTION_BACK, Action_Back);
		GUIObject_Show(mbk->CaptionInput);
	}
#endif
	return 1;
}

THUMB16
NEWCODE int pg_SC_Editor_LabelInput_ExitAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->CaptionInput);
	return 1;
}

// clang-format off

const PAGE_MSG Goto_Editor_CaptionInput_PageEvents[] =
{
	PAGE_ENTER_EVENT, pg_SC_Editor_LabelInput_EnterAction,
	PAGE_EXIT_EVENT, pg_SC_Editor_LabelInput_ExitAction,
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Editor_CaptionInput_PageDesc = 
{
	EDITOR_CAPTIONINPUT_BASEPAGE_NAME, NULL, Goto_Editor_CaptionInput_PageEvents
};

// clang-format on

//------------------------------------------------------------------------------

THUMB16
NEWCODE void Editor_onSelect(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	switch (ListMenu_GetSelectedItem(mbk->Editor))
	{
	case 0: BookObj_CallPage(&mbk->book, &Goto_Editor_CaptionInput_PageDesc); break;
	case 1: BookObj_CallPage(&mbk->book, &Goto_Editor_TypesList_PageDesc); break;
	}
}

THUMB16
NEWCODE void Editor_onBack(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	if (!mbk->ShortcutItem->ScLink || !mbk->ShortcutItem->ScText)
	{
		void *Item = List_RemoveFirst(mbk->ShortcutList);
		ShortcutFree(Item);
	}
	SaveConfig(mbk->ShortcutList);
	BookObj_ReturnPage(book, ACCEPT_EVENT);
}

THUMB16
NEWCODE int Editor_onMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		GotoShortcut_Book *mbk = (GotoShortcut_Book *)GUIonMessage_GetBook(msg);
		int index = GUIonMessage_GetCreatedItemIndex(msg);
		GUIonMessage_SetMenuItemIcon(msg, AlignLeft, EditorIcons[index]);
		if (index == 0)
		{
			GUIonMessage_SetMenuItemText(msg, EDITOR_LABEL_TXT);
			GUIonMessage_SetMenuItemSecondLineText(msg, WSTR(mbk->ShortcutItem->ScText));
		}
		if (index == 1)
		{
			GUIonMessage_SetMenuItemText(msg, EDITOR_SHORTCUT_TXT);
			GUIonMessage_SetMenuItemSecondLineText(msg, WSTR(mbk->ShortcutItem->ScLink));
		}
	}
	return 1;
}

THUMB16
NEWCODE int pg_SC_Editor_Main_EnterAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->Editor);
	if (mbk->Editor = CreateListMenu(&mbk->book, UIDisplay_Main))
	{
		GUIObject_SetTitleText(mbk->Editor, EDITOR_TITLE_TXT);
		ListMenu_SetItemCount(mbk->Editor, 2);
		ListMenu_SetCursorToItem(mbk->Editor, 0);
		ListMenu_SetItemStyle(mbk->Editor, 3);
		ListMenu_SetOnMessage(mbk->Editor, Editor_onMessage);
		GUIObject_SoftKeys_SetAction(mbk->Editor, ACTION_SELECT1, Editor_onSelect);
		GUIObject_SoftKeys_SetAction(mbk->Editor, ACTION_BACK, Editor_onBack);
		GUIObject_Show(mbk->Editor);
	}
	return 1;
}

THUMB16
NEWCODE int pg_CloseEditorMenu(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);
	FREE_GUI(mbk->Editor);
	return 1;
}

// clang-format off

const PAGE_MSG Goto_Editor_Main_PageEvents[] = 
{
	PAGE_ENTER_EVENT, pg_SC_Editor_Main_EnterAction,
	ACCEPT_EVENT, pg_SC_Editor_Main_AcceptAction,
	PAGE_EXIT_EVENT, pg_CloseEditorMenu,
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Editor_Main_PageDesc = 
{
	EDITOR_MAIN_BASEPAGE_NAME, NULL, Goto_Editor_Main_PageEvents
};

// clang-format on

THUMB16
NEWCODE int pg_SC_Editor_Main_AcceptAction(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	BookObj_GotoPage(&mbk->book, &Goto_Editor_Main_PageDesc);
	return 0;
}

THUMB16
NEWCODE void EditorRun(BOOK *book, int mode)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	if (mode == ADDING_MODE)
	{
		SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)malloc(sizeof(SC_LIST_ELEM));
		memset(Shortcut, 0, sizeof(SC_LIST_ELEM));
		List_InsertFirst(mbk->ShortcutList, Shortcut);
		mbk->ShortcutItem = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, 0);
	}
	else
	{
		int selected = ListMenu_GetSelectedItem(mbk->MainMenu);
		mbk->ShortcutItem = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, selected);
	}

	BookObj_CallPage(&mbk->book, &Goto_Editor_Main_PageDesc);
}
