#ifndef GUI_LIST_H
#define GUI_LIST_H

#include <base.h>
#include <bookobj.h>
#include <gui.h>

typedef struct GUI GUI_LIST;

typedef struct GUI_MESSAGE
{
	uint8_t __msg; // use GUIonMessage_GetMsg( )
	GUI *__gui;	   // use GUIonMessage_GetGui( )
	BOOK *__book;  // use GUIonMessage_GetBook( )
} GUI_MESSAGE;

typedef enum LISTMSGS
{
	LISTMSG_HighlightChanged = 0,
	LISTMSG_GetItem = 1,
	LISTMSG_SubItemHighlightChanged = 2,
	LISTMSG_GetSubItem = 3,
	LISTMSG_Edit = 4,
	LISTMSG_Delete = 5,
	LISTMSG_SearchIndex = 7,
	LISTMSG_GetKeyboard = 8,
	LISTMSG_ItemSelectionChanged = 9,
	LISTMSG_DrawComplete = 10,
	LISTMSG_ListBusy = 11,
	LISTMSG_KeyRepeat = 12,
	LISTMSG_StringInputCharProtYesCB = 13,
	LISTMSG_StringInputCharProtNoCB = 14,
	LISTMSG_Minipopup = 15
} LISTMSGS;

typedef enum LISTMENU_HOTKEY_MODE
{
	LKHM_SEARCH = 0,
	LKHM_SHORTCUT = 1,
	LKHM_FOCUS = 2,
	LKHM_PRESS = 3
} LISTMENU_HOTKEY_MODE;

#endif // GUI_LIST_H