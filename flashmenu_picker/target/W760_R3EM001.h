#pragma once

#define HAS_EXTERNAL

#define DEFAULT_FLASH_PATH (wchar_t *)0x11C41524
#define INT_FLASH_PATH L"/usb/picture/flash"
#define EXT_FLASH_PATH L"/card/picture/flash"

#define MAINMENU_TXT 0xDDD
#define SUBMENU_TXT 0x22DA
#define PREVIEW_SK_TXT 0xB48
#define EMPTY_LIST_TXT 0x1B18

#define ITEM_SYS_TXT 0x326
#define ITEM_INT_TXT 0x32D
#define ITEM_EXT_TXT 0x329

#define ITEM_SYS_ICN 0xF3CB
#define ITEM_INT_ICN 0xF844
#define ITEM_EXT_ICN 0xF845
#define DB_FLASH_ICN 0xEA51

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

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x11927744 | 1)
#define ADDR_memcpy (0x11927644 | 1)
#define ADDR_debug_printf (0x4BB3A365)
#define ADDR_snwprintf (0x10798B34 | 1)
#define ADDR_strstr (0x10798A70 | 1)
#define ADDR_strlen (0x10798964 | 1)
#define ADDR_strncpy (0x107989D4 | 1)
#define ADDR_strcmp (0x10798908 | 1)
#define ADDR_wstrcmpi (0x10E025E4 | 1)
#define ADDR_wstrlen (0x10E01180 | 1)
#define ADDR_wstr2strn 0(x10E012A0 | 1)
#define ADDR_wstrnupr (0x10E01250 | 1)
#define ADDR_wstrcpy (0x10E011C4 | 1)
#define ADDR_wstrrchr (0x10E02504 | 1)
#define ADDR_wstrcmp (0x10E01194 | 1)
#define ADDR_str2wstr (0x10E02448 | 1)
#define ADDR_wstrcat (0x107991F4 | 1)
#define ADDR__fopen (0x109F5840 | 1)
#define ADDR_fread (0x109F71D4 | 1)
#define ADDR_fclose (0x117A443C | 1)
#define ADDR_fwrite (0x109F73A0 | 1)
#define ADDR_fstat (0x109F61A4 | 1)
#define ADDR_FileCopy (0x109F673C | 1)
#define ADDR_FileDelete (0x109F6434 | 1)
#define ADDR_mkdir (0x109F2DBC | 1)
#define ADDR_w_fopen (0x11330F6C | 1)
#define ADDR_w_lseek (0x11AE3334 | 1)
#define ADDR_w_fread (0x11330F9C | 1)
#define ADDR_w_fstat (0x11331024 | 1)
#define ADDR_w_fclose (0x11330FCC | 1)
#define ADDR_w_diropen (0x4BB00354)
#define ADDR_w_chdir (0x4BB003AC)
#define ADDR_w_dirread (0x11AE39C4 | 1)
#define ADDR_w_dirclose (0x4BB0038C)
#define ADDR_List_DestroyElements (0x11B56FA4 | 1)
#define ADDR_List_Destroy (0x11B56CB8 | 1)
#define ADDR_List_Create (0x11B56C90 | 1)
#define ADDR_List_Get (0x11B56EB0 | 1)
#define ADDR_List_InsertLast (0x11B56E0C | 1)
#define ADDR_List_GetCount (0x11B56E84 | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_CreateIntegerID (0x10FFBD6C | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)
#define ADDR_TextID_GetLength (0x10FFC384 | 1)
#define ADDR_Disp_GetTextIDWidth (0x10A6AF58 | 1)
#define ADDR_CreateBook (0x10E89BAC | 1)
#define ADDR_FindBook (0x10E87DE4 | 1)
#define ADDR_IsAudioPlayerBook (0x10D21FC0 | 1)
#define ADDR_BookObj_ReturnPage (0x10E89A74 | 1)
#define ADDR_BookObj_CallPage (0x10E899F0 | 1)
#define ADDR_BookObj_GotoPage (0x10E898BC | 1)
#define ADDR_BookObj_GetBookID (0x10E8A318 | 1)
#define ADDR_BookObj_SetFocus (0x10E89E5C | 1)
#define ADDR_FreeBook (0x10E8A22C | 1)
#define ADDR_UI_Event (0x10E8894C | 1)
#define ADDR_FreeAllBook (0x10EBEE98 | 1)
#define ADDR_CreateMessageBox (0x11AE85E0 | 1)
#define ADDR_BookObj_SetDisplayOrientation (0x10E8A350 | 1)
#define ADDR_BookObj_GetDisplayOrientation (0x10E8A3B4 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x108AE74C | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x108AE7C4 | 1)
#define ADDR_GUIObject_SoftKeys_SetInfoText (0x108AE7B0 | 1)
#define ADDR_GUIObject_SoftKeys_SetItemAsSubItem (0x108AE8E8 | 1)
#define ADDR_GUIObject_SoftKeys_ExecuteAction (0x108AEAE4 | 1)
#define ADDR_GUIObject_SoftKeys_SetItemOnKey (0x108AE988 | 1)
#define ADDR_GUIObject_SoftKeys_AllowKeylock (0x108AEA68 | 1)
#define ADDR_GUIObject_SoftKeys_Hide (0x108AEB04 | 1)
#define ADDR_GUIObject_SoftKeys_Show (0x108AEB10 | 1)
#define ADDR_GUIObject_SoftKeys_RemoveBackground (0x108AEB1C | 1)
#define ADDR_DispObject_SoftKeys_Hide (0x108AAC64 | 1)
#define ADDR_DispObject_SoftKeys_Show (0x108AAC9C | 1)
#define ADDR_MediaPlayer_SoftKeys_SetItemAsSubItem (0x10B90CAC | 1)
#define ADDR_MediaPlayer_SoftKeys_SetAction 0x10B90C04 | 1
#define ADDR_MediaPlayer_SoftKeys_SetText (0x10B90C4C | 1)
#define ADDR_MediaPlayer_SoftKeys_SetInfoText (0x10B90CDC | 1)
#define ADDR_DISP_DESC_SetName (0x10A6301C | 1)
#define ADDR_DISP_DESC_SetSize (0x10A63020 | 1)
#define ADDR_DISP_DESC_SetOnCreate (0x10A63024 | 1)
#define ADDR_DISP_DESC_SetOnClose (0x10A63028 | 1)
#define ADDR_DISP_DESC_SetOnRedraw (0x10A6302C | 1)
#define ADDR_DISP_DESC_SetOnRefresh (0x10A63030 | 1)
#define ADDR_DISP_DESC_SetOnKey (0x10A63034 | 1)
#define ADDR_DISP_DESC_SetOnLayout (0x10A63040 | 1)
#define ADDR_GUIObject_Create (0x10A6F95C | 1)
#define ADDR_BookObj_AddGUIObject 0x10E89F3C | 1
#define ADDR_GUIObject_SetTitleType (0x10A6FF0C | 1)
#define ADDR_GUIObject_SetTitleText (0x10A6FF28 | 1)
#define ADDR_GUIObject_SetStyle (0x10A6FD6C | 1)
#define ADDR_GUIObject_GetStyle (0x10A6FD88 | 1)
#define ADDR_GUIObject_SetSecondRowTitleText (0x10A6FF44 | 1)
#define ADDR_GUIObject_Show (0x10A6FD14 | 1)
#define ADDR_GUIObject_Destroy (0x10A6FB20 | 1)
#define ADDR_GUIObject_GetDispObject 0x10A6FBAC | 1
#define ADDR_DispObject_SoftKeys_GetList 0x108ABBC0 | 1
#define ADDR_DispObject_InvalidateRect 0x10A6653C | 1
#define ADDR_DispObject_SetLayerColor 0x10A68734 | 1
#define ADDR_DispObject_SetAnimation 0x10A687EC | 1
#define ADDR_Display_GetWidth 0x11810F14 | 1
#define ADDR_Display_GetHeight 0x11810F08 | 1
#define ADDR_DispObject_SetBacklightMode 0x10A694D4 | 1
#define ADDR_DispObject_SetBacklightTimeout 0x10A6950C | 1
#define ADDR_DispObject_GetGUI 0x10A65E20 | 1
#define ADDR_DispObject_SetStyle 0x10A68BC8 | 1
#define ADDR_DispObject_GetStyle 0x10A68E68 | 1
#define ADDR_DispObject_SetRefreshTimer 0x10A65FA4 | 1
#define ADDR_DispObject_KillRefreshTimer 0x10A66020 | 1
#define ADDR_GUIObject_GetBook 0x10A6FBC0 | 1
#define ADDR_CreateOneOfMany 0x11B12B94 | 1
#define ADDR_OneOfMany_SetChecked 0x11B12D3C | 1
#define ADDR_OneOfMany_SetItemCount 0x11B12D20 | 1
#define ADDR_OneOfMany_SetOnMessage 0x11B12D68 | 1
#define ADDR_OneOfMany_GetSelected 0x11B12D4C | 1
#define ADDR_CreateListMenu (0x11B105D0 | 1)
#define ADDR_ListMenu_SetItemCount (0x11B107E4 | 1)
#define ADDR_ListMenu_SetItemStyle 0x11B10820 | 1
#define ADDR_ListMenu_SetTexts 0x11B108FC | 1
#define ADDR_ListMenu_SetCursorToItem (0x11B107BC | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x11B10920 | 1)
#define ADDR_ListMenu_SetOnMessage (0x11B108F4 | 1)
#define ADDR_ListMenu_DestroyItems (0x11B10C3C | 1)
#define ADDR_ListMenu_SetItemTextScroll (0x11B10EC4 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x11B107D0 | 1)
#define ADDR_ListMenu_SetNoItemText (0x11B10974 | 1)
#define ADDR_ListMenu_SetItemSecondLineText (0x11B10B98 | 1)
#define ADDR_GUIonMessage_GetBook (0x11B11374 | 1)
#define ADDR_GUIonMessage_GetMsg (0x11B1136C | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x11B11390 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x11B1139C | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x11B113DC | 1)
#define ADDR_GUIonMessage_SetMenuItemSecondLineText (0x11B113CC | 1)
#define ADDR_GUIonMessage_SetItemDisabled (0x11B11444 | 1)
#define ADDR_GUIonMessage_SetMenuItemUnavailableText (0x11B113BC | 1)
#define ADDR_SetFont 0x10A6A7CC | 1
#define ADDR_DrawString 0x10A69C0C | 1
#define ADDR_DrawRect 0x10A698C0 | 1
#define ADDR_get_DisplayGC 0x10A6DB74 | 1
#define ADDR_GetImageWidth 0x10A6AEA4 | 1
#define ADDR_GetImageHeight 0x10A6AEB8 | 1
#define ADDR_GC_SetPenColor 0x10A6E380 | 1
#define ADDR_GC_SetBrushColor 0x10A6E458 | 1
#define ADDR_GC_DrawLine 0x10A6EB00 | 1
#define ADDR_GC_GetRect 0x10A6E1B4 | 1
#define ADDR_GC_GetXX 0x10A6E4B0 | 1
#define ADDR_GC_SetXX 0x10A6E4A4 | 1
#define ADDR_GC_ValidateRect 0x10A6E164 | 1
#define ADDR_GC_GetPenColor 0x10A6E3BC | 1
#define ADDR_Timer_Kill 0x10E86218 | 1
#define ADDR_Timer_ReSet 0x10E861C0 | 1
#define ADDR_Timer_Set 0x10E8618C | 1
#define ADDR_CreateTabMenuBar 0x1180E898 | 1
#define ADDR_TabMenuBar_SetTabGui 0x1180E968 | 1
#define ADDR_TabMenuBar_SetTabTitle 0x1180EA30 | 1
#define ADDR_TabMenuBar_SetTabIcon 0x1180E9E8 | 1
#define ADDR_TabMenuBar_SetTabCount 0x1180EAF0 | 1
#define ADDR_TabMenuBar_SetFocusedTab 0x1180E94C | 1
#define ADDR_CreateStringInput 0x109342CC | 1
#define ADDR_StringInput_SetMode 0x10934B84 | 1
#define ADDR_StringInput_SetFixedText 0x10934CC8 | 1
#define ADDR_StringInput_SetMinLen 0x10934BEC | 1
#define ADDR_StringInput_SetMaxLen 0x10934C9C | 1
#define ADDR_StringInput_SetEnableEmptyText 0x10934D10 | 1
#define ADDR_StringInput_SetActionOK 0x10934BE0 | 1
#define ADDR_TextFeedbackWindow 0x1180FBF8 | 1
#define ADDR_Feedback_SetTextExtended 0x11810068 | 1
#define ADDR_Feedback_CloseAction 0x1180FFC8 | 1
#define ADDR_FSX_MakeFullPath (0x109F8FE4 | 1)
#define ADDR_FSX_FreeFullPath (0x109F9050 | 1)
#define ADDR_FSX_IsFileExists (0x1188A9F4 | 1)
#define ADDR_FILEITEM_GetFname (0x1188FBBC | 1)
#define ADDR_FILEITEM_GetPath (0x1188FC50 | 1)
#define ADDR_getFileExtention (0x109F8EB0 | 1)
#define ADDR_SETTING_RINGTYPESOUNDFILE_SET 0x11B2D364 | 1
#define ADDR_Sound_SetMessageAlert 0x10CEB740 | 1
#define ADDR_Sound_SetAlarmsignal 0x109D3318 | 1
#define ADDR_Sound_AddToContact 0x10BF13F8 | 1
#define ADDR_OSE_GetShell 0x10EA6F4C | 1
#define ADDR_CoCreateInstance 0x107BC050 | 1
#define ADDR_DisplayGC_AddRef 0x10A6DFAC | 1
#define ADDR_MetaData_GetTags 0x1188B00C | 1
#define ADDR_get_envp 0x10005C38 | 1
#define ADDR_set_envp 0x10005C4C | 1
#define ADDR_Volume_Get 0x11A72594 | 1
#define ADDR_Volume_Set 0x11A724C8 | 1
#define ADDR_ImageID_Free 0x10847AA8 | 1
#define ADDR_ImageID_GetIndirect 0x10841928 | 1
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE 0x10843910 | 1
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER 0x10843988 | 1
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER 0x10843A10 | 1
#define ADDR_MainMenu_SetFromUserTheme (0x10E769CC | 1)
#define ADDR_Set_SWF_AsFlashMenu (0x10DC9F40 | 1)
#define ADDR_MessageBox (0x11AE853C | 1)
#define ADDR_GetURIScheme (0x10EA8798 | 1)
#define ADDR_CreateURI (0x10EA8C34 | 1)
#define ADDR_FreeURI (0x10EA8D88 | 1)
#define ADDR_Browser_OpenURI (0x1081CF44 | 1)
#define ADDR_wstrncpy (0x10E011DC | 1)