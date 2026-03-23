#ifndef _ID3_H
#define _ID3_H

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

static const char ID3V2_MAGIC[3] = {'I', 'D', '3'};

#ifdef __cplusplus
extern "C" {
#endif

// ID3 Header
BOOL is_valid_id3_header(uint32_t header);
uint32_t get_header(uint8_t *mp3_data);
int get_bitrate(uint32_t header);
int get_frequency(uint32_t header);
const char *get_mode(uint32_t header);

uint32_t int_decode(uint8_t *bytes, int size, int offset);
uint32_t synch_decode(uint32_t value);

// ID3 Cover
const wchar_t *id3_cover_gettype(uint8_t cover_type);

#ifdef __cplusplus
}
#endif

#endif // _ID3_H
