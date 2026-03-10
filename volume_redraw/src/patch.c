#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(K600_R2BB001)
#include <K600_R2BB001.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <sync.h>

#include <book/VolumeControlBook.h>

#include <types/Colors.h>
#include <types/UIRichText_types.h>

#if defined(DB3200) || defined(DB3210)
#include "dll.h"
#endif
#include "patch.h"

extern int is_ongoingcallbook(BOOK *book);

THUMB16
NEWCODE static inline void *malloc(int size)
{
#if defined(DB2020)
	return (memalloc(0, size, 1, 5, V_MEM, 0));
#elif defined(A2)
	return (memalloc(-1, size, 1, 5, V_MEM, 0));
#else
	return (memalloc(size, 1, 5, V_MEM, 0));
#endif
}

THUMB16
NEWCODE static inline void mfree(void *mem)
{
	if (mem)
#if defined(DB2020) || defined(A2)
		memfree(0, mem, V_MEM, 0);
#else
		memfree(mem, V_MEM, 0);
#endif
}

THUMB16
NEWCODE vdata_t *Get_VDATA()
{
	vdata_t *data = (vdata_t *)get_envp(NULL, V_EMP);
	if (!data)
	{
		data = (vdata_t *)malloc(sizeof(vdata_t));
		memset(data, 0, sizeof(vdata_t));
		set_envp(NULL, V_EMP, (OSADDRESS)data);
	}
	return data;
}

THUMB16
NEWCODE void Free_VDATA(vdata_t *data)
{
	set_envp(NULL, V_EMP, 0);
	mfree(data);
}

#if defined(DB2000) || defined(DB2010)
#define MainDisplay_GetTopBook() Display_GetTopBook(UIDisplay_Main)

#if defined(DB2000)
int FSX_IsFileExists(const wchar_t *path, const wchar_t *name)
{
	FSTAT fs;
	return !fstat(path, name, &fs);
}
#endif
#endif

THUMB16
NEWCODE BOOL is_java_running(BOOK *book)
{
	char str[100];
	TextID_GetString(BookObj_GetSession(book)->name, str, MAXELEMS(str));

	if (!strncmp(str, FOREIGN_APP_STR, 11))
		return TRUE;

	if (!strncmp(str, JAVA_STR, 4))
		return TRUE;

	return FALSE;
}

THUMB16
NEWCODE int GetVolumeLevel(int type, int level)
{
	return type ? TABLE_VOL_MEDIA[level] : TABLE_VOL_CALL[level];
}

THUMB16
NEWCODE wchar_t *GetCurrentSkinPath(wchar_t *out)
{
	wstrcpy(out, DIR_OTHER_PATH);

	int file = _fopen(DEFAULT_CFG_PATH, VOL_CFG, FSX_O_RDONLY, FSX_S_IREAD, NULL);

	if (file != -1)
	{
		int fsize = MAX_PATH_LEN * sizeof(wchar_t);
		if (fread(file, out, fsize) != fsize)
		{
			if (!out[0])
				wstrcpy(out, DIR_OTHER_PATH);
		}
		fclose(file);
	}

	return out;
}

THUMB16
NEWCODE int GetConfig(const wchar_t *skin_path, skin_config_t *sc)
{
	memset(sc, 0, sizeof(skin_config_t));

	int file = _fopen(skin_path, SKIN_VSF, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file != -1)
	{
		int r = fread(file, sc, sizeof(skin_config_t));
		fclose(file);

		if (r == sizeof(skin_config_t))
			return 1;
	}

	return 0;
}

THUMB16
NEWCODE void RegisterImage(image_t *img, const wchar_t *path, const wchar_t *fname)
{
	char err;
	img->id = NOIMAGE;
	img->handle = NOIMAGE;

	if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(&SYNC, &img->handle, &err))
		if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(&SYNC, img->handle, path, fname, 0, &img->id, &err))
			if (err)
				img->handle = NOIMAGE;
}

THUMB16
NEWCODE void UnRegisterImage(vdata_t *data)
{
	char err;
	for (int i = 0; i < LAST_IMG; i++)
	{
		if (data->volume_img[i].handle != NOIMAGE)
			REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(
			        &SYNC, data->volume_img[i].handle, NULL, NULL, data->volume_img[i].id, 1, &err);
	}
}

THUMB16
NEWCODE void InitImage(vdata_t *data)
{
	for (int i = 0; i < LAST_IMG; i++)
	{
		if (FSX_IsFileExists(data->cfg_path, VOLUME_IMGS[i]))
			RegisterImage(&data->volume_img[i], data->cfg_path, VOLUME_IMGS[i]);
		else
			data->volume_img[i].id = NOIMAGE;
	}
}

THUMB16
NEWCODE void DrawImage(GC *gc_ctx, int x, int y, IMAGEID img)
{
	if (img != NOIMAGE)
#if defined(DB3200) || defined(DB3210)
		dll_GC_PutChar(gc_ctx, x, y, 0, 0, img);
#else
		GC_PutChar(gc_ctx, x, y, 0, 0, img);
#endif
}

THUMB16
NEWCODE void DrawProgressBar(GC *gc_ctx,
                             IMAGEID blob_id,
                             int value,
                             int max_value,
                             RECT rect,
                             uint32_t bg_color,
                             uint32_t elapsed_color,
                             bool enable_blob)
{
	int wid = rect.x2 - rect.x1;
	int nx2 = rect.x1 + (value * wid / max_value);

	DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, bg_color, bg_color);
	DrawRect(rect.x1, rect.y1, nx2, rect.y2, elapsed_color, elapsed_color);

#if defined(DB3200) || defined(DB3210)
	int blob_h = dll_GetImageHeight(blob_id) / 2;
	int blob_w = dll_GetImageWidth(blob_id) / 2;
#else
	int blob_h = GetImageHeight(blob_id) / 2;
	int blob_w = GetImageWidth(blob_id) / 2;
#endif
	if (enable_blob)
	{
		int blob_x = nx2 - blob_w;
		int blob_y = (rect.y1 - blob_h) + ((rect.y2 - rect.y1) / 2);
		DrawImage(gc_ctx, blob_x, blob_y, blob_id);
	}
}

THUMB16
NEWCODE void DrawText(int font, TEXTID text, int align, int xpos, int ypos, int width, uint32_t color)
{
	if (text != EMPTY_TEXTID)
	{
#if defined(DB3200) || defined(DB3210)
		dll_DrawString(font, text, align, xpos, ypos, xpos + width, ypos + (font & 0xFF), color);
#else
		SetFont(font);
		DrawString(text, align, xpos, ypos, xpos + width, ypos + (font & 0xFF), 0, 1, color, clEmpty);
#endif
	}
}

THUMB16
NEWCODE int New_Volume_OnCreate(DISP_OBJ *disp_obj)
{
	vdata_t *data = Get_VDATA();

	GetCurrentSkinPath(data->cfg_path);
	GetConfig(data->cfg_path, &data->sk_config);

	InitImage(data);

	return VolumeControl_OnCreate(disp_obj);
}

THUMB16
NEWCODE void New_Volume_OnClose(DISP_OBJ *disp_obj)
{
	vdata_t *data = Get_VDATA();

	UnRegisterImage(data);

	Free_VDATA(data);

	VolumeControl_OnClose(disp_obj);
}

THUMB16
NEWCODE void New_Volume_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
#ifdef HAS_SECOND_DISPLAY
	if (IsMainDisplayFocused())
	{
#endif
		vdata_t *data = Get_VDATA();
		if (!data->is_java)
		{
			GUI *vc_gui = DispObject_GetGUI(disp_obj);
			VolumeControlBook *vc_book = (VolumeControlBook *)GUIObject_GetBook(vc_gui);

			int Vol_Level = vc_book->level;
			int Max_Volume;
			int Volume_Type;

			GC *gc_ctx = get_DisplayGC();

			DrawImage(gc_ctx,
			          data->sk_config.bg_image.x,
			          data->sk_config.bg_image.y,
			          data->volume_img[BACKGROUND_IMG].id);

			if (Vol_Level)
			{
				if (FindBook(is_ongoingcallbook) || FindBook(is_mocallbook))
				{
					Volume_Type = 0;
					Max_Volume = 8;
					DrawImage(gc_ctx,
					          data->sk_config.state_image.x,
					          data->sk_config.state_image.y,
					          data->volume_img[CALL_IMG].id);
				}
				else
				{
					Volume_Type = 1;
					Max_Volume = 15;
					DrawImage(gc_ctx,
					          data->sk_config.state_image.x,
					          data->sk_config.state_image.y,
					          data->volume_img[MUSIC_IMG].id);
				}
			}
			else
			{
				DrawImage(gc_ctx,
				          data->sk_config.state_image.x,
				          data->sk_config.state_image.y,
				          data->volume_img[OFF_IMG].id);
			}

			if (data->sk_config.text_enable)
			{
				TEXTID vol_textid;
				TEXTID vText_id[2];
				int vLevel = GetVolumeLevel(Volume_Type, Vol_Level);
				vText_id[0] = TextID_CreateIntegerID(vLevel);
				vText_id[1] = TextID_Create(FMT_PERCENT, ENC_LAT1, 2);

				if (data->sk_config.percentage_enable)
					vol_textid = TextID_Create(vText_id, ENC_TEXTID, 2);
				else
					vol_textid = TextID_Copy(vText_id[0]);

				DrawText(data->sk_config.font_size,
				         vol_textid,
				         AlignLeft,
				         data->sk_config.text_pos.x,
				         data->sk_config.text_pos.y,
				         Display_GetWidth(UIDisplay_Main),
				         data->sk_config.text_color);

				TextID_Destroy(vol_textid);
			}

			DrawProgressBar(gc_ctx,
			                data->volume_img[BLOB_IMG].id,
			                Vol_Level,
			                Max_Volume,
			                data->sk_config.progressbar,
			                data->sk_config.progressbar_bg_color,
			                data->sk_config.progressbar_elapsed_color,
			                data->sk_config.blob_enable);
		}
#ifdef HAS_SECOND_DISPLAY
	}
	else
	{
		VolumeControl_OnRedraw(disp_obj, a, b, c);
	}
#endif
}

THUMB16
NEWCODE int New_Volume_OnEnter(void *r0, BOOK *book)
{
	if (pg_VolumeControl_Active_EnterEvent(r0, book) == 0)
		return 1;

#ifdef HAS_SECOND_DISPLAY
	if (!IsMainDisplayFocused())
		return 1;
#endif

	vdata_t *data = Get_VDATA();
	data->is_java = is_java_running(MainDisplay_GetTopBook());

	VolumeControlBook *vc_book = (VolumeControlBook *)book;
	DISP_OBJ *disp_obj = (DISP_OBJ *)GUIObject_GetDispObject(vc_book->gui);
	DispObject_WindowSetSize(disp_obj, Display_GetWidth(UIDisplay_Main), Display_GetHeight(UIDisplay_Main));
	DispObject_SetLayerColor(disp_obj, clEmpty);

	if (data->is_java)
		return 1;

	DispObject_SetAnimation(disp_obj, data->sk_config.anim_style);

	return 1;
}
