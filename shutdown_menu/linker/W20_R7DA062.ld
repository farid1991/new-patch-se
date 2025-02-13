/* Sections placement */
SECTIONS
{
    text.new_button 0x142E23A0 :
    {
        KEEP(*(.text.new_button))
    }

    text.patch_section 0x15CF0000 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}