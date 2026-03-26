#include "device.h"

#include <libse.h>
#include <book/FmRadio_Book.h>
#include <soundrecorder.h>
#include <sync.h>

#define FNAME_SIZE 256
const wchar_t output_dir[] = L"/card/music/FM";
const wchar_t output_fmt[] = L"fm-%ls-%d-%02d_%02d_%d-%02d:%02d.amr";

THUMB16
NEWCODE void FMRadio_Record(BOOK *book, GUI *gui)
{
	FmRadio_Book *fm_book = (FmRadio_Book *)book;
	SOUND_RECORDER_DESC *desc = (SOUND_RECORDER_DESC *)SoundRecorderDesc_Create();
	if (desc)
	{
		SoundRecorderDesc_SetBookID(desc, NO_BOOK_ID);
		SoundRecorderDesc_SetType(desc, TrackID_Recorder);
		SoundRecorderDesc_SetTitle(desc, RECORDING_TEXTID);
		SoundRecorderDesc_SetRadioVal(desc, fm_book->RadioVal);

		mkdir(output_dir);
		SoundRecorderDesc_SetFolder(desc, output_dir);

		DATETIME dt;
		REQUEST_DATEANDTIME_GET(&SYNC, &dt);

		wchar_t filename[FNAME_SIZE];
		snwprintf(filename,
		          MAXELEMS(filename),
		          output_fmt,
		          fm_book->Channel[fm_book->CurrentChannel - 1].Name,
		          fm_book->CurrentFrequency,
		          dt.date.day,
		          dt.date.mon,
		          dt.date.year,
		          dt.time.hour,
		          dt.time.min);
		SoundRecorderDesc_SetFname(desc, filename);

		SoundRecorderDesc_SetStyle(desc, PopupNoFrame);
		SoundRecorder_Create(desc);
		SoundRecorderDesc_Destroy(desc);
	}
}