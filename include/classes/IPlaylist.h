
#ifndef _IPLAYLIST_MANAGER_H_
#define _IPLAYLIST_MANAGER_H_

#include <base.h>

typedef struct PLAYLIST_ITEM
{
	wchar_t artist[31];
	wchar_t title[31];
	wchar_t album[31];
	wchar_t fpath[252];
	wchar_t fname[252];
	uint16_t unk_4AA;
	uint32_t unk_4AC;
	uint8_t unk_4B0[0xC];
} PLAYLIST_ITEM;

// clang-format off
#ifdef __cplusplus
#include <classes/IUnknown.h>

class IPlaylist : public IUnknown
{
public:
	virtual int unk_0x10();
	virtual int unk_0x14();
	virtual int unk_0x18();
	virtual int unk_0x1C();
	virtual int unk_0x20();
	virtual int GetName(int playlist_id, int playlist_index, wchar_t *playlist_name);
	virtual int unk_0x28();
	virtual int Update(int _null0, int _event, int _null1, int playlist_id);
	virtual int unk_0x30();
	virtual int unk_0x34();
	virtual int Rename(int _null0, int _event, int _null1, int playlist_id, wchar_t *new_name);
	virtual int unk_0x3C();
	virtual int unk_0x40();
	virtual int unk_0x44();
	virtual int unk_0x48();
	virtual int unk_0x4C();
	virtual int unk_0x50();
	virtual int unk_0x54();
	virtual int unk_0x58();
	virtual int unk_0x5C();
	virtual int unk_0x60();
	virtual int unk_0x64();
	virtual int unk_0x68();
	virtual int unk_0x6C();
	virtual int unk_0x70();
	virtual int Add(int _null0, int _event, int _null1, int playlist_id, wchar_t *playlist_name);
	virtual int unk_0x78();
	virtual int unk_0x7C();
	virtual int unk_0x80();
	virtual int unk_0x84();
#ifdef DB2020
	virtual int unk_0x88();
	virtual int unk_0x8C();
	virtual int unk_0x90();
	virtual int unk_0x94();
	virtual int GetItem(int playlist_id, int selected_track_id, PLAYLIST_ITEM *item);
#else
	virtual int GetItem(int playlist_id, int selected_track_id, PLAYLIST_ITEM *item);
	virtual int unk_0x8C();
	virtual int unk_0x90();
	virtual int unk_0x94();
	virtual int unk_0x98();
	virtual int unk_0x9C();
	virtual int GetItemCount(int playlist_id, int *counts);
	virtual int SortItem(int _null0, int _unk16d0, int _null1, int playlist_id, int sort_by, int current_track_id);
	virtual int unk_0xA8();
	virtual int unk_0xAC();
	virtual int unk_0xB0();
	virtual int unk_0xB4();
#endif
};

class IPlaylistManager : public IUnknown
{
public:
	virtual int CreatePlaylist(IPlaylist **ppIPlaylist);
};

#else

typedef struct IPlaylist IPlaylist;
typedef struct IPlaylistVtbl IPlaylistVtbl;

struct IPlaylistVtbl
{
	/* IUnknown */
	void *(*pguid)(IPlaylist *self);
	void *(*QueryInterface)(IPlaylist *self, PUUID iid, void **pInterface);
	void *(*AddRef)(IPlaylist *self);
	void *(*Release)(IPlaylist *self);

	/* IPlaylist */
	int (*unk_0x10)(IPlaylist *self);
	int (*unk_0x14)(IPlaylist *self);
	int (*unk_0x18)(IPlaylist *self);
	int (*unk_0x1C)(IPlaylist *self);
	int (*unk_0x20)(IPlaylist *self);
	int (*GetName)(IPlaylist *self, int playlist_id, int playlist_index, wchar_t *playlist_name);
	int (*unk_0x28)(IPlaylist *self);
	int (*Update)(IPlaylist *self, int _null0, int _event, int _null1, int playlist_id);
	int (*unk_0x30)(IPlaylist *self);
	int (*unk_0x34)(IPlaylist *self);
	int (*Rename)(IPlaylist *self, int _null0, int _event, int _null1, int playlist_id, wchar_t *new_name);
	int (*unk_0x3C)(IPlaylist *self);
	int (*unk_0x40)(IPlaylist *self);
	int (*unk_0x44)(IPlaylist *self);
	int (*unk_0x48)(IPlaylist *self);
	int (*unk_0x4C)(IPlaylist *self);
	int (*unk_0x50)(IPlaylist *self);
	int (*unk_0x54)(IPlaylist *self);
	int (*unk_0x58)(IPlaylist *self);
	int (*unk_0x5C)(IPlaylist *self);
	int (*unk_0x60)(IPlaylist *self);
	int (*unk_0x64)(IPlaylist *self);
	int (*unk_0x68)(IPlaylist *self);
	int (*unk_0x6C)(IPlaylist *self);
	int (*unk_0x70)(IPlaylist *self);
	int (*Add)(IPlaylist *self, int _null0, int _event, int _null1, int playlist_id, wchar_t *playlist_name);
	int (*unk_0x78)(IPlaylist *self);
	int (*unk_0x7C)(IPlaylist *self);
	int (*unk_0x80)(IPlaylist *self);
	int (*unk_0x84)(IPlaylist *self);
#ifdef DB2020
	int (*unk_0x88)(IPlaylist *self);
	int (*unk_0x8C)(IPlaylist *self);
	int (*unk_0x90)(IPlaylist *self);
	int (*unk_0x94)(IPlaylist *self);
	int (*GetItem)(IPlaylist *self, int playlist_id, int selected_track_id, PLAYLIST_ITEM *item);
#else
	int (*GetItem)(IPlaylist *self, int playlist_id, int selected_track_id, PLAYLIST_ITEM *item);
	int (*unk_0x8C)(IPlaylist *self);
	int (*unk_0x90)(IPlaylist *self);
	int (*unk_0x94)(IPlaylist *self);
	int (*unk_0x98)(IPlaylist *self);
	int (*unk_0x9C)(IPlaylist *self);
	int (*GetItemCount)(IPlaylist *self, int playlist_id, int *counts);
	int (*SortItem)(IPlaylist *self,
	                int _null0,
	                int _unk16d0,
	                int _null1,
	                int playlist_id,
	                int sort_by,
	                int current_track_id);
	int (*unk_0xA8)(IPlaylist *self);
	int (*unk_0xAC)(IPlaylist *self);
	int (*unk_0xB0)(IPlaylist *self);
	int (*unk_0xB4)(IPlaylist *self);
#endif
};

struct IPlaylist
{
	const IPlaylistVtbl *lpVtbl;
};
#endif

#define Playlist_GetName(p, a, b, c) \
    ((p)->lpVtbl->GetName((p), (a), (b), (c)))

#define Playlist_Update(p, a, b, c, d) \
    ((p)->lpVtbl->Update((p), (a), (b), (c), (d)))

#define Playlist_Rename(p, a, b, c, d, e) \
    ((p)->lpVtbl->Rename((p), (a), (b), (c), (d), (e)))

#define Playlist_Add(p, a, b, c, d, e) \
    ((p)->lpVtbl->Add((p), (a), (b), (c), (d), (e)))

#define Playlist_GetItem(p, a, b, c) \
    ((p)->lpVtbl->GetItem((p), (a), (b), (c)))

// clang-format on

#endif // _IPLAYLIST_MANAGER_H_
