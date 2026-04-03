#include "device.h"

#include <libse.h>

#include <book/DB3350/MusicApplication_Book.h>
#include <classes/DB3350/IMusicServerManager.h>
#include <types/IMMETypes.h>
#include <types/MusicServer_types.h>

extern "C" THUMB16
NEWCODE void Set_EqualizerGain(MusicApplication_Book *MusicBook, TMusicServer_EqBand band, int level)
{
	IMusicServer *pIMusicServer = (IMusicServer *)MusicBook->pIMusicServer;

	pIMusicServer->SetEqualizerGain(band, level);
}
