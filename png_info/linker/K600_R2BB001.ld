/* Sections placement */
SECTIONS
{
    .brw_png_hook 0x204EA450 :
    {
        KEEP(*(.text.brw_png_hook))
    }

    .patch_section 0x2147B420 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
