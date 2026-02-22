#if defined(C510_R1HA035)
#include "C510_R1HA035.h"
#elif defined(U10_R7AA071)
#include "U10_R7AA071.h"
#elif defined(U100_R7AA076)
#include "U100_R7AA076.h"
#endif

#include <libse.h>
#include <book/DataDownloadBook.h>

static const char EMP_NAME[] = "r_emp";
static const char MEM_NAME[] = "r_mem";
static const char DataDownload_ReplaceFile_Page_Name[] = "DataDownload_ReplaceFile_Page";

typedef struct FILE_DATA
{
    uint8_t state;
} FILE_DATA;

#define DataDownloadBook_onClose ((void (*)(BOOK *))ADDR_DataDownloadBook_onClose)

int pg_ReplaceFile_EnterEvent(void *data, BOOK *book);
int pg_ReplaceFile_ExitEvent(void *data, BOOK *book);

const PAGE_MSG evtlst_DataDownload_ReplaceFile[] =
    {
        PAGE_ENTER_EVENT, pg_ReplaceFile_EnterEvent,
        PAGE_EXIT_EVENT, pg_ReplaceFile_ExitEvent,
        NIL_EVENT, NULL};

const PAGE_DESC DataDownload_ReplaceFile_Page = {DataDownload_ReplaceFile_Page_Name, 0, evtlst_DataDownload_ReplaceFile};

THUMB16 NEWCODE void *malloc(int size)
{
#if defined(DB2020)
    return (memalloc(0, size, 1, 5, MEM_NAME, 0));
#elif defined(A2)
    return (memalloc(0xFFFFFFFF, size, 1, 5, MEM_NAME, 0));
#else
    return memalloc(size, 1, 5, MEM_NAME, 0);
#endif
}

THUMB16 NEWCODE void mfree(void *mem)
{
    if (mem)
#if defined(DB2020) || defined(A2)
        memfree(0, mem, MEM_NAME, 0);
#else
        memfree(mem, MEM_NAME, 0);
#endif
}

THUMB16 NEWCODE FILE_DATA *get_env_data()
{
    FILE_DATA *fdata = (FILE_DATA *)get_envp(NULL, EMP_NAME);
    if (!fdata)
    {
        fdata = (FILE_DATA *)malloc(sizeof(FILE_DATA));
        memset(fdata, NULL, sizeof(FILE_DATA));
        set_envp(NULL, EMP_NAME, (OSADDRESS)fdata);
    }
    return fdata;
}

THUMB16 NEWCODE void destroy_env_data()
{
    FILE_DATA *fdata = (FILE_DATA *)get_envp(NULL, EMP_NAME);
    if (fdata)
    {
        mfree(fdata);
        set_envp(NULL, EMP_NAME, (OSADDRESS)NULL);
    }
}

THUMB16 NEWCODE void pg_ReplaceFile_onYes(BOOK *book, GUI *gui)
{
    FILE_DATA *fdata = get_env_data();
    fdata->state = TRUE;

    BookObj_GotoPage(book, DataDownload_Main_Page);
}

THUMB16 NEWCODE void pg_ReplaceFile_onNo(BOOK *book, GUI *gui)
{
    BookObj_GotoPage(book, DataDownload_Main_Page);
}

THUMB16 NEWCODE int pg_ReplaceFile_EnterEvent(void *data, BOOK *book)
{
    DataDownloadBook *dl_book = (DataDownloadBook *)book;
    if (dl_book->gui = CreateYesNoQuestion(book, UIDisplay_Main))
    {
        YesNoQuestion_SetDescriptionText(dl_book->gui, DescriptionText);
        YesNoQuestion_SetQuestionText(dl_book->gui, QuestionText);
        GUIObject_SoftKeys_SetAction(dl_book->gui, YES_SOFTKEY, pg_ReplaceFile_onYes);
        GUIObject_SoftKeys_SetAction(dl_book->gui, NO_SOFTKEY, pg_ReplaceFile_onNo);
        GUIObject_Show(dl_book->gui);
    }
    return 1;
}

THUMB16 NEWCODE int pg_ReplaceFile_ExitEvent(void *data, BOOK *book)
{
    DataDownloadBook *dl_book = (DataDownloadBook *)book;
    GUIObject_Destroy(dl_book->gui);
    return 1;
}

THUMB16 NEWCODE void Patch_ReplaceFile_Page(BOOK *book)
{
    DataDownloadBook *dl_book = (DataDownloadBook *)book;

    if (FSX_IsFileExists(FILEITEM_GetPath(dl_book->fi), FILEITEM_GetFname(dl_book->fi)))
        BookObj_GotoPage(book, &DataDownload_ReplaceFile_Page);
    else
        BookObj_GotoPage(book, DataDownload_Main_Page);
}

THUMB16 NEWCODE void New_ReplaceFile(FILEITEM *fileitem)
{
    FILE_DATA *fd = get_env_data();

    if (fd->state)
        FileDelete(FILEITEM_GetPath(fileitem), FILEITEM_GetFname(fileitem), NULL);
    else
        DataBrowser_ItemDesc_CheckFileToCopyMove(fileitem);
}

THUMB16 NEWCODE void Close_DataDownloadBook(BOOK *book)
{
    destroy_env_data();
    DataDownloadBook_onClose(book);
}
