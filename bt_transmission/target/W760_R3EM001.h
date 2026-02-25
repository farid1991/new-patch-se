#pragma once

#define RECT_X1 86
#define RECT_X2 198
#define RECT_Y1 3
#define RECT_Y2 21
#define STR_X1 88
#define STR_X2 196
#define STR_Y1 3
#define STR_Y2 60

#define FONT_E_14B 0x13

#define ADDR_pg_ObEx_ReceiveFile (0x10940748 | 1)
#define ADDR_pg_ObEx_SendFile (0x10941350 | 1)
#define ADDR_pg_ObEx_SendMultipleFiles (0x109413B4 | 1)
#define ADDR_pg_ObEx_FileSent (0x1094178C | 1)
#define ADDR_IsObExSendBook (0x10940858 | 1)

#define ADDR_StatusRow_OnRedraw (0x11803C8C | 1)

#define ADDR_snwprintf (0x10798B34 | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)
#define ADDR_FindBook (0x10E87DE4 | 1)
#define ADDR_Display_GetTopBook (0x10E89690 | 1)
#define ADDR_SetFont (0x10A6A7CC | 1)
#define ADDR_DrawString (0x10A69C0C | 1)
#define ADDR_DrawRect (0x10A698C0 | 1)