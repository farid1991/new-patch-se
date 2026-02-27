/* Sections placement */
SECTIONS
{
    .brw_jpg_hook 0x14EA155C :
    {
        KEEP(*(.text.brw_jpg_hook))
    }

    .patch_section 0x15D18600 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
