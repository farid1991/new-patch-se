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

#define MP_ACTION_MYMUSIC 0x15
#define MP_ACTION_SKINS 0x16
#define MP_ACTION_SAVECOVER 0x17
#define MP_ACTION_EDITTAG 0x18

#define NIL_EVENT 0
#define PAGE_ENTER_EVENT 0x5
#define PAGE_EXIT_EVENT 0x6
#define ACCEPT_EVENT 0xF
#define PREVIOUS_EVENT 0x10
#define CANCEL_EVENT 0x11
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x39
#define MM_BRW_TOPLEVEL_STARTED_EVENT 0x222F
#define MM_BRW_TOPLEVEL_DESTROYED_EVENT 0x223E

#define MM_BRW_TOPLEVEL_TITLE_TXT 0x99A
#define MP_BRW_TOPW_ICN 0xE9F2

#define page_MediaPlayer_Audio_Bk_Main (PAGE_DESC *)0x442415B8
#define page_MM_Browser_Toplevel_Bk_NowPlaying (PAGE_DESC *)0x4428747C
#define page_MM_Browser_Toplevel_Bk_Artists (PAGE_DESC *)0x4428744C
#define page_MM_Browser_Toplevel_Bk_Tracks (PAGE_DESC *)0x44287458
#define page_MM_Browser_Toplevel_Bk_Playlist (PAGE_DESC *)0x44287464
#define page_MM_Browser_Toplevel_Bk_Videos (PAGE_DESC *)0x44287470
#define page_MM_Browser_Toplevel_Bk_ShowMessage (PAGE_DESC *)0x44287494

#define FILETYPE_MP3 (wchar_t *)0x441EB54C
#define FILETYPE_mp3 (wchar_t *)0x4425E3F4

#define MIMETYPE_BMP (char *)0x441CEEEE
#define MIMETYPE_GIF (char *)0x441CED3E
#define MIMETYPE_JPEG (char *)0x441CEDAA
#define MIMETYPE_PNG (char *)0x441CEE16

#define UNKNOWN_TXT 0xE4
#define SKINSELECT_LIST_ICN 0xE9C9
#define SKINSELECT_ARROW_ICN 0xE9E5

#define MP_BR_LISTNOWPLAYING_ICN 0xEA04
#define MP_BR_LISTARTIST_ICN 0xE9E6
#define MP_BR_LISTALBUM_ICN 0xE9EC
#define MP_BR_LISTTRACK_ICN 0xE9E9
#define MP_BR_LISTPLAYLIST_ICN 0xE9E8
#define MP_BR_LISTVIDEO_ICN 0xE9EA

#define MP_BR_LISTNOWPLAYING_TXT 0xB91
#define MP_BR_LISTARTIST_TXT 0xB5D
#define MP_BR_LISTTRACK_TXT 0xBB2
#define MP_BR_LISTPLAYLIST_TXT 0xB9C
#define MP_BR_LISTVIDEO_TXT 0xBBA

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

#define ADDR_memalloc (0x44F8145C | 1)
#define ADDR_memfree (0x44F82578 | 1)
#define ADDR_memset (0x44B42F8C | 1)
#define ADDR_memcmp (0x44B42F20 | 1)
#define ADDR_memcpy (0x44069D60)
#define ADDR_debug_printf (0x44AC8A7C | 1)
#define ADDR_set_envp (0x44031AC2 | 1)
#define ADDR_get_envp (0x44031AAE | 1)
#define ADDR_current_process (0x44068DBC)
#define ADDR_get_bid (0x44068DF4)
#define ADDR_sprintf (0x44B43AB4 | 1)
#define ADDR_snwprintf (0x44B44198 | 1)
#define ADDR_sscanf (0x4402F934 | 1)
#define ADDR__fopen (0x450E5728 | 1)
#define ADDR_fread (0x450E6C24 | 1)
#define ADDR_fclose (0x450E6908 | 1)
#define ADDR_fwrite (0x450E6EC0 | 1)
#define ADDR_fstat (0x450E5FE8 | 1)
#define ADDR_lseek (0x450E704C | 1)
#define ADDR_FileDelete (0x450E613C | 1)
#define ADDR_getFileExtension (0x450E7FD8 | 1)
#define ADDR_w_diropen (0x45114B54 | 1)
#define ADDR_w_chdir (0x4511311C | 1)
#define ADDR_w_dirread (0x44CFC2AC | 1)
#define ADDR_w_fstat (0x4480D50C | 1)
#define ADDR_w_dirclose (0x45114DDC | 1)
#define ADDR_wstrlen (0x44B4462C | 1)
#define ADDR_wstrcmp (0x44B445C0 | 1)
#define ADDR_wstrcpy (0x44B445F0 | 1)
#define ADDR_wstrncpy (0x44B446A4 | 1)
#define ADDR_wstrcat (0x44B44590 | 1)
#define ADDR_wstrcmpi (0x44BF1E50 | 1)
#define ADDR_wstrrchr (0x44B446F4 | 1)
#define ADDR_wstrwstr (0x44B44600 | 1)
#define ADDR_strncmp (0x44B43FB8 | 1)
#define ADDR_strcmp (0x44B43F18 | 1)
#define ADDR_strlen (0x44B43F80 | 1)
#define ADDR_manifest_GetParam (0x4508E5E4 | 1)
#define ADDR_Timer_ReSet (0x44E81DDC | 1)
#define ADDR_Timer_Set (0x44E81DA4 | 1)
#define ADDR_Timer_Kill (0x44E81E2C | 1)
#define ADDR_List_Create (0x44E57300 | 1)
#define ADDR_List_Destroy (0x44E57324 | 1)
#define ADDR_List_DestroyElements (0x44E5774C | 1)
#define ADDR_List_InsertFirst (0x44E57444 | 1)
#define ADDR_List_InsertLast (0x44E57454 | 1)
#define ADDR_List_Get (0x44E575D4 | 1)
#define ADDR_List_GetCount (0x44E575AC | 1)
#define ADDR_BookObj_GotoPage (0x44E827BC | 1)
#define ADDR_BookObj_CallPage (0x44E828D4 | 1)
#define ADDR_BookObj_GetBookID (0x44E831E4 | 1)
#define ADDR_BookObj_CallSubroutine (0x44E8283C | 1)
#define ADDR_FreeBook (0x44E83090 | 1)
#define ADDR_UI_Event (0x4505B5E4 | 1)
#define ADDR_TextID_Create (0x44EF41C4 | 1)
#define ADDR_TextID_CreateIntegerID (0x44EF3DF4 | 1)
#define ADDR_TextID_CreateCharacterID (0x44EF3DEC | 1)
#define ADDR_TextID_Destroy (0x44EF449C | 1)
#define ADDR_TextID_GetLength (0x44EF4530 | 1)
#define ADDR_Disp_GetTextIDWidth (0x44E8F0EC | 1)
#define ADDR_strftime (0x44F6649C | 1)
#define ADDR_TextID_CreateFromTextIterator (0x44EF3F40 | 1)
#define ADDR_count_digit (0x44D33F64 | 1)
#define ADDR_itow (0x44D33BD8 | 1)
#define ADDR_MessageBox (0x45067520 | 1)
#define ADDR_MessageBox_NoImage (0x4506757C | 1)
#define ADDR_ImageID_Get (0x44F53180 | 1)
#define ADDR_ImageID_Free (0x44F53520 | 1)
#define ADDR_ImageID_GetIndirect (0x44F531D8 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x450DEB10 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x450DEC28 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x450DEDA8 | 1)
#define ADDR_Display_GetHeight (0x45063BA4 | 1)
#define ADDR_Display_GetWidth (0x45063BB4 | 1)
#define ADDR_Display_GetTopBook (0x44E82380 | 1)
#define ADDR_GUIObject_GetDispObject (0x44EA6780 | 1)
#define ADDR_DispObject_GetGUI (0x44E89D84 | 1)
#define ADDR_GUIObject_GetBook (0x44EA67A8 | 1)
#define ADDR_DispObject_SoftKeys_GetList (0x44D378B4 | 1)
#define ADDR_get_DisplayGC (0x44D42738 | 1)
#define ADDR_GC_PutChar (0x44D43218 | 1)
#define ADDR_SetFont (0x44E8E8CC | 1)
#define ADDR_DrawString (0x44E8DD78 | 1)
#define ADDR_DrawRect (0x44E8D970 | 1)
#define ADDR_GetImageWidth (0x44E8F014 | 1)
#define ADDR_GetImageHeight (0x44E8F02C | 1)
#define ADDR_GetThemeColor (0x45062EF8 | 1)
#define ADDR_DispObject_SetLayerColor (0x44E8D2F0 | 1)
#define ADDR_DispObject_SetThemeImage (0x44E8CDB8 | 1)
#define ADDR_DispObject_WindowSetSize (0x44E8BCCC | 1)
#define ADDR_DispObject_InvalidateRect (0x44E8A2A8 | 1)
#define ADDR_DispObject_SetAnimation (0x44E8D348 | 1)
#define ADDR_CreateListMenu (0x44D64144 | 1)
#define ADDR_ListMenu_SetItemCount (0x44D64300 | 1)
#define ADDR_ListMenu_SetCursorToItem (0x44D642D0 | 1)
#define ADDR_ListMenu_GetSelectedItem (0x44D642E4 | 1)
#define ADDR_ListMenu_SetOnMessage (0x44D64430 | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x44D6445C | 1)
#define ADDR_GUIonMessage_GetMsg (0x44D64978 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x44D649A4 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x44D649B4 | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x44D649F4 | 1)
#define ADDR_GUIObject_SetTitleType (0x44D396AC | 1)
#define ADDR_GUIObject_SetTitleText (0x44D396C4 | 1)
#define ADDR_GUIObject_SetTitleTextAlign (0x44D39700 | 1)
#define ADDR_GUIObject_SetSecondRowTitleText (0x44D396E0 | 1)
#define ADDR_GUIObject_SetTitleBackgroundImage (0x44D655DC | 1)
#define ADDR_GUIObject_SetStyle (0x44D39618 | 1)
#define ADDR_GUIObject_Destroy (0x44EA6538 | 1)
#define ADDR_GUIObject_Show (0x44D395C8 | 1)
#define ADDR_DispObject_SetStyle (0x44E8D374 | 1)
#define ADDR_DispObject_SetTitleType (0x44E8BFCC | 1)
#define ADDR_DispObject_SetTitleText (0x44E8BEB0 | 1)
#define ADDR_DispObject_SetSecondRowTitleText (0x44E8BEF8 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x44D3ADF0 | 1)
#define ADDR_GUIObject_SoftKeys_SetInfoText (0x44D3ADB4 | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x44D3AD08 | 1)
#define ADDR_MediaPlayer_SoftKeys_SetText (0x44C7CE24 | 1)
#define ADDR_MediaPlayer_SoftKeys_SetAction (0x44C7CDF0 | 1)
#define ADDR_MediaPlayer_SoftKeys_AddHelpStr (0x44C7CE40 | 1)
#define ADDR_MediaPlayer_SoftKeys_Validate (0x44C7CDD0 | 1)
#define ADDR_CANVAS_Get_GviGC (0x447361D0 | 1)
#define ADDR_GVI_BitBlt (0x44827E24 | 1)
#define ADDR_GVI_StretchBlt (0x44827F94 | 1)
#define ADDR_GVI_TransformBlt (0x44828040 | 1)
#define ADDR_GVI_CreatePen (0x44827484 | 1)
#define ADDR_GVI_CreateDashedPen (0x44B08BD0 | 1)
#define ADDR_GVI_CreateSolidBrush (0x44827410 | 1)
#define ADDR_GVI_Delete_GVI_Object (0x44826E6C | 1)
#define ADDR_GVI_DrawEllipse (0x44827954 | 1)
#define ADDR_GVI_DrawLine (0x448284DC | 1)
#define ADDR_GVI_DrawLines (0x44828974 | 1)
#define ADDR_GVI_DrawPolyLine (0x448289FC | 1)
#define ADDR_GVI_DrawRectangle (0x44828BE4 | 1)
#define ADDR_GVI_DrawRoundRect (0x44827D18 | 1)
#define ADDR_GVI_DrawSolidLines (0x448285E0 | 1)
#define ADDR_GVI_DrawSolidPolyLine (0x448287BC | 1)
#define ADDR_GVI_DrawSolidRectangle (0x4482887C | 1)
#define ADDR_GVI_FillEllipse (0x44827BD0 | 1)
#define ADDR_GVI_FillPolygon (0x448283D8 | 1)
#define ADDR_GVI_FillRectangle (0x44828AF4 | 1)
#define ADDR_GVI_FillRectangles (0x44828B54 | 1)
#define ADDR_GVI_FillSolidEllipse (0x44827C68 | 1)
#define ADDR_GVI_FillSolidRectangle (0x44828BA0 | 1)
#define ADDR_GVI_FillSolidRoundRect (0x44827E00 | 1)
#define ADDR_GVI_FillSolidTriangle (0x44828350 | 1)
#define ADDR_GC_CreateMemoryGC (0x44D42744 | 1)
#define ADDR_GC_FreeGC (0x44D42800 | 1)
#define ADDR_GVI_CreateBitmap (0x44827558 | 1)
#define ADDR_GVI_CreateMemoryGC (0x44828CB4 | 1)
#define ADDR_GVI_DeleteMemoryGC (0x44869158 | 1)
#define ADDR_MediaPlayer_State_Get (0x44F69D64 | 1)
#define ADDR_MediaPlayer_Audio_ActionBack (0x44F6245C | 1)
#define ADDR_MediaPlayer_Audio_ActionLongBack (0x44F5D270 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_PrevEvent (0x44F5F068 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_CancelEvent (0x44F5F0AC | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_ExitEvent (0x44F5F040 | 1)
#define ADDR_Call_MM_BrowserAlbumsMain (0x4504C774 | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Start (0x45051C20 | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Cancel (0x45051CB4 | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Destroy (0x45051CEC | 1)
#define ADDR_MediaPlayer_Audio_OnCreate (0x44E2C8DC | 1)
#define ADDR_MediaPlayer_Audio_OnClose (0x44E2C9B8 | 1)
#define ADDR_MediaPlayer_Audio_Rename (0x44F5E398 | 1)
#define ADDR_MediaPlayer_NowPlaying_OnCreate (0x44E2DE3C | 1)
#define ADDR_MediaPlayer_NowPlaying_OnClose (0x44E2DF00 | 1)
#define ADDR_MediaPlayer_NowPlaying_OnRedraw (0x44E2DF44 | 1)
#define ADDR_pg_MEDIAPLAYER_AUDIO_PLAYING_TIME (0x44F5F328 | 1)
#define ADDR_pg_MEDIAPLAYER_NEW_TRACK_EVENT (0x44F5F3A8 | 1)
#define ADDR_pg_MEDIAPLAYER_CREATED_EVENT (0x44F60880 | 1)

#define ADDR_pg_Sound_Run_EnterEvent (0x450F56C8 | 1)
#define ADDR_pg_SoundRecorder_Playing_EnterEvent (0x44C7EEA8 | 1)
