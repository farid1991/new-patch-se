#if defined(J108_R7EA011)
#include <J108_R7EA011.h>
#define DB3350_R2
#endif

#include <libse.h>
#include <types/AudioControl_types.h>
#include <types/Colors.h>
#include <types/UIRichText_types.h>

#include "dll.h"
#include "patch.h"
#include "slider.h"

#ifdef DB3350
#define YPOS_MEDIA 60
#define YPOS_RINGTONE 110
#define YPOS_CALL 160
#else
#define YPOS_MEDIA 40
#define YPOS_RINGTONE 90
#define YPOS_CALL 140
#endif

static const char STR_CALL[] = "Call";
static const char STR_MEDIA[] = "Media";
static const char STR_RINGTONE[] = "Ringtone";
static const char STR_VOLUME[] = "Volume";

static const wchar_t PERC_FMT[] = L"%d%%";

//==============================================================================

THUMB16 NEWCODE void DrawText(int font, TEXTID text, int align, int XPos, int YPos, int Width, int TextColor)
{
    if (text != EMPTY_TEXTID)
    {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        dll_DrawString(font, text, align, XPos, YPos, XPos + Width, YPos + (font & 0xFF), TextColor);
#else
        SetFont(font);
        int font_h = GetImageHeight(' ');
        DrawString(text, align, XPos, YPos, XPos + Width, YPos + font_h, 0x14, 0x5, TextColor, clEmpty);
#endif
    }
}

THUMB16 NEWCODE void DrawSlider(int value, int max_value,
                                int rect_y1, int rect_height,
                                TEXTID slider_text, TEXTID value_text,
                                uint32_t text_color, uint32_t cursor_color,
                                uint32_t outline_color, uint32_t slider_color)
{
    // Define the slider rectangle
    int slider_height = rect_height >> 3;

    int slider_x1 = 10;
    int slider_x2 = 230;
    int slider_y1 = rect_y1 + (rect_height >> 1) + (rect_height >> 2);
    int slider_y2 = slider_y1 + slider_height;

    // Calculate the x coordinate for drawing the slider thumb
    int sliderWidth = slider_x2 - slider_x1;
    int thumbWidth = slider_height * 2;
    int thumbX = slider_x1 + (value * sliderWidth) / max_value - (thumbWidth >> 1);

    // Draw the main background rectangle as the background
    DrawRect(0, rect_y1, 240, rect_y1 + rect_height, cursor_color, cursor_color);

    // Draw the slider track
    DrawRect(slider_x1, slider_y1, slider_x2, slider_y2, outline_color, slider_color);

    // Draw the slider thumb and its outline
    DrawRect(thumbX, slider_y1, thumbX + thumbWidth, slider_y2, text_color, text_color);
    DrawRect(thumbX - 1, slider_y1, thumbX, slider_y2, outline_color, outline_color);
    DrawRect(thumbX + thumbWidth, slider_y1, thumbX + thumbWidth + 1, slider_y2, outline_color, outline_color);

    // Draw the slider text
    int textWidth = sliderWidth;
    int textX = slider_x1;
    int textY = rect_y1 + (rect_height >> 3);
    DrawText(FONT_E_20B, slider_text, AlignLeft, textX, textY, textWidth, text_color);
    DrawText(FONT_E_20B, value_text, AlignRight, 0, textY, textWidth, text_color);
}

THUMB16 NEWCODE TEXTID percent_to_textid(int percentage)
{
    wchar_t buf[16];
    snwprintf(buf, MAXELEMS(buf), PERC_FMT, percentage);
    return TextID_Create(buf, ENC_UCS2, MAXELEMS(buf));
}

THUMB16 NEWCODE int Slider_OnCreate(DISP_OBJ *disp)
{
    DISP_OBJ_SLIDER *disp_obj = (DISP_OBJ_SLIDER *)disp;

    disp_obj->slider_a_textid = STR(STR_MEDIA);
    disp_obj->slider_b_textid = STR(STR_RINGTONE);
    disp_obj->slider_c_textid = STR(STR_CALL);

    char media, ring, call;
    Volume_Get(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, &call);
    Volume_Get(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, &ring);
    Volume_Get(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, &media);

    disp_obj->slider_a = media - 18;
    disp_obj->slider_b = ring;
    disp_obj->slider_c = call - 9;

    disp_obj->slider_a_val = percent_to_textid(VOLUME_MEDIA[disp_obj->slider_a]);
    disp_obj->slider_b_val = percent_to_textid(VOLUME_RINGTONE[disp_obj->slider_b]);
    disp_obj->slider_c_val = percent_to_textid(VOLUME_RINGTONE[disp_obj->slider_c]);

    disp_obj->current_row = ROW_1;

    return 1;
}

THUMB16 NEWCODE void Slider_OnClose(DISP_OBJ *disp)
{
    DISP_OBJ_SLIDER *disp_obj = (DISP_OBJ_SLIDER *)disp;

    TextID_Destroy(disp_obj->slider_a_textid);
    TextID_Destroy(disp_obj->slider_b_textid);
    TextID_Destroy(disp_obj->slider_c_textid);
    TextID_Destroy(disp_obj->slider_a_val);
    TextID_Destroy(disp_obj->slider_b_val);
    TextID_Destroy(disp_obj->slider_c_val);
}

THUMB16 NEWCODE void Slider_OnRedraw(DISP_OBJ *disp, int, int, int)
{
    DISP_OBJ_SLIDER *disp_obj = (DISP_OBJ_SLIDER *)disp;

    DrawSlider(disp_obj->slider_a, MAX_MEDIAVOLUME,
               YPOS_MEDIA, 50,
               disp_obj->slider_a_textid,
               disp_obj->slider_a_val,
               (disp_obj->current_row == ROW_1) ? clAlpha : clBlueMidDark,
               (disp_obj->current_row == ROW_1) ? clBlueMidDark : clAlpha,
               clCyan,
               clTheta);

    DrawSlider(disp_obj->slider_b, MAX_RINGVOLUME,
               YPOS_RINGTONE, 50,
               disp_obj->slider_b_textid,
               disp_obj->slider_b_val,
               (disp_obj->current_row == ROW_2) ? clAlpha : clBlueMidDark,
               (disp_obj->current_row == ROW_2) ? clBlueMidDark : clAlpha,
               clCyan,
               clTheta);

    DrawSlider(disp_obj->slider_c, MAX_CALLVOLUME,
               YPOS_CALL, 50,
               disp_obj->slider_c_textid,
               disp_obj->slider_c_val,
               (disp_obj->current_row == ROW_3) ? clAlpha : clBlueMidDark,
               (disp_obj->current_row == ROW_3) ? clBlueMidDark : clAlpha,
               clCyan,
               clTheta);
}

THUMB16 NEWCODE void Slider_OnKey(DISP_OBJ *disp, int key, int r2, int repeat, int mode)
{
    DISP_OBJ_SLIDER *disp_obj = (DISP_OBJ_SLIDER *)disp;

    int _SYNC = 0;
    int *SYNC = &_SYNC;

    char media_volume;

    if (mode == KBD_SHORT_RELEASE || mode == KBD_REPEAT)
    {
        switch (key)
        {
        case KEY_UP:
        case KEY_DIGITAL_2:
            if ((--disp_obj->current_row) < ROW_1)
                disp_obj->current_row = ROW_3;
            break;

        case KEY_DOWN:
        case KEY_DIGITAL_8:
            if (++disp_obj->current_row > ROW_3)
                disp_obj->current_row = ROW_1;
            break;

        case KEY_LEFT:
        case KEY_DIGITAL_4:
            switch (disp_obj->current_row)
            {
            case ROW_1:
                if (disp_obj->slider_a)
                {
                    media_volume = (--disp_obj->slider_a) + 18;
                    Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, media_volume);
                }
                break;

            case ROW_2:
                if (disp_obj->slider_b)
                {
                    Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, --disp_obj->slider_b);
                    REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, disp_obj->slider_b);
                }
                break;

            case ROW_3:
                if (disp_obj->slider_c)
                    Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, --disp_obj->slider_c + 9);
                break;
            }
            break;

        case KEY_RIGHT:
        case KEY_DIGITAL_6:
            switch (disp_obj->current_row)
            {
            case ROW_1:
                if (disp_obj->slider_a < MAX_MEDIAVOLUME)
                {
                    media_volume = (++disp_obj->slider_a) + 18;
                    Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, media_volume);
                }
                break;

            case ROW_2:
                if (disp_obj->slider_b < MAX_RINGVOLUME)
                {
                    Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, ++disp_obj->slider_b);
                    REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, disp_obj->slider_b);
                }
                break;

            case ROW_3:
                if (disp_obj->slider_c < MAX_CALLVOLUME)
                    Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, ++disp_obj->slider_c + 9);
                break;
            }
            break;

        case KEY_DEL:
            switch (disp_obj->current_row)
            {
            case ROW_1:
                disp_obj->slider_a = 0;
                Volume_Set(AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, 18);
                break;

            case ROW_2:
                disp_obj->slider_b = 0;
                Volume_Set(AUDIOCONTROL_VOLUMETYPE_RINGVOLUME, 0);
                REQUEST_SETTING_RINGVOLUME_SET(SYNC, -2, 0, 0);
                break;

            case ROW_3:
                disp_obj->slider_c = 0;
                Volume_Set(AUDIOCONTROL_VOLUMETYPE_CALLVOLUME, 9);
                break;
            }
            break;
        }

        disp_obj->slider_a_val = percent_to_textid(VOLUME_MEDIA[disp_obj->slider_a]);
        disp_obj->slider_b_val = percent_to_textid(VOLUME_RINGTONE[disp_obj->slider_b]);
        disp_obj->slider_c_val = percent_to_textid(VOLUME_RINGTONE[disp_obj->slider_c]);
        DispObject_InvalidateRect(disp, NULL);
    }
}

THUMB16 NEWCODE void Slider_OnLayout(DISP_OBJ *disp, void *layout)
{
    DispObject_SetLayerColor(disp, clBlack);
}

THUMB16 NEWCODE void Slider_construct(DISP_DESC *desc)
{
    DISP_DESC_SetName(desc, Gui_Slider);
    DISP_DESC_SetSize(desc, sizeof(DISP_OBJ_SLIDER));
    DISP_DESC_SetOnCreate(desc, (DISP_OBJ_ONCREATE_METHOD)Slider_OnCreate);
    DISP_DESC_SetOnClose(desc, (DISP_OBJ_ONCLOSE_METHOD)Slider_OnClose);
    DISP_DESC_SetOnRedraw(desc, (DISP_OBJ_ONREDRAW_METHOD)Slider_OnRedraw);
    DISP_DESC_SetOnLayout(desc, (DISP_OBJ_ONLAYOUT_METHOD)Slider_OnLayout);
    DISP_DESC_SetOnKey(desc, (DISP_OBJ_ONKEY_METHOD)Slider_OnKey);
}

THUMB16 NEWCODE void Slider_destruct(GUI_SLIDER *gs)
{
}

THUMB16 NEWCODE void Slider_callback(DISP_OBJ *disp, void *msg, GUI_SLIDER *gui)
{
}

THUMB16 NEWCODE GUI_SLIDER *Create_Slider(VSBook *vs)
{
    GUI_SLIDER *gs = (GUI_SLIDER *)malloc(sizeof(GUI_SLIDER));
    if (!GUIObject_Create(gs, Slider_destruct, Slider_construct, &vs->book, Slider_callback, UIDisplay_Main, sizeof(GUI_SLIDER)))
    {
        mfree(gs);
        return NULL;
    }

    if (&vs->book)
        BookObj_AddGUIObject(&vs->book, gs);

    GUIObject_SetTitleType(gs, UI_TitleMode_Normal);
    GUIObject_SetTitleText(gs, STR(STR_VOLUME));
    return (gs);
}
