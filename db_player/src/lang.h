#ifndef _LANG_H_
#define _LANG_H_

typedef enum TEXT_ID
{
    ID_PTYPE,
    ID_PTYPE_1,
    ID_PTYPE_2,
    ID_ARTIST,
    ID_TITLE,
    ID_ALBUM,
    ID_YEAR,
    ID_GENRE,
    ID_FILETYPE,
    ID_TOTAL,
    ID_ELAPSED,
    ID_REMAINING,
    ID_BITRATE,
    ID_TIME_PROGRESS,
    ID_VOLUME_PROGRESS,
    ID_COVERART,
    ID_FRAME,
    ID_TEXT_COLOR,
    ID_COLOR_OVERLAY,
    ID_ALIGN,
    ID_ALIGN_LEFT,
    ID_ALIGN_RIGHT,
    ID_ALIGN_CENTER,
    ID_VISUAL_CONFIG,
    ID_SLIDER,
    ID_COLOR_F,
    ID_FULLSCREEN,
    ID_SOFTKEYS,
    ID_SAMPLERATE,
    ID_AUDIOOUTPUT,
    ID_STATE,
    ID_ARTIST_ICN,
    ID_TITLE_ICN,
    ID_ALBUM_ICN,
    ID_PLAYERSTATE_ICN,
    ID_BACKGROUND,
    ID_BACKGROUND_IMAGE,
    ID_BACKGROUND_THEME,
    ID_BACKGROUND_COLOR,
    ID_ADDITIONAL,
    ID_TAG_EDITOR,
} TEXT_ID;

static const char TEXT_PTYPE[] = "Type";
static const char TEXT_TAG_EDITOR[] = "Edit tag";
static const char TEXT_PTYPE_1[] = "Type 1";
static const char TEXT_PTYPE_2[] = "Type 2";
static const char TEXT_ARTIST[] = "Artist";
static const char TEXT_TITLE[] = "Title";
static const char TEXT_ALBUM[] = "Album";
static const char TEXT_YEAR[] = "Year";
static const char TEXT_GENRE[] = "Genre";
static const char TEXT_FILETYPE[] = "File type";
static const char TEXT_TIME_T[] = "Total time";
static const char TEXT_TIME_E[] = "Elapsed time";
static const char TEXT_TIME_R[] = "Remaining time";
static const char TEXT_BITRATE[] = "Bitrate";
static const char TEXT_TIME_PROGRESS[] = "Time (bar)";
static const char TEXT_VOLUME_PROGRESS[] = "Volume (bar)";
static const char TEXT_COVERART[] = "Cover Art";
static const char TEXT_FRAME[] = "Frame";
static const char TEXT_TEXT_COLOR[] = "Text color";
static const char TEXT_COLOR_OVERLAY[] = "Overlay color";
static const char TEXT_ALIGN[] = "Align";
static const char TEXT_ALIGN_LEFT[] = "Left";
static const char TEXT_ALIGN_RIGHT[] = "Right";
static const char TEXT_ALIGN_CENTER[] = "Center";
static const char TEXT_VISUAL_CONFIG[] = "Visual editor";
static const char TEXT_SLIDER[] = "Slider";
static const char TEXT_COLOR_F[] = "Fill color";
static const char TEXT_FULLSCREEN[] = "Fullscreen";
static const char TEXT_SOFTKEYS[] = "SoftKeys";
static const char TEXT_SAMPLERATE[] = "Samplerate";
static const char TEXT_AUDIOOUTPUT[] = "Audio output";
static const char TEXT_STATE[] = "State";
static const char TEXT_ARTIST_ICN[] = "Artist Icon";
static const char TEXT_TITLE_ICN[] = "Title Icon";
static const char TEXT_ALBUM_ICN[] = "Album Icon";
static const char TEXT_PLAYERSTATE_ICN[] = "State Icon";
static const char TEXT_BACKGROUND[] = "Background";
static const char TEXT_BACKGROUND_IMAGE[] = "Image";
static const char TEXT_BACKGROUND_THEME[] = "Theme Image";
static const char TEXT_BACKGROUND_COLOR[] = "Custom Color";
static const char TEXT_ADDITIONAL[] = "Additional";

TEXTID TextID_Global(int id);
TEXTID TextID_Setting(int id);

#endif
