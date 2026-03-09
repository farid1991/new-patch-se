/* Sections placement */
SECTIONS
{
    .oncreate_hook 0x11B49AF0 :
    {
        KEEP(*(.text.oncreate_hook))
    }
    .onredraw_hook 0x11B49AF8 :
    {
        KEEP(*(.text.onredraw_hook))
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
