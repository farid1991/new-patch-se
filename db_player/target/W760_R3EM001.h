#pragma once

#define FONTDESC_PTR (FONT_DESC *)0x4BBA2400
#define FONTCOUNT_PTR (int *)0x4BBA2770

#define CID_CMetaData (PUUID)0x11E4B308
#define IID_IMetaData (PUUID)0x11E7F594

#define POPUP_WARNING_ICN 0xF831

#define TEXT_STOP 0x5C1
#define TEXT_MINIMISE 0x823
#define TEXT_SETTINGS 0x336
#define TEXT_ENABLED 0x32C
#define TEXT_DISABLED 0x32B
#define TEXT_CHANGE 0x2100
#define TEXT_QUESTION 0x72E
#define TEXT_SAVE 0x121
#define TEXT_IMAGE 0x1031
#define TEXT_CANCEL 0x860
#define TEXT_PLAY 0x15CA
#define TEXT_PAUSE 0x15D1
#define TEXT_GOTO 0xC47
#define TEXT_ACTIVATE 0xE77
#define TEXT_COLOR 0x23AA
#define TEXT_COLOR_TEXT 0x23FA
#define TEXT_COLOR_B 0x23A6
#define TEXT_MODE 0x1A1E
#define TEXT_ANIMATION 0x173C
#define TEXT_UNKNOWN 0x110

#define ACTION_LONG_BACK 0xFAF
#define ACTION_NO 0xFBE
#define ACTION_BACK 0xFC0
#define ACTION_SELECT1 0xFC2
#define ACTION_YES 0xFC5

#define NIL_EVENT 0
#define ACCEPT_EVENT 0x2
#define PREVIOUS_EVENT 0x3
#define CANCEL_EVENT 0x4
#define PAGE_ENTER_EVENT 0xF
#define PAGE_EXIT_EVENT 0x10
#define RETURN_TO_STANDBY_EVENT 0x840

#define KBD_LONG_PRESS 0x1
#define KBD_LONG_RELEASE 0x4
#define KBD_REPEAT 0x2
#define KBD_SHORT_PRESS 0x0
#define KBD_SHORT_RELEASE 0x3

#define KEY_DEL 0x5
#define KEY_DIEZ 0x23
#define KEY_DIGITAL_0 0x18
#define KEY_DIGITAL_1 0x19
#define KEY_DIGITAL_2 0x1A
#define KEY_DIGITAL_3 0x1B
#define KEY_DIGITAL_4 0x1C
#define KEY_DIGITAL_5 0x1D
#define KEY_DIGITAL_6 0x1E
#define KEY_DIGITAL_7 0x1F
#define KEY_DIGITAL_8 0x20
#define KEY_DIGITAL_9 0x21
#define KEY_DOWN 0xD
#define KEY_ENTER 0x8
#define KEY_ESC 0x4
#define KEY_LEFT 0xF
#define KEY_MEDIAPLAYER 0x28
#define KEY_RIGHT 0xB
#define KEY_STAR 0x22
#define KEY_TASK 0x24
#define KEY_UP 0x9

#define FONT_D_24B 0x3F
#define FONT_D_29B 0x40
#define FONT_D_7R 0x1
#define FONT_E_100R 0x5E
#define FONT_E_12B 0xE
#define FONT_E_12R 0xD
#define FONT_E_14B 0x13
#define FONT_E_14R 0x12
#define FONT_E_16B 0x1A
#define FONT_E_16BI 0x1C
#define FONT_E_16I 0x1B
#define FONT_E_16R 0x19
#define FONT_E_18R 0x22
#define FONT_E_20B 0x2C
#define FONT_E_20BI 0x2E
#define FONT_E_20I 0x2D
#define FONT_E_20R 0x2B
#define FONT_E_24B 0x36
#define FONT_E_24BI 0x38
#define FONT_E_24I 0x37
#define FONT_E_24R 0x35
#define FONT_E_30R 0x55
#define FONT_E_40R 0x57
#define FONT_E_60R 0x5B
#define FONT_E_75R 0x5C
#define FONT_E_8R 0x2
#define FONT_ICON_16BIT_V2 0x48

#define ADDR_memalloc (0x4BB00584)
#define ADDR_memfree (0x4BB005AC)
#define ADDR_memset (0x4BB01144)
#define ADDR_memcpy (0x10147898)
#define ADDR_debug_printf (0x4BB3A365)
#define ADDR_get_envp (0x10005C38 | 1)
#define ADDR_set_envp (0x10005C4C | 1)
#define ADDR_get_bid (0x1017CC34)
#define ADDR_current_process (0x1017CBFC)

#define ADDR_sprintf (0x10798680 | 1)
#define ADDR_snprintf (0x10798638 | 1)
#define ADDR_snwprintf (0x10798B34 | 1)
#define ADDR__fopen (0x109F5840 | 1)
#define ADDR_fclose (0x117A443C | 1)
#define ADDR_fread (0x109F71D4 | 1)
#define ADDR_fwrite (0x109F73A0 | 1)
#define ADDR_fstat (0x109F61A4 | 1)
#define ADDR_lseek (0x109F7548 | 1)
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
#define ADDR_TextID_CreateIntegerID (0x10FFBD6C | 1)
#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_GetString (0x10FFC64C | 1)
#define ADDR_TextID_GetWString (0x10FFC4D4 | 1)
#define ADDR_TextID_GetLength (0x10FFC384 | 1)
#define ADDR_TextID_Destroy (0x10FFC27C | 1)
#define ADDR_GC_GetRect (0x10A6E1B4 | 1)
#define ADDR_GC_GetXX (0x10A6E4B0 | 1)
#define ADDR_GC_SetXX (0x10A6E4A4 | 1)
#define ADDR_GC_DrawLine (0x10A6EB00 | 1)
#define ADDR_GC_GetPenColor (0x10A6E3BC | 1)
#define ADDR_GC_SetPenColor (0x10A6E380 | 1)
#define ADDR_GC_ValidateRect (0x10A6E164 | 1)
#define ADDR_BookObj_AddGUIObject (0x10E89F3C | 1)
#define ADDR_DrawRect (0x10A698C0 | 1)
#define ADDR_DrawString (0x10A69C0C | 1)
#define ADDR_SetFont (0x10A6A7CC | 1)
#define ADDR_Disp_GetTextIDWidth (0x10A6AF58 | 1)
#define ADDR_DispObject_InvalidateRect (0x10A6653C | 1)
#define ADDR_GUIObject_GetDispObject (0x10A6FBAC | 1)
#define ADDR_GUIObject_Create (0x10A6F95C | 1)
#define ADDR_get_DisplayGC (0x10A6DB74 | 1)
#define ADDR_DisplayGC_AddRef (0x10A6DFAC | 1)
#define ADDR_DISP_DESC_SetName (0x10A6301C | 1)
#define ADDR_DISP_DESC_SetSize (0x10A63020 | 1)
#define ADDR_DISP_DESC_SetOnCreate (0x10A63024 | 1)
#define ADDR_DISP_DESC_SetOnClose (0x10A63028 | 1)
#define ADDR_DISP_DESC_SetOnRedraw (0x10A6302C | 1)
#define ADDR_DISP_DESC_SetOnKey (0x10A63034 | 1)
#define ADDR_DISP_DESC_SetOnRefresh (0x10A63030 | 1)
#define ADDR_DISP_DESC_SetMethod06 (0x10A63038 | 1)
#define ADDR_DISP_DESC_SetOnLayout (0x10A63040 | 1)
#define ADDR_DISP_DESC_SetOnConfig (0x10A63044 | 1)
#define ADDR_DispObject_SetLayerColor (0x10A68734 | 1)
#define ADDR_DispObject_SetRefreshTimer (0x10A65FA4 | 1)
#define ADDR_DispObject_KillRefreshTimer (0x10A66020 | 1)
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
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x10843910 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x10843988 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x10843A10 | 1)
#define ADDR_ImageID_Get (0x10841890 | 1)
#define ADDR_ImageID_Free (0x10847AA8 | 1)
#define ADDR_ImageID_GetIndirect (0x10841928 | 1)
#define ADDR_Timer_ReSet (0x10E861C0 | 1)
#define ADDR_Timer_Set (0x10E8618C | 1)
#define ADDR_Timer_Kill (0x10E86218 | 1)
#define ADDR_CreateBook (0x10E89BAC | 1)
#define ADDR_BookObj_KillBook (0x10E89CC0 | 1)
#define ADDR_BookObj_GotoPage (0x10E898BC | 1)
#define ADDR_BookObj_ReturnPage (0x10E89A74 | 1)
#define ADDR_BookObj_Hide (0x10E89E84 | 1)
#define ADDR_BookObj_Show (0x10E89E94 | 1)
#define ADDR_FreeBook (0x10E8A22C | 1)
#define ADDR_FindBook (0x10E87DE4 | 1)
#define ADDR_Display_GetHeight (0x11810F08 | 1)
#define ADDR_Display_GetWidth (0x11810F14 | 1)
#define ADDR_GC_PutChar (0x10A6E5AC | 1)
#define ADDR_GetImageWidth (0x10A6AEA4 | 1)
#define ADDR_GetImageHeight (0x10A6AEB8 | 1)
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
#define ADDR_GUIObject_SoftKeys_SetActionAndText (0x10C0943C | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x108AE848 | 1)
#define ADDR_GUIObject_SoftKeys_Hide (0x108AEB04 | 1)
#define ADDR_GUIObject_SoftKeys_Show (0x108AEB10 | 1)
#define ADDR_GUIObject_SoftKeys_RemoveBackground (0x108AEB1C | 1)
#define ADDR_GUIObject_SoftKeys_RestoreBackground (0x108AEB28 | 1)
#define ADDR_GUIObject_Show (0x10A6FD14 | 1)
#define ADDR_GUIObject_SetBacklightOn (0x10A6FE4C | 1)
#define ADDR_GUIObject_SetBacklightOff (0x10A6FE78 | 1)
#define ADDR_DispObject_SetAnimation (0x10A687EC | 1)
#define ADDR_DispObject_SetBacklightMode (0x10A694D4 | 1)
#define ADDR_DispObject_SetThemeImage (0x10A68290 | 1)
#define ADDR_FILEITEM_GetFname (0x1188FBBC | 1)
#define ADDR_FILEITEM_GetPath (0x1188FC50 | 1)
#define ADDR_MetaData_GetTags (0x1188B00C | 1)
#define ADDR_Volume_Get (0x11A72594 | 1)
#define ADDR_Volume_Set (0x11A724C8 | 1)
#define ADDR_CoCreateInstance (0x107BC050 | 1)
#define ADDR_FSX_MakeFullPath (0x109F8FE4 | 1)
#define ADDR_FSX_FreeFullPath (0x109F9050 | 1)
#define ADDR_FSX_IsFileExists (0x1188A9F4 | 1)
#define ADDR_MessageBox_NoImage (0x11AE85E0 | 1)
