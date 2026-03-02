/* Sections placement */
SECTIONS
{
    .timer_set_hook 0x144CF06C :
    {
        KEEP(*(.text.timer_set_hook))
    }
    .timer_kill_hook 0x141E007C :
    {
        KEEP(*(.text.timer_kill_hook))
    }
    .redraw_hook 0x1448DA98 :
    {
        KEEP(*(.text.redraw_hook))
    }

    .patch_section 0x15D65790 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
