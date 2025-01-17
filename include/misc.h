#ifndef MISC_H
#define MISC_H

// pb_ui_search_bk_create_search_menu
#define MODE_PB 0x0001
#define MODE_GROUPS 0x0002
#define MODE_SIM 0x0008
#define MODE_UNSAVED 0x0010

// uri scheme
typedef enum URISchemeID
{
	file = 0,
	http = 1,
	https = 2,
	rtsp = 3,
	mailto = 4,
	smsto = 5,
	mmsto = 6,
	sms = 7,
	mms = 8,
	tel = 9,
	vcard = 10,
	vnote = 11,
	vcal = 12
} URISchemeID;

// Metadata tags
enum METADATA_TAGS
{
	TAG_ARTIST,
	TAG_TITLE,
	TAG_ALBUM,
	TAG_YEAR,
	TAG_GENRE,
	TAG_X5,
	TAG_X6
};


#endif // MISC_H