/* Sections placement */
SECTIONS
{
    .oncreate_hook 0x452A927C :
    {
        KEEP(*(.text.oncreate_hook))
    }
    .onredraw_hook 0x452A9284 :
    {
        KEEP(*(.text.onredraw_hook))
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
