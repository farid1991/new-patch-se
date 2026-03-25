/* Sections placement */
SECTIONS
{
    .text.PATCH_SOUND_RECORDER 0x445038A0 :
    {
        KEEP(*(.text.PATCH_SOUND_RECORDER))
    }
    .text.PATCH_SOUND_RUN 0x444F1820 :
    {
        KEEP(*(.text.PATCH_SOUND_RUN))
    }

    .text.PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT 0x445015F0 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT))
    }
    .text.PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT 0x445015F8 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT))
    }
    .text.PATCH_UI_MEDIAPLAYER_CREATED_EVENT 0x44501658 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_CREATED_EVENT))
    }

    .text.PATCH_MediaPlayer_Audio_SetStyle 0x45256010 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_SetStyle))
    }

    .text.PATCH_MediaPlayer_Audio_OnCreate 0x452567FC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnCreate))
    }
    .text.PATCH_MediaPlayer_Audio_OnClose 0x45256800 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnClose))
    }
    .text.PATCH_MediaPlayer_Audio_OnRedraw 0x45256804 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnRedraw))
    }

    .text.PATCH_MediaPlayer_PlayQueue_SetTitle 0x45255EEC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetTitle))
    }
    .text.PATCH_MediaPlayer_PlayQueue_SetStyle 0x452560DC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetStyle))
    }
    .text.PATCH_MediaPlayer_PlayQueue_RemoveStyle 0x45256104 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_RemoveStyle))
    }
    .text.PATCH_MediaPlayer_ScrollText_SetSize 0x45256164 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_ScrollText_SetSize))
    }
    .text.PATCH_MediaPlayer_Volume_SetPosition 0x4525620C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Volume_SetPosition))
    }
    .text.PATCH_MediaPlayer_NowPlaying_SetSize 0x4525629C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_SetSize))
    }

    .text.PATCH_MediaPlayer_NowPlaying_OnCreate 0x45257510 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnCreate))
    }
    .text.PATCH_MediaPlayer_NowPlaying_OnClose 0x45257514 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnClose))
    }
    .text.PATCH_MediaPlayer_NowPlaying_OnRedraw 0x45257518 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnRedraw))
    }

    .text.PATCH_AudioPlayerBook_onClose 0x45430C38 :
    {
        KEEP(*(.text.PATCH_AudioPlayerBook_onClose))
    }
    .text.PATCH_MediaPlayer_SoftKeys 0x454313B4 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys))
    }
    .text.PATCH_MediaPlayer_SoftKeys_Minimize 0x45431228 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys_Minimize))
    }

    .text.PATCH_SKIN_SELECTOR_TEXT 0x45431418 :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_TEXT))
    }
    .text.PATCH_SKIN_SELECTOR_LINK 0x45431610 :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_LINK))
    }
    .text.PATCH_GUI_PLAYMODE 0x4543590E :
    {
        KEEP(*(.text.PATCH_GUI_PLAYMODE))
    }

    .text.PATCH_Toplevel_Bk_NowPlaying_PreviousEvent 0x445485FC :
    {
        KEEP(*(.text.PATCH_Toplevel_Bk_NowPlaying_PreviousEvent))
    }
    .text.PATCH_MEDIAPLAYER_MENU 0x4543AFA8 :
    {
        KEEP(*(.text.PATCH_MEDIAPLAYER_MENU))
    }

    .text.PATCH_GUI_TOPLEVEL_STYLE 0x4552D214 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_STYLE))
    }
    .text.PATCH_GUI_TOPLEVEL_ACTION_BACK 0x4552EE48 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_ACTION_BACK))
    }
    .text.PATCH_GUI_MM_BROWSER_STYLE 0x4552F10C :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_STYLE))
    }
    .text.PATCH_GUI_MM_BROWSER_LISTCOUNT 0x4552F0EC :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTCOUNT))
    }
    .text.PATCH_GUI_MM_BROWSER_LISTTEXT 0x4552F1CC :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTTEXT))
    }
    .text.PATCH_GUI_MM_BROWSER_LISTICON 0x4552F1E0 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTICON))
    }
    .text.PATCH_GUI_MM_BROWSER_LISTLINK 0x4552EEB8 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTLINK))
    }
    .text.PATCH_GUI_MM_ARTIST 0x4552BE38 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ARTIST))
    }
    .text.PATCH_GUI_MM_ALBUM 0x4552AE40 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ALBUM))
    }
    .text.PATCH_GUI_MM_TRACKS1 0x4552FDB0 :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS1))
    }
    .text.PATCH_GUI_MM_TRACKS2 0x4552F8FC :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS2))
    }
    .text.PATCH_GUI_MM_PLAYLIST 0x4552DFE4 :
    {
        KEEP(*(.text.PATCH_GUI_MM_PLAYLIST))
    }

    .text.patch_section 0x457AF5D0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
