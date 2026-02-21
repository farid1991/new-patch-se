#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(U10_R7AA071)
#include <U10_R7AA071.h>
#elif defined(U100_R7AA076)
#include <U100_R7AA076.h>
#endif

#include <libse.h>

THUMB16 NEWCODE void *malloc(int size)
{
#if defined(DB2020)
    return (memalloc(0, size, 1, 5, "al", 0));
#elif defined(A2)
    return (memalloc(0xFFFFFFFF, size, 1, 5, "al", 0));
#else
    return memalloc(size, 1, 5, "al", 0);
#endif
}

THUMB16 NEWCODE void mfree(void *mem)
{
    if (mem)
#if defined(DB2020)
        memfree(0, mem, "al", 0);
#elif defined(A2)
        memfree(0, mem, "al", 0);
#else
        memfree(mem, "al", 0);
#endif
}

THUMB16 NEWCODE TEXTID GetRemainingTimeID(TIME *alarm)
{
    int _SYNC = 0;
    int *SYNC = &_SYNC;

    DATETIME datetime_real;
    REQUEST_DATEANDTIME_GET(SYNC, &datetime_real);
    int unix_real = datetime2unixtime(&datetime_real);

    DATETIME *datetime_alarm = (DATETIME *)malloc(sizeof(DATETIME));
    datetime_alarm->date.year = datetime_real.date.year;
    datetime_alarm->date.mon = datetime_real.date.mon;
    datetime_alarm->date.day = datetime_real.date.day + 1;
    datetime_alarm->time.hour = alarm->hour;
    datetime_alarm->time.min = alarm->min + 1;
    datetime_alarm->time.sec = 0;
    datetime_alarm->time.msec = 0;
    int unix_alarm = datetime2unixtime(datetime_alarm);

    DATETIME datetime_back;
    unixtime2datetime(unix_alarm - unix_real, &datetime_back);

    mfree(datetime_alarm);

    wchar_t buf[64];
    snwprintf(buf, MAXELEMS(buf), L"%02d:%02d (%02d:%02d)", alarm->hour, alarm->min, datetime_back.time.hour, datetime_back.time.min);
    return TextID_Create(buf, ENC_UCS2, TEXTID_ANY_LEN);
}
