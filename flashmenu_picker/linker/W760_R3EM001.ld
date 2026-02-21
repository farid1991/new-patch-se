/* Sections placement */
SECTIONS
{
    .softkeys_hook 0x10E76548 :
    {
        KEEP(*(.text.softkeys_hook))
    }

    .patch_section 0x12817A90 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
