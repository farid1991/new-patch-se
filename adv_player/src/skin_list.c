#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include "data.h"
#include "skin_list.h"

THUMB16
NEWCODE BOOL is_directory(wchar_t *path)
{
	W_FSTAT fs;
	if (w_fstat(path, &fs) == -1)
		return FALSE;
	return (fs.attr & FSX_O_CHKPATH) != 0;
}

THUMB16
NEWCODE BOOL skin_list_filter(void *elem)
{
	return (elem != NULL);
}

THUMB16
NEWCODE void skin_list_remove_elem(void *item)
{
	SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)item;
	if (skin)
	{
		mfree(skin->fname);
		mfree(skin->fpath);
		mfree(skin);
	}
}

THUMB16
NEWCODE void skin_list_destroy(LIST **list)
{
	if (*list)
	{
		List_DestroyElements(*list, skin_list_filter, skin_list_remove_elem);
		List_Destroy(*list);
		*list = 0;
	}
}

THUMB16
NEWCODE SKIN_LIST_ELEM *skin_list_create_elem(const wchar_t *skinpath, wchar_t *name)
{
	SKIN_LIST_ELEM *skin = (SKIN_LIST_ELEM *)malloc(sizeof(SKIN_LIST_ELEM));
	if (!skin)
		return NULL;

	int name_len = wstrlen(name);
	skin->fname = (wchar_t *)malloc((name_len + 1) * sizeof(wchar_t));
	if (!skin->fname)
	{
		mfree(skin);
		return NULL;
	}
	memset(skin->fname, 0, (name_len + 1) * sizeof(wchar_t));

	int path_len = wstrlen(skinpath) + name_len + 1;
	skin->fpath = (wchar_t *)malloc((path_len + 1) * sizeof(wchar_t));
	if (!skin->fpath)
	{
		mfree(skin->fname);
		mfree(skin);
		return NULL;
	}
	memset(skin->fpath, 0, (path_len + 1) * sizeof(wchar_t));

	wstrcpy(skin->fname, name);
	wstrcpy(skin->fpath, skinpath);
	wstrcat(skin->fpath, L"/");
	wstrcat(skin->fpath, name);

	return skin;
}

THUMB16
NEWCODE LIST *skin_list_create(const wchar_t *skinpath)
{
	void *dir = w_diropen(skinpath);
	if (!dir)
		return NULL;

	LIST *skin_list = List_Create();

	w_chdir(skinpath);
	wchar_t *next;
	while ((next = w_dirread(dir)))
	{
		if (is_directory(next))
		{
			SKIN_LIST_ELEM *skin = skin_list_create_elem(skinpath, next);
			if (skin)
				List_InsertLast(skin_list, skin);
		}
	}
	w_dirclose(dir);

	return skin_list;
}
