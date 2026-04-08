#pragma once

#define TEXTID_LOCKED 0x7F6 // Locked

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define DB_UPDATE_EVENT 0x189C

#define KBD_SHORT_PRESS 0x0
#define KEY_STAR 0x22
#define KEY_DIEZ 0x23

#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define ADDR_memalloc (0x4BC00394)
#define ADDR_memfree (0x4BC003BC)
#define ADDR_memset (0x145C5AE8)
#define ADDR_get_envp (0x101A1C18 | 1)
#define ADDR_set_envp (0x101A1C2C | 1)
#define ADDR_get_bid (0x101A1508)
#define ADDR_current_process (0x101A14D0)

#define ADDR_BookObj_GetBookID (0x14460074 | 1)
#define ADDR_BookObj_ReturnPage (0x1422D034 | 1)
#define ADDR_BookObj_GotoPage (0x1404FF00 | 1)
#define ADDR_UI_Event_toBookID (0x1417ABE0 | 1)
#define ADDR_MainDisplay_GetTopBook (0x14050E58 | 1)

#define ADDR_TextID_Create (0x145B8610 | 1)
#define ADDR_MessageBox_NoImage (0x148C315C | 1)

#define ADDR_GUIObject_Show (0x1417A694 | 1)
#define ADDR_GUIObject_Destroy (0x14554DF4 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x14559DC4 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1455ADF0 | 1)
#define ADDR_GUIObject_SoftKeys_SetItemOnKey (0x144E01BC | 1)

#define ADDR_DataBrowserDesc_Create (0x14C55EB4 | 1)
#define ADDR_DataBrowserDesc_SetHeaderText (0x14C55C1C | 1)
#define ADDR_DataBrowserDesc_SetBookID (0x14C55E24 | 1)
#define ADDR_DataBrowserDesc_SetFolders (0x14C55E2C | 1)
#define ADDR_DataBrowserDesc_SetFoldersNumber (0x14C55E1C | 1)
#define ADDR_DataBrowserDesc_Menu_AddFSFunctions (0x14819774 | 1)
#define ADDR_DataBrowserDesc_Menu_AddNewFolder (0x14C56348 | 1)
#define ADDR_DataBrowserDesc_Menu_AddMarkFiles (0x14C55F6C | 1)
#define ADDR_DataBrowserDesc_SetViewModeAndSortOrder (0x14C55F64 | 1)
#define ADDR_DataBrowserDesc_SetOpenEmptyFolder (0x14B9E714 | 1)
#define ADDR_DataBrowserDesc_SetActions (0x14C560EC | 1)
#define ADDR_DataBrowser_Create (0x14C55150 | 1)
#define ADDR_DataBrowserDesc_Destroy (0x14C55DC8 | 1)
#define ADDR_DataBrowser_ItemDesc_CheckFileToCopyMove (0x14975D0C | 1)

#define ADDR_FILEITEM_GetFname (0x140214AC | 1)
#define ADDR_FILEITEM_GetPath (0x140213B0 | 1)
#define ADDR_FILEITEM_SetPath (0x1402120C | 1)
#define ADDR_FILEITEM_SetFnameAndContentType (0x1402118C | 1)

#define ADDR_CreateYesNoQuestion (0x1495DA80 | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x1495D904 | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x1495DA60 | 1)

#define ADDR_FileDelete (0x140DC6C4 | 1)
#define ADDR_FileMove (0x140DCC78 | 1)
#define ADDR_mkdir (0x14470494 | 1)

#define ADDR_CreatePasswordInputWindow (0x147DDC6C | 1)
#define ADDR_GetMemoryStickStatus (0x1492CA4C | 1)
