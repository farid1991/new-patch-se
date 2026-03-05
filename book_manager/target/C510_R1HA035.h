#pragma once

#define LAST_EXTDB_PTR 0x15B5CE04
#define BRIGHTNESS_SHC (wchar_t *)0x15A31520
#define CUIDISPLAYABLE_BOOK (char *)0x15A38E88

#define ELFS_ITEM_ICON 0xF874
#define BOOK_ITEM_ICON 0x838
#define DB_LIST_JAVA_ICN 0xF875

#define KBD_SHORT_RELEASE 0x3
#define KEY_DEL 0x5
#define KEY_DIGITAL_0 0x18
#define KEY_DIEZ 0x23
#define KEY_STAR 0x22

#define ACTION_BACK 0xFC0
#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10

#define RETURN_TO_STANDBY_EVENT 0x840
#define TERMINATE_SESSION_EVENT 0x842
#define RESTARTED_ACTIVITY_MENU_EVENT 0x1C87

#define ADDR_memalloc (0x4BA32698)
#define ADDR_memfree (0x4BA326C0)
#define ADDR_memset (0x14B31C80)
#define ADDR_set_envp (0x101D68BC | 1)
#define ADDR_get_envp (0x101D68A8 | 1)
#define ADDR_iconidname2id (0x144DA158 | 1)
#define ADDR_BookObj_GetSession (0x14481EB8 | 1)
#define ADDR_TextID_GetString (0x14182108 | 1)
#define ADDR_strncmp (0x141C7A0C | 1)
#define ADDR_JavaSession_GetName (0x140A74D8 | 1)
#define ADDR_strcmp (0x14C0BA78 | 1)
#define ADDR_fstat (0x144D8BBC | 1)
#define ADDR__fopen (0x141FA214 | 1)
#define ADDR_fread (0x14178B8C | 1)
#define ADDR_fclose (0x143CD0A0 | 1)
#define ADDR_w_fstat (0x100A6EA0 | 1)
#define ADDR_TabMenuBar_GetFocusedTab (0x1422B9E4 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x142800F8 | 1)
#define ADDR_List_Get (0x140CC3EC | 1)
#define ADDR_Find_StandbyBook (0x141ACACC | 1)
#define ADDR_BookObj_GetBookID (0x140CBC54 | 1)
#define ADDR_List_GetCount (0x140CC074 | 1)
#define ADDR_UI_Event_toBookID (0x141F464C | 1)
#define ADDR_UI_Event (0x140C5938 | 1)
#define ADDR_TextID_Create (0x141818E4 | 1)
#define ADDR_TextID_Destroy (0x14182788 | 1)
#define ADDR_TextID_GetWString (0x1418243C | 1)
#define ADDR_MessageBox (0x1585B1CC | 1)
#define ADDR_MessageBox_NoImage (0x14CE140C | 1)
#define ADDR_FreeBook (0x141293FC | 1)
#define ADDR_manifest_GetParam (0x141F620C | 1)
#define ADDR_wstrlen (0x14178EC8 | 1)
#define ADDR_wstrcmp (0x144D9600 | 1)
#define ADDR_strlen (0x14C0BAD4 | 1)
#define ADDR_strstr (0x143329AC | 1)
#define ADDR_GUIonMessage_GetMsg (0x142C5CA4 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x142C5BB4 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x1438A538 | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x144CC8B4 | 1)
#define ADDR_GetFreeBytesOnHeap (0x4BA32804)
#define ADDR_CreateListMenu (0x14285AF8 | 1)
#define ADDR_ListMenu_SetOnMessage (0x14302734 | 1)
#define ADDR_ListMenu_SetItemCount (0x14280610 | 1)
#define ADDR_ListMenu_SetCursorToItem (0x14417A80 | 1)
#define ADDR_GUIObject_SetStyle (0x14129878 | 1)
#define ADDR_GUIObject_TabTitleRemove (0x143C1DAC | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1417BACC | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x141C4E24 | 1)
#define ADDR_GUIObject_GetDispObject (0x140CACD8 | 1)
#define ADDR_DispObject_GetOnKey (0x1449FFD4 | 1)
#define ADDR_DispObject_GetDESC (0x150AFF30 | 1)
#define ADDR_DISP_DESC_SetOnKey (0x14295990 | 1)
#define ADDR_TabMenuBar_SetTabGui (0x14127A08 | 1)
#define ADDR_TabMenuBar_SetTabTitle (0x14287DDC | 1)
#define ADDR_BookObj_SetFocus (0x144CB1A0 | 1)
#define ADDR_UI_Event_toBookIDwData (0x1412935C | 1)
#define ADDR_GUIObject_SoftKeys_SetEnable (0x141C5108 | 1)
#define ADDR_ListMenu_SetNoItemText (0x1419F41C | 1)
#define ADDR_GUIonMessage_SetItemDisabled (0x144DF9F4 | 1)
#define ADDR_GUIonMessage_SetMenuItemUnavailableText (0x14075940 | 1)
#define ADDR_GUIonMessage_GetSelectedItem (0x1416A898 | 1)
#define ADDR_sprintf (0x14405D14 | 1)
#define ADDR_snwprintf (0x143EEBC4 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x141C50C8 | 1)
#define ADDR_REQUEST_SYSTEM_SHUTDOWN (0x10464F50 | 1)
#define ADDR_REQUEST_SYSTEM_RESTART (0x10464F70 | 1)
#define ADDR_Shortcut_Run (0x14278FCC | 1)
#define ADDR_FlightMode_GetState (0x141B5508 | 1)
#define ADDR_FlightMode_SetState (0x144D2134 | 1)
#define ADDR_Request_ICA_ShutdownAllConnections (0x1048F540 | 1)
#define ADDR_Display_GetBrightness (0x14D35A70 | 1)
#define ADDR_List_DestroyElements (0x140EF194 | 1)
#define ADDR_List_Destroy (0x1430E244 | 1)
#define ADDR_List_Create (0x1430E0E0 | 1)
#define ADDR_root_list_get_session_count (0x14482300 | 1)
#define ADDR_root_list_get_session (0x144825A4 | 1)
#define ADDR_List_InsertFirst (0x1430E4B0 | 1)
#define ADDR_IsVolumeControllerBook (0x14199E64 | 1)
#define ADDR_IsRightNowBook (0x14004888 | 1)
#define ADDR_strcpy (0x14C0BAA0 | 1)
#define ADDR_JavaDialog_Open (0x142CEAF8 | 1)
#define ADDR_JavaAppDesc_GetFirstApp (0x14028628 | 1)
#define ADDR_str2wstr (0x141C9A44 | 1)
#define ADDR_JavaAppDesc_GetJavaAppInfo (0x144D7ECC | 1)
#define ADDR_wstrncmp (0x14325C10 | 1)
#define ADDR_JavaApp_LogoImageID_Get (0x14EB08B4 | 1)
#define ADDR_JavaAppDesc_GetNextApp (0x143F0258 | 1)
#define ADDR_JavaDialog_Close (0x143F042C | 1)
#define ADDR_GUIObject_Destroy (0x144CBD98 | 1)
#define ADDR_NewEvents_GetCount (0x14389A0C | 1)
#define ADDR_ConnectionManager_Connection_GetState_A2 (0x144110A4 | 1)
