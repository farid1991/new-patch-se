#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#endif

#include <libse.h>
#include <id3.h>

#include "dll.h"
#include "patch.h"
#include "data.h"
#include "info.h"

static const char FMT_3GP[] = "3GP";
static const char FMT_AAC[] = "AAC";
static const char FMT_AMR[] = "AMR";
static const char FMT_M4A[] = "M4A";
static const char FMT_MP3[] = "MP3";
static const char FMT_MP4[] = "MP4";
static const char FMT_WAV[] = "WAV";
static const char FMT_WMA[] = "WMA";
static const char FMT_UNK[] = "UNK";

static const char FMT_TIME1[] = "%02d:%02d";
static const char FMT_TIME2[] = "-%02d:%02d";

static const char SAMPLE_8K[] = "8.0 KHz";
static const char SAMPLE_11K[] = "11.02 KHz";
static const char SAMPLE_16K[] = "16.0 KHz";
static const char SAMPLE_22K[] = "22.05 KHz";
static const char SAMPLE_24K[] = "24.0 KHz";
static const char SAMPLE_32K[] = "32.0 KHz";
static const char SAMPLE_44K[] = "44.1 KHz";
static const char SAMPLE_48K[] = "48.0 KHz";

static const char OUT_MONO[] = "Mono";
static const char OUT_STEREO[] = "Stereo";

THUMB16
NEWCODE IMAGEID MetaData_GetCover(DBP_DATA *Data)
{
	IMAGEID image_id = NOIMAGE;
	METADATA_DESC *MetaData_Desc = dll_MetaData_Desc_Create(Data->path, Data->name);

	char cover_type;
	int size;
	int cover_offset;
	if (dll_MetaData_Desc_GetCoverInfo(MetaData_Desc, &cover_type, &size, &cover_offset))
	{
		int file = _fopen(Data->path, Data->name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
		if (file != -1)
		{
			if (lseek(file, cover_offset, FSX_SEEK_SET))
			{
				char *buf = (char *)malloc(size);
				fread(file, buf, size);
				ImageID_GetIndirect(buf, size, NULL, id3_cover_gettype(cover_type), &image_id);
				Data->cover_size = size;
			}
			fclose(file);
		}
	}
	dll_MetaData_Desc_Destroy(MetaData_Desc);
	return image_id;
}

THUMB16
NEWCODE IMAGEID GetCoverArt(DBP_DATA *Data)
{
	IMAGEID image_id = MetaData_GetCover(Data);
	if (image_id == NOIMAGE)
	{
		Data->has_cover_art = FALSE;
		image_id = Data->Image[IMG_NO_COVER].ID;
	}
	else
	{
		Data->has_cover_art = TRUE;
	}
	return image_id;
}

THUMB16
NEWCODE TEXTID GetTags(wchar_t *path, wchar_t *name, int tag_id)
{
	TEXTID text_id;
	wchar_t *tag = MetaData_GetTags(path, name, tag_id);
	if (tag)
	{
		text_id = TextID_Create(tag, ENC_UCS2, TEXTID_ANY_LEN);
		mfree(tag);
		return text_id;
	}
	else if (tag_id == TAG_TITLE)
		return TextID_Create(name, ENC_UCS2, wstrlen(name) - 4);
	else if (tag_id == TAG_ARTIST || tag_id == TAG_ALBUM)
		return TEXT_UNKNOWN;

	return EMPTY_TEXTID;
}

THUMB16
NEWCODE const char *GetFormatType(DBP_DATA *data)
{
	switch (data->file_format_type)
	{
	case TMMEFileFormatIdType_3GP: return FMT_3GP;
	case TMMEFileFormatIdType_AAC: return FMT_AAC;
	case TMMEFileFormatIdType_AMR: return FMT_AMR;
	case TMMEFileFormatIdType_M4A: return FMT_M4A;
	case TMMEFileFormatIdType_MP3: return FMT_MP3;
	case TMMEFileFormatIdType_MP4: return FMT_MP4;
	case TMMEFileFormatIdType_WAV: return FMT_WAV;
	case TMMEFileFormatIdType_WMA: return FMT_WMA;
	default: return FMT_UNK;
	}
}

THUMB16
NEWCODE TEXTID GetFileExt(DBP_DATA *data)
{
	return TextID_Create(GetFormatType(data), ENC_LAT1, strlen(GetFormatType(data)));
}

THUMB16
NEWCODE TEXTID GetTotalTime(DBP_DATA *data)
{
	char buf[16];
	snprintf(buf,
	         MAXELEMS(buf),
	         FMT_TIME1,
	         data->track_time.Hours * 60 + data->track_time.Minutes,
	         data->track_time.Seconds);
	return TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));
}

THUMB16
NEWCODE TEXTID GetElapsedTime(DBP_DATA *data)
{
	char buf[16];
	snprintf(buf,
	         MAXELEMS(buf),
	         FMT_TIME1,
	         data->elapsed_time.Hours * 60 + data->elapsed_time.Minutes,
	         data->elapsed_time.Seconds);
	return TextID_Create(buf, ENC_LAT1, MAXELEMS(buf));
}

THUMB16
NEWCODE TEXTID GetRemainingTime(DBP_DATA *data)
{
	int totalSeconds = data->track_time.Hours * 3600 + data->track_time.Minutes * 60 + data->track_time.Seconds;
	int elapsedSeconds =
	        data->elapsed_time.Hours * 3600 + data->elapsed_time.Minutes * 60 + data->elapsed_time.Seconds;
	int remainingSeconds = totalSeconds - elapsedSeconds;

	int remainingMinutes = remainingSeconds / 60;
	remainingSeconds %= 60;

	char buf[16];
	snprintf(buf, MAXELEMS(buf), FMT_TIME2, remainingMinutes, remainingSeconds);
	return TextID_Create(buf, ENC_UCS2, MAXELEMS(buf));
}

THUMB16
NEWCODE int synchsafeToNormal(uint8_t header[HEADER_SIZE])
{
	int synchsafe, sizeloc, size, power, x;

	size = sizeloc = 0;
	for (synchsafe = 31; synchsafe >= 0; synchsafe--)
	{
		if (GETBIT(header, synchsafe))
		{
			power = 1;
			for (x = 0; x < sizeloc; x++)
				power *= 2;
			size += power;
		}
		if (SHIFT(synchsafe))
			sizeloc++;
	}
	return size;
}

THUMB16
NEWCODE int get_tag_size(wchar_t *path, wchar_t *name)
{
	int ret = 0;
	int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file >= 0)
	{
		uint8_t buf[10];
		fread(file, buf, 10);
		if (buf[0] == 'I' && buf[1] == 'D' && buf[2] == '3')
		{
			uint8_t header[HEADER_SIZE];
			header[0] = buf[6];
			header[1] = buf[7];
			header[2] = buf[8];
			header[3] = buf[9];
			ret = synchsafeToNormal(header);
		}
		fclose(file);
	}
	return ret;
}

static const char FMT_BITRATE[] = "%d Kbps";
THUMB16
NEWCODE TEXTID GetBitrate(DBP_DATA *data)
{
	int id3size = get_tag_size(data->path, data->name);
	FSTAT stat;
	fstat(data->path, data->name, &stat);
	int size_in_kb = (stat.fsize - id3size - data->cover_size) / 1000;
	int bitrate = (size_in_kb * 8) / data->full_track_time;

	char buf[16];
	snprintf(buf, MAXELEMS(buf), FMT_BITRATE, bitrate);
	return TextID_Create(buf, ENC_UCS2, MAXELEMS(buf));
}

THUMB16
NEWCODE const char *getSampleRate(int index)
{
	switch (index)
	{
	case 8000: return SAMPLE_8K;
	case 11025: return SAMPLE_11K;
	case 16000: return SAMPLE_16K;
	case 22050: return SAMPLE_22K;
	case 24000: return SAMPLE_24K;
	case 32000: return SAMPLE_32K;
	case 44100: return SAMPLE_44K;
	case 48000: return SAMPLE_48K;
	}
	return 0;
}

THUMB16
NEWCODE TEXTID GetSampleRate(DBP_DATA *data)
{
	return TextID_Create(getSampleRate(data->samplerate), ENC_LAT1, strlen(getSampleRate(data->samplerate)));
}

THUMB16
NEWCODE TEXTID GetAudioOutput(DBP_DATA *data)
{
	switch (data->audio_output)
	{
	case TMMEAudioOutput_Mono: return TextID_Create(OUT_MONO, ENC_LAT1, 4);
	case TMMEAudioOutput_Stereo: return TextID_Create(OUT_STEREO, ENC_LAT1, 6);
	default: return TEXT_UNKNOWN;
	}
}
