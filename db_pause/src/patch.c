#include "device.h"

#include <libse.h>
#include <classes/IMMEPlayer.h>

THUMB16
NEWCODE void db_action_pause(BOOK *book, GUI *gui)
{
	SUB_EXECUTE *sub_execute = BrowserItem_Get_SUB_EXECUTE(book);
	TMMEState state;

	IMMEPlayer *pIMMEPlayer = (IMMEPlayer *)sub_execute->pIMMEPlayer;

	IMME_GetState(pIMMEPlayer, &state);

	if (state == TMMEState_Playing)
	{
		IMME_Pause(pIMMEPlayer);

		GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, TRUE);
		GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, FALSE);
	}
	else
	{
		IMME_Play(pIMMEPlayer, 0, FALSE);

		GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PLAY, FALSE);
		GUIObject_SoftKeys_SetVisible(sub_execute->gui, ACTION_PAUSE, TRUE);
	}
}
