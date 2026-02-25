#pragma once

#define HAS_EXTERNAL

#define DEFAULT_FLASH_PATH (wchar_t *)0x11C41524
#define INT_FLASH_PATH L"/usb/picture/flash"
#define EXT_FLASH_PATH L"/card/picture/flash"

#define MAINMENU_TXT 0xDDD
#define SUBMENU_TXT 0x22DA
#define PREVIEW_SK_TXT 0xB48
#define EMPTY_LIST_TXT 0x1B18

#define ITEM_SYS_TXT 0x326
#define ITEM_INT_TXT 0x32D
#define ITEM_EXT_TXT 0x329

#define ITEM_SYS_ICN 0xF3CB
#define ITEM_INT_ICN 0xF844
#define ITEM_EXT_ICN 0xF845
#define DB_FLASH_ICN 0xEA51

#define ACTION_BACK 0xFC0
#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10

#define RETURN_TO_STANDBY_EVENT 0x840

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x11927744 | 1)
#define ADDR_wstrcmpi (0x10E025E4 | 1)
#define ADDR_wstrlen (0x10E01180 | 1)
#define ADDR_FileCopy (0x109F673C | 1)
#define ADDR_FileDelete (0x109F6434 | 1)
#define ADDR_mkdir (0x109F2DBC | 1)
#define ADDR_w_fstat (0x11331024 | 1)
#define ADDR_w_diropen (0x4BB00354)
#define ADDR_w_chdir (0x4BB003AC)
#define ADDR_w_dirread (0x11AE39C4 | 1)
#define ADDR_w_dirclose (0x4BB0038C)
#define ADDR_List_DestroyElements (0x11B56FA4 | 1)
#define ADDR_List_Destroy (0x11B56CB8 | 1)
#define ADDR_List_Create (0x11B56C90 | 1)
#define ADDR_List_Get (0x11B56EB0 | 1)
#define ADDR_List_InsertLast (0x11B56E0C | 1)
#define ADDR_List_GetCount (0x11B56E84 | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_CreateBook (0x10E89BAC | 1)
#define ADDR_FindBook (0x10E87DE4 | 1)
#define ADDR_BookObj_ReturnPage (0x10E89A74 | 1)
#define ADDR_BookObj_CallPage (0x10E899F0 | 1)
#define ADDR_BookObj_GotoPage (0x10E898BC | 1)
#define ADDR_BookObj_SetFocus (0x10E89E5C | 1)
#define ADDR_FreeBook (0x10E8A22C | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x108AE74C | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x108AE7C4 | 1)
#define ADDR_GUIObject_SetTitleType (0x10A6FF0C | 1)
#define ADDR_GUIObject_SetTitleText (0x10A6FF28 | 1)
#define ADDR_GUIObject_Show (0x10A6FD14 | 1)
#define ADDR_GUIObject_Destroy (0x10A6FB20 | 1)
#define ADDR_CreateListMenu (0x11B105D0 | 1)
#define ADDR_ListMenu_SetItemCount (0x11B107E4 | 1)
#define ADDR_ListMenu_SetItemStyle 0x11B10820 | 1
#define ADDR_ListMenu_SetCursorToItem (0x11B107BC | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x11B10920 | 1)
#define ADDR_ListMenu_SetOnMessage (0x11B108F4 | 1)
#define ADDR_ListMenu_SetItemTextScroll (0x11B10EC4 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x11B107D0 | 1)
#define ADDR_ListMenu_SetNoItemText (0x11B10974 | 1)
#define ADDR_GUIonMessage_GetBook (0x11B11374 | 1)
#define ADDR_GUIonMessage_GetMsg (0x11B1136C | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x11B11390 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x11B1139C | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x11B113DC | 1)
#define ADDR_FSX_IsFileExists (0x1188A9F4 | 1)
#define ADDR_getFileExtention (0x109F8EB0 | 1)
#define ADDR_MainMenu_SetFromUserTheme (0x10E769CC | 1)
#define ADDR_Set_SWF_AsFlashMenu (0x10DC9F40 | 1)
#define ADDR_MessageBox (0x11AE853C | 1)
#define ADDR_GetURIScheme (0x10EA8798 | 1)
#define ADDR_CreateURI (0x10EA8C34 | 1)
#define ADDR_FreeURI (0x10EA8D88 | 1)
#define ADDR_Browser_OpenURI (0x1081CF44 | 1)
#define ADDR_wstrncpy (0x10E011DC | 1)