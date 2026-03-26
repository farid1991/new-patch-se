#include "device.h"

#include <libse.h>

#include <book/AudioPlayerBook.h>

#include "patch.h"
#include "toplevel.h"

static const char page_MM_Browser_Toplevel_Bk_Albums_Name[] = "MM_Browser_Toplevel_Bk_AlbumsPage";

int pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent(void *data, BOOK *book);

// clang-format off

const PAGE_MSG bk_msglst_mm[] = 
{
    PAGE_ENTER_EVENT, pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent,
    ACCEPT_EVENT, pg_MM_Browser_Toplevel_Bk_Start,
#ifdef DB2020
    MM_BRW_TOPLEVEL_EVENT, pg_MM_Browser_Toplevel_Bk_Start,
#endif
    PREVIOUS_EVENT, pg_MM_Browser_Toplevel_Bk_Start,
    CANCEL_EVENT, pg_MM_Browser_Toplevel_Bk_Cancel,    
    MM_BRW_TOPLEVEL_STARTED_EVENT, pg_MM_Browser_Toplevel_Bk_Start,    
    MM_BRW_TOPLEVEL_DESTROYED_EVENT, pg_MM_Browser_Toplevel_Bk_Destroy,
    NIL_EVENT, 0
};

const PAGE_DESC page_MM_Browser_Toplevel_Bk_Albums = {page_MM_Browser_Toplevel_Bk_Albums_Name, NULL, bk_msglst_mm};

// clang-format on

static const IMAGEID topLevelBrowserIcons[MENU_LAST] = {
        MP_BR_LISTNOWPLAYING_ICN, // MENU_NOW_PLAYING
        MP_BR_LISTARTIST_ICN,     // MENU_ARTIST
        MP_BR_LISTALBUM_ICN,      // MENU_ALBUMS
        MP_BR_LISTTRACK_ICN,      // MENU_TRACKS
        MP_BR_LISTPLAYLIST_ICN,   // MENU_PLAYLIST
        MP_BR_LISTVIDEO_ICN       // MENU_VIDEOS
};

#if defined(OLD_PLAYER) || defined(DB2020)
THUMB16
NEWCODE void _GUIObject_SetAnimation(GUI *gui, int type)
{
	int anim;
	switch (type)
	{
	case LEFT_IN_LEFT_OUT: anim = 0x3000000; break;
	case LEFT_IN_RIGHT_OUT: anim = 0x3000010; break;
	case RIGHT_IN_LEFT_OUT: anim = 0x3000020; break;
	}
	DispObject_SetAnimation(GUIObject_GetDispObject(gui), anim);
}
#else
#define _GUIObject_SetAnimation GUIObject_SetAnimation
#endif

THUMB16
NEWCODE void New_MainMenu_TopLevelBrowser(GUI *MM_Browser)
{
	GUIObject_SetTitleBackgroundImage(MM_Browser, MP_BRW_TOPW_ICN);
	ListMenu_SetHotkeyMode(MM_Browser, LKHM_SHORTCUT);
}

#ifdef DB2010
static const char ALBUMS_TXT[] = "Albums";
#define MP_BR_LISTALBUM_TXT TextID_Create(ALBUMS_TXT, ENC_LAT1, TEXTID_ANY_LEN)
#endif

THUMB16
NEWCODE TEXTID New_ListText_TopLevelBrowser(BOOK *book, int index)
{
	if (index == MENU_NOWPLAYING)
		return MP_BR_LISTNOWPLAYING_TXT;
	else if (index == MENU_ARTIST)
		return MP_BR_LISTARTIST_TXT;
	else if (index == MENU_ALBUMS)
		return MP_BR_LISTALBUM_TXT;
	else if (index == MENU_TRACKS)
		return MP_BR_LISTTRACK_TXT;
	else if (index == MENU_PLAYLIST)
		return MP_BR_LISTPLAYLIST_TXT;
	else if (index == MENU_VIDEOS)
		return MP_BR_LISTVIDEO_TXT;

	return EMPTY_TEXTID;
}

THUMB16
NEWCODE IMAGEID New_ListIcon_TopLevelBrowser(BOOK *book, int index)
{
	return topLevelBrowserIcons[index];
}

THUMB16
NEWCODE int pg_MM_Browser_Toplevel_Bk_AlbumsPage_EnterEvent(void *data, BOOK *book)
{
	MM_BrowserToplevelBook *mm_book = (MM_BrowserToplevelBook *)book;

#ifdef DB2020
	if (!Call_MM_BrowserAlbumsMain(BookObj_GetBookID(book), NULL, 1, &mm_book->pShell))
#else
	if (!Call_MM_BrowserAlbumsMain(BookObj_GetBookID(book), NULL, &mm_book->pShell))
#endif
	{
		BookObj_CallPage(book, page_MM_Browser_Toplevel_Bk_ShowMessage);
	}
	return 1;
}

THUMB16
NEWCODE void New_ListLink_TopLevelBrowser(BOOK *book, GUI *gui)
{
	MM_BrowserToplevelBook *mm_book = (MM_BrowserToplevelBook *)book;
	switch (mm_book->index)
	{
	case MENU_NOWPLAYING:
		_GUIObject_SetAnimation(mm_book->MM_TopLevel, LEFT_IN_RIGHT_OUT);
		BookObj_CallPage(book, page_MM_Browser_Toplevel_Bk_NowPlaying);
		break;
	case MENU_ARTIST:
		_GUIObject_SetAnimation(mm_book->MM_TopLevel, RIGHT_IN_LEFT_OUT);
		BookObj_CallPage(book, page_MM_Browser_Toplevel_Bk_Artists);
		break;
	case MENU_ALBUMS:
		_GUIObject_SetAnimation(mm_book->MM_TopLevel, RIGHT_IN_LEFT_OUT);
		BookObj_CallPage(book, &page_MM_Browser_Toplevel_Bk_Albums);
		break;
	case MENU_TRACKS:
		_GUIObject_SetAnimation(mm_book->MM_TopLevel, RIGHT_IN_LEFT_OUT);
		BookObj_CallPage(book, page_MM_Browser_Toplevel_Bk_Tracks);
		break;
	case MENU_PLAYLIST:
		_GUIObject_SetAnimation(mm_book->MM_TopLevel, LEFT_IN_RIGHT_OUT);
		BookObj_CallPage(book, page_MM_Browser_Toplevel_Bk_Playlist);
		break;
	case MENU_VIDEOS: _GUIObject_SetAnimation(mm_book->MM_TopLevel, LEFT_IN_RIGHT_OUT);
#ifdef DB2020
		Shortcut_Run(MEDIAPLAYER_VIDEO);
#else
		BookObj_CallPage(book, page_MM_Browser_Toplevel_Bk_Videos);
#endif
		break;
	}
}
#define TEXTID_SPACE 0x78000020
THUMB16
NEWCODE TEXTID New_ListText_Track(TEXTID TrackName, GUI_MESSAGE *msg)
{
	int index = GUIonMessage_GetCreatedItemIndex(msg);

	TEXTID new_textid[3];
	new_textid[0] = TextID_CreateIntegerID(index + 1);
	new_textid[1] = TEXTID_SPACE;
	new_textid[2] = TrackName;
	return TextID_Create(new_textid, ENC_TEXTID, 3);
}

THUMB16
NEWCODE void New_MainMenu_TopLevelBrowser_ActionBack(MM_BrowserToplevelBook *mm_book, GUI *gui)
{
	UI_Event(MEDIAPLAYERKEY_PRESSED_EVENT);
}

THUMB16
NEWCODE int New_Toplevel_Bk_NowPlaying_PreviousEvent(void *data, MM_BrowserToplevelBook *mm_book)
{
	UI_Event(MEDIAPLAYERKEY_PRESSED_EVENT);
	return 1;
}
