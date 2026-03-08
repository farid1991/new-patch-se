/* Sections placement */
SECTIONS
{
    .timer_set_hook 0x2027A618 :
    {
        KEEP(*(.text.timer_set_hook))
    }
    .timer_kill_hook 0x2027A6B8 :
    {
        KEEP(*(.text.timer_kill_hook))
    }
    .redraw_hook 0x2027AF34 :
    {
        KEEP(*(.text.redraw_hook))
    }

    .patch_section 0x21474000 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
