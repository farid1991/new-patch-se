#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#ifdef ENABLE_VISUALIZER
#include "draw.h"
#include "timer.h"
#include "visualizer.h"

THUMB16
NEWCODE void wait_for_player(uint16_t timer_id, ADVPLAYER_DATA *data)
{
	if (data->is_playing && !data->has_coverart)
	{
		KILL_TIMER(data->wait_timer);
		data->viz_ready = TRUE;
		data->viz_timer = Timer_Set(20, MKTIMERPROC(refresh_viz), (LPARAM)data);
	}
	else
	{
		data->viz_ready = FALSE;
		Timer_ReSet(&data->wait_timer, 1000, MKTIMERPROC(wait_for_player), (LPARAM)data);
	}
}

THUMB16
NEWCODE void refresh_viz(uint16_t timer_id, ADVPLAYER_DATA *data)
{
	if (data->is_playing && !data->has_coverart)
	{
		data->viz_ready = TRUE;
		visualizer_update(data->skin_data->coverart_w, data->skin_data->coverart_h);

		DispObject_InvalidateRect((DISP_OBJ *)data->disp_obj_nowplaying, NULL);

		Timer_ReSet(&data->viz_timer, 20, MKTIMERPROC(refresh_viz), (LPARAM)data);
	}
	else
	{
		data->viz_ready = FALSE;
		KILL_TIMER(data->viz_timer);
		data->wait_timer = Timer_Set(1000, MKTIMERPROC(wait_for_player), (LPARAM)data);
	}
}
#endif
