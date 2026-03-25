/* Sections placement */
SECTIONS
{
    .text.PATCH_SOUND_RECORDER 0x4424423C :
    {
        KEEP(*(.text.PATCH_SOUND_RECORDER))
    }
    .text.PATCH_SOUND_RUN 0x44230A24 :
    {
        KEEP(*(.text.PATCH_SOUND_RUN))
    }

    .text.PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT 0x44241E88 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT))
    }

    .text.PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT 0x44241E90 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT))
    }

    .text.PATCH_UI_MEDIAPLAYER_CREATED_EVENT 0x44241EF0 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_CREATED_EVENT))
    }

    .text.PATCH_MediaPlayer_Audio_SetStyle 0x44E32B04 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_SetStyle))
    }

    .text.PATCH_MediaPlayer_Audio_OnCreate 0x44E3367C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnCreate))
    }

    .text.PATCH_MediaPlayer_Audio_OnClose 0x44E33680 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnClose))
    }

    .text.PATCH_MediaPlayer_Audio_OnRedraw 0x44E33684 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnRedraw))
    }

    .text.PATCH_MediaPlayer_PlayQueue_SetTitle 0x44E329CC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetTitle))
    }

    .text.PATCH_MediaPlayer_PlayQueue_SetStyle 0x44E32C30 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetStyle))
    }

    .text.PATCH_MediaPlayer_PlayQueue_RemoveStyle 0x44E32C60 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_RemoveStyle))
    }

    .text.PATCH_MediaPlayer_ScrollText_SetSize 0x44E32CC0 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_ScrollText_SetSize))
    }

    .text.PATCH_MediaPlayer_Volume_SetPosition 0x44E32E6C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Volume_SetPosition))
    }

    .text.PATCH_MediaPlayer_NowPlaying_SetSize 0x44E32F10 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_SetSize))
    }

    .text.PATCH_MediaPlayer_NowPlaying_OnCreate 0x44E3486C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnCreate))
    }

    .text.PATCH_MediaPlayer_NowPlaying_OnClose 0x44E34870 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnClose))
    }

    .text.PATCH_MediaPlayer_NowPlaying_OnRedraw 0x44E34874 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnRedraw))
    }

    .text.PATCH_MediaPlayer_SoftKeys 0x44F64B1C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys))
    }

    .text.PATCH_MediaPlayer_SoftKeys_Minimize 0x44F64990 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys_Minimize))
    }

    .text.PATCH_AudioPlayerBook_onClose 0x44F64318 :
    {
        KEEP(*(.text.PATCH_AudioPlayerBook_onClose))
    }

    .text.PATCH_SKIN_SELECTOR_TEXT1 0x44F64B90 :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_TEXT1))
    }

    .text.PATCH_SKIN_SELECTOR_TEXT2 0x44F64B9C :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_TEXT2))
    }

    .text.PATCH_SKIN_SELECTOR_LINK 0x44F64D78 :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_LINK))
    }

    .text.PATCH_Toplevel_Bk_NowPlaying_PreviousEvent 0x44287D34 :
    {
        KEEP(*(.text.PATCH_Toplevel_Bk_NowPlaying_PreviousEvent))
    }

    .text.PATCH_MEDIAPLAYER_MENU 0x44F6EFF4 :
    {
        KEEP(*(.text.PATCH_MEDIAPLAYER_MENU))
    }

    .text.PATCH_GUI_PLAYMODE 0x44F6978C :
    {
        KEEP(*(.text.PATCH_GUI_PLAYMODE))
    }

    .text.PATCH_GUI_TOPLEVEL_ACTION_BACK 0x45058244 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_ACTION_BACK))
    }

    .text.PATCH_GUI_TOPLEVEL_STYLE 0x45056018 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_STYLE))
    }

    .text.PATCH_GUI_MM_BROWSER_STYLE 0x45058620 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_STYLE))
    }

    .text.PATCH_GUI_MM_BROWSER_LISTCOUNT 0x45058600 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTCOUNT))
    }

    .text.PATCH_GUI_MM_BROWSER_LISTTEXT 0x45058714 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTTEXT))
    }

    .text.PATCH_GUI_MM_BROWSER_LISTICON 0x45058724 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTICON))
    }

    .text.PATCH_GUI_MM_BROWSER_LISTLINK 0x45058308 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTLINK))
    }

    .text.PATCH_GUI_MM_ARTIST 0x45054940 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ARTIST))
    }

    .text.PATCH_GUI_MM_ALBUM 0x45053820 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ALBUM))
    }

    .text.PATCH_GUI_MM_TRACKS1 0x450596A4 :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS1))
    }

    .text.PATCH_GUI_MM_TRACKS2 0x45059094 :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS2))
    }

    .text.patch_section 0x451ED000 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
