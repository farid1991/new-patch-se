#pragma once

#define RECT_X1 86
#define RECT_X2 198
#define RECT_Y1 3
#define RECT_Y2 21
#define STR_X1 88
#define STR_X2 196
#define STR_Y1 3
#define STR_Y2 60

#define FONT_E_14B 0x10E

#define CID_CUIFontManager (PUUID)0x1571BACC
#define IID_IUIFontManager (PUUID)0x1575471C
#define CID_CTextRenderingManager (PUUID)0x15722A1C
#define IID_ITextRenderingManager (PUUID)0x1575A340

#define ADDR_pg_ObEx_ReceiveFile (0x1445A79C | 1)
#define ADDR_pg_ObEx_SendFile (0x14956ED0 | 1)
#define ADDR_pg_ObEx_SendMultipleFiles (0x14D073C0 | 1)
#define ADDR_pg_ObEx_FileSent (0x146BDCA4 | 1)
#define ADDR_IsObExSendBook (0x14860B08 | 1)

#define ADDR_StatusRow_OnRedraw (0x141B6794 | 1)

#define ADDR_snwprintf (0x145C4A3C | 1)
#define ADDR_TextID_Create (0x145B8610 | 1)
#define ADDR_TextID_Destroy (0x145B7C6C | 1)
#define ADDR_FindBook (0x1445FFC0 | 1)

#define ADDR_Display_GetTopBook (0x14050D80 | 1)
#define ADDR_DrawRect (0x141A41F0 | 1)

#define ADDR_memset (0x145C5AE8)
#define ADDR_CoCreateInstance (0x144E924C | 1)
#define ADDR_get_DisplayGC (0x142CCD80 | 1)
#define ADDR_DisplayGC_AddRef (0x14370D88 | 1)
#define ADDR_TextObject_SetText (0x1427864C | 1)
#define ADDR_TextObject_SetFont (0x144AEC28 | 1)