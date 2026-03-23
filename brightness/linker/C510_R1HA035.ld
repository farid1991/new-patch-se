/* Sections placement */
SECTIONS
{
    .text.patch_ChangeBrightness_Enter 0x15A31634 :
    {
        KEEP(*(.text.patch_ChangeBrightness_Enter))
    }
    .text.patch_ChangeBrightness_Exit 0x15A3163C :
    {
        KEEP(*(.text.patch_ChangeBrightness_Exit))
    }
    .text.patch_fix_secondline 0x141ADF96 :
    {
        KEEP(*(.text.patch_fix_secondline))
    }
    .text.patch_brightness_1 0x1546E4F2 :
    {
        KEEP(*(.text.patch_brightness_1))
    }
    .text.patch_brightness_2 0x1546E4F6 :
    {
        KEEP(*(.text.patch_brightness_2))
    }

    .text.patch_section 0x12791F00 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
