#include <base.h>

#include "id3.h"

// clang-format off

// Lookup table for bitrate values (depends on version and layer)
static const uint8_t bitrate_table[2][3][16] = 
{
	{
		// MPEG 2 & 2.5
		{0, 4, 8, 12, 16, 20, 24, 28, 32, 40, 48, 56, 64, 72, 80, 0},     // Layer III
		{0, 4, 8, 12, 16, 20, 24, 28, 32, 40, 48, 56, 64, 72, 80, 0},     // Layer II
		{0, 16, 24, 28, 32, 40, 48, 56, 64, 72, 80, 88, 96, 112, 128, 0}  // Layer I
	},
	{
		// MPEG 1
		{0, 16, 20, 24, 28, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 0},     // Layer III
		{0, 16, 24, 28, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 0},    // Layer II
		{0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 0} // Layer I
	}
};

static const uint8_t frequency_table[5][5] = 
{
	{32, 16, 8 }, // MPEG 2.5
	{0,  0,  0 }, // reserved
	{22, 24, 16}, // MPEG 2
	{44, 48, 32}  // MPEG 1
};

// clang-format on

static const char STEREO[] = "Stereo";
static const char J_STEREO[] = "Joint Stereo";
static const char D_CHANNEL[] = "Dual Channel";
static const char S_CHANNEL[] = "Single Channel";

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
