#pragma once

#define ADDR_BookObj_GotoPage (0x1457B000 | 1)

#define ADDR_memalloc (0x4BC00394)
#define ADDR_memfree (0x4BC003BC)
#define ADDR_memset (0x147ECE78)

#define ADDR_get_envp (0x10297144 | 1)
#define ADDR_set_envp (0x10297158 | 1)

#define ADDR_CreateYesNoQuestion (0x140DF6EC | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x145CD45C | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x14488D48 | 1)

#define ADDR_GUIObject_Show (0x1469C1AC | 1)
#define ADDR_GUIObject_Destroy (0x1457BDE8 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x14391FA8 | 1)

#define ADDR_FILEITEM_GetFname (0x146A1684 | 1)
#define ADDR_FILEITEM_GetPath (0x146A12F4 | 1)
#define ADDR_FileDelete (0x1462FF80 | 1)
#define ADDR_FSX_IsFileExists (0x147002C0 | 1)
#define ADDR_DATABROWSER_CHECKFILE (0x147002FC | 1)

#define ADDR_DataDownloadBook_onClose (0x157143F8 | 1)

#define DataDownload_Main_Page (PAGE_DESC *)0x15AA228C

#define DescriptionText 0x918
#define QuestionText 0x919

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
