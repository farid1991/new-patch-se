#include <libse.h>

#ifdef K800_R8BF003
    #include "K800_R8BF003.h"
#endif

#define NEWCODE __attribute__((section(".text.patch_section")))

#define GUIObject_GetDispObject ((DISP_OBJ *(*)(GUI *))ADDR_GUIObject_GetDispObject)
#define DispObject_SetScrollbarMode ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetScrollbarMode)

THUMB16 NEWCODE void GUIObject_SetScrollbarMode(GUI *gui, int mode)
{
    DISP_OBJ* disp = GUIObject_GetDispObject(gui);
    DispObject_SetScrollbarMode(disp, mode);
}