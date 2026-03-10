#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include "id3v2.h"

#define MAX_INFO_SIZE 128
static const char output_fmt[] = "\nid3v2.%d\n"
                                 "Bitrate: %dkbps\n"
                                 "Frequency: %dKHz\n"
                                 "Mode: %s";

THUMB16
NEWCODE TEXTID patch_brw_mp3info(TEXTID text_id, SUB_EXECUTE *sub_exec)
{
	wchar_t *path = FILEITEM_GetPath(sub_exec->file_item);
	wchar_t *name = FILEITEM_GetFname(sub_exec->file_item);

	uint32_t id3_vers;
	uint32_t fpos;
	uint32_t tagsize;
	uint32_t header = id3v2_read_header(path, name, &tagsize, &id3_vers, &fpos);
	if (!header || !tagsize)
		return text_id;

	char mp3_info[MAX_INFO_SIZE];
#if defined(DB2000) || defined(DB2010)
	sprintf(mp3_info,
#else
	snprintf(mp3_info,
	         MAX_INFO_SIZE,
#endif
	        output_fmt,
	        id3_vers,
	        get_bitrate(header),
	        get_frequency(header),
	        get_mode(header));

	TEXTID new_textid[2];
	new_textid[0] = text_id;
	new_textid[1] = TextID_Create(mp3_info, ENC_LAT1, MAX_INFO_SIZE);

	return TextID_Create(new_textid, ENC_TEXTID, 2);
}
