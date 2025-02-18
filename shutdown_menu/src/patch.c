#include <libse.h>
#include <book/SetBook.h>

#if defined(J10_R7CA065)
    #include <J10_R7CA065.h>
#elif defined(J20_R7CA064)
    #include <J20_R7CA064.h>
#elif defined(J108_R7EA011)
    #include <J108_R7EA011.h>
#elif defined(U10_R7AA071)
    #include <U10_R7AA071.h>
#elif defined(U10_R7BA084)
    #include <U10_R7BA084.h>
#elif defined(U100_R7AA076)
    #include <U100_R7AA076.h>
#elif defined(W20_R7DA062)
    #include <W20_R7DA062.h>
#endif

#define NEWCODE __attribute__((section(".text.patch_section")))

enum MENU_ITEMS
{
    ITEM_1,
    ITEM_2,
    ITEM_3,
    LAST_ITEM
};

#define ACTION_SELECT1    0xFC2
#define ACTION_BACK       0xFC0
#define ACTION_LONG_BACK  0xFAF

#define snwprintf ((int (*)(wchar_t *, int, const wchar_t *, ...))ADDR_snwprintf)
#define TextID_Create ((int (*)(const void *, int, int))ADDR_TextID_Create)

#define Create_KnobOption ((GUI * (*)(BOOK * bk, int display)) ADDR_Create_KnobOption)
#define KnobOption_SetTitleText ((void (*)(GUI * g, TEXTID text)) ADDR_KnobOption_SetTitleText)
#define KnobOption_SetItemCount ((void (*)(GUI * g, int item)) ADDR_KnobOption_SetItemCount)
#define KnobOption_SetCursor ((void (*)(GUI * g, int pos)) ADDR_KnobOption_SetCursor)
#define KnobOption_SetItems ((void (*)(GUI * g, TEXTID text, int num)) ADDR_KnobOption_SetItems)
#define KnobOption_GetSelectedItem ((int (*)(GUI * g)) ADDR_KnobOption_GetSelectedItem)

#define GUIObject_SoftKeys_SetAction ((void (*)(GUI *, uint16_t, SKACTIONPROC))ADDR_GUIObject_SoftKeys_SetAction)
#define GUIObject_Show ((void (*)(GUI *))ADDR_GUIObject_Show)

#define DynamicMenu_CreateSetBook ((BOOK *(*)(void))ADDR_DynamicMenu_CreateSetBook)
#define REQUEST_SYSTEM_SHUTDOWN ((void (*)(void))ADDR_REQUEST_SYSTEM_SHUTDOWN)
#define REQUEST_SYSTEM_RESTART ((void (*)(void))ADDR_REQUEST_SYSTEM_RESTART)
#define GetFreeBytesOnHeap ((int (*)(void))ADDR_GetFreeBytesOnHeap)
#define FreeBook ((void (*)(BOOK * book)) ADDR_FreeBook)
#define FlightMode_GetState ((int (*)(void))ADDR_FlightMode_GetState)
#define FlightMode_SetState ((void (*)(int state))ADDR_FlightMode_SetState)

THUMB16 NEWCODE TEXTID GetTitleText()
{
    wchar_t buff[32];
    snwprintf(buff, MAXELEMS(buff), L"Free HEAP: %dKB", GetFreeBytesOnHeap() >> 10);
    return TextID_Create(buff, ENC_UCS2, TEXTID_ANY_LEN);
}

THUMB16 NEWCODE void ShutdownMenu_onClose(BOOK *book, GUI *gui)
{
    SetBook *setbook = (SetBook *)book;
    FreeBook(&setbook->book);
}

THUMB16 NEWCODE void ShutdownMenu_onSelect(BOOK *book, GUI *gui)
{
    SetBook *setbook = (SetBook *)book;
    switch (KnobOption_GetSelectedItem(setbook->gui))
    {
    case ITEM_1:
        REQUEST_SYSTEM_SHUTDOWN();
        break;
    case ITEM_2:
        REQUEST_SYSTEM_RESTART();
        break;
    case ITEM_3:
        FlightMode_GetState() ? FlightMode_SetState(OFF) : FlightMode_SetState(ON);
        break;
    }
    FreeBook(&setbook->book);
}

THUMB16 NEWCODE void CreateShutdownMenu()
{
    SetBook *setbook = (SetBook *)DynamicMenu_CreateSetBook();

    setbook->gui = Create_KnobOption(&setbook->book, UIDisplay_Main);
    KnobOption_SetItemCount(setbook->gui, LAST_ITEM);
    KnobOption_SetCursor(setbook->gui, ITEM_1);
    KnobOption_SetTitleText(setbook->gui, GetTitleText());
    KnobOption_SetItems(setbook->gui, ITEM1_TEXT, ITEM_1);
    KnobOption_SetItems(setbook->gui, ITEM2_TEXT, ITEM_2);
    KnobOption_SetItems(setbook->gui, ITEM3_TEXT, ITEM_3);
    GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_SELECT1, ShutdownMenu_onSelect);
    GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_BACK, ShutdownMenu_onClose);
    GUIObject_SoftKeys_SetAction(setbook->gui, ACTION_LONG_BACK, ShutdownMenu_onClose);
    GUIObject_Show(setbook->gui);
}
