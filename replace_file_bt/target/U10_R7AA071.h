#pragma once

#define ADDR_BookObj_GotoPage (0x1459A190 | 1)

#define ADDR_memalloc (0x4FC00394)
#define ADDR_memfree (0x4FC003BC)
#define ADDR_memset (0x140E2D1C)

#define ADDR_get_envp (0x1029A4E4 | 1)
#define ADDR_set_envp (0x1029A4F8 | 1)

#define ADDR_CreateYesNoQuestion (0x140E2BCC | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x145ED8A4 | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x144A23F8 | 1)

#define ADDR_GUIObject_Show (0x146C5748 | 1)
#define ADDR_GUIObject_Destroy (0x1459AF78 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x143A8288 | 1)

#define ADDR_FILEITEM_GetFname (0x146CAC1C | 1)
#define ADDR_FILEITEM_GetPath (0x146CA88C | 1)
#define ADDR_FileDelete (0x146566B8 | 1)
#define ADDR_FSX_IsFileExists (0x14729F3C | 1)
#define ADDR_DATABROWSER_CHECKFILE (0x14729F78 | 1)

#define ADDR_DataDownloadBook_onClose (0x15952394 | 1)

#define DataDownload_Main_Page (PAGE_DESC *)0x15CFCD10

#define DescriptionText 0x918
#define QuestionText 0x919

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
