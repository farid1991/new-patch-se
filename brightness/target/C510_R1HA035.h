#pragma once

#define TEXTID_SAVE 0x120
#define TEXTID_BRIGHTNESS 0x2E8

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
#define ADDR__fopen (0x141FA214 | 1)
#define ADDR_fread (0x14178B8C | 1)
#define ADDR_fclose (0x143CD0A0 | 1)
#define ADDR_fstat (0x144D8BBC | 1)
#define ADDR_FSX_IsFileExists (0x14411678 | 1)
#define ADDR_TextID_Create (0x141818E4 | 1)
#define ADDR_TextID_CreateIntegerID (0x1401F5BC | 1)
#define ADDR_TextID_Destroy (0x14182788 | 1)
#define ADDR_DispObject_InvalidateRect (0x140CA948 | 1)
#define ADDR_CoCreateInstance (0x1401106C | 1)
#define ADDR_get_DisplayGC (0x1449E09C | 1)
#define ADDR_DisplayGC_AddRef (0x144CDAA4 | 1)
#define ADDR_TextObject_SetText (0x14183164 | 1)
#define ADDR_TextObject_SetFont (0x1449CD74 | 1)
#define ADDR_Display_GetHeight (0x140C93BC | 1)
#define ADDR_Display_GetWidth (0x140C93AC | 1)
#define ADDR_Display_GetBrightness (0x14D35A70 | 1)
#define ADDR_Display_SetBrightness (0x1541F1C8 | 1)
#define ADDR_Save_Brightness_Level (0x1541AF94 | 1)
#define ADDR_manifest_GetParam (0x141F620C | 1)
#define ADDR_FreeBook (0x141293FC | 1)
#define ADDR_UI_Event (0x140C5938 | 1)
#define ADDR_GUIObject_SetTitleType (0x14093534 | 1)
#define ADDR_GUIObject_Create (0x144CB8B0 | 1)
#define ADDR_BookObj_AddGUIObject (0x14285AEC | 1)
#define ADDR_DISP_DESC_SetName (0x142957C4 | 1)
#define ADDR_DISP_DESC_SetSize (0x142958A8 | 1)
#define ADDR_DISP_DESC_SetOnCreate (0x14295844 | 1)
#define ADDR_DISP_DESC_SetOnClose (0x14295840 | 1)
#define ADDR_DISP_DESC_SetOnRedraw (0x14295848 | 1)
#define ADDR_DISP_DESC_SetOnKey (0x14295990 | 1)
#define ADDR_DISP_DESC_SetOnRefresh (0x1429540C | 1)
#define ADDR_DISP_DESC_SetMethod06 (0x14295630 | 1)
#define ADDR_DISP_DESC_SetOnLayout (0x14295474 | 1)
#define ADDR_DISP_DESC_SetOnConfig (0x14295530 | 1)
#define ADDR_DispObject_SetLayerColor (0x140C6CA0 | 1)
#define ADDR_ImageID_Free (0x14410D58 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x144B9C9C | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x150D4864 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x150D48EC | 1)
#define ADDR_GUIObject_Show (0x144CB9BC | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x141C50C8 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1417BACC | 1)
