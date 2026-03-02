/* Sections placement */
SECTIONS
{
    .timer_set_hook 0x1412D096 :
    {
        KEEP(*(.text.timer_set_hook))
    }
    .timer_kill_hook 0x142F11D8 :
    {
        KEEP(*(.text.timer_kill_hook))
    }
    .redraw_hook 0x14295978 :
    {
        KEEP(*(.text.redraw_hook))
    }

    .patch_section 0x15D18600 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
