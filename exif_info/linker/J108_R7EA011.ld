/* Sections placement */
SECTIONS
{
    .brw_jpg_hook 0x1529EFF4 :
    {
        KEEP(*(.text.brw_jpg_hook))
    }

    .patch_section 0x15D636A0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
