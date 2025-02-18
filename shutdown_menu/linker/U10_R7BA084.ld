/* Sections placement */
SECTIONS
{
    text.new_button 0x14593468 :
    {
        KEEP(*(.text.new_button))
    }

    text.patch_section 0x160F8000 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}