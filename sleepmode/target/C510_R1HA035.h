#pragma once

#define MissedEvents (char *)0x4BA1B07C

#define KEYLOCK_SLEEPMODE_ICN 0x47B
#define SILENT_SLEEPMODE_ICN 0x869
#define CALLS_MISSED_SLEEPMODE_ICN 0xD1
#define SMS_SLEEPMODE_ICN 0x8A7
#define MMS_NEW_MESSAGE_SLEEPMODE_ICN 0x55D
#define APPOINTMENT_REMINDER_SLEEPMODE_ICN 0x3
#define TASK_REMINDER_SLEEPMODE_ICN 0x918
#define MSG_UI_EMAIL_MESSAGE_SLEEPMODE_ICN 0x636

#define TEXTID_1 0x1D6 // Monday
#define TEXTID_2 0x246 // Thursday
#define TEXTID_3 0x26B // Wednesday
#define TEXTID_4 0x253 // Tuesday
#define TEXTID_5 0x1A6 // Friday
#define TEXTID_6 0x217 // Saturday
#define TEXTID_7 0x243 // Sunday

#define FONT_TIME MAKE_FONT(1, 80)
#define FONT_DATE MAKE_FONT(1, 40)
#define FONT_DAY MAKE_FONT(1, 50)

#define MISSED_STEP 5
#define MISSED_Y 5
#define TIME_Y 115
#define DATE_Y 60
#define DAY_Y 230

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
#define ADDR_Timer_Set (0x1449FF70 | 1)
#define ADDR_Timer_ReSet (0x1417A1C4 | 1)
#define ADDR_Timer_Kill (0x1417A7F0 | 1)

#define ADDR_TextID_Create (0x141818E4 | 1)
#define ADDR_TextID_Destroy (0x14182788 | 1)
#define ADDR_DispObject_InvalidateRect (0x140CA948 | 1)

#define ADDR_CoCreateInstance (0x1401106C | 1)
#define ADDR_get_DisplayGC (0x1449E09C | 1)
#define ADDR_DisplayGC_AddRef (0x144CDAA4 | 1)
#define ADDR_TextObject_SetText (0x14183164 | 1)
#define ADDR_TextObject_SetFont (0x1449CD74 | 1)

#define ADDR_Display_GetHeight (0x140C93BC | 1)
#define ADDR_Display_GetWidth (0x140C93AC | 1)

#define ADDR_REQUEST_DATEANDTIME_GET (0x140C4E48 | 1)
#define ADDR_Date2ID (0x143A0B38 | 1)
#define ADDR_Time2ID (0x1430989C | 1)
#define ADDR_DATE_GetWeekDay (0x14428310 | 1)
