#include "device.h"

#include <libse.h>
#include <types/Colors.h>
#include <types/UIFont_types.h>
#include <types/UIRichText_types.h>

#include "patch.h"
#include "data.h"
#include "settings.h"
#include "lang.h"
#include "editor.h"

static const char BASE_PAGE_NAME[] = "DBPlayer_Settings_Base_Page";
static const char MAIN_PAGE_NAME[] = "DBPlayer_Settings_Main_Page";

static const char FMT_XY[] = "X:%d, Y:%d";
static const char FMT_XYWH[] = "X:%d, Y:%d, W:%d, H:%d";
static const char FMT_XYWH_R[] = "%d,%d,%d,%d font:%dR";
static const char FMT_XYWH_B[] = "%d,%d,%d,%d font:%dB";
static const char FMT_XYWH_I[] = "%d,%d,%d,%d font:%dI";
static const char FMT_XYWH_BI[] = "%d,%d,%d,%d font:%dBI";
static const char FMT_XY2[] = "%d, %d, %d, %d";
static const char FMT_COLOR_HEX[] = "%02X, %02X, %02X, %02X";

// clang-format off

const PAGE_MSG base_evtlst[] =
{
    RETURN_TO_STANDBY_EVENT, DBPlayer_Settings_onCancel,
    NIL_EVENT, 0
};

const PAGE_MSG main_evtlst[] =
{
    PAGE_ENTER_EVENT, DBPlayer_Settings_onEnter,
    PAGE_EXIT_EVENT, DBPlayer_Settings_onExit,
    PREVIOUS_EVENT, DBPlayer_Settings_onPrev,
    CANCEL_EVENT, DBPlayer_Settings_onCancel,
    NIL_EVENT, 0
};

const PAGE_DESC DBPlayer_Settings_Base_Page = {BASE_PAGE_NAME, 0, base_evtlst};
const PAGE_DESC DBPlayer_Settings_Main_Page = {MAIN_PAGE_NAME, 0, main_evtlst};

// clang-format on

THUMB16
NEWCODE void Text_OnSelect(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	int item = ListMenu_GetSelectedItem(setbook->sub_menu);
	if (item == SUBITEM_TXT_STATE)
	{
		OneOfMany_SetMode(book, 2);
	}
	else if (item == SUBITEM_TXT_COLOR)
	{
		SetColor(book, 1);
	}
	else if (item == SUBITEM_TXT_OVERLAY)
	{
		SetColor(book, 2);
	}
	else if (item == SUBITEM_TXT_ALIGN)
	{
		OneOfMany_SetMode(book, 1);
	}
	else if (item == SUBITEM_TXT_VISUAL)
	{
		SetVisual(book);
	}
}

THUMB16
NEWCODE void Progress_OnSelect(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	int item = ListMenu_GetSelectedItem(setbook->sub_menu);
	if (item == SUBITEM_PB_STATE)
	{
		SetActivate(book, SUBITEM_PB_LAST);
	}
	else if (item == SUBITEM_PB_SLIDER)
	{
		SetActivate(book, SUBITEM_PB_LAST);
	}
	else if (item == SUBITEM_PB_ROUND)
	{
		SetActivate(book, SUBITEM_PB_LAST);
	}
	else if (item == SUBITEM_PB_BCOLOR)
	{
		SetColor(book, 1);
	}
	else if (item == SUBITEM_PB_FCOLOR)
	{
		SetColor(book, 2);
	}
	else if (item == SUBITEM_PB_VISUAL)
	{
		SetVisual(book);
	}
}

THUMB16
NEWCODE void Image_OnSelect(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	int item = ListMenu_GetSelectedItem(setbook->sub_menu);
	if (item == SUBITEM_IMG_STATE)
	{
		SetActivate(book, SUBITEM_IMG_LAST);
	}
	else if (item == SUBITEM_IMG_VISUAL)
	{
		SetVisual(book);
	}
}

THUMB16
NEWCODE void Background_OnSelect(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	int item = ListMenu_GetSelectedItem(setbook->sub_menu);
	if (item == SUBITEM_BG_TYPE)
	{
		OneOfMany_SetMode(book, 0);
	}
	else if (item == SUBITEM_BG_COLOR)
	{
		SetColor(book, 0);
	}
	else if (item == SUBITEM_BG_VISUAL)
	{
		SetVisual(book);
	}
}

THUMB16
NEWCODE void Additional_OnSelect(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	int item = ListMenu_GetSelectedItem(setbook->sub_menu);
	if (item == SUBITEM_ADDITIONAL_1)
	{
		SetActivate(book, SUBITEM_ADDITIONAL_LAST);
	}
	else if (item == SUBITEM_ADDITIONAL_2)
	{
		SetActivate(book, SUBITEM_ADDITIONAL_LAST);
	}
#ifndef DB3350
	else if (item == SUBITEM_ADDITIONAL_3)
	{
		SetActivate(book, SUBITEM_ADDITIONAL_LAST);
	}
#endif
}

THUMB16
NEWCODE int Text_OnMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		DBP_DATA *data = GetData();
		int item = GUIonMessage_GetCreatedItemIndex(msg);

		TEXTID first_text = EMPTY_TEXTID;
		TEXTID second_text = EMPTY_TEXTID;

		if (item == SUBITEM_TXT_STATE)
		{
			first_text = TextID_Global(ID_STATE);
			if (data->temp.activate1)
				second_text = TEXT_ENABLED;
			else
				second_text = TEXT_DISABLED;
		}
		else
		{
			if (item == SUBITEM_TXT_COLOR || item == SUBITEM_TXT_OVERLAY)
			{
				uint32_t color;
				if (item == 1)
				{
					first_text = TextID_Global(ID_TEXT_COLOR);
					color = data->temp.color1;
				}
				else
				{
					first_text = TextID_Global(ID_COLOR_OVERLAY);
					color = data->temp.color2;
				}

				char buf[16];
				snprintf(buf,
				         MAXELEMS(buf),
				         FMT_COLOR_HEX,
				         COLOR_GET_R(color),
				         COLOR_GET_G(color),
				         COLOR_GET_B(color),
				         COLOR_GET_A(color));
				second_text = TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));
			}
			else if (item == SUBITEM_TXT_ALIGN)
			{
				first_text = TextID_Global(ID_ALIGN);
				if (data->temp.align == AlignLeft)
					second_text = TextID_Global(ID_ALIGN_LEFT);
				else if (data->temp.align == AlignRight)
					second_text = TextID_Global(ID_ALIGN_RIGHT);
				else if (data->temp.align == AlignCenter)
					second_text = TextID_Global(ID_ALIGN_CENTER);
			}
			else if (item == SUBITEM_TXT_VISUAL)
			{
				first_text = TextID_Global(ID_VISUAL_CONFIG);
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
				int font_size = data->temp.font & 0xFF;
				int font_style = data->temp.font >> 8;

				char buf[16];
				if (font_style == UIFontStylePlain)
				{
					snprintf(buf,
					         MAXELEMS(buf),
					         FMT_XYWH_R,
					         data->temp.x1,
					         data->temp.y1,
					         data->temp.x2,
					         data->temp.y1 + font_size,
					         font_size);
				}
				else if (font_style == UIFontStyleBold)
				{
					snprintf(buf,
					         MAXELEMS(buf),
					         FMT_XYWH_B,
					         data->temp.x1,
					         data->temp.y1,
					         data->temp.x2,
					         data->temp.y1 + font_size & 0xFF,
					         font_size & 0xFF);
				}
				else if (font_style == UIFontStyleItalic)
				{
					snprintf(buf,
					         MAXELEMS(buf),
					         FMT_XYWH_I,
					         data->temp.x1,
					         data->temp.y1,
					         data->temp.x2,
					         data->temp.y1 + font_size & 0xFF,
					         font_size & 0xFF);
				}
				else if (font_style == UIFontStyleBoldItalic)
				{
					snprintf(buf,
					         MAXELEMS(buf),
					         FMT_XYWH_BI,
					         data->temp.x1,
					         data->temp.y1,
					         data->temp.x2,
					         data->temp.y1 + font_size & 0xFF,
					         font_size & 0xFF);
				}
				second_text = TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));
#else
				second_text =
				        TextID_Create(Font_GetNameByFontId(data->temp.font), ENC_UCS2, TEXTID_ANY_LEN);
#endif
			}
			if (!data->temp.activate1)
				GUIonMessage_SetItemDisabled(msg, TRUE);
		}

		GUIonMessage_SetMenuItemText(msg, first_text);
		GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
	}
	return 1;
}

THUMB16
NEWCODE int Progress_OnMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		DBP_DATA *data = GetData();
		int item = GUIonMessage_GetCreatedItemIndex(msg);

		TEXTID first_text = EMPTY_TEXTID;
		TEXTID second_text = EMPTY_TEXTID;

		if (item == SUBITEM_PB_BCOLOR || item == SUBITEM_PB_FCOLOR)
		{
			uint32_t color;
			if (item == SUBITEM_PB_BCOLOR)
			{
				first_text = TEXT_COLOR_B;
				color = data->temp.color1;
			}
			else
			{
				first_text = TextID_Global(ID_COLOR_F);
				color = data->temp.color2;
			}

			char buf[16];
			snprintf(buf,
			         MAXELEMS(buf),
			         FMT_COLOR_HEX,
			         COLOR_GET_R(color),
			         COLOR_GET_G(color),
			         COLOR_GET_B(color),
			         COLOR_GET_A(color));
			second_text = TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));
		}
		else
		{
			switch (item)
			{
			case SUBITEM_PB_STATE:
				first_text = TextID_Global(ID_STATE);
				if (data->temp.activate1)
					second_text = TEXT_ENABLED;
				else
					second_text = TEXT_DISABLED;
				break;
			case SUBITEM_PB_SLIDER:
				first_text = TextID_Global(ID_SLIDER);
				if (data->temp.activate2)
					second_text = TEXT_ENABLED;
				else
					second_text = TEXT_DISABLED;
				break;
			case SUBITEM_PB_ROUND:
				first_text = TextID_Global(ID_PTYPE);
				if (data->temp.activate3)
					second_text = TextID_Global(ID_PTYPE_2);
				else
					second_text = TextID_Global(ID_PTYPE_1);
				break;
			case SUBITEM_PB_VISUAL:
				first_text = TextID_Global(ID_VISUAL_CONFIG);

				char buf[16];
				snprintf(buf,
				         MAXELEMS(buf),
				         FMT_XYWH,
				         data->temp.x1,
				         data->temp.y1,
				         data->temp.x2 - data->temp.x1,
				         data->temp.y2 - data->temp.y1);
				second_text = TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));
				break;
			}
		}
		GUIonMessage_SetMenuItemText(msg, first_text);
		GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
	}
	return 1;
}

THUMB16
NEWCODE int Image_OnMessage(GUI_MESSAGE *msg)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)GUIonMessage_GetBook(msg);
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		DBP_DATA *data = GetData();

		TEXTID first_text = EMPTY_TEXTID;
		TEXTID second_text = EMPTY_TEXTID;

		switch (GUIonMessage_GetCreatedItemIndex(msg))
		{
		case SUBITEM_IMG_STATE:
			first_text = TextID_Global(ID_STATE);

			if (data->temp.activate1)
				second_text = TEXT_ENABLED;
			else
				second_text = TEXT_DISABLED;

			break;
		case SUBITEM_IMG_VISUAL:
			first_text = TextID_Global(ID_VISUAL_CONFIG);

			char buf[16];
			if (setbook->is_cover_art)
				snprintf(buf,
				         MAXELEMS(buf),
				         FMT_XYWH,
				         data->temp.x1,
				         data->temp.y1,
				         data->temp.x2 - data->temp.x1,
				         data->temp.y2 - data->temp.y1);

			else
				snprintf(buf, MAXELEMS(buf), FMT_XY, data->temp.x1, data->temp.y1);

			second_text = TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));

			if (!data->temp.activate1)
				GUIonMessage_SetItemDisabled(msg, TRUE);

			break;
		}

		GUIonMessage_SetMenuItemText(msg, first_text);
		GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
	}
	return 1;
}

THUMB16
NEWCODE int Background_OnMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		DBP_DATA *data = GetData();
		int item = GUIonMessage_GetCreatedItemIndex(msg);

		TEXTID first_text = EMPTY_TEXTID;
		TEXTID second_text = EMPTY_TEXTID;

		if (item == SUBITEM_BG_TYPE)
		{
			first_text = TEXT_MODE;

			switch (data->temp.activate1)
			{
			case BG_TYPE_IMAGE: second_text = TextID_Global(ID_BACKGROUND_IMAGE); break;
			case BG_TYPE_THEME: second_text = TextID_Global(ID_BACKGROUND_THEME); break;
			case BG_TYPE_COLOR: second_text = TextID_Global(ID_BACKGROUND_COLOR); break;
			}
		}
		else if (item == SUBITEM_BG_COLOR)
		{
			first_text = TEXT_COLOR;
			uint32_t color = data->temp.color1;

			char buf[16];
			snprintf(buf,
			         MAXELEMS(buf),
			         FMT_COLOR_HEX,
			         COLOR_GET_R(color),
			         COLOR_GET_G(color),
			         COLOR_GET_B(color),
			         COLOR_GET_A(color));
			second_text = TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));

			if (data->temp.activate1 == BG_TYPE_IMAGE || data->temp.activate1 == BG_TYPE_THEME)
				GUIonMessage_SetItemDisabled(msg, TRUE);
		}
		else if (item == SUBITEM_BG_VISUAL)
		{
			first_text = TextID_Global(ID_VISUAL_CONFIG);

			char buf[16];
			snprintf(buf,
			         MAXELEMS(buf),
			         FMT_XY2,
			         data->temp.x1,
			         data->temp.y1,
			         data->temp.x2,
			         data->temp.y2);
			second_text = TextID_Create(buf, ENC_LAT1, TEXTID_ANY_LEN);

			if (data->temp.activate1 == BG_TYPE_THEME || data->temp.activate1 == BG_TYPE_COLOR)
				GUIonMessage_SetItemDisabled(msg, TRUE);
		}
		GUIonMessage_SetMenuItemText(msg, first_text);
		GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
	}
	return 1;
}

THUMB16
NEWCODE int Additional_OnMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		DBP_DATA *data = GetData();

		TEXTID first_text = EMPTY_TEXTID;
		TEXTID second_text = EMPTY_TEXTID;

		switch (GUIonMessage_GetCreatedItemIndex(msg))
		{
		case SUBITEM_ADDITIONAL_1:
			first_text = TextID_Global(ID_FULLSCREEN);
			if (data->temp.activate1)
				second_text = TEXT_ENABLED;
			else
				second_text = TEXT_DISABLED;
			break;
		case SUBITEM_ADDITIONAL_2:
			first_text = TextID_Global(ID_SOFTKEYS);
			if (data->temp.activate2)
				second_text = TEXT_ENABLED;
			else
				second_text = TEXT_DISABLED;
			break;
#ifndef DB3350
		case SUBITEM_ADDITIONAL_3:
			first_text = TEXT_ANIMATION;
			if (data->temp.activate3)
				second_text = TEXT_ENABLED;
			else
				second_text = TEXT_DISABLED;
			break;
#endif
		}
		GUIonMessage_SetMenuItemText(msg, first_text);
		GUIonMessage_SetMenuItemSecondLineText(msg, second_text);
	}
	return 1;
}

THUMB16
NEWCODE void Editor_OnBack(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	if (setbook->changed)
		SaveData(FALSE, setbook->element);
	FREE_GUI(setbook->sub_menu);
}

THUMB16
NEWCODE void CreateEditor(SETTINGS_BOOK *setbook, int type, int count)
{
	if (setbook->sub_menu = CreateListMenu(&setbook->book, UIDisplay_Main))
	{
		if (type == EDIT_TEXT)
		{
			ListMenu_SetOnMessage(setbook->sub_menu, Text_OnMessage);
			GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Text_OnSelect);
		}
		else if (type == EDIT_SLIDER)
		{
			ListMenu_SetOnMessage(setbook->sub_menu, Progress_OnMessage);
			GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Progress_OnSelect);
		}
		else if (type == EDIT_ICON)
		{
			ListMenu_SetOnMessage(setbook->sub_menu, Image_OnMessage);
			GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Image_OnSelect);
		}
		else if (type == EDIT_BACKGROUND)
		{
			ListMenu_SetOnMessage(setbook->sub_menu, Background_OnMessage);
			GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Background_OnSelect);
		}
		else if (type == EDIT_EXTENDED)
		{
			ListMenu_SetOnMessage(setbook->sub_menu, Additional_OnMessage);
			GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_SELECT1, Additional_OnSelect);
		}

		GUIObject_SetTitleText(setbook->sub_menu, TextID_Setting(setbook->element));
		ListMenu_SetItemCount(setbook->sub_menu, count);
		ListMenu_SetCursorToItem(setbook->sub_menu, 0);
		ListMenu_SetItemStyle(setbook->sub_menu, 3);
		GUIObject_SoftKeys_SetAction(setbook->sub_menu, ACTION_BACK, Editor_OnBack);
		GUIObject_Show(setbook->sub_menu);
	}
}

//******************************************************************************

THUMB16
NEWCODE int Setting_OnMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		int item = GUIonMessage_GetCreatedItemIndex(msg);
		GUIonMessage_SetMenuItemText(msg, TextID_Setting(item));
	}
	return 1;
}

THUMB16
NEWCODE void Setting_OnSelect(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	int item = ListMenu_GetSelectedItem(setbook->main_menu);
	setbook->element = item;
	setbook->changed = FALSE;

	DBP_DATA *data = GetData();
	data->temp.activate1 = NULL;
	data->temp.activate2 = NULL;
	data->temp.activate3 = NULL;
	data->temp.align = NULL;
	data->temp.color1 = NULL;
	data->temp.color2 = NULL;
	data->temp.overlay = NULL;
	data->temp.font = NULL;
	data->temp.x1 = NULL;
	data->temp.y1 = NULL;
	data->temp.x2 = NULL;
	data->temp.y2 = NULL;

	if (item == ITEM_ARTIST)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.artist.state;
		data->temp.align = data->settings.artist.align;
		data->temp.color1 = data->settings.artist.tcolor;
		data->temp.color2 = data->settings.artist.ocolor;
		data->temp.overlay = data->settings.artist.overlay;
		data->temp.font = data->settings.artist.font;
		data->temp.x1 = data->settings.artist.coord.x1;
		data->temp.y1 = data->settings.artist.coord.y1;
		data->temp.x2 = data->settings.artist.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_TITLE)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.title.state;
		data->temp.align = data->settings.title.align;
		data->temp.color1 = data->settings.title.tcolor;
		data->temp.color2 = data->settings.title.ocolor;
		data->temp.overlay = data->settings.title.overlay;
		data->temp.font = data->settings.title.font;
		data->temp.x1 = data->settings.title.coord.x1;
		data->temp.y1 = data->settings.title.coord.y1;
		data->temp.x2 = data->settings.title.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_ALBUM)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.album.state;
		data->temp.align = data->settings.album.align;
		data->temp.color1 = data->settings.album.tcolor;
		data->temp.color2 = data->settings.album.ocolor;
		data->temp.overlay = data->settings.album.overlay;
		data->temp.font = data->settings.album.font;
		data->temp.x1 = data->settings.album.coord.x1;
		data->temp.y1 = data->settings.album.coord.y1;
		data->temp.x2 = data->settings.album.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_YEAR)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.year.state;
		data->temp.align = data->settings.year.align;
		data->temp.color1 = data->settings.year.tcolor;
		data->temp.color2 = data->settings.year.ocolor;
		data->temp.overlay = data->settings.year.overlay;
		data->temp.font = data->settings.year.font;
		data->temp.x1 = data->settings.year.coord.x1;
		data->temp.y1 = data->settings.year.coord.y1;
		data->temp.x2 = data->settings.year.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_GENRE)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.genre.state;
		data->temp.align = data->settings.genre.align;
		data->temp.color1 = data->settings.genre.tcolor;
		data->temp.color2 = data->settings.genre.ocolor;
		data->temp.overlay = data->settings.genre.overlay;
		data->temp.font = data->settings.genre.font;
		data->temp.x1 = data->settings.genre.coord.x1;
		data->temp.y1 = data->settings.genre.coord.y1;
		data->temp.x2 = data->settings.genre.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_FILETYPE)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.ext.state;
		data->temp.align = data->settings.ext.align;
		data->temp.color1 = data->settings.ext.tcolor;
		data->temp.color2 = data->settings.ext.ocolor;
		data->temp.overlay = data->settings.ext.overlay;
		data->temp.font = data->settings.ext.font;
		data->temp.x1 = data->settings.ext.coord.x1;
		data->temp.y1 = data->settings.ext.coord.y1;
		data->temp.x2 = data->settings.ext.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_TOTAL)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.time_t.state;
		data->temp.align = data->settings.time_t.align;
		data->temp.color1 = data->settings.time_t.tcolor;
		data->temp.color2 = data->settings.time_t.ocolor;
		data->temp.overlay = data->settings.time_t.overlay;
		data->temp.font = data->settings.time_t.font;
		data->temp.x1 = data->settings.time_t.coord.x1;
		data->temp.y1 = data->settings.time_t.coord.y1;
		data->temp.x2 = data->settings.time_t.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_ELAPSED)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.time_e.state;
		data->temp.align = data->settings.time_e.align;
		data->temp.color1 = data->settings.time_e.tcolor;
		data->temp.color2 = data->settings.time_e.ocolor;
		data->temp.overlay = data->settings.time_e.overlay;
		data->temp.font = data->settings.time_e.font;
		data->temp.x1 = data->settings.time_e.coord.x1;
		data->temp.y1 = data->settings.time_e.coord.y1;
		data->temp.x2 = data->settings.time_e.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_REMAINING)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.time_r.state;
		data->temp.align = data->settings.time_r.align;
		data->temp.color1 = data->settings.time_r.tcolor;
		data->temp.color2 = data->settings.time_r.ocolor;
		data->temp.overlay = data->settings.time_r.overlay;
		data->temp.font = data->settings.time_r.font;
		data->temp.x1 = data->settings.time_r.coord.x1;
		data->temp.y1 = data->settings.time_r.coord.y1;
		data->temp.x2 = data->settings.time_r.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_BITRATE)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.bitrate.state;
		data->temp.align = data->settings.bitrate.align;
		data->temp.color1 = data->settings.bitrate.tcolor;
		data->temp.color2 = data->settings.bitrate.ocolor;
		data->temp.overlay = data->settings.bitrate.overlay;
		data->temp.font = data->settings.bitrate.font;
		data->temp.x1 = data->settings.bitrate.coord.x1;
		data->temp.y1 = data->settings.bitrate.coord.y1;
		data->temp.x2 = data->settings.bitrate.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_SAMPLERATE)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.samplerate.state;
		data->temp.align = data->settings.samplerate.align;
		data->temp.color1 = data->settings.samplerate.tcolor;
		data->temp.color2 = data->settings.samplerate.ocolor;
		data->temp.overlay = data->settings.samplerate.overlay;
		data->temp.font = data->settings.samplerate.font;
		data->temp.x1 = data->settings.samplerate.coord.x1;
		data->temp.y1 = data->settings.samplerate.coord.y1;
		data->temp.x2 = data->settings.samplerate.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_AUDIOOUTPUT)
	{
		setbook->elem_type = ELEM_TEXT;
		data->temp.activate1 = data->settings.audiooutput.state;
		data->temp.align = data->settings.audiooutput.align;
		data->temp.color1 = data->settings.audiooutput.tcolor;
		data->temp.color2 = data->settings.audiooutput.ocolor;
		data->temp.overlay = data->settings.audiooutput.overlay;
		data->temp.font = data->settings.audiooutput.font;
		data->temp.x1 = data->settings.audiooutput.coord.x1;
		data->temp.y1 = data->settings.audiooutput.coord.y1;
		data->temp.x2 = data->settings.audiooutput.coord.x2;
		CreateEditor(setbook, EDIT_TEXT, SUBITEM_TXT_LAST);
	}
	else if (item == ITEM_TIME_PROGRESS)
	{
		setbook->elem_type = ELEM_RECT;
		data->temp.activate1 = data->settings.time.state;
		data->temp.activate2 = data->settings.time.slider;
		data->temp.activate3 = data->settings.time.round;
		data->temp.color1 = data->settings.time.progress_bcolor;
		data->temp.color2 = data->settings.time.progress_fcolor;
		data->temp.x1 = data->settings.time.progress_rect.x1;
		data->temp.y1 = data->settings.time.progress_rect.y1;
		data->temp.x2 = data->settings.time.progress_rect.x2;
		data->temp.y2 = data->settings.time.progress_rect.y2;
		CreateEditor(setbook, EDIT_SLIDER, SUBITEM_PB_LAST);
	}
	else if (item == ITEM_VOLUME_PROGRESS)
	{
		setbook->elem_type = ELEM_RECT;
		data->temp.activate1 = data->settings.volume.state;
		data->temp.activate2 = data->settings.volume.slider;
		data->temp.activate3 = data->settings.volume.round;
		data->temp.color1 = data->settings.volume.progress_bcolor;
		data->temp.color2 = data->settings.volume.progress_fcolor;
		data->temp.x1 = data->settings.volume.progress_rect.x1;
		data->temp.y1 = data->settings.volume.progress_rect.y1;
		data->temp.x2 = data->settings.volume.progress_rect.x2;
		data->temp.y2 = data->settings.volume.progress_rect.y2;
		CreateEditor(setbook, EDIT_SLIDER, SUBITEM_PB_LAST);
	}
	else if (item == ITEM_COVERART)
	{
		setbook->elem_type = ELEM_RECT;
		setbook->is_cover_art = TRUE;
		data->temp.activate1 = data->settings.cover;
		data->temp.x1 = data->settings.cover_rect.x1;
		data->temp.y1 = data->settings.cover_rect.y1;
		data->temp.x2 = data->settings.cover_rect.x2;
		data->temp.y2 = data->settings.cover_rect.y2;
		CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
	}
	else if (item == ITEM_FRAME)
	{
		setbook->elem_type = ELEM_ICON;
		setbook->is_cover_art = FALSE;
		data->temp.activate1 = data->settings.frame.state;
		data->temp.x1 = data->settings.frame.pos.x;
		data->temp.y1 = data->settings.frame.pos.y, CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
	}
	else if (item == ITEM_ARTIST_ICN)
	{
		setbook->elem_type = ELEM_ICON;
		setbook->is_cover_art = FALSE;
		data->temp.activate1 = data->settings.artist_icn.state;
		data->temp.x1 = data->settings.artist_icn.pos.x;
		data->temp.y1 = data->settings.artist_icn.pos.y, CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
	}
	else if (item == ITEM_TITLE_ICN)
	{
		setbook->elem_type = ELEM_ICON;
		setbook->is_cover_art = FALSE;
		data->temp.activate1 = data->settings.title_icn.state;
		data->temp.x1 = data->settings.title_icn.pos.x;
		data->temp.y1 = data->settings.title_icn.pos.y, CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
	}
	else if (item == ITEM_ALBUM_ICN)
	{
		setbook->elem_type = ELEM_ICON;
		setbook->is_cover_art = FALSE;
		data->temp.activate1 = data->settings.album_icn.state;
		data->temp.x1 = data->settings.album_icn.pos.x;
		data->temp.y1 = data->settings.album_icn.pos.y, CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
	}
	else if (item == ITEM_PLAYERSTATE_ICN)
	{
		setbook->elem_type = ELEM_ICON;
		setbook->is_cover_art = FALSE;
		data->temp.activate1 = data->settings.playerstate_icn.state;
		data->temp.x1 = data->settings.playerstate_icn.pos.x;
		data->temp.y1 = data->settings.playerstate_icn.pos.y,
		CreateEditor(setbook, EDIT_ICON, SUBITEM_IMG_LAST);
	}
	else if (item == ITEM_BACKROUND)
	{
		setbook->elem_type = ELEM_ICON;
		setbook->is_cover_art = FALSE;
		data->temp.activate1 = data->settings.background.state;
		data->temp.color1 = data->settings.background_color;
		data->temp.x1 = data->settings.background.pos.x;
		data->temp.y1 = data->settings.background.pos.y;
		CreateEditor(setbook, EDIT_BACKGROUND, SUBITEM_BG_LAST);
	}
	else if (item == ITEM_ADDITIONAL)
	{
		data->temp.activate1 = data->settings.screen;
		data->temp.activate2 = data->settings.soft;
#ifndef DB3350
		data->temp.activate3 = data->settings.animation;
#endif
		CreateEditor(setbook, EDIT_EXTENDED, SUBITEM_ADDITIONAL_LAST);
	}
}

THUMB16
NEWCODE void Question_OnYes(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	SaveData(TRUE, setbook->element);
	FreeBook(&setbook->book);

	DBP_DATA *data = GetData();
	if (data->settings.screen)
	{
		GUIObject_SetStyle(data->gui, UI_OverlayStyle_TrueFullScreen);
	}
	else
	{
		GUIObject_SetStyle(data->gui, UI_OverlayStyle_Default);
	}

	if (!data->settings.soft)
	{
		GUIObject_SoftKeys_Hide(data->gui);
	}
	else
	{
		GUIObject_SoftKeys_Show(data->gui);
	}
}

THUMB16
NEWCODE void Question_OnNo(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	DBP_DATA *Data = GetData();
	LoadData(Data);
	FreeBook(&setbook->book);
}

THUMB16
NEWCODE void Question_OnBack(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	FREE_GUI(setbook->question_menu);
}

THUMB16
NEWCODE void Setting_OnBack(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	if (setbook->changed)
	{
		if (setbook->question_menu = CreateYesNoQuestion(&setbook->book, UIDisplay_Main))
		{
			YesNoQuestion_SetDescriptionText(setbook->question_menu, TEXT_CHANGE);
			YesNoQuestion_SetQuestionText(setbook->question_menu, TEXT_QUESTION);
			YesNoQuestion_SetIcon(setbook->question_menu, POPUP_WARNING_ICN);
			GUIObject_SoftKeys_SetAction(setbook->question_menu, ACTION_YES, Question_OnYes);
			GUIObject_SoftKeys_SetAction(setbook->question_menu, ACTION_NO, Question_OnNo);
			GUIObject_SoftKeys_SetAction(setbook->question_menu, ACTION_BACK, Question_OnBack);
			GUIObject_Show(setbook->question_menu);
		}
	}
	else
	{
		FreeBook(&setbook->book);
	}
}

THUMB16
NEWCODE int DBPlayer_Settings_onEnter(void *data, BOOK *book)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	if (setbook->main_menu = CreateListMenu(&setbook->book, UIDisplay_Main))
	{
		GUIObject_SetTitleText(setbook->main_menu, TEXT_SETTINGS);
		ListMenu_SetItemCount(setbook->main_menu, ITEM_LAST);
		ListMenu_SetOnMessage(setbook->main_menu, Setting_OnMessage);
		ListMenu_SetCursorToItem(setbook->main_menu, 0);
		ListMenu_SetItemStyle(setbook->main_menu, 0);
		GUIObject_SoftKeys_SetAction(setbook->main_menu, ACTION_SELECT1, Setting_OnSelect);
		GUIObject_SoftKeys_SetAction(setbook->main_menu, ACTION_BACK, Setting_OnBack);
		GUIObject_Show(setbook->main_menu);
	}
	return 1;
}

THUMB16
NEWCODE int DBPlayer_Settings_onExit(void *data, BOOK *book)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	FREE_GUI(setbook->main_menu);
	FREE_GUI(setbook->sub_menu);
	FREE_GUI(setbook->options_menu);
	FREE_GUI(setbook->question_menu);
	return 1;
}

THUMB16
NEWCODE int DBPlayer_Settings_onPrev(void *data, BOOK *book)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	BookObj_ReturnPage(&setbook->book, PREVIOUS_EVENT);
	return 1;
}

THUMB16
NEWCODE int DBPlayer_Settings_onCancel(void *data, BOOK *book)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	BookObj_ReturnPage(&setbook->book, CANCEL_EVENT);
	return 1;
}

THUMB16
NEWCODE void SettingBook_onClose(BOOK *book)
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)book;
	FREE_GUI(setbook->main_menu);
	FREE_GUI(setbook->sub_menu);
	FREE_GUI(setbook->options_menu);
	FREE_GUI(setbook->question_menu);
	setbook->element = 0;
	setbook->elem_type = 0;
	setbook->changed = 0;
	setbook->is_cover_art = 0;
}

THUMB16
NEWCODE SETTINGS_BOOK *Create_DBPlayer_SettingBook()
{
	SETTINGS_BOOK *setbook = (SETTINGS_BOOK *)malloc(sizeof(SETTINGS_BOOK));
	memset(setbook, 0, sizeof(SETTINGS_BOOK));
	if (!CreateBook((BOOK *)setbook,
	                SettingBook_onClose,
	                &DBPlayer_Settings_Base_Page,
	                DBPLAYER_SETTINGS_BOOKNAME,
	                NO_BOOK_ID,
	                NULL))
	{
		mfree(setbook);
		return NULL;
	}
	setbook->main_menu = 0;
	setbook->sub_menu = 0;
	setbook->options_menu = 0;
	setbook->question_menu = 0;
	setbook->color_picker = 0;

	setbook->element = 0;
	setbook->elem_type = 0;
	setbook->changed = 0;
	setbook->is_cover_art = 0;
	return setbook;
}

THUMB16
NEWCODE void DBPlayer_Setting(BOOK *book, GUI *gui)
{
	SETTINGS_BOOK *setbook = Create_DBPlayer_SettingBook();
	if (setbook)
		BookObj_GotoPage(&setbook->book, &DBPlayer_Settings_Main_Page);
}
