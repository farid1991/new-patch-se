#ifndef _IMETADATA_H_
#define _IMETADATA_H_

#include <base.h>

// const UUID CID_CMetaData = {0x0B, 0xCD, 0x95, 0x0F, 0x9F, 0xB6, 0x4E, 0x7A, 0xA7, 0xCD, 0xCA, 0x1D, 0x87, 0xBA, 0x9A, 0x27};
// const UUID IID_IMetaData = {0xB1, 0xEB, 0x4F, 0x97, 0xB0, 0xDD, 0x42, 0x09, 0xB6, 0x96, 0xCE, 0x11, 0x2D, 0x5E, 0xD8, 0xE8};

#ifndef METADATA_H
#define METADATA_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct IMetaData IMetaData;

typedef struct COVER_INFO_DESC
{
	char cover_type;
	int size;
	int cover_offset;
} COVER_INFO_DESC;

typedef enum
{
	TMetadataTagId_Artist,
	TMetadataTagId_Title,
	TMetadataTagId_Album,
	TMetadataTagId_Year,
	TMetadataTagId_Genre,
	TMetadataTagId_x6,
	TMetadataTagId_x7,
} TMetadata_TagId;

typedef struct METADATA_DESC
{
	wchar_t artist[0x100];
	wchar_t title[0x100];
	wchar_t album[0x100];
	wchar_t year[0x100];
	wchar_t genre[0x100];
	wchar_t x6[0x100];
	wchar_t x7[0x100];
	IMetaData *pIMetaData;
} METADATA_DESC;

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus

#include <classes/IUnknown.h>

// clang-format off
class IMetaData : public IUnknown
{
public:
    virtual int SetFile(wchar_t *path, wchar_t *name);
    virtual int unk_0x14(void *unk1, void *unk2);
    virtual int GetTag(int tagID, wchar_t *tag);
    virtual int GetTrackNum(int unk, int *track_num);
    virtual int GetCoverInfo(COVER_INFO_DESC *cover_info);
    virtual int unk_0x24();
    virtual int unk_0x28();
    virtual int unk_0x2C();
    virtual int HasAlbumArt(wchar_t *path, wchar_t *name);
};
// clang-format on

#else /* ================= C version ================= */

struct IMetaData;

typedef struct IMetaDataVtbl
{
	/* IUnknown */
	void *(*pguid)(struct IMetaData *);
	void *(*QueryInterface)(struct IMetaData *, void *, void **);
	void *(*AddRef)(struct IMetaData *);
	void *(*Release)(struct IMetaData *);

	/* IMetaData */
	int (*SetFile)(struct IMetaData *, wchar_t *, wchar_t *);
	int (*unk_0x14)(struct IMetaData *, void *, void *);
	int (*GetTag)(struct IMetaData *, int, wchar_t *);
	int (*GetTrackNum)(struct IMetaData *, int, int *);
	int (*GetCoverInfo)(struct IMetaData *, COVER_INFO_DESC *);
	int (*unk_0x24)(struct IMetaData *);
	int (*unk_0x28)(struct IMetaData *);
	int (*unk_0x2C)(struct IMetaData *);
	int (*HasAlbumArt)(struct IMetaData *, wchar_t *, wchar_t *);

} IMetaDataVtbl;

typedef struct IMetaData
{
	const IMetaDataVtbl *lpVtbl;
} IMetaData;

#endif /* __cplusplus */

#endif /* METADATA_H */
#endif
