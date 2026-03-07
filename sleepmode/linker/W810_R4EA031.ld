/* Sections placement */
SECTIONS
{
    .timer_set_hook 0x452AB328 :
    {
        KEEP(*(.text.timer_set_hook))
    }
    .timer_kill_hook 0x452AB3C8 :
    {
        KEEP(*(.text.timer_kill_hook))
    }
    .redraw_hook 0x452ABC30 :
    {
        KEEP(*(.text.redraw_hook))
    }

    .patch_section 0x456D93E0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
