/* Sections placement */
SECTIONS
{
    .timer_set_hook 0x10984A20 :
    {
        KEEP(*(.text.timer_set_hook))
    }
    .timer_kill_hook 0x10984ACC :
    {
        KEEP(*(.text.timer_kill_hook))
    }
    .redraw_hook 0x10985120 :
    {
        KEEP(*(.text.redraw_hook))
    }

    .patch_section 0x1281A990 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
