#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include "patch.h"

static const char KEY_VIZ[] = "[VIZ]";
static const char KEY_GUI_STYLE[] = "[GUI_STYLE]";
static const char KEY_HIDE_SOFT[] = "[HIDE_SOFTKEYS]";
static const char KEY_BACKGROUND[] = "[BACKGROUND]";
static const char KEY_COVER_EN[] = "[COVER_EN]";
static const char KEY_COVER_POS[] = "[COVER_POS]";
static const char KEY_TITLE[] = "[TITLE]";
static const char KEY_TITLE_POS[] = "[TITLE_POS]";
static const char KEY_TITLE_COLOR[] = "[TITLE_COLOR]";
static const char KEY_TITLE_ICON[] = "[TITLE_ICON]";
static const char KEY_ARTIST[] = "[ARTIST]";
static const char KEY_ARTIST_POS[] = "[ARTIST_POS]";
static const char KEY_ARTIST_COLOR[] = "[ARTIST_COLOR]";
static const char KEY_ARTIST_ICON[] = "[ARTIST_ICON]";
static const char KEY_ALBUM[] = "[ALBUM]";
static const char KEY_ALBUM_POS[] = "[ALBUM_POS]";
static const char KEY_ALBUM_COLOR[] = "[ALBUM_COLOR]";
static const char KEY_ALBUM_ICON[] = "[ALBUM_ICON]";

static const char KEY_TIME_E[] = "[TIME_E]";
static const char KEY_TIME_E_POS[] = "[TIME_E_POS]";
static const char KEY_TIME_E_COLOR[] = "[TIME_E_COLOR]";
static const char KEY_TIME_F[] = "[TIME_F]";
static const char KEY_TIME_F_POS[] = "[TIME_F_POS]";
static const char KEY_TIME_F_COLOR[] = "[TIME_F_COLOR]";
static const char KEY_TIME_R[] = "[TIME_R]";
static const char KEY_TIME_R_POS[] = "[TIME_R_POS]";
static const char KEY_TIME_R_COLOR[] = "[TIME_R_COLOR]";

static const char KEY_PROGRESS_BAR[] = "[PROGRESS_BAR]";
static const char KEY_PB_POS[] = "[PB_POS]";

THUMB16
NEWCODE static inline int isspace(int c)
{
	return (c == ' ' || c >= '\t' && c <= '\r');
}

THUMB16
NEWCODE static inline int isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

THUMB16
NEWCODE static inline int isxdigit(int c)
{
	return ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'));
}

THUMB16
NEWCODE int hex2int(const char *h)
{
	int res = 0;

	while (*h && *h != 'x')
		h++;
	if (*h == 'x')
		h++;

	while (*h && *h != ';')
	{
		char c = *h++;
		if (c >= '0' && c <= '9')
		{
			res = (res << 4) | (c - '0');
		}
		else if (c >= 'A' && c <= 'F')
		{
			res = (res << 4) | (c - 'A' + 10);
		}
		else if (c >= 'a' && c <= 'f')
		{
			res = (res << 4) | (c - 'a' + 10);
		}
	}
	return res;
}

THUMB16
NEWCODE int ascii2int(const char *s)
{
	int result = 0;

	while (isspace(*s))
		s++;

	while (isdigit(*s))
	{
		result = result * 10 + (*s - '0');
		s++;
	}

	return result;
}

THUMB16
NEWCODE int parse_value(const char *str)
{
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		return hex2int(str);

	return ascii2int(str);
}

THUMB16
NEWCODE void parse_values(const char *input, int *output)
{
	const char *input_start = input;
	int i = 0;

	while (*input_start)
	{
		const char *end = input_start;
		while (*end && *end != ',')
			end++;

		char temp[32];
		int len = end - input_start;
		if (len >= sizeof(temp))
			len = sizeof(temp) - 1;

		memcpy(temp, input_start, len);
		temp[len] = '\0';

		output[i++] = parse_value(temp);

		if (*end == ',')
			input_start = end + 1;
		else
			break;
	}
}

THUMB16
NEWCODE FILE_STYLE *DBRedraw_Load_CfgData(const wchar_t *fpath)
{
	size_t cfg_size = sizeof(FILE_STYLE);
	FILE_STYLE *fs = malloc(cfg_size);
	if (!fs)
		return NULL;

	memset(fs, 0, cfg_size);

	FSTAT st;
	if (fstat(fpath, CFG_NAME, &st) != 0)
		return fs;

	int file = _fopen(fpath, CFG_NAME, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file == -1)
		return fs;

	int fsize = st.fsize;
	char *buf = (char *)malloc(fsize + 1);
	if (!buf)
	{
		fclose(file);
		return fs;
	}

	memset(buf, 0, fsize + 1);
	if (fread(file, buf, fsize) != fsize)
	{
		fclose(file);
		mfree(buf);
		return fs;
	}
	fclose(file);

	char *param;

	/* =============== Background ==========================*/

	param = manifest_GetParam(buf, KEY_BACKGROUND, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->background_state = values[0];
		fs->background_x = values[1];
		fs->background_y = values[2];
		mfree(param);
	}

	/* =============== Cover Art ==========================*/

	param = manifest_GetParam(buf, KEY_COVER_EN, 0);
	if (param)
	{
		fs->cover_state = parse_value(param);
		mfree(param);
	}

	param = manifest_GetParam(buf, KEY_COVER_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->cover_x = values[0];
		fs->cover_y = values[1];
		fs->cover_w = values[2];
		fs->cover_h = values[3];
		mfree(param);
	}

	/* =============== Title ======================*/

	param = manifest_GetParam(buf, KEY_TITLE, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->title_state = values[0];
		fs->title_font = values[1];
		fs->title_align = values[2];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TITLE_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->title_x1 = values[0];
		fs->title_x2 = values[1];
		fs->title_y1 = values[2];
		fs->title_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TITLE_COLOR, 0);
	if (param)
	{
		int values[2];
		parse_values(param, values);
		fs->title_color = values[0];
		fs->title_border_color = values[1];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TITLE_ICON, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->title_icon_state = values[0];
		fs->title_icon_x = values[1];
		fs->title_icon_y = values[2];
		mfree(param);
	}

	/* =============== Artist ======================*/

	param = manifest_GetParam(buf, KEY_ARTIST, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->artist_state = values[0];
		fs->artist_font = values[1];
		fs->artist_align = values[2];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_ARTIST_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->artist_x1 = values[0];
		fs->artist_x2 = values[1];
		fs->artist_y1 = values[2];
		fs->artist_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_ARTIST_COLOR, 0);
	if (param)
	{
		int values[2];
		parse_values(param, values);
		fs->artist_color = values[0];
		fs->artist_border_color = values[1];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_ARTIST_ICON, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->artist_icon_state = values[0];
		fs->artist_icon_x = values[1];
		fs->artist_icon_y = values[2];
		mfree(param);
	}

	/* =============== Album ======================*/

	param = manifest_GetParam(buf, KEY_ALBUM, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->album_state = values[0];
		fs->album_font = values[1];
		fs->album_align = values[2];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_ALBUM_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->album_x1 = values[0];
		fs->album_x2 = values[1];
		fs->album_y1 = values[2];
		fs->album_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_ALBUM_COLOR, 0);
	if (param)
	{
		int values[2];
		parse_values(param, values);
		fs->album_color = values[0];
		fs->album_border_color = values[1];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_ALBUM_ICON, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->album_icon_state = values[0];
		fs->album_icon_x = values[1];
		fs->album_icon_y = values[2];
		mfree(param);
	}

	/* =============== Elapsed Time =====================*/

	param = manifest_GetParam(buf, KEY_TIME_E, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->elapsed_time_state = values[0];
		fs->elapsed_time_font = values[1];
		fs->elapsed_time_align = values[2];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TIME_E_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->elapsed_time_x1 = values[0];
		fs->elapsed_time_x2 = values[1];
		fs->elapsed_time_y1 = values[2];
		fs->elapsed_time_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TIME_E_COLOR, 0);
	if (param)
	{
		int values[2];
		parse_values(param, values);
		fs->elapsed_time_color = values[0];
		fs->elapsed_time_border_color = values[1];
		mfree(param);
	}

	/* =============== Full Time =====================*/

	param = manifest_GetParam(buf, KEY_TIME_F, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->full_time_state = values[0];
		fs->full_time_font = values[1];
		fs->full_time_align = values[2];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TIME_F_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->full_time_x1 = values[0];
		fs->full_time_x2 = values[1];
		fs->full_time_y1 = values[2];
		fs->full_time_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TIME_F_COLOR, 0);
	if (param)
	{
		int values[2];
		parse_values(param, values);
		fs->full_time_color = values[0];
		fs->full_time_border_color = values[1];
		mfree(param);
	}

	/* =============== Remaining Time =====================*/

	param = manifest_GetParam(buf, KEY_TIME_R, 0);
	if (param)
	{
		int values[3];
		parse_values(param, values);
		fs->remaining_time_state = values[0];
		fs->remaining_time_font = values[1];
		fs->remaining_time_align = values[2];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TIME_R_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->remaining_time_x1 = values[0];
		fs->remaining_time_x2 = values[1];
		fs->remaining_time_y1 = values[2];
		fs->remaining_time_y2 = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_TIME_R_COLOR, 0);
	if (param)
	{
		int values[2];
		parse_values(param, values);
		fs->remaining_time_color = values[0];
		fs->remaining_time_border_color = values[1];
		mfree(param);
	}

	/* =============== Progress Bar =====================*/

	param = manifest_GetParam(buf, KEY_PROGRESS_BAR, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->progbar_state = values[0];
		fs->progbar_current_color = values[1];
		fs->progbar_background_color = values[2];
		fs->progbar_border_color = values[3];
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_PB_POS, 0);
	if (param)
	{
		int values[4];
		parse_values(param, values);
		fs->progbar_x1 = values[0];
		fs->progbar_x2 = values[1];
		fs->progbar_y1 = values[2];
		fs->progbar_y2 = values[3];
		mfree(param);
	}

	/* =============== Misc =====================*/

	param = manifest_GetParam(buf, KEY_GUI_STYLE, 0);
	if (param)
	{
		fs->gui_style = parse_value(param);
		mfree(param);
	}
	param = manifest_GetParam(buf, KEY_HIDE_SOFT, 0);
	if (param)
	{
		fs->hide_softkeys = parse_value(param);
		mfree(param);
	}

	param = manifest_GetParam(buf, KEY_VIZ, 0);
	if (param)
	{
		int values[5];
		parse_values(param, values);
		fs->viz_count = values[0];
		fs->viz_x = values[1];
		fs->viz_y = values[2];
		fs->viz_w = values[3];
		fs->viz_h = values[4];
		mfree(param);
	}

	mfree(buf);

	return fs;
}
