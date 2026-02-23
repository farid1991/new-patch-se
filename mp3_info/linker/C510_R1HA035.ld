/* Sections placement */
SECTIONS
{
    .brw_mp3_hook 0x1574AF70 :
    {
        KEEP(*(.text.brw_mp3_hook))
    }

    .patch_section 0x15D1A200 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
