/* Sections placement */
SECTIONS
{
    .softkeys_hook 0x14CE0CEC :
    {
        KEEP(*(.text.softkeys_hook))
    }

    .patch_section 0x15DD9890 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
