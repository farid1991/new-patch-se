/* Sections placement */
SECTIONS
{
    .PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT 0x442416D8 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_AUDIO_PLAYING_TIME_EVENT))
    }

    .PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT 0x442416E0 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_NEW_TRACK_EVENT))
    }

    .PATCH_UI_MEDIAPLAYER_CREATED_EVENT 0x44241740 :
    {
        KEEP(*(.text.PATCH_UI_MEDIAPLAYER_CREATED_EVENT))
    }

    .PATCH_MediaPlayer_Audio_SetStyle 0x44E2C974 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_SetStyle))
    }

    .PATCH_MediaPlayer_Audio_OnCreate 0x44E2D4EC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnCreate))
    }

    .PATCH_MediaPlayer_Audio_OnClose 0x44E2D4F0 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnClose))
    }

    .PATCH_MediaPlayer_Audio_OnRedraw 0x44E2D4F4 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Audio_OnRedraw))
    }

    .PATCH_MediaPlayer_PlayQueue_SetTitle 0x44E2C83C :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetTitle))
    }

    .PATCH_MediaPlayer_PlayQueue_SetStyle 0x44E2CAA0 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_SetStyle))
    }

    .PATCH_MediaPlayer_PlayQueue_RemoveStyle 0x44E2CAD0 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_PlayQueue_RemoveStyle))
    }

    .PATCH_MediaPlayer_ScrollText_SetSize 0x44E2CB30 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_ScrollText_SetSize))
    }

    .PATCH_MediaPlayer_Volume_SetPosition 0x44E2CCDC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_Volume_SetPosition))
    }

    .PATCH_MediaPlayer_NowPlaying_SetSize 0x44E2CD80 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_SetSize))
    }

    .PATCH_MediaPlayer_NowPlaying_OnCreate 0x44E2E6DC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnCreate))
    }

    .PATCH_MediaPlayer_NowPlaying_OnClose 0x44E2E6E0 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnClose))
    }

    .PATCH_MediaPlayer_NowPlaying_OnRedraw 0x44E2E6E4 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_NowPlaying_OnRedraw))
    }

    .PATCH_MediaPlayer_SoftKeys 0x44F5D5FC :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys))
    }

    .PATCH_MediaPlayer_SoftKeys_Minimize 0x44F5D468 :
    {
        KEEP(*(.text.PATCH_MediaPlayer_SoftKeys_Minimize))
    }

    .PATCH_AudioPlayerBook_onClose 0x44F5CDF4 :
    {
        KEEP(*(.text.PATCH_AudioPlayerBook_onClose))
    }

    .PATCH_SKIN_SELECTOR_TEXT1 0x44F5D66C :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_TEXT1))
    }

    .PATCH_SKIN_SELECTOR_TEXT2 0x44F5D678 :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_TEXT2))
    }

    .PATCH_SKIN_SELECTOR_LINK 0x44F5D85C :
    {
        KEEP(*(.text.PATCH_SKIN_SELECTOR_LINK))
    }

    .PATCH_Toplevel_Bk_NowPlaying_PreviousEvent 0x442876B0 :
    {
        KEEP(*(.text.PATCH_Toplevel_Bk_NowPlaying_PreviousEvent))
    }

    .PATCH_MEDIAPLAYER_MENU 0x44F67ADC :
    {
        KEEP(*(.text.PATCH_MEDIAPLAYER_MENU))
    }

    .PATCH_GUI_PLAYMODE 0x44F62278 :
    {
        KEEP(*(.text.PATCH_GUI_PLAYMODE))
    }

    .PATCH_GUI_TOPLEVEL_ACTION_BACK 0x45051610 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_ACTION_BACK))
    }

    .PATCH_GUI_TOPLEVEL_STYLE 0x4504F3F0 :
    {
        KEEP(*(.text.PATCH_GUI_TOPLEVEL_STYLE))
    }

    .PATCH_GUI_MM_BROWSER_STYLE 0x450519EC :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_STYLE))
    }

    .PATCH_GUI_MM_BROWSER_LISTCOUNT 0x450519CC :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTCOUNT))
    }

    .PATCH_GUI_MM_BROWSER_LISTTEXT 0x45051AE0 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTTEXT))
    }

    .PATCH_GUI_MM_BROWSER_LISTICON 0x45051AF0 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTICON))
    }

    .PATCH_GUI_MM_BROWSER_LISTLINK 0x450516D4 :
    {
        KEEP(*(.text.PATCH_GUI_MM_BROWSER_LISTLINK))
    }

    .PATCH_GUI_MM_ARTIST 0x4504DD18 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ARTIST))
    }

    .PATCH_GUI_MM_ALBUM 0x4504CBF8 :
    {
        KEEP(*(.text.PATCH_GUI_MM_ALBUM))
    }

    .PATCH_GUI_MM_TRACKS1 0x45052A6C :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS1))
    }

    .PATCH_GUI_MM_TRACKS2 0x4505245C :
    {
        KEEP(*(.text.PATCH_GUI_MM_TRACKS2))
    }

    .patch_section 0x45204100 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
