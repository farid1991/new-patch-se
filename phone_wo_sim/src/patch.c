#include "device.h"

#include <libse.h>

typedef struct
{
	uint8_t field_0;
	uint8_t padding[3];
	uint32_t field_4;
} SIMApplication;

#define ISimApplication ((int (*)(uint32_t *, uint8_t *))ADDR_ISIMAPPLICATION)
#define InitBook_Started__AcceptEvent ((int (*)(void *, BOOK *))ADDR_INITBOOK_ACCEPTEVENT)
#define InitBook_Started__EnterEvent ((int (*)(void *, BOOK *))ADDR_INITBOOK_ENTEREVENT)

THUMB16
NEWCODE int PATCH_InitBook_Started_EnterEvent(void *r0, BOOK *book)
{
	SIMApplication sm;
	sm.field_0 = 0;
	sm.field_4 = 0;
	ISimApplication(&sm.field_4, &sm.field_0);

	if (sm.field_4 != 0)
	{
		InitBook_Started__EnterEvent(r0, book);
	}
	else
	{
		InitBook_Started__AcceptEvent(r0, book);
	}

	return 1;
}
