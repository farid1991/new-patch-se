#pragma once

#define DB3350_R2

#define POPUP_WARNING_ICN 0xF831

#define TEXT_STOP 0xF4D
#define TEXT_MINIMISE 0x92A
#define TEXT_SETTINGS 0x388
#define TEXT_ENABLED 0xAE2
#define TEXT_DISABLED 0xAE0
#define TEXT_CHANGE 0x251
#define TEXT_QUESTION 0x839
#define TEXT_SAVE 0x315
#define TEXT_IMAGE 0xE75
#define TEXT_CANCEL 0x1781
#define TEXT_PLAY 0x812
#define TEXT_PAUSE 0x875
#define TEXT_GOTO 0xD1C
#define TEXT_COLOR 0x234E
#define TEXT_COLOR_B 0x2349
#define TEXT_MODE 0x1A94
#define TEXT_UNKNOWN 0x134

#define TEXT_ID_ARTIST 0x16C3
#define TEXT_ID_ALBUM 0x16C2
#define TEXT_ID_TITLE 0x1714
#define TEXT_ID_GENRE 0x16C5
#define TEXT_ID_YEAR 0x1736
#define TEXT_ID_ALBUMART 0x171F
#define TEXT_ID_FILETYPE 0x16C6

#define KBD_SHORT_PRESS 0x0
#define KBD_LONG_PRESS 0x1
#define KBD_REPEAT 0x2
#define KBD_SHORT_RELEASE 0x3
#define KBD_LONG_RELEASE 0x4

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

#define KEY_STAR 0x22
#define KEY_DIEZ 0x23
#define KEY_UP 0x9
#define KEY_DOWN 0xD
#define KEY_LEFT 0xF
#define KEY_RIGHT 0xB
#define KEY_ESC 0x4
#define KEY_DEL 0x5
#define KEY_ENTER 0x8

#define ACTION_LONG_BACK 0xFAF
#define ACTION_SELECT1 0xFC2
#define ACTION_DELETE 0xFB4
#define ACTION_ACCEPT 0xFAC
#define ACTION_BACK 0xFC0
#define ACTION_YES 0xFC5
#define ACTION_NO 0xFBE

#define NIL_EVENT 0
#define ACCEPT_EVENT 2
#define PREVIOUS_EVENT 3
#define CANCEL_EVENT 4
#define PAGE_ENTER_EVENT 0x10
#define PAGE_EXIT_EVENT 0x11
#define RETURN_TO_STANDBY_EVENT 0x840

#define FONT_D_18B 0x112
#define FONT_D_24B 0x118
#define FONT_D_29B 0x11D
#define FONT_D_7R 0x7
#define FONT_E_100R 0x64
#define FONT_E_12B 0x10C
#define FONT_E_12R 0xC
#define FONT_E_14B 0x10E
#define FONT_E_14BI 0x30E
#define FONT_E_14I 0x20E
#define FONT_E_14R 0xE
#define FONT_E_16B 0x110
#define FONT_E_16BI 0x310
#define FONT_E_16I 0x210
#define FONT_E_16R 0x10
#define FONT_E_18B 0x112
#define FONT_E_18BI 0x312
#define FONT_E_18I 0x212
#define FONT_E_18R 0x12
#define FONT_E_20B 0x114
#define FONT_E_20BI 0x314
#define FONT_E_20I 0x214
#define FONT_E_20R 0x14
#define FONT_E_22B 0x116
#define FONT_E_22BI 0x316
#define FONT_E_22I 0x216
#define FONT_E_22R 0x16
#define FONT_E_24B 0x118
#define FONT_E_24BI 0x318
#define FONT_E_24I 0x218
#define FONT_E_24R 0x18
#define FONT_E_25B 0x119
#define FONT_E_25BI 0x319
#define FONT_E_25I 0x219
#define FONT_E_25R 0x19
#define FONT_E_30R 0x1E
#define FONT_E_36R 0x24
#define FONT_E_40R 0x28
#define FONT_E_50R 0x32
#define FONT_E_60R 0x3C
#define FONT_E_75R 0x49
#define FONT_E_8R 0x8

#define CID_CUIFontManager (PUUID)0x1571BACC
#define IID_IUIFontManager (PUUID)0x1575471C
#define CID_CTextRenderingManager (PUUID)0x15722A1C
#define IID_ITextRenderingManager (PUUID)0x1575A340
#define CID_CUIImageManager (PUUID)0x15720964
#define IID_IUIImageManager (PUUID)0x157576C0
#define CID_CMetaData (PUUID)0x156FE4C4
#define IID_IMetaData (PUUID)0x1573FE24

#define ADDR_memalloc (0x4BC00394)
#define ADDR_memfree (0x4BC003BC)
#define ADDR_memset (0x145C5AE8)
#define ADDR_memcpy (0x145C5D98)
#define ADDR_get_envp (0x101A1C18 | 1)
#define ADDR_set_envp (0x101A1C2C | 1)
#define ADDR_get_bid (0x101A1508)
#define ADDR_current_process (0x101A14D0)

#define ADDR__fopen (0x142048D8 | 1)
#define ADDR_fread (0x1428EA7C | 1)
#define ADDR_fwrite (0x1428F010 | 1)
#define ADDR_fclose (0x14587FC0 | 1)
#define ADDR_fstat (0x145BAB14 | 1)
#define ADDR_lseek (0x1428EC20 | 1)
#define ADDR_FSX_IsFileExists (0x14975F68 | 1)
#define ADDR_FSX_MakeFullPath (0x145B9D4C | 1)
#define ADDR_FSX_FreeFullPath (0x141144A8 | 1)
#define ADDR_FILEITEM_GetFname (0x140214AC | 1)
#define ADDR_FILEITEM_GetPath (0x140213B0 | 1)

#define ADDR_snprintf (0x145C4AF0 | 1)
#define ADDR_snwprintf (0x145C4A3C | 1)
#define ADDR_strcpy (0x142F73B8 | 1)
#define ADDR_strncpy (0x145C60DC)
#define ADDR_wstrcpy (0x145C5B08 | 1)
#define ADDR_strstr (0x145C635A | 1)
#define ADDR_strlen (0x142F7364 | 1)
#define ADDR_wstrlen (0x145C5D36 | 1)
#define ADDR_wstrcat (0x145C5B40 | 1)
#define ADDR_wstrrchr (0x1428E348 | 1)
#define ADDR_str2wstr (0x142B4188 | 1)

#define ADDR_Timer_Set (0x143A995C | 1)
#define ADDR_Timer_ReSet (0x145B91D8 | 1)
#define ADDR_Timer_Kill (0x145B8DE8 | 1)

#define ADDR_MessageBox_NoImage (0x148C315C | 1)
#define ADDR_TextID_Create (0x145B8610 | 1)
#define ADDR_TextID_Copy (0x145B7F08 | 1)
#define ADDR_TextID_GetWString (0x145B7BF4 | 1)
#define ADDR_TextID_GetLength (0x145B80E8 | 1)
#define ADDR_TextID_Destroy (0x145B7C6C | 1)
#define ADDR_CoCreateInstance (0x144E924C | 1)
#define ADDR_get_DisplayGC (0x142CCD80 | 1)
#define ADDR_DisplayGC_AddRef (0x14370D88 | 1)
#define ADDR_TextObject_SetText (0x1427864C | 1)
#define ADDR_TextObject_SetFont (0x144AEC28 | 1)
#define ADDR_RichTextLayout_GetTextWidth (0x1495EE6C | 1)

#define ADDR_DISP_DESC_SetSize (0x1448D778 | 1)
#define ADDR_DISP_DESC_SetName (0x1448D77C | 1)
#define ADDR_DISP_DESC_SetOnCreate (0x1448D7F0 | 1)
#define ADDR_DISP_DESC_SetOnClose (0x1448D780 | 1)
#define ADDR_DISP_DESC_SetOnRedraw (0x1448D774 | 1)
#define ADDR_DISP_DESC_SetOnKey (0x1448D300 | 1)
#define ADDR_DISP_DESC_SetOnLayout (0x1448D8C8 | 1)
#define ADDR_DISP_DESC_SetOnRefresh (0x1448D304 | 1)
#define ADDR_DispObject_InvalidateRect (0x144D7100 | 1)
#define ADDR_DispObject_SetLayerColor (0x14566D90 | 1)
#define ADDR_DispObject_SetRefreshTimer (0x1427816C | 1)
#define ADDR_DispObject_KillRefreshTimer (0x142781B4 | 1)
#define ADDR_DispObject_SetBacklightMode (0x144CEE00 | 1)
#define ADDR_DispObject_SetThemeImage (0x140538E0 | 1)

#define ADDR_GUIObject_Create (0x141798F4 | 1)
#define ADDR_GUIObject_GetDispObject (0x1446083C | 1)
#define ADDR_GUIObject_SetStyle (0x143F35FC | 1)
#define ADDR_GUIObject_SetTitleType (0x143F4A74 | 1)
#define ADDR_GUIObject_SetTitleText (0x14053100 | 1)
#define ADDR_GUIObject_Show (0x1417A694 | 1)
#define ADDR_GUIObject_Destroy (0x14554DF4 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x14559DC4 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x1455ADF0 | 1)
#define ADDR_GUIObject_SoftKeys_SetActionAndText (0x14704240 | 1)
#define ADDR_GUIObject_SoftKeys_SetVisible (0x142CE958 | 1)
#define ADDR_GUIObject_SoftKeys_Hide (0x14177518 | 1)
#define ADDR_GUIObject_SoftKeys_Show (0x14B790FC | 1)
#define ADDR_GUIObject_SoftKeys_RemoveBackground (0x144DFF58 | 1)
#define ADDR_GUIObject_SoftKeys_RestoreBackground (0x146B4CD0 | 1)

#define ADDR_CreateListMenu (0x14179864 | 1)
#define ADDR_ListMenu_SetItemCount (0x140D9A08 | 1)
#define ADDR_ListMenu_SetItemStyle (0x1417BB54 | 1)
#define ADDR_ListMenu_SetCursorToItem (0x140030F0 | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x1417BC0C | 1)
#define ADDR_ListMenu_SetOnMessage (0x143C8F80 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x1436F420 | 1)
#define ADDR_ListMenu_DestroyItems (0x1447A20C | 1)
#define ADDR_ListMenu_SetItemSecondLineText (0x14051F38 | 1)
#define ADDR_GUIonMessage_GetBook (0x1436E40C | 1)
#define ADDR_GUIonMessage_GetMsg (0x140222FC | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x14022530 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x1402281C | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x1436FAA0 | 1)
#define ADDR_GUIonMessage_SetMenuItemSecondLineText (0x14193DF4 | 1)
#define ADDR_GUIonMessage_SetItemDisabled (0x148CF8FC | 1)

#define ADDR_CreateOneOfMany (0x14C3144C | 1)
#define ADDR_OneOfMany_SetChecked (0x14C31610 | 1)
#define ADDR_OneOfMany_SetTexts (0x14C312BC | 1)
#define ADDR_OneOfMany_GetSelected (0x147DDFDC | 1)
#define ADDR_OneOfMany_SetFocused (0x14C3128C | 1)

#define ADDR_CreateYesNoQuestion (0x1495DA80 | 1)
#define ADDR_YesNoQuestion_SetQuestionText (0x1495DA60 | 1)
#define ADDR_YesNoQuestion_SetDescriptionText (0x1495D904 | 1)
#define ADDR_YesNoQuestion_SetIcon (0x1495D904 | 1)

#define ADDR_DrawRect (0x141A41F0 | 1)
#define ADDR_GC_SetXX (0x141D25BC | 1)
#define ADDR_GC_GetXX (0x14558708 | 1)
#define ADDR_GC_GetRect (0x144D6370 | 1)
#define ADDR_GC_SetPenColor (0x141A2108 | 1)
#define ADDR_GC_GetPenColor (0x141A3FE8 | 1)
#define ADDR_GC_DrawLine (0x1419EC00 | 1)
#define ADDR_Display_GetHeight (0x144D60E0 | 1)
#define ADDR_Display_GetWidth (0x144D60D0 | 1)

#define ADDR_CreateBook (0x14179108 | 1)
#define ADDR_FreeBook (0x1417924C | 1)
#define ADDR_BookObj_AddGUIObject (0x141798E8 | 1)
#define ADDR_BookObj_SetFocus (0x141775BC | 1)
#define ADDR_BookObj_GotoPage (0x1404FF00 | 1)
#define ADDR_BookObj_ReturnPage (0x1422D034 | 1)
#define ADDR_BookObj_Hide (0x144A625C | 1)

#define ADDR_ImageID_Get (0x143F7100 | 1)
#define ADDR_ImageID_Free (0x140230CC | 1)
#define ADDR_ImageID_GetIndirect (0x14CD4B2C | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x147E29C0 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x14CD5A2C | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x14C16B4C | 1)

#define ADDR_Volume_Get (0x144DA0C0 | 1)
#define ADDR_Volume_Set (0x144DC690 | 1)
#define ADDR_MetaData_GetTags (0x14A01E18 | 1)

#define ADDR_pg_Sound_Run__0x17FC (0x14816C1C | 1)
