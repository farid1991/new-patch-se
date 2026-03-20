/* Sections placement */
SECTIONS
{
    .text.patch_MediaPlayer_SingleFile_Exit 0x44501C7C  :
    {
        KEEP(*(.text.patch_MediaPlayer_SingleFile_Exit))
    }
    .text.patch_MediaPlayer_SingleFile_Enter 0x44501C64 :
    {
        KEEP(*(.text.patch_MediaPlayer_SingleFile_Enter))
    }
    .text.patch_BookObj_SetFocus 0x4529F994 :
    {
        KEEP(*(.text.patch_BookObj_SetFocus))
    }
    .text.patch_MediaPlayer_SoftKeys 0x45432204 :
    {
        KEEP(*(.text.patch_MediaPlayer_SoftKeys))
    }
    .text.patch_DataBrowser_SoftKeys 0x45247BD0 :
    {
        KEEP(*(.text.patch_DataBrowser_SoftKeys))
    }

    .text.patch_section 0x456D6300 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
