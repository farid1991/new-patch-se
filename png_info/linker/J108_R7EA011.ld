/* Sections placement */
SECTIONS
{
    .brw_png_hook 0x1529F3D4 :
    {
        KEEP(*(.text.brw_png_hook))
    }

    .patch_section 0x15D65220 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
