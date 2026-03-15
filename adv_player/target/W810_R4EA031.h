#pragma once

#define MEGABASS
#define ENABLE_VISUALIZER

#define STATUSBAR_HEIGHT 20
#define SOFTKEYS_HEIGHT 24

#define _SKIN_CFG_PATH L"/usb/other/WALKMAN"
#define _SKIN_PATH L"/usb/other/WALKMAN/skins"
#define _DEFAULT_SKIN_PATH L"/usb/other/WALKMAN/skins/WALKMAN"

#define _ZBIN_PATH L"/usb/other/ZBin"
#define _MTAGGER_PATH L"/usb/other/ZBin/MusicTagger.elf"
#define _TAGEDIT_PATH L"/usb/other/ZBin/TagEditor.elf"

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
#define MEDIAPLAYERKEY_PRESSED_EVENT 0x3B
#define MM_BRW_TOPLEVEL_STARTED_EVENT 0x2329
#define MM_BRW_TOPLEVEL_DESTROYED_EVENT 0x2338

#define MM_BRW_TOPLEVEL_TITLE_TXT 0xAA2
#define MP_BRW_TOPW_ICN 0xE865

#define FILETYPE_MP3 (wchar_t *)0x4450273C
#define FILETYPE_mp3 (wchar_t *)0x444BB4A8

#define MIMETYPE_BMP (char *)0x44409BCE
#define MIMETYPE_GIF (char *)0x44409A1E
#define MIMETYPE_JPEG (char *)0x44440978
#define MIMETYPE_PNG (char *)0x44409AF6

#define page_MediaPlayer_Audio_Bk_Main (PAGE_DESC *)0x44501424
#define page_MM_Browser_Toplevel_Bk_NowPlaying (PAGE_DESC *)0x44548534
#define page_MM_Browser_Toplevel_Bk_Artists (PAGE_DESC *)0x44548504
#define page_MM_Browser_Toplevel_Bk_Tracks (PAGE_DESC *)0x44548510
#define page_MM_Browser_Toplevel_Bk_Playlist (PAGE_DESC *)0x4454851C
#define page_MM_Browser_Toplevel_Bk_Videos (PAGE_DESC *)0x44548528
#define page_MM_Browser_Toplevel_Bk_ShowMessage (PAGE_DESC *)0x44548674

#define UNKNOWN_TXT 0xE4
#define SKINSELECT_LIST_ICN 0xE961
#define SKINSELECT_ARROW_ICN 0xE857

#define MP_BR_LISTNOWPLAYING_ICN 0xE85A
#define MP_BR_LISTARTIST_ICN 0xE858
#define MP_BR_LISTALBUM_ICN 0xE85F
#define MP_BR_LISTTRACK_ICN 0xE85C
#define MP_BR_LISTPLAYLIST_ICN 0xE85B
#define MP_BR_LISTVIDEO_ICN 0xE85D

#define MP_BR_LISTNOWPLAYING_TXT 0xCC2
#define MP_BR_LISTARTIST_TXT 0xC8C
#define MP_BR_LISTTRACK_TXT 0xCE5
#define MP_BR_LISTPLAYLIST_TXT 0xCCD
#define MP_BR_LISTVIDEO_TXT 0xCEE

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

#define ADDR_memalloc (0x45453AA8 | 1)
#define ADDR_memfree (0x454547E0 | 1)
#define ADDR_memset (0x44E24360 | 1)
#define ADDR_memcpy (0x4418E878)
#define ADDR_memcmp (0x44E242F4 | 1)
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
#define ADDR_lseek (0x455B5AA8 | 1)
#define ADDR_FileDelete (0x455B4BF4 | 1)
#define ADDR_w_diropen (0x455E5DC0 | 1)
#define ADDR_w_chdir (0x455E40A4 | 1)
#define ADDR_w_dirread (0x4510AA68 | 1)
#define ADDR_w_fstat (0x44B24B64 | 1)
#define ADDR_w_dirclose (0x455E603C | 1)
#define ADDR_strncmp (0x44E2538C | 1)
#define ADDR_strcmp (0x44E252EC | 1)
#define ADDR_strlen (0x44E25354 | 1)
#define ADDR_str2wstr (0x44FEAE4C | 1)
#define ADDR_str2wstrn (0x44FE9C1C | 1)
#define ADDR_wstrcpy (0x44E25C34 | 1)
#define ADDR_wstrncpy (0x44FE9B88 | 1)
#define ADDR_wstrcat (0x44E25BD4 | 1)
#define ADDR_wstrlen (0x44FE9B2C | 1)
#define ADDR_wstrcmp (0x44FE9B40 | 1)
#define ADDR_wstrcmpi (0x44FEAFB4 | 1)
#define ADDR_wstrrchr (0x44E25D38 | 1)
#define ADDR_wstrwstr (0x44E25E48 | 1)
#define ADDR_wstrnlwr (0x450D2754 | 1)
#define ADDR_manifest_GetParam (0x45565E94 | 1)
#define ADDR_List_Create (0x4527EFAC | 1)
#define ADDR_List_InsertFirst (0x4527F0C0 | 1)
#define ADDR_List_InsertLast (0x4527F0D0 | 1)
#define ADDR_List_Destroy (0x4527EFC4 | 1)
#define ADDR_List_DestroyElements (0x4527F3B4 | 1)
#define ADDR_List_Get (0x4527F250 | 1)
#define ADDR_List_GetCount (0x4527F228 | 1)
#define ADDR_strftime (0x454396B0 | 1)
#define ADDR_TextID_CreateFromTextIterator (0x452FE434 | 1)
#define ADDR_TextID_Create (0x452FE69C | 1)
#define ADDR_TextID_CreateIntegerID (0x452FE300 | 1)
#define ADDR_TextID_CreateCharacterID (0x452FE2F8 | 1)
#define ADDR_TextID_GetLength (0x452FE8FC | 1)
#define ADDR_TextID_Destroy (0x452FE86C | 1)
#define ADDR_TextID_GetString (0x452FF248 | 1)
#define ADDR_Disp_GetTextIDWidth (0x45308098 | 1)
#define ADDR_MessageBox_NoImage (0x45533CE0 | 1)
#define ADDR_FSX_IsFileExists (0x452510D8 | 1)
#define ADDR_FSX_MakeFullPath (0x455B6EE0 | 1)
#define ADDR_Display_GetTopBook (0x4529F01C | 1)
#define ADDR_GUIObject_GetDispObject (0x45193C40 | 1)
#define ADDR_DispObject_GetGUI (0x453024AC | 1)
#define ADDR_GUIObject_GetBook (0x45193C54 | 1)
#define ADDR_DispObject_SoftKeys_GetList (0x45199EB4 | 1)
#define ADDR_BookObj_GotoPage (0x4529F4CC | 1)
#define ADDR_BookObj_CallPage (0x4529F5DC | 1)
#define ADDR_BookObj_GetBookID (0x4529FD0C | 1)
#define ADDR_FindBook (0x45531160 | 1)
#define ADDR_FreeBook (0x4529FC78 | 1)
#define ADDR_UI_Event (0x4553127C | 1)
#define ADDR_IsAudioPlayerBook (0x4542FF58 | 1)
#define ADDR_GUIObject_SetAnimation (0x451533E0 | 1)
#define ADDR_DispObject_InvalidateRect (0x45302A70 | 1)
#define ADDR_DispObject_SetStyle (0x45306190 | 1)
#define ADDR_DispObject_GetStyle (0x453062BC | 1)
#define ADDR_DispObject_SetLayerColor (0x453060C4 | 1)
#define ADDR_DispObject_WindowSetSize (0x4530476C | 1)
#define ADDR_DispObject_SetBackgroundColor (0x4530EFFC | 1)
#define ADDR_DispObject_SetListTextColor (0x452E66F4 | 1)
#define ADDR_DispObject_SetTitleText (0x45304A34 | 1)
#define ADDR_DispObject_SetTitleType (0x45304B98 | 1)
#define ADDR_DispObject_SetSecondRowTitleText (0x45304A8C | 1)
#define ADDR_DispObject_ListMenu_GetItemCount (0x452DC0FC | 1)
#define ADDR_DispObject_SetThemeImage (0x45305BE4 | 1)
#define ADDR_DispObject_SetCursorImage (0x452E6680 | 1)
#define ADDR_DispObject_SetBackgroundImage (0x452E669C | 1)
#define ADDR_ImageID_Get (0x45426B54 | 1)
#define ADDR_ImageID_Free (0x45426B44 | 1)
#define ADDR_ImageID_GetIndirect (0x45426D24 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE (0x455ADDD0 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_REGISTER (0x455ADE50 | 1)
#define ADDR_REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER (0x455ADEE4 | 1)
#define ADDR_GUIObject_SetStyle (0x45193EC4 | 1)
#define ADDR_GUIObject_SetListTextColor (0x45171F28 | 1)
#define ADDR_GUIObject_SetCursorImage (0x45171EF8 | 1)
#define ADDR_GUIObject_SetBackgroundImage (0x45171F08 | 1)
#define ADDR_GUIObject_SetTitleBackgroundImage (0x45171F18 | 1)
#define ADDR_GUIObject_SetTitleType (0x45193F58 | 1)
#define ADDR_GUIObject_SetTitleText (0x45193F7C | 1)
#define ADDR_GUIObject_SetTitleTextAlign (0x45193FC8 | 1)
#define ADDR_GUIObject_SetSecondRowTitleText (0x45193F98 | 1)
#define ADDR_GUIObject_Show (0x45193E64 | 1)
#define ADDR_GUIObject_Destroy (0x45193BE4 | 1)
#define ADDR_CreateListMenu (0x45170674 | 1)
#define ADDR_ListMenu_SetItemCount (0x4517089C | 1)
#define ADDR_ListMenu_GetSelectedItem (0x45170884 | 1)
#define ADDR_ListMenu_SetCursorToItem (0x45170870 | 1)
#define ADDR_ListMenu_SetOnMessage (0x451709D8 | 1)
#define ADDR_ListMenu_SetHotkeyMode (0x45170A04 | 1)
#define ADDR_ListMenu_SetItemSecondLineText (0x45170C98 | 1)
#define ADDR_GUIonMessage_GetMsg (0x45171378 | 1)
#define ADDR_GUIonMessage_GetCreatedItemIndex (0x451713A4 | 1)
#define ADDR_GUIonMessage_SetMenuItemText (0x451713B4 | 1)
#define ADDR_GUIonMessage_SetMenuItemIcon (0x451713F4 | 1)
#define ADDR_CreateOneOfMany (0x4517250C | 1)
#define ADDR_OneOfMany_SetItemCount (0x451726A0 | 1)
#define ADDR_OneOfMany_SetChecked (0x451726C4 | 1)
#define ADDR_OneOfMany_SetTexts (0x451726F8 | 1)
#define ADDR_OneOfMany_GetSelected (0x451726D4 | 1)
#define ADDR_GUIObject_SoftKeys_SetActionAndText (0x45219CDC | 1)
#define ADDR_GUIObject_SoftKeys_SetAction (0x4519B824 | 1)
#define ADDR_GUIObject_SoftKeys_SetText (0x4519B90C | 1)
#define ADDR_GUIObject_SoftKeys_SetInfoText (0x4519B8D0 | 1)
#define ADDR_MessageBox (0x45533C94 | 1)
#define ADDR_GetThemeColor (0x45532A30 | 1)
#define ADDR_Display_GetHeight (0x45547974 | 1)
#define ADDR_Display_GetWidth (0x45547984 | 1)
#define ADDR_GetImageHeight (0x45307FC0 | 1)
#define ADDR_GetImageWidth (0x45307FD8 | 1)
#define ADDR_SetFont (0x45307888 | 1)
#define ADDR_DrawString (0x45306D48 | 1)
#define ADDR_DrawRect (0x45306940 | 1)
#define ADDR_DrawObject (0x45306B64 | 1)
#define ADDR_get_DisplayGC (0x45191A98 | 1)
#define ADDR_GC_PutChar (0x451925BC | 1)
#define ADDR_GC_CreateMemoryGC (0x45191AA4 | 1)
#define ADDR_GC_FreeGC (0x45191B58 | 1)
#define ADDR_GC_DrawFRect (0x45192E64 | 1)
#define ADDR_CANVAS_Get_GviGC (0x44A4CAF0 | 1)
#define ADDR_GVI_BitBlt (0x44B3EE38 | 1)
#define ADDR_GVI_StretchBlt (0x44B3EFA8 | 1)
#define ADDR_GVI_TransformBlt (0x44B3F054 | 1)
#define ADDR_GVI_CreatePen (0x44B3E498 | 1)
#define ADDR_GVI_CreateDashedPen (0x44B3E4D4 | 1)
#define ADDR_GVI_CreateSolidBrush (0x44B3E424 | 1)
#define ADDR_GVI_Delete_GVI_Object (0x44B3DE80 | 1)
#define ADDR_GVI_DrawEllipse (0x44B3E968 | 1)
#define ADDR_GVI_DrawLine (0x44B3F4F0 | 1)
#define ADDR_GVI_DrawLines (0x44B3F988 | 1)
#define ADDR_GVI_DrawPolyLine (0x44B3FA10 | 1)
#define ADDR_GVI_DrawRectangle (0x44B3FBF8 | 1)
#define ADDR_GVI_DrawRoundRect (0x44B3ED2C | 1)
#define ADDR_GVI_DrawSolidLines (0x44B3F5F4 | 1)
#define ADDR_GVI_DrawSolidPolyLine (0x44B3F7D0 | 1)
#define ADDR_GVI_DrawSolidRectangle (0x44B3F890 | 1)
#define ADDR_GVI_FillEllipse (0x44B3EBE4 | 1)
#define ADDR_GVI_FillPolygon (0x44B3F3EC | 1)
#define ADDR_GVI_FillRectangle (0x44B3FB08 | 1)
#define ADDR_GVI_FillRectangles (0x44B3FB68 | 1)
#define ADDR_GVI_FillSolidEllipse (0x44B3EC7C | 1)
#define ADDR_GVI_FillSolidRectangle (0x44B3FBB4 | 1)
#define ADDR_GVI_FillSolidRoundRect (0x44B3EE14 | 1)
#define ADDR_GVI_FillSolidTriangle (0x44B3F364 | 1)
#define ADDR_GVI_CreateBitmap (0x44B3E56C | 1)
#define ADDR_GVI_CreateMemoryGC (0x44B3FCC8 | 1)
#define ADDR_GVI_DeleteMemoryGC (0x44B88884 | 1)
#define ADDR_Timer_ReSet (0x4529EAE4 | 1)
#define ADDR_Timer_Set (0x4529EAC0 | 1)
#define ADDR_Timer_Kill (0x4529EB10 | 1)
#define ADDR_count_digit (0x451517D0 | 1)
#define ADDR_itow (0x45151444 | 1)
#define ADDR_MediaPlayer_State_Get (0x4543CC98 | 1)
#define ADDR_MediaPlayer_SoftKeys_Validate (0x45074F90 | 1)
#define ADDR_MediaPlayer_SoftKeys_SetAction (0x45074FAC | 1)
#define ADDR_MediaPlayer_SoftKeys_SetText (0x45074FE0 | 1)
#define ADDR_MediaPlayer_SoftKeys_AddHelpStr (0x45074FFC | 1)

#define ADDR_MediaPlayer_Audio_OnCreate (0x45255F84 | 1)
#define ADDR_MediaPlayer_Audio_OnClose (0x4525604C | 1)
#define ADDR_MediaPlayer_Audio_OnRefresh (0x452567B8 | 1)
#define ADDR_MediaPlayer_NowPlaying_OnCreate (0x45256DA0 | 1)
#define ADDR_MediaPlayer_NowPlaying_OnClose (0x45256E90 | 1)
#define ADDR_MediaPlayer_NowPlaying_OnRedraw (0x45256EC4 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_PrevEvent (0x45432C84 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_CancelEvent (0x45432CB4 | 1)
#define ADDR_pg_MediaPlayer_Audio_Bk_ExitEvent (0x45432C70 | 1)
#define ADDR_pg_MEDIAPLAYER_AUDIO_PLAYING_TIME (0x45432FB0 | 1)
#define ADDR_pg_MEDIAPLAYER_NEW_TRACK_EVENT (0x45433008 | 1)
#define ADDR_pg_MEDIAPLAYER_CREATED_EVENT (0x45434224 | 1)
#define ADDR_MM_BrowserToplevel_Enter (0x4552EEB8 | 1)
#define ADDR_Call_MM_BrowserAlbumsMain (0x4552AA8C | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Start (0x4552F270 | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Cancel (0x4552F2A8 | 1)
#define ADDR_pg_MM_Browser_Toplevel_Bk_Destroy (0x4552F2CC | 1)

#define ADDR_MediaPlayer_Audio_Rename (0x454320B4 | 1)
#define ADDR_MediaPlayer_Audio_Sort (0x4543646C | 1)
#define ADDR_MediaPlayer_Audio_ActionBack (0x45431080 | 1)
#define ADDR_MediaPlayer_Audio_ActionLongBack (0x4543103C | 1)