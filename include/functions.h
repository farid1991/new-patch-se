#ifndef functions_h
#define functions_h

// memory allocators
#if defined(DB2020)
#define memalloc ((void *(*)(int, int, int, int, const char *, int))ADDR_memalloc)
#define memfree ((void (*)(int, void *, const char *, int))ADDR_memfree)
#elif defined(A2)
#define memalloc ((void *(*)(int, int, int, int, const char *, int))ADDR_memalloc)
#define memfree ((void (*)(int, void *, const char *, int))ADDR_memfree)
#else
#define memalloc ((void *(*)(int, int, int, const char *, int))ADDR_memalloc)
#define memfree ((void (*)(void *, const char *, int))ADDR_memfree)
#endif

#define memset ((void *(*)(void *, int, int))ADDR_memset)

#define memcpy ((int (*)(void *, const void *, int))ADDR_memcpy)

#define memcmp ((int (*)(const void *, const void *, int))ADDR_memcmp)

// OSE functioms
#define GetCurrentPID ((PROCESS (*)(void))ADDR_GetCurrentPID)

#define alloc ((union SIGNAL * (*)(OSBUFSIZE, SIGSELECT)) ADDR_alloc)

#define receive ((union SIGNAL * (*)(const SIGSELECT *)) ADDR_receive)

#define send ((void (*)(union SIGNAL **, PROCESS))ADDR_send)

#define sender ((PROCESS (*)(union SIGNAL **))ADDR_sender)

#define free_buf ((void (*)(union SIGNAL **))ADDR_free_buf)

#define create_process \
	((PROCESS (*)(PROCESS_TYPE, \
	              char *, \
	              OSENTRYPOINT *, \
	              OSADDRESS, \
	              OSPRIORITY, \
	              OSTIME, \
	              PROCESS, \
	              void *, \
	              OSVECTOR, \
	              OSUSER))ADDR_create_process)

#define start ((void (*)(PROCESS))ADDR_start)

#define get_ptype ((int (*)(PROCESS))ADDR_get_ptype)

#define current_process ((PROCESS (*)(void))ADDR_current_process)

#define delay ((void (*)(OSTIME))ADDR_delay)

#define hunt ((OSBOOLEAN (*)(const char *, OSUSER, PROCESS *, union SIGNAL **))ADDR_hunt)

#define kill_proc ((void (*)(PROCESS))ADDR_kill_proc)

#define receive_w_tmo ((union SIGNAL * (*)(OSTIME, SIGSELECT *)) ADDR_receive_w_tmo)

#define stop ((void (*)(PROCESS))ADDR_stop)

#define get_bid ((PROCESS (*)(PROCESS))ADDR_get_bid)

#define GetCurrentPID ((PROCESS (*)(void))ADDR_GetCurrentPID)

#define get_envp ((OSADDRESS (*)(PROCESS, const char *))ADDR_get_envp)

#define set_envp ((OSBOOLEAN (*)(PROCESS, const char *, OSADDRESS))ADDR_set_envp)

#define debug_printf ((void (*)(const char *fmt, ...))ADDR_debug_printf)

// printf-style helpers --------------------------------------------------------

#define sprintf ((int (*)(char *, const char *, ...))ADDR_sprintf)

#define snprintf ((int (*)(char *, int, const char *, ...))ADDR_snprintf)

#define snwprintf ((int (*)(wchar_t *, int, const wchar_t *, ...))ADDR_snwprintf)

#define sscanf ((int (*)(const char *, const char *, ...))ADDR_sscanf)

#define swscanf ((int (*)(const wchar_t *, const wchar_t *, ...))ADDR_swscanf)

#define strftime ((int (*)(int, int, int, int, void *, int))ADDR_strftime)

// MessageBox ---------------------------------------------------------------

#define MessageBox ((int (*)(TEXTID, TEXTID, IMAGEID, int, int, BOOK *))ADDR_MessageBox)

#define MessageBox_NoImage ((void (*)(TEXTID, TEXTID, int, int, BOOK *))ADDR_MessageBox_NoImage)

// file I/O --------------------------------------------------------------------

#define _fopen ((int (*)(const wchar_t *, const wchar_t *, unsigned int, unsigned int, FILELISTITEM *))ADDR__fopen)

#define fclose ((int (*)(int))ADDR_fclose)

#define fread ((int (*)(int, void *, int))ADDR_fread)

#define fwrite ((int (*)(int, const void *, int))ADDR_fwrite)

#define fstat ((int (*)(const wchar_t *, const wchar_t *, FSTAT *))ADDR_fstat)

#define fflush ((int (*)(int))ADDR_fflush)

#define lseek ((int (*)(int file, int offset, int mode))ADDR_lseek)

#define FSX_IsFileExists ((BOOL (*)(const wchar_t *, const wchar_t *))ADDR_FSX_IsFileExists)

#define FSX_MakeFullPath ((wchar_t * (*)(const wchar_t *, const wchar_t *)) ADDR_FSX_MakeFullPath)

#define FSX_FreeFullPath ((void (*)(const wchar_t *))ADDR_FSX_FreeFullPath)

// file operations -------------------------------------------------------------

#define FileDelete ((void (*)(const wchar_t *, const wchar_t *, int *))ADDR_FileDelete)

#define FileCopy ((int (*)(const wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *, int))ADDR_FileCopy)

#define FileMove ((int (*)(const wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *, int))ADDR_FileMove)

// filesystem ---------------------------------------------------------------

#define mkdir ((int (*)(const wchar_t *))ADDR_mkdir)

#define rmdir ((int (*)(const wchar_t *, int))ADDR_rmdir)

#define chmod ((int (*)(const wchar_t *, const wchar_t *, int))ADDR_chmod)

#define rename ((int (*)(const wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *, int))ADDR_rename)

#define getFileExtension ((wchar_t * (*)(const wchar_t *)) ADDR_getFileExtension)

// wide filesystem (w_*) -------------------------------------------------------

#define w_chdir ((int (*)(const wchar_t *))ADDR_w_chdir)

#define w_fopen ((int (*)(const wchar_t *, int, int, int))ADDR_w_fopen)

#define w_fstat ((int (*)(const wchar_t *, W_FSTAT *))ADDR_w_fstat)

#define w_fwrite ((int (*)(int, void *, int))ADDR_w_fwrite)

#define w_fread ((int (*)(int, void *, int))ADDR_w_fread)

#define w_lseek ((int (*)(int, int, int))ADDR_w_lseek)

#define w_fclose ((int (*)(int))ADDR_w_fclose)

#define w_mkdir ((int (*)(const wchar_t *, int))ADDR_w_mkdir)

#define w_diropen ((void *(*)(const wchar_t *))ADDR_w_diropen)

#define w_dirread ((wchar_t * (*)(void *)) ADDR_w_dirread)

#define w_dirclose ((int (*)(void *))ADDR_w_dirclose)

#define w_rename ((int (*)(const wchar_t *, const wchar_t *))ADDR_w_rename)

#define w_remove ((int (*)(const wchar_t *))ADDR_w_remove)

// Linked list
#define List_Create ((LIST * (*)(void)) ADDR_List_Create)

#define List_Destroy ((void (*)(LIST * lst)) ADDR_List_Destroy)

#define List_InsertFirst ((int (*)(LIST * lst, void *item)) ADDR_List_InsertFirst)

#define List_RemoveAt ((void *(*)(LIST * lst, int index)) ADDR_List_RemoveAt)

#define List_IndexOf ((int (*)(LIST * lst, void *item)) ADDR_List_IndexOf)

#define List_Find ((int (*)(LIST * lst, void *itemtofind, LISTFINDCALLBACK cmp_proc)) ADDR_List_Find)

#define List_Get ((void *(*)(LIST * lst, int index)) ADDR_List_Get)

#define List_InsertLast ((int (*)(LIST * lst, void *item)) ADDR_List_InsertLast)

#define List_DestroyElements \
	((void (*)(LIST * lst, int (*cmp_proc)(void *item), void (*free_proc)(void *item))) ADDR_List_DestroyElements)

#define List_Insert ((int (*)(LIST * lst, int i, void *item)) ADDR_List_Insert)

#define List_InsertSorted ((int (*)(LIST * list, void *item, int (*cmp_proc)(void *, void *))) ADDR_List_InsertSorted)

#define List_Init ((void (*)(LIST * list)) ADDR_List_Init)

#define List_Erase ((void (*)(LIST * list)) ADDR_List_Erase)

#define List_InsertBefore ((int (*)(LIST * list, void *pElem, int itemno)) ADDR_List_InsertBefore)

#define List_InsertAfter ((int (*)(LIST * list, void *pElem, int itemno)) ADDR_List_InsertAfter)

#define List_RemoveFirst ((void *(*)(LIST * lst)) ADDR_List_RemoveFirst)

#define List_RemoveLast ((void *(*)(LIST * lst)) ADDR_List_RemoveLast)

#define List_GetCount ((int (*)(LIST *))ADDR_List_GetCount)

#define List_GetFirst ((void *(*)(LIST * list)) ADDR_List_GetFirst)

#define List_GetLast ((void *(*)(LIST * list)) ADDR_List_GetLast)

#define List_FindNext ((void *(*)(LIST * list, void *pElem)) ADDR_List_FindNext)

#define List_FindPrev ((void *(*)(LIST * list, void *pElem)) ADDR_List_FindPrev)

#define List_Last ((int (*)(LIST * list)) ADDR_List_Last)

#define List_Next ((int (*)(LIST * list, int itemno)) ADDR_List_Next)

// Book --------------------------------------------------------------------

#define CreateBook \
	((int (*)(BOOK *, void (*)(BOOK *), const PAGE_DESC *, const char *, int, const APP_DESC *))ADDR_CreateBook)

#define BookObj_KillBook ((void (*)(BOOK *))ADDR_BookObj_KillBook)

#define BookObj_GotoPage ((void (*)(BOOK *, const PAGE_DESC *))ADDR_BookObj_GotoPage)

#define BookObj_ReturnPage ((void (*)(BOOK *, int))ADDR_BookObj_ReturnPage)

#define BookObj_CallPage ((void (*)(BOOK *, const PAGE_DESC *))ADDR_BookObj_CallPage)

#define FreeBook ((void (*)(BOOK *))ADDR_FreeBook)

#define FindBook ((BOOK * (*)(IS_NEEDED_BOOK)) ADDR_FindBook)

#define FindBookByID ((BOOK * (*)(int)) ADDR_FindBookByID)

#define FindBookEx ((BOOK * (*)(int (*)(BOOK *, int *), int *)) ADDR_FindBookEx)

#define Find_StandbyBook ((BOOK * (*)(void)) ADDR_Find_StandbyBook)

#define BookObj_SetFocus ((void (*)(BOOK *, int))ADDR_BookObj_SetFocus)

#define BookObj_Hide ((void (*)(BOOK *, int))ADDR_BookObj_Hide)

#define BookObj_Show ((void (*)(BOOK *, int))ADDR_BookObj_Show)

#define BookObj_GetSession ((UI_APP_SESSION * (*)(BOOK *)) ADDR_BookObj_GetSession)

#define BookObj_GetSessionID ((int (*)(BOOK *))ADDR_BookObj_GetSessionID)

#define BookObj_GetBookID ((int (*)(BOOK *))ADDR_BookObj_GetBookID)

#define BookObj_WindowSetWantsFocus ((void (*)(BOOK *, int, BOOL))ADDR_BookObj_WindowSetWantsFocus)

#define BookObj_StayOnTop ((void (*)(BOOK *, int))ADDR_BookObj_StayOnTop)

#define root_list_get_session_count ((int (*)(void))ADDR_root_list_get_session_count)

#define root_list_get_session ((UI_APP_SESSION * (*)(int)) ADDR_root_list_get_session)

#define IsRightNowBook ((int (*)(BOOK *))ADDR_IsRightNowBook)

#define IsVolumeControllerBook ((int (*)(BOOK *))ADDR_IsVolumeControllerBook)

#define IsScreenSaverBook ((int (*)(BOOK *))ADDR_IsScreenSaverBook)

#define IsFmRadioBook ((int (*)(BOOK *))ADDR_IsFmRadioBook)

#define IsAudioPlayerBook ((int (*)(BOOK *))ADDR_IsAudioPlayerBook)

#define IsDataBrowserBook ((int (*)(BOOK *))ADDR_IsDataBrowserBook)

#define IsCameraBook ((int (*)(BOOK *))ADDR_IsCameraBook)

#define IsSoundRecorderBook ((int (*)(BOOK *))ADDR_IsSoundRecorderBook)

#define UIEventName ((char *(*)(int))ADDR_UIEventName)

#define UI_Event ((void (*)(int))ADDR_UI_Event)

#define UI_Event_wData ((void (*)(int, void *, void (*)(void *)))ADDR_UI_Event_wData)

#define UI_Event_toBookID ((void (*)(int, int))ADDR_UI_Event_toBookID)

#define UI_Event_toBookIDwData ((void (*)(int, int, void *, void (*)(void *)))ADDR_UI_Event_toBookIDwData)

#define Session_SetFocus ((void *(*)(UI_APP_SESSION *, int))ADDR_Session_SetFocus)

// DISP / GC / GUI -------------------------------------------------------------

#define get_DisplayGC ((GC * (*)(void)) ADDR_get_DisplayGC)

#define DisplayGC_AddRef ((void (*)(GC *, void *))ADDR_DisplayGC_AddRef)

#define DispObject_GetRect ((void (*)(DISP_OBJ *, RECT *))ADDR_DispObject_GetRect)

#define GC_GetRect ((void (*)(GC *, RECT *))ADDR_GC_GetRect)

#define GC_GetXX ((int (*)(GC *))ADDR_GC_GetXX)

#define GC_SetXX ((void (*)(GC *, int))ADDR_GC_SetXX)

#define GC_GetPenColor ((int (*)(GC *))ADDR_GC_GetPenColor)

#define GC_SetPenColor ((void (*)(GC *, int))ADDR_GC_SetPenColor)

#define GC_SetPixel ((void (*)(GC *, int, int, int))ADDR_GC_SetPixel)

#define GC_DrawLine ((void (*)(GC *, int, int, int, int))ADDR_GC_DrawLine)

#define GC_DrawFRect ((void (*)(GC *, int, int, int, int, int))ADDR_GC_DrawFRect)

#define GC_WritePixels ((int (*)(GC *, int, int, int, int, int *))ADDR_GC_WritePixels)

#define GC_ValidateRect ((void (*)(GC *, RECT *))ADDR_GC_ValidateRect)

#define BookObj_AddGUIObject ((void (*)(BOOK *, GUI *))ADDR_BookObj_AddGUIObject)

#define DrawRect ((void (*)(int, int, int, int, int, int))ADDR_DrawRect)

#define XGUIList_AddGUIObject ((void (*)(XGUILIST *, GUI *))ADDR_XGUIList_AddGUIObject)

#define DispObject_InvalidateRect ((void (*)(DISP_OBJ *, RECT *))ADDR_DispObject_InvalidateRect)

#define DispObject_SetLayerColor ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetLayerColor)

#define DispObject_SetScrollbarMode ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetScrollbarMode)

#define DispObject_SetRefreshTimer ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetRefreshTimer)

#define DispObject_KillRefreshTimer ((void (*)(DISP_OBJ *))ADDR_DispObject_KillRefreshTimer)

#define DispObject_SetAnimation ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetAnimation)

#define DispObject_SetBacklightMode ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetBacklightMode)

#define DispObject_SetThemeImage ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetThemeImage)

#define DispObject_WindowSetPosition ((void (*)(DISP_OBJ *, int, int))ADDR_DispObject_WindowSetPosition)

#define DispObject_WindowSetSize ((void (*)(DISP_OBJ *, int, int))ADDR_DispObject_WindowSetSize)

#define DispObject_SetStyle ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetStyle)

#define DispObject_GetStyle ((int (*)(DISP_OBJ *))ADDR_DispObject_GetStyle)

#define DispObject_GetGUI ((GUI * (*)(DISP_OBJ *)) ADDR_DispObject_GetGUI)

#define DispObject_SetTitleText ((void (*)(DISP_OBJ *, TEXTID))ADDR_DispObject_SetTitleText)

#define DispObject_SetTitleType ((void (*)(DISP_OBJ *, int))ADDR_DispObject_SetTitleType)

#define DispObject_GetTitleType ((int (*)(DISP_OBJ *))ADDR_DispObject_GetTitleType)

#define DispObject_SetTitleAlignment ((void (*)(DISP_OBJ *, char))ADDR_DispObject_SetTitleAlignment)

#define DispObject_GetTitleAlignment ((int (*)(DISP_OBJ *))ADDR_DispObject_GetTitleAlignment)

#define DispObject_SetSecondRowTitleText ((void (*)(DISP_OBJ *, TEXTID))ADDR_DispObject_SetSecondRowTitleText)

// --- Text / Image drawing --------------------------------------------------

#define SetFont ((int (*)(int))ADDR_SetFont)

#define DrawString ((void (*)(TEXTID, int, int, int, int, int, int, int, int, int))ADDR_DrawString)

#define GC_PutChar ((void (*)(GC *, int, int, int, int, IMAGEID))ADDR_GC_PutChar)

#define GetImageHeight ((int (*)(IMAGEID))ADDR_GetImageHeight)

#define GetImageWidth ((int (*)(IMAGEID))ADDR_GetImageWidth)

#define GetThemeColor ((int (*)(int, int))ADDR_GetThemeColor)

#define ImageID_Get ((int (*)(const wchar_t *, const wchar_t *, IMAGEID *))ADDR_ImageID_Get)

#define ImageID_Free ((void (*)(IMAGEID))ADDR_ImageID_Free)

#define ImageID_Copy ((IMAGEID (*)(IMAGEID))ADDR_ImageID_Copy)

#define ImageID_GetIndirect ((int (*)(void *, int, int, const wchar_t *, IMAGEID *))ADDR_ImageID_GetIndirect)

#define iconidname2id ((int (*)(const wchar_t *, int, int *))ADDR_iconidname2id)

#define textidname2id ((int (*)(const wchar_t *, int, TEXTID *))ADDR_textidname2id)

// GUI object creation / lifecycle --------------------------------------------

#define GUIObject_Create \
	((int (*)( \
	        GUI *, void (*)(GUI *), void (*)(DISP_DESC *), BOOK *, void (*)(DISP_OBJ *, void *, GUI *), int, int)) \
	         ADDR_GUIObject_Create)

#define GUIObject_SetTitleType ((void (*)(GUI *, int))ADDR_GUIObject_SetTitleType)

#define GUIObject_SetTitleText ((void (*)(GUI *, TEXTID))ADDR_GUIObject_SetTitleText)

#define GUIObject_SetTitleIcon ((void (*)(GUI *, IMAGEID))ADDR_GUIObject_SetTitleIcon)

#define GUIObject_SetSecondRowTitleText ((void (*)(GUI *, TEXTID))ADDR_GUIObject_SetSecondRowTitleText)

#define GUIObject_SetStyle ((void (*)(GUI *, int))ADDR_GUIObject_SetStyle)

#define GUIObject_GetStyle ((int (*)(GUI *))ADDR_GUIObject_GetStyle)

#define GUIObject_SetTitleTextAlign ((void (*)(GUI *, char))ADDR_GUIObject_SetTitleTextAlign)

#define GUIObject_GetTitleTextAlign ((int (*)(GUI *))ADDR_GUIObject_GetTitleTextAlign)

#define GUIObject_Show ((void (*)(GUI *))ADDR_GUIObject_Show)

#define GUIObject_Destroy ((GUI * (*)(GUI *)) ADDR_GUIObject_Destroy)

#define GUIObject_GetDispObject ((DISP_OBJ * (*)(GUI *)) ADDR_GUIObject_GetDispObject)

#define GUIObject_GetBook ((BOOK * (*)(GUI *)) ADDR_GUIObject_GetBook)

#define GUIObject_TabTitleRemove ((void (*)(GUI *, int))ADDR_GUIObject_TabTitleRemove)

#define GUIObject_SetTitleBackgroundImage ((void (*)(GUI *, IMAGEID))ADDR_GUIObject_SetTitleBackgroundImage)

#define GUIObject_SetCursorImage ((void (*)(GUI *, IMAGEID))ADDR_GUIObject_SetCursorImage)

#define GUIObject_SetBackgroundImage ((void (*)(GUI *, IMAGEID))ADDR_GUIObject_SetBackgroundImage)

#define GUIObject_SetTitleTextColor ((void (*)(GUI *, int))ADDR_GUIObject_SetTitleTextColor)

// Softkey handling ------------------------------------------------------------

#define GUIObject_SoftKeys_SetAction ((void (*)(GUI *, uint16_t, SKACTIONPROC proc))ADDR_GUIObject_SoftKeys_SetAction)

#define GUIObject_SoftKeys_SetText ((void (*)(GUI *, uint16_t, TEXTID))ADDR_GUIObject_SoftKeys_SetText)

#define GUIObject_SoftKeys_SetActionAndText \
	((void (*)(GUI *, uint16_t, SKACTIONPROC proc, TEXTID))ADDR_GUIObject_SoftKeys_SetActionAndText)

#define GUIObject_SoftKeys_SetInfoText ((void (*)(GUI *, uint16_t, TEXTID))ADDR_GUIObject_SoftKeys_SetInfoText)

#define GUIObject_SoftKeys_Hide ((void (*)(GUI *))ADDR_GUIObject_SoftKeys_Hide)

#define GUIObject_SoftKeys_Show ((void (*)(GUI *))ADDR_GUIObject_SoftKeys_Show)

#define GUIObject_SoftKeys_RemoveBackground ((void (*)(GUI *))ADDR_GUIObject_SoftKeys_RemoveBackground)

#define GUIObject_SoftKeys_RestoreBackground ((void (*)(GUI *))ADDR_GUIObject_SoftKeys_RestoreBackground)

#define GUIObject_SoftKeys_SetEnable ((void (*)(GUI *, uint16_t, BOOL))ADDR_GUIObject_SoftKeys_SetEnable)

#define GUIObject_SoftKeys_AddErrorStr ((void (*)(GUI *, uint16_t, TEXTID))ADDR_GUIObject_SoftKeys_AddErrorStr)

#define GUIObject_SoftKeys_RemoveItem ((void (*)(GUI *, uint16_t))ADDR_GUIObject_SoftKeys_RemoveItem)

#define GUIObject_SoftKeys_SetVisible ((void (*)(GUI *, uint16_t, BOOL))ADDR_GUIObject_SoftKeys_SetVisible)

#define GUIObject_SoftKeys_SetItemAsSubItem ((void (*)(GUI *, int, int))ADDR_GUIObject_SoftKeys_SetItemAsSubItem)

#define GUIObject_SoftKeys_SuppressDefaultAction \
	((void (*)(GUI *, uint16_t))ADDR_GUIObject_SoftKeys_SuppressDefaultAction)

#define MediaPlayer_SoftKeys_Validate ((int (*)(GUI *))ADDR_MediaPlayer_SoftKeys_Validate)

#define MediaPlayer_SoftKeys_SetText ((void (*)(GUI *, int, TEXTID))ADDR_MediaPlayer_SoftKeys_SetText)

#define MediaPlayer_SoftKeys_SetAction ((void (*)(GUI *, int, SKACTIONPROC proc))ADDR_MediaPlayer_SoftKeys_SetAction)

#define MediaPlayer_SoftKeys_SetItemAsSubItem ((void (*)(GUI *, int, int))ADDR_MediaPlayer_SoftKeys_SetItemAsSubItem)

#define MediaPlayer_SoftKeys_AddHelpStr ((void (*)(GUI *, int, TEXTID))ADDR_MediaPlayer_SoftKeys_AddHelpStr)

// DISP descriptor / object API -----------------------------------------------

#define DISP_DESC_SetName ((void (*)(DISP_DESC *, const char *))ADDR_DISP_DESC_SetName)

#define DISP_DESC_SetSize ((void (*)(DISP_DESC *, uint16_t))ADDR_DISP_DESC_SetSize)

#define DISP_DESC_SetOnCreate ((void (*)(DISP_DESC *, DISP_OBJ_ONCREATE_METHOD))ADDR_DISP_DESC_SetOnCreate)

#define DISP_DESC_SetOnClose ((void (*)(DISP_DESC *, DISP_OBJ_ONCLOSE_METHOD))ADDR_DISP_DESC_SetOnClose)

#define DISP_DESC_SetOnRedraw ((void (*)(DISP_DESC *, DISP_OBJ_ONREDRAW_METHOD))ADDR_DISP_DESC_SetOnRedraw)

#define DISP_DESC_SetOnKey ((void (*)(DISP_DESC *, DISP_OBJ_ONKEY_METHOD))ADDR_DISP_DESC_SetOnKey)

#define DISP_DESC_SetOnRefresh ((void (*)(DISP_DESC *, DISP_OBJ_METHOD))ADDR_DISP_DESC_SetOnRefresh)

#define DISP_DESC_SetMethod06 ((void (*)(DISP_DESC *, DISP_OBJ_METHOD))ADDR_DISP_DESC_SetMethod06)

#define DISP_DESC_SetOnLayout ((void (*)(DISP_DESC *, DISP_OBJ_ONLAYOUT_METHOD))ADDR_DISP_DESC_SetOnLayout)

#define DISP_DESC_SetOnConfig ((void (*)(DISP_DESC *, DISP_OBJ_ONCONFIG_METHOD))ADDR_DISP_DESC_SetOnConfig)

#define DispObject_GetDESC ((DISP_DESC * (*)(DISP_OBJ *)) ADDR_DispObject_GetDESC)

#define DispObject_GetName ((char *(*)(DISP_OBJ *))ADDR_DispObject_GetName)

#define DispObject_GetOnCreate ((DISP_OBJ_ONCREATE_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetOnCreate)

#define DispObject_GetOnClose ((DISP_OBJ_ONCLOSE_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetOnClose)

#define DispObject_GetOnRedraw ((DISP_OBJ_ONREDRAW_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetOnRedraw)

#define DispObject_GetOnKey ((DISP_OBJ_ONKEY_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetOnKey)

#define DispObject_GetonRefresh ((DISP_OBJ_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetonRefresh)

#define DispObject_GetMethod06 ((DISP_OBJ_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetMethod06)

#define DispObject_GetOnLayout ((DISP_OBJ_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetOnLayout)

#define DispObject_GetOnConfig ((DISP_OBJ_METHOD (*)(DISP_OBJ *))ADDR_DispObject_GetOnConfig)

// wchar / string helpers ------------------------------------------------------

#define wstrcpy ((wchar_t * (*)(wchar_t *, const wchar_t *)) ADDR_wstrcpy)

#define wstrncpy ((wchar_t * (*)(wchar_t *, const wchar_t *, int)) ADDR_wstrncpy)

#define wstrcat ((wchar_t * (*)(wchar_t *, const wchar_t *)) ADDR_wstrcat)

#define wstrncat ((wchar_t * (*)(wchar_t *, const wchar_t *, int)) ADDR_wstrncat)

#define wstrcmp ((int (*)(const wchar_t *, const wchar_t *))ADDR_wstrcmp)

#define wstrlen ((int (*)(const wchar_t *))ADDR_wstrlen)

#define wstrcmpni ((int (*)(const wchar_t *, const wchar_t *, int))ADDR_wstrcmpni)

#define wtoi ((int (*)(const wchar_t *, int, int *))ADDR_wtoi)

#define wstrwstr ((wchar_t * (*)(const wchar_t *, const wchar_t *)) ADDR_wstrwstr)

#define wstrncmp ((int (*)(const wchar_t *, const wchar_t *, int))ADDR_wstrncmp)

#define wstrcmpi ((int (*)(const wchar_t *, const wchar_t *))ADDR_wstrcmpi)

#define wstrchr ((wchar_t * (*)(const wchar_t *, wchar_t)) ADDR_wstrchr)

#define wstrrchr ((wchar_t * (*)(const wchar_t *, wchar_t)) ADDR_wstrrchr)

#define wstrnupr ((void (*)(wchar_t *, int))ADDR_wstrnupr)

#define wstrnlwr ((void (*)(wchar_t *, int))ADDR_wstrnlwr)

#define strcpy ((char *(*)(char *, const char *))ADDR_strcpy)

#define strncpy ((char *(*)(char *, const char *, int))ADDR_strncpy)

#define str2wstr ((wchar_t * (*)(wchar_t *, const char *)) ADDR_str2wstr)

#define strcmp ((int (*)(const char *, const char *))ADDR_strcmp)

#define strncmp ((int (*)(const char *, const char *, int))ADDR_strncmp)

#define strlen ((int (*)(const char *))ADDR_strlen)

#define strcat ((char *(*)(char *, const char *))ADDR_strcat)

#define strncat ((char *(*)(char *, const char *, int))ADDR_strncat)

#define str2wstrn ((wchar_t * (*)(wchar_t *, const char *, int)) ADDR_str2wstrn)

#define wstr2strn ((char *(*)(char *, const wchar_t *, int))ADDR_wstr2strn)

#define strstr ((char *(*)(const char *, const char *))ADDR_strstr)

#define count_digit ((int (*)(int))ADDR_count_digit)

#define itow ((int (*)(int, wchar_t *, int))ADDR_itow)

// TextID API ------------------------------------------------------------------

#define TextID_CreateIntegerID ((TEXTID (*)(int))ADDR_TextID_CreateIntegerID)

#define TextID_Create ((TEXTID (*)(const void *, TEXT_ENCODING, int))ADDR_TextID_Create)

#define TextID_GetString ((void (*)(TEXTID, char *, int))ADDR_TextID_GetString)

#define TextID_GetWString ((int (*)(TEXTID, wchar_t *, int))ADDR_TextID_GetWString)

#define TextID_GetLength ((int (*)(TEXTID))ADDR_TextID_GetLength)

#define TextID_Destroy ((void (*)(TEXTID))ADDR_TextID_Destroy)

#define TextID_Copy ((TEXTID (*)(TEXTID))ADDR_TextID_Copy)

#define TextID_CreateFromTextIterator ((TEXTID (*)(void *, TEXT_ENCODING, int))ADDR_TextID_CreateFromTextIterator)

// Timer -----------------------------------------------------------------------

#define Timer_ReSet ((void (*)(uint16_t *timer, int time, TIMERPROC onTimer, LPARAM lparam))ADDR_Timer_ReSet)

#define Timer_Set ((uint16_t (*)(int time, TIMERPROC onTimer, LPARAM lparam))ADDR_Timer_Set)

#define Timer_Kill ((void (*)(uint16_t *timerID))ADDR_Timer_Kill)

// OSE / UI / COM-style interfaces ---------------------------------------------

#define CoCreateInstance ((int (*)(UUID *, UUID *, void **))ADDR_CoCreateInstance)

#define OSE_GetShell ((void (*)(void **))ADDR_OSE_GetShell)

#define TextObject_SetText ((void (*)(void *, TEXTID))ADDR_TextObject_SetText)

#define TextObject_SetFont ((void (*)(void *, void *, const int, const int))ADDR_TextObject_SetFont)

#define RichTextLayout_GetTextWidth ((int (*)(TEXTID, void *, void *))ADDR_RichTextLayout_GetTextWidth)

// DynamicMenu function --------------------------------------------------------

#define DynamicMenu_GetElementMsg ((int (*)(DYNAMIC_MENU_ELEMENT *))ADDR_DynamicMenu_GetElementMsg)

#define DynamicMenu_GetElementId ((wchar_t * (*)(DYNAMIC_MENU_ELEMENT *)) ADDR_DynamicMenu_GetElementId)

#define DynamicMenu_SetElement_FirstLineText \
	((void (*)(DYNAMIC_MENU_ELEMENT *, TEXTID))ADDR_DynamicMenu_SetElement_FirstLineText)

#define DynamicMenu_SetElement_HelpText ((void (*)(DYNAMIC_MENU_ELEMENT *, TEXTID))ADDR_DynamicMenu_SetElement_HelpText)

#define DynamicMenu_SetElement_Icon ((void (*)(DYNAMIC_MENU_ELEMENT *, int, IMAGEID))ADDR_DynamicMenu_SetElement_Icon)

#define DynamicMenu_SetElement_UnavailableState \
	((void (*)(DYNAMIC_MENU_ELEMENT *, BOOL))ADDR_DynamicMenu_SetElement_UnavailableState)

#define DynamicMenu_SetElement_UnavailableText \
	((void (*)(DYNAMIC_MENU_ELEMENT *, TEXTID))ADDR_DynamicMenu_SetElement_UnavailableText)

#define DynamicMenu_SetElement_SecondLineText \
	((void (*)(DYNAMIC_MENU_ELEMENT *, TEXTID))ADDR_DynamicMenu_SetElement_SecondLineText)

#define DynamicMenu_SetElement_TitleText \
	((void (*)(DYNAMIC_MENU_ELEMENT *, TEXTID))ADDR_DynamicMenu_SetElement_TitleText)

#define DynamicMenu_CreateSetBook ((BOOK * (*)(void)) ADDR_DynamicMenu_CreateSetBook)

// volume control --------------------------------------------------------------

#define Volume_Set ((void (*)(int, char))ADDR_Volume_Set)

#define Volume_Get ((int (*)(int, char *))ADDR_Volume_Get)

// REQUEST / settings / system -------------------------------------------------

#define REQUEST_DATEANDTIME_GET ((void (*)(const int *, DATETIME *))ADDR_REQUEST_DATEANDTIME_GET)

#define REQUEST_DATEFORMAT_GET ((int (*)(const int *, char *))ADDR_REQUEST_DATEFORMAT_GET)

#define REQUEST_TIMEFORMAT_GET ((int (*)(const int *, char *))ADDR_REQUEST_TIMEFORMAT_GET)

#define REQUEST_SETTING_ALLOWEDCALLERS_GET ((void (*)(const int *, int, char *))ADDR_REQUEST_SETTING_ALLOWEDCALLERS_GET)

#define REQUEST_SETTING_RINGVOLUME_SET ((int (*)(const int *, int, int, int))ADDR_REQUEST_SETTING_RINGVOLUME_SET)

#define REQUEST_SETTING_VIBRATOR_SET ((int (*)(const int *, int, int))ADDR_REQUEST_SETTING_VIBRATOR_SET)

#define REQUEST_SETTING_RINGTYPESOUNDFILE_SET \
	((int (*)(const int *, int, wchar_t *, wchar_t *))ADDR_REQUEST_SETTING_RINGTYPESOUNDFILE_SET)

#define REQUEST_SETTING_ANSWERINGMODE_SET ((int (*)(const int *, int, int))ADDR_REQUEST_SETTING_ANSWERINGMODE_SET)

#define REQUEST_SETTING_INCREASINGRING_SET \
	((int (*)(const int *, int, int, int))ADDR_REQUEST_SETTING_INCREASINGRING_SET)

#define REQUEST_SETTING_ALLOWEDCALLERS_SET ((int (*)(const int *, int, int))ADDR_REQUEST_SETTING_ALLOWEDCALLERS_SET)

#define REQUEST_SETTING_SILENCE_SET ((int (*)(const int *, uint16_t, uint16_t))ADDR_REQUEST_SETTING_SILENCE_SET)

#define REQUEST_SETTING_SILENCE_GET ((int (*)(const int *, uint16_t, char *))ADDR_REQUEST_SETTING_SILENCE_GET)

#define REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE \
	((int (*)(const int *, uint16_t *, char *))ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE)

#define REQUEST_IMAGEHANDLER_INTERNAL_REGISTER \
	((int (*)(const int *, uint16_t, const wchar_t *, const wchar_t *, int, IMAGEID *, char *)) \
	         ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER)

#define REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER \
	((int (*)(const int *, uint16_t, uint16_t *, uint16_t *, IMAGEID, int, char *)) \
	         ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER)

#define REQUEST_SYSTEM_SHUTDOWN ((void (*)(void))ADDR_REQUEST_SYSTEM_SHUTDOWN)

#define REQUEST_SYSTEM_RESTART ((void (*)(void))ADDR_REQUEST_SYSTEM_RESTART)

#define Request_ICA_ShutdownAllConnections ((int (*)(const int *))ADDR_Request_ICA_ShutdownAllConnections)

#define REQUEST_UI_OAF_START_APPLICATION ((void (*)(const int *, int, char *))ADDR_REQUEST_UI_OAF_START_APPLICATION)

// List Menu GUI ------------------------------------------------------------

#define CreateListMenu ((GUI_LIST * (*)(BOOK *, int display)) ADDR_CreateListMenu)

#define ListMenu_SetItemCount ((void (*)(GUI_LIST *, int))ADDR_ListMenu_SetItemCount)

#define ListMenu_GetItemCount ((int (*)(GUI_LIST *))ADDR_ListMenu_GetItemCount)

#define ListMenu_GetSelectedItem ((int (*)(GUI_LIST *))ADDR_ListMenu_GetSelectedItem)

#define ListMenu_SetItemStyle ((void (*)(GUI_LIST *, int))ADDR_ListMenu_SetItemStyle)

#define ListMenu_SetCursorToItem ((void (*)(GUI_LIST *, int))ADDR_ListMenu_SetCursorToItem)

#define ListMenu_SetOnMessage ((void (*)(GUI_LIST *, int (*)(GUI_MESSAGE *)))ADDR_ListMenu_SetOnMessage)

#define ListMenu_SetNoItemText ((void (*)(GUI_LIST *, TEXTID))ADDR_ListMenu_SetNoItemText)

#define ListMenu_SetItemSecondLineText ((void (*)(GUI_LIST *, uint16_t, TEXTID))ADDR_ListMenu_SetItemSecondLineText)

#define ListMenu_SetItemIcon ((int (*)(GUI_LIST *, uint16_t, uint16_t, int, IMAGEID))ADDR_ListMenu_SetItemIcon)

#define ListMenu_SetItemTextScroll ((int (*)(GUI_LIST *, int))ADDR_ListMenu_SetItemTextScroll)

#define ListMenu_DestroyItems ((void (*)(GUI_LIST *))ADDR_ListMenu_DestroyItems)

#define ListMenu_SetHotkeyMode ((void (*)(GUI_LIST *, LISTMENU_HOTKEY_MODE))ADDR_ListMenu_SetHotkeyMode)

#define ListMenu_SetSearchLanguageMode ((void (*)(GUI_LIST *, int))ADDR_ListMenu_SetSearchLanguageMode)

#define ListMenu_EnableSearchHeader ((void (*)(GUI_LIST *, BOOL))ADDR_ListMenu_EnableSearchHeader)

#define ListMenu_SetTexts ((void (*)(GUI_LIST *, TEXTID *, int))ADDR_ListMenu_SetTexts)

// --- OneOfMany ------------------------------------------------------------

#define CreateOneOfMany ((GUI_ONEOFMANY * (*)(BOOK *)) ADDR_CreateOneOfMany)

#define OneOfMany_SetItemCount ((void (*)(GUI_ONEOFMANY *, int))ADDR_OneOfMany_SetItemCount)

#define OneOfMany_SetChecked ((void (*)(GUI_ONEOFMANY *, int))ADDR_OneOfMany_SetChecked)

#define OneOfMany_SetTexts ((void (*)(GUI_ONEOFMANY *, TEXTID *, int))ADDR_OneOfMany_SetTexts)

#define OneOfMany_GetSelected ((int (*)(GUI_ONEOFMANY *))ADDR_OneOfMany_GetSelected)

#define OneOfMany_SetFocused ((void (*)(GUI_ONEOFMANY *, int))ADDR_OneOfMany_SetFocused)

#define OneOfMany_SetOnMessage ((void (*)(GUI_ONEOFMANY *, int (*)(GUI_MESSAGE *)))ADDR_OneOfMany_SetOnMessage)

#define OneOfMany_SetInfoText ((void (*)(GUI_ONEOFMANY *, uint16_t, uint16_t, TEXTID))ADDR_OneOfMany_SetInfoText)

// --- NOfMany --------------------------------------------------------------

#define CreateNOfMany ((GUI_NOFMANY * (*)(BOOK *)) ADDR_CreateNOfMany)

#define NOfMany_SetTexts ((void (*)(GUI_NOFMANY *, TEXTID *, int))ADDR_NOfMany_SetTexts)

#define NOfMany_SetChecked ((void (*)(GUI_NOFMANY *, uint16_t *, int))ADDR_NOfMany_SetChecked)

#define NOfMany_SetCursor ((void (*)(GUI_NOFMANY *, int))ADDR_NOfMany_SetCursor)

#define NOfMany_GetCheckedCount ((int (*)(GUI_NOFMANY *))ADDR_NOfMany_GetCheckedCount)

#define NOfMany_GetChecked ((int (*)(GUI_NOFMANY *, uint16_t *))ADDR_NOfMany_GetChecked)

#define NOfMany_SetOnMessage ((void (*)(GUI_NOFMANY *, int (*)(GUI_MESSAGE *)))ADDR_NOfMany_SetOnMessage)

#define NOfMany_GetItemCount ((int (*)(GUI_NOFMANY *))ADDR_NOfMany_GetItemCount)

#define NOfMany_SetItemCount ((void (*)(GUI_NOFMANY *, int))ADDR_NOfMany_SetItemCount)

#define NOfMany_ItemGetChecked ((void (*)(GUI_NOFMANY *, int))ADDR_NOfMany_ItemGetChecked)

// --- GUIonMessage helpers -------------------------------------------------

#define GUIonMessage_GetCreatedItemIndex ((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_GetCreatedItemIndex)

#define GUIonMessage_SetMenuItemText ((char (*)(GUI_MESSAGE *, TEXTID))ADDR_GUIonMessage_SetMenuItemText)

#define GUIonMessage_SetMenuItemSecondLineText \
	((char (*)(GUI_MESSAGE *, TEXTID))ADDR_GUIonMessage_SetMenuItemSecondLineText)

#define GUIonMessage_SetMenuItemInfoText ((char (*)(GUI_MESSAGE *, TEXTID))ADDR_GUIonMessage_SetMenuItemInfoText)

#define GUIonMessage_SetMenuItemUnavailableText \
	((char (*)(GUI_MESSAGE *, TEXTID))ADDR_GUIonMessage_SetMenuItemUnavailableText)

#define GUIonMessage_SetMenuItemIcon ((void (*)(GUI_MESSAGE *, int, IMAGEID))ADDR_GUIonMessage_SetMenuItemIcon)

#define GUIonMessage_GetMsg ((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_GetMsg)

#define GUIonMessage_SetItemDisabled ((void (*)(GUI_MESSAGE *, BOOL))ADDR_GUIonMessage_SetItemDisabled)

#define GUIonMessage_GetBook ((BOOK * (*)(GUI_MESSAGE *)) ADDR_GUIonMessage_GetBook)

#define GUIonMessage_GetGui ((GUI * (*)(GUI_MESSAGE *)) ADDR_GUIonMessage_GetGui)

#define GUIonMessage_GetSelectedItem ((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_GetSelectedItem)

#define GUIonMessage_GetPrevSelectedItem ((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_GetPrevSelectedItem)

#define GUIonMessage_SetLineSeparator ((void (*)(GUI_MESSAGE *, int))ADDR_GUIonMessage_SetLineSeparator)

#define GUIonMessage_GetSearchString ((wchar_t * (*)(GUI_MESSAGE *)) ADDR_GUIonMessage_GetSearchString)

#define GUIonMessage_GetSearchStringLength ((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_GetSearchStringLength)

#define GUIonMessage_SetNumberOfSubItems ((void (*)(GUI_MESSAGE *, int, int))ADDR_GUIonMessage_SetNumberOfSubItems)

#define GUIonMessage_SubItem_SetText ((void (*)(GUI_MESSAGE *, TEXTID))ADDR_GUIonMessage_SubItem_SetText)

#define GUIonMessage_SubItem_GetCreatedParentIndex \
	((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_SubItem_GetCreatedParentIndex)

#define GUIonMessage_SubItem_GetSelectedIndex ((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_SubItem_GetSelectedIndex)

#define GUIonMessage_SubItem_SetDisabled ((void (*)(GUI_MESSAGE *, BOOL))ADDR_GUIonMessage_SubItem_SetDisabled)

#define GUIonMessage_SubItem_GetCreatedIndex ((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_SubItem_GetCreatedIndex)

#define GUIonMessage_SubItem_GetSelectedParentIndex \
	((int (*)(GUI_MESSAGE *))ADDR_GUIonMessage_SubItem_GetSelectedParentIndex)

// --- OnOffList ------------------------------------------------------------

#define CreateOnOffList ((GUI * (*)(BOOK *)) ADDR_CreateOnOffList)

#define OnOffList_GetSelected ((int (*)(GUI *))ADDR_OnOffList_GetSelected)

#define OnOffList_SetChecked ((void (*)(GUI *, int))ADDR_OnOffList_SetChecked)

#define OnOffList_SetFirstText ((void (*)(GUI *, TEXTID))ADDR_OnOffList_SetFirstText)

#define OnOffList_SetSecondText ((void (*)(GUI *, TEXTID))ADDR_OnOffList_SetSecondText)

// String Input GUI

#define CreateStringInput ((GUI * (*)(BOOK * book)) ADDR_CreateStringInput)

#define CreateStringInputVA ((GUI * (*)(int, ...)) ADDR_CreateStringInputVA)

#define StringInput_SetMode ((void (*)(GUI *, int mode))ADDR_StringInput_SetMode)

#define StringInput_SetActionOK \
	((void (*)(GUI * strinp, void (*proc)(BOOK *, wchar_t *, int))) ADDR_StringInput_SetActionOK)

#define StringInput_SetActionBack \
	((void (*)(GUI * strinp, void (*proc)(BOOK *, wchar_t *, int))) ADDR_StringInput_SetActionBack)

#define StringInput_SetActionCancel \
	((void (*)(GUI * strinp, void (*proc)(BOOK *, wchar_t *, int))) ADDR_StringInput_SetActionCancel)

#define StringInput_SetText ((void (*)(GUI * strinp, TEXTID)) ADDR_StringInput_SetText)

#define StringInput_SetFixedText ((void (*)(GUI * strinp, TEXTID)) ADDR_StringInput_SetFixedText)

#define StringInput_SetMinLen ((void (*)(GUI * strinp, int len)) ADDR_StringInput_SetMinLen)

#define StringInput_SetMaxLen ((void (*)(GUI * strinp, int len)) ADDR_StringInput_SetMaxLen)

#define StringInput_SetEnableEmptyText ((void (*)(GUI * strinp, BOOL state)) ADDR_StringInput_SetEnableEmptyText)

#define StringInput_GetCursorPosition ((int (*)(GUI *, uint16_t *pos, char *_zero))ADDR_StringInput_GetCursorPosition)

#define StringInput_SetCursorPosition ((void (*)(GUI *, uint16_t curs_pos, char unk))ADDR_StringInput_SetCursorPosition)

#define StringInput_GetStringAndLen ((int (*)(GUI *, wchar_t **, uint16_t *))ADDR_StringInput_GetStringAndLen)

#define StringInput_MenuItem_SetPriority \
	((void (*)(GUI * strinp, int prio, int actionID)) ADDR_StringInput_MenuItem_SetPriority)

#define StringInput_DispObject_SetLanguage \
	((int (*)(DISP_OBJ_STRING_INPUT *, int langID, int flag))ADDR_StringInput_DispObject_SetLanguage)

#define StringInput_DispObject_SetText ((void (*)(DISP_OBJ *, TEXTID))ADDR_StringInput_DispObject_SetText)

#define StringInput_DispObject_StartSelectedText ((void (*)(DISP_OBJ *))ADDR_StringInput_DispObject_StartSelectedText)

#define StringInput_DispObject_CopySelectedText ((void (*)(DISP_OBJ *))ADDR_StringInput_DispObject_CopySelectedText)

// Yes No Question GUI

#define CreateYesNoQuestion ((GUI * (*)(BOOK *, int)) ADDR_CreateYesNoQuestion)

#define CreateYesNoQuestionVA ((GUI * (*)(int, ...)) ADDR_CreateYesNoQuestionVA)

#define YesNoQuestion_SetQuestionText ((void (*)(GUI *, TEXTID))ADDR_YesNoQuestion_SetQuestionText)

#define YesNoQuestion_SetDescriptionText ((void (*)(GUI *, TEXTID))ADDR_YesNoQuestion_SetDescriptionText)

#define YesNoQuestion_SetIcon ((void (*)(GUI *, IMAGEID))ADDR_YesNoQuestion_SetIcon)

// Knob GUI DB3350 only
#ifdef DB3350
#define Create_KnobOption ((GUI * (*)(BOOK *, int)) ADDR_Create_KnobOption)

#define KnobOption_SetTitleText ((void (*)(GUI *, TEXTID))ADDR_KnobOption_SetTitleText)

#define KnobOption_SetItemCount ((void (*)(GUI *, int))ADDR_KnobOption_SetItemCount)

#define KnobOption_SetCursor ((void (*)(GUI *, int pos))ADDR_KnobOption_SetCursor)

#define KnobOption_SetItems ((void (*)(GUI *, TEXTID, int))ADDR_KnobOption_SetItems)

#define KnobOption_GetSelectedItem ((int (*)(GUI *))ADDR_KnobOption_GetSelectedItem)
#endif

// TabMenuBar GUI

#define CreateTabMenuBar ((GUI_TABMENUBAR * (*)(BOOK * book)) ADDR_CreateTabMenuBar)

#define TabMenuBar_SetTabCount ((void (*)(GUI_TABMENUBAR *, int count))ADDR_TabMenuBar_SetTabCount)

#define TabMenuBar_SetTabGui ((void (*)(GUI_TABMENUBAR *, int tab, GUI *))ADDR_TabMenuBar_SetTabGui)

#define TabMenuBar_SetTabIcon ((void (*)(GUI_TABMENUBAR *, int tab, IMAGEID, int for_state))ADDR_TabMenuBar_SetTabIcon)

#define TabMenuBar_GetFocusedTab ((int (*)(GUI_TABMENUBAR *))ADDR_TabMenuBar_GetFocusedTab)

#define TabMenuBar_SetFocusedTab ((void (*)(GUI_TABMENUBAR *, int tab_num))ADDR_TabMenuBar_SetFocusedTab)

#define TabMenuBar_SetOnTabSwitch \
	((void (*)(GUI_TABMENUBAR *, void (*proc)(BOOK *, int act_tab)))ADDR_TabMenuBar_SetOnTabSwitch)

#define TabMenuBar_SetTabTitle ((void (*)(GUI_TABMENUBAR *, int tab_num, TEXTID))ADDR_TabMenuBar_SetTabTitle)

// Date and Time

#define datetime2unixtime ((int (*)(DATETIME *))ADDR_datetime2unixtime)

#define unixtime2datetime ((void (*)(int, DATETIME *))ADDR_unixtime2datetime)

#define DATE_GetWeekDay ((void (*)(DATE *, char *))ADDR_DATE_GetWeekDay)

#define Date2ID ((TEXTID (*)(DATE *, int, int))ADDR_Date2ID)

#define Time2ID ((TEXTID (*)(TIME *, char, int))ADDR_Time2ID)

// DataBrowser / FILEITEM ------------------------------------------------------

#define DataBrowserDesc_Create ((void *(*)(void))ADDR_DataBrowserDesc_Create)

#define DataBrowserDesc_SetItemStyle ((void (*)(void *, int))ADDR_DataBrowserDesc_SetItemStyle)

#define DataBrowserDesc_SetHeaderText ((void (*)(void *, TEXTID))ADDR_DataBrowserDesc_SetHeaderText)

#define DataBrowserDesc_SetFolders ((void (*)(void *, const wchar_t **))ADDR_DataBrowserDesc_SetFolders)

#define DataBrowserDesc_SetOKSoftKeyText ((void (*)(void *, TEXTID))ADDR_DataBrowserDesc_SetOKSoftKeyText)

#define DataBrowserDesc_SetFoldersNumber ((void (*)(void *, int))ADDR_DataBrowserDesc_SetFoldersNumber)

#define DataBrowserDesc_SetActions ((void (*)(void *, char *))ADDR_DataBrowserDesc_SetActions)

#define DataBrowserDesc_SetDefaultActions ((void (*)(void *, BOOL))ADDR_DataBrowserDesc_SetDefaultActions)

#define DataBrowserDesc_SetSelectAction ((void (*)(void *, int))ADDR_DataBrowserDesc_SetSelectAction)

#define DataBrowserDesc_SetSelectActionOnFolders ((void (*)(void *, int))ADDR_DataBrowserDesc_SetSelectActionOnFolders)

#define DataBrowserDesc_SetBookID ((void (*)(void *, int))ADDR_DataBrowserDesc_SetBookID)

#define DataBrowserDesc_SetItemFilter ((void (*)(void *, DB_FILE_FILTER))ADDR_DataBrowserDesc_SetItemFilter)

#define DataBrowserDesc_SetOption ((void (*)(void *, char *))ADDR_DataBrowserDesc_SetOption)

#define DataBrowserDesc_SetOpenEmptyFolder ((void (*)(void *, int))ADDR_DataBrowserDesc_SetOpenEmptyFolder)

#define DataBrowserDesc_SetFileExtList ((void (*)(void *, const wchar_t *))ADDR_DataBrowserDesc_SetFileExtList)

#define DataBrowserDesc_Menu_AddFSFunctions ((void (*)(void *, int))ADDR_DataBrowserDesc_Menu_AddFSFunctions)

#define DataBrowserDesc_Menu_AddNewFolder ((void (*)(void *, int))ADDR_DataBrowserDesc_Menu_AddNewFolder)

#define DataBrowserDesc_Menu_AddMarkFiles ((void (*)(void *, int))ADDR_DataBrowserDesc_Menu_AddMarkFiles)

#define DataBrowserDesc_SetViewModeAndSortOrder ((void (*)(void *, int))ADDR_DataBrowserDesc_SetViewModeAndSortOrder)

#define DataBrowserDesc_SetFocusToFILEITEM ((int (*)(void *, FILEITEM *))ADDR_DataBrowserDesc_SetFocusToFILEITEM)

#define DataBrowser_Create ((void (*)(void *))ADDR_DataBrowser_Create)

#define DataBrowserDesc_Destroy ((void (*)(void *))ADDR_DataBrowserDesc_Destroy)

#define DataBrowser_CreateSubExecute ((SUB_EXECUTE * (*)(int, FILEITEM *)) ADDR_DataBrowser_CreateSubExecute)

#define DataBrowser_ExecuteSubroutine ((int (*)(SUB_EXECUTE *, int, uint16_t *))ADDR_DataBrowser_ExecuteSubroutine)

#define DataBrowser_ItemDesc_CheckFileToCopyMove ((int (*)(FILEITEM *))ADDR_DataBrowser_ItemDesc_CheckFileToCopyMove)

#define DataBrowser_isFileInListExt \
	((int (*)(const wchar_t *, const wchar_t *, const wchar_t *))ADDR_DataBrowser_isFileInListExt)

#define FILEITEM_SetFname ((int (*)(FILEITEM *, const wchar_t *))ADDR_FILEITEM_SetFname)

#define FILEITEM_SetPath ((int (*)(FILEITEM *, const wchar_t *))ADDR_FILEITEM_SetPath)

#define FILEITEM_GetFname ((wchar_t * (*)(FILEITEM *)) ADDR_FILEITEM_GetFname)

#define FILEITEM_GetPath ((wchar_t * (*)(FILEITEM *)) ADDR_FILEITEM_GetPath)

#define FILEITEM_SetFnameAndContentType ((int (*)(FILEITEM *, const wchar_t *))ADDR_FILEITEM_SetFnameAndContentType)

#define FILEITEM_SetPathAndContentType ((int (*)(FILEITEM *, const wchar_t *))ADDR_FILEITEM_SetPathAndContentType)

#define BrowserItem_Get_SUB_EXECUTE ((SUB_EXECUTE * (*)(BOOK *)) ADDR_BrowserItem_Get_SUB_EXECUTE)

// Java dialog / app descriptor ------------------------------------------------

#define JavaDialog_Open ((int (*)(int, char *, void **))ADDR_JavaDialog_Open)

#define JavaDialog_Close ((void (*)(int))ADDR_JavaDialog_Close)

#define JavaAppDesc_Get ((int (*)(int, void **))ADDR_JavaAppDesc_Get)

#define JavaAppDesc_GetFirstApp ((int (*)(void *))ADDR_JavaAppDesc_GetFirstApp)

#define JavaAppDesc_GetNextApp ((int (*)(void *))ADDR_JavaAppDesc_GetNextApp)

#define JavaAppDesc_GetJavaAppInfo ((int (*)(void *, int, wchar_t **))ADDR_JavaAppDesc_GetJavaAppInfo)

#define JavaApp_LogoImageID_Get ((int (*)(wchar_t *, IMAGEID *))ADDR_JavaApp_LogoImageID_Get)

#define manifest_GetParam ((char *(*)(const char *, const char *, int))ADDR_manifest_GetParam)

#define JavaSession_Manager ((void (*)(int))ADDR_JavaSession_Manager)

#define JavaSession_GetName ((TEXTID (*)(void))ADDR_JavaSession_GetName)

#define JavaAppDesc_GetJavaAppID ((int (*)(void *))ADDR_JavaAppDesc_GetJavaAppID)

// Sound Recorder

#define SoundRecorderDesc_Create ((void *(*)())ADDR_SoundRecorderDesc_Create)

#define SoundRecorderDesc_Destroy ((void (*)(void *desc))ADDR_SoundRecorderDesc_Destroy)

#define SoundRecorderDesc_SetBookID ((int (*)(void *desc, int BookID))ADDR_SoundRecorderDesc_SetBookID)

#define SoundRecorderDesc_SetType ((int (*)(void *desc, const int type))ADDR_SoundRecorderDesc_SetType)

#define SoundRecorderDesc_SetFolder ((int (*)(void *desc, const wchar_t *fpath))ADDR_SoundRecorderDesc_SetFolder)

#define SoundRecorderDesc_SetFname ((int (*)(void *desc, const wchar_t *fname))ADDR_SoundRecorderDesc_SetFname)

#define SoundRecorderDesc_SetRecordSize ((int (*)(void *desc, const int size))ADDR_SoundRecorderDesc_SetRecordSize)

#define SoundRecorderDesc_SetRadioVal ((int (*)(void *desc, int value))ADDR_SoundRecorderDesc_SetRadioVal)

#define SoundRecorderDesc_SetTitle ((int (*)(void *desc, TEXTID Title))ADDR_SoundRecorderDesc_SetTitle)

#define SoundRecorderDesc_SetStyle ((int (*)(void *desc, int style))ADDR_SoundRecorderDesc_SetStyle)

#define SoundRecorder_Create ((int (*)(void *desc))ADDR_SoundRecorder_Create)

// --- Browser / URI --------------------------------------------------------

#define Browser_OpenURI ((int (*)(BOOK *, char *, int))ADDR_Browser_OpenURI)

#define GetURIScheme ((char *(*)(int schemeID))ADDR_GetURIScheme)

#define CreateURI ((char *(*)(const wchar_t *, const wchar_t *, char *))ADDR_CreateURI)

#define FreeURI ((void (*)(char *))ADDR_FreeURI)

// Display -------------------------------------------------------------

#define Display_GetHeight ((int (*)(int))ADDR_Display_GetHeight)

#define Display_GetWidth ((int (*)(int))ADDR_Display_GetWidth)

#define Display_GetTopBook ((BOOK * (*)(int)) ADDR_Display_GetTopBook)

#if defined(DB2020) || defined(PNX5230) || defined(A2)
#define MainDisplay_GetTopBook ((BOOK * (*)()) ADDR_MainDisplay_GetTopBook)
#endif

#define Display_GetBrightness ((int (*)(int))ADDR_Display_GetBrightness)

#define Disp_GetTextIDWidth ((int (*)(TEXTID, int))ADDR_Disp_GetTextIDWidth)

// CANVAS / GVI GC -------------------------------------------------------------

#define CANVAS_Get_GviGC ((int (*)(PCANVAS, GVI_GC *))ADDR_CANVAS_Get_GviGC)

#define GVI_BitBlt ((void (*)(GVI_GC, int, int, int, int, GVI_GC, int, int, int, int, int, int))ADDR_GVI_BitBlt)

#define GVI_StretchBlt \
	((void (*)(GVI_GC, int, int, int, int, GVI_GC, int, int, int, int, int, int, int, int))ADDR_GVI_StretchBlt)

#define GVI_TransformBlt ((void (*)(GVI_GC, int, int, GVI_GC, int, int, int, int, int, int))ADDR_GVI_TransformBlt)

// GVI objects -----------------------------------------------------------------

#define GVI_CreatePen ((GVI_PEN (*)(char, int))ADDR_GVI_CreatePen)

#define GVI_CreateDashedPen ((GVI_PEN (*)(char, int, int, int, int))ADDR_GVI_CreateDashedPen)

#define GVI_CreateSolidBrush ((GVI_BRUSH (*)(int))ADDR_GVI_CreateSolidBrush)

#define GVI_Delete_GVI_Object ((BOOL (*)(GVI_OBJ *))ADDR_GVI_Delete_GVI_Object)

// GVI drawing (outline) -------------------------------------------------------

#define GVI_DrawEllipse ((void (*)(GVI_GC, int, int, int, int, GVI_PEN))ADDR_GVI_DrawEllipse)

#define GVI_DrawLine ((void (*)(GVI_GC, int, int, int, int, GVI_PEN))ADDR_GVI_DrawLine)

#define GVI_DrawLines ((void (*)(GVI_GC, POINT *, int, GVI_PEN))ADDR_GVI_DrawLines)

#define GVI_DrawPolyLine ((void (*)(GVI_GC, POINT *, int, GVI_PEN, int))ADDR_GVI_DrawPolyLine)

#define GVI_DrawRectangle ((void (*)(GVI_GC, int, int, int, int, GVI_PEN))ADDR_GVI_DrawRectangle)

#define GVI_DrawRoundRect ((void (*)(GVI_GC, int, int, int, int, int, int, GVI_PEN))ADDR_GVI_DrawRoundRect)

#define GVI_DrawSolidLines ((void (*)(GVI_GC, POINT *, int, int, int))ADDR_GVI_DrawSolidLines)

#define GVI_DrawSolidPolyLine ((void (*)(GVI_GC, POINT *, int, int, int, int))ADDR_GVI_DrawSolidPolyLine)

#define GVI_DrawSolidRectangle ((void (*)(GVI_GC, int, int, int, int, int, int))ADDR_GVI_DrawSolidRectangle)

// GVI filling -----------------------------------------------------------------

#define GVI_FillEllipse ((void (*)(GVI_GC, int, int, int, int, GVI_BRUSH))ADDR_GVI_FillEllipse)

#define GVI_FillPolygon ((void (*)(GVI_GC, POINT *, int, GVI_BRUSH))ADDR_GVI_FillPolygon)

#define GVI_FillRectangle ((void (*)(GVI_GC, int, int, int, int, GVI_BRUSH))ADDR_GVI_FillRectangle)

#define GVI_FillRectangles ((void (*)(GVI_GC, GVI_XYWH *, int, GVI_BRUSH))ADDR_GVI_FillRectangles)

#define GVI_FillSolidEllipse ((void (*)(GVI_GC, int, int, int, int, int))ADDR_GVI_FillSolidEllipse)

#define GVI_FillSolidRectangle ((void (*)(GVI_GC, int, int, int, int, int))ADDR_GVI_FillSolidRectangle)

#define GVI_FillSolidRoundRect ((int (*)(GVI_GC, int, int, int, int, int, int, int))ADDR_GVI_FillSolidRoundRect)

#define GVI_FillSolidTriangle ((void (*)(GVI_GC, int, int, int, int, int, int, int))ADDR_GVI_FillSolidTriangle)

// Bitmap / memory GC ----------------------------------------------------------

#define GVI_CreateBitmap ((GVI_BMP (*)(int, int, int))ADDR_GVI_CreateBitmap)

#define GVI_CreateMemoryGC ((GVI_GC (*)(GVI_BMP))ADDR_GVI_CreateMemoryGC)

#define GVI_DeleteMemoryGC ((void (*)(GVI_GC))ADDR_GVI_DeleteMemoryGC)

#define GC_CreateMemoryGC ((GC * (*)(int, int, int, int, void *, int)) ADDR_GC_CreateMemoryGC)

#define GC_FreeGC ((void (*)(GC *))ADDR_GC_FreeGC)

// Phone Book

#define AB_GETNBROFITEMS ((int (*)(int, int))ADDR_AB_GETNBROFITEMS)

// METADATA API

#define MetaData_Desc_Create ((void *(*)(wchar_t *, wchar_t *))ADDR_MetaData_Desc_Create)

#define MetaData_Desc_Destroy ((void (*)(void *))ADDR_MetaData_Desc_Destroy)

#define MetaData_Desc_HasCover ((bool (*)(void *))ADDR_MetaData_Desc_HasCover)

#define MetaData_Desc_GetCoverInfo ((int (*)(void *, char *, int *, int *))ADDR_MetaData_Desc_GetCoverInfo)

#define MetaData_Desc_GetTags ((wchar_t * (*)(void *, int)) ADDR_MetaData_Desc_GetTags)

// Misc

#define GetFreeBytesOnHeap ((int (*)(void))ADDR_GetFreeBytesOnHeap)

#define FlightMode_GetState ((int (*)(void))ADDR_FlightMode_GetState)

#define FlightMode_SetState ((void (*)(int state))ADDR_FlightMode_SetState)

#define ConnectionManager_Connection_GetState ((int (*)(void))ADDR_ConnectionManager_Connection_GetState)

#define ConnectionManager_Connection_GetState_A2 ((int (*)(char *))ADDR_ConnectionManager_Connection_GetState_A2)

#define MetaData_GetTags ((wchar_t * (*)(const wchar_t *, const wchar_t *, int)) ADDR_MetaData_GetTags)

#define NewEvents_GetCount ((int (*)(void))ADDR_NewEvents_GetCount)

#define IsMainDisplayFocused ((int (*)(void))ADDR_IsMainDisplayFocused)

// Main Menu

#define MenuBook_Desktop ((BOOK * (*)(int, int)) ADDR_MenuBook_Desktop)

#define MenuBook_Desktop_GetSelectedItemID ((wchar_t * (*)(BOOK *)) ADDR_MenuBook_Desktop_GetSelectedItemID)

#define BookObj_SoftKeys_SetAction ((void (*)(BOOK *, int, SKACTIONPROC))ADDR_BookObj_SoftKeys_SetAction)

#define BookObj_SoftKeys_SetText ((void (*)(BOOK *, int, TEXTID))ADDR_BookObj_SoftKeys_SetText)

#define Shortcut_Get_MenuItemName ((TEXTID (*)(void *))ADDR_Shortcut_Get_MenuItemName)

#define Shortcut_Get_MenuItemIconID ((IMAGEID (*)(void *))ADDR_Shortcut_Get_MenuItemIconID)

#define Shortcut_Run ((void (*)(const wchar_t *))ADDR_Shortcut_Run)

// --- Theme / Flash menu ---------------------------------------------------

#define MainMenu_SetFromUserTheme ((void (*)(int))ADDR_MainMenu_SetFromUserTheme)

#define ThemeImage_Apply \
	((void (*)(const wchar_t *, const wchar_t *, const wchar_t *, const wchar_t *, int, int))ADDR_ThemeImage_Apply)

#define Set_SWF_AsFlashMenu ((void (*)(const wchar_t *, const wchar_t *, int *))ADDR_Set_SWF_AsFlashMenu)

// -------------------------------- libpng -------------------------------------
#ifdef USE_LIBPNG
#define png_create_read_struct_2 \
	((png_structp (*)( \
	        png_const_charp, png_voidp, png_error_ptr, png_error_ptr, png_voidp, png_malloc_ptr, png_free_ptr)) \
	         ADDR_png_create_read_struct_2)

#define png_destroy_read_struct ((void (*)(png_structpp, png_infopp, png_infopp))ADDR_png_destroy_read_struct)

#define png_create_info_struct ((png_infop (*)(png_structp))ADDR_png_create_info_struct)

#define png_destroy_info_struct ((void (*)(png_structp, png_infopp))ADDR_png_destroy_info_struct)

#define png_set_progressive_read_fn \
	((void (*)( \
	        png_structp, png_voidp, png_progressive_info_ptr, png_progressive_row_ptr, png_progressive_end_ptr)) \
	         ADDR_png_set_progressive_read_fn)

#define png_process_data ((void (*)(png_structp, png_infop, png_bytep, png_size_t))ADDR_png_process_data)

#define png_read_update_info ((void (*)(png_structp, png_infop))ADDR_png_read_update_info)

#define png_get_progressive_ptr ((png_voidp (*)(png_structp))ADDR_png_get_progressive_ptr)

#define png_get_IHDR \
	((png_uint_32 (*)(png_structp, png_infop, png_uint_32 *, png_uint_32 *, int *, int *, int *, int *, int *)) \
	         ADDR_png_get_IHDR)

#define png_set_strip_16 ((void (*)(png_structp))ADDR_png_set_strip_16)

#define png_set_gray_1_2_4_to_8 ((void (*)(png_structp))ADDR_png_set_gray_1_2_4_to_8)

#define png_set_gray_to_rgb ((void (*)(png_structp))ADDR_png_set_gray_to_rgb)

#define png_get_valid ((png_uint_32 (*)(png_structp, png_infop, png_uint_32))ADDR_png_get_valid)

#define png_set_tRNS_to_alpha ((void (*)(png_structp))ADDR_png_set_tRNS_to_alpha)

#define png_set_filler ((void (*)(png_structp, png_uint_32, int))ADDR_png_set_filler)

#define png_set_palette_to_rgb ((void (*)(png_structp))ADDR_png_set_palette_to_rgb)

#define png_get_rowbytes ((png_uint_32 (*)(png_structp, png_infop))ADDR_png_get_rowbytes)

#define png_progressive_combine_row ((void (*)(png_structp, png_bytep, png_bytep))ADDR_png_progressive_combine_row)

#define png_sig_cmp ((int (*)(png_bytep, png_size_t, png_size_t))ADDR_png_sig_cmp)

#define png_get_io_ptr ((png_voidp (*)(png_structp))ADDR_png_get_io_ptr)

#define png_set_read_fn ((void (*)(png_structp, png_voidp, png_rw_ptr))ADDR_png_set_read_fn)

#define png_read_info ((void (*)(png_structp, png_infop))ADDR_png_read_info)

#endif // USE_LIBPNG

#endif