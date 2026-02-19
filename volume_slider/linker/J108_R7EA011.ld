/* Sections placement */
SECTIONS
{
    text.volume_hook 0x146DC770 :
    {
        KEEP(*(.text.volume_hook))
    }

    text.patch_section 0x15D624D0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}