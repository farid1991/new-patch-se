#include "device.h"

#include <libse.h>
#include <id3.h>

#include "id3v2.h"

THUMB16
NEWCODE uint32_t id3_header_get_tag_size(uint8_t *data, int byte_count)
{
	uint32_t normal_size = 0;

	for (int i = 0; i < byte_count; i++)
	{
		normal_size = (normal_size << 7) | (data[i] & 0x7F);
	}

	return normal_size;
}

THUMB16
NEWCODE uint32_t id3_frame_get_size(uint8_t *data, uint32_t fpos, int version)
{
	uint32_t res = 0;
	if (version == ID3V2_4)
	{
		// ID3v2.4 uses synchsafe integers (4 bytes)
		for (int i = 0; i < 4; i++)
		{
			res = (res << 7) | (data[i + fpos] & 0x7F);
		}
	}
	else if (version == ID3V2_3)
	{
		// ID3v2.3 uses normal 4-byte integers
		for (int i = 0; i < 4; i++)
		{
			res = (res << 8) | data[i + fpos];
		}
	}
	else if (version == ID3V2_2)
	{
		// ID3v2.2 uses 3-byte integers
		for (int i = 0; i < 3; i++)
		{
			res = (res << 8) | data[i + fpos];
		}
	}
	return res;
}

THUMB16
NEWCODE uint32_t
id3v2_read_header(const wchar_t *path, const wchar_t *name, uint32_t *tagsize, uint32_t *version, uint32_t *fpos)
{
	int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file == -1)
		return 0;

	uint8_t header_buf[ID3V2_HEADER_SIZE];
	fread(file, header_buf, ID3V2_HEADER_SIZE);

	*fpos = 0;
	if (!memcmp(header_buf, ID3V2_MAGIC, sizeof(ID3V2_MAGIC)))
	{
		*version = header_buf[3];
		uint8_t flags = header_buf[5];

		if (*version == ID3V2_2)
		{
			uint8_t temp_data[ID3V2_2_BYTE] = {header_buf[6], header_buf[7], header_buf[8]};
			*tagsize = id3_header_get_tag_size(temp_data, ID3V2_2_BYTE);

			*fpos = ID3V2_HEADER_SIZE;
		}
		else if (*version == ID3V2_3 || *version == ID3V2_4)
		{
			uint8_t temp_data[ID3V2_X_BYTE] = {header_buf[6], header_buf[7], header_buf[8], header_buf[9]};
			*tagsize = id3_header_get_tag_size(temp_data, ID3V2_X_BYTE);

			*fpos = ID3V2_HEADER_SIZE;
			if (flags & 0x40)
				*fpos += ID3V2_EXTENDED_HEADER_FLAGS + ID3V2_EXTENDED_HEADER_SIZE +
				         ID3V2_EXTENDED_HEADER_PADDING_SIZE;
		}
		else
		{
			fclose(file);
			return 0;
		}

		lseek(file, *tagsize + ID3V2_HEADER_SIZE, FSX_SEEK_SET);
	}
	else
	{
		fclose(file);
		return 0;
	}

	uint8_t mp3_frame_header[ID3V2_FRAME_SIZE];
	fread(file, mp3_frame_header, ID3V2_FRAME_SIZE);
	fclose(file);

	uint32_t header = get_header(mp3_frame_header);
	if (is_valid_id3_header(header))
		return header;
	return 0;
}
