#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#elif defined(W810_R4EA031)
#include <W810_R4EA031.h>
#endif

#include <libse.h>
#include <sync.h>

#include <types/Colors.h>
#include <types/UIRichText_types.h>

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"
#endif

#include "patch.h"

THUMB16 NEWCODE void *malloc(int size)
{
#if defined(DB2020)
    return memalloc(0, size, 1, 5, MEM_NAME, 0);
#elif defined(A2)
    return memalloc(-1, size, 1, 5, MEM_NAME, 0);
#else
    return memalloc(size, 1, 5, MEM_NAME, 0);
#endif
}

THUMB16 NEWCODE void mfree(void *mem)
{
    if (mem)
#if defined(DB2020) || defined(A2)
        memfree(0, mem, MEM_NAME, 0);
#else
        memfree(mem, MEM_NAME, 0);
#endif
}

THUMB16 NEWCODE uint16_t *get_timer_id()
{
    return (uint16_t *)get_envp(NULL, EMP_NAME);
}

THUMB16 NEWCODE uint16_t *create_timer_id()
{
    uint16_t *timer_id = (uint16_t *)malloc(sizeof(uint16_t));
    memset(timer_id, 0, sizeof(uint16_t));
    set_envp(NULL, EMP_NAME, (OSADDRESS)timer_id);
    return timer_id;
}

THUMB16 NEWCODE void onTimer(uint16_t timerID, LPARAM disp_obj)
{
    uint16_t *timer_id = get_timer_id();
    DispObject_InvalidateRect((DISP_OBJ *)disp_obj, NULL);
    Timer_ReSet(timer_id, 1000, onTimer, disp_obj);
}

THUMB16 NEWCODE void SetRefreshTimer(DISP_OBJ *disp_obj)
{
    uint16_t *timer_id = get_timer_id();
    if (!timer_id)
        timer_id = create_timer_id();
    *timer_id = Timer_Set(0, onTimer, (LPARAM)disp_obj);
}

THUMB16 NEWCODE void KillRefreshTimer()
{
    uint16_t *timer_id = get_timer_id();
    if (timer_id)
    {
        Timer_Kill(timer_id);
        *timer_id = 0;
        set_envp(NULL, EMP_NAME, 0);
    }
}

THUMB16 NEWCODE void DrawText(int font, TEXTID text, int align, int x1, int y1, int x2, int y2, int pen_color)
{
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
    dll_DrawString(font, text, align, x1, y1, x2, y2 + (font & 0xFF), pen_color);
#else
    SetFont(font);
    DrawString(text, align, x1, y1, x2, y2 + GetImageHeight(' '), 20, 5, pen_color, pen_color);
#endif
}

THUMB16 NEWCODE void New_SleepMode_OnRedraw(DISP_OBJ *disp_obj, int a, int b, int c)
{
    uint16_t disp_width = Display_GetWidth(UIDisplay_Main);
    TEXTID text_id;

    DATETIME dt;
    REQUEST_DATEANDTIME_GET(&SYNC, &dt);

    text_id = Time2ID(&dt.time, 2, FALSE);
    DrawText(FONT_TIME, text_id, AlignCenter, 0, TIME_Y, disp_width, TIME_Y, clBlack);
    TextID_Destroy(text_id);

    text_id = Date2ID(&dt.date, 0, 1);
    DrawText(FONT_DATE, text_id, AlignCenter, 0, DATE_Y, disp_width, DATE_Y, clBlack);
    TextID_Destroy(text_id);

    char weekday;
    DATE_GetWeekDay(&dt.date, &weekday);
    text_id = WEEKDAYS[weekday];
    DrawText(FONT_DAY, text_id, AlignCenter, 0, DAY_Y, disp_width, DAY_Y, clBlack);
    TextID_Destroy(text_id);

    int missed[ICONS_COUNT];
    int *p = missed;
    int m = *(MISSED_EVENTS_PTR);
    int i;
    for (i = 0; i < ICONS_COUNT; i++)
    {
        if (m & (1 << i))
            *p++ = missed_icons[i];
    }

    int x = 0;
    for (i = 0; i < (p - missed); i++)
    {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        x = x + dll_GetImageWidth(missed[i]);
#else
        x = x + GetImageWidth(missed[i]);
#endif
    }

    x = (disp_width - (x + (i - 1) * 10)) / 2;
    for (i = 0; i < (p - missed); i++)
    {
#if defined(DB3200) || defined(DB3210) || defined(DB3350)
        dll_GC_PutChar(x, MISSED_Y, 0, 0, missed[i]);
        x = x + 10 + dll_GetImageWidth(missed[i]);
#else
        GC_PutChar(get_DisplayGC(), x, MISSED_Y, 0, 0, missed[i]);
        x = x + 10 + GetImageWidth(missed[i]);
#endif
    }
}
