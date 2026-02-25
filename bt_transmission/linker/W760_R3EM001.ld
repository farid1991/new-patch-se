/* Sections placement */
SECTIONS
{
    .StatusRow_OnRedraw 0x11804054 :
    {
        KEEP(*(.text.StatusRow_OnRedraw))
    }
    .ObEx_ReceiveFile 0x11B9B3B4 :
    {
        KEEP(*(.text.ObEx_ReceiveFile))
    }
    .ObEx_SendFile 0x11B9B6F0 :
    {
        KEEP(*(.text.ObEx_SendFile))
    }
    .ObEx_SendMultipleFiles 0x11B9B728 :
    {
        KEEP(*(.text.ObEx_SendMultipleFiles))
    }
    .ObEx_FileSent 0x11B9B77C :
    {
        KEEP(*(.text.ObEx_FileSent))
    }
    .pg_ObEx_FileSent 0x109417C0 :
    {
        KEEP(*(.text.pg_ObEx_FileSent))
    }
    .pg_ObEx_FileSentFailed 0x10941856 :
    {
        KEEP(*(.text.pg_ObEx_FileSentFailed))
    }

    .patch_section 0x12818720 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
