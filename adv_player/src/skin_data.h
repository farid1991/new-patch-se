#ifndef _SkinData_h_
#define _SkinData_h_

static const wchar_t MP_BACKGROUND_ICN_NAME[] = L"MP_BACKGROUND_ICN.png";
static const wchar_t MP_COVERART_ICN_NAME[] = L"MP_COVERART_ICN.png";
static const wchar_t MP_REFLECT_ICN_NAME[] = L"MP_REFLECT_ICN.png";
static const wchar_t MP_OVERLAY_ICN_NAME[] = L"MP_OVERLAY_ICN.png";
static const wchar_t MP_ARTIST_ICN_NAME[] = L"MP_ARTIST_ICN.png";
static const wchar_t MP_TITLE_ICN_NAME[] = L"MP_TITLE_ICN.png";
static const wchar_t MP_ALBUM_ICN_NAME[] = L"MP_ALBUM_ICN.png";
static const wchar_t MP_PLAY_ICN_NAME[] = L"MP_PLAY_ICN.png";
static const wchar_t MP_PAUSE_ICN_NAME[] = L"MP_PAUSE_ICN.png";
static const wchar_t MP_NEXT_ICN_NAME[] = L"MP_NEXT_ICN.png";
static const wchar_t MP_PREVIOUS_ICN_NAME[] = L"MP_PREVIOUS_ICN.png";
static const wchar_t MP_FF_ICN_NAME[] = L"MP_FF_ICN.png";
static const wchar_t MP_RW_ICN_NAME[] = L"MP_RW_ICN.png";
static const wchar_t MP_MODE_RANDOM_ICN_NAME[] = L"MP_MODE_RANDOM_ICN.png";
static const wchar_t MP_MODE_REPEAT_ICN_NAME[] = L"MP_MODE_REPEAT_ICN.png";
static const wchar_t MP_EQ_BASS_ICN_NAME[] = L"MP_EQ_BASS_ICN.png";
static const wchar_t MP_EQ_MEGABASS_ICN_NAME[] = L"MP_EQ_MEGABASS_ICN.png";
static const wchar_t MP_EQ_MANUAL_ICN_NAME[] = L"MP_EQ_MANUAL_ICN.png";
static const wchar_t MP_EQ_NORMAL_ICN_NAME[] = L"MP_EQ_NORMAL_ICN.png";
static const wchar_t MP_EQ_TREBLEBOOST_ICN_NAME[] = L"MP_EQ_TREBLEBOOST_ICN.png";
static const wchar_t MP_EQ_VOICE_ICN_NAME[] = L"MP_EQ_VOICE_ICN.png";
static const wchar_t MP_PROGRESS_INDICATOR_ICN_NAME[] = L"MP_PROGRESS_INDICATOR_ICN.png";

#ifdef DB2020
static const wchar_t MP_PLAYLIST_BG_ICN_NAME[] = L"MP_PLAYLIST_BG_ICN.png";
static const wchar_t MP_PLAYLIST_TITLE_ICN_NAME[] = L"MP_PLAYLIST_TITLE_ICN.png";
#endif

static const wchar_t WALKMAN_ICN_NAME[] = L"WALKMAN_ICN.png";

static const wchar_t *const skin_icon_names[MP_LAST_ICN] = {MP_BACKGROUND_ICN_NAME,  MP_COVERART_ICN_NAME,
                                                            MP_REFLECT_ICN_NAME,     MP_OVERLAY_ICN_NAME,
                                                            MP_ARTIST_ICN_NAME,      MP_TITLE_ICN_NAME,
                                                            MP_ALBUM_ICN_NAME,       MP_PLAY_ICN_NAME,
                                                            MP_PAUSE_ICN_NAME,       MP_NEXT_ICN_NAME,
                                                            MP_PREVIOUS_ICN_NAME,    MP_FF_ICN_NAME,
                                                            MP_RW_ICN_NAME,          MP_MODE_RANDOM_ICN_NAME,
                                                            MP_MODE_REPEAT_ICN_NAME, MP_EQ_BASS_ICN_NAME,
                                                            MP_EQ_MEGABASS_ICN_NAME, MP_EQ_MANUAL_ICN_NAME,
                                                            MP_EQ_NORMAL_ICN_NAME,   MP_EQ_TREBLEBOOST_ICN_NAME,
                                                            MP_EQ_VOICE_ICN_NAME,    MP_PROGRESS_INDICATOR_ICN_NAME,
#ifdef DB2020
                                                            MP_PLAYLIST_BG_ICN_NAME, MP_PLAYLIST_TITLE_ICN_NAME,
#endif
                                                            WALKMAN_ICN_NAME};

static const char KEY_BACKGROUND[] = "[Background]";
static const char KEY_OVERLAY[] = "[Overlay]";

static const char KEY_ARTIST_TEXT[] = "[ArtistText]";
static const char KEY_ARTIST_POS[] = "[ArtistPos]";
static const char KEY_ARTIST_COLOR[] = "[ArtistColor]";
static const char KEY_ARTIST_ICON[] = "[ArtistIcon]";

static const char KEY_TITLE_TEXT[] = "[TitleText]";
static const char KEY_TITLE_POS[] = "[TitlePos]";
static const char KEY_TITLE_COLOR[] = "[TitleColor]";
static const char KEY_TITLE_ICON[] = "[TitleIcon]";

static const char KEY_ALBUM_TEXT[] = "[AlbumText]";
static const char KEY_ALBUM_POS[] = "[AlbumPos]";
static const char KEY_ALBUM_COLOR[] = "[AlbumColor]";
static const char KEY_ALBUM_ICON[] = "[AlbumIcon]";

static const char KEY_TRACKID[] = "[TrackID]";
static const char KEY_TRACKID_POS[] = "[TrackIDPos]";
static const char KEY_TRACKID_COLOR[] = "[TrackIDColor]";

static const char KEY_FULLTIME[] = "[Fulltime]";
static const char KEY_FULLTIME_POS[] = "[FulltimePos]";
static const char KEY_FULLTIME_COLOR[] = "[FulltimeColor]";

static const char KEY_ELAPSED[] = "[Elapsed]";
static const char KEY_ELAPSED_POS[] = "[ElapsedPos]";
static const char KEY_ELAPSED_COLOR[] = "[ElapsedColor]";

static const char KEY_REMAINING[] = "[Remaining]";
static const char KEY_REMAINING_POS[] = "[RemainingPos]";
static const char KEY_REMAINING_COLOR[] = "[RemainingColor]";

static const char KEY_SAMPLERATE[] = "[SampleRate]";
static const char KEY_SAMPLERATE_POS[] = "[SampleRatePos]";
static const char KEY_SAMPLERATE_COLOR[] = "[SampleRateColor]";

static const char KEY_COVERART[] = "[CoverArt]";
static const char KEY_COVER_POS[] = "[CoverPos]";

static const char KEY_PLAYERSTATE[] = "[PlayerState]";
static const char KEY_NEXT_ICON[] = "[NextIcon]";
static const char KEY_PREV_ICON[] = "[PrevIcon]";
static const char KEY_RANDOM_ICON[] = "[RandomIcon]";
static const char KEY_REPEAT_ICON[] = "[RepeatIcon]";
static const char KEY_EQ_ICON[] = "[EQIcon]";

static const char KEY_PROGRESSBAR[] = "[ProgressBar]";
static const char KEY_PB_POS[] = "[PB_Pos]";
static const char KEY_PB_COLOR_B[] = "[PBColor_B]";
static const char KEY_PB_COLOR_E[] = "[PBColor_E]";

#ifdef DB2020
static const char KEY_PL_ITEM_COLOR[] = "[PlaylistItemColor]";
static const char KEY_PL_HIGHLIGHT[] = "[PlaylistHighlightColor]";
static const char KEY_PL_TITLE_COLOR[] = "[PlaylistTitleColor]";
#endif

static const char KEY_WALKMAN[] = "[WALKMAN]";

#ifdef ENABLE_VISUALIZER
static const char KEY_VISUALIZATION[] = "[VISUALIZATION]";
#endif

static const char KEY_FULLSCREEN[] = "[FULLSCREEN]";

#define MAX_PATH 256

typedef struct SKIN_CONFIG
{
	wchar_t path[MAX_PATH];
} SKIN_CONFIG;

typedef struct _SKIN_DATA
{
	bool bg_enable;
	uint16_t bg_x;
	uint16_t bg_y;

	bool overlay_enable;
	uint16_t overlay_x;
	uint16_t overlay_y;

	bool text_artist_enable;
	uint8_t text_artist_font;
	uint8_t text_artist_align;
	uint16_t text_artist_x;
	uint16_t text_artist_y;
	uint16_t text_artist_w;
	uint16_t text_artist_h;
	uint32_t text_artist_color;
	bool icon_artist_enable;
	uint16_t icon_artist_x;
	uint16_t icon_artist_y;

	bool text_title_enable;
	uint8_t text_title_font;
	uint8_t text_title_align;
	uint16_t text_title_x;
	uint16_t text_title_y;
	uint16_t text_title_w;
	uint16_t text_title_h;
	uint32_t text_title_color;
	bool icon_title_enable;
	uint16_t icon_title_x;
	uint16_t icon_title_y;

	bool text_album_enable;
	uint8_t text_album_font;
	uint8_t text_album_align;
	uint16_t text_album_x;
	uint16_t text_album_y;
	uint16_t text_album_w;
	uint16_t text_album_h;
	uint32_t text_album_color;
	bool icon_album_enable;
	uint16_t icon_album_x;
	uint16_t icon_album_y;

	bool text_trackid_enable;
	uint8_t text_trackid_font;
	uint8_t text_trackid_align;
	uint16_t text_trackid_x;
	uint16_t text_trackid_y;
	uint16_t text_trackid_w;
	uint16_t text_trackid_h;
	uint32_t text_trackid_color;

	bool text_fulltime_enable;
	uint8_t text_fulltime_font;
	uint8_t text_fulltime_align;
	uint16_t text_fulltime_x;
	uint16_t text_fulltime_y;
	uint16_t text_fulltime_w;
	uint16_t text_fulltime_h;
	uint32_t text_fulltime_color;

	bool text_elapsedtime_enable;
	uint8_t text_elapsedtime_font;
	uint8_t text_elapsedtime_align;
	uint16_t text_elapsedtime_x;
	uint16_t text_elapsedtime_y;
	uint16_t text_elapsedtime_w;
	uint16_t text_elapsedtime_h;
	uint32_t text_elapsedtime_color;

	bool text_remainingtime_enable;
	uint8_t text_remainingtime_font;
	uint8_t text_remainingtime_align;
	uint16_t text_remainingtime_x;
	uint16_t text_remainingtime_y;
	uint16_t text_remainingtime_w;
	uint16_t text_remainingtime_h;
	uint32_t text_remainingtime_color;

	bool text_samplerate_enable;
	uint8_t text_samplerate_font;
	uint16_t text_samplerate_align;
	uint16_t text_samplerate_x;
	uint16_t text_samplerate_y;
	uint16_t text_samplerate_w;
	uint16_t text_samplerate_h;
	uint32_t text_samplerate_color;

	bool coverart_enable;
	uint16_t coverart_x;
	uint16_t coverart_y;
	uint16_t coverart_w;
	uint16_t coverart_h;

	bool icon_playerstate_enable;
	uint16_t icon_playerstate_x;
	uint16_t icon_playerstate_y;

	bool icon_next_enable;
	uint16_t icon_next_x;
	uint16_t icon_next_y;

	bool icon_prev_enable;
	uint16_t icon_prev_x;
	uint16_t icon_prev_y;

	bool icon_random_enable;
	uint16_t icon_random_x;
	uint16_t icon_random_y;

	bool icon_repeat_enable;
	uint16_t icon_repeat_x;
	uint16_t icon_repeat_y;

	bool icon_eq_enable;
	uint16_t icon_eq_x;
	uint16_t icon_eq_y;

	bool pb_enable;
	bool pb_enable_indicator;
	uint16_t pb_x1;
	uint16_t pb_x2;
	uint16_t pb_y1;
	uint16_t pb_y2;
	uint32_t pb_color_b;
	uint32_t pb_color_e;

#ifdef DB2020
	uint32_t PL_title_color;
	uint32_t PL_item_color;
	uint32_t PL_highlight_color;
#endif

	bool icon_walkman_enable;
	uint16_t icon_walkman_x;
	uint16_t icon_walkman_y;

#ifdef ENABLE_VISUALIZER
	bool viz_enable;
#endif
	bool fullscreen;

} SKIN_DATA;

void skin_data_path_save(const wchar_t *skin_path);
SKIN_CONFIG *skin_data_config_get(const wchar_t *cfg_path, const wchar_t *cfg_name);
void skin_data_read(SKIN_DATA *skin_data, wchar_t *skin_path);

#ifndef OLD_PLAYER
void skin_data_reload(AudioPlayerBook *audio_book, wchar_t *new_skin_path);
#endif

const wchar_t *skin_images_getname(int index);
void skin_images_unload();
void skin_images_load(wchar_t *skin_path);

#endif
