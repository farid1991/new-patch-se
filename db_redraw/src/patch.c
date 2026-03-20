#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <sync.h>

#include <book/AudioPlayerBook.h>
#include <classes/IMetaData.h>
#include <types/Colors.h>
#include <types/MusicServer_types.h>

#include "patch.h"

// clang-format off

const PAGE_MSG bk_msglst_base[] = 
{
	CANCEL_EVENT, NULL, 
	NIL_EVENT, NULL
};

const PAGE_MSG bk_msglst_main[] = 
{
	PAGE_ENTER_EVENT, pg_DBRedraw_onEnter,
	UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT, pg_DBRedraw_onPlaying,
	NIL_EVENT, NULL
};

const PAGE_DESC bk_base = {BASEPAGE_NAME, NULL, bk_msglst_base};
const PAGE_DESC bk_main = {MAINPAGE_NAME, NULL, bk_msglst_main};

// clang-format on

THUMB16
NEWCODE void *malloc(int size)
{
#ifdef DB2020
	return (memalloc(0, size, 1, 5, MEM_NAME, 0));
#else
	return (memalloc(size, 1, 5, MEM_NAME, 0));
#endif
}

THUMB16
NEWCODE void mfree(void *mem)
{
	if (mem)
#ifdef DB2020
		memfree(0, mem, MEM_NAME, 0);
#else
		memfree(mem, MEM_NAME, 0);
#endif
}

THUMB16
NEWCODE void image_register(IMAGE_DESC *img_desc, const wchar_t *fpath, const wchar_t *fname)
{
	char err;
	img_desc->id = NOIMAGE;
	img_desc->handle = NOIMAGE;

	if (REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(&SYNC, &img_desc->handle, &err))
		return;

	REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(&SYNC, img_desc->handle, fpath, fname, 0, &img_desc->id, &err);
}

THUMB16
NEWCODE void image_unregister(IMAGE_DESC *img_desc)
{
	if (img_desc->id == NOIMAGE)
		return;

	char err;
	REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(&SYNC, img_desc->handle, NULL, NULL, img_desc->id, 1, &err);
	img_desc->id = NOIMAGE;
	img_desc->handle = NOIMAGE;
}

THUMB16
NEWCODE const wchar_t *Image_GetName(int index)
{
	return images_names[index];
}

THUMB16
NEWCODE void UnInit_Images(DISP_OBJ_DBP *disp)
{
	for (int i = 0; i < LAST_ICN; i++)
	{
		image_unregister(&disp->skin_images[i]);
	}
}

THUMB16
NEWCODE void Init_Images(DISP_OBJ_DBP *disp)
{
	for (int i = 0; i < LAST_ICN; i++)
	{
		if (FSX_IsFileExists(CFG_PATH, Image_GetName(i)))
			image_register(&disp->skin_images[i], CFG_PATH, Image_GetName(i));
		else
		{
			disp->skin_images[i].handle = NOIMAGE;
			disp->skin_images[i].id = NOIMAGE;
		}
	}
}

THUMB16
NEWCODE void Init_VizImages(DBRedrawBook *dbp)
{
	if (dbp->fs->viz_count >= MAX_VIZ)
		dbp->fs->viz_count = MAX_VIZ;

	for (int i = 0; i < dbp->fs->viz_count; i++)
	{
		wchar_t viz_name[32];
		snwprintf(viz_name, MAXELEMS(viz_name), VIZ_FMT, i);
		if (FSX_IsFileExists(CFG_PATH, viz_name))
			image_register(&dbp->viz_image[i], CFG_PATH, viz_name);
		else
		{
			dbp->viz_image[i].handle = NOIMAGE;
			dbp->viz_image[i].id = NOIMAGE;
		}
	}
}

THUMB16
NEWCODE void UnInit_VizImages(DBRedrawBook *dbp)
{
	if (dbp->fs->viz_count >= MAX_VIZ)
		dbp->fs->viz_count = MAX_VIZ;

	for (int i = 0; i < dbp->fs->viz_count; i++)
	{
		image_unregister(&dbp->viz_image[i]);
	}
}

THUMB16
NEWCODE void DrawImage(GC *gc, int x, int y, int w, int h, IMAGEID img)
{
	if (img != NOIMAGE)
		GC_PutChar(gc, x, y, w, h, img);
}

THUMB16
NEWCODE void DrawProgressBar(int x1,
                             int y1,
                             int x2,
                             int y2,
                             int background_color,
                             int elapsed_time_color,
                             int border_color,
                             int elapsed_time,
                             int full_time)
{
	DrawRect(x1 + 1, y1, x2 - 1, y2, clEmpty, border_color);
	DrawRect(x1, y1 + 1, x2, y2 - 1, clEmpty, border_color);
	DrawRect(x1 + 1, y1 + 1, x2 - 1, y2 - 1, background_color, background_color);
	int width = x2 - x1;
	int start_pos = x1;
	int length = start_pos + (elapsed_time * width / full_time);
	DrawRect(x1 + 1, y1 + 1, (int)length - 1, y2 - 1, elapsed_time_color, elapsed_time_color);
}

THUMB16
NEWCODE void
DrawStr(TEXTID text_id, int font_size, int align, int x1, int x2, int y1, int y2, int TextColor, int BorderColor)
{
	SetFont(font_size);
	DrawString(text_id, align, x1 - 1, y1 - 1, x2 - 1, y2, 60, 0x05, BorderColor, clEmpty);
	DrawString(text_id, align, x1 - 1, y1 + 1, x2 - 1, y2, 60, 0x05, BorderColor, clEmpty);
	DrawString(text_id, align, x1 + 1, y1 - 1, x2 + 1, y2, 60, 0x05, BorderColor, clEmpty);
	DrawString(text_id, align, x1 + 1, y1 + 1, x2 + 1, y2, 60, 0x05, BorderColor, clEmpty);
	DrawString(text_id, align, x1, y1, x2, y2, 60, 0x05, TextColor, clEmpty);
}

THUMB16
NEWCODE void *DBRedraw_Init_Metadata(DBRedrawBook *dbp)
{
	AudioPlayerBook *audiobook = (AudioPlayerBook *)dbp->audiobook;
	if (!audiobook->dsc)
		return NULL;

	wchar_t *fpath = audiobook->dsc->fpath;
	wchar_t *fname = audiobook->dsc->fname;

	void *metadata = MetaData_Desc_Create(fpath, fname);
	if (!metadata)
		return NULL;

	dbp->title = MetaData_Desc_GetTags(metadata, TMetadataTagId_Title);
	if (!wstrlen(dbp->title))
		dbp->title = fname;
	dbp->album = MetaData_Desc_GetTags(metadata, TMetadataTagId_Album);
	dbp->artist = MetaData_Desc_GetTags(metadata, TMetadataTagId_Artist);
	dbp->full_time = audiobook->dsc->full_time;

	wchar_t *wsext = getFileExtension(fname);
	if (!wstrcmpi(wsext, FILETYPE_mp3))
		dbp->has_cover = id3v2_get_coverart(fpath, fname, &dbp->cover);

	return metadata;
}

THUMB16
NEWCODE int DBRedraw_onCreate(DISP_OBJ *disp_obj)
{
	DISP_OBJ_DBP *disp = (DISP_OBJ_DBP *)disp_obj;

	Init_Images(disp);

	DispObject_SetRefreshTimer(disp_obj, 80);
	return 1;
}

THUMB16
NEWCODE void DBRedraw_onClose(DISP_OBJ *disp_obj)
{
	DISP_OBJ_DBP *disp = (DISP_OBJ_DBP *)disp_obj;

	UnInit_Images(disp);

	DispObject_KillRefreshTimer(disp_obj);
}

THUMB16
NEWCODE void DBRedraw_onRefresh(DISP_OBJ *disp_obj)
{
	DISP_OBJ_DBP *disp = (DISP_OBJ_DBP *)disp_obj;

	disp->viz_index++;
	if (disp->viz_index >= disp->viz_count)
		disp->viz_index = 0;

	DispObject_InvalidateRect(disp_obj, NULL);
	DispObject_SetRefreshTimer(disp_obj, 60);
}

THUMB16
NEWCODE void DBRedraw_onLayout(DISP_OBJ *disp_obj, void *layoutstruct)
{
	DispObject_SetLayerColor(disp_obj, clTransGray);
}

THUMB16
NEWCODE void DBRedraw_onRedraw(DISP_OBJ *disp_obj, int, int, int)
{
	DISP_OBJ_DBP *disp = (DISP_OBJ_DBP *)disp_obj;
	GUI *player = DispObject_GetGUI(disp_obj);
	DBRedrawBook *dbp = (DBRedrawBook *)GUIObject_GetBook(player);
	FILE_STYLE *fs = dbp->fs;

	disp->viz_count = fs->viz_count;

	TEXTID text_id;

	GC *gc = get_DisplayGC();

	if (fs->background_state)
		DrawImage(gc, fs->background_x, fs->background_y, 0, 0, disp->skin_images[BACKGROUND_ICN].id);

	if (fs->viz_count)
		DrawImage(gc, fs->viz_x, fs->viz_y, fs->viz_w, fs->viz_h, dbp->viz_image[disp->viz_index].id);

	if (fs->title_icon_state)
		DrawImage(gc, fs->title_icon_x, fs->title_icon_y, 0, 0, disp->skin_images[TITLE_ICN].id);

	if (fs->artist_icon_state)
		DrawImage(gc, fs->artist_icon_x, fs->artist_icon_y, 0, 0, disp->skin_images[ARTIST_ICN].id);

	if (fs->album_icon_state)
		DrawImage(gc, fs->album_icon_x, fs->album_icon_y, 0, 0, disp->skin_images[ALBUM_ICN].id);

	if (fs->cover_state)
	{
		DrawImage(gc, fs->cover_x, fs->cover_y, fs->cover_w, fs->cover_h, disp->skin_images[NOCOVER_ICN].id);
		if (dbp->has_cover)
			DrawImage(gc, fs->cover_x, fs->cover_y, fs->cover_w, fs->cover_h, dbp->cover);
	}

	if (fs->title_state)
	{
		text_id = TextID_Create(dbp->title, ENC_UCS2, wstrlen(dbp->title));
		DrawStr(text_id,
		        fs->title_font,
		        fs->title_align,
		        fs->title_x1,
		        fs->title_x2,
		        fs->title_y1,
		        fs->title_y2,
		        fs->title_color,
		        fs->title_border_color);
		TextID_Destroy(text_id);
	}

	if (fs->artist_state)
	{
		text_id = TextID_Create(dbp->artist, ENC_UCS2, wstrlen(dbp->artist));
		DrawStr(text_id,
		        fs->artist_font,
		        fs->artist_align,
		        fs->artist_x1,
		        fs->artist_x2,
		        fs->artist_y1,
		        fs->artist_y2,
		        fs->artist_color,
		        fs->artist_border_color);
		TextID_Destroy(text_id);
	}

	if (fs->album_state)
	{
		text_id = TextID_Create(dbp->album, ENC_UCS2, wstrlen(dbp->album));
		DrawStr(text_id,
		        fs->album_font,
		        fs->album_align,
		        fs->album_x1,
		        fs->album_x2,
		        fs->album_y1,
		        fs->album_y2,
		        fs->album_color,
		        fs->album_border_color);
		TextID_Destroy(text_id);
	}

	if (fs->full_time_state)
	{
		char time_buffer[16];
		int text_len = strftime(dbp->full_time, dbp->elapsed_time, 0, 0, time_buffer, 1);
		text_id = TextID_CreateFromTextIterator(time_buffer, ENC_LAT1, text_len);
		DrawStr(text_id,
		        fs->full_time_font,
		        fs->full_time_align,
		        fs->full_time_x1,
		        fs->full_time_x2,
		        fs->full_time_y1,
		        fs->full_time_y2,
		        fs->full_time_color,
		        fs->full_time_border_color);
		TextID_Destroy(text_id);
	}

	if (fs->elapsed_time_state)
	{
		char time_buffer[16];
		int text_len = strftime(dbp->elapsed_time, dbp->full_time, 0, 0, time_buffer, 1);
		text_id = TextID_CreateFromTextIterator(time_buffer, ENC_LAT1, text_len);
		DrawStr(text_id,
		        fs->elapsed_time_font,
		        fs->elapsed_time_align,
		        fs->elapsed_time_x1,
		        fs->elapsed_time_x2,
		        fs->elapsed_time_y1,
		        fs->elapsed_time_y2,
		        fs->elapsed_time_color,
		        fs->elapsed_time_border_color);
		TextID_Destroy(text_id);
	}
	if (fs->remaining_time_state)
	{
		char time_buffer[16];
		int text_len = strftime(dbp->elapsed_time, dbp->full_time, 0, 1, time_buffer, 1);
		text_id = TextID_CreateFromTextIterator(time_buffer, ENC_LAT1, text_len);
		DrawStr(text_id,
		        fs->remaining_time_font,
		        fs->remaining_time_align,
		        fs->remaining_time_x1,
		        fs->remaining_time_x2,
		        fs->remaining_time_y1,
		        fs->remaining_time_y2,
		        fs->remaining_time_color,
		        fs->remaining_time_border_color);
		TextID_Destroy(text_id);
	}

	if (fs->progbar_state)
		DrawProgressBar(fs->progbar_x1,
		                fs->progbar_y1,
		                fs->progbar_x2,
		                fs->progbar_y2,
		                fs->progbar_background_color,
		                fs->progbar_current_color,
		                fs->progbar_border_color,
		                dbp->elapsed_time,
		                dbp->full_time);
}

THUMB16
NEWCODE void DBRedraw_Constructor(DISP_DESC *desc)
{
	DISP_DESC_SetName(desc, GUI_NAME);
	DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_DBP));
	DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)DBRedraw_onCreate);
	DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)DBRedraw_onClose);
	DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)DBRedraw_onRedraw);
	DISP_DESC_SetOnRefresh(desc, (DISP_OBJ_METHOD)DBRedraw_onRefresh);
	DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)DBRedraw_onLayout);
}

THUMB16
NEWCODE void DBRedraw_Destructor(GUI *gui) {}

THUMB16
NEWCODE void DBRedraw_CallBack(DISP_OBJ *disp, void *msg, GUI *gui) {}

THUMB16
NEWCODE GUI_DBP *Create_DBRedraw(BOOK *book)
{
	GUI_DBP *player = (GUI_DBP *)malloc(sizeof(GUI_DBP));

	if (!GUIObject_Create(player,
	                      DBRedraw_Destructor,
	                      DBRedraw_Constructor,
	                      book,
	                      DBRedraw_CallBack,
	                      UIDisplay_Main,
	                      sizeof(GUI_DBP)))
	{
		mfree(player);
		return NULL;
	}

	if (book)
		BookObj_AddGUIObject(book, player);

	GUIObject_SetTitleType(player, UI_TitleMode_None);

	return player;
}

THUMB16
NEWCODE int pg_DBRedraw_onEnter(void *msg, BOOK *book)
{
	DBRedrawBook *dbp = (DBRedrawBook *)book;

	dbp->player = Create_DBRedraw(&dbp->book);
	GUIObject_SetStyle(dbp->player, dbp->fs->gui_style);

	if (dbp->fs->hide_softkeys)
		GUIObject_SoftKeys_Hide(dbp->player);

	GUIObject_Show(dbp->player);

	return 1;
}

THUMB16
NEWCODE int pg_DBRedraw_onPlaying(void *msg, BOOK *book)
{
	DBRedrawBook *dbp = (DBRedrawBook *)book;
	AudioPlayerBook *audiobook = (AudioPlayerBook *)dbp->audiobook;
	if (audiobook)
		dbp->elapsed_time = audiobook->elapsed_time;

	return 1;
}

THUMB16
NEWCODE void DBPlayerBook_onClose(BOOK *book)
{
	DBRedrawBook *dbp = (DBRedrawBook *)book;

	MetaData_Desc_Destroy(dbp->metadata);

	ImageID_Free(dbp->cover);
	UnInit_VizImages(dbp);

	mfree(dbp->fs);

	FREE_GUI(dbp->player);
}

THUMB16
NEWCODE int IsDBRedrawBook(BOOK *book)
{
	return book->onClose == DBPlayerBook_onClose ? TRUE : FALSE;
}

THUMB16
NEWCODE DBRedrawBook *Create_DBRedrawBook()
{
	DBRedrawBook *dbp = (DBRedrawBook *)malloc(sizeof(DBRedrawBook));
	if (!dbp)
		return NULL;

	memset(dbp, 0, sizeof(DBRedrawBook));

	if (CreateBook(&dbp->book, DBPlayerBook_onClose, &bk_base, BOOK_NAME, NO_BOOK_ID, NULL))
	{
		dbp->cover = NOIMAGE;
		return dbp;
	}

	mfree(dbp);
	return NULL;
}

THUMB16
NEWCODE void DB_Set_SK_Visibility(int mode)
{
	DataBrowserBook *brw = (DataBrowserBook *)FindBook((IS_NEEDED_BOOK)IsDataBrowserBook);
	if (brw)
		GUIObject_SoftKeys_SetVisible(brw->gui, 0xFA, mode);
}

THUMB16
NEWCODE int New_MediaPlayer_SingleFile_Exit(void *msg, BOOK *audiobook)
{
	DB_Set_SK_Visibility(FALSE);

	FreeBook(FindBook(IsDBRedrawBook));

	pg_MediaPlayer_SingleFile_Exit(msg, audiobook);

	UI_Event(DB_UPDATE_EVENT);

	return 1;
}

THUMB16
NEWCODE int New_MediaPlayer_SingleFile_Enter(void *msg, BOOK *audiobook)
{
	DB_Set_SK_Visibility(TRUE);

	DBRedrawBook *dbp = Create_DBRedrawBook();
	if (dbp)
	{
		dbp->audiobook = audiobook;
		dbp->metadata = DBRedraw_Init_Metadata(dbp);
		dbp->fs = DBRedraw_Load_CfgData(CFG_PATH);

		Init_VizImages(dbp);

		BookObj_GotoPage(&dbp->book, &bk_main);
	}

	int result = pg_MediaPlayer_SingleFile_Enter(msg, audiobook);
	Session_SetFocus(audiobook->xbook->app_session, 0);

	return result;
}

THUMB16
NEWCODE void *New_BookObj_SetFocus(BOOK *book, int focus)
{
	if (!book)
		return NULL;

	BOOK *audiobook = FindBook(IsAudioPlayerBook);
	BOOK *dbp = FindBook(IsDBRedrawBook);

	if ((book == dbp) && audiobook)
	{
		BookObj_Show(dbp, UIDisplay_Main);
		void *result = Session_SetFocus(dbp->xbook->app_session, focus);
		BookObj_Show(audiobook, UIDisplay_Main);
		Session_SetFocus(audiobook->xbook->app_session, focus);
		return result;
	}
	else if ((book == audiobook) && dbp)
	{
		BookObj_Show(dbp, UIDisplay_Main);
		Session_SetFocus(dbp->xbook->app_session, focus);
		BookObj_Show(audiobook, UIDisplay_Main);
		return Session_SetFocus(audiobook->xbook->app_session, focus);
	}

	return Session_SetFocus(book->xbook->app_session, focus);
}

THUMB16
NEWCODE void New_Mediaplayer_SoftKeys(BOOK *book, GUI *gui)
{
	DBRedrawBook *dbp = (DBRedrawBook *)FindBook(IsDBRedrawBook);
	if (dbp)
	{
		BookObj_Hide(&dbp->book, UIDisplay_Main);
		BookObj_Hide(dbp->audiobook, UIDisplay_Main);
		UI_Event(DB_UPDATE_EVENT);
	}
}

THUMB16
NEWCODE void New_DataBrowser_SoftKeys(BOOK *book, GUI *gui)
{
	DBRedrawBook *dbp = (DBRedrawBook *)FindBook(IsDBRedrawBook);
	if (dbp)
	{
		BookObj_Show(&dbp->book, UIDisplay_Main);
		BookObj_Show(dbp->audiobook, UIDisplay_Main);
		New_BookObj_SetFocus(dbp->audiobook, 0);
		UI_Event(DB_UPDATE_EVENT);
	}
}
