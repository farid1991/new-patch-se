#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#endif

#include <libse.h>
#include <ini_parser.h>
#include <sync.h>

#include <book/SetBook.h>

#include <types/Colors.h>
#include <types/UIRichText_types.h>

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"
#define DrawImage dll_GC_PutChar
#else
#define DrawImage GC_PutChar
#endif

#include "patch.h"

THUMB16
NEWCODE void *malloc(int size)
{
#if defined(DB2020)
	return (memalloc(NULL, size, 1, 5, GUI_BRIGHT_MEM, NULL));
#elif defined(A2)
	return (memalloc(-1, size, 1, 5, GUI_BRIGHT_MEM, NULL));
#else
	return (memalloc(size, 1, 5, GUI_BRIGHT_MEM, NULL));
#endif
}

THUMB16
NEWCODE void mfree(void *mem)
{
	if (mem)
#if defined(DB2020) || defined(A2)
		memfree(NULL, mem, GUI_BRIGHT_MEM, NULL);
#else
		memfree(mem, GUI_BRIGHT_MEM, NULL);
#endif
}

THUMB16
NEWCODE CONFIG_DATA *ReadConfig()
{
	size_t cfg_size = sizeof(CONFIG_DATA);
	CONFIG_DATA *cfg = malloc(cfg_size);
	if (!cfg)
		return NULL;

	memset(cfg, 0, cfg_size);

	FSTAT st;
	if (fstat(CONFIG_PATH, CONFIG_NAME, &st) != 0)
		return cfg;

	int file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file == -1)
		return cfg;

	int fsize = st.fsize;
	char *buf = (char *)malloc(fsize + 1);
	if (!buf)
	{
		fclose(file);
		return cfg;
	}

	memset(buf, 0, fsize + 1);
	if (fread(file, buf, fsize) != fsize)
	{
		fclose(file);
		mfree(buf);
		return cfg;
	}
	fclose(file);

	char *param;

	/* =================== Background ==========================*/

	param = manifest_GetParam(buf, KEY_BACKGROUND, 0);
	if (param)
	{
		int values[2];
		ini_parse_values(param, values, 2);
		cfg->Icon_Background_x = values[0];
		cfg->Icon_Background_y = values[1];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_LEVEL, 0);
	if (param)
	{
		int values[2];
		ini_parse_values(param, values, 2);
		cfg->Icon_Level_x = values[0];
		cfg->Icon_Level_y = values[1];
		mfree(param);
	}
	/* ====================== Title ==========================*/

	param = manifest_GetParam(buf, KEY_TITLE_POS, 0);
	if (param)
	{
		int values[4];
		ini_parse_values(param, values, 4);
		cfg->Title_Text_x1 = values[0];
		cfg->Title_Text_y1 = values[1];
		cfg->Title_Text_x2 = values[2];
		cfg->Title_Text_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TITLE_COLOR, 0);
	if (param)
	{
		int values[2];
		ini_parse_values(param, values, 2);
		cfg->Title_Text_Color = values[0];
		cfg->Title_Text_Border = values[1];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TITLE_ALIGN, 0);
	if (param)
	{
		cfg->Title_Text_Align = ini_parse_value(param);
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TITLE_FONT, 0);
	if (param)
	{
		cfg->Title_Text_Font = ini_parse_value(param);
		mfree(param);
	}

	/* ===================== Percent ========================*/

	param = manifest_GetParam(buf, KEY_PERCENT_POS, 0);
	if (param)
	{
		int values[4];
		ini_parse_values(param, values, 4);
		cfg->Percent_Text_x1 = values[0];
		cfg->Percent_Text_y1 = values[1];
		cfg->Percent_Text_x2 = values[2];
		cfg->Percent_Text_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_PERCENT_COLOR, 0);
	if (param)
	{
		int values[2];
		ini_parse_values(param, values, 2);
		cfg->Percent_Text_Color = values[0];
		cfg->Percent_Text_Border = values[1];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_PERCENT_ALIGN, 0);
	if (param)
	{
		cfg->Percent_Text_Align = ini_parse_value(param);
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_PERCENT_FONT, 0);
	if (param)
	{
		cfg->Percent_Text_Font = ini_parse_value(param);
		mfree(param);
	}
	mfree(buf);

	return cfg;
}

THUMB16
NEWCODE void RegisterImage(IMAGE_DESC *img, const wchar_t *fpath, const wchar_t *fname)
{
	char error_code;
	img->id = NOIMAGE;
	img->handle = NOIMAGE;

	if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(&SYNC, &img->handle, &error_code))
		if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(
		            &SYNC, img->handle, fpath, fname, NULL, &img->id, &error_code))
			if (error_code)
				img->handle = NOIMAGE;
}

THUMB16
NEWCODE void UnLoadImages(DISP_OBJ_BRIGHT *disp_obj)
{
	char error_code;

	ImageID_Free(disp_obj->active_image);

	for (int i = 0; i < LAST_ICN; i++)
	{
		if (disp_obj->images[i].id != NOIMAGE)
			REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(
			        &SYNC, disp_obj->images[i].handle, 0, 0, disp_obj->images[i].id, 1, &error_code);
	}
}

THUMB16
NEWCODE void LoadImages(DISP_OBJ_BRIGHT *disp_obj)
{
	for (int i = 0; i < LAST_ICN; i++)
	{
		if (FSX_IsFileExists(CONFIG_PATH, images_names[i]))
			RegisterImage(&disp_obj->images[i], CONFIG_PATH, images_names[i]);
		else
			disp_obj->images[i].id = NOIMAGE;
	}
}

THUMB16
NEWCODE void SetScreenBrightness(int bright)
{
#ifdef A1
	Display_SetBrightness(UIDisplay_Main, bright);
#else
	Display_SetBrightness(bright);
#endif
	Save_Brightness_Level(bright);
}

THUMB16
NEWCODE int Bright_onCreate(DISP_OBJ_BRIGHT *disp_obj)
{
	disp_obj->bright = Display_GetBrightness(UIDisplay_Main);
	disp_obj->cstep = 1;

	LoadImages(disp_obj);

	disp_obj->data = ReadConfig();

	if (disp_obj->bright == BRIGHT_MAX)
		disp_obj->active_image = disp_obj->images[LEVEL_UP_ICN].id;
	else if (disp_obj->bright == BRIGHT_MIN)
		disp_obj->active_image = disp_obj->images[LEVEL_DOWN_ICN].id;
	else
		disp_obj->active_image = disp_obj->images[LEVEL_NORMAL_ICN].id;

	return 1;
}

THUMB16
NEWCODE void Bright_onClose(DISP_OBJ_BRIGHT *disp_obj)
{
	UnLoadImages(disp_obj);
	mfree(disp_obj->data);
}

THUMB16
NEWCODE void
DrawStr(TEXTID text, int font, int align, int x1, int y1, int x2, int y2, uint32_t t_color, uint32_t o_color)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
	int font_height = y1 + (font & 0xFF);
	dll_DrawString(font, text, align, x1 + 1, y1, x2, font_height, o_color);
	dll_DrawString(font, text, align, x1, y1 + 1, x2, font_height, o_color);
	dll_DrawString(font, text, align, x1 - 1, y1, x2, font_height, o_color);
	dll_DrawString(font, text, align, x1, y1 - 1, x2, font_height, o_color);
	dll_DrawString(font, text, align, x1, y1, x2, y2, t_color);
#else
	int font_height = GetImageHeight(' ');
	SetFont(font);
	DrawString(text, align, x1 + 1, y1, x2, font_height, 0, 0, o_color, clEmpty);
	DrawString(text, align, x1, y1 + 1, x2, font_height, 0, 0, o_color, clEmpty);
	DrawString(text, align, x1 - 1, y1, x2, font_height, 0, 0, o_color, clEmpty);
	DrawString(text, align, x1, y1 - 1, x2, font_height, 0, 0, o_color, clEmpty);
	DrawString(text, align, x1, y1, x2, y2, 0, 0, t_color, clEmpty);
#endif
}

THUMB16
NEWCODE void Bright_onRedraw(DISP_OBJ_BRIGHT *disp_obj, int, int, int)
{
	GC *gc = get_DisplayGC();
	DrawImage(gc,
	          disp_obj->data->Icon_Background_x,
	          disp_obj->data->Icon_Background_y,
	          0,
	          0,
	          disp_obj->images[BACKGROUND_ICN].id);
	DrawImage(gc, disp_obj->data->Icon_Level_x, disp_obj->data->Icon_Level_y, 0, 0, disp_obj->active_image);

	TEXTID text_id = TextID_CreateIntegerID(disp_obj->bright);
	DrawStr(text_id,
	        disp_obj->data->Percent_Text_Font,
	        disp_obj->data->Percent_Text_Align,
	        disp_obj->data->Percent_Text_x1,
	        disp_obj->data->Percent_Text_y1,
	        disp_obj->data->Percent_Text_x2,
	        disp_obj->data->Percent_Text_y2,
	        disp_obj->data->Percent_Text_Color,
	        disp_obj->data->Percent_Text_Border);
	TextID_Destroy(text_id);

	DrawStr(TEXTID_BRIGHTNESS,
	        disp_obj->data->Title_Text_Font,
	        disp_obj->data->Title_Text_Align,
	        disp_obj->data->Title_Text_x1,
	        disp_obj->data->Title_Text_y1,
	        disp_obj->data->Title_Text_x2,
	        disp_obj->data->Title_Text_y2,
	        disp_obj->data->Title_Text_Color,
	        disp_obj->data->Title_Text_Border);
}

THUMB16
NEWCODE void Bright_OnLayout(DISP_OBJ_BRIGHT *disp_obj)
{
	DispObject_SetLayerColor(&disp_obj->disp, clEmpty);
}

THUMB16
NEWCODE void Bright_onKeyPress(DISP_OBJ_BRIGHT *disp_obj, int key, int unk, int repeat, int mode)
{
	if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
	{
		if (mode == KBD_SHORT_RELEASE)
			disp_obj->cstep = 1;
		else if (mode == KBD_REPEAT && repeat > 5)
			disp_obj->cstep = 4;

		switch (key)
		{
		case KEY_UP:
			if ((disp_obj->bright += disp_obj->cstep) >= BRIGHT_MAX)
			{
				disp_obj->bright = BRIGHT_MAX;
				disp_obj->active_image = disp_obj->images[LEVEL_UP_ICN].id;
			}
			else
				disp_obj->active_image = disp_obj->images[LEVEL_NORMAL_ICN].id;
			break;
		case KEY_DOWN:
			if ((disp_obj->bright -= disp_obj->cstep) <= BRIGHT_MIN)
			{
				disp_obj->bright = BRIGHT_MIN;
				disp_obj->active_image = disp_obj->images[LEVEL_DOWN_ICN].id;
			}
			else
				disp_obj->active_image = disp_obj->images[LEVEL_NORMAL_ICN].id;
			break;
		}

		if (mode == KBD_LONG_RELEASE)
			disp_obj->cstep = 1;

		SetScreenBrightness(disp_obj->bright);
		DispObject_InvalidateRect(&disp_obj->disp, NULL);
	}
}

THUMB16
NEWCODE void Bright_constructor(DISP_DESC *desc)
{
	DISP_DESC_SetName(desc, GUI_BRIGHT_NAME);
	DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_BRIGHT));
	DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Bright_onCreate);
	DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Bright_onClose);
	DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Bright_onRedraw);
	DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)Bright_OnLayout);
	DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Bright_onKeyPress);
}

THUMB16
NEWCODE void Bright_destructor(GUI *gui) {}

THUMB16
NEWCODE void Bright_callBack(DISP_OBJ *, void *msg, GUI *) {}

THUMB16
NEWCODE GUI_BRIGHT *Create_GUIBright(BOOK *book)
{
	GUI_BRIGHT *gui_bright = (GUI_BRIGHT *)malloc(sizeof(GUI_BRIGHT));

	if (!GUIObject_Create(gui_bright,
	                      Bright_destructor,
	                      Bright_constructor,
	                      book,
	                      Bright_callBack,
	                      UIDisplay_Main,
	                      sizeof(GUI_BRIGHT)))
	{
		mfree(gui_bright);
		return NULL;
	}

	if (book)
		BookObj_AddGUIObject(book, gui_bright);

	GUIObject_SetTitleType(gui_bright, UI_TitleMode_None);
	return gui_bright;
}

THUMB16
NEWCODE void Bright_LongClose(BOOK *book, GUI *gui)
{
	SetBook *stb = (SetBook *)book;
	SetScreenBrightness(stb->brightness);
	UI_Event(RETURN_TO_STANDBY_EVENT);
}

THUMB16
NEWCODE void Bright_Close(BOOK *book, GUI *gui)
{
	SetBook *stb = (SetBook *)book;
	SetScreenBrightness(stb->brightness);
	FreeBook(&stb->book);
}

THUMB16
NEWCODE void Bright_Save(BOOK *book, GUI *gui)
{
	SetBook *stb = (SetBook *)book;
	FreeBook(&stb->book);
}

THUMB16
NEWCODE int New_Brightness_ChangeBrightness(void *data, BOOK *book)
{
	SetBook *stb = (SetBook *)book;
	stb->brightness = Display_GetBrightness(UIDisplay_Main);

	if (stb->gui = Create_GUIBright(&stb->book))
	{
		GUIObject_SoftKeys_SetAction(stb->gui, ACTION_LONG_BACK, Bright_LongClose);
		GUIObject_SoftKeys_SetAction(stb->gui, ACTION_BACK, Bright_Close);
		GUIObject_SoftKeys_SetAction(stb->gui, ACTION_SELECT1, Bright_Save);
		GUIObject_SoftKeys_SetText(stb->gui, ACTION_SELECT1, TEXTID_SAVE);
		GUIObject_Show(stb->gui);
	}
	return 1;
}
