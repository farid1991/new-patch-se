#pragma once

#define DIR_OTHER_PATH (wchar_t *)0x11E36A54
#define DEFAULT_CFG_PATH (wchar_t *)0x11E350A4

#define JAVA_STR (char *)0x11C58418
#define FOREIGN_APP_STR (char *)0x11C1BF24

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x4BB01144)
#define ADDR_set_envp (0x10005C4C | 1)
#define ADDR_get_envp (0x10005C38 | 1)
#define ADDR_strncmp (0x107989A0 | 1)
#define ADDR_strcmp (0x10798908 | 1)
#define ADDR_wstrcmp (0x10E01194 | 1)
#define ADDR_get_DisplayGC (0x10A6DB74 | 1)
#define ADDR_BookObj_GetSession (0x10E8A278 | 1)
#define ADDR_TextID_GetString (0x10FFC64C | 1)
#define ADDR__fopen (0x109F5840 | 1)
#define ADDR_fread (0x109F71D4 | 1)
#define ADDR_fclose (0x117A443C | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x10843910 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x10843988 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x10843A10 | 1)
#define ADDR_FSX_IsFileExists (0x1188A9F4 | 1)
#define ADDR_DrawRect (0x10A698C0 | 1)
#define ADDR_GC_PutChar (0x10A6E5AC | 1)
#define ADDR_GetImageHeight (0x10A6AEB8 | 1)
#define ADDR_GetImageWidth (0x10A6AEA4 | 1)
#define ADDR_SetFont (0x10A6A7CC | 1)
#define ADDR_DrawString (0x10A69C0C | 1)
#define ADDR_wstrcpy (0x10E011C4 | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)
#define ADDR_DispObject_GetGUI (0x10A65E20 | 1)
#define ADDR_GUIObject_GetBook (0x10A6FBC0 | 1)
#define ADDR_FindBook (0x10E87DE4 | 1)
#define ADDR_TextID_CreateIntegerID (0x10FFBD6C | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_Copy (0x10FFC120 | 1)
#define ADDR_MainDisplay_GetTopBook (0x10E8968C | 1)
#define ADDR_GUIObject_GetDispObject (0x10A6FBAC | 1)
#define ADDR_Display_GetHeight (0x11810F08 | 1)
#define ADDR_Display_GetWidth (0x11810F14 | 1)
#define ADDR_DispObject_WindowSetSize (0x10A67824 | 1)
#define ADDR_DispObject_SetLayerColor (0x10A68734 | 1)
#define ADDR_DispObject_SetAnimation (0x10A687EC | 1)

#define ADDR_is_mocallbook (0x10E9E8DC | 1)

#define ADDR_VolumeControl_OnCreate (0x11B48FBC | 1)
#define ADDR_VolumeControl_OnClose (0x11B491E4 | 1)
#define ADDR_VolumeControl_OnRedraw (0x11B49748 | 1)
#define ADDR_pg_VolumeControl_Active_EnterEvent (0x11B49C7C | 1)
