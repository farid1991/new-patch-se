/* Sections placement */
SECTIONS
{
    .secondline_hook_fix 0x11875992 :
    {
        KEEP(*(.text.secondline_hook_fix))
    }
    .secondline_hook 0x11875994 :
    {
        KEEP(*(.text.secondline_hook))
    }

    .patch_section 0x1281AD70 :
    {
        KEEP(*(.text.patch_section))
    }
}
