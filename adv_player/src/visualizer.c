#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include <types/Colors.h>

#ifdef ENABLE_VISUALIZER
#include "data.h"
#include "draw.h"
#include "patch.h"
#include "visualizer.h"

static const wchar_t VIZ_PNG[] = L"viz.png";

THUMB16
NEWCODE void visualizer_image_register()
{
	ADVPLAYER_DATA *data = env_data_get();

	data->viz_image.handle = NOIMAGE;
	data->viz_image.id = NOIMAGE;
	data->viz_image.exist = FALSE;

	if (FSX_IsFileExists(SKIN_CFG_PATH, VIZ_PNG))
		image_register(&data->viz_image, SKIN_CFG_PATH, VIZ_PNG);
}

THUMB16
NEWCODE void visualizer_init()
{
	ADVPLAYER_DATA *data = env_data_get();
	data->viz.dx = 2;
	data->viz.dy = 2;
	data->viz.gravity = 1;
}

THUMB16
NEWCODE void visualizer_update(int max_x, int max_y)
{
	ADVPLAYER_DATA *data = env_data_get();

	int icon_w, icon_h;
	icon_w = icon_h = max_x >> 1;
	data->viz.icon_size = icon_w;

	data->viz.x += data->viz.dx;
	data->viz.y += data->viz.dy;
	data->viz.dy += data->viz.gravity;

	if (data->viz.x <= 0)
	{
		data->viz.dx = -data->viz.dx;
		data->viz.x = 0;
	}
	else if ((data->viz.x + icon_w) >= max_x)
	{
		data->viz.dx = -data->viz.dx;
		data->viz.x = max_x - icon_w;
	}

	if ((data->viz.y + icon_h) >= max_y)
	{
		data->viz.dy = -((data->viz.dy * 29) >> 5);
		data->viz.y = max_y - icon_h;
	}

	if (data->viz.y <= 0)
	{
		data->viz.dy = -data->viz.dy;
		data->viz.y = 0;
	}
}

THUMB16
NEWCODE void visualizer_draw_bouncing_walkman(GC *disp_ctx, int x_dest, int y_dest, int w_dest, int h_dest)
{
	ADVPLAYER_DATA *data = env_data_get();

	if (data->viz_gvi == 0)
	{
		data->viz_canvas = GC_CreateMemoryGC(w_dest, h_dest, 16, 0, 0, 0);
		CANVAS_Get_GviGC(data->viz_canvas->pcanvas, &data->viz_gvi);

		GVI_BRUSH backbrush = GVI_CreateSolidBrush(clEmpty);
		GVI_FillRectangle(data->viz_gvi, 0, 0, w_dest, h_dest, backbrush);
		GVI_Delete_GVI_Object(&backbrush);
	}

	GVI_FillSolidRoundRect(data->viz_gvi, 0, 0, w_dest, h_dest, 4, 4, clAlpha);

	GC_PutChar(data->viz_canvas,
	           data->viz.x,
	           data->viz.y,
	           data->viz.icon_size,
	           data->viz.icon_size,
	           data->viz_image.id);

	CANVAS_Get_GviGC(disp_ctx->pcanvas, &data->disp_gvi);
	GVI_TransformBlt(data->disp_gvi, x_dest, y_dest, data->viz_gvi, 0, 0, w_dest, h_dest, 0, 0);
}

#endif
