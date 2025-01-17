/* Sections placement */
SECTIONS
{
    .alarmlist 0x1412D220 :
    {
        KEEP(*(.text.alarmlist))
    }

    .alarmstandby 0x145E7F44 :
    {
        KEEP(*(.text.alarmstandby))
    }

    .patch_section 0x162BCE40 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
