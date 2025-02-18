#pragma once

#define ITEM1_TEXT 0x152F
#define ITEM2_TEXT 0xF26
#define ITEM3_TEXT 0xB91

#define ADDR_GUIObject_Show (0x14181520 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1456E038 | 1)
#define ADDR_snwprintf (0x145D8D40 | 1)
#define ADDR_TextID_Create (0x145CC790 | 1)

#define ADDR_Create_KnobOption (0x14BF817C | 1)
#define ADDR_KnobOption_SetTitleText (0x14EA07FC | 1)
#define ADDR_KnobOption_SetItemCount (0x14771804 | 1)
#define ADDR_KnobOption_SetCursor (0x14EA0844 | 1)
#define ADDR_KnobOption_SetItems (0x14BF815C | 1)
#define ADDR_KnobOption_GetSelectedItem (0x14B4B9D8 | 1)

#define ADDR_REQUEST_SYSTEM_SHUTDOWN (0x1052A9E0 | 1)
#define ADDR_REQUEST_SYSTEM_RESTART (0x1052AA00 | 1)
#define ADDR_GetFreeBytesOnHeap (0x4BC00500)
#define ADDR_FreeBook (0x141800D8 | 1)
#define ADDR_FlightMode_GetState (0x14097088 | 1)
#define ADDR_FlightMode_SetState (0x14B25640 | 1)

#define ADDR_DynamicMenu_CreateSetBook (0x14B10600 | 1)