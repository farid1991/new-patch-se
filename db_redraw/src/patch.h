#ifndef __PATCH_H__
#define __PATCH_H__

static const wchar_t CFG_NAME[] = L"DBPlayerStyle.ini";
static const wchar_t CFG_PATH[] = CONFIG_PATH;

static const char MEM_NAME[] = "DBP_MEM";
static const char BOOK_NAME[] = "DBRedrawBook";
static const char GUI_NAME[] = "DBRedraw";
static const char BASEPAGE_NAME[] = "DBP_Base_Page";
static const char MAINPAGE_NAME[] = "DBP_Main_Page";

static const wchar_t VIZ_FMT[] = L"ANIM%02d.png";

typedef struct
{
	uint8_t background_state;
	int16_t background_x;
	int16_t background_y;

	uint8_t title_state;
	int16_t title_x1;
	int16_t title_x2;
	int16_t title_y1;
	int16_t title_y2;
	uint8_t title_align;
	uint8_t title_font;
	uint32_t title_color;
	uint32_t title_border_color;
	uint8_t title_icon_state;
	int16_t title_icon_x;
	int16_t title_icon_y;

	uint8_t artist_state;
	int16_t artist_x1;
	int16_t artist_x2;
	int16_t artist_y1;
	int16_t artist_y2;
	uint8_t artist_align;
	uint8_t artist_font;
	uint32_t artist_color;
	uint32_t artist_border_color;
	uint8_t artist_icon_state;
	int16_t artist_icon_x;
	int16_t artist_icon_y;

	uint8_t album_state;
	int16_t album_x1;
	int16_t album_x2;
	int16_t album_y1;
	int16_t album_y2;
	uint8_t album_align;
	uint8_t album_font;
	uint32_t album_color;
	uint32_t album_border_color;
	uint8_t album_icon_state;
	int16_t album_icon_x;
	int16_t album_icon_y;

	uint8_t elapsed_time_state;
	int16_t elapsed_time_x1;
	int16_t elapsed_time_x2;
	int16_t elapsed_time_y1;
	int16_t elapsed_time_y2;
	uint8_t elapsed_time_align;
	uint8_t elapsed_time_font;
	uint32_t elapsed_time_color;
	uint32_t elapsed_time_border_color;

	uint8_t remaining_time_state;
	int16_t remaining_time_x1;
	int16_t remaining_time_x2;
	int16_t remaining_time_y1;
	int16_t remaining_time_y2;
	uint8_t remaining_time_align;
	uint8_t remaining_time_font;
	uint32_t remaining_time_color;
	uint32_t remaining_time_border_color;

	uint8_t full_time_state;
	int16_t full_time_x1;
	int16_t full_time_x2;
	int16_t full_time_y1;
	int16_t full_time_y2;
	uint8_t full_time_align;
	uint8_t full_time_font;
	uint32_t full_time_color;
	uint32_t full_time_border_color;

	uint8_t progbar_state;
	int16_t progbar_x1;
	int16_t progbar_x2;
	int16_t progbar_y1;
	int16_t progbar_y2;
	uint32_t progbar_background_color;
	uint32_t progbar_current_color;
	uint32_t progbar_border_color;

	uint8_t cover_state;
	int16_t cover_x;
	int16_t cover_y;
	int16_t cover_w;
	int16_t cover_h;

	int16_t viz_x;
	int16_t viz_y;
	int16_t viz_w;
	int16_t viz_h;
	uint8_t viz_count;

	uint8_t gui_style;
	uint8_t hide_softkeys;
} FILE_STYLE;

enum DBPLAYER_IMAGE
{
	BACKGROUND_ICN,
	NOCOVER_ICN,
	ARTIST_ICN,
	TITLE_ICN,
	ALBUM_ICN,
	WALKMAN_ICN,
	LAST_ICN
};

typedef struct
{
	IMAGEID id;
	uint16_t handle;
} IMAGE_DESC;

#define MAX_VIZ 9

typedef struct
{
	BOOK book;
	GUI *player;
	void *metadata;
	BOOK *audiobook;
	FILE_STYLE *fs;
	wchar_t *title;
	wchar_t *artist;
	wchar_t *album;
	uint32_t elapsed_time;
	uint32_t full_time;
	IMAGEID cover;
	bool has_cover;
	IMAGE_DESC viz_image[MAX_VIZ];
} DBRedrawBook;

typedef struct GUI GUI_DBP;

typedef struct DISP_OBJ_DBP
{
	DISP_OBJ disp_obj;
	IMAGE_DESC skin_images[LAST_ICN];
	uint8_t viz_index;
	uint8_t viz_count;
} DISP_OBJ_DBP;

typedef struct
{
	BOOK book;
	int unk_18;
	GUI *gui;
} DataBrowserBook;

static const wchar_t MP_BACKGROUND_ICN_NAME[] = L"BACKGROUND_ICN.png";
static const wchar_t MP_COVERART_ICN_NAME[] = L"COVERART_ICN.png";
static const wchar_t MP_ARTIST_ICN_NAME[] = L"ARTIST_ICN.png";
static const wchar_t MP_TITLE_ICN_NAME[] = L"TITLE_ICN.png";
static const wchar_t MP_ALBUM_ICN_NAME[] = L"ALBUM_ICN.png";
static const wchar_t WALKMAN_ICN_NAME[] = L"WALKMAN_ICN.png";

static const wchar_t *const images_names[LAST_ICN] = {MP_BACKGROUND_ICN_NAME,
                                                      MP_COVERART_ICN_NAME,
                                                      MP_ARTIST_ICN_NAME,
                                                      MP_TITLE_ICN_NAME,
                                                      MP_ALBUM_ICN_NAME,
                                                      WALKMAN_ICN_NAME};

void *malloc(int size);
void mfree(void *mem);
int pg_DBRedraw_onEnter(void *msg, BOOK *book);
int pg_DBRedraw_onPlaying(void *msg, BOOK *book);
bool id3v2_get_coverart(const wchar_t *fpath, const wchar_t *fname, IMAGEID *imageid);
int parse_value(const char *str);
void parse_values(const char *input, int *output);
FILE_STYLE *DBRedraw_Load_CfgData(const wchar_t *fpath);

#define pg_MediaPlayer_SingleFile_Enter ((int (*)(void *, BOOK *))ADDR_pg_MediaPlayer_SingleFile_Enter)
#define pg_MediaPlayer_SingleFile_Exit ((int (*)(void *, BOOK *))ADDR_pg_MediaPlayer_SingleFile_Exit)

#endif // __PATCH_H__