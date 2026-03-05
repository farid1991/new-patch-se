#pragma once

#define LAST_EXTDB_PTR 0x11ED5ED8
#define BRIGHTNESS_SHC (wchar_t *)0x11C10810
#define CUIDISPLAYABLE_BOOK (char *)0x11C58404

#define RESTARTED_ACTIVITY_MENU_EVENT 0x1B5B

#define ELFS_ITEM_ICON 0xF874
#define BOOK_ITEM_ICON 0xF3E8
#define DB_LIST_JAVA_ICN 0xF875

#define KBD_SHORT_RELEASE 0x3
#define KEY_STAR 0x22
#define KEY_DIEZ 0x23
#define KEY_DEL 0x5
#define KEY_DIGITAL_0 0x18

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

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x4BB01144)
#define ADDR_set_envp (0x10005C4C | 1)
#define ADDR_get_envp (0x10005C38 | 1)
#define ADDR_iconidname2id (0x115BABB0 | 1)
#define ADDR_BookObj_GetSession (0x10E8A278 | 1)
#define ADDR_TextID_GetString (0x10FFC64C | 1)
#define ADDR_strncmp (0x107989A0 | 1)
#define ADDR_JavaSession_GetName (0x1096CED4 | 1)
#define ADDR_strcmp (0x10798908 | 1)
#define ADDR_fstat (0x109F61A4 | 1)
#define ADDR__fopen (0x109F5840 | 1)
#define ADDR_fread (0x109F71D4 | 1)
#define ADDR_fclose (0x117A443C | 1)
#define ADDR_w_fstat (0x11331024 | 1)
#define ADDR_TabMenuBar_GetFocusedTab (0x1180E95C | 1)
#define ADDR_ListMenu_GetSelectedItem (0x11B107D0 | 1)
#define ADDR_List_Get (0x11B56EB0 | 1)
#define ADDR_Find_StandbyBook (0x10E28CE8 | 1)
#define ADDR_BookObj_GetBookID (0x10E8A318 | 1)
#define ADDR_List_GetCount (0x11B56E84 | 1)
#define ADDR_UI_Event_toBookID (0x10E889A4 | 1)
#define ADDR_UI_Event (0x10E8894C | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)
#define ADDR_TextID_GetWString (0x10FFC4D4 | 1)
#define ADDR_MessageBox (0x11AE853C | 1)
#define ADDR_MessageBox_NoImage (0x11AE85E0 | 1)
#define ADDR_FreeBook (0x10E8A22C | 1)
#define ADDR_manifest_GetParam (0x10BA3410 | 1)
#define ADDR_wstrlen (0x10E01180 | 1)
#define ADDR_wstrcmp (0x10E01194 | 1)
#define ADDR_strlen (0x10798964 | 1)
#define ADDR_strstr (0x10798A70 | 1)
#define ADDR_GUIonMessage_GetMsg (0x11B1136C | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x11B11390 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x11B1139C | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x11B113DC | 1)
#define ADDR_GetFreeBytesOnHeap (0x4BB00700)
#define ADDR_CreateListMenu (0x11B105D0 | 1)
#define ADDR_ListMenu_SetOnMessage (0x11B108F4 | 1)
#define ADDR_ListMenu_SetItemCount (0x11B107E4 | 1)
#define ADDR_ListMenu_SetCursorToItem (0x11B107BC | 1)
#define ADDR_GUIObject_SetStyle (0x10A6FD6C | 1)
#define ADDR_GUIObject_TabTitleRemove (0x11B10ED4 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x108AE74C | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x108AE848 | 1)
#define ADDR_GUIObject_GetDispObject (0x10A6FBAC | 1)
#define ADDR_DispObject_GetOnKey (0x10A63110 | 1)
#define ADDR_DispObject_GetDESC (0x10014E98 | 1)
#define ADDR_DISP_DESC_SetOnKey (0x10A63034 | 1)
#define ADDR_TabMenuBar_SetTabGui (0x1180E968 | 1)
#define ADDR_TabMenuBar_SetTabTitle (0x1180EA30 | 1)
#define ADDR_BookObj_SetFocus (0x10E89E5C | 1)
#define ADDR_UI_Event_toBookIDwData (0x10E889B8 | 1)
#define ADDR_GUIObject_SoftKeys_SetEnable (0x108AE8B4 | 1)
#define ADDR_ListMenu_SetNoItemText (0x11B10974 | 1)
#define ADDR_GUIonMessage_SetItemDisabled (0x11B11444 | 1)
#define ADDR_GUIonMessage_SetMenuItemUnavailableText (0x11B113BC | 1)
#define ADDR_GUIonMessage_GetSelectedItem (0x11B11378 | 1)
#define ADDR_sprintf (0x10798680 | 1)
#define ADDR_snwprintf (0x10798B34 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x108AE7C4 | 1)
#define ADDR_REQUEST_SYSTEM_SHUTDOWN (0x11596430 | 1)
#define ADDR_REQUEST_SYSTEM_RESTART (0x11596450 | 1)
#define ADDR_Shortcut_Run (0x10E76124 | 1)
#define ADDR_FlightMode_GetState (0x11AEC68C | 1)
#define ADDR_FlightMode_SetState (0x11AECEA0 | 1)
#define ADDR_Request_ICA_ShutdownAllConnections (0x115373AC | 1)
#define ADDR_Display_GetBrightness (0x10E5AA44 | 1)
#define ADDR_List_DestroyElements (0x11B56FA4 | 1)
#define ADDR_List_Destroy (0x11B56CB8 | 1)
#define ADDR_List_Create (0x11B56C90 | 1)
#define ADDR_root_list_get_session_count (0x10E87EE4 | 1)
#define ADDR_root_list_get_session (0x10E87EF4 | 1)
#define ADDR_List_InsertFirst (0x11B56E04 | 1)
#define ADDR_IsVolumeControllerBook (0x11B4A12C | 1)
#define ADDR_IsRightNowBook (0x10BD022C | 1)
#define ADDR_strcpy (0x10798930 | 1)
#define ADDR_JavaDialog_Open (0x10BB13A0 | 1)
#define ADDR_JavaAppDesc_GetFirstApp (0x10BA6D34 | 1)
#define ADDR_str2wstr (0x10E02448 | 1)
#define ADDR_JavaAppDesc_GetJavaAppInfo (0x10BA6800 | 1)
#define ADDR_wstrncmp (0x107992C8 | 1)
#define ADDR_JavaApp_LogoImageID_Get (0x10CCB41C | 1)
#define ADDR_JavaAppDesc_GetNextApp (0x10BA6D3C | 1)
#define ADDR_JavaDialog_Close (0x10BB4AF4 | 1)
#define ADDR_GUIObject_Destroy (0x10A6FB20 | 1)
#define ADDR_NewEvents_GetCount (0x10BD65AC | 1)
#define ADDR_ConnectionManager_Connection_GetState_A2 (0x10CBFFBC | 1)
