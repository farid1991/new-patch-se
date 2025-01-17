#include <libse.h>

#if defined(C510_R1HA035)
    #include "C510_R1HA035.h"
#elif defined(U10_R7AA071)
    #include "U10_R7AA071.h"
#elif defined(U10_R7BA084)
    #include "U10_R7BA084.h"
#elif defined(W810_R4EA031)
    #include "W810_R4EA031.h"
#elif defined(W995_R1HA035)
    #include "W995_R1HA035.h"
#endif

typedef struct
{
    uint8_t field_0;
    uint8_t padding[3];
    uint32_t field_4;
} SIMApplication;

#define NEWCODE __attribute__((section(".text.patch_section")))

#define ISimApplication ((int (*)(uint32_t *, uint8_t *))ADDR_ISIMAPPLICATION)
#define InitBook_Started__AcceptEvent ((int (*)(void *, BOOK *))ADDR_INITBOOK_ACCEPTEVENT)
#define InitBook_Started__EnterEvent ((int (*)(void *, BOOK *))ADDR_INITBOOK_ENTEREVENT)

THUMB16 NEWCODE int PATCH_InitBook_Started_EnterEvent(void *r0, BOOK *book)
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
