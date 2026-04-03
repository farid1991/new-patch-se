#include "device.h"

#include <libse.h>
#include <sync.h>

#include <book/DB3350/MusicApplication_Book.h>
#include <types/IMMETypes.h>
#include <types/MusicServer_types.h>
#include <types/UIFont_types.h>
#include <types/UIRichText_types.h>

#include <types/Colors.h>

#include "dll.h"
#include "eq.h"
#include "gui.h"
#include "patch.h"

THUMB16
NEWCODE void RegisterImage(IMG *img, const wchar_t *fpath, const wchar_t *fname)
{
	char error_code;
	img->ID = NOIMAGE;
	img->ImageHandle = NOIMAGE;

	if (REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(&SYNC, &img->ImageHandle, &error_code))
		return;

	if (REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(&SYNC, img->ImageHandle, fpath, fname, NULL, &img->ID, &error_code))
		return;

	if (error_code)
		img->ImageHandle = NOIMAGE;
}

THUMB16
NEWCODE void UnRegisterEQImage(DISP_OBJ_CLEARBASS *disp_obj)
{
	if (disp_obj->Background.ID != NOIMAGE)
	{
		REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(
		        &SYNC, disp_obj->Background.ImageHandle, NULL, NULL, disp_obj->Background.ID, 1, NULL);
	}

	for (int j = 0; j < LastBoostLevel; j++)
	{
		if (disp_obj->Boost_Image[j].ID != NOIMAGE)
		{
			REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(&SYNC,
			                                         disp_obj->Boost_Image[j].ImageHandle,
			                                         NULL,
			                                         NULL,
			                                         disp_obj->Boost_Image[j].ID,
			                                         1,
			                                         NULL);
		}
	}
	for (int k = 0; k < LastBarLevel; k++)
	{
		if (disp_obj->Bar_Image[k].ID != NOIMAGE)
		{
			REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(&SYNC,
			                                         disp_obj->Bar_Image[k].ImageHandle,
			                                         NULL,
			                                         NULL,
			                                         disp_obj->Bar_Image[k].ID,
			                                         TRUE,
			                                         NULL);
		}
	}
}

THUMB16
NEWCODE void LoadBackgroundImage(DISP_OBJ_CLEARBASS *disp_obj)
{
	if (FSX_IsFileExists(CONFIG_PATH, BackgroundImage))
		RegisterImage(&disp_obj->Background, CONFIG_PATH, BackgroundImage);
	else
		disp_obj->Background.ID = NOIMAGE;
}

THUMB16
NEWCODE void LoadBoostImage(DISP_OBJ_CLEARBASS *disp_obj)
{
	for (int i = 0; i < LastBoostLevel; i++)
	{
		if (FSX_IsFileExists(CONFIG_PATH, BoostImage[i]))
			RegisterImage(&disp_obj->Boost_Image[i], CONFIG_PATH, BoostImage[i]);
		else
			disp_obj->Boost_Image[i].ID = NOIMAGE;
	}
}

THUMB16
NEWCODE void LoadBarImage(DISP_OBJ_CLEARBASS *disp_obj)
{
	for (int i = 0; i < LastBarLevel; i++)
	{
		if (FSX_IsFileExists(CONFIG_PATH, BarImage[i]))
			RegisterImage(&disp_obj->Bar_Image[i], CONFIG_PATH, BarImage[i]);
		else
			disp_obj->Bar_Image[i].ID = NOIMAGE;
	}
}

THUMB16
NEWCODE void DrawImage(int16_t x, int16_t y, IMAGEID img)
{
	if (img != NOIMAGE)
		dll_GC_PutChar(x, y, 0, 0, img);
}

THUMB16
NEWCODE void Clearbass_SetEqualizerGain(DISP_OBJ *disp)
{
	GUI *Clearbass = DispObject_GetGUI(disp);
	MusicApplication_Book *MusicBook = (MusicApplication_Book *)GUIObject_GetBook(Clearbass);

	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)disp;

	// clang-format off
	Set_EqualizerGain(MusicBook, TMMEEqBand_63, (disp_obj->bar1_level - Bar_Netral) * (disp_obj->boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_250, (disp_obj->bar2_level - Bar_Netral) * (disp_obj->boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_1000, (disp_obj->bar3_level - Bar_Netral) * (disp_obj->boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_4000, (disp_obj->bar4_level - Bar_Netral) * (disp_obj->boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_16000, (disp_obj->bar5_level - Bar_Netral) * (disp_obj->boost_level + 2));
	// clang-format on
}

THUMB16
NEWCODE void GUIObject_Clearbass_SetBarLevel(GUI *gui, int b0, int b1, int b2, int b3, int b4, int b5)
{
	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
	disp_obj->boost_level = b0;
	disp_obj->bar1_level = b1;
	disp_obj->bar2_level = b2;
	disp_obj->bar3_level = b3;
	disp_obj->bar4_level = b4;
	disp_obj->bar5_level = b5;
	Clearbass_SetEqualizerGain(&disp_obj->disp);
}

THUMB16
NEWCODE int GUIObject_Clearbass_GetCursor(GUI *gui)
{
	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
	return disp_obj->cursor;
}

THUMB16
NEWCODE void GUIObject_Clearbass_GetBarLevel(GUI *gui, int *b0, int *b1, int *b2, int *b3, int *b4, int *b5)
{
	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)GUIObject_GetDispObject(gui);
	*b0 = disp_obj->boost_level;
	*b1 = disp_obj->bar1_level;
	*b2 = disp_obj->bar2_level;
	*b3 = disp_obj->bar3_level;
	*b4 = disp_obj->bar4_level;
	*b5 = disp_obj->bar5_level;
}

THUMB16
NEWCODE int ClearbassGUI_OnCreate(DISP_OBJ *disp)
{
	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)disp;

	disp_obj->width = Display_GetWidth(UIDisplay_Main);
	disp_obj->height = Display_GetHeight(UIDisplay_Main);

	disp_obj->cursor = Eq_Band0;

	disp_obj->boost_level = Boost_0;
	disp_obj->bar1_level = Bar_Netral;
	disp_obj->bar2_level = Bar_Netral;
	disp_obj->bar3_level = Bar_Netral;
	disp_obj->bar4_level = Bar_Netral;
	disp_obj->bar5_level = Bar_Netral;

	LoadBackgroundImage(disp_obj);
	LoadBarImage(disp_obj);
	LoadBoostImage(disp_obj);

	return 1;
}

THUMB16
NEWCODE void ClearbassGUI_OnClose(DISP_OBJ *disp)
{
	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)disp;
	UnRegisterEQImage(disp_obj);
}

THUMB16
NEWCODE void ClearbassGUI_OnRedraw(DISP_OBJ *disp, int r1, int r2, int r3)
{
	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)disp;

	DrawImage(0, 22, disp_obj->Background.ID);

	DrawImage(14, 96, disp_obj->Boost_Image[disp_obj->boost_level].ID);

	DrawImage(75, 96, disp_obj->Bar_Image[disp_obj->bar1_level].ID);

	DrawImage(106, 96, disp_obj->Bar_Image[disp_obj->bar2_level].ID);

	DrawImage(137, 96, disp_obj->Bar_Image[disp_obj->bar3_level].ID);

	DrawImage(168, 96, disp_obj->Bar_Image[disp_obj->bar4_level].ID);

	DrawImage(199, 96, disp_obj->Bar_Image[disp_obj->bar5_level].ID);

	DrawRect(redrect_positions[disp_obj->cursor][0],
	         redrect_positions[disp_obj->cursor][1],
	         redrect_positions[disp_obj->cursor][0] + redrect_positions[disp_obj->cursor][2],
	         redrect_positions[disp_obj->cursor][1] + redrect_positions[disp_obj->cursor][3],
	         clEmpty,
	         clRed2);

	dll_DrawString(MAKE_FONT(UIFontStyleBold, 24), EQUALIZER_TXT, AlignCenter, 0, 40, disp_obj->width, 60, clWhite);
}

THUMB16
NEWCODE void ClearbassGUI_OnKey(DISP_OBJ *disp, int key, int count, int repeat, int mode)
{
	DISP_OBJ_CLEARBASS *disp_obj = (DISP_OBJ_CLEARBASS *)disp;

	if (mode == KBD_SHORT_PRESS || mode == KBD_REPEAT)
	{
		switch (key)
		{
		case KEY_RIGHT:
			if (disp_obj->cursor < Eq_Band5)
				disp_obj->cursor++;
			else
				disp_obj->cursor = Eq_Band5;
			break;
		case KEY_LEFT:
			if (disp_obj->cursor > Eq_Band0)
				disp_obj->cursor--;
			else
				disp_obj->cursor = Eq_Band0;
			break;
		case KEY_UP:
			if (disp_obj->cursor == Eq_Band0)
			{
				if (disp_obj->boost_level < Boost_3)
					disp_obj->boost_level++;
				else
					disp_obj->boost_level = Boost_3;
			}
			else if (disp_obj->cursor == Eq_Band1)
			{
				if (disp_obj->bar1_level < Bar_Plus_3)
					disp_obj->bar1_level++;
				else
					disp_obj->bar1_level = Bar_Plus_3;
			}
			else if (disp_obj->cursor == Eq_Band2)
			{
				if (disp_obj->bar2_level < Bar_Plus_3)
					disp_obj->bar2_level++;
				else
					disp_obj->bar2_level = Bar_Plus_3;
			}
			else if (disp_obj->cursor == Eq_Band3)
			{
				if (disp_obj->bar3_level < Bar_Plus_3)
					disp_obj->bar3_level++;
				else
					disp_obj->bar3_level = Bar_Plus_3;
			}
			else if (disp_obj->cursor == Eq_Band4)
			{
				if (disp_obj->bar4_level < Bar_Plus_3)
					disp_obj->bar4_level++;
				else
					disp_obj->bar4_level = Bar_Plus_3;
			}
			else if (disp_obj->cursor == Eq_Band5)
			{
				if (disp_obj->bar5_level < Bar_Plus_3)
					disp_obj->bar5_level++;
				else
					disp_obj->bar5_level = Bar_Plus_3;
			}
			break;
		case KEY_DOWN:
			if (disp_obj->cursor == Eq_Band0)
			{
				if (disp_obj->boost_level > Boost_0)
					disp_obj->boost_level--;
				else
					disp_obj->boost_level = Boost_0;
			}
			else if (disp_obj->cursor == Eq_Band1)
			{
				if (disp_obj->bar1_level > Bar_Minus_3)
					disp_obj->bar1_level--;
				else
					disp_obj->bar1_level = Bar_Minus_3;
			}
			else if (disp_obj->cursor == Eq_Band2)
			{
				if (disp_obj->bar2_level > Bar_Minus_3)
					disp_obj->bar2_level--;
				else
					disp_obj->bar2_level = Bar_Minus_3;
			}
			else if (disp_obj->cursor == Eq_Band3)
			{
				if (disp_obj->bar3_level > Bar_Minus_3)
					disp_obj->bar3_level--;
				else
					disp_obj->bar3_level = Bar_Minus_3;
			}
			else if (disp_obj->cursor == Eq_Band4)
			{
				if (disp_obj->bar4_level > Bar_Minus_3)
					disp_obj->bar4_level--;
				else
					disp_obj->bar4_level = Bar_Minus_3;
			}
			else if (disp_obj->cursor == Eq_Band5)
			{
				if (disp_obj->bar5_level > Bar_Minus_3)
					disp_obj->bar5_level--;
				else
					disp_obj->bar5_level = Bar_Minus_3;
			}
			break;
		}
		Clearbass_SetEqualizerGain(disp);
		DispObject_InvalidateRect(disp, NULL);
	}
}

THUMB16
NEWCODE void ClearbassGUI_OnLayout(DISP_OBJ *disp_obj, void *layoutstruct)
{
	DispObject_SetLayerColor(disp_obj, clEmpty);
}

THUMB16
NEWCODE void ClearbassGUI_constr(DISP_DESC *desc)
{
	DISP_DESC_SetName(desc, GUI_MANUAL_EQ);
	DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_CLEARBASS));
	DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)ClearbassGUI_OnCreate);
	DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)ClearbassGUI_OnClose);
	DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)ClearbassGUI_OnRedraw);
	DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)ClearbassGUI_OnKey);
	DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)ClearbassGUI_OnLayout);
}

THUMB16
NEWCODE void ClearbassGUI_destr(GUI *desc) {}

THUMB16
NEWCODE void ClearbassGUI_callback(DISP_OBJ *, void *msg, GUI *) {}

THUMB16
NEWCODE GUI *Create_ClearbassGUI(BOOK *book)
{
	GUI *gui_cb = (GUI *)malloc(sizeof(GUI));
	if (!GUIObject_Create(gui_cb,
	                      ClearbassGUI_destr,
	                      ClearbassGUI_constr,
	                      book,
	                      ClearbassGUI_callback,
	                      UIDisplay_Main,
	                      sizeof(GUI)))
	{
		mfree(gui_cb);
		return NULL;
	}

	if (book)
		BookObj_AddGUIObject(book, gui_cb);

	GUIObject_SetTitleType(gui_cb, UI_TitleMode_None);
	GUIObject_SetStyle(gui_cb, UI_OverlayStyle_TrueFullScreen);
	GUIObject_SoftKeys_RemoveBackground(gui_cb);

	return gui_cb;
}
