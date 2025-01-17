SECTIONS
{
    .initbook_enter 0x15BEFE54 :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x15D0B090 :
    {
        KEEP(*(.text.patch_section))
    }
}
