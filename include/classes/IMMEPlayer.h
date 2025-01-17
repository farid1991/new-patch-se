#ifndef _IMMEPLAYER_H_
#define _IMMEPLAYER_H_

#include <base.h>
#include <classes/IMME_types.h>
#include <classes/IUnknown.h>

class IMMEPlayer : public IUnknown
{
public:
    virtual int GetHandle(uint32_t *handle);
    virtual int GetState(TMMEState *state);
    virtual int GetTime(TMMETime *elapsedTime);
    virtual int SetTime(TMMETime *offsetTime);
    virtual int SetDisplayAppearance(UIRECT *TMMEVideoArea);
    virtual int Play(uint32_t unk_null, uint8_t repeat);
    virtual int Pause();
    virtual int SetFastForwardRewindBoundaryConditions(TMMEWindCondition windCondition);
    virtual int SetWindTimerInterval(uint32_t time);
    virtual int StartFastForward();
    virtual int StopFastForward();
    virtual int StartRewind();
    virtual int StopRewind();
    virtual int SlowMotion();
    virtual int SetFadeDownOnInterrupted(TMMEFadeDirection fadeDirection);
    virtual int StartAudioFade();
    virtual int Mute();
    virtual int UnMute();
    virtual int SetVolume();
    virtual int GetVolume();
};

#endif