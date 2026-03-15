#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <elf_int.h>

#include <book/AudioPlayerBook.h>

#include <classes/IPlaylist.h>

#include "data.h"
#include "patch.h"
#include "edit_tag.h"

static const char ELFPACK_DATA[] = "elfpackdata";
static const char NO_ELFPACK[] = "Elfloader is not installed";
static const char ELF_NOT_FOUND[] = "MusicTagger.elf / TagEditor.elf not found";
static const char GET_ITEM_FAILED[] = "Failed to alloc playlist item";

static const wchar_t MTAGGER_ELF[] = L"MusicTagger.elf";
static const wchar_t TAGEDIT_ELF[] = L"TagEditor.elf";
static const wchar_t ZBIN_PATH[] = _ZBIN_PATH;
static const wchar_t MTAGGER_PATH[] = _MTAGGER_PATH;
static const wchar_t TAGEDIT_PATH[] = _TAGEDIT_PATH;

THUMB16
NEWCODE void tagedit_start_elf(BOOK *book, GUI *gui)
{
	if (!get_envp(get_bid(current_process()), ELFPACK_DATA))
	{
		MessageBox_NoImage(EMPTY_TEXTID, STR(NO_ELFPACK), 0, 1500, NULL);
		return;
	}

	AudioPlayerBook *audio_book = (AudioPlayerBook *)book;
	PLAYLIST_ITEM *item = (PLAYLIST_ITEM *)malloc(sizeof(PLAYLIST_ITEM));
	if (!item)
	{
		MessageBox_NoImage(EMPTY_TEXTID, STR(GET_ITEM_FAILED), 0, 1500, NULL);
		return;
	}

	if (Playlist_GetItem((IPlaylist *)audio_book->pIPlaylist,
	                     audio_book->playlist_id,
	                     audio_book->selected_track_id,
	                     item) >= 0)
	{
		if (_FSX_IsFileExists(ZBIN_PATH, MTAGGER_ELF))
			elfload_int(MTAGGER_PATH, (void *)item->fpath, (void *)item->fname, NULL);
		else if (_FSX_IsFileExists(ZBIN_PATH, TAGEDIT_ELF))
			elfload_int(TAGEDIT_PATH, (void *)item->fpath, (void *)item->fname, NULL);
		else
			MessageBox_NoImage(EMPTY_TEXTID, STR(ELF_NOT_FOUND), 0, 1500, NULL);
	}
	mfree(item);
}
