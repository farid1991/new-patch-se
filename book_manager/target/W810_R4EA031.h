#pragma once

#define LAST_EXTDB_PTR 0x444EE0B8
#define BRIGHTNESS_SHC (wchar_t *)0x445696E2
#define CUIDISPLAYABLE_BOOK (char *)0x4456185C

#define JAVA_STR (char *)0x449566C3
#define FOREIGN_APP_STR (char *)0x4466B79A

#define ACTION_BACK 0xFC0
#define ACTION_DELETE 0xFB4
#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2

#define KBD_SHORT_RELEASE 0x3
#define KEY_DEL 0x4
#define KEY_DIEZ 0x1B
#define KEY_DIGITAL_0 0x10
#define KEY_STAR 0x1A

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11

#define RETURN_TO_STANDBY_EVENT 0x7B2
#define TERMINATE_SESSION_EVENT 0x7B4
#define RESTARTED_ACTIVITY_MENU_EVENT 0x702

#define DB_LIST_JAVA_ICN 0xE62B
#define BOOK_ITEM_ICON 0xE806
#define ELFS_ITEM_ICON 0xE5AF

#define ADDR_memalloc (0x45453AA8 | 1)
#define ADDR_memfree (0x454547E0 | 1)
#define ADDR_memset (0x44E24360 | 1)
#define ADDR_debug_printf (0x44C9E13C | 1)
#define ADDR_set_envp (0x44149D0A | 1)
#define ADDR_get_envp (0x44149CF6 | 1)
#define ADDR_current_process (0x4418D8F0)
#define ADDR_get_bid (0x4418D928)
#define ADDR_sprintf (0x44E24E88 | 1)
#define ADDR_snwprintf (0x44E25568 | 1)
#define ADDR_sscanf (0x44147BAC | 1)
#define ADDR__fopen (0x455B4268 | 1)
#define ADDR_fread (0x455B5700 | 1)
#define ADDR_fclose (0x455B54A0 | 1)
#define ADDR_fwrite (0x455B58E4 | 1)
#define ADDR_fstat (0x455B4ADC | 1)
#define ADDR_w_diropen (0x455E5DC0 | 1)
#define ADDR_w_chdir (0x455E40A4 | 1)
#define ADDR_w_dirread (0x4510AA68 | 1)
#define ADDR_w_fstat (0x44B24B64 | 1)
#define ADDR_w_dirclose (0x455E603C | 1)
#define ADDR_wstrlen (0x44FE9B2C | 1)
#define ADDR_wstrcmpi (0x44FEAFB4 | 1)
#define ADDR_wstrrchr (0x44E25D38 | 1)
#define ADDR_wstrcpy (0x44E25C34 | 1)
#define ADDR_wstrcmp (0x44E25C04 | 1)
#define ADDR_wstrncmp (0x44E25CAC | 1)
#define ADDR_str2wstr (0x44FEAE4C | 1)
#define ADDR_strncmp (0x44E2538C | 1)
#define ADDR_strcmp (0x44E252EC | 1)
#define ADDR_strlen (0x44E25354 | 1)
#define ADDR_strcpy (0x44E2531C | 1)
#define ADDR_strstr (0x44E2546C | 1)

#define ADDR_BookObj_GetSession (0x4529FCB0 | 1)
#define ADDR_BookObj_SetFocus (0x4529F994 | 1)
#define ADDR_BookObj_GetBookID (0x4529FD0C | 1)
#define ADDR_FreeBook (0x4529FC78 | 1)
#define ADDR_Shortcut_Run (0x45643298 | 1)

#define ADDR_TextID_Create (0x452FE69C | 1)
#define ADDR_TextID_Destroy (0x452FE86C | 1)
#define ADDR_TextID_GetString (0x452FF248 | 1)
#define ADDR_TextID_GetWString (0x452FEA1C | 1)

#define ADDR_List_DestroyElements (0x4527F3B4 | 1)
#define ADDR_List_Destroy (0x4527EFC4 | 1)
#define ADDR_List_Create (0x4527EFAC | 1)
#define ADDR_List_Get (0x4527F250 | 1)
#define ADDR_List_InsertFirst (0x4527F0C0 | 1)
#define ADDR_List_GetCount (0x4527F228 | 1)
#define ADDR_root_list_get_session_count (0x45531254 | 1)
#define ADDR_root_list_get_session (0x45531268 | 1)

#define ADDR_IsVolumeControllerBook (0x45643CC0 | 1)
#define ADDR_IsRightNowBook (0x4563E6CC | 1)
#define ADDR_Find_StandbyBook (0x452AC7B8 | 1)

#define ADDR_JavaDialog_Open (0x45020BF0 | 1)
#define ADDR_JavaDialog_Close (0x45023F98 | 1)
#define ADDR_JavaAppDesc_GetFirstApp (0x4501BE90 | 1)
#define ADDR_JavaAppDesc_GetNextApp (0x4501BE98 | 1)
#define ADDR_JavaAppDesc_GetJavaAppInfo (0x4501BB98 | 1)
#define ADDR_JavaApp_LogoImageID_Get (0x4544A3B8 | 1)
#define ADDR_JavaSession_GetName (0x45641594 | 1)
#define ADDR_manifest_GetParam (0x45565E94 | 1)

#define ADDR_UI_Event_toBookID (0x455312AC | 1)
#define ADDR_UI_Event (0x4553127C | 1)
#define ADDR_UI_Event_toBookIDwData (0x455312BC | 1)
#define ADDR_MessageBox (0x45533C94 | 1)
#define ADDR_MessageBox_NoImage (0x45533CE0 | 1)
#define ADDR_GetFreeBytesOnHeap (0x45455734 | 1)
#define ADDR_iconidname2id (0x45329110 | 1)

#define ADDR_CreateListMenu (0x45170674 | 1)
#define ADDR_ListMenu_SetOnMessage (0x451709D8 | 1)
#define ADDR_ListMenu_SetItemCount (0x4517089C | 1)
#define ADDR_ListMenu_SetCursorToItem (0x45170870 | 1)
#define ADDR_ListMenu_SetNoItemText (0x45170A5C | 1)
#define ADDR_ListMenu_GetSelectedItem (0x45170884 | 1)
#define ADDR_GUIObject_SetStyle (0x45193EC4 | 1)
#define ADDR_GUIObject_TabTitleRemove (0x45171014 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x4519B824 | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x4519B9A4 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x4519B90C | 1)
#define ADDR_GUIObject_SoftKeys_SetEnable (0x4519BA78 | 1)
#define ADDR_GUIObject_Destroy (0x45193BE4 | 1)

#define ADDR_GUIonMessage_GetMsg (0x45171378 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x451713A4 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x451713B4 | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x451713F4 | 1)
#define ADDR_GUIonMessage_SetItemDisabled (0x4517144C | 1)
#define ADDR_GUIonMessage_SetMenuItemUnavailableText (0x451713D4 | 1)
#define ADDR_GUIonMessage_GetSelectedItem (0x45171384 | 1)

#define ADDR_TabMenuBar_GetFocusedTab (0x45153844 | 1)
#define ADDR_TabMenuBar_SetTabGui (0x4515394C | 1)
#define ADDR_TabMenuBar_SetTabTitle (0x45153A58 | 1)
#define ADDR_TabMenuBar_SetOnTabSwitch (0x45153ABC | 1)

#define ADDR_GUIObject_GetDispObject (0x45193C40 | 1)
#define ADDR_DispObject_GetOnKey (0x45301FCC | 1)
#define ADDR_DispObject_GetDESC (0x4531E678 | 1)
#define ADDR_DISP_DESC_SetOnKey (0x45301D30 | 1)

#define ADDR_NewEvents_GetCount (0x4563FA6C | 1)
