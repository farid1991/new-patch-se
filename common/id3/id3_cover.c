#include <base.h>
#include <types/MusicServer_types.h>

static const wchar_t JPG_EXT[] = L"jpg";
static const wchar_t GIF_EXT[] = L"gif";
static const wchar_t PNG_EXT[] = L"png";
static const wchar_t BMP_EXT[] = L"bmp";

THUMB16
NEWCODE const wchar_t *id3_cover_gettype(uint8_t cover_type)
{
	switch (cover_type)
	{
	case TMusicServer_AlbumArt_ImageType_Jpeg: return JPG_EXT;
	case TMusicServer_AlbumArt_ImageType_Gif: return GIF_EXT;
	case TMusicServer_AlbumArt_ImageType_Png: return PNG_EXT;
	case TMusicServer_AlbumArt_ImageType_Bmp: return BMP_EXT;
	default: return NULL;
	}
}
