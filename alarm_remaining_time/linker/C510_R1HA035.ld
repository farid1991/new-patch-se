/* Sections placement */
SECTIONS
{
    .alarmlist 0x1517A6E4 :
    {
        KEEP(*(.text.alarmlist))
    }

    .alarmstandby 0x141ACA2C :
    {
        KEEP(*(.text.alarmstandby))
    }

    .patch_section 0x15D85B50 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
