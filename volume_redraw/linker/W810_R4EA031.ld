/* Sections placement */
SECTIONS
{
    .dispdesc_hook 0x452A927C :
    {
        KEEP(*(.text.dispdesc_hook))
    }

    .on_enter_hook 0x445647A4 :
    {
        KEEP(*(.text.on_enter_hook))
    }

    .patch_section 0x457AE960 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
