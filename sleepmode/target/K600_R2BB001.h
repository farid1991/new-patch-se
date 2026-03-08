#pragma once

#define MISSED_EVENTS_PTR (char *)0x28244364

#define CALLS_MISSED_SLEEPMODE_ICN 0xE869
#define SMS_SLEEPMODE_ICN 0xE64C
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0xE64D
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0xE64E

#define TEXTID_1 0x15A // Monday
#define TEXTID_2 0x1A6 // Tuesday
#define TEXTID_3 0x1B6 // Wednesday
#define TEXTID_4 0x198 // Thursday
#define TEXTID_5 0x12E // Friday
#define TEXTID_6 0x176 // Saturday
#define TEXTID_7 0x196 // Sunday

#define FONT_D_24B 0x2F
#define FONT_D_29B 0x30
#define FONT_D_7R 0x00
#define FONT_E_14B 0x11
#define FONT_E_14BI 0x13
#define FONT_E_14I 0x12
#define FONT_E_14R 0x10
#define FONT_E_16B 0x18
#define FONT_E_16BI 0x1A
#define FONT_E_16I 0x19
#define FONT_E_16R 0x17
#define FONT_E_20B 0x26
#define FONT_E_20BI 0x28
#define FONT_E_20I 0x27
#define FONT_E_20R 0x25
#define FONT_ICON_16BIT_V2 0x38
#define FONT_ICON_2BIT_V2_2NDLCD 0x37

#define FONT_TIME FONT_D_29B
#define FONT_DATE FONT_E_20R
#define FONT_DAY FONT_E_20R

#define TIME_Y 85
#define DATE_Y 50
#define DAY_Y 150
#define MISSED_Y 3

#define ADDR_memalloc (0x20363C0C | 1)
#define ADDR_memfree (0x20364D24 | 1)
#define ADDR_memset (0x20D66768 | 1)
#define ADDR_set_envp (0x2006CF5E | 1)
#define ADDR_get_envp (0x2006CF4A | 1)

#define ADDR_snwprintf (0x20D67990 | 1)
#define ADDR__fopen (0x204DBDF4 | 1)
#define ADDR_fread (0x204DD2F0 | 1)
#define ADDR_fclose (0x204DCFD4 | 1)
#define ADDR_fwrite (0x204DD58C | 1)
#define ADDR_fstat (0x204DC6B4 | 1)
#define ADDR_TextID_Create (0x202CFF38 | 1)
#define ADDR_TextID_Destroy (0x202D0210 | 1)
#define ADDR_CreateMessageBox (0x20431AF0 | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x20753884 | 1)
#define ADDR_GUIObject_GetBook (0x20280EEC | 1)

#define ADDR_FindBook (0x20425C9C | 1)
#define ADDR_IsScreenSaverBook (0x20761A1C | 1)
#define ADDR_GUIObject_GetDispObject (0x20280EC4 | 1)
#define ADDR_DispObject_InvalidateRect (0x202647D4 | 1)
#define ADDR_DispObject_SetBacklightMode (0x20267D8C | 1)

#define ADDR_Timer_Set (0x2025C1A0 | 1)
#define ADDR_Timer_ReSet (0x2025C1D8 | 1)
#define ADDR_Timer_Kill (0x2025C228 | 1)

#define ADDR_Display_GetWidth (0x2042E154 | 1)
#define ADDR_GetImageHeight (0x20269660 | 1)
#define ADDR_REQUEST_DATEANDTIME_GET (0x204BD5DC | 1)
#define ADDR_Time2ID (0x2074B830 | 1)
#define ADDR_Date2ID (0x2074B918 | 1)
#define ADDR_DATE_GetWeekDay (0x20223624 | 1)

#define ADDR_SetFont (0x20268F18 | 1)
#define ADDR_DrawString (0x202683C4 | 1)
#define ADDR_get_DisplayGC (0x2075B474 | 1)
#define ADDR_GC_PutChar (0x2075BF54 | 1)
#define ADDR_GetImageWidth (0x20269660 | 1)