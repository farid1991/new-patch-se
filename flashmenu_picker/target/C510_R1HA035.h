#pragma once

#define HAS_EXTERNAL

#define DEFAULT_FLASH_PATH (wchar_t *)0x15A1B488
#define INT_FLASH_PATH L"/usb/picture/flash"
#define EXT_FLASH_PATH L"/card/picture/flash"

#define FD_IMAGE (wchar_t *)0x15A1B708
#define SETTINGS_PATH (wchar_t *)0x15A86E38

#define MAINMENU_TXT 0x790
#define SUBMENU_TXT 0x1C5C
#define PREVIEW_SK_TXT 0x8FD
#define EMPTY_LIST_TXT 0x612

#define ITEM_SYS_TXT 0x1863
#define ITEM_INT_TXT 0x2D0
#define ITEM_EXT_TXT 0x2CF

#define ITEM_SYS_ICN 0x24D
#define ITEM_INT_ICN 0x657
#define ITEM_EXT_ICN 0x64A

#define DB_FLASH_ICN 0x184

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

#define ADDR_memalloc (0x4BA32698)
#define ADDR_memfree (0x4BA326C0)
#define ADDR_memset (0x14B31C80)
#define ADDR_getFileExtention (0x144D94F8 | 1)
#define ADDR_CreateBook (0x142866FC | 1)
#define ADDR_BookObj_GotoPage (0x14481B20 | 1)
#define ADDR_BookObj_ReturnPage (0x14212A58 | 1)
#define ADDR_FreeBook (0x141293FC | 1)
#define ADDR_FindBook (0x140CC010 | 1)
#define ADDR_BookObj_SetFocus (0x144CB1A0 | 1)
#define ADDR_GUIObject_SetTitleText (0x1443F740 | 1)
#define ADDR_GUIObject_Show (0x144CB9BC | 1)
#define ADDR_ListMenu_SetCursorToItem (0x14417A80 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x142C5BB4 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x1438A538 | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x144CC8B4 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x142800F8 | 1)
#define ADDR_ListMenu_SetItemStyle (0x140B9BF0 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1417BACC | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x141C50C8 | 1)
#define ADDR_wstrncpy (0x143EEBF8 | 1)
#define ADDR_wstrlen (0x14178EC8 | 1)
#define ADDR_TextID_Create (0x141818E4 | 1)
#define ADDR_List_Create (0x1430E0E0 | 1)
#define ADDR_List_Destroy (0x1430E244 | 1)
#define ADDR_ListMenu_SetOnMessage (0x14302734 | 1)
#define ADDR_List_Get (0x140CC3EC | 1)
#define ADDR_List_InsertLast (0x1417A03C | 1)
#define ADDR_CreateListMenu (0x14285AF8 | 1)
#define ADDR_ListMenu_SetItemCount (0x14280610 | 1)
#define ADDR_GUIObject_Destroy (0x144CBD98 | 1)
#define ADDR_FileDelete (0x14176C04 | 1)
#define ADDR_MessageBox (0x1585B1CC | 1)
#define ADDR_ListMenu_SetNoItemText (0x1419F41C | 1)
#define ADDR_mkdir (0x141C9C20 | 1)
#define ADDR_List_DestroyElements (0x140EF194 | 1)
#define ADDR_wstrcmpi (0x14179B14 | 1)
#define ADDR_BookObj_CallPage (0x1402068C | 1)
#define ADDR_w_chdir (0x104F943C | 1)
#define ADDR_w_fstat (0x100A6EA0 | 1)
#define ADDR_FileCopy (0x141FA7F0 | 1)
#define ADDR_w_diropen (0x140F1B08 | 1)
#define ADDR_w_dirread (0x142E855C | 1)
#define ADDR_w_dirclose (0x104F84D4 | 1)
#define ADDR_Browser_OpenURI (0x1405C658 | 1)
#define ADDR_GetURIScheme (0x143C31FC | 1)
#define ADDR_CreateURI (0x143C2BA4 | 1)
#define ADDR_GUIonMessage_GetMsg (0x142C5CA4 | 1)
#define ADDR_GUIonMessage_GetBook (0x142C5E94 | 1)
#define ADDR_ListMenu_SetItemTextScroll (0x1442FA78 | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x14417B18 | 1)
#define ADDR_FSX_IsFileExists (0x14411678 | 1)
#define ADDR_ThemeImage_Apply (0x14074BA4 | 1)
#define ADDR_MainMenu_SetFromUserTheme (0x142A92AC | 1)
#define ADDR_FreeURI (0x140D5948 | 1)
#define ADDR_List_GetCount (0x140CC074 | 1)