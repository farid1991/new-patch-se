/* Sections placement */
SECTIONS
{
    text.new_button 0x142E0BDC :
    {
        KEEP(*(.text.new_button))
    }

    text.patch_section 0x15D62250 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}