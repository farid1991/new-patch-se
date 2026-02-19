#ifndef patch_h
#define patch_h

static const char MEM_NAME[] = "VS";
static const char BOOK_NAME[] = "VolumeSettingsBook";

void *malloc(int size);
void mfree(void *mem);

int pg_vs_EnterEvent(void *data, BOOK *book);
int pg_vs_ExitEvent(void *data, BOOK *book);
int pg_vs_CancelEvent(void *data, BOOK *book);

static const char MAIN_PAGE[] = "VolumeSlider_Main_Page";
static const char BASE_PAGE[] = "VolumeSlider_Base_Page";

typedef struct
{
    BOOK book;
    GUI *gui;
} VSBook;

#define MAX_MEDIAVOLUME 15
#define MAX_CALLVOLUME 8
#define MAX_RINGVOLUME 8

#define ACTION_LONG_BACK 0xFAF
#define ACTION_BACK 0xFC0
#define ACTION_SELECT1 0xFC2

#define KBD_SHORT_PRESS 0x0
#define KBD_LONG_PRESS 0x1
#define KBD_REPEAT 0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE 0x4

//
#define onBackPressed \
    ((void (*)(BOOK *, GUI *))ADDR_onBackPressed)

#define onLongBackPressed \
    ((void (*)(BOOK *, GUI *))ADDR_onLongBackPressed)

#define onCloseBook \
    ((void (*)(BOOK *))ADDR_onCloseBook)

#define onStandyEvent \
    ((int (*)(void *, BOOK *))ADDR_onStandyEvent)

#define StandartRingMenu \
    ((void (*)(DYNAMIC_MENU_ELEMENT *))ADDR_StandartRingMenu)

#endif