#include "device.h"

#include <libse.h>

#include <types/UIRichText_types.h>

#include "patch.h"
#include "editor.h"
#include "fs_browser.h"
#include "utils.h"
#include "wstr_helper.h"

static const char GT_MEM[] = "GT_MEM";
static const char BOOKNAME[] = "GotoShortcutBook";
static const char BASE_PAGE_NAME[] = "Goto_Base_Page";
static const char MAIN_PAGE_NAME[] = "Goto_Main_Page";
static const char COPYRIGHT_STR[] = "GotoShortcut\nv3.11\n(c) farid";

// clang-format off

const PAGE_MSG bk_msglst_base[] =
{
	CANCEL_EVENT, pg_Goto_Shortcut_CancelEvent,
	RETURN_TO_STANDBY_EVENT, pg_Goto_Shortcut_CancelEvent,
	NIL_EVENT, NULL
};

const PAGE_DESC Goto_Shortcut_Base_Page = 
{
	BASE_PAGE_NAME, NULL, bk_msglst_base
};

const PAGE_MSG bk_msglst_main[] =
{
		PAGE_ENTER_EVENT, pg_Goto_Shortcut_EnterEvent,
		PAGE_EXIT_EVENT, pg_Goto_Shortcut_EnterEvent,
		ACCEPT_EVENT, pg_Goto_Shortcut_AcceptEvent,
		NIL_EVENT, NULL
};

const PAGE_DESC Goto_Shortcut_Main_Page = 
{
	MAIN_PAGE_NAME, NULL, bk_msglst_main
};

// clang-format on

THUMB16
NEWCODE void *malloc(int size)
{
#if defined(DB2020)
	return (memalloc(0, size, 1, 5, GT_MEM, 0));
#elif defined(A2)
	return (memalloc(-1, size, 1, 5, GT_MEM, 0));
#else
	return (memalloc(size, 1, 5, GT_MEM, 0));
#endif
}

THUMB16
NEWCODE void mfree(void *mem)
{
	if (mem)
#if defined(DB2020) || defined(A2)
		memfree(0, mem, GT_MEM, 0);
#else
		memfree(mem, GT_MEM, 0);
#endif
}

THUMB16
NEWCODE void ShortcutFree(void *item)
{
	SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)item;
	if (Shortcut)
	{
		mfree(Shortcut->ScLink);
		mfree(Shortcut->ScText);
		mfree(Shortcut);
	}
}

THUMB16
NEWCODE void Menu_Delete_Yes(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);

	void *item = List_RemoveAt(mbk->ShortcutList, mbk->CurrentItem);
	ShortcutFree(item);

	SaveConfig(mbk->ShortcutList);
	pg_Goto_Shortcut_AcceptEvent(NULL, book);
}

THUMB16
NEWCODE void Menu_Delete_No(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	mbk->CurrentItem = ListMenu_GetSelectedItem(mbk->MainMenu);

	pg_Goto_Shortcut_AcceptEvent(NULL, book);
}

THUMB16
NEWCODE void Menu_DeleteItem(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	if (!List_GetCount(mbk->ShortcutList))
		return;

	int selected = ListMenu_GetSelectedItem(mbk->MainMenu);
	SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, selected);

	if (mbk->YesNoQuestion = CreateYesNoQuestion(&mbk->book, UIDisplay_Main))
	{
		YesNoQuestion_SetQuestionText(mbk->YesNoQuestion, DELETEQ_TXT);
		YesNoQuestion_SetDescriptionText(mbk->YesNoQuestion, WSTR(Shortcut->ScText));
		YesNoQuestion_SetIcon(mbk->YesNoQuestion, Shortcut->ScIcon);
		GUIObject_SoftKeys_SetAction(mbk->YesNoQuestion, ACTION_YES, Menu_Delete_Yes);
		GUIObject_SoftKeys_SetAction(mbk->YesNoQuestion, ACTION_NO, Menu_Delete_No);
		GUIObject_Show(mbk->YesNoQuestion);
	}
}

THUMB16
NEWCODE void Menu_AddItem(BOOK *book, GUI *gui)
{
	EditorRun(book, ADDING_MODE);
}

THUMB16
NEWCODE void Menu_ModifyItem(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	if (List_GetCount(mbk->ShortcutList))
		EditorRun(book, EDITING_MODE);
	else
		MessageBox_NoImage(EMPTY_TEXTID, EMPTY_LIST_TXT, 1, 0, book);
}

THUMB16
NEWCODE void Menu_About(BOOK *book, GUI *gui)
{
	MessageBox_NoImage(EMPTY_TEXTID, STR(COPYRIGHT_STR), 1, 0, book);
}

THUMB16
NEWCODE void Menu_Select(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	int selected = ListMenu_GetSelectedItem(mbk->MainMenu);
	SC_LIST_ELEM *sc = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, selected);

	if (sc)
		RunShortcut(sc);

	FreeBook(book);
}

THUMB16
NEWCODE void Menu_Exit(BOOK *book, GUI *gui)
{
	FreeBook(book);
}

THUMB16
NEWCODE int Menu_onMessage(GUI_MESSAGE *msg)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)GUIonMessage_GetBook(msg);

	if (!List_GetCount(mbk->ShortcutList))
		return 0;

	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		int index = GUIonMessage_GetCreatedItemIndex(msg);
		SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(mbk->ShortcutList, index);

		GUIonMessage_SetMenuItemText(msg, WSTR(Shortcut->ScText));
		GUIonMessage_SetMenuItemIcon(msg, AlignLeft, Shortcut->ScIcon);
		break;
	}
	return 1;
}

THUMB16
NEWCODE int pg_Goto_Shortcut_EnterEvent(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->MainMenu);

	int count = List_GetCount(mbk->ShortcutList);

	if (mbk->MainMenu = CreateListMenu(&mbk->book, UIDisplay_Main))
	{
		GUIObject_SetTitleText(mbk->MainMenu, TITLE_TXT);
		ListMenu_SetItemCount(mbk->MainMenu, count);
		ListMenu_SetOnMessage(mbk->MainMenu, Menu_onMessage);
		ListMenu_SetCursorToItem(mbk->MainMenu, mbk->CurrentItem);
		ListMenu_SetHotkeyMode(mbk->MainMenu, LKHM_SHORTCUT);
#ifndef DB2000
		ListMenu_SetItemTextScroll(mbk->MainMenu, 0);
#endif
#if defined(DB2020) || defined(PNX5230) || defined(A2)
		ListMenu_SetNoItemText(mbk->MainMenu, EMPTY_LIST_TXT);
#endif
		GUIObject_SoftKeys_SetText(mbk->MainMenu, 0, MENU_ADD_TXT);
		GUIObject_SoftKeys_SetAction(mbk->MainMenu, 0, Menu_AddItem);
		GUIObject_SoftKeys_SetText(mbk->MainMenu, 1, MENU_MODIFY_TXT);
		GUIObject_SoftKeys_SetAction(mbk->MainMenu, 1, Menu_ModifyItem);
		GUIObject_SoftKeys_SetText(mbk->MainMenu, 2, MENU_ABOUT_TXT);
		GUIObject_SoftKeys_SetAction(mbk->MainMenu, 2, Menu_About);
		if (count)
		{
			GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_DELETE, Menu_DeleteItem);
			GUIObject_SoftKeys_SetVisible(mbk->MainMenu, ACTION_DELETE, FALSE);
			GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_SELECT1, Menu_Select);
		}
		GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_BACK, Menu_Exit);
		GUIObject_SoftKeys_SetAction(mbk->MainMenu, ACTION_LONG_BACK, Menu_Exit);
		GUIObject_Show(mbk->MainMenu);
	}
	return 1;
};

THUMB16
NEWCODE int pg_Goto_Shortcut_CancelEvent(void *data, BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	FREE_GUI(mbk->MainMenu);
	return 1;
}

THUMB16
NEWCODE int pg_Goto_Shortcut_AcceptEvent(void *data, BOOK *book)
{
	BookObj_GotoPage(book, &Goto_Shortcut_Main_Page);
	return 1;
}

THUMB16
NEWCODE void Goto_Shortcut_onClose(BOOK *book)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	FREE_GUI(mbk->MainMenu);
	FREE_GUI(mbk->Editor);
	FREE_GUI(mbk->JavaMenu);
	FREE_GUI(mbk->Types);
	FREE_GUI(mbk->CaptionInput);
	FREE_GUI(mbk->YesNoQuestion);

	if (mbk->ShortcutList)
	{
		SaveConfig(mbk->ShortcutList);
		list_destroy(&mbk->ShortcutList, ShortcutFree);
	}
}

THUMB16
NEWCODE BOOL IsGotoShortcutBook(BOOK *book)
{
	return book->onClose == Goto_Shortcut_onClose ? TRUE : FALSE;
}

THUMB16
NEWCODE GotoShortcut_Book *Create_GotoShortcutBook()
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)malloc(sizeof(GotoShortcut_Book));
	memset(mbk, 0, sizeof(GotoShortcut_Book));

	if (!CreateBook((BOOK *)mbk, Goto_Shortcut_onClose, &Goto_Shortcut_Base_Page, BOOKNAME, NO_BOOK_ID, NULL))
	{
		mfree(mbk);
		return NULL;
	}
	return mbk;
}

THUMB16
NEWCODE void GotoShortcut(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)FindBook(IsGotoShortcutBook);
	if (!mbk)
	{
		mbk = Create_GotoShortcutBook();
		mbk->ShortcutList = LoadConfig();
		BookObj_GotoPage(&mbk->book, &Goto_Shortcut_Main_Page);
	}
	else
	{
		BookObj_SetFocus(&mbk->book, UIDisplay_Main);
	}
}
