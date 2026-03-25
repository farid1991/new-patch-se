#if defined(W700_R1CA021)
    .equ MEDIAPLAYERKEY_PRESSED_EVENT, 0x39
    .equ MP_BR_LISTNOWPLAYING_TXT, 0xB92

    .equ UI_Event, 0x45062224
    .equ TextID_Create, 0x44EFA32C
    .equ DispObject_SetTitleText, 0x44E91F48
    .equ MediaPlayer_Audio_Rename, 0x44F658B8
    .equ MediaPlayer_SoftKeys_Validate, 0x44C810DC

    .equ mp_playqueue_setstyle_ret, 0x44E32C42
    .equ mp_nowplaying_setsize_ret, 0x44E32F1C
    .equ mp_audio_setstyle_ret, 0x44E32B0C
    .equ mp_softkeys_minim_ret, 0x44F64A2C
    .equ mp_softkeys_ret1, 0x44F64B28
    .equ mp_softkeys_ret2, 0x44F64B34
    .equ audioplayer_onclose_func, 0x44F6B898
    .equ audioplayer_onclose_ret, 0x44F64320
    .equ start_mediaplayer_audio_ret, 0x44F6EFFC
    .equ menu_toplevel_browser_ret, 0x4505862E
    .equ listtext_toplevel_browser_ret, 0x4505871C
    .equ listicon_toplevel_browser_ret, 0x4505872E
    .equ list_tracks_number_ret, 0x4505909C
#elif defined(W800_R1BD001)
    .equ MEDIAPLAYERKEY_PRESSED_EVENT, 0x39
    .equ MP_BR_LISTNOWPLAYING_TXT, 0x99A

    .equ UI_Event, 0x4505B5E4
    .equ TextID_Create, 0x44EF41C4
    .equ DispObject_SetTitleText, 0x44E8BEB0
    .equ MediaPlayer_Audio_Rename, 0x44F5E398
    .equ MediaPlayer_SoftKeys_Validate, 0x44C7CDD0

    .equ mp_playqueue_setstyle_ret, 0x44E2CAB2
    .equ mp_nowplaying_setsize_ret, 0x44E2CD8C
    .equ mp_audio_setstyle_ret, 0x44E2C97C
    .equ mp_softkeys_minim_ret, 0x44F5D50C
    .equ mp_softkeys_ret1, 0x44F5D606
    .equ mp_softkeys_ret2, 0x44F5D612
    .equ audioplayer_onclose_func, 0x44F64380
    .equ audioplayer_onclose_ret, 0x44F5CDFC
    .equ start_mediaplayer_audio_ret, 0x44F67AE4
    .equ menu_toplevel_browser_ret, 0x450519FA
    .equ listtext_toplevel_browser_ret, 0x45051AE8
    .equ listicon_toplevel_browser_ret, 0x45051AFA
    .equ list_tracks_number_ret, 0x45052464
#elif defined(W810_R4EA031)
    .equ MEDIAPLAYERKEY_PRESSED_EVENT, 0x3B
    .equ MP_BR_LISTNOWPLAYING_TXT, 0xCC2

    .equ UI_Event, 0x4553127C
    .equ TextID_Create, 0x452FE69C
    .equ DispObject_SetTitleText, 0x45304A34
    .equ MediaPlayer_Audio_Rename, 0x454320B4
    .equ MediaPlayer_SoftKeys_Validate, 0x45074F90

    .equ mp_playqueue_setstyle_ret, 0x452560E6
    .equ mp_playqueue_settitle_ret, 0x45255EF4
    .equ mp_nowplaying_setsize_ret, 0x452562AA
    .equ mp_audio_setstyle_ret, 0x45256018
    .equ mp_softkeys_minim_ret, 0x454312C4
    .equ mp_softkeys_ret1, 0x454313BE
    .equ mp_softkeys_ret2, 0x454313CA
    .equ audioplayer_onclose_func, 0x454376D4
    .equ audioplayer_onclose_ret, 0x45430C42
    .equ start_mediaplayer_audio_ret, 0x4543AFB2
    .equ menu_toplevel_browser_ret, 0x4552F118
    .equ listtext_toplevel_browser_ret, 0x4552F1D4
    .equ listicon_toplevel_browser_ret, 0x4552F1E8
    .equ list_tracks_number_ret, 0x4552F904
#endif

.section .text.PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT
    .word New_UI_MEDIAPLAYER_NEW_TRACK_EVENT

.section .text.PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT
    .word New_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT

.section .text.PATCH_UI_MEDIAPLAYER_CREATED_EVENT
    .word New_UI_MEDIAPLAYER_CREATED_EVENT

.section .text.PATCH_MediaPlayer_Audio_OnCreate
    .word New_MediaPlayer_Audio_OnCreate

.section .text.PATCH_MediaPlayer_Audio_OnRedraw
    .word New_MediaPlayer_Audio_OnRedraw

.section .text.PATCH_MediaPlayer_NowPlaying_OnCreate
    .word New_MediaPlayer_NowPlaying_OnCreate

.section .text.PATCH_MediaPlayer_NowPlaying_OnRedraw
    .word New_MediaPlayer_NowPlaying_OnRedraw

.section .text.PATCH_SOUND_RUN
    .word New_Sound_Run_Enter

.section .text.PATCH_SOUND_RECORDER
    .word New_SoundRecorder_Playing

@ ==================== Other GUI=============================

.section .text.PATCH_MediaPlayer_Volume_SetPosition
.thumb
    nop
    mov     r2, #0
    mov     r1, #0
#if defined(W810_R4EA031)
    ldr     r0, [r4, #0x70]
#endif

.section .text.PATCH_MediaPlayer_ScrollText_SetSize
.thumb
    nop
    nop
    mov     r2, #0
    mov     r1, #0

@ ====================PlayQueue=============================

.section .text.PATCH_MediaPlayer_PlayQueue_RemoveStyle
.thumb
    b       rem_style
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
    nop
#if defined(W700_R1CA021) || defined(W800_R1BD001)
    nop
    nop
#endif
rem_style:

.section .text.PATCH_MediaPlayer_PlayQueue_SetStyle
.thumb
    ldr     r3, =mp_playqueue_setstyle+1
    bx      r3

#if defined(W810_R4EA031)
.section .text.PATCH_MediaPlayer_PlayQueue_SetTitle
.thumb
    ldr     r3, =mp_playqueue_settitle+1
    bx      r3
#endif

@ ====================NowPlaying=============================

.section .text.PATCH_MediaPlayer_NowPlaying_SetSize
.thumb
    ldr     r3, =mp_nowplaying_setsize+1
    bx      r3

.section .text.PATCH_GUI_PLAYMODE
.thumb
    mov     r1, #9

@ ==================== SoftKeys Action===========================

.section .text.PATCH_MediaPlayer_SoftKeys_Minimize
.thumb
    ldr     r3, =mp_softkeys_minim+1
    bx      r3

.section .text.PATCH_MediaPlayer_SoftKeys
.thumb
    ldr     r3, =mp_softkeys+1
    bx      r3

@ ======================OnClose Book=============================

.section .text.PATCH_AudioPlayerBook_onClose
.thumb
    ldr     r3, =audioplayer_onclose+1
    bx      r3

@ ==================== Dynamic Menu=============================

.section .text.PATCH_MEDIAPLAYER_MENU
.thumb
    ldr     r3, =start_mediaplayer_audio+1
    bx      r3

@ ====================TopLevel Parts=============================

.section .text.PATCH_Toplevel_Bk_NowPlaying_PreviousEvent
    .word New_Toplevel_Bk_NowPlaying_PreviousEvent

.section .text.PATCH_GUI_TOPLEVEL_ACTION_BACK
    .word New_MainMenu_TopLevelBrowser_ActionBack

.section .text.PATCH_GUI_TOPLEVEL_STYLE
.thumb
    bx      lr

#if defined(W810_R4EA031)
.section .text.PATCH_GUI_MM_PLAYLIST
.thumb
    nop
#endif

.section .text.PATCH_GUI_MM_ARTIST
.thumb
    nop
    nop
    nop
    nop

.section .text.PATCH_GUI_MM_ALBUM
.thumb
    nop
    nop
    nop
#if defined(W700_R1CA021) || defined(W800_R1BD001)
    nop
#endif

.section .text.PATCH_GUI_MM_TRACKS1
.thumb
    nop
    nop
    nop
    nop

.section .text.PATCH_GUI_MM_BROWSER_LISTLINK
.thumb
    ldr     r3, =New_ListLink_TopLevelBrowser+1
    bx      r3

.section .text.PATCH_GUI_MM_BROWSER_STYLE
.thumb
    ldr     r3, =menu_toplevel_browser+1
    bx      r3

.section .text.PATCH_GUI_MM_BROWSER_LISTCOUNT
.thumb
#if defined(W700_R1CA021) || defined(W800_R1BD001)
    nop
#endif
    nop
    mov     r0, #6

.section .text.PATCH_GUI_MM_BROWSER_LISTTEXT
.thumb
    ldr     r3, =listtext_toplevel_browser+1
    bx      r3

.section .text.PATCH_GUI_MM_BROWSER_LISTICON
.thumb
    ldr     r3, =listicon_toplevel_browser+1
    bx      r3

.section .text.PATCH_GUI_MM_TRACKS2
.thumb
    ldr     r3, =list_tracks_number+1
    bx      r3

.section .text.patch_section
.thumb
mp_playqueue_setstyle:
    ldr     r0, [r4, #0x68]
    bl      New_MediaPlayer_PlayQueue_SetStyle
    ldr     r3, =mp_playqueue_setstyle_ret+1
    bx      r3

.align 2

#if defined(W810_R4EA031)
mp_playqueue_settitle:
    ldr     r1, =MP_BR_LISTNOWPLAYING_TXT
    ldr     r3, =DispObject_SetTitleText+1
    blx     r3
    ldr     r0, [r5, #0]
    bl      New_MediaPlayer_PlayQueue_SetTitle
    ldr     r0, [r5, #0]
    ldr     r3, =mp_playqueue_settitle_ret+1
    bx      r3

.align 2
#endif

mp_nowplaying_setsize:
    ldr     r0, [r4, #0x74]
    bl      New_MediaPlayer_NowPlaying_SetSize
    ldr     r3, =mp_nowplaying_setsize_ret+1
    bx      r3

@ .align 2

@ mp_audio_setstyle:
@     add     r0, r4, #0
@     bl      New_MediaPlayer_Audio_SetStyle
@     ldr     r3, =mp_audio_setstyle_ret+1
@     bx      r3

.align 2

mp_softkeys_minim:
    mov     r0, r4
    bl      New_MediaPlayer_SoftKeys_MyMusic
    ldr     r3, =mp_softkeys_minim_ret+1
    bx      r3

.align 2

mp_softkeys:
    mov     r0, r4
    bl      New_MediaPlayer_SoftKeys
    ldr     r5, =MediaPlayer_Audio_Rename+1
    ldr     r0, [r4, #0x1C]
    ldr     r3, =MediaPlayer_SoftKeys_Validate+1
    blx     r3
    cmp     r0, #0
    beq     not_valid_exit
    ldr     r3, =mp_softkeys_ret1+1
    bx      r3
not_valid_exit:
    ldr     r3, =mp_softkeys_ret2+1
    bx      r3

.align 2

audioplayer_onclose:
    bl      New_AudioPlayerBook_onClose
    ldr     r0, [sp, #0]
    ldr     r3, =audioplayer_onclose_func+1
    blx     r3
    ldr     r1, [r4, #0x18]
    ldr     r3, =audioplayer_onclose_ret+1
    bx      r3

.align 2

start_mediaplayer_audio:
    bne     next_
    mov     r0, #MEDIAPLAYERKEY_PRESSED_EVENT
    ldr     r3, =UI_Event+1
    blx     r3
    pop     {r4, r5, pc}
next_:
    ldr     r3, =start_mediaplayer_audio_ret+1
    bx      r3

.align 2

menu_toplevel_browser:
#if defined(W700_R1CA021) || defined(W800_R1BD001)
    ldr     r0, [r4, #0x18]
#endif
    bl      New_MainMenu_TopLevelBrowser
    ldr     r3, =menu_toplevel_browser_ret+1
    bx      r3

.align 2

listtext_toplevel_browser:
#if defined(W810_R4EA031)
    add     r0, r6, #0
    bl      New_ListText_TopLevelBrowser
    add     r1, r0, #0
#else
    bl      New_ListText_TopLevelBrowser
    add     r1, r0, #0
    add     r0, r4, #0
#endif
    ldr     r3, =listtext_toplevel_browser_ret+1
    bx      r3

.align 2

listicon_toplevel_browser:
#if defined(W700_R1CA021) || defined(W800_R1BD001)
    add     r0, r5, #0
#endif
    bl      New_ListIcon_TopLevelBrowser
    add     r2, r0, #0
    ldr     r3, =listicon_toplevel_browser_ret+1
    bx      r3

.align 2
list_tracks_number:
#if defined(W810_R4EA031)
    ldr     r3, =TextID_Create+1
    blx     r3
    add     r1, r4, #0
    bl      New_ListText_Track
    add     r1, r0, #0
    add     r0, r4, #0
#else
    mov     r1, #0
    ldr     r3, =TextID_Create+1
    blx     r3
    ldr     r1, [sp, #0xC]
    bl      New_ListText_Track
    add     r1, r0, #0
#endif
    ldr     r3, =list_tracks_number_ret+1
    bx      r3
