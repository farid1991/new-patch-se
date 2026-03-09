/* Sections placement */
SECTIONS
{
    .dispdesc_hook 0x11B49AF0 :
    {
        KEEP(*(.text.dispdesc_hook))
    }

    .on_enter_hook 0x11FAEB7C :
    {
        KEEP(*(.text.on_enter_hook))
    }

    .patch_section 0x1281C410 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
