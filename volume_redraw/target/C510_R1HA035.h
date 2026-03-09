#pragma once

#define DIR_OTHER_PATH (wchar_t *)0x15A88970
#define DEFAULT_CFG_PATH (wchar_t *)0x15A86E38

#define JAVA_STR (char *)0x15A38E9C
#define FOREIGN_APP_STR (char *)0x1594776C

#define CID_CUIFontManager (PUUID)0x15AC227C
#define IID_IUIFontManager (PUUID)0x15AFB108
#define CID_CUIImageManager (PUUID)0x15AC4F1C
#define IID_IUIImageManager (PUUID)0x15AFD4C4
#define CID_CTextRenderingManager (PUUID)0x15AC99C4
#define IID_ITextRenderingManager (PUUID)0x15AFFFA4

#define ADDR_memalloc (0x4BA32698)
#define ADDR_memfree (0x4BA326C0)
#define ADDR_memset (0x14B31C80)
#define ADDR_get_envp (0x101D68A8 | 1)
#define ADDR_set_envp (0x101D68BC | 1)
#define ADDR_strncmp (0x141C7A0C | 1)
#define ADDR_strcmp (0x14C0BA78 | 1)
#define ADDR_wstrcmp (0x144D9600 | 1)
#define ADDR_wstrcpy (0x144D851C | 1)
#define ADDR_BookObj_GetSession (0x14481EB8 | 1)
#define ADDR_TextID_CreateIntegerID (0x1401F5BC | 1)
#define ADDR_TextID_Create (0x141818E4 | 1)
#define ADDR_TextID_Copy (0x14181E88 | 1)
#define ADDR_TextID_GetString (0x14182108 | 1)
#define ADDR_TextID_Destroy (0x14182788 | 1)
#define ADDR__fopen (0x141FA214 | 1)
#define ADDR_fread (0x14178B8C | 1)
#define ADDR_fclose (0x143CD0A0 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x144B9C9C | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x150D4864 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x150D48EC | 1)
#define ADDR_FSX_IsFileExists (0x14411678 | 1)
#define ADDR_DrawRect (0x1445A7BC | 1)
#define ADDR_DispObject_GetGUI (0x142A8F2C | 1)
#define ADDR_GUIObject_GetBook (0x140CAEC8 | 1)
#define ADDR_FindBook (0x140CC010 | 1)
#define ADDR_CoCreateInstance (0x1401106C | 1)
#define ADDR_get_DisplayGC (0x1449E09C | 1)
#define ADDR_DisplayGC_AddRef (0x144CDAA4 | 1)
#define ADDR_TextObject_SetText (0x14183164 | 1)
#define ADDR_TextObject_SetFont (0x1449CD74 | 1)

#define ADDR_MainDisplay_GetTopBook (0x1427D1BC | 1)
#define ADDR_GUIObject_GetDispObject (0x140CACD8 | 1)
#define ADDR_Display_GetHeight (0x140C93BC | 1)
#define ADDR_Display_GetWidth (0x140C93AC | 1)
#define ADDR_DispObject_WindowSetSize (0x140CA498 | 1)
#define ADDR_DispObject_SetLayerColor (0x140C6CA0 | 1)
#define ADDR_DispObject_SetAnimation (0x14E1B408 | 1)

#define ADDR_is_mocallbook (0x1422B2D8 | 1)

#define ADDR_VolumeControl_OnCreate (0x14EED68C | 1)
#define ADDR_VolumeControl_OnClose (0x14CB7648 | 1)
#define ADDR_VolumeControl_OnRedraw (0x14E9E7CC | 1)
#define ADDR_pg_VolumeControl_Active_EnterEvent (0x14F295F0 | 1)