/* Sections placement */
SECTIONS
{
    .PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT 0x44241E88 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT))
    }

    .PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT 0x44241E90 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT))
    }

    .PATCH_UI_MEDIAPLAYER_CREATED_EVENT 0x44241EF0 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_CREATED_EVENT))
    }

    .PATCH_MediaPlayer_Audio_SetStyle 0x44E32B04 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_SetStyle))
    }

    .PATCH_MediaPlayer_Audio_OnCreate 0x44E3367C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnCreate))
    }

    .PATCH_MediaPlayer_Audio_OnClose 0x44E33680 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnClose))
    }

    .PATCH_MediaPlayer_Audio_OnRedraw 0x44E33684 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnRedraw))
    }

    .PATCH_MediaPlayer_PlayQueue_SetTitle 0x44E329CC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetTitle))
    }

    .PATCH_MediaPlayer_PlayQueue_SetStyle 0x44E32C30 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetStyle))
    }

    .PATCH_MediaPlayer_PlayQueue_RemoveStyle 0x44E32C60 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_RemoveStyle))
    }

    .PATCH_MediaPlayer_ScrollText_SetSize 0x44E32CC0 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_ScrollText_SetSize))
    }

    .PATCH_MediaPlayer_Volume_SetPosition 0x44E32E6C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Volume_SetPosition))
    }

    .PATCH_MediaPlayer_NowPlaying_SetSize 0x44E32F10 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_SetSize))
    }

    .PATCH_MediaPlayer_NowPlaying_OnCreate 0x44E3486C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnCreate))
    }

    .PATCH_MediaPlayer_NowPlaying_OnClose 0x44E34870 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnClose))
    }

    .PATCH_MediaPlayer_NowPlaying_OnRedraw 0x44E34874 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnRedraw))
    }

    .PATCH_MediaPlayer_SoftKeys 0x44F64B1C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys))
    }

    .PATCH_MediaPlayer_SoftKeys_Minimize 0x44F64990 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys_Minimize))
    }

    .PATCH_AudioPlayerBook_onClose 0x44F64318 :
    {
        KEEP(*(.text.PATCH_AudioPlayerBook_onClose))
    }

    .PATCH_SKIN_SELECTOR_TEXT1 0x44F64B90 :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_TEXT1))
    }

    .PATCH_SKIN_SELECTOR_TEXT2 0x44F64B9C :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_TEXT2))
    }

    .PATCH_SKIN_SELECTOR_LINK 0x44F64D78 :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_LINK))
    }

    .PATCH_Toplevel_Bk_NowPlaying_PreviousEvent 0x44287D34 :
    {
        KEEP(*(.text.PATCH_Toplevel_Bk_NowPlaying_PreviousEvent))
    }

    .PATCH_MEDIAPLAYER_MENU 0x44F6EFF4 :
    {
        KEEP(*(.text.PATCH_MEDIAPLAYER_MENU))
    }

    .PATCH_GUI_PLAYMODE 0x44F6978C :
    {
        KEEP(*(.text.PATCH_GUI_PLAYMODE))
    }

    .PATCH_GUI_TOPLEVEL_ACTION_BACK 0x45058244 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_ACTION_BACK))
    }

    .PATCH_GUI_TOPLEVEL_STYLE 0x45056018 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_STYLE))
    }

    .PATCH_GUI_MM_BROWSER_STYLE 0x45058620 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_STYLE))
    }

    .PATCH_GUI_MM_BROWSER_LISTCOUNT 0x45058600 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTCOUNT))
    }

    .PATCH_GUI_MM_BROWSER_LISTTEXT 0x45058714 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTTEXT))
    }

    .PATCH_GUI_MM_BROWSER_LISTICON 0x45058724 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTICON))
    }

    .PATCH_GUI_MM_BROWSER_LISTLINK 0x45058308 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTLINK))
    }

    .PATCH_GUI_MM_ARTIST 0x45054940 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ARTIST))
    }

    .PATCH_GUI_MM_ALBUM 0x45053820 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ALBUM))
    }

    .PATCH_GUI_MM_TRACKS1 0x450596A4 :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS1))
    }

    .PATCH_GUI_MM_TRACKS2 0x45059094 :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS2))
    }

    .patch_section 0x451ED000 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
