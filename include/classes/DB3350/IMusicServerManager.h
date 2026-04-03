#ifndef _IMUSICSERVERMANAGER_H_
#define _IMUSICSERVERMANAGER_H_

#include <base.h>
#include <classes/IUnknown.h>
#include <types/IMMETypes.h>
#include <types/MusicServer_types.h>

// clang-format off

class IMusicServer : public IUnknown
{
public:
#if defined(DB3350_R2)
	virtual void *unk_0x10();
	virtual void *unk_0x14();
	virtual void *unk_0x18();
	virtual void *unk_0x1C();
	virtual void *unk_0x20();
	virtual void *unk_0x24();
	virtual void *unk_0x28();
	virtual void *unk_0x2C();
	virtual void *unk_0x30();
	virtual void *unk_0x34();
	virtual void *unk_0x38();
	virtual void *unk_0x3C();
	virtual void *unk_0x40();
	virtual void *unk_0x44();
	virtual void *unk_0x48();
	virtual void *unk_0x4C();
	virtual void *unk_0x50();
	virtual void *unk_0x54();
	virtual void *unk_0x58();
	virtual void *unk_0x5C();            // 0x5C
	virtual void *unk_0x60();            // 0x60
	virtual int Play(FUint32 itemIndex); // 0x64
	virtual int Pause(void);             // 0x68
	virtual int FastFoward(void);        // 0x6C                                                                                                                                                                                                                        // 0x48
	virtual int Rewind(void);            // 0x70
	virtual int Next(TBool activePress); // 0x74
	virtual int Previous(void);          // 0x78
	virtual void *unk_0x7C();
	virtual void *unk_0x80();
	virtual void *unk_0x84();
	virtual void *unk_0x88();
	virtual void *unk_0x8C();
	virtual void *unk_0x90();
	virtual int EnableEqualizer(void);
	virtual int DisableEqualizer(void);
	virtual int SetEqualizerGain(TMusicServer_EqBand band, TSigned level);
	virtual void *unk_0xA0();
	virtual void *unk_0xA4();
	virtual void *unk_0xA8();
	virtual int RemoveFromPlaylist(FUint32 itemIndex);
	virtual int SavePlayQueue(const wchar_t *name);
	virtual void *unk_0xB4();
	virtual void *unk_0xB8();
	virtual void *unk_0xBC();
#else
	virtual void *unk_0x10();
	virtual void *unk_0x14();
	virtual void *unk_0x18();
	virtual void *unk_0x1C();
	virtual void *unk_0x20();
	virtual void *unk_0x24();
	virtual void *unk_0x28();
	virtual void *unk_0x2C();
	virtual void *unk_0x30();
	virtual void *unk_0x34();
	virtual void *unk_0x38();
	virtual int GetItem(FUint32 itemIndex, FUint32 length, wchar_t *pArtist, wchar_t *pAlbum, wchar_t *pTitle);
	virtual void *unk_0x40();
	virtual void *unk_0x44();
	virtual void *unk_0x48();
	virtual void *unk_0x4C();
	virtual void *unk_0x50();
	virtual void *unk_0x54();
	virtual int GetAlbumArt(FUint32 itemIndex,
	                        FUint32 length,
	                        wchar_t *pFilename,
	                        FUint32 *Offset,
	                        FUint32 *Size,
	                        TMusicServer_AlbumArt_ImageType *pImageType,
	                        TBool *IsDRMProtected);
	virtual void *unk_0x5C();
	virtual int Play(FUint32 itemIndex); // 0x60
	virtual int Pause(void);             // 0x64
	virtual int FastFoward(void);        // 0x68
	virtual int Rewind(void);            // 0x6C
	virtual int Next(TBool activePress); // 0x70
	virtual void *unk_0x74();            // 0x74
	virtual int Previous(void);          // 0x78
	virtual void *unk_0x7C();
	virtual void *unk_0x80();
	virtual void *unk_0x84();
	virtual void *unk_0x88();
	virtual void *unk_0x8C();
	virtual int EnableEqualizer(void);
	virtual int DisableEqualizer(void);
	virtual int SetEqualizerGain(TMusicServer_EqBand band, TSigned level);
	virtual void *unk_0x9C();
	virtual void *unk_0xA0();
	virtual void *unk_0xA4();
	virtual int RemoveFromPlaylist(FUint32 itemIndex);
	virtual int SavePlayQueue(const wchar_t *name);
	virtual void *unk_0xB0();
	virtual void *unk_0xB4();
	virtual void *unk_0xB8();
	virtual void *unk_0xBC();
#endif
};

class IMusicServerManager : public IUnknown
{
public:
	virtual int CreateMusicServer(void *pICBMusicServer, IMusicServer **ppIMusicServer);
	virtual int method1();
};

// clang-format on

#endif
