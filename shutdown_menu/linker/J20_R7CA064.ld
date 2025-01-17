/* Sections placement */
SECTIONS
{
    text.new_button 0x142EA058 :
    {
        KEEP(*(.text.new_button))
    }

    text.patch_section 0x15F60000 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}