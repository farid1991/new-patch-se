/* Sections placement */
SECTIONS
{
    .StatusRow_OnRedraw 0x1480DEE8 :
    {
        KEEP(*(.text.StatusRow_OnRedraw))
    }
    .ObEx_ReceiveFile 0x15605B64 :
    {
        KEEP(*(.text.ObEx_ReceiveFile))
    }
    .ObEx_SendFile 0x15605D40 :
    {
        KEEP(*(.text.ObEx_SendFile))
    }
    .ObEx_SendMultipleFiles 0x15605D78 :
    {
        KEEP(*(.text.ObEx_SendMultipleFiles))
    }
    .ObEx_FileSent 0x15605DC0 :
    {
        KEEP(*(.text.ObEx_FileSent))
    }
    .pg_ObEx_FileSent 0x146BDCE0 :
    {
        KEEP(*(.text.pg_ObEx_FileSent))
    }
    .pg_ObEx_FileSentFailed 0x14D07638 :
    {
        KEEP(*(.text.pg_ObEx_FileSentFailed))
    }

    .patch_section 0x15D63300 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
