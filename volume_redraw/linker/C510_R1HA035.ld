/* Sections placement */
SECTIONS
{
    .oncreate_hook 0x14ED7504 :
    {
        KEEP(*(.text.oncreate_hook))
    }
    .onredraw_hook 0x14ED750C :
    {
        KEEP(*(.text.onredraw_hook))
    }

    .on_enter_hook 0x15C3A608 :
    {
        KEEP(*(.text.on_enter_hook))
    }

    .patch_section 0x15D3B3D0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
