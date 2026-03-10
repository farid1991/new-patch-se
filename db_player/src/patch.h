#ifndef _MAIN_H_
#define _MAIN_H_

#define FONTHEIGHT(font) (font & 0xFF)

static const wchar_t MTAGGER_ELF[] = L"MusicTagger.elf";
static const wchar_t ZBIN_PATH[] = L"/usb/other/ZBin";
static const wchar_t MTAGGER_PATH[] = L"/usb/other/ZBin/MusicTagger.elf";

static const char GuiName_DBPlayer[] = "GUI_DBPlayer";

typedef struct GUI GUI_DBPLAYER;

enum DBPLAYER_TAB
{
	PLAYER_TAB,
	LYRIC_TAB
};

typedef struct
{
	uint32_t timer;
	wchar_t *lrcinfo;
} TimerList;

typedef struct DISP_OBJ_DBP
{
	DISP_OBJ disp;
	TEXTID artist;
	TEXTID title;
	TEXTID album;
	TEXTID year;
	TEXTID genre;
	TEXTID ext;
	TEXTID time_f;
	TEXTID time_e;
	TEXTID time_r;
	TEXTID bitrate;
	TEXTID samplerate;
	TEXTID audiooutput;
	TEXTID buf_text;
	uint8_t media_volume;
	uint8_t cstep;
	uint16_t disp_width;
	uint16_t disp_height;
	uint16_t softkeys_height;
	uint16_t status_height;
	bool lrc_show_tags;
	bool lrc_show_inactive;
	bool lrc_is_centered;
	char *lrcbuf;
	TimerList *lrclist;
	uint16_t lrc_timer_id;
	int lrc_state;
	int current_offset;
	int total_offset;
	int offset_len;
	uint8_t tab;
} DISP_OBJ_DBP;

enum DBP_ACTION_ID
{
	ACTION_PAUSE,
	ACTION_PLAY,
	ACTION_STOP,
	ACTION_SETTINGS,
	ACTION_TAG,
	ACTION_TIME,
	ACTION_MINIMISE,
	ACTION_LAST
};

#ifdef __cplusplus
extern "C" {
#endif
void *malloc(int size);
void mfree(void *mem);
#ifdef __cplusplus
}
#endif

#define pg_Sound_Run__0x17FC ((int (*)(void *, BOOK *))ADDR_pg_Sound_Run__0x17FC)

#endif
