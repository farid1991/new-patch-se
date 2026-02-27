/* Sections placement */
SECTIONS
{
    .brw_jpg_hook 0x11878C54 :
    {
        KEEP(*(.text.brw_jpg_hook))
    }

    .patch_section 0x128188A0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
