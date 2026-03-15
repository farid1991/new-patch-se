#ifndef _SkinSelect_h_
#define _SkinSelect_h_

int pg_MediaPlayer_SkinSelector_EnterEvent(void *data, BOOK *book);
int pg_MediaPlayer_SkinSelector_ExitEvent(void *data, BOOK *book);

static const char MediaPlayer_SkinSelectorPage_Name[] = "page_MediaPlayer_SkinSelectorPage";

// clang-format off

static const PAGE_MSG bk_msglst_skin[] = 
{
	PAGE_ENTER_EVENT, pg_MediaPlayer_SkinSelector_EnterEvent,
	PAGE_EXIT_EVENT, pg_MediaPlayer_Audio_Bk_ExitEvent,
	PREVIOUS_EVENT,	pg_MediaPlayer_Audio_Bk_PrevEvent,
	CANCEL_EVENT, pg_MediaPlayer_Audio_Bk_CancelEvent,
	NIL_EVENT, 0
};

static const PAGE_DESC page_MediaPlayer_SkinSelectorPage = {MediaPlayer_SkinSelectorPage_Name, 0, bk_msglst_skin};

// clang-format on

#endif
