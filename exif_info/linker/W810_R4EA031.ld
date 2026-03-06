/* Sections placement */
SECTIONS
{
    .brw_jpg_hook 0x455C1E08 :
    {
        KEEP(*(.text.brw_jpg_hook))
    }

    .patch_section 0x457F1300 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
