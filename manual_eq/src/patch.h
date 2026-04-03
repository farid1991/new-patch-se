#ifndef __PATCH_H__
#define __PATCH_H__

void *malloc(int size);
void mfree(void *mem);

static const char EQ_MEM[] = "EQ_MEM";
static const char SOFTKEY_TEXT[] = "Manual EQ";

static const char MusicApplication_ManualEQ_PageName[] = "MusicApplication_ManualEQ_Page";

#define MusicApplication_CancelAction ((void (*)(BOOK *, GUI *))ADDR_MusicApplication_CancelAction)
#define MusicApplication_PrevAction ((void (*)(BOOK *, GUI *))ADDR_MusicApplication_PrevAction)

#define pg_MusicApplication_PreviousEvent ((int (*)(void *, BOOK *))ADDR_pg_MusicApplication_PreviousEvent)
#define pg_MusicApplication_CancelEvent ((int (*)(void *, BOOK *))ADDR_pg_MusicApplication_CancelEvent)
#define pg_MusicApplication_ExitEvent ((int (*)(void *, BOOK *))ADDR_pg_MusicApplication_ExitEvent)

int pg_MusicApplication_ManualEQ__EnterEvent(void *msg, BOOK *book);

// clang-format off

static const PAGE_MSG bk_MusicApplication_ManualEQ[] = 
{
    PAGE_ENTER_EVENT, pg_MusicApplication_ManualEQ__EnterEvent,
    PREVIOUS_EVENT, pg_MusicApplication_PreviousEvent,
    CANCEL_EVENT, pg_MusicApplication_CancelEvent,
    UI_MEDIAPLAYER_UPDATE_EVENT, pg_MusicApplication_PreviousEvent,
    PAGE_EXIT_EVENT, pg_MusicApplication_ExitEvent,
    NIL_EVENT, NULL
};

static const PAGE_DESC page_MusicApplication_ManualEQ = 
{
    MusicApplication_ManualEQ_PageName, NULL, bk_MusicApplication_ManualEQ
};

// clang-format on

#endif
