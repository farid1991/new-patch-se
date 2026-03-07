#pragma once

#define MISSED_EVENTS_PTR (char *)0x4BB9E4A0

#define KEYLOCK_SLEEPMODE_ICN 0xECA2
#define SILENT_SLEEPMODE_ICN 0xF40F
#define CALLS_MISSED_SLEEPMODE_ICN 0xE5B3
#define SMS_SLEEPMODE_ICN 0xF4A7
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0xED71
#define APPOINTMENT_REMINDER_SLEEPMODE_ICN 0xE557
#define TASK_REMINDER_SLEEPMODE_ICN 0xF51A
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0xEE25

#define TEXTID_1 0x1D2 // Monday
#define TEXTID_2 0x252 // Thursday
#define TEXTID_3 0x281 // Wednesday
#define TEXTID_4 0x261 // Tuesday
#define TEXTID_5 0x190 // Friday
#define TEXTID_6 0x21D // Saturday
#define TEXTID_7 0x24E // Sunday

#define FONT_TIME 0x5E
#define FONT_DATE 0x55
#define FONT_DAY 0x55

#define MISSED_STEP 5
#define MISSED_Y 5
#define TIME_Y 115
#define DATE_Y 60
#define DAY_Y 230

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x4BB01144)
#define ADDR_memcmp (0x126B3F40)
#define ADDR_get_envp (0x10005C38 | 1)
#define ADDR_set_envp (0x10005C4C | 1)
#define ADDR_Timer_Set (0x10E8618C | 1)
#define ADDR_Timer_ReSet (0x10E861C0 | 1)
#define ADDR_Timer_Kill (0x10E86218 | 1)

#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)

#define ADDR_REQUEST_DATEANDTIME_GET (0x1084D8F4 | 1)
#define ADDR_Date2ID (0x11AEB39C | 1)
#define ADDR_Time2ID (0x11AEB2B8 | 1)
#define ADDR_DATE_GetWeekDay (0x10C68CA8 | 1)
             
#define ADDR_DispObject_InvalidateRect (0x10A6653C | 1)
#define ADDR_SetFont (0x10A6A7CC | 1)
#define ADDR_DrawString (0x10A69C0C | 1)
#define ADDR_DrawRect (0x10A698C0 | 1)
#define ADDR_get_DisplayGC (0x10A6DB74 | 1)
#define ADDR_GC_PutChar (0x10A6E5AC | 1)
#define ADDR_GetImageWidth (0x10A6AEA4 | 1)
#define ADDR_GetImageHeight (0x10A6AEB8 | 1)
#define ADDR_Display_GetHeight (0x11810F08 | 1)
#define ADDR_Display_GetWidth (0x11810F14 | 1)
