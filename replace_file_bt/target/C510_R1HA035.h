#pragma once

#define ADDR_BookObj_GotoPage (0x14481B20 | 1)

#define ADDR_memalloc (0x4BA32698)
#define ADDR_memfree (0x4BA326C0)
#define ADDR_memset (0x14B31C80)

#define ADDR_get_envp (0x101D68A8 | 1)
#define ADDR_set_envp (0x101D68BC | 1)

#define ADDR_CreateYesNoQuestion (0x142CD924 | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x14337434 | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x14337444 | 1)

#define ADDR_GUIObject_Show (0x144CB9BC | 1)
#define ADDR_GUIObject_Destroy (0x144CBD98 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1417BACC | 1)

#define ADDR_FILEITEM_GetFname (0x142C7D74 | 1)
#define ADDR_FILEITEM_GetPath (0x142C7CA0 | 1)
#define ADDR_FileDelete (0x14176C04 | 1)
#define ADDR_FSX_IsFileExists (0x14411678 | 1)
#define ADDR_DATABROWSER_CHECKFILE (0x14DDA4CC | 1)

#define ADDR_DataDownloadBook_onClose (0x14EF13A8 | 1)

#define DataDownload_Main_Page (PAGE_DESC *)0x15B6AD68

#define DescriptionText 0x73E
#define QuestionText 0x73F

#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define NIL_EVENT 0