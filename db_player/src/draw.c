#include "device.h"

#include <libse.h>
#include <types/Colors.h>

#include "dll.h"
#include "data.h"
#include "draw.h"
#include "patch.h"

THUMB16
NEWCODE void DrawImageEx(GC *gc, int x, int y, int w, int h, IMAGEID image_id)
{
	if (image_id != NOIMAGE)
	{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
		dll_GC_PutChar(gc, x, y, w, h, image_id);
#else
		GC_PutChar(gc, x, y, w, h, image_id);
#endif
	}
}

THUMB16
NEWCODE void DrawImage(int x, int y, IMAGEID image_id)
{
	DrawImageEx(get_DisplayGC(), x, y, 0, 0, image_id);
}

THUMB16
NEWCODE void
DrawProgressBar(DBP_DATA *data, int cur_value, int total_value, RECT rect, uint32_t b_color, uint32_t e_color)
{
	int bar = rect.x1 + (cur_value * (rect.x2 - rect.x1) / total_value);

	if (data->settings.time.round || data->settings.volume.round)
	{
		DrawRect(rect.x1 + 1, rect.y1, rect.x2 - 1, rect.y2, clEmpty, e_color);
		DrawRect(rect.x1, rect.y1 + 1, rect.x2, rect.y2 - 1, clEmpty, e_color);
		DrawRect(rect.x1 + 1, rect.y1 + 1, rect.x2 - 1, rect.y2 - 1, b_color, b_color);
		DrawRect(rect.x1 + 1, rect.y1 + 1, bar - 1, rect.y2 - 1, e_color, e_color);
	}
	else
	{
		DrawRect(rect.x1, rect.y1, rect.x2, rect.y2, b_color, b_color);
		DrawRect(rect.x1, rect.y1, bar, rect.y2, e_color, e_color);
	}

	if (data->settings.time.slider || data->settings.volume.slider)
	{
		IMAGEID image_id = data->Image[IMG_SLIDER].ID;
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
		int blob_x = bar - (dll_GetImageHeight(image_id) / 2);
		int blob_y = (rect.y1 - (dll_GetImageWidth(image_id) / 2)) + ((rect.y2 - rect.y1) / 2);
#else
		int blob_x = bar - (GetImageHeight(image_id) / 2);
		int blob_y = (rect.y1 - (GetImageWidth(image_id) / 2)) + ((rect.y2 - rect.y1) / 2);
#endif
		DrawImage(blob_x, blob_y, image_id);
	}
}

THUMB16
NEWCODE void DrawText(int font, TEXTID text_id, int align, int x1, int y1, int x2, uint32_t t_color)
{
	if (text_id != EMPTY_TEXTID)
	{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
		dll_DrawString(font, text_id, align, x1, y1, x2, y1 + (font & 0xFF), t_color);
#else
		SetFont(font);
		int font_h = GetImageHeight(' ');
		DrawString(text_id, align, x1, y1, x2, y1 + font_h, 0, 0, t_color, t_color);
#endif
	}
}

THUMB16
NEWCODE void DrawTextEx(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, uint32_t t_color)
{
	if (text_id != EMPTY_TEXTID)
	{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
		dll_DrawString(font, text_id, align, x1, y1, x2, y2, t_color);
#else
		SetFont(font);
		DrawString(text_id, align, x1, y1, x2, y2, 0x10, 0x5, t_color, t_color);
#endif
	}
}

THUMB16
NEWCODE void DrawTextWithStyle(
        TEXTID text_id, int font, int align, int x1, int y1, int x2, uint32_t t_color, uint32_t h_color, int overlay)
{
	switch (overlay) //(Overlay type)
	{
	case TEXTOVERLAY_TYPE1: // (Full) v1
		DrawText(font, text_id, align, x1 - 1, y1 - 1, x2 - 1, h_color);
		DrawText(font, text_id, align, x1 - 1, y1 + 1, x2 - 1, h_color);
		DrawText(font, text_id, align, x1 + 1, y1 - 1, x2 + 1, h_color);
		DrawText(font, text_id, align, x1 + 1, y1 + 1, x2 + 1, h_color);
		break;
	case TEXTOVERLAY_TYPE2: // (Full) v2
		DrawText(font, text_id, align, x1 + 1, y1, x2, h_color);
		DrawText(font, text_id, align, x1, y1 + 1, x2, h_color);
		DrawText(font, text_id, align, x1 - 1, y1, x2, h_color);
		DrawText(font, text_id, align, x1, y1 - 1, x2, h_color);
		break;
	case TEXTOVERLAY_TYPE3: // (Shadow)
		DrawText(font, text_id, align, x1 + 1, y1 + 1, x2, h_color);
		break;
	}
	DrawText(font, text_id, align, x1, y1, x2, t_color);
}
