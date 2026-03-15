#if defined(W700_R1CA021)
#include <W700_R1CA021.h>
#elif defined(W800_R1BD001)
#include <W800_R1BD001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>

#include "data.h"

static const char ADV_EMP[] = "ADV_EMP";

THUMB16
NEWCODE ADVPLAYER_DATA *env_data_get()
{
	ADVPLAYER_DATA *data = (ADVPLAYER_DATA *)get_envp(NULL, ADV_EMP);
	if (!data)
	{
		data = (ADVPLAYER_DATA *)malloc(sizeof(ADVPLAYER_DATA));
		memset(data, 0, sizeof(ADVPLAYER_DATA));
		data->disp_w = Display_GetWidth(UIDisplay_Main);
		data->disp_h = Display_GetHeight(UIDisplay_Main);
		set_envp(NULL, ADV_EMP, (OSADDRESS)data);
	}
	return data;
}

THUMB16
NEWCODE void env_data_destroy(ADVPLAYER_DATA *data)
{
	if (data)
	{
		mfree(data);
		set_envp(NULL, ADV_EMP, 0);
	}
}
