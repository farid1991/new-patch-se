#pragma once

#define DescriptionText 0x83F // File already exists
#define QuestionText 0x840    // Replace?

#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define NIL_EVENT 0

#define DataDownload_Main_Page (PAGE_DESC *)0x11EE2CEC

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x4BB01144)
#define ADDR_get_envp (0x10005C38 | 1)
#define ADDR_set_envp (0x10005C4C | 1)
#define ADDR_CreateYesNoQuestion (0x118106B8 | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x11810A20 | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x11810A10 | 1)
#define ADDR_YesNoQuestion_SetIcon (0x11810A40 | 1)
#define ADDR_GUIObject_Destroy (0x10A6FB20 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x108AE74C | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x108AE7C4 | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x108AE848 | 1)
#define ADDR_GUIObject_Show (0x10A6FD14 | 1)
#define ADDR_FILEITEM_GetFname (0x1188FBBC | 1)
#define ADDR_FILEITEM_GetPath (0x1188FC50 | 1)
#define ADDR_FileDelete (0x109F6434 | 1)
#define ADDR_FSX_IsFileExists (0x1188A9F4 | 1)
#define ADDR_BookObj_GotoPage (0x10E898BC | 1)
#define ADDR_DataBrowser_ItemDesc_CheckFileToCopyMove (0x11870184 | 1)
#define ADDR_DataDownloadBook_onClose (0x1188D088 | 1)
