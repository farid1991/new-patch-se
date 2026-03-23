#pragma once

#define TEXTID_SAVE 0x121
#define TEXTID_BRIGHTNESS 0x1250

#define ACTION_LONG_BACK 0xFAF
#define ACTION_NO 0xFBE
#define ACTION_BACK 0xFC0
#define ACTION_SELECT1 0xFC2
#define ACTION_YES 0xFC5

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define RETURN_TO_STANDBY_EVENT 0x840

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DEL 0x5
#define KEY_DIEZ 0x23
#define KEY_DIGITAL_0 0x18
#define KEY_DIGITAL_1 0x19
#define KEY_DIGITAL_2 0x1A
#define KEY_DIGITAL_3 0x1B
#define KEY_DIGITAL_4 0x1C
#define KEY_DIGITAL_5 0x1D
#define KEY_DIGITAL_6 0x1E
#define KEY_DIGITAL_7 0x1F
#define KEY_DIGITAL_8 0x20
#define KEY_DIGITAL_9 0x21
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_ESC 0x4
#define KEY_LEFT 0xF
#define KEY_MEDIAPLAYER 0x28
#define KEY_RIGHT 0xB
#define KEY_STAR 0x22
#define KEY_TASK 0x24
#define KEY_UP 0x9

#define ADDR_debug_printf (0x4BB3A365)
#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x4BB01144)
#define ADDR__fopen (0x109F5840 | 1)
#define ADDR_fread (0x109F71D4 | 1)
#define ADDR_fclose (0x117A443C | 1)
#define ADDR_fwrite (0x109F73A0 | 1)
#define ADDR_fstat (0x109F61A4 | 1)
#define ADDR_FSX_IsFileExists (0x1188A9F4 | 1)
#define ADDR_ImageID_Free (0x10847AA8 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x10843910 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x10843988 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x10843A10 | 1)
#define ADDR_Display_SetBrightness (0x10E5AA84 | 1)
#define ADDR_Display_GetBrightness (0x10E5AA44 | 1)
#define ADDR_Save_Brightness_Level (0x10E51E5C | 1)
#define ADDR_DispObject_SetLayerColor (0x10A68734 | 1)
#define ADDR_DispObject_InvalidateRect (0x10A6653C | 1)
#define ADDR_DISP_DESC_SetName (0x10A6301C | 1)
#define ADDR_DISP_DESC_SetSize (0x10A63020 | 1)
#define ADDR_DISP_DESC_SetOnCreate (0x10A63024 | 1)
#define ADDR_DISP_DESC_SetOnClose (0x10A63028 | 1)
#define ADDR_DISP_DESC_SetOnRedraw (0x10A6302C | 1)
#define ADDR_DISP_DESC_SetOnKey (0x10A63034 | 1)
#define ADDR_DISP_DESC_SetOnRefresh (0x10A63030 | 1)
#define ADDR_DISP_DESC_SetMethod06 (0x10A63038 | 1)
#define ADDR_DISP_DESC_SetOnLayout (0x10A63040 | 1)
#define ADDR_DISP_DESC_SetOnConfig (0x10A63044 | 1)
#define ADDR_UI_Event (0x10E8894C | 1)
#define ADDR_FreeBook (0x10E8A22C | 1)
#define ADDR_GUIObject_Create (0x10A6F95C | 1)
#define ADDR_BookObj_AddGUIObject (0x10E89F3C | 1)
#define ADDR_GUIObject_SetTitleType (0x10A6FF0C | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x108AE74C | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x108AE7C4 | 1)
#define ADDR_GUIObject_Show (0x10A6FD14 | 1)
#define ADDR_SetFont (0x10A6A7CC | 1)
#define ADDR_DrawString (0x10A69C0C | 1)
#define ADDR_get_DisplayGC (0x10A6DB74 | 1)
#define ADDR_Display_GetHeight (0x11810F08 | 1)
#define ADDR_Display_GetWidth (0x11810F14 | 1)
#define ADDR_GC_PutChar (0x10A6E5AC | 1)
#define ADDR_GetImageWidth (0x10A6AEA4 | 1)
#define ADDR_GetImageHeight (0x10A6AEB8 | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)
#define ADDR_TextID_CreateIntegerID (0x10FFBD6C | 1)
#define ADDR_manifest_GetParam (0x10BA3410 | 1)
#define ADDR_DynamicMenu_SetElement_SecondLineText (0x10E73AF4 | 1)
