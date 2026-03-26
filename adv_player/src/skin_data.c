#include "device.h"

#include <libse.h>
#include <ini_parser.h>

#include "data.h"
#include "draw.h"
#include "patch.h"
#include "track_desc.h"
#include "skin_data.h"
#include "timer.h"

THUMB16
NEWCODE const wchar_t *skin_images_getname(int index)
{
	return skin_icon_names[index];
}

THUMB16
NEWCODE void skin_images_unload()
{
	ADVPLAYER_DATA *data = env_data_get();

	for (int i = 0; i < MP_LAST_ICN; i++)
	{
		image_unregister(&data->skin_images[i]);
	}
	data->image_loaded = FALSE;
}

THUMB16
NEWCODE void skin_images_load(wchar_t *skin_path)
{
	ADVPLAYER_DATA *data = env_data_get();

	for (int i = 0; i < MP_LAST_ICN; i++)
	{
		if (_FSX_IsFileExists(skin_path, skin_images_getname(i)))
			image_register(&data->skin_images[i], skin_path, skin_images_getname(i));
		else
		{
			data->skin_images[i].handle = NOIMAGE;
			data->skin_images[i].id = NOIMAGE;
			data->skin_images[i].exist = FALSE;
		}
	}
	data->image_loaded = TRUE;
}

THUMB16
NEWCODE void skin_data_path_save(const wchar_t *skin_path)
{
	int file = _fopen(SKIN_CFG_PATH, SKIN_CFG_NAME, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
	if (file != -1)
	{
		fwrite(file, skin_path, (wstrlen(skin_path) + 1) * sizeof(wchar_t));
		fclose(file);
	}
}

THUMB16
NEWCODE SKIN_CONFIG *skin_data_config_get(const wchar_t *cfg_path, const wchar_t *cfg_name)
{
	SKIN_CONFIG *skin_cfg = malloc(sizeof(SKIN_CONFIG));
	if (!skin_cfg)
		return NULL;

	memset(skin_cfg, 0, sizeof(SKIN_CONFIG));

	FSTAT fs;
	if (fstat(cfg_path, cfg_name, &fs) != 0 || fs.fsize <= 0 || fs.fsize > sizeof(skin_cfg->path))
		goto exit_default;

	int file = _fopen(cfg_path, cfg_name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file != -1)
	{
		fread(file, skin_cfg->path, fs.fsize);
		fclose(file);
		return skin_cfg;
	}

exit_default:
	wstrcpy(skin_cfg->path, DEFAULT_SKIN_PATH);
	return skin_cfg;
}

THUMB16
NEWCODE SKIN_DATA *skin_data_read(wchar_t *skin_path)
{
	SKIN_DATA *skin_data = (SKIN_DATA *)malloc(sizeof(SKIN_DATA));
	memset(skin_data, 0, sizeof(SKIN_DATA));

	FSTAT fs;
	if (fstat(skin_path, SKIN_NAME, &fs) != 0)
		return skin_data;

	int fsize = fs.fsize;
	int file = _fopen(skin_path, SKIN_NAME, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file == -1)
		return skin_data;

	char *buf = (char *)malloc(fsize + 1);
	if (!buf)
		return skin_data;

	memset(buf, 0, fsize + 1);
	if (fread(file, buf, fsize) != fsize)
	{
		fclose(file);
		mfree(buf);
		return skin_data;
	}
	fclose(file);

	char *param;
	if (param = manifest_GetParam(buf, KEY_BACKGROUND, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->bg_enable = values[0];
		skin_data->bg_x = values[1];
		skin_data->bg_y = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_OVERLAY, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->overlay_enable = values[0];
		skin_data->overlay_x = values[1];
		skin_data->overlay_y = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ARTIST_TEXT, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_artist_enable = values[0];
		skin_data->text_artist_font = values[1];
		skin_data->text_artist_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ARTIST_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_artist_x = values[0];
		skin_data->text_artist_y = values[1];
		skin_data->text_artist_w = values[2];
		skin_data->text_artist_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ARTIST_COLOR, 0))
	{
		skin_data->text_artist_color = ini_parse_value(param);
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ARTIST_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_artist_enable = values[0];
		skin_data->icon_artist_x = values[1];
		skin_data->icon_artist_y = values[2];
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_TITLE_TEXT, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_title_enable = values[0];
		skin_data->text_title_font = values[1];
		skin_data->text_title_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_TITLE_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_title_x = values[0];
		skin_data->text_title_y = values[1];
		skin_data->text_title_w = values[2];
		skin_data->text_title_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_TITLE_COLOR, 0))
	{
		skin_data->text_title_color = ini_parse_value(param);
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_TITLE_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_title_enable = values[0];
		skin_data->icon_title_x = values[1];
		skin_data->icon_title_y = values[2];
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_ALBUM_TEXT, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_album_enable = values[0];
		skin_data->text_album_font = values[1];
		skin_data->text_album_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ALBUM_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_album_x = values[0];
		skin_data->text_album_y = values[1];
		skin_data->text_album_w = values[2];
		skin_data->text_album_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ALBUM_COLOR, 0))
	{
		skin_data->text_album_color = ini_parse_value(param);
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ALBUM_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_album_enable = values[0];
		skin_data->icon_album_x = values[1];
		skin_data->icon_album_y = values[2];
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_TRACKID, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_trackid_enable = values[0];
		skin_data->text_trackid_font = values[1];
		skin_data->text_trackid_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_TRACKID_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_trackid_x = values[0];
		skin_data->text_trackid_y = values[1];
		skin_data->text_trackid_w = values[2];
		skin_data->text_trackid_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_TRACKID_COLOR, 0))
	{
		skin_data->text_trackid_color = ini_parse_value(param);
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_FULLTIME, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_fulltime_enable = values[0];
		skin_data->text_fulltime_font = values[1];
		skin_data->text_fulltime_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_FULLTIME_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_fulltime_x = values[0];
		skin_data->text_fulltime_y = values[1];
		skin_data->text_fulltime_w = values[2];
		skin_data->text_fulltime_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_FULLTIME_COLOR, 0))
	{
		skin_data->text_fulltime_color = ini_parse_value(param);
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_ELAPSED, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_elapsedtime_enable = values[0];
		skin_data->text_elapsedtime_font = values[1];
		skin_data->text_elapsedtime_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ELAPSED_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_elapsedtime_x = values[0];
		skin_data->text_elapsedtime_y = values[1];
		skin_data->text_elapsedtime_w = values[2];
		skin_data->text_elapsedtime_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_ELAPSED_COLOR, 0))
	{
		skin_data->text_elapsedtime_color = ini_parse_value(param);
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_REMAINING, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_remainingtime_enable = values[0];
		skin_data->text_remainingtime_font = values[1];
		skin_data->text_remainingtime_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_REMAINING_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_remainingtime_x = values[0];
		skin_data->text_remainingtime_y = values[1];
		skin_data->text_remainingtime_w = values[2];
		skin_data->text_remainingtime_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_REMAINING_COLOR, 0))
	{
		skin_data->text_remainingtime_color = ini_parse_value(param);
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_SAMPLERATE, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->text_samplerate_enable = values[0];
		skin_data->text_samplerate_font = values[1];
		skin_data->text_samplerate_align = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_SAMPLERATE_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->text_samplerate_x = values[0];
		skin_data->text_samplerate_y = values[1];
		skin_data->text_samplerate_w = values[2];
		skin_data->text_samplerate_h = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_SAMPLERATE_COLOR, 0))
	{
		skin_data->text_samplerate_color = ini_parse_value(param);
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_COVERART, 0))
	{
		skin_data->coverart_enable = ini_parse_value(param);
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_COVER_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->coverart_x = values[0];
		skin_data->coverart_y = values[1];
		skin_data->coverart_w = values[2];
		skin_data->coverart_h = values[3];
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_PLAYERSTATE, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_playerstate_enable = values[0];
		skin_data->icon_playerstate_x = values[1];
		skin_data->icon_playerstate_y = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_NEXT_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_next_enable = values[0];
		skin_data->icon_next_x = values[1];
		skin_data->icon_next_y = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_PREV_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_prev_enable = values[0];
		skin_data->icon_prev_x = values[1];
		skin_data->icon_prev_y = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_RANDOM_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_random_enable = values[0];
		skin_data->icon_random_x = values[1];
		skin_data->icon_random_y = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_REPEAT_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_repeat_enable = values[0];
		skin_data->icon_repeat_x = values[1];
		skin_data->icon_repeat_y = values[2];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_EQ_ICON, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_eq_enable = values[0];
		skin_data->icon_eq_x = values[1];
		skin_data->icon_eq_y = values[2];
		mfree(param);
	}

	if (param = manifest_GetParam(buf, KEY_PROGRESSBAR, 0))
	{
		int values[2];
		ini_parse_values(param, values, 2);
		skin_data->pb_enable = values[0];
		skin_data->pb_enable_indicator = values[1];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_PB_POS, 0))
	{
		int values[4];
		ini_parse_values(param, values, 4);
		skin_data->pb_x1 = values[0];
		skin_data->pb_x2 = values[1];
		skin_data->pb_y1 = values[2];
		skin_data->pb_y2 = values[3];
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_PB_COLOR_B, 0))
	{
		skin_data->pb_color_b = ini_parse_value(param);
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_PB_COLOR_E, 0))
	{
		skin_data->pb_color_e = ini_parse_value(param);
		mfree(param);
	}

#ifdef DB2020
	if (param = manifest_GetParam(buf, KEY_PL_ITEM_COLOR, 0))
	{
		skin_data->PL_item_color = ini_parse_value(param);
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_PL_HIGHLIGHT, 0))
	{
		skin_data->PL_highlight_color = ini_parse_value(param);
		mfree(param);
	}
	if (param = manifest_GetParam(buf, KEY_PL_TITLE_COLOR, 0))
	{
		skin_data->PL_title_color = ini_parse_value(param);
		mfree(param);
	}
#endif

	if (param = manifest_GetParam(buf, KEY_WALKMAN, 0))
	{
		int values[3];
		ini_parse_values(param, values, 3);
		skin_data->icon_walkman_enable = values[0];
		skin_data->icon_walkman_x = values[1];
		skin_data->icon_walkman_y = values[2];
		mfree(param);
	}
#ifdef ENABLE_VISUALIZER
	if (param = manifest_GetParam(buf, KEY_VISUALIZATION, 0))
	{
		skin_data->viz_enable = ini_parse_value(param);
		mfree(param);
	}
#endif
	if (param = manifest_GetParam(buf, KEY_FULLSCREEN, 0))
	{
		skin_data->fullscreen = ini_parse_value(param);
		mfree(param);
	}

	mfree(buf);

	return skin_data;
}

#ifndef OLD_PLAYER
THUMB16
NEWCODE void skin_data_reload(AudioPlayerBook *audio_book, wchar_t *new_skin_path)
{
	ADVPLAYER_DATA *data = env_data_get();

	if (data->skin_loaded)
		mfree(data->skin_data);

	if (data->image_loaded)
		skin_images_unload();

	data->skin_data = skin_data_read(new_skin_path);
	skin_images_load(new_skin_path);
	data->skin_loaded = TRUE;

	DISP_OBJ *dispobj_nowplaying = GUIObject_GetDispObject(audio_book->Gui_NowPlaying);

#ifdef DB2010
	int style = data->skin_data->fullscreen ? UI_OverlayStyle_FullScreenNoStatus : UI_OverlayStyle_Default;
#else
	int style = data->skin_data->fullscreen ? UI_OverlayStyle_FullScreenNoStatus : UI_OverlayStyle_FullScreen;
#endif
	DispObject_SetStyle(dispobj_nowplaying, style);
	DispObject_WindowSetSize(dispobj_nowplaying, data->disp_w, data->disp_h);

#ifdef ENABLE_VISUALIZER
	KILL_TIMER(data->viz_timer);
	visualizer_init();
	Timer_ReSet(&data->wait_timer, 1000, MKTIMERPROC(wait_for_player), (LPARAM)data);
#endif

	DispObject_InvalidateRect(dispobj_nowplaying, NULL);
}
#endif
