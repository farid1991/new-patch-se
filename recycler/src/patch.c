#include "device.h"

#include <libse.h>
#include <book/BrowserItemBook.h>

static const char EMP_NAME[] = "rc_emp";
static const char MEM_NAME[] = "rc_mem";
static const char RECYCLER_PAGE_NAME[] = "DataBrowser_Recycler_Page";

static const wchar_t INT_PATH[] = L"/usb/RECYCLER";
static const wchar_t EXT_PATH[] = L"/card/RECYCLER";

static const char TEXT_DELETE_PERMANENT[] = "File(s) will deleted permanently";
static const char TEXT_DELETE_FILES[] = "Are you sure want to delete permanently this file?";
static const char TEXT_DELETE_MARKED[] = "Are you sure want to delete permanently this marked files?";

typedef struct
{
	BOOL state;
	BOOL is_marked;
} RECYCLER_DATA;

THUMB16
NEWCODE void *malloc(int size)
{
#if defined(DB2020)
	return (memalloc(0, size, 1, 5, MEM_NAME, 0));
#elif defined(A2)
	return (memalloc(-1, size, 1, 5, MEM_NAME, 0));
#else
	return (memalloc(size, 1, 5, MEM_NAME 0));
#endif
}

THUMB16
NEWCODE void mfree(void *mem)
{
	if (mem)
#if defined(DB2020) || defined(A2)
		memfree(0, mem, MEM_NAME, 0);
#else
		memfree(mem, MEM_NAME, 0);
#endif
}

THUMB16
NEWCODE RECYCLER_DATA *GetEnvData()
{
	RECYCLER_DATA *data = (RECYCLER_DATA *)get_envp(get_bid(current_process()), EMP_NAME);
	if (!data)
	{
		data = (RECYCLER_DATA *)malloc(sizeof(RECYCLER_DATA));
		data->state = 0;
		data->is_marked = 0;
		set_envp(get_bid(current_process()), EMP_NAME, (OSADDRESS)data);
	}
	return data;
}

THUMB16
NEWCODE const wchar_t *GetRecyclerPath()
{
	if (GetMemoryStickStatus())
		return EXT_PATH;
	return INT_PATH;
}

THUMB16
NEWCODE int pg_DataBrowser_Recycler_EnterEvent(void *data, BOOK *book)
{
	CreatePasswordInputWindow(BookObj_GetBookID(book), 0, 2, TEXTID_LOCKED);
	return 1;
}

THUMB16
NEWCODE int pg_DataBrowser_Recycler_AcceptEvent(void *data, BOOK *book)
{
	int BookID = BookObj_GetBookID(book);

	void *desc = DataBrowserDesc_Create();
	if (desc)
	{
		mkdir(GetRecyclerPath());
		DataBrowserDesc_SetHeaderText(desc, STR("Recycle Bin"));
		DataBrowserDesc_SetBookID(desc, BookID);
		const wchar_t *folder_list[2];
		folder_list[0] = GetRecyclerPath();
		folder_list[1] = NULL;
		DataBrowserDesc_SetFolders(desc, folder_list);
		DataBrowserDesc_SetFoldersNumber(desc, 1);
		DataBrowserDesc_Menu_AddFSFunctions(desc, 0);
		DataBrowserDesc_Menu_AddNewFolder(desc, 0);
		DataBrowserDesc_Menu_AddMarkFiles(desc, 1);
		DataBrowserDesc_SetOpenEmptyFolder(desc, 1);
		DataBrowser_Create(desc);
		DataBrowserDesc_Destroy(desc);
	}
	else
		UI_Event_toBookID(PREVIOUS_EVENT, BookID);

	return 1;
}

THUMB16
NEWCODE int pg_DataBrowser_Recycler_PreviousEvent(void *data, BOOK *book)
{
	BookObj_ReturnPage(book, 0);
	return 1;
}

// clang-format off

static const PAGE_MSG evtlst_DataBrowser_Recycler_Page[] = 
{
    PAGE_ENTER_EVENT, pg_DataBrowser_Recycler_EnterEvent,
    ACCEPT_EVENT, pg_DataBrowser_Recycler_AcceptEvent,
    PREVIOUS_EVENT, pg_DataBrowser_Recycler_PreviousEvent,
    NIL_EVENT, NULL
};

static const PAGE_DESC DataBrowser_Recycler_Page = 
{
    RECYCLER_PAGE_NAME, NULL, evtlst_DataBrowser_Recycler_Page
};

// clang-format on

THUMB16
NEWCODE void OpenRecycler(BOOK *book, GUI *gui)
{
	BookObj_GotoPage(book, &DataBrowser_Recycler_Page);
}

THUMB16
NEWCODE void Question_OnYes(BOOK *book, GUI *gui)
{
	RECYCLER_DATA *data = GetEnvData();
	data->state = FALSE;
	FREE_GUI(gui);
	MessageBox_NoImage(EMPTY_TEXTID, STR(TEXT_DELETE_PERMANENT), 1, 2000, NULL);
}

THUMB16
NEWCODE void Question_OnNo(BOOK *book, GUI *gui)
{
	RECYCLER_DATA *data = GetEnvData();
	data->state = TRUE;
	FREE_GUI(gui);
}

THUMB16
NEWCODE void CreateConfirmationWindow(BOOK *book, GUI *gui)
{
	BrowserItemBook *itembook = (BrowserItemBook *)book;
	gui = CreateYesNoQuestion(&itembook->book, UIDisplay_Main);

	RECYCLER_DATA *data = GetEnvData();
	if (!data->is_marked)
	{
		wchar_t *fname = FILEITEM_GetFname(itembook->sub_exec->file_item);
		YesNoQuestion_SetDescriptionText(gui, TextID_Create(fname, ENC_UCS2, TEXTID_ANY_LEN));
		YesNoQuestion_SetQuestionText(gui, STR(TEXT_DELETE_FILES));
	}
	else
		YesNoQuestion_SetQuestionText(gui, STR(TEXT_DELETE_MARKED));

	GUIObject_SoftKeys_SetAction(gui, ACTION_YES, Question_OnYes);
	GUIObject_SoftKeys_SetAction(gui, ACTION_NO, Question_OnNo);
	GUIObject_Show(gui);
}

THUMB16
NEWCODE void Set_New_SoftKeys(GUI *gui, int mode, BOOL is_marked)
{
	RECYCLER_DATA *data = GetEnvData();
	data->is_marked = is_marked;
	if (!mode)
	{
		data->state = TRUE;
		GUIObject_SoftKeys_SetAction(gui, 1, CreateConfirmationWindow);
		GUIObject_SoftKeys_SetItemOnKey(gui, 1, KEY_STAR, KBD_SHORT_PRESS);
	}
	GUIObject_SoftKeys_SetAction(gui, 2, OpenRecycler);
	GUIObject_SoftKeys_SetItemOnKey(gui, 2, KEY_DIEZ, KBD_SHORT_PRESS);
}

THUMB16
NEWCODE void New_FileDelete(const wchar_t *src_path, const wchar_t *src_name, int *error)
{
	RECYCLER_DATA *data = GetEnvData();
	if (data->state)
	{
		FILEITEM *fi = (FILEITEM *)malloc(sizeof(FILEITEM));
		memset(fi, 0, sizeof(FILEITEM));

		FILEITEM_SetPath(fi, GetRecyclerPath());
		FILEITEM_SetFnameAndContentType(fi, src_name);

		if (DataBrowser_ItemDesc_CheckFileToCopyMove(fi))
		{
			wchar_t *dst_name = FILEITEM_GetFname(fi);
			wchar_t *dst_path = FILEITEM_GetPath(fi);
			FileMove(src_path, src_name, dst_path, dst_name, error);
			UI_Event_toBookID(DB_UPDATE_EVENT, BookObj_GetBookID(MainDisplay_GetTopBook()));
		}

		mfree(fi);
	}
	else
		FileDelete(src_path, src_name, error);
}
