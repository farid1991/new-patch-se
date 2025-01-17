/* Sections placement */
SECTIONS
{
    text.new_button 0x14598710 :
    {
        KEEP(*(.text.new_button))
    }

    text.patch_section 0x162CC5A0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}