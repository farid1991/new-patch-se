#include <libse.h>
#include <classes/IMMEPlayer.h>

#if defined(C510_R1HA035)
    #include <C510_R1HA035.h>
#endif

#define NEWCODE __attribute__((section(".text.patch_section")))

#define GUIObject_SoftKeys_SetVisible ((void (*)(GUI *, uint16_t, BOOL))ADDR_GUIObject_SoftKeys_SetVisible)
#define BrowserItem_Get_SUB_EXECUTE ((SUB_EXECUTE *(*)(BOOK *))ADDR_BrowserItem_Get_SUB_EXECUTE)

extern "C" void db_action_pause(BOOK *book, GUI *gui) THUMB16 NEWCODE;

extern "C" void db_action_pause(BOOK *book, GUI *gui)
{
  SUB_EXECUTE *sub_execute = BrowserItem_Get_SUB_EXECUTE(book);
  TMMEState state;

  IMMEPlayer *pIMMEPlayer = (IMMEPlayer *)sub_execute->pIMMEPlayer;
  pIMMEPlayer->GetState(&state);
  if (state == TMMEState_Playing)
  {
    pIMMEPlayer->Pause();
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, TRUE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, FALSE);
  }
  else
  {
    pIMMEPlayer->Play(NULL, FALSE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, FALSE);
    GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, TRUE);
  }
}