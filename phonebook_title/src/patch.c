#include <libse.h>

#ifdef C510_R1HA035
    #include "C510_R1HA035.h"
#endif

#define NEWCODE __attribute__((section(".text.patch_section")))

#define AB_GETNBROFITEMS ((int (*)(int, int))ADDR_AB_GETNBROFITEMS)
#define snwprintf ((int (*)(wchar_t *, int, const wchar_t *, ...))ADDR_snwprintf)
#define TextID_Create ((int (*)(const void *, int, int))ADDR_TextID_Create)

#define GUIObject_SetTitleIcon ((void (*)(GUI *, IMAGEID))ADDR_GUIObject_SetTitleIcon)
#define GUIObject_SetTitleType ((void (*)(GUI *, UI_TitleMode_t))ADDR_GUIObject_SetTitleType)
#define GUIObject_SetTitleText ((void (*)(GUI *, TEXTID))ADDR_GUIObject_SetTitleText)
#define GUIObject_SetSecondRowTitleText ((void (*)(GUI *, TEXTID))ADDR_GUIObject_SetSecondRowTitleText)

#define MEMORY 2

THUMB16 NEWCODE void SetTitleText(int mem, GUI *gui)
{
    IMAGEID image;
    TEXTID title;
    wchar_t buf[64];

    if (mem != MEMORY)
    {
        image = IMAGEID_SIM;
        title = TEXTID_SIM;
        snwprintf(buf, sizeof(buf), L"Contacts: %d", AB_GETNBROFITEMS(4, 0));
    }
    else
    {
        image = IMAGEID_PHONE;
        title = TEXTID_PHONE;
        snwprintf(buf, sizeof(buf), L"Contacts: %d(%d)", AB_GETNBROFITEMS(0, 0), AB_GETNBROFITEMS(3, 0));
    }

    GUIObject_SetTitleIcon(gui, image);
    GUIObject_SetTitleType(gui, UI_TitleMode_Large);
    GUIObject_SetTitleText(gui, title);
    GUIObject_SetSecondRowTitleText(gui, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
}
