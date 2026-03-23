/* Sections placement */
SECTIONS
{
    .text.patch_ChangeBrightness_Enter 0x11C512B8 :
    {
        KEEP(*(.text.patch_ChangeBrightness_Enter))
    }
    .text.patch_ChangeBrightness_Exit 0x11C512C0 :
    {
        KEEP(*(.text.patch_ChangeBrightness_Exit))
    }
    .text.patch_fix_secondline 0x10E5A67C :
    {
        KEEP(*(.text.patch_fix_secondline))
    }
    .text.patch_brightness_1 0x10EFE5EA :
    {
        KEEP(*(.text.patch_brightness_1))
    }
    .text.patch_brightness_2 0x10EFE5EE :
    {
        KEEP(*(.text.patch_brightness_2))
    }

    .text.patch_section 0x12791F00 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
