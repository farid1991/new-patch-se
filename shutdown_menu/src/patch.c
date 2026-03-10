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

#include <libse.h>
#include <book/SetBook.h>

enum MENU_ITEMS
{
	ITEM_1,
	ITEM_2,
	ITEM_3,
	LAST_ITEM
};

#define ACTION_SELECT1 0xFC2
#define ACTION_BACK 0xFC0
#define ACTION_LONG_BACK 0xFAF

const char title_fmt[] = "Free HEAP: %02d KB";

THUMB16
NEWCODE TEXTID GetTitleText()
{
	char buff[32];
	snprintf(buff, MAXELEMS(buff), title_fmt, GetFreeBytesOnHeap() >> 10);
	return TextID_Create(buff, ENC_LAT1, TEXTID_ANY_LEN);
}

THUMB16
NEWCODE void ShutdownMenu_onClose(BOOK *book, GUI *gui)
{
	SetBook *setbook = (SetBook *)book;
	FreeBook(&setbook->book);
}

THUMB16
NEWCODE void ShutdownMenu_onSelect(BOOK *book, GUI *gui)
{
	SetBook *setbook = (SetBook *)book;
	switch (KnobOption_GetSelectedItem(setbook->gui))
	{
	case ITEM_1: REQUEST_SYSTEM_SHUTDOWN(); break;
	case ITEM_2: REQUEST_SYSTEM_RESTART(); break;
	case ITEM_3: FlightMode_GetState() ? FlightMode_SetState(OFF) : FlightMode_SetState(ON); break;
	}
	FreeBook(&setbook->book);
}

THUMB16
NEWCODE void CreateShutdownMenu()
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
