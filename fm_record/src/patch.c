#include <libse.h>
#include <book/FmRadio_Book.h>
#include <soundrecorder.h>

#if defined(C510_R1HA035)
    #include "C510_R1HA035.h"
#endif

#define NEWCODE __attribute__((section(".text.patch_section")))

#define SoundRecorderDesc_Create ((void *(*)())ADDR_SoundRecorderDesc_Create)
#define SoundRecorderDesc_Destroy ((void (*)(void *desc))ADDR_SoundRecorderDesc_Destroy)
#define SoundRecorderDesc_SetBookID ((int (*)(void *desc, int BookID))ADDR_SoundRecorderDesc_SetBookID)
#define SoundRecorderDesc_SetType ((int (*)(void *desc, const int type))ADDR_SoundRecorderDesc_SetType)
#define SoundRecorderDesc_SetFolder ((int (*)(void *desc, const wchar_t *fpath))ADDR_SoundRecorderDesc_SetFolder)
#define SoundRecorderDesc_SetFname ((int (*)(void *desc, const wchar_t *fname))ADDR_SoundRecorderDesc_SetFname)
#define SoundRecorderDesc_SetRecordSize ((int (*)(void *desc, const int size))ADDR_SoundRecorderDesc_SetRecordSize)
#define SoundRecorderDesc_SetRadioVal ((int (*)(void *desc, int value))ADDR_SoundRecorderDesc_SetRadioVal)
#define SoundRecorderDesc_SetTitle ((int (*)(void *desc, TEXTID Title))ADDR_SoundRecorderDesc_SetTitle)
#define SoundRecorderDesc_SetStyle ((int (*)(void *desc, int style))ADDR_SoundRecorderDesc_SetStyle)
#define SoundRecorder_Create ((int (*)(void *desc))ADDR_SoundRecorder_Create)

#define mkdir ((int (*)(const wchar_t *path))ADDR_mkdir)
#define snwprintf ((int (*)(wchar_t *, int, const wchar_t *, ...))ADDR_snwprintf)
#define REQUEST_DATEANDTIME_GET ((void (*)(int *, DATETIME *))ADDR_REQUEST_DATEANDTIME_GET)
#define TextID_Create ((int (*)(const void *, int, int))ADDR_TextID_Create)

#define FNAME_SIZE 256

THUMB16 NEWCODE void FMRadio_Record(BOOK *book, GUI *gui)
{
    FmRadio_Book *fm_book = (FmRadio_Book *)book;
    SOUND_RECORDER_DESC *desc = (SOUND_RECORDER_DESC *)SoundRecorderDesc_Create();
    if (desc)
    {
        SoundRecorderDesc_SetBookID(desc, NO_BOOK_ID);
        SoundRecorderDesc_SetType(desc, TrackID_Recorder);
        SoundRecorderDesc_SetTitle(desc, RECORDING_TEXTID);
        SoundRecorderDesc_SetRadioVal(desc, fm_book->RadioVal);

        mkdir(L"/card/music/FM");
        SoundRecorderDesc_SetFolder(desc, L"/card/music/FM");

        int _SYNC = 0;
        int *SYNC = &_SYNC;
        DATETIME dt;
        REQUEST_DATEANDTIME_GET(SYNC, &dt);

        wchar_t filename[FNAME_SIZE];
        snwprintf(filename,
                  MAXELEMS(filename),
                  L"fm-%ls-%d-%02d_%02d_%d-%02d:%02d.amr",
                  fm_book->Channel[fm_book->CurrentChannel - 1].Name,
                  fm_book->CurrentFrequency,
                  dt.date.day, dt.date.mon, dt.date.year,
                  dt.time.hour, dt.time.min);
        SoundRecorderDesc_SetFname(desc, filename);

        SoundRecorderDesc_SetStyle(desc, PopupNoFrame);
        SoundRecorder_Create(desc);
        SoundRecorderDesc_Destroy(desc);
    }
}