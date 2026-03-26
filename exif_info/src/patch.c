#include "device.h"

#include <libse.h>

#include "patch.h"
#include "nanoexif.h"
#include "tag_list.h"
#include "tag_parser.h"

#define MAX_NAME 32
#define MAX_VALUE 32
#define MAX_TAGS 256

#if defined(DB2000) || defined(DB2010)
#define exif_printf(buf, size, fmt, ...) sprintf((buf), (fmt), ##__VA_ARGS__)
#else
#define exif_printf(buf, size, fmt, ...) snprintf((buf), (size), (fmt), ##__VA_ARGS__)
#endif

static const char exif_mem[] = "ExIf";
static const char STR_TITLE[] = "\n=EXIF Info=";
static const char STR_NEWLINE[] = "\n";
static const char STR_SEPARATOR[] = ": ";

static const char STR_ORIENTATION[] = "Orientation";
static const char STR_RES_UNIT[] = "Resolution Unit";
static const char STR_YCBCR_POS[] = "YCbCr Positioning";
static const char STR_EXPOSURE_PROGRAM[] = "Exposure Program";
static const char STR_ISO_SPEED[] = "ISO Speed";
static const char STR_METERING_MODE[] = "Metering Mode";
static const char STR_LIGHT_SOURCE[] = "Light Source";
static const char STR_FLASH_MODE[] = "Flash Mode";
static const char STR_CUSTOM_RENDERED[] = "Custom Rendered";
static const char STR_EXPOSURE_MODE[] = "Exposure Mode";
static const char STR_COLORSPACE[] = "Colorspace";
static const char STR_SENSING_METHOD[] = "Sensing Method";
static const char STR_WHITE_BALANCE[] = "White Balance";
static const char STR_SCENE_CAPTURE[] = "Scene Capture Type";
static const char STR_CONTRAST[] = "Contrast";
static const char STR_SATURATION[] = "Saturation";
static const char STR_SHARPNESS[] = "Sharpness";
static const char STR_CENTERED[] = "Centered";
static const char STR_COSITED[] = "Co-sited";
static const char STR_MANUAL[] = "Manual";
static const char STR_AUTO[] = "Auto";

static const char STR_XRES[] = "X Resolution";
static const char STR_YRES[] = "Y Resolution";
static const char STR_EXPTIME[] = "Exposure Time";
static const char STR_FNUMBER[] = "F-Number";
static const char STR_EXPCOMP[] = "Exposure Compensation";
static const char STR_SUBDIST[] = "Subject Distance";
static const char STR_FOCAL[] = "Focal Length";
static const char STR_DZOOM[] = "Digital Zoom";
static const char STR_GPS_LAT[] = "GPS Latitude";
static const char STR_GPS_LON[] = "GPS Longitude";
static const char STR_GPS_ALT[] = "GPS Altitude";
static const char STR_GPS_TIME[] = "GPS Timestamp";

static const char STR_CAMERA_MAKE[] = "Camera Make";
static const char STR_CAMERA_MODEL[] = "Camera Model";
static const char STR_SOFTWARE[] = "Software";
static const char STR_MODIFY_DATE[] = "Modify Date";
static const char STR_COPYRIGHT[] = "Copyright";
static const char STR_DATETIME_ORIGINAL[] = "Date/Time Original";
static const char STR_LENS_MAKE[] = "Lens Make";
static const char STR_LENS_MODEL[] = "Lens Model";
static const char STR_GPS_LAT_REF[] = "GPS LatRef";
static const char STR_GPS_LON_REF[] = "GPS LonRef";
static const char STR_GPS_SATELLITES[] = "GPS Satellites";

/* format fragments */
static const char STR_DPI_FMT[] = "%u dpi";
static const char STR_PERSEC[] = "1/%u sec";
static const char STR_GPS_FMT[] = "%u° %u' %u.%u\"";
static const char STR_FNUMBER_FMT[] = "f/%u.%u";
static const char STR_RATIO_FMT[] = "%u/%u";
static const char STR_MM_FMT[] = "%u.%02umm";
static const char STR_DEC2_FMT[] = "%u.%02u";
static const char STR_PAIR_FMT[] = "%u %u";
static const char STR_TIME_FMT[] = "%02u:%02u:%02u";
static const char STR_FMT_ISO[] = "ISO-%u";

THUMB16
NEWCODE void *malloc(int size)
{
#if defined(DB2020)
	return memalloc(NULL, size, 1, 5, exif_mem, NULL);
#elif defined(A2)
	return memalloc(-1, size, 1, 5, exif_mem, NULL);
#else
	return memalloc(size, 1, 5, exif_mem, NULL);
#endif
}

THUMB16
NEWCODE void mfree(void *mem)
{
	if (mem)
#if defined(DB2020)
		memfree(NULL, mem, exif_mem, NULL);
#elif defined(A2)
		memfree(NULL, mem, exif_mem, NULL);
#else
		memfree(mem, exif_mem, NULL);
#endif
}

THUMB16
NEWCODE BOOL tagid_and_shortdata_to_name(uint16_t tag_id, uint16_t data, char *name, char *value)
{
	BOOL skip = FALSE;

	switch (tag_id)
	{
	case NANOEXIF_TAG_ORIENTATION:
		strncpy(name, STR_ORIENTATION, MAX_NAME);
		strncpy(value, get_orientation(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_RES_UNIT:
		strncpy(name, STR_RES_UNIT, MAX_NAME);
		strncpy(value, get_resolution_unit(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_YCbCrPOSITIONING:
		strncpy(name, STR_YCBCR_POS, MAX_NAME);
		strncpy(value, ((data == 1) ? STR_CENTERED : STR_COSITED), MAX_VALUE);
		break;

	case NANOEXIF_TAG_EXPOSURE_PROGRAM:
		strncpy(name, STR_EXPOSURE_PROGRAM, MAX_NAME);
		strncpy(value, get_exposure_program(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_ISO_SPEED:
		strncpy(name, STR_ISO_SPEED, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_FMT_ISO, data);
		break;

	case NANOEXIF_TAG_METERING_MODE:
		strncpy(name, STR_METERING_MODE, MAX_NAME);
		strncpy(value, get_metering_mode(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_LIGHT_SOURCE:
		strncpy(name, STR_LIGHT_SOURCE, MAX_NAME);
		strncpy(value, get_light_source(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_FLASH_MODE:
		strncpy(name, STR_FLASH_MODE, MAX_NAME);
		strncpy(value, get_flash_mode(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_CUSTOM_RENDERED:
		strncpy(name, STR_CUSTOM_RENDERED, MAX_NAME);
		strncpy(value, get_custom_render(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_EXPOSURE_MODE:
		strncpy(name, STR_EXPOSURE_MODE, MAX_NAME);
		strncpy(value, get_exposure_mode(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_COLORSPACE:
		strncpy(name, STR_COLORSPACE, MAX_NAME);
		strncpy(value, get_colorspace(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_SENSING_METHOD:
		strncpy(name, STR_SENSING_METHOD, MAX_NAME);
		strncpy(value, get_sensing(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_WHITE_BALANCE:
		strncpy(name, STR_WHITE_BALANCE, MAX_NAME);
		strncpy(value, (data ? STR_MANUAL : STR_AUTO), MAX_VALUE);
		break;

	case NANOEXIF_TAG_SCENE_CAPTURE_TYPE:
		strncpy(name, STR_SCENE_CAPTURE, MAX_NAME);
		strncpy(value, get_scene(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_CONTRAST:
		strncpy(name, STR_CONTRAST, MAX_NAME);
		strncpy(value, get_contrast_saturation(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_SATURATION:
		strncpy(name, STR_SATURATION, MAX_NAME);
		strncpy(value, get_contrast_saturation(data), MAX_VALUE);
		break;

	case NANOEXIF_TAG_SHARPNESS:
		strncpy(name, STR_SHARPNESS, MAX_NAME);
		strncpy(value, get_sharpness(data), MAX_VALUE);
		break;

	default: skip = TRUE; break;
	}

	return skip;
}

THUMB16
NEWCODE BOOL tagid_and_rationaldata_to_name(uint16_t tag_id, uint32_t *data, char *name, char *value)
{
	BOOL skip = FALSE;

	switch (tag_id)
	{
	case NANOEXIF_TAG_XRES:
		strncpy(name, STR_XRES, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_DPI_FMT, data[1] ? (data[0] / data[1]) : 0);
		break;

	case NANOEXIF_TAG_YRES:
		strncpy(name, STR_YRES, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_DPI_FMT, data[1] ? (data[0] / data[1]) : 0);
		break;

	case NANOEXIF_TAG_EXPOSURETIME:
		strncpy(name, STR_EXPTIME, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_PERSEC, data[0] ? (data[1] / data[0]) : 0);
		break;

	case NANOEXIF_TAG_F_NUMBER: {
		strncpy(name, STR_FNUMBER, MAX_NAME);

		uint32_t scaled = data[1] ? (data[0] * 10U) / data[1] : 0;

		exif_printf(value, MAX_VALUE, STR_FNUMBER_FMT, scaled / 10, scaled % 10);
	}
	break;

	case NANOEXIF_TAG_EXPOSURE_COMP:
		strncpy(name, STR_EXPCOMP, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_RATIO_FMT, data[0], data[1]);
		break;

	case NANOEXIF_TAG_SUBJECT_DISTANCE: {
		strncpy(name, STR_SUBDIST, MAX_NAME);

		uint32_t scaled = data[1] ? (data[0] * 100U) / data[1] : 0;

		exif_printf(value, MAX_VALUE, STR_MM_FMT, scaled / 100, scaled % 100);
	}
	break;

	case NANOEXIF_TAG_FOCAL_LENGTH: {
		strncpy(name, STR_FOCAL, MAX_NAME);

		uint32_t scaled = data[1] ? (data[0] * 100U) / data[1] : 0;

		exif_printf(value, MAX_VALUE, STR_DEC2_FMT, scaled / 100, scaled % 100);
	}
	break;

	case NANOEXIF_TAG_DIGITALZOOM_RATIO: {
		strncpy(name, STR_DZOOM, MAX_NAME);

		uint32_t scaled = data[1] ? (data[0] * 10U) / data[1] : 0;

		exif_printf(value, MAX_VALUE, STR_DEC2_FMT, scaled / 10, scaled % 10);
	}
	break;

	case NANOEXIF_TAG_GPS_LATITUDE:
		strncpy(name, STR_GPS_LAT, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_GPS_FMT, data[0], data[1], data[2], data[3]);
		break;

	case NANOEXIF_TAG_GPS_LONGITUDE:
		strncpy(name, STR_GPS_LON, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_GPS_FMT, data[0], data[1], data[2], data[3]);
		break;

	case NANOEXIF_TAG_GPS_ALTITUDE:
		strncpy(name, STR_GPS_ALT, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_PAIR_FMT, data[0], data[1]);
		break;

	case NANOEXIF_TAG_GPS_TIMESTAMP:
		strncpy(name, STR_GPS_TIME, MAX_NAME);
		exif_printf(value, MAX_VALUE, STR_TIME_FMT, data[0], data[1], data[2]);
		break;

	default: skip = TRUE; break;
	}

	return skip;
}

THUMB16
NEWCODE BOOL tagid_to_name(uint16_t tag_id, char *name)
{
	BOOL skip = FALSE;

	switch (tag_id)
	{
	case NANOEXIF_TAG_MAKE: strncpy(name, STR_CAMERA_MAKE, MAX_NAME); break;

	case NANOEXIF_TAG_MODEL: strncpy(name, STR_CAMERA_MODEL, MAX_NAME); break;

	case NANOEXIF_TAG_SOFTWARE: strncpy(name, STR_SOFTWARE, MAX_NAME); break;

	case NANOEXIF_TAG_DATETIME: strncpy(name, STR_MODIFY_DATE, MAX_NAME); break;

	case NANOEXIF_TAG_COPYRIGHT: strncpy(name, STR_COPYRIGHT, MAX_NAME); break;

	case NANOEXIF_TAG_DATETIME_ORI: strncpy(name, STR_DATETIME_ORIGINAL, MAX_NAME); break;

	case NANOEXIF_TAG_LENSMAKE: strncpy(name, STR_LENS_MAKE, MAX_NAME); break;

	case NANOEXIF_TAG_LENSMODEL: strncpy(name, STR_LENS_MODEL, MAX_NAME); break;

	case NANOEXIF_TAG_GPS_LATITUDE_REF: strncpy(name, STR_GPS_LAT_REF, MAX_NAME); break;

	case NANOEXIF_TAG_GPS_LONGITUDE_REF: strncpy(name, STR_GPS_LON_REF, MAX_NAME); break;

	case NANOEXIF_TAG_GPS_SATELLITES: strncpy(name, STR_GPS_SATELLITES, MAX_NAME); break;

	default: skip = TRUE; break;
	}

	return skip;
}

THUMB16
NEWCODE void
jpg_read_exif_tag(LIST *list, nanoexif *ne, uint32_t ifd_offset, uint16_t *processed_tags, uint16_t *processed_count)
{
	uint32_t next_ifd_offset;
	nanoexif_ifd_entry *entries;
	TAG_LIST_ELEM *tag_list;
	do
	{
		uint16_t cnt;
		entries = nanoexif_read_ifd(ne, ifd_offset, &next_ifd_offset, &cnt);

		for (int i = 0; i < cnt; i++)
		{
			BOOL already_processed = FALSE;
			for (int j = 0; j < *processed_count; j++)
			{
				if (processed_tags[j] == entries[i].tag)
				{
					already_processed = TRUE;
					break;
				}
			}

			if (already_processed)
				continue;

			processed_tags[*processed_count] = entries[i].tag;
			(*processed_count)++;

			BOOL skip;

			switch (entries[i].type)
			{
			case NANOEXIF_TYPE_RATIONAL: {
				uint32_t *data = nanoexif_get_ifd_entry_data_rational(ne, &entries[i]);
				char *name = (char *)malloc(MAX_NAME);
				char *value = (char *)malloc(MAX_VALUE);
				skip = tagid_and_rationaldata_to_name(entries[i].tag, data, name, value);
				if (!skip)
				{
					tag_list = tag_list_create_elem(entries[i].tag, name, value);
					List_InsertLast(list, tag_list);
				}
				mfree(name);
				mfree(value);
				mfree(data);
				break;
			}
			case NANOEXIF_TYPE_ASCII: {
				char *name = (char *)malloc(MAX_NAME);
				char *value = nanoexif_get_ifd_entry_data_ascii(ne, &entries[i]);
				skip = tagid_to_name(entries[i].tag, name);
				if (!skip)
				{
					tag_list = tag_list_create_elem(entries[i].tag, name, value);
					List_InsertLast(list, tag_list);
				}
				mfree(name);
				mfree(value);
				break;
			}
			case NANOEXIF_TYPE_SHORT: {
				uint16_t *data = nanoexif_get_ifd_entry_data_short(ne, &entries[i]);
				char *name = (char *)malloc(MAX_NAME);
				char *value = (char *)malloc(MAX_VALUE);
				skip = tagid_and_shortdata_to_name(entries[i].tag, *data, name, value);
				if (!skip)
				{
					tag_list = tag_list_create_elem(entries[i].tag, name, value);
					List_InsertLast(list, tag_list);
				}
				mfree(name);
				mfree(value);
				mfree(data);
				break;
			}
			}

			if (entries[i].tag == NANOEXIF_TAG_EXIF_OFFSET || entries[i].tag == NANOEXIF_TAG_GPS_INFO)
			{
				uint32_t *data = nanoexif_get_ifd_entry_data_long(ne, &entries[i]);
				uint32_t offset = *data;
				mfree(data);

				jpg_read_exif_tag(list, ne, offset, processed_tags, processed_count);
			}
		}
		ifd_offset = next_ifd_offset;
	} while (next_ifd_offset != 0);

	mfree(entries);
}

THUMB16
NEWCODE LIST *jpeg_read_exif_to_list(const wchar_t *path, const wchar_t *name)
{
	int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
	if (file == -1)
		return NULL;

	uint32_t ifd_offset;
	nanoexif *ne = nanoexif_init(file, &ifd_offset);
	if (ne == NULL)
	{
		fclose(file);
		return NULL;
	}

	uint16_t processed_tags[MAX_TAGS];
	uint16_t processed_count = 0;

	LIST *list = List_Create();

	jpg_read_exif_tag(list, ne, ifd_offset, processed_tags, &processed_count);
	nanoexif_free(ne);
	fclose(file);

	return list;
}

THUMB16
NEWCODE TEXTID patch_brw_jpg_info(TEXTID text_id, SUB_EXECUTE *sub_exec)
{
	wchar_t *path = FILEITEM_GetPath(sub_exec->file_item);
	wchar_t *name = FILEITEM_GetFname(sub_exec->file_item);

	LIST *tag_list = jpeg_read_exif_to_list(path, name);
	if (!tag_list)
		return text_id;

	int list_count = List_GetCount(tag_list);
	int exif_info_size = (MAX_NAME + MAX_VALUE) * list_count;

	char *exif_info = (char *)malloc(exif_info_size);
	memset(exif_info, 0, exif_info_size);
	exif_printf(exif_info, exif_info_size, STR_TITLE);

	for (int i = 0; i < list_count; i++)
	{
		TAG_LIST_ELEM *tag_elem = (TAG_LIST_ELEM *)List_Get(tag_list, i);
		strncat(exif_info, STR_NEWLINE, sizeof(STR_NEWLINE));
		strncat(exif_info, tag_elem->name, tag_elem->name_len);
		strncat(exif_info, STR_SEPARATOR, sizeof(STR_SEPARATOR));
		strncat(exif_info, tag_elem->value, tag_elem->value_len);
	}

	TEXTID new_textid[2];
	new_textid[0] = text_id;
	new_textid[1] = TextID_Create(exif_info, ENC_LAT1, TEXTID_ANY_LEN);

	mfree(exif_info);
	tag_list_destroy(&tag_list, tag_list_remove_elem);

	return TextID_Create(new_textid, ENC_TEXTID, 2);
}
