#include "device.h"

#include <libse.h>

#define MEMORY 2

const wchar_t sim_fmt[] = L"Contacts: %d";
const wchar_t phone_fmt[] = L"Contacts: %d";

THUMB16
NEWCODE void SetTitleText(int mem, GUI *gui)
{
	IMAGEID image;
	TEXTID title;
	wchar_t buf[64];

	if (mem != MEMORY)
	{
		image = IMAGEID_SIM;
		title = TEXTID_SIM;
		snwprintf(buf, sizeof(buf), sim_fmt, AB_GETNBROFITEMS(4, 0));
	}
	else
	{
		image = IMAGEID_PHONE;
		title = TEXTID_PHONE;
		snwprintf(buf, sizeof(buf), phone_fmt, AB_GETNBROFITEMS(0, 0), AB_GETNBROFITEMS(3, 0));
	}

	GUIObject_SetTitleIcon(gui, image);
	GUIObject_SetTitleType(gui, UI_TitleMode_Large);
	GUIObject_SetTitleText(gui, title);
	GUIObject_SetSecondRowTitleText(gui, TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN));
}
