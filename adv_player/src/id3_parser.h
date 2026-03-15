#ifndef _ID3Parser_h
#define _ID3Parser_h

#include <classes/IPlaylist.h>

#include "track_desc.h"

bool id3v2_extract_coverart(PLAYLIST_ITEM *item);
bool id3v2_get_coverart(TRACK_DESC *item);

#endif
