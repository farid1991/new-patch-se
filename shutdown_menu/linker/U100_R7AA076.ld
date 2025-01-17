/* Sections placement */
SECTIONS
{
    text.new_button 0x14579580 :
    {
        KEEP(*(.text.new_button))
    }

    text.patch_section 0x16026000 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}