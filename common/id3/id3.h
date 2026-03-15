#ifndef _ID3_HDR_H
#define _ID3_HDR_H

#define BITRATE_SCALE 2

#define ID3V2_2 2
#define ID3V2_2_BYTE 3
#define ID3V2_3 3
#define ID3V2_4 4
#define ID3V2_X_BYTE 4

#define ID3V2_HEADER_TAG_SIZE 4
#define ID3V2_HEADER_SIZE 10
#define ID3V2_EXTENDED_HEADER_SIZE 4
#define ID3V2_EXTENDED_HEADER_FLAGS 3
#define ID3V2_EXTENDED_HEADER_PADDING_SIZE 4

#define ID3V2_FRAME_ID_SIZE 4
#define ID3V2_FRAME_SIZE 4
#define ID3V2_FRAME_FLAGS_SIZE 3
#define ID3V2_FRAME_ENC_SIZE 1
#define ID3V2_FRAME_LYRIC_LNG_SIZE 3
#define ID3V2_FRAME_SYNC 0x7FF

#define ID3V2_RESERVED_VERSION 1
#define ID3V2_INVALID_LAYER 0
#define ID3V2_INVALID_BITRATE 15
#define ID3V2_INVALID_FREQ 3

// Lookup table for bitrate values (depends on version and layer)
static const uint8_t bitrate_table[2][3][16] = {
        {
         // MPEG 2 & 2.5
                {0, 4, 8, 12, 16, 20, 24, 28, 32, 40, 48, 56, 64, 72, 80, 0},      // Layer III
                {0, 4, 8, 12, 16, 20, 24, 28, 32, 40, 48, 56, 64, 72, 80, 0},            // Layer II
                {0, 16, 24, 28, 32, 40, 48, 56, 64, 72, 80, 88, 96, 112, 128, 0} // Layer I
        },
        {
         // MPEG 1
                {0, 16, 20, 24, 28, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 0}, // Layer III
                {0, 16, 24, 28, 32, 40, 48, 56, 64, 80, 96, 112, 128, 160, 192, 0}, // Layer II
                {0, 16, 32, 48, 64, 80, 96, 112, 128, 144, 160, 176, 192, 208, 224, 0} // Layer I
        }
};

static const uint8_t frequency_table[5][5] = {
        {32, 16, 8 }, // MPEG 2.5
        {0,  0,  0 }, // reserved
        {22, 24, 16}, // MPEG 2
        {44, 48, 32}  // MPEG 1
};

static const char ID3V2_MAGIC[3] = {'I', 'D', '3'};
static const char STEREO[] = "Stereo";
static const char J_STEREO[] = "Joint Stereo";
static const char D_CHANNEL[] = "Dual Channel";
static const char S_CHANNEL[] = "Single Channel";

#ifdef __cplusplus
extern "C" {
#endif

BOOL is_valid_id3_header(uint32_t header);
uint32_t get_header(uint8_t *mp3_data);
int get_bitrate(uint32_t header);
int get_frequency(uint32_t header);
const char *get_mode(uint32_t header);

uint32_t int_decode(uint8_t *bytes, int size, int offset);
uint32_t synch_decode(uint32_t value);

#ifdef __cplusplus
}
#endif

#endif // _ID3_HDR_H