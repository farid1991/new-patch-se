#ifndef SOUND_RECORDER_H
#define SOUND_RECORDER_H

#include <base.h>
#include <textid.h>

enum RECORDER_TYPE
{
    MMS_Recorder = 1,
    Sound_Recorder,
    TrackID_Recorder,
};

enum RECORDER_STYLE
{
    PopupNoFrame,
    FullScreen,
};

typedef struct
{
    uint8_t dummy[0x40C];
    uint8_t t[0x10];
    uint8_t RecordTimeFlag;
    uint8_t RecordOpenFlag;
    uint16_t _unk;
    uint32_t RadioVal;
    TEXTID RecorderTitle;
    uint8_t RecorderStyle;
} SOUND_RECORDER_DESC;

#endif // SOUND_RECORDER_H