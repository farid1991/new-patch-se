#pragma once

#define ZBIN_INT_PATH L"/usb/other/ZBin"
#define ZBIN_EXT_PATH L"/card/MSSEMC/Media files/other/ZBin"
#define DIR_ZBIN_CNT 2

#define CFG_PATH (wchar_t *)0x4464B72C

#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC0
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_CONTACTS 0xFBA
#define ACTION_CONTINUE 0xFB1
#define ACTION_DELETE 0xFB4
#define ACTION_DONE 0xFB5
#define ACTION_EDIT 0xFB6
#define ACTION_EXPAND 0xFA2
#define ACTION_HELP 0xFB7
#define ACTION_INFO 0xFB9
#define ACTION_LONG_BACK 0xFAF
#define ACTION_MORE 0xFA0
#define ACTION_MORE1 0xFA1
#define ACTION_MORELIST 0xFB2
#define ACTION_NO 0xFBE
#define ACTION_NOT_EMPTY 0xFBB
#define ACTION_OK 0xFBF
#define ACTION_SAVE 0xFC1
#define ACTION_SELECT 0xFB8
#define ACTION_SELECT1 0xFC2
#define ACTION_UNCHECK 0xFC3
#define ACTION_YES 0xFC5

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define RETURN_TO_STANDBY_EVENT 0x7B2

#define TITLE_TXT 0x6D9            // L"Goto"
#define MENU_ADD_TXT 0x745         // L"New shortcut"
#define MENU_MODIFY_TXT 0x1207     // L"Edit shortcut"
#define EMPTY_LIST_TXT 0xAC5       // L"No shortcuts"
#define MENU_ABOUT_TXT 0x194E      // L"About"
#define EDITOR_TITLE_TXT 0x754     // L"Edit shortcuts"
#define EDITOR_LABEL_TXT 0x9D5     // L"Edit name"
#define EDITOR_SHORTCUT_TXT 0x122D // L"Shortcut"
#define TYPES_TITLE_TXT 0x5EA      // L"Type"
#define SHC_SET_MM 0x122C
#define SHC_SET_SHORTCUT_SK 0x122D
#define DELETEQ_TXT 0x747
#define OPEN_TXT 0xEA1
#define SELECT_TXT 0x718
#define JAVA_APP_TXT 0x342
#define EVENT_TXT 0x748
#define FOLDER_TXT 0x3E0
#define SELECT_FOLDER_TXT 0xE38

#define HPB_OTHER_ICN 0xE75E
#define MENU_SETTINGS_ICN 0xE5B3
#define ANIMALS_MOUSE_ICN 0xE59C
#define SHORTCUT_LIST_ICN 0xE95C
#define ENTERTAINMENT_ICN 0xE95E
#define DB_LIST_JAVA_ICN 0xE62B
#define GUI_UNAVAILABLE_ICN 0xE73D
#define DB_LIST_FOLDER_ICN 0xE628

#define FONT_D_18B 0x2D
#define FONT_D_24B 0x2F
#define FONT_D_29B 0x30
#define FONT_E_14B 0x11
#define FONT_E_14BI 0x13
#define FONT_E_14I 0x12
#define FONT_E_14R 0x10
#define FONT_E_16B 0x18
#define FONT_E_16BI 0x1A
#define FONT_E_16I 0x19
#define FONT_E_16R 0x17
#define FONT_E_20B 0x25
#define FONT_E_20BI 0x27
#define FONT_E_20I 0x26
#define FONT_E_20R 0x24
#define FONT_ICON_16BIT_V2 0x38

#define THEMEITEM_BACKGROUND 0x1
#define THEMEITEM_CALENDAR_WEEKVIEW_MARKINGS 0x76
#define THEMEITEM_DESKTOP 0x33
#define THEMEITEM_DESKTOP_TITLE_TEXT 0x32
#define THEMEITEM_HIGHLIGHT 0x7
#define THEMEITEM_HIGHLIGHT_TEXT 0x6
#define THEMEITEM_HOME_SCREEN 0x13
#define THEMEITEM_HOME_SCREEN_FRAME 0x24
#define THEMEITEM_HOME_SCREEN_HIGHLIGHT 0x1F
#define THEMEITEM_HOME_SCREEN_HIGHLIGHT_TEXT 0x1E
#define THEMEITEM_HOME_SCREEN_SCROLLBAR_BACKGROUND 0x23
#define THEMEITEM_HOME_SCREEN_SCROLLBAR_SLIDER 0x22
#define THEMEITEM_HOME_SCREEN_TAB 0x16
#define THEMEITEM_HOME_SCREEN_TAB_SELECTED 0x1A
#define THEMEITEM_HOME_SCREEN_TAB_TEXT 0x1C
#define THEMEITEM_HOME_SCREEN_TAB_UNSELECTED 0x18
#define THEMEITEM_HOME_SCREEN_TEXT 0x12
#define THEMEITEM_INPUT_MARKED_TEXT 0xB
#define THEMEITEM_INPUT_POPUP 0xD
#define THEMEITEM_INPUT_POPUP_FRAME 0x10
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT 0xF
#define THEMEITEM_INPUT_POPUP_HIGHLIGHT_TEXT 0xE
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_BACKGROUND 0x9
#define THEMEITEM_INPUT_POPUP_SCROLLBAR_SLIDER 0x8
#define THEMEITEM_INPUT_POPUP_TEXT 0xC
#define THEMEITEM_INPUT_TEXT 0xA
#define THEMEITEM_MORELIST 0x27
#define THEMEITEM_MORELIST_FRAME 0x30
#define THEMEITEM_MORELIST_HIGHLIGHT 0x2B
#define THEMEITEM_MORELIST_HIGHLIGHT_TEXT 0x2A
#define THEMEITEM_MORELIST_SCROLLBAR_BACKGROUND 0x2F
#define THEMEITEM_MORELIST_SCROLLBAR_SLIDER 0x2E
#define THEMEITEM_MORELIST_TEXT 0x26
#define THEMEITEM_POPUP 0x41
#define THEMEITEM_POPUP_DIM 0x4A
#define THEMEITEM_POPUP_FRAME 0x3A
#define THEMEITEM_POPUP_HIGHLIGHT 0x3D
#define THEMEITEM_POPUP_HIGHLIGHT_TEXT 0x3C
#define THEMEITEM_POPUP_SCROLLBAR_BACKGROUND 0x43
#define THEMEITEM_POPUP_SCROLLBAR_SLIDER 0x42
#define THEMEITEM_POPUP_TEXT 0x40
#define THEMEITEM_POPUP_TITLE_TEXT 0x46
#define THEMEITEM_PROGRESS_BAR_FILL 0x75
#define THEMEITEM_PROGRESS_BAR_OUTLINE 0x72
#define THEMEITEM_PROGRESS_BAR_SLIDER 0x74
#define THEMEITEM_SCROLLBAR_BACKGROUND 0x49
#define THEMEITEM_SCROLLBAR_SLIDER 0x48
#define THEMEITEM_SOFTKEY_LEFT 0x50
#define THEMEITEM_SOFTKEY_RIGHT 0x52
#define THEMEITEM_SOFTKEY_TEXT_LEFT 0x58
#define THEMEITEM_SOFTKEY_TEXT_LEFT_PRESSED 0x54
#define THEMEITEM_SOFTKEY_TEXT_RIGHT 0x5C
#define THEMEITEM_SOFTKEY_TEXT_RIGHT_PRESSED 0x56
#define THEMEITEM_STANDBY_OPERATORNAME_OUTLINE 0x61
#define THEMEITEM_STANDBY_OPERATORNAME_TEXT 0x60
#define THEMEITEM_STANDBY_TIME 0x62
#define THEMEITEM_STANDBY_TIME_OUTLINE 0x63
#define THEMEITEM_TAB 0x64
#define THEMEITEM_TAB_SELECTED 0x6A
#define THEMEITEM_TAB_TEXT 0x66
#define THEMEITEM_TAB_UNSELECTED 0x68
#define THEMEITEM_TEXT 0x4
#define THEMEITEM_TITLE_TEXT 0x6E
#define THEMEITEM_VOLUME_STAPLES 0x70
#define THEMEITEM_WAPBROWSER_TABLEBORDER 0x2
#define THEMEITEM_WAPBROWSER_UNDERLINE 0x0

#define VAR_ARG_BOOK (char *)0x4495FFD3
#define VAR_ARG_CALL_BACK_LONG_BACK (char *)0x4495FFDD
#define VAR_ARG_CALL_BACK_OK (char *)0x4495FFBB
#define VAR_ARG_CALL_BACK_PREV_ACT (char *)0x44960045
#define VAR_ARG_HTEXT (char *)0x4496005F
#define VAR_ARG_STRINP_EMPTY_STR_EN (char *)0x4496000D
#define VAR_ARG_STRINP_MAX_LEN (char *)0x4496001D
#define VAR_ARG_STRINP_MIN_LEN (char *)0x44960025
#define VAR_ARG_STRINP_MODE (char *)0x4496000F
#define VAR_ARG_STRINP_NEW_LINE (char *)0x44960001
#define VAR_ARG_STRINP_TEXT (char *)0x4495FFF7

#define DB_CMD_DELETE 0x3
#define DB_CMD_LAST 0x44
#define DB_CMD_RUN 0x1

#define ADDR_memalloc (0x45453AA8 | 1)
#define ADDR_memfree (0x454547E0 | 1)
#define ADDR_memset (0x44E24360 | 1)
#define ADDR_debug_printf (0x44C9E13C | 1)
#define ADDR_set_envp (0x44149D0A | 1)
#define ADDR_get_envp (0x44149CF6 | 1)
#define ADDR_current_process (0x4418D8F0)
#define ADDR_get_bid (0x4418D928)
#define ADDR_snwprintf (0x44E25568 | 1)
#define ADDR__fopen (0x455B4268 | 1)
#define ADDR_fread (0x455B5700 | 1)
#define ADDR_fclose (0x455B54A0 | 1)
#define ADDR_fwrite (0x455B58E4 | 1)
#define ADDR_fstat (0x455B4ADC | 1)
#define ADDR_lseek (0x455B5AA8 | 1)
#define ADDR_FileDelete (0x455B4BF4 | 1)
#define ADDR_w_diropen (0x455E5DC0 | 1)
#define ADDR_w_chdir (0x455E40A4 | 1)
#define ADDR_w_dirread (0x4510AA68 | 1)
#define ADDR_w_fstat (0x44B24B64 | 1)
#define ADDR_w_dirclose (0x455E603C | 1)
#define ADDR_wstrlen (0x44FE9B2C | 1)
#define ADDR_wstrcmpi (0x44FEAFB4 | 1)
#define ADDR_wstrrchr (0x44E25D38 | 1)
#define ADDR_wstrcpy (0x44E25C34 | 1)
#define ADDR_wstrcat (0x44E25BD4 | 1)
#define ADDR_wstrcmp (0x44E25C04 | 1)
#define ADDR_wstrncpy (0x44E25CE8 | 1)
#define ADDR_wstrncmp (0x44E25CAC | 1)
#define ADDR_wstrnupr (0x44FE9BF4 | 1)
#define ADDR_strncmp (0x44E2538C | 1)
#define ADDR_strcmp (0x44E252EC | 1)
#define ADDR_BookObj_GetSession (0x4529FCB0 | 1)
#define ADDR_BookObj_SetFocus (0x4529F994 | 1)
#define ADDR_BookObj_GotoPage (0x4529F4CC | 1)
#define ADDR_BookObj_CallPage (0x4529F5DC | 1)
#define ADDR_BookObj_ReturnPage (0x4529F648 | 1)
#define ADDR_BookObj_GetBookID (0x4529FD0C | 1)
#define ADDR_CreateBook (0x4529F750 | 1)
#define ADDR_FreeBook (0x4529FC78 | 1)
#define ADDR_FindBook (0x45531160 | 1)
#define ADDR_FindBookByID (0x45531124 | 1)
#define ADDR_UI_Event_toBookID (0x455312AC | 1)
#define ADDR_UI_Event (0x4553127C | 1)
#define ADDR_UI_Event_toBookIDwData (0x455312BC | 1)
#define ADDR_TextID_Create (0x452FE69C | 1)
#define ADDR_TextID_GetString (0x452FF248 | 1)
#define ADDR_TextID_GetWString (0x452FEA1C | 1)
#define ADDR_List_DestroyElements (0x4527F3B4 | 1)
#define ADDR_List_Destroy (0x4527EFC4 | 1)
#define ADDR_List_Create (0x4527EFAC | 1)
#define ADDR_List_Get (0x4527F250 | 1)
#define ADDR_List_InsertFirst (0x4527F0C0 | 1)
#define ADDR_List_GetCount (0x4527F228 | 1)
#define ADDR_List_RemoveFirst (0x4527F148 | 1)
#define ADDR_List_RemoveAt (0x4527F048 | 1)
#define ADDR_List_InsertLast (0x4527F0D0 | 1)
#define ADDR_CreateListMenu (0x45170674 | 1)
#define ADDR_ListMenu_SetItemStyle (0x451708E8 | 1)
#define ADDR_ListMenu_SetItemCount (0x4517089C | 1)
#define ADDR_ListMenu_SetCursorToItem (0x45170870 | 1)
#define ADDR_ListMenu_SetOnMessage (0x451709D8 | 1)
#define ADDR_ListMenu_DestroyItems (0x45170F28 | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x45170A04 | 1)
#define ADDR_ListMenu_SetItemTextScroll (0x45171004 | 1)
#define ADDR_ListMenu_SetNoItemText (0x45170A5C | 1)
#define ADDR_ListMenu_SetItemSecondLineText (0x45170C98 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x45170884 | 1)
#define ADDR_GUIObject_SetTitleText (0x45193F7C | 1)
#define ADDR_GUIObject_Show (0x45193E64 | 1)
#define ADDR_GUIObject_Destroy (0x45193BE4 | 1)
#define ADDR_GUIObject_GetDispObject (0x45193C40 | 1)
#define ADDR_GUIonMessage_GetMsg (0x45171378 | 1)
#define ADDR_GUIonMessage_GetBook (0x45171380 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x451713A4 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x451713B4 | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x451713F4 | 1)
#define ADDR_GUIonMessage_SetItemDisabled (0x4517144C | 1)
#define ADDR_GUIonMessage_SetMenuItemUnavailableText (0x451713D4 | 1)
#define ADDR_GUIonMessage_SetMenuItemSecondLineText (0x451713E4 | 1)
#define ADDR_GUIonMessage_GetSelectedItem (0x45171384 | 1)
#define ADDR_GUIObject_SoftKeys_SetActionAndText (0x45219CDC | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x4519B824 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x4519B90C | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x4519B9A4 | 1)
#define ADDR_CreateYesNoQuestion (0x45196AF4 | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x45196E8C | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x45196E7C | 1)
#define ADDR_YesNoQuestion_SetIcon (0x45196EA8 | 1)
#define ADDR_ImageID_Get (0x45426B54 | 1)
#define ADDR_ImageID_Free (0x45426B44 | 1)
#define ADDR_JavaDialog_Open (0x45020BF0 | 1)
#define ADDR_JavaDialog_Close (0x45023F98 | 1)
#define ADDR_JavaAppDesc_GetFirstApp (0x4501BE90 | 1)
#define ADDR_JavaAppDesc_GetNextApp (0x4501BE98 | 1)
#define ADDR_JavaAppDesc_GetJavaAppInfo (0x4501BB98 | 1)
#define ADDR_JavaApp_LogoImageID_Get (0x4544A3B8 | 1)
#define ADDR_JavaSession_GetName (0x45641594 | 1)
#define ADDR_JavaAppDesc_GetJavaAppID (0x450240C8 | 1)
#define ADDR_manifest_GetParam (0x45565E94 | 1)
#define ADDR_REQUEST_UI_OAF_START_APPLICATION (0x455CBD7C | 1)
#define ADDR_Shortcut_Get_MenuItemIconID (0x4553B53C | 1)
#define ADDR_MenuBook_Desktop_GetSelectedItemID (0x4553B490 | 1)
#define ADDR_Shortcut_Get_MenuItemName (0x45641074 | 1)
#define ADDR_Shortcut_Run (0x45643298 | 1)
#define ADDR_MenuBook_Desktop (0x4553A4F0 | 1)
#define ADDR_BookObj_SoftKeys_SetAction (0x4554A6B0 | 1)
#define ADDR_BookObj_SoftKeys_SetText (0x4554A6FC | 1)
#define ADDR_FILEITEM_GetFname (0x455C6A08 | 1)
#define ADDR_FILEITEM_GetPath (0x455C6A6C | 1)
#define ADDR_FSX_MakeFullPath (0x455B6EE0 | 1)
#define ADDR_FSX_IsFileExists (0x452510D8 | 1)
#define ADDR_DataBrowser_isFileInListExt (0x455B2970 | 1)
#define ADDR_DataBrowserDesc_Create (0x4524A5E4 | 1)
#define ADDR_DataBrowserDesc_SetHeaderText (0x4524A55C | 1)
#define ADDR_DataBrowserDesc_SetBookID (0x4524A498 | 1)
#define ADDR_DataBrowserDesc_SetFolders (0x4524A54C | 1)
#define ADDR_DataBrowserDesc_SetFileExtList (0x4524A444 | 1)
#define ADDR_DataBrowserDesc_SetItemFilter (0x4524A43C | 1)
#define ADDR_DataBrowserDesc_SetFoldersNumber (0x4524A554 | 1)
#define ADDR_DataBrowserDesc_SetSelectAction (0x4524A4C4 | 1)
#define ADDR_DataBrowserDesc_SetDefaultActions (0x4524A4FC | 1)
#define ADDR_DataBrowserDesc_Menu_AddFSFunctions (0x4524A4A0 | 1)
#define ADDR_DataBrowserDesc_Menu_AddNewFolder (0x4524A518 | 1)
#define ADDR_DataBrowserDesc_Menu_AddMarkFiles (0x4524A4F4 | 1)
#define ADDR_DataBrowser_Create (0x45249B38 | 1)
#define ADDR_DataBrowserDesc_Destroy (0x4524A66C | 1)
#define ADDR_CreateStringInputVA (0x45165BDC | 1)
#define ADDR_StringInput_GetStringAndLen (0x45166484 | 1)
#define ADDR_StringInput_MenuItem_SetPriority (0x451665CC | 1)
#define ADDR_StringInput_DispObject_SetText (0x452C42D0 | 1)
#define ADDR_MessageBox_NoImage (0x45533CE0 | 1)
#define ADDR_Display_GetTopBook (0x4529F01C | 1)
#define ADDR_DataBrowserDesc_SetOpenEmptyFolder (0x4524A5C4 | 1)
#define ADDR_DataBrowserDesc_SetActions (0x4524A530 | 1)