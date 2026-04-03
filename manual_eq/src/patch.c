#include "device.h"

#include <libse.h>
#include <sync.h>

#include <book/DB3350/MusicApplication_Book.h>
#include <types/IMMETypes.h>
#include <types/MusicServer_types.h>

#include "dll.h"
#include "eq.h"
#include "gui.h"
#include "patch.h"

THUMB16
NEWCODE void *malloc(int size)
{
	return memalloc(-1, size, 1, 5, EQ_MEM, NULL);
}

THUMB16
NEWCODE void mfree(void *mem)
{
	if (mem)
		memfree(NULL, mem, EQ_MEM, NULL);
}

THUMB16
NEWCODE void Save_EqualiserData(BOOL is_manual, int boost_level, int b1, int b2, int b3, int b4, int b5)
{
	int file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_WRONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
	if (file >= 0)
	{
		EQ_SETTINGS *FileData = (EQ_SETTINGS *)malloc(sizeof(EQ_SETTINGS));
		FileData->manual = is_manual;
		FileData->boost_level = boost_level;
		FileData->bar1_level = b1;
		FileData->bar2_level = b2;
		FileData->bar3_level = b3;
		FileData->bar4_level = b4;
		FileData->bar5_level = b5;
		fwrite(file, FileData, sizeof(EQ_SETTINGS));
		fclose(file);
		mfree(FileData);
	}
}

THUMB16
NEWCODE void Get_EqualizerData(BOOL *is_manual, int *boost_level, int *bar1, int *bar2, int *bar3, int *bar4, int *bar5)
{
	int file = _fopen(CONFIG_PATH, CONFIG_NAME, FSX_O_RDONLY, FSX_S_IREAD | FSX_S_IWRITE, NULL);
	if (file >= 0)
	{
		EQ_SETTINGS *FileData = (EQ_SETTINGS *)malloc(sizeof(EQ_SETTINGS));
		memset(FileData, 0, sizeof(EQ_SETTINGS));
		fread(file, FileData, sizeof(EQ_SETTINGS));
		*is_manual = FileData->manual;
		*boost_level = FileData->boost_level;
		*bar1 = FileData->bar1_level;
		*bar2 = FileData->bar2_level;
		*bar3 = FileData->bar3_level;
		*bar4 = FileData->bar4_level;
		*bar5 = FileData->bar5_level;
		fclose(file);
		mfree(FileData);
	}
}

THUMB16
NEWCODE void SetEqualizerState()
{
	BOOL is_manual;
	int boost_level, b1, b2, b3, b4, b5;
	Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);
	Save_EqualiserData(FALSE, boost_level, b1, b2, b3, b4, b5);
}

THUMB16
NEWCODE BOOL GetEqualizerState()
{
	BOOL is_manual;
	int boost_level, b1, b2, b3, b4, b5;
	Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);
	return is_manual;
}

THUMB16
NEWCODE void SetManualEQ(MusicApplication_Book *MusicBook)
{
	BOOL is_manual;
	int boost_level, b1, b2, b3, b4, b5;
	Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);

	Set_EqualizerGain(MusicBook, TMMEEqBand_63, (b1 - Bar_Netral) * (boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_250, (b2 - Bar_Netral) * (boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_1000, (b3 - Bar_Netral) * (boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_4000, (b4 - Bar_Netral) * (boost_level + 2));
	Set_EqualizerGain(MusicBook, TMMEEqBand_16000, (b5 - Bar_Netral) * (boost_level + 2));
}

THUMB16
NEWCODE void Clearbass_SelectAction(BOOK *book, GUI *gui)
{
	MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

	int boost_level, b1, b2, b3, b4, b5;
	GUIObject_Clearbass_GetBarLevel(MusicBook->Gui_submenu, &boost_level, &b1, &b2, &b3, &b4, &b5);
	Save_EqualiserData(TRUE, boost_level, b1, b2, b3, b4, b5);

	FREE_GUI(MusicBook->Gui_submenu);
}

THUMB16
NEWCODE void Clearbass_PrevAction(BOOK *book, GUI *gui)
{
	MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;

	if (GetEqualizerState())
	{
		SetManualEQ(MusicBook);
	}
	else //reactivate eq preset
	{
		Set_EqualizerGain(MusicBook, TMMEEqBand_63, MusicBook->EqBand_63);
		Set_EqualizerGain(MusicBook, TMMEEqBand_250, MusicBook->EqBand_250);
		Set_EqualizerGain(MusicBook, TMMEEqBand_1000, MusicBook->EqBand_1000);
		Set_EqualizerGain(MusicBook, TMMEEqBand_4000, MusicBook->EqBand_4000);
		Set_EqualizerGain(MusicBook, TMMEEqBand_16000, MusicBook->EqBand_16000);
	}

	FREE_GUI(MusicBook->Gui_submenu);
}

THUMB16
NEWCODE int pg_MusicApplication_ManualEQ__EnterEvent(void *data, BOOK *book)
{
	MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
	FREE_GUI(MusicBook->Gui_submenu);

	BOOL is_manual;
	int boost_level, b1, b2, b3, b4, b5;
	Get_EqualizerData(&is_manual, &boost_level, &b1, &b2, &b3, &b4, &b5);

	if (MusicBook->Gui_submenu = Create_ClearbassGUI(&MusicBook->book))
	{
		GUIObject_Clearbass_SetBarLevel(MusicBook->Gui_submenu, boost_level, b1, b2, b3, b4, b5);
		GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_SELECT1, Clearbass_SelectAction);
		GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_BACK, Clearbass_PrevAction);
		GUIObject_SoftKeys_SetAction(MusicBook->Gui_submenu, ACTION_LONG_BACK, MusicApplication_CancelAction);
		GUIObject_Show(MusicBook->Gui_submenu);
	}
	return 1;
}

THUMB16
NEWCODE void Enter_ManualEqualizer(BOOK *book, GUI *gui)
{
	MusicApplication_Book *MusicBook = (MusicApplication_Book *)book;
	MusicBook->Callpage = TRUE;

	BookObj_CallPage(&MusicBook->book, &page_MusicApplication_ManualEQ);
}

THUMB16
NEWCODE void create_new_softkeys(GUI *Gui_submenu)
{
	GUIObject_SoftKeys_SetItemAsSubItem(Gui_submenu, ACTION_MP_SETTINGS, ACTION_MP_MANUALEQ);
	GUIObject_SoftKeys_SetAction(Gui_submenu, ACTION_MP_MANUALEQ, Enter_ManualEqualizer);
	GUIObject_SoftKeys_SetText(Gui_submenu, ACTION_MP_MANUALEQ, STR(SOFTKEY_TEXT));
}
