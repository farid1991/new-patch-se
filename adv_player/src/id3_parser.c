#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <id3.h>

#include <types/MusicServer_types.h>

#include "data.h"
#include "id3_parser.h"
#include "image.h"
#include "patch.h"

static const wchar_t COVERNAME_FMT[] = L"%ls_%ls.coverart.%ls";
static const char COVER_SAVED[] = "Saved";
static const char COVER_FAILED[] = "Failed";

THUMB16
NEWCODE uint32_t int_decode(uint8_t *bytes, int size, int offset)
{
	uint32_t result = 0x00;
	int i = 0;
	for (i = 0; i < size; i++)
	{
		result = result << 8;
		result = result | (uint8_t)bytes[offset + i];
	}

	return result;
}

THUMB16
NEWCODE uint32_t synch_decode(uint32_t value)
{
	uint32_t a, b, c, d, result = 0x0;
	a = (value >> 0) & 0xFF;
	b = (value >> 8) & 0xFF;
	c = (value >> 16) & 0xFF;
	d = (value >> 24) & 0xFF;

	result = result | (a << 0);
	result = result | (b << 7);
	result = result | (c << 14);
	result = result | (d << 21);

	return result;
}

THUMB16
NEWCODE uint32_t id3v2_get_header(const wchar_t *path, const wchar_t *name)
{
	int mp3_f = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (mp3_f != -1)
	{
		uint8_t header_buf[ID3V2_HEADER_SIZE];
		fread(mp3_f, header_buf, ID3V2_HEADER_SIZE);

		if (memcmp(header_buf, ID3V2_MAGIC, sizeof(ID3V2_MAGIC)) != 0)
		{
			fclose(mp3_f);
			return 0;
		}

		uint8_t version = header_buf[3];
		if (version == ID3V2_3 || version == ID3V2_4)
		{
			uint32_t tag_size = synch_decode(int_decode(header_buf, 4, 6));

			lseek(mp3_f, tag_size + ID3V2_HEADER_SIZE, FSX_SEEK_SET);

			uint8_t frame_header[ID3V2_FRAME_SIZE];
			fread(mp3_f, frame_header, ID3V2_FRAME_SIZE);
			fclose(mp3_f);

			uint32_t header = get_header(frame_header);
			if (is_valid_id3_header(header))
				return header;
		}
	}
	return NULL;
}

THUMB16
NEWCODE uint8_t *id3v2_tag_get(const wchar_t *path, const wchar_t *name, size_t *tag_size, int *version)
{
	int mp3_f = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (mp3_f != -1)
	{
		uint8_t header[ID3V2_HEADER_SIZE];
		fread(mp3_f, header, ID3V2_HEADER_SIZE);

		if (!memcmp(header, ID3V2_MAGIC, sizeof(ID3V2_MAGIC)))
		{
			*version = header[3];
			if (*version == ID3V2_3 || *version == ID3V2_4)
			{
				*tag_size = synch_decode(int_decode(header, 4, 6));

				uint8_t *tag_buffer = (uint8_t *)malloc(*tag_size);
				fread(mp3_f, tag_buffer, *tag_size);
				fclose(mp3_f);

				return tag_buffer;
			}
		}
		fclose(mp3_f);
	}
	return NULL;
}

#ifdef DB2010
static const char MIMETYPE_JPG[] = "image/jpg";
#endif

THUMB16
NEWCODE uint8_t *id3v2_apic_frame_get(const wchar_t *path, const wchar_t *name, uint8_t *cover_type, size_t *cover_size)
{
	size_t tag_size;
	int version;
	uint8_t *tag_buffer = id3v2_tag_get(path, name, &tag_size, &version);
	if (!tag_buffer)
		return NULL;

	int cur_pos = 0;
	bool has_cover_art = FALSE;
	while (cur_pos < (tag_size - 4))
	{
		if (tag_buffer[cur_pos + 0] == 'A' && tag_buffer[cur_pos + 1] == 'P' &&
		    tag_buffer[cur_pos + 2] == 'I' && tag_buffer[cur_pos + 3] == 'C')
		{
			has_cover_art = TRUE;
			break;
		}
		cur_pos++;
	}
	cur_pos += ID3V2_FRAME_ID_SIZE;

	if (!has_cover_art)
	{
		mfree(tag_buffer);
		return NULL;
	}

	int frame_size = int_decode(tag_buffer, 4, cur_pos);
	if (version == ID3V2_4)
		frame_size = synch_decode(frame_size);

	cur_pos += ID3V2_FRAME_SIZE;

	// skip flag
	cur_pos += ID3V2_FRAME_FLAGS_SIZE;

	// get mime type
	int mime_len = 0;
	while (tag_buffer[(cur_pos + mime_len)] != '\0')
	{
		mime_len++;
	}
	char mime[11];
	memset(mime, 0, 11);
	memcpy(mime, tag_buffer + cur_pos, mime_len);
	cur_pos += mime_len;

	// convert mime type to cover type
	if (!strcmp(MIMETYPE_BMP, mime))
		*cover_type = TMusicServer_AlbumArt_ImageType_Bmp;
	else if (!strcmp(MIMETYPE_GIF, mime))
		*cover_type = TMusicServer_AlbumArt_ImageType_Gif;
	else if (!strcmp(MIMETYPE_PNG, mime))
		*cover_type = TMusicServer_AlbumArt_ImageType_Png;
	else if ((!strcmp(MIMETYPE_JPG, mime)) || (!strcmp(MIMETYPE_JPEG, mime)))
		*cover_type = TMusicServer_AlbumArt_ImageType_Jpeg;

	// skip picture type
	cur_pos++;

	// skip description
	int offset = 0;
	while (tag_buffer[(cur_pos + offset)] != '\0')
	{
		offset++;
	}
	// description should be at least 1 byte (null terminator)
	if (offset == 0)
		offset++;

	cur_pos += offset;

	// remove any 0x00 bytes before image
	while (tag_buffer[cur_pos] == 0x00)
	{
		cur_pos++;
	}

	*cover_size = frame_size - mime_len - offset;
	uint8_t *cover_art = (uint8_t *)malloc(*cover_size);
	if (!cover_art)
		return NULL;

	memset(cover_art, 0, *cover_size);
	memcpy(cover_art, tag_buffer + cur_pos, *cover_size);
	mfree(tag_buffer);

	return cover_art;
}

THUMB16
NEWCODE bool id3v2_extract_coverart(PLAYLIST_ITEM *item)
{
	uint8_t cover_type;
	size_t cover_size;
	uint8_t *cover_art = id3v2_apic_frame_get(item->fpath, item->fname, &cover_type, &cover_size);

	wchar_t cover_name[128];
	snwprintf(cover_name,
	          MAXELEMS(cover_name),
	          COVERNAME_FMT,
	          item->artist,
	          item->album,
	          id3_cover_gettype(cover_type));

	if (_FSX_IsFileExists(item->fpath, cover_name))
		FileDelete(item->fpath, cover_name, NULL);

	if (cover_art)
	{
		int out_f = _fopen(item->fpath, cover_name, FSX_O_WRONLY, FSX_S_IWRITE, NULL);
		if (out_f != -1)
		{
			fwrite(out_f, cover_art, cover_size);
			fclose(out_f);
		}

		IMAGEID image_id;
		ImageID_GetIndirect(cover_art, cover_size, 0, id3_cover_gettype(cover_type), &image_id);

		MessageBox(EMPTY_TEXTID, STR(COVER_SAVED), image_id, 0, 0, NULL);

		ImageID_Free(image_id);
		return TRUE;
	}
	MessageBox_NoImage(EMPTY_TEXTID, STR(COVER_FAILED), 0, 0, NULL);
	return FALSE;
}

THUMB16
NEWCODE bool id3v2_get_coverart(TRACK_DESC *track)
{
	ADVPLAYER_DATA *data = env_data_get();

	uint8_t cover_type;
	size_t cover_size;
	uint8_t *cover_art = id3v2_apic_frame_get(track->fpath, track->fname, &cover_type, &cover_size);

	if (cover_art)
	{
		// IMAGEID image_id;
		if (!ImageID_GetIndirect(
		            cover_art, cover_size, 0, id3_cover_gettype(cover_type), &data->cover_image.id))
		{
			// data->cover_image.id = image_id;
			data->cover_image.exist = TRUE;
			data->cover_image.handle = 0;
			data->has_coverart = TRUE;
			return TRUE;
		}
	}
	return FALSE;
}
