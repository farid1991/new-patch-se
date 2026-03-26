#include "device.h"

#include <libse.h>

THUMB16
NEWCODE void GUIObject_SetScrollbarMode(GUI *gui, int mode)
{
	DISP_OBJ *disp = GUIObject_GetDispObject(gui);
	DispObject_SetScrollbarMode(disp, mode);
}
