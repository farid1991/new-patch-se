#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <elf_int.h>
#include <sync.h>

#include "patch.h"
#include "utils.h"
#include "wstr_helper.h"

THUMB16
NEWCODE void Run_JavaApp_ByName(wchar_t *name)
{
	wchar_t *java_name;
	char java_dialog;
	void *java_desc;

	JavaDialog_Open(0, &java_dialog, &java_desc);

	if (!JavaAppDesc_GetFirstApp(java_desc))
	{
		int next = 0;
		while (!next)
		{
			JavaAppDesc_GetJavaAppInfo(java_desc, JAVAAPP_NAME, &java_name);
			if (!wstrcmp(java_name, name))
			{
				mfree(java_name);
				int app_id = JavaAppDesc_GetJavaAppID(java_desc);
				char err;
				REQUEST_UI_OAF_START_APPLICATION(&ASYNC, app_id + 0x10000, &err);
				break;
			}
			else
				next = JavaAppDesc_GetNextApp(java_desc);

			mfree(java_name);
		}
	}
	JavaDialog_Close(java_dialog);
}

THUMB16
NEWCODE int OpenFolder(const wchar_t *folders)
{
	BOOK *book = Display_GetTopBook(UIDisplay_Main);
	if (!book)
		return -1;

	int book_id = BookObj_GetBookID(book);

	void *db_desc = DataBrowserDesc_Create();
	if (!db_desc)
	{
		UI_Event_toBookID(PREVIOUS_EVENT, book_id);
		return 0;
	}
	const wchar_t *DIR_LIST[2];
	DIR_LIST[0] = folders;
	DIR_LIST[1] = 0;
	DataBrowserDesc_SetHeaderText(db_desc, WSTR(folders));
	DataBrowserDesc_SetBookID(db_desc, book_id);
	DataBrowserDesc_SetFolders(db_desc, DIR_LIST);
	DataBrowserDesc_SetFoldersNumber(db_desc, 1);
	DataBrowserDesc_SetSelectAction(db_desc, FALSE);
	DataBrowserDesc_Menu_AddFSFunctions(db_desc, TRUE);
	DataBrowserDesc_Menu_AddNewFolder(db_desc, TRUE);
	DataBrowserDesc_Menu_AddMarkFiles(db_desc, TRUE);
#ifndef DB2000
	DataBrowserDesc_SetOpenEmptyFolder(db_desc, TRUE);
#endif
	DataBrowserDesc_SetDefaultActions(db_desc, TRUE);

	DataBrowser_Create(db_desc);
	DataBrowserDesc_Destroy(db_desc);

	return 1;
}

THUMB16
NEWCODE void RunShortcut(SC_LIST_ELEM *ShortcutItem)
{
	switch (ShortcutItem->ScType)
	{
	case TYPE_SHORTCUT: Shortcut_Run(ShortcutItem->ScLink); break;
	case TYPE_JAVA: Run_JavaApp_ByName(ShortcutItem->ScLink); break;
	case TYPE_ELF: elfload_int(ShortcutItem->ScLink, 0, 0, 0); break;
	case TYPE_FOLDER: OpenFolder(ShortcutItem->ScLink); break;
	}
}

THUMB16
NEWCODE int list_item_filter(void *elem)
{
	return (elem != NULL);
}

THUMB16
NEWCODE void list_destroy(LIST **list, void (*list_free_elem)(void *item))
{
	if (*list)
	{
		List_DestroyElements(*list, list_item_filter, list_free_elem);
		List_Destroy(*list);
		*list = NULL;
	}
}

THUMB16
NEWCODE void java_list_free_item(void *item)
{
	JAVA_LIST_ELEM *j_elem = (JAVA_LIST_ELEM *)item;
	if (j_elem)
	{
		mfree(j_elem->name);
		mfree(j_elem->fullpath);

		if (j_elem->image_id != NOIMAGE)
			ImageID_Free(j_elem->image_id);

		mfree(j_elem);
	}
}

THUMB16
NEWCODE JAVA_LIST_ELEM *java_list_create_elem(void *java_desc)
{
	JAVA_LIST_ELEM *j_elem = (JAVA_LIST_ELEM *)malloc(sizeof(JAVA_LIST_ELEM));
	if (!j_elem)
		return NULL;

	JavaAppDesc_GetJavaAppInfo(java_desc, JAVAAPP_NAME, &j_elem->name);
	JavaAppDesc_GetJavaAppInfo(java_desc, JAVAAPP_FULLPATH, &j_elem->fullpath);
	JavaApp_LogoImageID_Get(j_elem->fullpath, &j_elem->image_id);
	return j_elem;
}

THUMB16
NEWCODE LIST *java_list_create()
{
	LIST *java_list = List_Create();

	char java_dialog;
	void *java_desc;
	wchar_t *semclet;

	JavaDialog_Open(0, &java_dialog, &java_desc);

	if (!JavaAppDesc_GetFirstApp(java_desc))
	{
		int next = 0;
		while (!next)
		{
			JavaAppDesc_GetJavaAppInfo(java_desc, JAVAAPP_SEMCLET, &semclet);
			if (semclet[0])
				List_InsertLast(java_list, java_list_create_elem(java_desc));

			mfree(semclet);
			next = JavaAppDesc_GetNextApp(java_desc);
		}
	}
	JavaDialog_Close(java_dialog);
	return java_list;
}

THUMB16
NEWCODE void SaveConfig(LIST *list)
{
	int file = _fopen(CFG_PATH, CONFIG_NAME, FSX_O_TRUNC | FSX_O_RDWR, FSX_S_IREAD | FSX_S_IWRITE, NULL);
	if (file == -1)
		return;

	int text_len = 0;
	int link_len = 0;
	uint16_t list_count = List_GetCount(list);

	fwrite(file, &list_count, sizeof(uint16_t));

	for (int i = 0; i < list_count; i++)
	{
		SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)List_Get(list, i);
		fwrite(file, &Shortcut->ScType, sizeof(char));
		link_len = wstrlen(Shortcut->ScLink);
		fwrite(file, &link_len, sizeof(int));
		fwrite(file, Shortcut->ScLink, link_len * sizeof(wchar_t));
		text_len = wstrlen(Shortcut->ScText);
		fwrite(file, &text_len, sizeof(int));
		fwrite(file, Shortcut->ScText, text_len * sizeof(wchar_t));
		fwrite(file, &Shortcut->ScIcon, sizeof(IMAGEID));
	}
	fclose(file);
}

#if defined(DB2000)
THUMB16
NEWCODE BOOL FSX_IsFileExists_(const wchar_t *fpath, const wchar_t *fname)
{
	FSTAT fs;
	return !fstat(fpath, fname, &fs);
}
#endif

THUMB16
NEWCODE LIST *LoadConfig()
{
	LIST *list = List_Create();

#if defined(DB2000)
	if (!FSX_IsFileExists_(CFG_PATH, CONFIG_NAME))
#else
	if (!FSX_IsFileExists(CFG_PATH, CONFIG_NAME))
#endif
		return list;

	int file = _fopen(CFG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
	if (file == -1)
		return list;

	int text_len = 0;
	int link_len = 0;
	uint16_t list_count;

	fread(file, &list_count, sizeof(uint16_t));

	int i = 0;
	while (i < list_count)
	{
		SC_LIST_ELEM *Shortcut = (SC_LIST_ELEM *)malloc(sizeof(SC_LIST_ELEM));
		fread(file, &Shortcut->ScType, sizeof(char));
		fread(file, &link_len, sizeof(int));
		Shortcut->ScLink = WStringAlloc(link_len + 1);
		fread(file, Shortcut->ScLink, link_len * sizeof(wchar_t));
		fread(file, &text_len, sizeof(int));
		Shortcut->ScText = WStringAlloc(text_len + 1);
		fread(file, Shortcut->ScText, text_len * sizeof(wchar_t));
		fread(file, &Shortcut->ScIcon, sizeof(IMAGEID));
		List_InsertLast(list, Shortcut);
		i++;
	}
	fclose(file);

	return list;
}
