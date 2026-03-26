#pragma once

#define DB3350_R2

#define KEY_ESC 0x4
#define KEY_DEL 0x5
#define KEY_ENTER 0x8

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

#define KEY_STAR 0x22
#define KEY_DIEZ 0x23
#define KEY_UP 0x9
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
#define RETURN_TO_STANDBY_EVENT 0x840

#define FONT_D_18B 0x112
#define FONT_D_24B 0x118
#define FONT_D_29B 0x11D
#define FONT_D_7R 0x7
#define FONT_E_100R 0x64
#define FONT_E_12B 0x10C
#define FONT_E_12R 0xC
#define FONT_E_14B 0x10E
#define FONT_E_14BI 0x30E
#define FONT_E_14I 0x20E
#define FONT_E_14R 0xE
#define FONT_E_16B 0x110
#define FONT_E_16BI 0x310
#define FONT_E_16I 0x210
#define FONT_E_16R 0x10
#define FONT_E_18B 0x112
#define FONT_E_18BI 0x312
#define FONT_E_18I 0x212
#define FONT_E_18R 0x12
#define FONT_E_20B 0x114
#define FONT_E_20BI 0x314
#define FONT_E_20I 0x214
#define FONT_E_20R 0x14
#define FONT_E_22B 0x116
#define FONT_E_22BI 0x316
#define FONT_E_22I 0x216
#define FONT_E_22R 0x16
#define FONT_E_24B 0x118
#define FONT_E_24BI 0x318
#define FONT_E_24I 0x218
#define FONT_E_24R 0x18
#define FONT_E_25B 0x119
#define FONT_E_25BI 0x319
#define FONT_E_25I 0x219
#define FONT_E_25R 0x19
#define FONT_E_30R 0x1E
#define FONT_E_36R 0x24
#define FONT_E_40R 0x28
#define FONT_E_50R 0x32
#define FONT_E_60R 0x3C
#define FONT_E_75R 0x49
#define FONT_E_8R 0x8

#define CID_CUIFontManager (PUUID)0x1571BACC
#define IID_IUIFontManager (PUUID)0x1575471C
#define CID_CTextRenderingManager (PUUID)0x15722A1C
#define IID_ITextRenderingManager (PUUID)0x1575A340
#define CID_CUIImageManager (PUUID)0x15720964
#define IID_IUIImageManager (PUUID)0x157576C0

#define RING_VOLUME_TXT 0x11FB

#define ADDR_memalloc (0x4BC00394)
#define ADDR_memfree (0x4BC003BC)
#define ADDR_memset (0x145C5AE8)

#define ADDR_snwprintf (0x145C4A3C | 1)
#define ADDR_TextID_Create (0x145B8610 | 1)
#define ADDR_TextID_Destroy (0x145B7C6C | 1)
#define ADDR_Volume_Get (0x144DA0C0 | 1)
#define ADDR_Volume_Set (0x144DC690 | 1)

#define ADDR_DISP_DESC_SetSize (0x1448D778 | 1)
#define ADDR_DISP_DESC_SetName (0x1448D77C | 1)
#define ADDR_DISP_DESC_SetOnCreate (0x1448D7F0 | 1)
#define ADDR_DISP_DESC_SetOnClose (0x1448D780 | 1)
#define ADDR_DISP_DESC_SetOnRedraw (0x1448D774 | 1)
#define ADDR_DISP_DESC_SetOnKey (0x1448D300 | 1)
#define ADDR_DISP_DESC_SetOnLayout (0x1448D8C8 | 1)
#define ADDR_DispObject_InvalidateRect (0x144D7100 | 1)
#define ADDR_DispObject_SetLayerColor (0x14566D90 | 1)

#define ADDR_GUIObject_Create (0x141798F4 | 1)
#define ADDR_GUIObject_SetTitleType (0x143F4A74 | 1)
#define ADDR_GUIObject_SetTitleText (0x14053100 | 1)
#define ADDR_GUIObject_Show (0x1417A694 | 1)
#define ADDR_GUIObject_Destroy (0x14554DF4 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1455ADF0 | 1)

#define ADDR_DrawRect (0x141A41F0 | 1)

#define ADDR_REQUEST_SETTING_RINGVOLUME_SET (0x15303A14 | 1)

#define ADDR_CreateBook (0x14179108 | 1)
#define ADDR_FreeBook (0x1417924C | 1)
#define ADDR_BookObj_AddGUIObject (0x141798E8 | 1)
#define ADDR_BookObj_SetFocus (0x141775BC | 1)
#define ADDR_BookObj_GotoPage (0x1404FF00 | 1)

#define ADDR_CoCreateInstance (0x144E924C | 1)
#define ADDR_get_DisplayGC (0x142CCD80 | 1)
#define ADDR_DisplayGC_AddRef (0x14370D88 | 1)
#define ADDR_TextObject_SetText (0x1427864C | 1)
#define ADDR_TextObject_SetFont (0x144AEC28 | 1)

#define ADDR_onBackPressed (0x14F51494 | 1)
#define ADDR_onLongBackPressed (0x14F7F9C0 | 1)
