#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include <types/Colors.h>

#include "data.h"
#include "draw.h"
#include "patch.h"

THUMB16
NEWCODE void draw_image_ex(GC *gc, int x, int y, int w, int h, IMAGEID image_id)
{
	if (image_id != NOIMAGE)
		GC_PutChar(gc, x, y, w, h, image_id);
}

THUMB16
NEWCODE void draw_image(GC *gc, int x, int y, IMAGEID image_id)
{
	if (image_id != NOIMAGE)
		GC_PutChar(gc, x, y, 0, 0, image_id);
}

THUMB16
NEWCODE void DrawProgressBar(GC *gc,
                             IMAGEID blob_id,
                             int start_pos,
                             int end_pos,
                             int x1,
                             int y1,
                             int x2,
                             int y2,
                             uint32_t bg_color,
                             uint32_t bar_color,
                             bool indicator)
{
	int w = x2 - x1;
	int h = y2 - y1;
	int nx2 = x1 + (start_pos * w / end_pos);

	DrawRect(x1, y1, x2, y2, bg_color, bg_color);
	DrawRect(x1, y1, nx2, y2, bar_color, bar_color);

	if (indicator)
	{
		int blob_w = GetImageWidth(blob_id) / 2;
		int blob_h = GetImageHeight(blob_id) / 2;
		int blob_x = nx2 - blob_w;
		int blob_y = (y1 - blob_h) + (h / 2);
		draw_image(gc, blob_x, blob_y, blob_id);
	}
}

THUMB16
NEWCODE void
DrawText(int font, TEXTID text, int align, int x_pos, int y_pos, int width, int height, uint32_t text_color)
{
	if (text == EMPTY_TEXTID)
		return;

	SetFont(font);
	DrawString(text, align, x_pos, y_pos, x_pos + width, y_pos + height, 0, 1, text_color, text_color);
}
