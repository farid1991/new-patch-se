/* Sections placement */
SECTIONS
{
    .alarmlist 0x14129440 :
    {
        KEEP(*(.text.alarmlist))
    }

    .alarmstandby 0x145C7E5C :
    {
        KEEP(*(.text.alarmstandby))
    }

    .patch_section 0x1602F3B0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
