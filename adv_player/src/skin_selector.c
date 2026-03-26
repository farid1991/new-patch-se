#include "device.h"

#include <libse.h>

#include <book/AudioPlayerBook.h>
#include <types/UIRichText_types.h>

#include "data.h"
#include "patch.h"
#include "skin_data.h"
#include "skin_list.h"
#include "skin_selector.h"

static const char TITLE_TXT[] = "Select skin";
static const char TOTAL_FMT[] = "Total Skins: %d";

THUMB16
NEWCODE int SkinSelect_OnMessage(GUI_MESSAGE *msg)
{
	ADVPLAYER_DATA *data = env_data_get();

	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		int index = GUIonMessage_GetCreatedItemIndex(msg);
		SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)List_Get(data->skin_list, index);

		GUIonMessage_SetMenuItemText(msg, TextID_Create(skin->fname, ENC_UCS2, TEXTID_ANY_LEN));
		GUIonMessage_SetMenuItemIcon(msg, AlignLeft, SKINSELECT_LIST_ICN);
		GUIonMessage_SetMenuItemIcon(msg, AlignRight, SKINSELECT_ARROW_ICN);
		break;
	}
	return 1;
}

THUMB16
NEWCODE void SkinSelect_onSelectPressed(BOOK *book, GUI *gui)
{
	AudioPlayerBook *audio_book = (AudioPlayerBook *)book;
	int index = ListMenu_GetSelectedItem(audio_book->Gui_SubMenu);

	ADVPLAYER_DATA *data = env_data_get();
	SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)List_Get(data->skin_list, index);

	skin_data_path_save(skin->fpath);
#ifndef OLD_PLAYER
	skin_data_reload(audio_book, skin->fpath);
#endif

	skin_list_destroy(&data->skin_list);

#ifdef OLD_PLAYER
	FreeBook(book);
#else
	FREE_GUI(audio_book->Gui_SubMenu);
	BookObj_GotoPage(&audio_book->book, page_MediaPlayer_Audio_Bk_Main);
#endif
}
THUMB16
NEWCODE void SkinSelect_onBackPressed(BOOK *book, GUI *gui)
{
	ADVPLAYER_DATA *data = env_data_get();

	if (data->skin_list)
		skin_list_destroy(&data->skin_list);

	MediaPlayer_Audio_ActionBack(book, gui);
}

THUMB16
NEWCODE void SkinSelect_onLongBackPressed(BOOK *book, GUI *gui)
{
	ADVPLAYER_DATA *data = env_data_get();

	if (data->skin_list)
		skin_list_destroy(&data->skin_list);

	MediaPlayer_Audio_ActionLongBack(book, gui);
}

THUMB16
NEWCODE TEXTID GetTitleText(int count)
{
	char cstr[20];
	sprintf(cstr, TOTAL_FMT, count);
	return TextID_Create(cstr, ENC_LAT1, MAXELEMS(cstr));
}

THUMB16
NEWCODE int pg_MediaPlayer_SkinSelector_EnterEvent(void *r0, BOOK *book)
{
	ADVPLAYER_DATA *data = env_data_get();
	AudioPlayerBook *audio_book = (AudioPlayerBook *)book;

	data->skin_list = skin_list_create(SKIN_PATH);

	int count = List_GetCount(data->skin_list);

	FREE_GUI(audio_book->Gui_SubMenu);

	audio_book->Gui_SubMenu = CreateListMenu(&audio_book->book, UIDisplay_Main);
	ListMenu_SetItemCount(audio_book->Gui_SubMenu, count);
	ListMenu_SetCursorToItem(audio_book->Gui_SubMenu, 0);
	ListMenu_SetHotkeyMode(audio_book->Gui_SubMenu, LKHM_SHORTCUT);

	GUIObject_SetTitleType(audio_book->Gui_SubMenu, UI_TitleMode_Large);
	GUIObject_SetTitleText(audio_book->Gui_SubMenu, STR(TITLE_TXT));
	GUIObject_SetTitleTextAlign(audio_book->Gui_SubMenu, AlignLeft);
	GUIObject_SetSecondRowTitleText(audio_book->Gui_SubMenu, GetTitleText(count));

	if (count)
	{
		ListMenu_SetOnMessage(audio_book->Gui_SubMenu, SkinSelect_OnMessage);

		if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_SubMenu))
			MediaPlayer_SoftKeys_SetAction(
			        audio_book->Gui_SubMenu, ACTION_SELECT1, SkinSelect_onSelectPressed);
		else
			GUIObject_SoftKeys_SetAction(
			        audio_book->Gui_SubMenu, ACTION_SELECT1, SkinSelect_onSelectPressed);
	}

	if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_SubMenu))
		MediaPlayer_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_BACK, SkinSelect_onBackPressed);
	else
		GUIObject_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_BACK, SkinSelect_onBackPressed);

	if (MediaPlayer_SoftKeys_Validate(audio_book->Gui_SubMenu))
		MediaPlayer_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_LONG_BACK, SkinSelect_onLongBackPressed);
	else
		GUIObject_SoftKeys_SetAction(audio_book->Gui_SubMenu, ACTION_LONG_BACK, SkinSelect_onLongBackPressed);

	GUIObject_Show(audio_book->Gui_SubMenu);

	return 1;
}
