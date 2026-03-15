#pragma once

#define OLD_PLAYER
#define MEGABASS

#define STATUSBAR_HEIGHT 20
#define SOFTKEYS_HEIGHT 24

#define _SKIN_CFG_PATH L"/tpa/user/other/WALKMAN"
#define _SKIN_PATH L"/tpa/user/other/WALKMAN/Skins"
#define _DEFAULT_SKIN_PATH L"/tpa/user/other/WALKMAN/Skins/WALKMAN"

#define _ZBIN_PATH L"/tpa/user/other/ZBin"
#define _MTAGGER_PATH L"/tpa/user/other/ZBin/MusicTagger.elf"
#define _TAGEDIT_PATH L"/tpa/user/other/ZBin/TagEditor.elf"

#define ACTION_ACCEPT 0xFAC
#define ACTION_ADD 0xFAD
#define ACTION_BACK 0xFC1
#define ACTION_CANCEL 0xFAB
#define ACTION_CHECK 0xFB0
#define ACTION_CONTACTS 0xFBB
#define ACTION_CONTINUE 0xFB1
#define ACTION_DELETE 0xFB4
#define ACTION_DONE 0xFB5
#define ACTION_EDIT 0xFB6
#define ACTION_EXPAND 0xFA2
#define ACTION_HELP 0xFB7
#define ACTION_INFO 0xFBA
#define ACTION_LONG_BACK 0xFAF
#define ACTION_MORE 0xFA0
#define ACTION_MORE1 0xFA1
#define ACTION_MORELIST 0xFB2
#define ACTION_NO 0xFBF
#define ACTION_NOT_EMPTY 0xFBC
#define ACTION_OK 0xFC0
#define ACTION_SAVE 0xFC2
#define ACTION_SELECT 0xFB9
#define ACTION_SELECT1 0xFC3
#define ACTION_UNCHECK 0xFC4
#define ACTION_YES 0xFC6

#define MP_ACTION_MYMUSIC 0x14
#define MP_ACTION_SKINS 0x15
#define MP_ACTION_SAVECOVER 0x16
#define MP_ACTION_EDITTAG 0x17

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x39
#define MM_BRW_TOPLEVEL_STARTED_EVENT 0x222F
#define MM_BRW_TOPLEVEL_DESTROYED_EVENT 0x223E

#define MM_BRW_TOPLEVEL_TITLE_TXT 0xAA2
#define MP_BRW_TOPW_ICN 0xEA08

#define page_MediaPlayer_Audio_Bk_Main (PAGE_DESC *)0x44241D68
#define page_MM_Browser_Toplevel_Bk_NowPlaying (PAGE_DESC *)0x44287B00
#define page_MM_Browser_Toplevel_Bk_Artists (PAGE_DESC *)0x44287AD0
#define page_MM_Browser_Toplevel_Bk_Tracks (PAGE_DESC *)0x44287ADC
#define page_MM_Browser_Toplevel_Bk_Playlist (PAGE_DESC *)0x44287AE8
#define page_MM_Browser_Toplevel_Bk_Videos (PAGE_DESC *)0x44287AF4
#define page_MM_Browser_Toplevel_Bk_ShowMessage (PAGE_DESC *)0x44287B18

#define FILETYPE_MP3 (wchar_t *)0x441EBBD0
#define FILETYPE_mp3 (wchar_t *)0x4425EE28

#define MIMETYPE_BMP (char *)0x441DA8AA
#define MIMETYPE_GIF (char *)0x441DA6FA
#define MIMETYPE_JPEG (char *)0x441DA766
#define MIMETYPE_PNG (char *)0x441DA7D2

#define UNKNOWN_TXT 0xE4
#define SKINSELECT_LIST_ICN 0xE9C9
#define SKINSELECT_ARROW_ICN 0xE9E5

#define MP_BR_LISTNOWPLAYING_ICN 0xE9FA
#define MP_BR_LISTARTIST_ICN 0xE9E6
#define MP_BR_LISTALBUM_ICN 0xE9EC
#define MP_BR_LISTTRACK_ICN 0xE9E9
#define MP_BR_LISTPLAYLIST_ICN 0xE9E8
#define MP_BR_LISTVIDEO_ICN 0xE9EA

#define MP_BR_LISTNOWPLAYING_TXT 0xB92
#define MP_BR_LISTARTIST_TXT 0xB5E
#define MP_BR_LISTTRACK_TXT 0xBB3
#define MP_BR_LISTPLAYLIST_TXT 0xB9D
#define MP_BR_LISTVIDEO_TXT 0xBBB

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

#define ADDR_memalloc (0x44F89D7C | 1)
#define ADDR_memfree (0x44F8AE98 | 1)
#define ADDR_memset (0x44B46898 | 1)
#define ADDR_memcmp (0x44B4682C | 1)
#define ADDR_memcpy (0x44069D54)
#define ADDR_debug_printf (0x44AF7014 | 1)
#define ADDR_set_envp (0x44031AB6 | 1)
#define ADDR_get_envp (0x44031AA2 | 1)
#define ADDR_current_process (0x44068DB0)
#define ADDR_get_bid (0x44068DE8)
#define ADDR_sprintf (0x44B473C0 | 1)
#define ADDR_snwprintf (0x44B47AA4 | 1)
#define ADDR_sscanf (0x4402F928 | 1)
#define ADDR__fopen (0x450EC374 | 1)
#define ADDR_fread (0x450ED870 | 1)
#define ADDR_fclose (0x450ED554 | 1)
#define ADDR_fwrite (0x450EDB0C | 1)
#define ADDR_fstat (0x450ECC34 | 1)
#define ADDR_lseek (0x450EDC98 | 1)
#define ADDR_FileDelete (0x450ECD88 | 1)
#define ADDR_w_diropen (0x4511B760 | 1)
#define ADDR_w_chdir (0x45119D28 | 1)
#define ADDR_w_dirread (0x44D00464 | 1)
#define ADDR_w_fstat (0x4476D184 | 1)
#define ADDR_w_dirclose (0x4511B9E8 | 1)
#define ADDR_strncmp (0x44B478C4 | 1)
#define ADDR_strcmp (0x44B47824 | 1)
#define ADDR_wstrlen (0x44BF49F4 | 1)
#define ADDR_wstrcmp (0x44BF4A20 | 1)
#define ADDR_wstrcmpi (0x44BF6164 | 1)
#define ADDR_wstrrchr (0x44BF5FDC | 1)
#define ADDR_wstrcpy (0x44BF4A70 | 1)
#define ADDR_wstrncpy (0x44BF4AB8 | 1)
#define ADDR_wstrcat (0x44BF4B18 | 1)
#define ADDR_wstrwstr (0x44B48110 | 1)
#define ADDR_manifest_GetParam (0x45095244 | 1)
#define ADDR_Timer_ReSet (0x44E87E74 | 1)
#define ADDR_Timer_Set (0x44E87E3C | 1)
#define ADDR_Timer_Kill (0x44E87EC4 | 1)
#define ADDR_List_Create (0x44E5D390 | 1)
#define ADDR_List_Destroy (0x44E5D3B4 | 1)
#define ADDR_List_DestroyElements (0x44E5D7DC | 1)
#define ADDR_List_InsertFirst (0x44E5D4D4 | 1)
#define ADDR_List_InsertLast (0x44E5D4E4 | 1)
#define ADDR_List_Get (0x44E5D664 | 1)
#define ADDR_List_GetCount (0x44E5D63C | 1)
#define ADDR_BookObj_GotoPage (0x44E88854 | 1)
#define ADDR_BookObj_CallPage (0x44E8896C | 1)
#define ADDR_BookObj_GetBookID (0x44E8927C | 1)
#define ADDR_FreeBook (0x44E89128 | 1)
#define ADDR_UI_Event (0x45062224 | 1)
#define ADDR_TextID_Create (0x44EFA32C | 1)
#define ADDR_TextID_CreateIntegerID (0x44EF9F5C | 1)
#define ADDR_TextID_CreateCharacterID (0x44EF9F54 | 1)
#define ADDR_TextID_Destroy (0x44EFA604 | 1)
#define ADDR_TextID_GetLength (0x44EFA698 | 1)
#define ADDR_Disp_GetTextIDWidth (0x44E95184 | 1)
#define ADDR_strftime (0x44F6D9B4 | 1)
#define ADDR_TextID_CreateFromTextIterator (0x44EFA0A8 | 1)
#define ADDR_count_digit (0x44D3811C | 1)
#define ADDR_itow (0x44D37D90 | 1)
#define ADDR_MessageBox (0x4506E180 | 1)
#define ADDR_MessageBox_NoImage (0x4506E1CC | 1)
#define ADDR_ImageID_Get (0x44F5A660 | 1)
#define ADDR_ImageID_Free (0x44F5AA00 | 1)
#define ADDR_ImageID_GetIndirect (0x44F5A6B8 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x450E575C | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x450E5874 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x450E59F4 | 1)
#define ADDR_Display_GetHeight (0x4506A804 | 1)
#define ADDR_Display_GetWidth (0x4506A814 | 1)
#define ADDR_Display_GetTopBook (0x44E88418 | 1)
#define ADDR_GUIObject_GetDispObject (0x44EAC810 | 1)
#define ADDR_DispObject_GetGUI (0x44E8FE1C | 1)
#define ADDR_GUIObject_GetBook (0x44EAC838 | 1)
#define ADDR_DispObject_SoftKeys_GetList (0x44D3BA80 | 1)
#define ADDR_get_DisplayGC (0x44D46904 | 1)
#define ADDR_GC_PutChar (0x44D473E4 | 1)
#define ADDR_SetFont (0x44E94964 | 1)
#define ADDR_DrawString (0x44E93E10 | 1)
#define ADDR_DrawRect (0x44E93A08 | 1)
#define ADDR_GetImageWidth (0x44E950AC | 1)
#define ADDR_GetImageHeight (0x44E950C4 | 1)
#define ADDR_GetThemeColor (0x45069B58 | 1)
#define ADDR_DispObject_SetLayerColor (0x44E93388 | 1)
#define ADDR_DispObject_SetThemeImage (0x44E92E50 | 1)
#define ADDR_DispObject_WindowSetSize (0x44E91D64 | 1)
#define ADDR_DispObject_InvalidateRect (0x44E90340 | 1)
#define ADDR_DispObject_SetAnimation (0x44E933E0 | 1)
#define ADDR_CreateListMenu (0x44D68400 | 1)
#define ADDR_ListMenu_SetItemCount (0x44D685BC | 1)
#define ADDR_ListMenu_SetCursorToItem (0x44D6858C | 1)
#define ADDR_ListMenu_GetSelectedItem (0x44D685A0 | 1)
#define ADDR_ListMenu_SetOnMessage (0x44D686EC | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x44D68718 | 1)
#define ADDR_GUIonMessage_GetMsg (0x44D68C34 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x44D68C60 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x44D68C70 | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x44D68CB0 | 1)
#define ADDR_GUIObject_SetTitleType (0x44D3D878 | 1)
#define ADDR_GUIObject_SetTitleText (0x44D3D890 | 1)
#define ADDR_GUIObject_SetTitleTextAlign (0x44D3D8CC | 1)
#define ADDR_GUIObject_SetSecondRowTitleText (0x44D3D8AC | 1)
#define ADDR_GUIObject_SetTitleBackgroundImage (0x44D698A8 | 1)
#define ADDR_GUIObject_SetStyle (0x44D3D7E4 | 1)
#define ADDR_GUIObject_Destroy (0x44EAC5C8 | 1)
#define ADDR_GUIObject_Show (0x44D3D794 | 1)
#define ADDR_DispObject_SetStyle (0x44E9340C | 1)
#define ADDR_DispObject_SetTitleType (0x44E92064 | 1)
#define ADDR_DispObject_SetTitleText (0x44E91F48 | 1) + 1
#define ADDR_DispObject_SetSecondRowTitleText (0x44E91F90 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x44D3EFBC | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x44D3EED4 | 1)
#define ADDR_MediaPlayer_SoftKeys_SetAction (0x44C810FC | 1)
#define ADDR_MediaPlayer_SoftKeys_SetText (0x44C81130 | 1)
#define ADDR_MediaPlayer_SoftKeys_AddHelpStr (0x44C8114C | 1)
#define ADDR_GUIObject_SoftKeys_SetInfoText (0x44D3EF80 | 1)
#define ADDR_MediaPlayer_SoftKeys_Validate (0x44C810DC | 1)
#define ADDR_CANVAS_Get_GviGC (0x44A40D9C | 1)
#define ADDR_GVI_BitBlt (0x447845AC | 1)
#define ADDR_GVI_StretchBlt (0x4478471C | 1)
#define ADDR_GVI_TransformBlt (0x447847C8 | 1)
#define ADDR_GVI_CreatePen (0x44783C0C | 1)
#define ADDR_GVI_CreateDashedPen (0x44783C48 | 1)
#define ADDR_GVI_CreateSolidBrush (0x44783B98 | 1)
#define ADDR_GVI_Delete_GVI_Object (0x447835F4 | 1)
#define ADDR_GVI_DrawEllipse (0x447840DC | 1)
#define ADDR_GVI_DrawLine (0x44784C64 | 1)
#define ADDR_GVI_DrawLines (0x447850FC | 1)
#define ADDR_GVI_DrawPolyLine (0x44785184 | 1)
#define ADDR_GVI_DrawRectangle (0x4478527C | 1)
#define ADDR_GVI_DrawRoundRect (0x447844A0 | 1)
#define ADDR_GVI_DrawSolidLines (0x44784D68 | 1)
#define ADDR_GVI_DrawSolidPolyLine (0x44784F44 | 1)
#define ADDR_GVI_DrawSolidRectangle (0x44785004 | 1)
#define ADDR_GVI_FillEllipse (0x44784358 | 1)
#define ADDR_GVI_FillPolygon (0x44784B60 | 1)
#define ADDR_GVI_FillRectangle (0x4478527C | 1)
#define ADDR_GVI_FillRectangles (0x447852DC | 1)
#define ADDR_GVI_FillSolidEllipse (0x447843F0 | 1)
#define ADDR_GVI_FillSolidRectangle (0x44785328 | 1)
#define ADDR_GVI_FillSolidRoundRect (0x44784588 | 1)
#define ADDR_GVI_FillSolidTriangle (0x44784AD8 | 1)
#define ADDR_GC_CreateMemoryGC (0x44D46910 | 1)
#define ADDR_GC_FreeGC (0x44D469CC | 1)
#define ADDR_GVI_CreateBitmap (0x44783CE0 | 1)
#define ADDR_GVI_CreateMemoryGC (0x4478543C | 1)
#define ADDR_GVI_DeleteMemoryGC (0x447C5740 | 1)
#define ADDR_MediaPlayer_State_Get (0x44F71284 | 1)
#define ADDR_MediaPlayer_Audio_ActionBack (0x44F647D8 | 1)
#define ADDR_MediaPlayer_Audio_ActionLongBack (0x44F64794 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_PrevEvent (0x44F66584 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_CancelEvent (0x44F665C8 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_ExitEvent (0x44F6655C | 1)
#define ADDR_Call_MM_BrowserAlbumsMain (0x4505339C | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Start (0x45058854 | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Cancel (0x450588E8 | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Destroy (0x45058920 | 1)
#define ADDR_MediaPlayer_Audio_OnCreate (0x44E32A6C | 1)
#define ADDR_MediaPlayer_Audio_OnClose (0x44E32B48 | 1)
#define ADDR_MediaPlayer_NowPlaying_OnCreate (0x44E33FCC | 1)
#define ADDR_MediaPlayer_NowPlaying_OnClose (0x44E34090 | 1)
#define ADDR_MediaPlayer_NowPlaying_OnRedraw (0x44E340D4 | 1)
#define ADDR_pg_MEDIAPLAYER_AUDIO_PLAYING_TIME (0x44F66844 | 1)
#define ADDR_pg_MEDIAPLAYER_NEW_TRACK_EVENT (0x44F668C4 | 1)
#define ADDR_pg_MEDIAPLAYER_CREATED_EVENT (0x44F67D98 | 1)
#define ADDR_MediaPlayer_Audio_Rename (0x44F658B8 | 1)
