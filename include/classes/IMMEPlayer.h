#ifndef _IMMEPLAYER_H_
#define _IMMEPLAYER_H_

#include <base.h>

#include <types/IMMETypes.h>
#include <types/UIRect_types.h>

#ifdef __cplusplus
#include <classes/IUnknown.h>

// clang-format off
class IMMEPlayer : public IUnknown
{
public:
    virtual int GetHandle(FUint32 *handle);
    virtual int GetState(TMMEState *state);
    virtual int GetTime(TMMETime *elapsedTime);
    virtual int SetTime(TMMETime *offsetTime);
    virtual int SetDisplayAppearance(TUIRectangle *TMMEVideoArea);
    virtual int Play(FUint32 unk_null, TBool repeat);
    virtual int Pause();
    virtual int SetFastForwardRewindBoundaryConditions(TMMEWindCondition windCondition);
    virtual int SetWindTimerInterval(FUint32 time);
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
// clang-format on

#else

typedef struct IMMEPlayer IMMEPlayer;

typedef struct IMMEPlayerVtbl
{
	/* IUnknown */
	void *(*pguid)(IMMEPlayer *);
	void *(*QueryInterface)(IMMEPlayer *, void *, void **);
	void *(*AddRef)(IMMEPlayer *);
	void *(*Release)(IMMEPlayer *);

	/* IMMEPlayer */
	int (*GetHandle)(IMMEPlayer *, FUint32 *handle);
	int (*GetState)(IMMEPlayer *, uint8_t *state);
	int (*GetTime)(IMMEPlayer *, TMMETime *elapsedTime);
	int (*SetTime)(IMMEPlayer *, TMMETime *offsetTime);
	int (*SetDisplayAppearance)(IMMEPlayer *, TUIRectangle *);
	int (*Play)(IMMEPlayer *, FUint32, TBool);
	int (*Pause)(IMMEPlayer *);
	int (*SetFastForwardRewindBoundaryConditions)(IMMEPlayer *, TMMEWindCondition);
	int (*SetWindTimerInterval)(IMMEPlayer *, FUint32);
	int (*StartFastForward)(IMMEPlayer *);
	int (*StopFastForward)(IMMEPlayer *);
	int (*StartRewind)(IMMEPlayer *);
	int (*StopRewind)(IMMEPlayer *);
	int (*SlowMotion)(IMMEPlayer *);
	int (*SetFadeDownOnInterrupted)(IMMEPlayer *, TMMEFadeDirection);
	int (*StartAudioFade)(IMMEPlayer *);
	int (*Mute)(IMMEPlayer *);
	int (*UnMute)(IMMEPlayer *);
	int (*SetVolume)(IMMEPlayer *);
	int (*GetVolume)(IMMEPlayer *);
} IMMEPlayerVtbl;

struct IMMEPlayer
{
	IMMEPlayerVtbl *lpVtbl;
};

#define IMME_GetHandle(p, a) ((p)->lpVtbl->GetHandle((p), (a)))
#define IMME_GetState(p, a) ((p)->lpVtbl->GetState((p), (a)))
#define IMME_GetTime(p, a) ((p)->lpVtbl->GetTime((p), (a)))
#define IMME_SetTime(p, a) ((p)->lpVtbl->SetTime((p), (a)))
#define IMME_SetDisplayAppearance(p, a) ((p)->lpVtbl->SetDisplayAppearance((p), (a)))

#define IMME_Play(p, a, b) ((p)->lpVtbl->Play((p), (a), (b)))
#define IMME_Pause(p) ((p)->lpVtbl->Pause((p)))

#define IMME_StartFastForward(p) ((p)->lpVtbl->StartFastForward((p)))
#define IMME_StopFastForward(p) ((p)->lpVtbl->StopFastForward((p)))
#define IMME_StartRewind(p) ((p)->lpVtbl->StartRewind((p)))
#define IMME_StopRewind(p) ((p)->lpVtbl->StopRewind((p)))

#define IMME_SlowMotion(p) ((p)->lpVtbl->SlowMotion((p)))
#define IMME_Mute(p) ((p)->lpVtbl->Mute((p)))
#define IMME_UnMute(p) ((p)->lpVtbl->UnMute((p)))
#define IMME_SetVolume(p) ((p)->lpVtbl->SetVolume((p)))
#define IMME_GetVolume(p) ((p)->lpVtbl->GetVolume((p)))

#endif

#endif