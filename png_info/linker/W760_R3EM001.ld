/* Sections placement */
SECTIONS
{
    .brw_png_hook 0x1187907C :
    {
        KEEP(*(.text.brw_png_hook))
    }

    .patch_section 0x1281A420 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
