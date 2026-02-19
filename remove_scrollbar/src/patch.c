#ifdef K800_R8BF003
#include "K800_R8BF003.h"
#endif

#include <libse.h>

THUMB16 NEWCODE void GUIObject_SetScrollbarMode(GUI *gui, int mode)
{
    DISP_OBJ* disp = GUIObject_GetDispObject(gui);
    DispObject_SetScrollbarMode(disp, mode);
}