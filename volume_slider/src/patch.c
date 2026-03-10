#if defined(J108_R7EA011)
#include <J108_R7EA011.h>
#define DB3350_R2
#endif

#include <libse.h>

#include "patch.h"
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"
#endif
#include "slider.h"

// clang-format off

static const PAGE_MSG bk_msglst_main[] =
{
    PAGE_ENTER_EVENT, pg_vs_EnterEvent,
    PAGE_EXIT_EVENT, pg_vs_ExitEvent,
    NIL_EVENT, NULL
};

static const PAGE_DESC vs_Main_Page = {MAIN_PAGE, NULL, bk_msglst_main};

static const PAGE_MSG bk_msglst_base[] =
{
    CANCEL_EVENT, pg_vs_CancelEvent,
    RETURN_TO_STANDBY_EVENT, pg_vs_CancelEvent,
    NIL_EVENT, NULL
};

static const PAGE_DESC vs_Base_Page = {BASE_PAGE, NULL, bk_msglst_base};

// clang-format on

THUMB16
NEWCODE void *malloc(int size)
{
#if defined(DB2020)
	return (memalloc(0, size, 1, 5, MEM_NAME, 0));
#elif defined(A2)
	return (memalloc(0xFFFFFFFF, size, 1, 5, MEM_NAME, 0));
#else
	return memalloc(size, 1, 5, MEM_NAME, 0);
#endif
}

THUMB16
NEWCODE void mfree(void *mem)
{
	if (mem)
#if defined(DB2020)
		memfree(0, mem, MEM_NAME, 0);
#elif defined(A2)
		memfree(0, mem, MEM_NAME, 0);
#else
		memfree(mem, MEM_NAME, 0);
#endif
}

THUMB16
NEWCODE int pg_vs_EnterEvent(void *data, BOOK *book)
{
	VSBook *vs = (VSBook *)book;
	if (vs->gui = Create_Slider(vs))
	{
		GUIObject_SoftKeys_SetAction(vs->gui, ACTION_BACK, onBackPressed);
		GUIObject_SoftKeys_SetAction(vs->gui, ACTION_LONG_BACK, onLongBackPressed);
		GUIObject_Show(vs->gui);
	}
	return 1;
}

THUMB16
NEWCODE int pg_vs_ExitEvent(void *data, BOOK *book)
{
	VSBook *vs = (VSBook *)book;
	GUIObject_Destroy(vs->gui);
	return 1;
}

THUMB16
NEWCODE int pg_vs_CancelEvent(void *data, BOOK *book)
{
	VSBook *vs = (VSBook *)book;
	FreeBook(&vs->book);
	return 1;
}

THUMB16
NEWCODE void vs_onClose(BOOK *book)
{
	VSBook *vs = (VSBook *)book;
	GUIObject_Destroy(vs->gui);
}

THUMB16
NEWCODE VSBook *Create_vs()
{
	VSBook *vs = (VSBook *)malloc(sizeof(VSBook));
	memset(vs, NULL, sizeof(VSBook));
	if (!CreateBook((BOOK *)vs, vs_onClose, &vs_Base_Page, BOOK_NAME, NO_BOOK_ID, NULL))
	{
		mfree(vs);
		return NULL;
	}
	vs->gui = 0;
	return vs;
}

THUMB16
NEWCODE void Call_vs(BOOK *book, GUI *gui)
{
	VSBook *vs = Create_vs();
	if (vs)
		BookObj_GotoPage(&vs->book, &vs_Main_Page);
}
