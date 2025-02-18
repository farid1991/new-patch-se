/* Sections placement */
SECTIONS
{
    text.new_button 0x142EA048 :
    {
        KEEP(*(.text.new_button))
    }

    text.patch_section 0x15EB8E80 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}