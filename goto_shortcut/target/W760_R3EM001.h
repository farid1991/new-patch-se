#pragma once

#define ZBIN_INT_PATH L"/usb/other/ZBin"
#define ZBIN_EXT_PATH L"/card/other/ZBin"
#define DIR_ZBIN_CNT 2

#define CFG_PATH (wchar_t *)0x11E350A4

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

#define TITLE_TXT 0x2C82           // L"Goto"
#define MENU_ADD_TXT 0x22D4        // L"New shortcut"
#define MENU_MODIFY_TXT 0x22CF     // L"Edit shortcut"
#define EMPTY_LIST_TXT 0xAC5       // L"No shortcuts"
#define MENU_ABOUT_TXT 0x1A02      // L"About"
#define EDITOR_TITLE_TXT 0x22CF    // L"Edit shortcuts"
#define EDITOR_LABEL_TXT 0x1E9F    // L"Edit name"
#define EDITOR_SHORTCUT_TXT 0x22CE // L"Shortcut"
#define TYPES_TITLE_TXT 0x2B44     // L"Type"
#define SHC_SET_MM 0x22DA
#define SHC_SET_SHORTCUT_SK 0x22DB
#define DELETEQ_TXT 0x22CC
#define OPEN_TXT 0x6F7
#define SELECT_TXT 0x97B
#define JAVA_APP_TXT 0x6A6
#define EVENT_TXT 0x1BB1
#define FOLDER_TXT 0x16EF
#define SELECT_FOLDER_TXT 0x1835

#define HPB_OTHER_ICN 0xF761
#define MENU_SETTINGS_ICN 0xED30
#define ANIMALS_MOUSE_ICN 0xE59C
#define SHORTCUT_LIST_ICN 0xF3C5
#define ENTERTAINMENT_ICN 0xF3BD
#define DB_LIST_JAVA_ICN 0xF875
#define GUI_UNAVAILABLE_ICN 0xF8A6
#define DB_LIST_FOLDER_ICN 0xF3BB

#define DB_CMD_DELETE 0x9
#define DB_CMD_LAST 0x4C
#define DB_CMD_RUN 0x1

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x4BB01144)
#define ADDR_memcpy (0x10147898)
#define ADDR_debug_printf (0x4BB3A365)
#define ADDR_get_envp (0x10005C38 | 1)
#define ADDR_set_envp (0x10005C4C | 1)
#define ADDR_get_bid (0x1017CC34)
#define ADDR_current_process (0x1017CBFC)
#define ADDR_snwprintf (0x10798B34 | 1)
#define ADDR__fopen (0x109F5840 | 1)
#define ADDR_fclose (0x117A443C | 1)
#define ADDR_fread (0x109F71D4 | 1)
#define ADDR_fwrite (0x109F73A0 | 1)
#define ADDR_fstat (0x109F61A4 | 1)
#define ADDR_lseek (0x109F7548 | 1)
#define ADDR_mkdir (0x109F2DBC | 1)
#define ADDR_w_fstat (0x11331024 | 1)
#define ADDR_w_diropen (0x4BB00354)
#define ADDR_w_chdir (0x4BB003AC)
#define ADDR_w_dirread (0x11AE39C4 | 1)
#define ADDR_w_dirclose (0x4BB0038C)
#define ADDR_strcpy (0x10798930 | 1)
#define ADDR_strlen (0x10798964 | 1)
#define ADDR_strstr (0x10798A70 | 1)
#define ADDR_strncmp (0x107989A0 | 1)
#define ADDR_strncpy (0x107989D4 | 1)
#define ADDR_strcat (0x107988D0 | 1)
#define ADDR_wstrcpy (0x10E011C4 | 1)
#define ADDR_wstrncpy (0x10E011DC | 1)
#define ADDR_wstrcat (0x107991F4 | 1)
#define ADDR_wstrncat (0x10E01224 | 1)
#define ADDR_wstrcmp (0x10E01194 | 1)
#define ADDR_wstrlen (0x10E01180 | 1)
#define ADDR_wstrrchr (0x10E02504 | 1)
#define ADDR_wstr2strn (0x10E012A0 | 1)
#define ADDR_str2wstr (0x10E02448 | 1)
#define ADDR_wstrncmp (0x107992C8 | 1)
#define ADDR_wstrcmpi (0x10E025E4 | 1)
#define ADDR_wstrnupr (0x10E01250 | 1)
#define ADDR_List_DestroyElements (0x11B56FA4 | 1)
#define ADDR_List_Destroy (0x11B56CB8 | 1)
#define ADDR_List_Create (0x11B56C90 | 1)
#define ADDR_List_Get (0x11B56EB0 | 1)
#define ADDR_List_InsertLast (0x11B56E0C | 1)
#define ADDR_List_InsertFirst (0x11B56E04 | 1)
#define ADDR_List_RemoveFirst (0x11B56E5C | 1)
#define ADDR_List_RemoveAt (0x11B56D90 | 1)
#define ADDR_List_GetCount (0x11B56E84 | 1)
#define ADDR_TextID_CreateIntegerID (0x10FFBD6C | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_GetString (0x10FFC64C | 1)
#define ADDR_TextID_GetWString (0x10FFC4D4 | 1)
#define ADDR_TextID_GetLength (0x10FFC384 | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)
#define ADDR_GUIObject_GetDispObject (0x10A6FBAC | 1)
#define ADDR_GUIonMessage_GetMsg (0x11B1136C | 1)
#define ADDR_GUIonMessage_GetBook (0x11B11374 | 1)
#define ADDR_GUIonMessage_GetGui (0x11B11370 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x11B11390 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x11B1139C | 1)
#define ADDR_GUIonMessage_SetMenuItemSecondLineText (0x11B113CC | 1)
#define ADDR_GUIonMessage_SetMenuItemInfoText (0x11B113AC | 1)
#define ADDR_GUIonMessage_SetMenuItemUnavailableText (0x11B113BC | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x11B113DC | 1)
#define ADDR_GUIonMessage_SetItemDisabled (0x11B11444 | 1)
#define ADDR_ImageID_Get (0x10841890 | 1)
#define ADDR_ImageID_Free (0x10847AA8 | 1)
#define ADDR_CreateBook (0x10E89BAC | 1)
#define ADDR_BookObj_CallPage (0x10E899F0 | 1)
#define ADDR_BookObj_KillBook (0x10E89CC0 | 1)
#define ADDR_BookObj_GotoPage (0x10E898BC | 1)
#define ADDR_BookObj_ReturnPage (0x10E89A74 | 1)
#define ADDR_BookObj_Hide (0x10E89E84 | 1)
#define ADDR_BookObj_Show (0x10E89E94 | 1)
#define ADDR_BookObj_GetBookID (0x10E8A318 | 1)
#define ADDR_BookObj_SetFocus (0x10E89E5C | 1)
#define ADDR_FreeBook (0x10E8A22C | 1)
#define ADDR_FindBook (0x10E87DE4 | 1)
#define ADDR_FindBookByID (0x10E87DB0 | 1)
#define ADDR_UI_Event_toBookID (0x10E889A4 | 1)
#define ADDR_Display_GetTopBook (0x10E89690 | 1)
#define ADDR_CreateOneOfMany (0x11B12B94 | 1)
#define ADDR_OneOfMany_SetItemCount (0x11B12D20 | 1)
#define ADDR_OneOfMany_SetChecked (0x11B12D3C | 1)
#define ADDR_OneOfMany_SetTexts (0x11B12D70 | 1)
#define ADDR_OneOfMany_GetSelected (0x11B12D4C | 1)
#define ADDR_CreateListMenu (0x11B105D0 | 1)
#define ADDR_ListMenu_SetItemStyle (0x11B10820 | 1)
#define ADDR_ListMenu_SetItemCount (0x11B107E4 | 1)
#define ADDR_ListMenu_SetOnMessage (0x11B108F4 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x11B107D0 | 1)
#define ADDR_ListMenu_SetCursorToItem (0x11B107BC | 1)
#define ADDR_ListMenu_SetNoItemText (0x11B10974 | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x11B10920 | 1)
#define ADDR_ListMenu_SetItemTextScroll (0x11B10EC4 | 1)
#define ADDR_ListMenu_SetItemSecondLineText (0x11B10B98 | 1)
#define ADDR_ListMenu_DestroyItems (0x11B10C3C | 1)
#define ADDR_CreateYesNoQuestion (0x118106B8 | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x11810A20 | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x11810A10 | 1)
#define ADDR_YesNoQuestion_SetIcon (0x11810A40 | 1)
#define ADDR_GUIObject_SetStyle (0x10A6FD6C | 1)
#define ADDR_GUIObject_SetTitleType (0x10A6FF0C | 1)
#define ADDR_GUIObject_SetTitleText (0x10A6FF28 | 1)
#define ADDR_GUIObject_Destroy (0x10A6FB20 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x108AE74C | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x108AE7C4 | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x108AE848 | 1)
#define ADDR_GUIObject_Show (0x10A6FD14 | 1)
#define ADDR_FILEITEM_GetFname (0x1188FBBC | 1)
#define ADDR_FILEITEM_GetPath (0x1188FC50 | 1)
#define ADDR_FSX_MakeFullPath (0x109F8FE4 | 1)
#define ADDR_FSX_FreeFullPath (0x109F9050 | 1)
#define ADDR_FSX_IsFileExists (0x1188A9F4 | 1)
#define ADDR_MessageBox_NoImage (0x11AE85E0 | 1)

#define ADDR_DataBrowser_isFileInListExt (0x109F3AC4 | 1)
#define ADDR_DataBrowserDesc_Create (0x11886338 | 1)
#define ADDR_DataBrowserDesc_SetHeaderText (0x118865E8 | 1)
#define ADDR_DataBrowserDesc_SetBookID (0x11886538 | 1)
#define ADDR_DataBrowserDesc_SetFolders (0x118865D0 | 1)
#define ADDR_DataBrowserDesc_SetFileExtList (0x118864E4 | 1)
#define ADDR_DataBrowserDesc_SetItemFilter (0x118864DC | 1)
#define ADDR_DataBrowserDesc_SetFoldersNumber (0x118865D8 | 1)
#define ADDR_DataBrowserDesc_SetSelectAction (0x11886554 | 1)
#define ADDR_DataBrowserDesc_SetDefaultActions (0x1188658C | 1)
#define ADDR_DataBrowserDesc_Menu_AddFSFunctions (0x11886540 | 1)
#define ADDR_DataBrowserDesc_Menu_AddNewFolder (0x1188659C | 1)
#define ADDR_DataBrowserDesc_Menu_AddMarkFiles (0x118865A4 | 1)
#define ADDR_DataBrowserDesc_SetOpenEmptyFolder (0x11886670 | 1)
#define ADDR_DataBrowserDesc_SetActions (0x118865AC | 1)
#define ADDR_DataBrowser_Create (0x118825D0 | 1)
#define ADDR_DataBrowserDesc_Destroy (0x118863E8 | 1)
#define ADDR_CreateStringInput (0x109342CC | 1)
#define ADDR_StringInput_SetMode (0x10934B84 | 1)
#define ADDR_StringInput_SetText (0x10934DA0 | 1)
#define ADDR_StringInput_SetFixedText (0x10934CC8 | 1)
#define ADDR_StringInput_SetMinLen (0x10934BEC | 1)
#define ADDR_StringInput_SetMaxLen (0x10934C9C | 1)
#define ADDR_StringInput_SetEnableEmptyText (0x10934D10 | 1)
#define ADDR_StringInput_SetActionOK (0x10934BE0 | 1)
#define ADDR_StringInput_SetActionBack (0x10934BE4 | 1)
#define ADDR_StringInput_GetStringAndLen (0x10934C1C | 1)
#define ADDR_StringInput_MenuItem_SetPriority (0x10934D70 | 1)
#define ADDR_JavaDialog_Open (0x10BB13A0 | 1)
#define ADDR_JavaAppDesc_GetFirstApp (0x10BA6D34 | 1)
#define ADDR_JavaAppDesc_GetJavaAppInfo (0x10BA6800 | 1)
#define ADDR_JavaApp_LogoImageID_Get (0x10CCB41C | 1)
#define ADDR_JavaAppDesc_GetNextApp (0x10BA6D3C | 1)
#define ADDR_JavaDialog_Close (0x10BB4AF4 | 1)
#define ADDR_JavaAppDesc_GetJavaAppID (0x10BB4C1C | 1)
#define ADDR_REQUEST_UI_OAF_START_APPLICATION (0x10CD6B84 | 1)
#define ADDR_Shortcut_Get_MenuItemIconID (0x10E75AFC | 1)
#define ADDR_MenuBook_Desktop_GetSelectedItemID (0x10E74C0C | 1)
#define ADDR_Shortcut_Get_MenuItemName (0x10BD1D84 | 1)
#define ADDR_Shortcut_Run (0x10E76124 | 1)
#define ADDR_MenuBook_Desktop (0x10E758D8 | 1)
#define ADDR_BookObj_SoftKeys_SetAction (0x108A8D8C | 1)
#define ADDR_BookObj_SoftKeys_SetText (0x108A8DC4 | 1)
