#include "device.h"

#include <libse.h>

#include "patch.h"
#include "data.h"
#include "lang.h"
#include "settings.h"

static const char DB_EMP[] = "dbp_emp";

THUMB16
NEWCODE DBP_DATA *GetData()
{
	DBP_DATA *data = (DBP_DATA *)get_envp(NULL, DB_EMP);
	if (!data)
	{
		data = (DBP_DATA *)malloc(sizeof(DBP_DATA));
		memset(data, 0, sizeof(DBP_DATA));
		set_envp(NULL, DB_EMP, (OSADDRESS)data);
	}
	return data;
}

THUMB16
NEWCODE void DeleteData(DBP_DATA *data)
{
	if (data)
	{
		FSX_FreeFullPath(data->fullpath);
		FREE_GUI(data->time_input);
		mfree(data);
		set_envp(NULL, DB_EMP, NULL);
	}
}

THUMB16
NEWCODE void SaveData(bool save, int item)
{
	DBP_DATA *data = GetData();

	if (item == ITEM_ARTIST)
	{
		data->settings.artist.state = data->temp.activate1;
		data->settings.artist.align = data->temp.align;
		data->settings.artist.tcolor = data->temp.color1;
		data->settings.artist.ocolor = data->temp.color2;
		data->settings.artist.overlay = data->temp.overlay;
		data->settings.artist.font = data->temp.font;
		data->settings.artist.coord.x1 = data->temp.x1;
		data->settings.artist.coord.y1 = data->temp.y1;
		data->settings.artist.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_TITLE)
	{
		data->settings.title.state = data->temp.activate1;
		data->settings.title.align = data->temp.align;
		data->settings.title.tcolor = data->temp.color1;
		data->settings.title.ocolor = data->temp.color2;
		data->settings.title.overlay = data->temp.overlay;
		data->settings.title.font = data->temp.font;
		data->settings.title.coord.x1 = data->temp.x1;
		data->settings.title.coord.y1 = data->temp.y1;
		data->settings.title.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_ALBUM)
	{
		data->settings.album.state = data->temp.activate1;
		data->settings.album.align = data->temp.align;
		data->settings.album.tcolor = data->temp.color1;
		data->settings.album.ocolor = data->temp.color2;
		data->settings.album.overlay = data->temp.overlay;
		data->settings.album.font = data->temp.font;
		data->settings.album.coord.x1 = data->temp.x1;
		data->settings.album.coord.y1 = data->temp.y1;
		data->settings.album.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_YEAR)
	{
		data->settings.year.state = data->temp.activate1;
		data->settings.year.align = data->temp.align;
		data->settings.year.tcolor = data->temp.color1;
		data->settings.year.ocolor = data->temp.color2;
		data->settings.year.overlay = data->temp.overlay;
		data->settings.year.font = data->temp.font;
		data->settings.year.coord.x1 = data->temp.x1;
		data->settings.year.coord.y1 = data->temp.y1;
		data->settings.year.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_GENRE)
	{
		data->settings.genre.state = data->temp.activate1;
		data->settings.genre.align = data->temp.align;
		data->settings.genre.tcolor = data->temp.color1;
		data->settings.genre.ocolor = data->temp.color2;
		data->settings.genre.overlay = data->temp.overlay;
		data->settings.genre.font = data->temp.font;
		data->settings.genre.coord.x1 = data->temp.x1;
		data->settings.genre.coord.y1 = data->temp.y1;
		data->settings.genre.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_FILETYPE)
	{
		data->settings.ext.state = data->temp.activate1;
		data->settings.ext.align = data->temp.align;
		data->settings.ext.tcolor = data->temp.color1;
		data->settings.ext.ocolor = data->temp.color2;
		data->settings.ext.overlay = data->temp.overlay;
		data->settings.ext.font = data->temp.font;
		data->settings.ext.coord.x1 = data->temp.x1;
		data->settings.ext.coord.y1 = data->temp.y1;
		data->settings.ext.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_TOTAL)
	{
		data->settings.time_t.state = data->temp.activate1;
		data->settings.time_t.align = data->temp.align;
		data->settings.time_t.tcolor = data->temp.color1;
		data->settings.time_t.ocolor = data->temp.color2;
		data->settings.time_t.overlay = data->temp.overlay;
		data->settings.time_t.font = data->temp.font;
		data->settings.time_t.coord.x1 = data->temp.x1;
		data->settings.time_t.coord.y1 = data->temp.y1;
		data->settings.time_t.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_ELAPSED)
	{
		data->settings.time_e.state = data->temp.activate1;
		data->settings.time_e.align = data->temp.align;
		data->settings.time_e.tcolor = data->temp.color1;
		data->settings.time_e.ocolor = data->temp.color2;
		data->settings.time_e.overlay = data->temp.overlay;
		data->settings.time_e.font = data->temp.font;
		data->settings.time_e.coord.x1 = data->temp.x1;
		data->settings.time_e.coord.y1 = data->temp.y1;
		data->settings.time_e.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_REMAINING)
	{
		data->settings.time_r.state = data->temp.activate1;
		data->settings.time_r.align = data->temp.align;
		data->settings.time_r.tcolor = data->temp.color1;
		data->settings.time_r.ocolor = data->temp.color2;
		data->settings.time_r.overlay = data->temp.overlay;
		data->settings.time_r.font = data->temp.font;
		data->settings.time_r.coord.x1 = data->temp.x1;
		data->settings.time_r.coord.y1 = data->temp.y1;
		data->settings.time_r.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_BITRATE)
	{
		data->settings.bitrate.state = data->temp.activate1;
		data->settings.bitrate.align = data->temp.align;
		data->settings.bitrate.tcolor = data->temp.color1;
		data->settings.bitrate.ocolor = data->temp.color2;
		data->settings.bitrate.overlay = data->temp.overlay;
		data->settings.bitrate.font = data->temp.font;
		data->settings.bitrate.coord.x1 = data->temp.x1;
		data->settings.bitrate.coord.y1 = data->temp.y1;
		data->settings.bitrate.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_SAMPLERATE)
	{
		data->settings.samplerate.state = data->temp.activate1;
		data->settings.samplerate.align = data->temp.align;
		data->settings.samplerate.tcolor = data->temp.color1;
		data->settings.samplerate.ocolor = data->temp.color2;
		data->settings.samplerate.overlay = data->temp.overlay;
		data->settings.samplerate.font = data->temp.font;
		data->settings.samplerate.coord.x1 = data->temp.x1;
		data->settings.samplerate.coord.y1 = data->temp.y1;
		data->settings.samplerate.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_AUDIOOUTPUT)
	{
		data->settings.audiooutput.state = data->temp.activate1;
		data->settings.audiooutput.align = data->temp.align;
		data->settings.audiooutput.tcolor = data->temp.color1;
		data->settings.audiooutput.ocolor = data->temp.color2;
		data->settings.audiooutput.overlay = data->temp.overlay;
		data->settings.audiooutput.font = data->temp.font;
		data->settings.audiooutput.coord.x1 = data->temp.x1;
		data->settings.audiooutput.coord.y1 = data->temp.y1;
		data->settings.audiooutput.coord.x2 = data->temp.x2;
	}
	else if (item == ITEM_TIME_PROGRESS)
	{
		data->settings.time.state = data->temp.activate1;
		data->settings.time.slider = data->temp.activate2;
		data->settings.time.round = data->temp.activate3;
		data->settings.time.progress_bcolor = data->temp.color1;
		data->settings.time.progress_fcolor = data->temp.color2;
		data->settings.time.progress_rect.x1 = data->temp.x1;
		data->settings.time.progress_rect.y1 = data->temp.y1;
		data->settings.time.progress_rect.x2 = data->temp.x2;
		data->settings.time.progress_rect.y2 = data->temp.y2;
	}
	else if (item == ITEM_VOLUME_PROGRESS)
	{
		data->settings.volume.state = data->temp.activate1;
		data->settings.volume.slider = data->temp.activate2;
		data->settings.volume.round = data->temp.activate3;
		data->settings.volume.progress_bcolor = data->temp.color1;
		data->settings.volume.progress_fcolor = data->temp.color2;
		data->settings.volume.progress_rect.x1 = data->temp.x1;
		data->settings.volume.progress_rect.y1 = data->temp.y1;
		data->settings.volume.progress_rect.x2 = data->temp.x2;
		data->settings.volume.progress_rect.y2 = data->temp.y2;
	}
	else if (item == ITEM_COVERART)
	{
		data->settings.cover = data->temp.activate1;
		data->settings.cover_rect.x1 = data->temp.x1;
		data->settings.cover_rect.y1 = data->temp.y1;
		data->settings.cover_rect.x2 = data->temp.x2;
		data->settings.cover_rect.y2 = data->temp.y2;
	}
	else if (item == ITEM_FRAME)
	{
		data->settings.frame.state = data->temp.activate1;
		data->settings.frame.pos.x = data->temp.x1;
		data->settings.frame.pos.y = data->temp.y1;
	}
	else if (item == ITEM_ARTIST_ICN)
	{
		data->settings.artist_icn.state = data->temp.activate1;
		data->settings.artist_icn.pos.x = data->temp.x1;
		data->settings.artist_icn.pos.y = data->temp.y1;
	}
	else if (item == ITEM_TITLE_ICN)
	{
		data->settings.title_icn.state = data->temp.activate1;
		data->settings.title_icn.pos.x = data->temp.x1;
		data->settings.title_icn.pos.y = data->temp.y1;
	}
	else if (item == ITEM_ALBUM_ICN)
	{
		data->settings.album_icn.state = data->temp.activate1;
		data->settings.album_icn.pos.x = data->temp.x1;
		data->settings.album_icn.pos.y = data->temp.y1;
	}
	else if (item == ITEM_PLAYERSTATE_ICN)
	{
		data->settings.playerstate_icn.state = data->temp.activate1;
		data->settings.playerstate_icn.pos.x = data->temp.x1;
		data->settings.playerstate_icn.pos.y = data->temp.y1;
	}
	else if (item == ITEM_BACKROUND)
	{
		data->settings.background.state = data->temp.activate1;
		data->settings.background_color = data->temp.color1;
		data->settings.background.pos.x = data->temp.x1;
		data->settings.background.pos.y = data->temp.y1;
	}
	else if (item == ITEM_ADDITIONAL)
	{
		data->settings.screen = data->temp.activate1;
		data->settings.soft = data->temp.activate2;
#ifndef DB3350
		data->settings.animation = data->temp.activate3;
#endif
	}

	if (save)
	{
		int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_WRONLY, FSX_S_IWRITE, NULL);
		if (file != -1)
		{
			fwrite(file, &data->settings, sizeof(SETTINGS_DATA));
			fclose(file);
		}
	}
}

THUMB16
NEWCODE void LoadData(DBP_DATA *Data)
{
	int file = _fopen(FILE_PATH, FILE_NAME, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file != -1)
	{
		memset(&Data->settings, 0, sizeof(SETTINGS_DATA));
		fread(file, &Data->settings, sizeof(SETTINGS_DATA));
		fclose(file);
	}
}
