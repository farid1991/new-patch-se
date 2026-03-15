#ifndef AudioPlayerBook_H
#define AudioPlayerBook_H

typedef enum
{
	EqPreset_Normal = 0,
	EqPreset_Bass = 1,
#ifdef MEGABASS
	EqPreset_Megabass = 2,
	EqPreset_Voice = 3,
	EqPreset_TrebleBoost = 4,
#else
	EqPreset_Voice = 2,
	EqPreset_TrebleBoost = 3,
#endif
	EqPreset_Manual = 6
} EqPreset_t;

typedef enum
{
	TMusicState_Idle,           ///< Player is idle, eg is in the init phase but not yet fully initiated.
	TMusicState_Playing,        ///< Player is playing.
	TMusicState_Paused,         ///< Player is paused. Use the resume method to resume the playback.
	TMusicState_FastForwarding, ///< Player is fast forwarding.
	TMusicState_Interrupted,    ///< Player is interrupted by another playback session/player/call.
	TMusicState_Rewinding,      ///< Player is rewinding.
	TMusicState_Unknown,        ///< State is unknown to the Music Server.
	TMusicState_Last            ///< Place holder. Put new data before this!
} TMusic_State;

typedef struct MEDIAPLAYER_TRACK_DESC
{
	uint16_t unk_0;
	uint16_t unk_2;
	wchar_t *fpath;
	wchar_t *fname;
	wchar_t *mime;
	uint32_t full_time;
	int unk_14;
	uint32_t sample_rate;
	int unk_1C;
	int unk_20;
	int unk_24;
} MEDIAPLAYER_TRACK_DESC;

typedef struct MEDIAPLAYER_PLAYING_TIME_DATA
{
	uint16_t unk_0;
	uint16_t unk_2;
	BOOK *audio_book;
	char unk_8[0x1C];
	uint32_t hours;
	uint32_t minutes;
	uint32_t seconds;
} MEDIAPLAYER_PLAYING_TIME_DATA;

typedef struct MEDIAPLAYER_NEWTRACK_DATA
{
	uint16_t unk_0;
	uint16_t unk_2;
	BOOK *audio_book;
	char unk_8[0x1C];
} MEDIAPLAYER_NEWTRACK_DATA;

typedef struct MEDIAPLAYER_EQ
{
	int8_t band_1;
	int8_t band_2;
	int8_t band_3;
	int8_t band_4;
	int8_t band_5;
} MEDIAPLAYER_EQ;

typedef struct MEDIAPLAYER_STATE
{
	uint8_t unk_18;
	uint8_t state;
	uint8_t unk_1A;
	uint8_t unk_1B;
} MEDIAPLAYER_STATE;

typedef struct MM_BrowserToplevelBook
{
	BOOK book;
	GUI *MM_TopLevel; // 0x18
	int unk_1C;       // 0x1C
	uint16_t index;   // 0x20
	uint16_t unk_22;  // 0x22
	int unk_24;       // 0x24
	void *pShell;     // 0x28
	int unk_2C;       // 0x2c
	int unk_30;       // 0x30
	int unk_34;       // 0x34
} MM_BrowserToplevelBook;

typedef struct MM_BrowserArtistsBook
{
	BOOK book;
	GUI *MM_TopLevel; // 0x18
	char unk_1C[0xC]; // 0x1C
	void *unk_28;     // 0x28
	int unk_2C;       // 0x2c
	void *pIShell;    // 0x30
	void *unk_34;     // 0x34
	void *unk_38;     // 0x38
} MM_BrowserArtistsBook;

#if defined(OLD_PLAYER) // W700 & W800

typedef struct DISP_OBJ_NOWPLAYING_OLD
{
	DISP_OBJ disp_obj;
	char unk_BC[0x60];    // 0xBC
	TEXTID artist_textid; // 0x11C
	TEXTID title_textid;  // 0x120
	TEXTID album_textid;  // 0x124
	int full_time;        // 0x128
	int total_tracks;     // 0x12C
	int current_track_id; // 0x130
	int elapsed_time;     // 0x134
	bool is_preset;       // 0x138
	bool random;          // 0x139
	bool repeat;          // 0x13A
	char unk_13B;         // 0x13B
	uint8_t eq_preset;    // 0x13C
} DISP_OBJ_NOWPLAYING;

typedef struct DISP_OBJ_MP_AUDIO_OLD
{
	DISP_OBJ disp_obj;
	char unk_BC[0xD0]; // 0xBC
} DISP_OBJ_MP_AUDIO;

typedef struct AudioPlayerBook_Old
{
	BOOK book;
	MEDIAPLAYER_STATE player;    // 0x18
	GUI *Gui_NowPlaying;         // 0x1C
	GUI *Gui_SubMenu;            // 0x20
	void *pPlayerManager;        // 0x24 Interface?
	void *pAudioControl;         // 0x28
	int audio_session_id;        // 0x2C
	void *unk_30;                // 0x30
	uint32_t sample_rate;        // 0x34
	bool eq_enabled;             // 0x38
	char unk_39;                 // 0x39
	uint8_t eq_preset;           // 0x3A
	MEDIAPLAYER_EQ eq_active;    // 0x3B
	uint32_t unk_40;             // 0x40
	uint32_t parent_book_id;     // 0x44
	uint16_t unk_48;             // 0x48
	uint16_t unk_4A;             // 0x4A
	uint8_t window_mode;         // 0x4C
	char unk_4D;                 // 0x4D
	char unk_4E;                 // 0x4E
	char unk_4F;                 // 0x4F
	SUB_EXECUTE *sub_exec;       // 0x50
	uint32_t book_id;            // 0x54
	TEXTID error_text;           // 0x58
	uint16_t track_index;        // 0x5C
	uint16_t timer_id;           // 0x5E
	int unk_60;                  // 0x60
	void *unk_64;                // 0x64 Interface?
	uint32_t elapsed_time;       // 0x68
	MEDIAPLAYER_TRACK_DESC *dsc; // 0x6C
	uint16_t current_track_id;   // 0x70
	uint16_t selected_track_id;  // 0x72
	uint8_t unk_74[0x20];        // 0x74
	void *pIPlaylist;            // 0x94
	uint32_t playlist_id;        // 0x98
} AudioPlayerBook;

#elif defined(DB2010)

typedef struct DISP_OBJ_NOWPLAYING
{
	DISP_OBJ disp_obj;
	IMAGEID MP_BACKGROUND;        // 0xB8
	IMAGEID MP_MODE_NORMAL;       // 0xBA
	IMAGEID MP_MODE_RANDOM;       // 0xBC
	IMAGEID MP_MODE_REPEAT;       // 0xBE
	IMAGEID MP_EQ_ICON;           // 0xC0
	IMAGEID NOIMAGE_C2;           // 0xC2
	IMAGEID MP_EQ_MANUAL;         // 0xC4
	IMAGEID MP_EQ_NORMAL;         // 0xC6
	IMAGEID MP_EQ_BASS;           // 0xC8
	IMAGEID MP_EQ_MEGABASS;       // 0xCA
	IMAGEID MP_EQ_VOICE;          // 0xCC
	IMAGEID MP_EQ_TREBLE;         // 0xCE
	uint16_t artist_font_size;    // 0xD0
	uint16_t artist_font_height;  // 0xD2
	uint16_t album_font_size;     // 0xD4
	uint16_t album_font_height;   // 0xD6
	uint16_t title_font_size;     // 0xD8
	uint16_t title_font_height;   // 0xDA
	uint16_t other_font_size;     // 0xDC
	uint16_t other_font_height;   // 0xDE
	uint16_t elapsed_font_size;   // 0xE0
	uint16_t elapsed_font_height; // 0xE2
	uint16_t trackid_font_size;   // 0xE4
	uint16_t trackid_font_height; // 0xE6
	IMAGEID PB_PLAY_ICN;          // 0xE8
	IMAGEID image_EA;             // 0xEA
	IMAGEID PB_STOP_ICN;          // 0xEC
	IMAGEID PB_PAUSE_ICN;         // 0xEE
	int unk_F0;                   // 0xF0
	int unk_F4;                   // 0xF4
	uint32_t artist_color;        // 0xF8
	uint32_t title_color;         // 0xFC
	uint32_t additional_color;    // 0x100
	char unk_104[0x10];           // 0x104
	uint32_t brush_color;         // 0x114
	char unk_118[0x10];           // 0x118
	TEXTID artist_textid;         // 0x128
	TEXTID title_textid;          // 0x12C
	TEXTID album_textid;          // 0x130
	int full_time;                // 0x134
	int total_tracks;             // 0x138
	int current_track_id;         // 0x13C
	int elapsed_time;             // 0x140
	bool is_preset;               // 0x144
	bool random;                  // 0x145
	bool repeat;                  // 0x146
	char unk_147;                 // 0x147
	uint8_t eq_preset;            // 0x148
} DISP_OBJ_NOWPLAYING;

typedef struct DISP_OBJ_MP_AUDIO
{
	DISP_OBJ disp_obj;
	IMAGEID MP_BACKGROUND;              // 0xB8
	IMAGEID MP_LIST_BACKGROUND;         // 0xBA
	IMAGEID NOIMAGE_BC;                 // 0xBC
	IMAGEID MP_MODE_NORMAL;             // 0xBE
	IMAGEID MP_MODE_RANDOM;             // 0xC0
	IMAGEID MP_MODE_REPEAT;             // 0xC2
	IMAGEID MP_LOW_BACKGROUND;          // 0xC4
	uint16_t FontSize_C6;               // 0xC6
	uint16_t FontHeight_C6;             // 0xC8
	uint16_t FontSize_CA;               // 0xCA
	uint16_t FontHeight_CA;             // 0xCC
	uint16_t FontSize_CE;               // 0xCE
	uint16_t FontHeight_CE;             // 0xD0
	uint16_t FontSize_D2;               // 0xD2
	uint16_t FontHeight_D2;             // 0xD4
	RECT rect_background;               // 0xD6
	RECT rect_scrollbar;                // 0xDE
	RECT rect_playerstate;              // 0xE6
	RECT rect_remaining_time;           // 0xEE
	RECT rect_progressbar;              // 0xF6
	RECT rect_volume;                   // 0xFE
	RECT rect_repeat;                   // 0x106
	RECT rect_random;                   // 0x10E
	RECT rect_progressbar_bg;           // 0x116
	char unk_11E[0xA];                  // 0x11E
	DISP_OBJ *mp_playqueue;             // 0x128
	DISP_OBJ *mp_scrolltext;            // 0x12C
	DISP_OBJ *mp_volume;                // 0x130
	DISP_OBJ_NOWPLAYING *mp_nowplaying; // 0x134
	uint16_t current_track_id;          // 0x138
	uint8_t player_state;               // 0x13A
	uint8_t unk_13B;                    // 0x13B
	uint16_t full_time;                 // 0x13C
	uint16_t elapsed_time;              // 0x13E
	uint16_t remaining_time;            // 0x140
	char unk_142[0x4];                  // 0x142
	IMAGEID MP_PLAY;                    // 0x146
	IMAGEID NOIMAGE_148;                // 0x148
	IMAGEID MP_STOP;                    // 0x14A
	IMAGEID MP_PAUSE;                   // 0x14C
	IMAGEID MP_FAST_FORWARD;            // 0x14E
	IMAGEID MP_REWIND;                  // 0x150
	IMAGEID NOIMAGE_152;                // 0x152
	IMAGEID MP_SLOW_MOTION;             // 0x154
	char unk_156[0x36];                 // 0x156
} DISP_OBJ_MP_AUDIO;

typedef struct AudioPlayerBook
{
	BOOK book;
	MEDIAPLAYER_STATE player;    // 0x18
	GUI *Gui_NowPlaying;         // 0x1C
	GUI *Gui_SubMenu;            // 0x20
	void *pPlayerManager;        // 0x24 Interface?
	void *pAudioControl;         // 0x28
	int audio_session_id;        // 0x2C
	void *unk_30;                // 0x30
	uint16_t sample_rate;        // 0x34
	char unk_36;                 // 0x36
	char unk_37;                 // 0x37
	bool eq_enabled;             // 0x38
	char unk_39;                 // 0x39
	uint8_t eq_preset;           // 0x3A
	MEDIAPLAYER_EQ eq_active;    // 0x3B
	uint32_t unk_40;             // 0x40
	uint32_t parent_book_id;     // 0x44
	uint16_t unk_48;             // 0x48
	uint16_t unk_4A;             // 0x4A
	uint8_t window_mode;         // 0x4C
	char unk_4D;                 // 0x4D
	char unk_4E;                 // 0x4E
	char unk_4F;                 // 0x4F
	SUB_EXECUTE *sub_exec;       // 0x50
	uint32_t book_id;            // 0x54
	TEXTID error_text;           // 0x58
	uint16_t track_index;        // 0x5C
	uint16_t timer_id;           // 0x5E
	int unk_60;                  // 0x60
	void *unk_64;                // 0x64 Interface?
	uint32_t elapsed_time;       // 0x68
	MEDIAPLAYER_TRACK_DESC *dsc; // 0x6C
	uint16_t unk_70;             // 0x70
	uint16_t current_track_id;   // 0x72
	uint16_t selected_track_id;  // 0x74
	uint16_t unk_76;             // 0x76
	uint16_t unk_78;             // 0x78
	uint16_t unk_7A;             // 0x7A
	int unk_7C;                  // 0x7C
	int unk_80;                  // 0x80
	int total_tracks;            // 0x84
	bool repeat;                 // 0x88
	bool random;                 // 0x89
	char unk_8A;                 // 0x8A
	char unk_8B;                 // 0x8B
	void *unk_8C;                // 0x8C Interface?
	char unk_90;                 // 0x90
	uint8_t eq_state;            // 0x91
	char unk_92;                 // 0x92
	char unk_93;                 // 0x93
	MEDIAPLAYER_EQ *eq_settings; // 0x94
	void *pIPlaylist;            // 0x98
	uint32_t playlist_id;        // 0x9C
	int unk_A0;                  // 0xA0
	int unk_A4;                  // 0xA4
	int unk_A8;                  // 0xA8
	int unk_AC;                  // 0xAC
	void *pDrmHandler;           // 0xB0 Interface?
	int unk_B4;                  // 0xB4
	uint16_t unk_B8;             // 0xB8
	uint16_t unk_BA;             // 0xBA
	int unk_BC;                  // 0xBC
	char unk_C0[0xC];            // 0xC0
} AudioPlayerBook;
#endif

#endif
