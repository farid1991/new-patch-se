#ifndef __ID3V2_H__
#define __ID3V2_H__

uint32_t
id3v2_read_header(const wchar_t *path, const wchar_t *name, uint32_t *tagsize, uint32_t *version, uint32_t *fpos);

#endif
