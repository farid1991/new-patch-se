#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include <book/AudioPlayerBook.h>

#include "data.h"
#include "str_helper.h"
#include "track_desc.h"

THUMB16
NEWCODE bool track_desc_compare(TRACK_DESC *t1, TRACK_DESC *t2)
{
	if (t1 && t2)
	{
		if (!wstrcmp(t1->fpath, t2->fpath) && !wstrcmp(t1->fname, t2->fname))
			return TRUE;
	}
	return FALSE;
}

THUMB16
NEWCODE void track_desc_free(TRACK_DESC *track)
{
	if (track)
	{
		mfree(track->fpath);
		mfree(track->fname);
		mfree(track);
	}
}

THUMB16
NEWCODE TRACK_DESC *track_desc_get(AudioPlayerBook *audio_book)
{
	if (!audio_book->dsc)
		return NULL;

	TRACK_DESC *track = (TRACK_DESC *)malloc(sizeof(TRACK_DESC));
	if (!track)
		return NULL;

	wchar_t *fpath = audio_book->dsc->fpath;
	wchar_t *fname = audio_book->dsc->fname;

	int path_len = (wstrlen(fpath) + 1) * sizeof(wchar_t);
	track->fpath = (wchar_t *)malloc(path_len);
	memset(track->fpath, 0, path_len);
	wstrcpy(track->fpath, fpath);

	int name_len = (wstrlen(fname) + 1) * sizeof(wchar_t);
	track->fname = (wchar_t *)malloc(name_len);
	memset(track->fname, 0, name_len);
	wstrcpy(track->fname, fname);

	return track;
}
