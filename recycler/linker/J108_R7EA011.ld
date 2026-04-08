/* Sections placement */
SECTIONS
{
    .text.patch_Generic_Delete 0x1495DD34 :
    {
        KEEP(*(.text.patch_Generic_Delete))
    }
    .text.patch_Mark_Delete 0x147713F4 :
    {
        KEEP(*(.text.patch_Mark_Delete))
    }
    .text.patch_Directory_Delete 0x149DC938 :
    {
        KEEP(*(.text.patch_Directory_Delete))
    }
    .text.patch_FileDelete 0x1447AAC4 :
    {
        KEEP(*(.text.patch_FileDelete))
    }

    .text.patch_section 0x15D6D290 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
