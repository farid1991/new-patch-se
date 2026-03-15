#ifndef _Main_h_
#define _Main_h_

#ifdef DEBUG
#define DBG(...) debug_printf(__VA_ARGS__);
#else
#define DBG(...)
#endif

static const wchar_t SKIN_NAME[] = L"walkman.ini";
static const wchar_t SKIN_CFG_NAME[] = L"skin.cfg";
static const wchar_t SKIN_CFG_PATH[] = _SKIN_CFG_PATH;
static const wchar_t SKIN_PATH[] = _SKIN_PATH;
static const wchar_t DEFAULT_SKIN_PATH[] = _DEFAULT_SKIN_PATH;

#ifdef OLD_PLAYER
BOOL _FSX_IsFileExists(const wchar_t *fpath, const wchar_t *fname);
#else
#define _FSX_IsFileExists FSX_IsFileExists
#endif

#define RESIZED_CANVAS (480)

#define MediaPlayer_Audio_OnCreate ((int (*)(DISP_OBJ *))ADDR_MediaPlayer_Audio_OnCreate)

#define MediaPlayer_Audio_OnClose ((void (*)(DISP_OBJ *))ADDR_MediaPlayer_Audio_OnClose)

#define MediaPlayer_Audio_OnRefresh ((void (*)(DISP_OBJ *))ADDR_MediaPlayer_Audio_OnRefresh)

#define MediaPlayer_Audio_OnDestroy ((int (*)(void *, AudioPlayerBook *))ADDR_MediaPlayer_Audio_OnDestroy)

#define MediaPlayer_NowPlaying_OnCreate ((int (*)(DISP_OBJ *))ADDR_MediaPlayer_NowPlaying_OnCreate)

#define MediaPlayer_NowPlaying_OnClose ((void (*)(DISP_OBJ *))ADDR_MediaPlayer_NowPlaying_OnClose)

#define MediaPlayer_NowPlaying_OnRedraw ((void (*)(DISP_OBJ *, int, int, int))ADDR_MediaPlayer_NowPlaying_OnRedraw)

#define MediaPlayer_Audio_Sort ((void (*)(BOOK *, GUI *))ADDR_MediaPlayer_Audio_Sort)

#define MediaPlayer_Audio_ActionBack ((void (*)(BOOK *, GUI *))ADDR_MediaPlayer_Audio_ActionBack)

#define MediaPlayer_Audio_ActionLongBack ((void (*)(BOOK *, GUI *))ADDR_MediaPlayer_Audio_ActionLongBack)

#define MM_BrowserToplevel_Enter ((void (*)(BOOK *, GUI *))ADDR_MM_BrowserToplevel_Enter)

#define pg_MEDIAPLAYER_AUDIO_PLAYING_TIME ((int (*)(void *, BOOK *))ADDR_pg_MEDIAPLAYER_AUDIO_PLAYING_TIME)

#define pg_MEDIAPLAYER_NEW_TRACK_EVENT ((int (*)(void *, BOOK *))ADDR_pg_MEDIAPLAYER_NEW_TRACK_EVENT)

#define pg_MEDIAPLAYER_CREATED_EVENT ((int (*)(void *, BOOK *))ADDR_pg_MEDIAPLAYER_CREATED_EVENT)

#define pg_MediaPlayer_Audio_Bk_ExitEvent ((int (*)(void *, BOOK *))ADDR_pg_MediaPlayer_Audio_Bk_ExitEvent)

#define pg_MediaPlayer_Audio_Bk_PrevEvent ((int (*)(void *, BOOK *))ADDR_pg_MediaPlayer_Audio_Bk_PrevEvent)

#define pg_MediaPlayer_Audio_Bk_CancelEvent ((int (*)(void *, BOOK *))ADDR_pg_MediaPlayer_Audio_Bk_CancelEvent)

#define pg_MM_Browser_Toplevel_Bk_Cancel ((int (*)(void *, BOOK *))ADDR_pg_MM_Browser_Toplevel_Bk_Cancel)

#define pg_MM_Browser_Toplevel_Bk_Start ((int (*)(void *, BOOK *))ADDR_pg_MM_Browser_Toplevel_Bk_Start)

#define pg_MM_Browser_Toplevel_Bk_Destroy ((int (*)(void *, BOOK *))ADDR_pg_MM_Browser_Toplevel_Bk_Destroy)

#define pg_MM_Browser_Toplevel_Bk_AlbumsPage_ExitEvent \
	((int (*)(void *, BOOK *))ADDR_pg_MM_Browser_Toplevel_Bk_AlbumsPage_ExitEvent)

#if defined(DB2020)
#define Call_MM_BrowserAlbumsMain ((int (*)(int, wchar_t *, int, void **))ADDR_Call_MM_BrowserAlbumsMain)
#elif defined(DB2010)
#define Call_MM_BrowserAlbumsMain ((int (*)(int, wchar_t *, void **))ADDR_Call_MM_BrowserAlbumsMain)
#define GUIObject_SetAnimation ((void (*)(GUI *, int))ADDR_GUIObject_SetAnimation)
#endif

#define MediaPlayer_State_Get ((char (*)(void *))ADDR_MediaPlayer_State_Get)

#endif
