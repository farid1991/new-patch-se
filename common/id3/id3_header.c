#include <base.h>

#include "id3.h"

static inline int get_frame_sync(uint32_t header)
{
	return (header >> 21);
}

static inline int get_bitrate_index(uint32_t header)
{
	return (header >> 12) & 15;
}

static inline int get_frequency_index(uint32_t header)
{
	return (header >> 10) & 3;
}

static inline int get_layer(uint32_t header)
{
	return (header >> 17) & 3;
}

static inline int get_mode_index(uint32_t header)
{
	return (header >> 6) & 3;
}

static inline int get_version_id(uint32_t header)
{
	return (header >> 19) & 3;
}

THUMB16
NEWCODE BOOL is_valid_id3_header(uint32_t header)
{
	return get_frame_sync(header) == 0x7FF && // Frame sync (first 11 bits must be 0x7FF)
	       get_version_id(header) != 1 &&     // Version ID cannot be reserved (1)
	       get_layer(header) != 0 &&          // Layer cannot be 0 (invalid layer)
	       get_bitrate_index(header) != 15 && // Bitrate index cannot be 15 (invalid bitrate)
	       get_frequency_index(header) != 3;  // Frequency index cannot be 3 (invalid frequency)
}

THUMB16
NEWCODE uint32_t get_header(uint8_t *mp3_data)
{
	return ((mp3_data[0] << 24) | (mp3_data[1] << 16) | (mp3_data[2] << 8) | mp3_data[3]);
}

THUMB16
NEWCODE int get_bitrate(uint32_t header)
{
	int version_id = get_version_id(header);       // MPEG version ID
	int layer = get_layer(header);                 // Layer description
	int bitrate_index = get_bitrate_index(header); // Bitrate index
	int version_index = (version_id == 3) ? 1 : 0; // MPEG-1 is index 1, MPEG-2/2.5 is index 0

	return BITRATE_SCALE * bitrate_table[version_index][layer - 1][bitrate_index];
}

THUMB16
NEWCODE int get_frequency(uint32_t header)
{
	int version_id = get_version_id(header);           // MPEG version ID
	int frequency_index = get_frequency_index(header); // Frequency index
	int version_index = (version_id == 3) ? 3 : (version_id == 2) ? 2 : 0;
	return frequency_table[version_index][frequency_index];
}

THUMB16
NEWCODE const char *get_mode(uint32_t header)
{
	const char *mode[4] = {STEREO, J_STEREO, D_CHANNEL, S_CHANNEL};
	return mode[get_mode_index(header)];
}
