#ifndef _SLIDER_H_
#define _SLIDER_H_

static const char Gui_Slider[] = "GUI_Slider";

static const uint8_t VOLUME_RINGTONE[MAX_RINGVOLUME + 1] = {0, 12, 25, 37, 50, 62, 75, 87, 100};
static const uint8_t VOLUME_MEDIA[MAX_MEDIAVOLUME + 1] = {0, 6, 13, 20, 26, 33, 40, 46, 53, 60, 66, 73, 80, 86, 93, 100};

enum
{
    ROW_1,
    ROW_2,
    ROW_3,
    LAST_ROW
};

typedef struct GUI GUI_SLIDER;

typedef struct _DISP_OBJ_SLIDER
{
    DISP_OBJ disp;
    int current_row;

    int a, b, c;

    TEXTID slider_a_textid;
    TEXTID slider_b_textid;
    TEXTID slider_c_textid;

    TEXTID slider_a_val;
    TEXTID slider_b_val;
    TEXTID slider_c_val;

    int slider_a;
    int slider_b;
    int slider_c;

} DISP_OBJ_SLIDER;

GUI *Create_Slider(VSBook *vs);

#endif
