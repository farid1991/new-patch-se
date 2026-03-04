#ifndef _SETTING_H_
#define _SETTING_H_

static const char DBPLAYER_SETTINGS_BOOKNAME[]="DBPlayer_SettingBook";
enum ELEM_TYPE
{
    ELEM_TEXT,
    ELEM_RECT,
    ELEM_ICON
};

enum ITEM_SETTING
{
    ITEM_ARTIST,
    ITEM_TITLE,
    ITEM_ALBUM,
    ITEM_YEAR,
    ITEM_GENRE,
    ITEM_FILETYPE,
    ITEM_TOTAL,
    ITEM_ELAPSED,
    ITEM_REMAINING,
    ITEM_BITRATE,
    ITEM_SAMPLERATE,
    ITEM_AUDIOOUTPUT,
    ITEM_TIME_PROGRESS,
    ITEM_VOLUME_PROGRESS,
    ITEM_COVERART,
    ITEM_FRAME,
    ITEM_ARTIST_ICN,
    ITEM_TITLE_ICN,
    ITEM_ALBUM_ICN,
    ITEM_PLAYERSTATE_ICN,
    ITEM_BACKROUND,
    ITEM_ADDITIONAL,
    ITEM_LAST
};

enum BACKGROUND_TYPE
{
    BG_TYPE_IMAGE,
    BG_TYPE_THEME,
    BG_TYPE_COLOR
};

enum EDITOR_TYPE
{
    EDIT_TEXT,
    EDIT_SLIDER,
    EDIT_ICON,
    EDIT_BACKGROUND,
    EDIT_EXTENDED,
    EDIT_LAST
};

enum SUBITEM_TXT
{
    SUBITEM_TXT_STATE,
    SUBITEM_TXT_COLOR,
    SUBITEM_TXT_OVERLAY,
    SUBITEM_TXT_ALIGN,
    SUBITEM_TXT_VISUAL,
    SUBITEM_TXT_LAST
};

enum SUBITEM_IMG
{
    SUBITEM_IMG_STATE,
    SUBITEM_IMG_VISUAL,
    SUBITEM_IMG_LAST
};

enum SUBITEM_PROGRESSBAR
{
    SUBITEM_PB_STATE,
    SUBITEM_PB_SLIDER,
    SUBITEM_PB_ROUND,
    SUBITEM_PB_BCOLOR,
    SUBITEM_PB_FCOLOR,
    SUBITEM_PB_VISUAL,
    SUBITEM_PB_LAST
};

enum SUBITEM_BACKGROUND
{
    SUBITEM_BG_TYPE,
    SUBITEM_BG_COLOR,
    SUBITEM_BG_VISUAL,
    SUBITEM_BG_LAST
};

enum SUBITEM_ADDITIONAL
{
    SUBITEM_ADDITIONAL_1,
    SUBITEM_ADDITIONAL_2,
#ifndef DB3350
    SUBITEM_ADDITIONAL_3,
#endif
    SUBITEM_ADDITIONAL_LAST
};

typedef struct SETTINGS_BOOK
{
    BOOK book;
    GUI_LIST *main_menu;
    GUI_LIST *sub_menu;
    GUI_ONEOFMANY *options_menu;
    GUI *question_menu;
    GUI *color_picker;

    uint8_t element;
    uint8_t elem_type;
    bool changed;
    bool is_cover_art;
} SETTINGS_BOOK;

void DBPlayer_Setting(BOOK *book, GUI *gui);
int DBPlayer_Settings_onEnter(void *data, BOOK *book);
int DBPlayer_Settings_onExit(void *data, BOOK *book);
int DBPlayer_Settings_onPrev(void *data, BOOK *book);
int DBPlayer_Settings_onCancel(void *data, BOOK *book);

#endif
