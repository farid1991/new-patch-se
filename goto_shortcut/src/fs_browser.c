#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include <types/UIRichText_types.h>

#include "patch.h"
#include "editor.h"
#include "fs_browser.h"
#include "wstr_helper.h"

static const char EMP_FLIST[] = "FL_EMP";

static const wchar_t ROOT_DIR[] = L"/";
static const wchar_t IFS_DIR[] = L"ifs";
static const wchar_t PREV_DIR[] = L"...";
static const wchar_t FMT_DIR[] = L"/%ls";

THUMB16
NEWCODE BOOL IsDirectory(const wchar_t *name)
{
	W_FSTAT fs;
	if (w_fstat(name, &fs) != -1)
		return fs.attr & FSX_O_CHKPATH;

	return FALSE;
}

THUMB16
NEWCODE void Free_FLIST(GotoShortcut_Book *mbk)
{
	FILELIST *flist = mbk->fltop;
	mbk->fltop = NULL;

	while (flist)
	{
		FILELIST *next = flist->next;

		mfree(flist->fullpath);
		mfree(flist->str_name);
		mfree(flist);

		flist = next;
	}
}

THUMB16
NEWCODE FILELIST *AddToFList(GotoShortcut_Book *mbk, const wchar_t *full_name, const wchar_t *name, BOOL is_folder)
{
	FILELIST *fl_next = malloc(sizeof(FILELIST));
	if (!fl_next)
		return NULL;

	memset(fl_next, 0, sizeof(FILELIST));

	fl_next->fullpath = WStringAlloc(wstrlen(full_name) + 1);
	fl_next->str_name = WStringAlloc(wstrlen(name) + 1);

	if (!fl_next->fullpath || !fl_next->str_name)
		return NULL;

	wstrcpy(fl_next->fullpath, full_name);
	wstrcpy(fl_next->str_name, name);

	fl_next->is_folder = is_folder;

	FILELIST *cur = mbk->fltop;
	FILELIST *prev = NULL;

	while (cur && wstrcmpi(cur->str_name, fl_next->str_name) < 0)
	{
		prev = cur;
		cur = cur->next;
	}

	fl_next->next = cur;

	if (prev)
		prev->next = fl_next;
	else
		mbk->fltop = fl_next;

	return fl_next;
}

// type == 0 SelectFolder, type == 1 SelectFile
THUMB16
NEWCODE int FindFiles(GotoShortcut_Book *mbk, const wchar_t *fpath, int type)
{
	int count = 0;

	Free_FLIST(mbk);

	wchar_t *fullpath = WStringAlloc(MAX_PATH_LEN + 1);
	wchar_t *fname = WStringAlloc(MAX_PATH_LEN + 1);

	if (!fullpath || !fname)
		return 0;

	wchar_t *rev = NULL;
	wchar_t *d = fname;
	const wchar_t *s = fpath;
	int c;

	while ((c = *s++))
	{
		*d = c;
		if (c == '/' && *s != '\0')
			rev = d;
		d++;
	}
	*d = 0;

	if (rev)
	{
		if (rev == fname)
			*(rev + 1) = 0;
		else
			*rev = 0;

		AddToFList(mbk, fname, PREV_DIR, ITEM_PREV);
		count++;
	}

	void *dir = w_diropen(fpath);
	if (dir)
	{
		wchar_t *next;

		w_chdir(fpath);

		while ((next = w_dirread(dir)))
		{
			int i = wstrlen(fpath);

			wstrcpy(fullpath, fpath);

			if (rev)
				fullpath[i++] = '/';

			fullpath[i] = 0;

			wstrcpy(fullpath + i, next);

			if (IsDirectory(next))
			{
				if (!wstrncmp(next, IFS_DIR, 3))
				{
					wstrnupr(fullpath, wstrlen(fullpath));
					wstrnupr(next, wstrlen(next));
				}

				snwprintf(fname, MAX_PATH_LEN, FMT_DIR, next);

				AddToFList(mbk, fullpath, fname, ITEM_FOLDER);
				count++;
			}
		}

		w_dirclose(dir);
	}

	mfree(fname);
	mfree(fullpath);

	return count;
}

THUMB16
NEWCODE FILELIST *FindFLISTtByNS(GotoShortcut_Book *mbk, int *i, int type)
{
	FILELIST *flist = (FILELIST *)mbk->fltop;

	while (flist)
	{
		if (flist->is_folder == type)
		{
			if (!(*i))
				return flist;
			(*i)--;
		}
		flist = (FILELIST *)flist->next;
	}
	return flist;
}

THUMB16
NEWCODE FILELIST *FindFLISTtByN(GotoShortcut_Book *mbk, int n)
{
	FILELIST *flist;
	flist = FindFLISTtByNS(mbk, &n, ITEM_PREV);

	if (!n && flist)
		return flist;

	flist = FindFLISTtByNS(mbk, &n, ITEM_FOLDER);
	if (!n && flist)
		return flist;

	flist = FindFLISTtByNS(mbk, &n, ITEM_FILE);

	if (!n && flist)
		return flist;

	return flist;
}

THUMB16
NEWCODE int FsBrowser_OnMessage(GUI_MESSAGE *msg)
{
	switch (GUIonMessage_GetMsg(msg))
	{
	case LISTMSG_GetItem:
		int index = GUIonMessage_GetCreatedItemIndex(msg);
		GotoShortcut_Book *mbk = (GotoShortcut_Book *)GUIonMessage_GetBook(msg);

		FILELIST *flist = FindFLISTtByN(mbk, index);
		TEXTID textid = WSTR(flist->str_name);
		GUIonMessage_SetMenuItemText(msg, textid);

		if (wstrcmp(flist->str_name, PREV_DIR))
			GUIonMessage_SetMenuItemIcon(msg, AlignLeft, TypesIcons[TYPE_FOLDER]);

		break;
	}
	return 1;
};

THUMB16
NEWCODE void FsBrowser_OnBackPressed(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	Free_FLIST(mbk);
	FREE_GUI(mbk->FSBrowser);
}

THUMB16
NEWCODE void FsBrowser_OnOpenPressed(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	int selected = ListMenu_GetSelectedItem(mbk->FSBrowser);
	FILELIST *flist = FindFLISTtByN(mbk, selected);
	if (!flist)
		return;

	if (flist->is_folder == ITEM_FOLDER || flist->is_folder == ITEM_PREV)
	{
		wchar_t fpath[MAX_PATH_LEN + 1];
		memset(&fpath, 0, MAX_PATH_LEN + 1);
		wstrcpy(fpath, flist->fullpath);

		Free_FLIST(mbk);
		FREE_GUI(mbk->FSBrowser);
		mbk->FSBrowser = Create_FsBrowser(&mbk->book, fpath);
	}
	else
	{
		TEXTID textid = WSTR(flist->fullpath);

#if defined(DB2000) || defined(DB2010)
		StringInput_DispObject_SetText(GUIObject_GetDispObject(mbk->FolderInput), textid);
#else
		StringInput_SetText(mbk->FolderInput, textid);
#endif

		Free_FLIST(mbk);
		FREE_GUI(mbk->FSBrowser);
	}
}

THUMB16
NEWCODE void FsBrowser_OnSelectPressed(BOOK *book, GUI *gui)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;
	int item = ListMenu_GetSelectedItem(mbk->FSBrowser);

	FILELIST *flist = FindFLISTtByN(mbk, item);
	if (!flist)
		return;

	if ((flist->is_folder == ITEM_FOLDER && mbk->FType == SEL_FOLDER) || flist->is_folder == ITEM_FILE)
	{
		TEXTID textid = WSTR(flist->fullpath);
#if defined(DB2000) || defined(DB2010)
		StringInput_DispObject_SetText(GUIObject_GetDispObject(mbk->FolderInput), textid);
#else
		StringInput_SetText(mbk->FolderInput, textid);
#endif
		Free_FLIST(mbk);
		FREE_GUI(mbk->FSBrowser);
	}
}

THUMB16
NEWCODE GUI_LIST *Create_FsBrowser(BOOK *book, wchar_t *path)
{
	GotoShortcut_Book *mbk = (GotoShortcut_Book *)book;

	wchar_t *wstr = WStringAlloc(MAX_PATH_LEN + 1);
	if (!wstr)
		return NULL;

	wstrcpy(wstr, path);

	int found = 0;
	wchar_t *s;

	do
	{
		if (IsDirectory(wstr))
		{
			found = 1;
			break;
		}

		s = wstrrchr(wstr, L'/');

		if (!s || s == wstr)
			break;

		*s = 0;

	} while (1);

	if (!found)
		wstrcpy(wstr, ROOT_DIR);

	int count = FindFiles(mbk, wstr, mbk->FType);

	GUI_LIST *f_list_gui = CreateListMenu(&mbk->book, UIDisplay_Main);
	GUIObject_SetTitleText(f_list_gui, WSTR(wstr));
	ListMenu_SetItemCount(f_list_gui, count);
	ListMenu_SetCursorToItem(f_list_gui, ITEM_PREV);
	ListMenu_SetOnMessage(f_list_gui, FsBrowser_OnMessage);

	GUIObject_SoftKeys_SetText(f_list_gui, 0, SELECT_TXT);
	GUIObject_SoftKeys_SetAction(f_list_gui, 0, FsBrowser_OnSelectPressed);

	GUIObject_SoftKeys_SetText(f_list_gui, ACTION_SELECT1, OPEN_TXT);
	GUIObject_SoftKeys_SetAction(f_list_gui, ACTION_SELECT1, FsBrowser_OnOpenPressed);
	GUIObject_SoftKeys_SetAction(f_list_gui, ACTION_BACK, FsBrowser_OnBackPressed);

	GUIObject_Show(f_list_gui);

	mfree(wstr);
	return f_list_gui;
}
