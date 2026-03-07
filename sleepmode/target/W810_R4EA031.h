#pragma once

#define MISSED_EVENTS_PTR (char *)0x4C2E666F

#define CALLS_MISSED_SLEEPMODE_ICN 0xE5D2
#define SMS_SLEEPMODE_ICN 0xE9A0
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0xE892
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0xE8F3

#define TEXTID_1 0x167 // Monday
#define TEXTID_2 0x1A7 // Tuesday
#define TEXTID_3 0x1CC // Wednesday
#define TEXTID_4 0x1B5 // Thursday
#define TEXTID_5 0x139 // Friday
#define TEXTID_6 0x183 // Saturday
#define TEXTID_7 0x1A5 // Sunday

#define FONT_D_18B 0x2D
#define FONT_D_24B 0x2F
#define FONT_D_29B 0x30
#define FONT_E_14B 0x11
#define FONT_E_14BI 0x13
#define FONT_E_14I 0x12
#define FONT_E_14R 0x10
#define FONT_E_16B 0x18
#define FONT_E_16BI 0x1A
#define FONT_E_16I 0x19
#define FONT_E_16R 0x17
#define FONT_E_20B 0x25
#define FONT_E_20BI 0x27
#define FONT_E_20I 0x26
#define FONT_E_20R 0x24
#define FONT_ICON_16BIT_V2 0x38

#define FONT_TIME FONT_D_29B
#define FONT_DATE FONT_E_20R
#define FONT_DAY FONT_E_20R

#define TIME_Y 85
#define DATE_Y 50
#define DAY_Y 150
#define MISSED_Y 3

#define ADDR_memalloc (0x45453AA8 | 1)
#define ADDR_memfree (0x454547E0 | 1)
#define ADDR_memcmp (0x44E242F4 | 1)
#define ADDR_memcpy (0x4418E878)
#define ADDR_memset (0x44E24360 | 1)
#define ADDR_get_envp (0x44149CF6 | 1)
#define ADDR_set_envp (0x44149D0A | 1)
#define ADDR_Timer_Set (0x4529EAC0 | 1)
#define ADDR_Timer_ReSet (0x4529EAE4 | 1)
#define ADDR_Timer_Kill (0x4529EB10 | 1)

#define ADDR_TextID_Create (0x452FE69C | 1)
#define ADDR_TextID_Destroy (0x452FE86C | 1)

#define ADDR_REQUEST_DATEANDTIME_GET (0x455953A4 | 1)
#define ADDR_Date2ID (0x45150BE0 | 1)
#define ADDR_Time2ID (0x45150AF8 | 1)
#define ADDR_DATE_GetWeekDay (0x4526CB00 | 1)

#define ADDR_DispObject_InvalidateRect (0x45302A70 | 1)
#define ADDR_SetFont (0x45307888 | 1)
#define ADDR_DrawString (0x45306D48 | 1)
#define ADDR_DrawRect (0x45306940 | 1)
#define ADDR_get_DisplayGC (0x45191A98 | 1)
#define ADDR_GC_PutChar (0x451925BC | 1)
#define ADDR_GetImageWidth (0x45307FC0 | 1)
#define ADDR_GetImageHeight (0x45307FD8 | 1)
#define ADDR_Display_GetHeight (0x45547974 | 1)
#define ADDR_Display_GetWidth (0x45547984 | 1)
