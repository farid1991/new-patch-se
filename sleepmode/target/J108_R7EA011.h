#pragma once

#define DB3350_R2
#define MissedEvents (char *)0x4BC03328

#define KEYLOCK_SLEEPMODE_ICN 0x1046
#define SILENT_SLEEPMODE_ICN 0x1E35
#define CALLS_MISSED_SLEEPMODE_ICN 0x479
#define SMS_SLEEPMODE_ICN 0x1EA2
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0x131F
#define APPOINTMENT_REMINDER_SLEEPMODE_ICN 0xDC
#define TASK_REMINDER_SLEEPMODE_ICN 0x918
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0x16BA

#define TEXTID_1 0x20E // Monday
#define TEXTID_2 0x281 // Thursday
#define TEXTID_3 0x2AC // Wednesday
#define TEXTID_4 0x290 // Tuesday
#define TEXTID_5 0x1DB // Friday
#define TEXTID_6 0x250 // Saturday
#define TEXTID_7 0x27E // Sunday

#define FONT_TIME MAKE_FONT(1, 80)
#define FONT_DATE MAKE_FONT(1, 40)
#define FONT_DAY MAKE_FONT(1, 50)

#define MISSED_STEP 5
#define MISSED_Y 5
#define TIME_Y 115
#define DATE_Y 60
#define DAY_Y 230

#define CID_CUIFontManager (PUUID)0x1571BACC
#define IID_IUIFontManager (PUUID)0x1575471C
#define CID_CTextRenderingManager (PUUID)0x15722A1C
#define IID_ITextRenderingManager (PUUID)0x1575A340
#define CID_CUIImageManager (PUUID)0x15720964
#define IID_IUIImageManager (PUUID)0x157576C0

#define ADDR_memalloc (0x4BC00394)
#define ADDR_memfree (0x4BC003BC)
#define ADDR_memset (0x145C5AE8)

#define ADDR_get_envp (0x101A1C18 | 1)
#define ADDR_set_envp (0x101A1C2C | 1)
#define ADDR_Timer_Set (0x143A995C | 1)
#define ADDR_Timer_ReSet (0x145B91D8 | 1)
#define ADDR_Timer_Kill (0x145B8DE8 | 1)

#define ADDR_TextID_Create (0x145B8610 | 1)
#define ADDR_TextID_Destroy (0x145B7C6C | 1)
#define ADDR_DispObject_InvalidateRect (0x144D7100 | 1)

#define ADDR_CoCreateInstance (0x144E924C | 1)
#define ADDR_get_DisplayGC (0x142CCD80 | 1)
#define ADDR_DisplayGC_AddRef (0x14370D88 | 1)
#define ADDR_TextObject_SetText (0x1427864C | 1)
#define ADDR_TextObject_SetFont (0x144AEC28 | 1)

#define ADDR_Display_GetHeight (0x144D60E0 | 1)
#define ADDR_Display_GetWidth (0x144D60D0 | 1)

#define ADDR_REQUEST_DATEANDTIME_GET (0x14093DB8 | 1)
#define ADDR_Date2ID (0x144BA2B4 | 1)
#define ADDR_Time2ID (0x144BB084 | 1)
#define ADDR_DATE_GetWeekDay (0x14115990 | 1)
