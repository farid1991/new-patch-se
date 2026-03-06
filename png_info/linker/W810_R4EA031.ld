/* Sections placement */
SECTIONS
{
    .brw_png_hook 0x455C217C :
    {
        KEEP(*(.text.brw_png_hook))
    }

    .patch_section 0x457F2E60 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
