SECTIONS
{
    .initbook_enter 0x444C2E9C :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x457009B0 :
    {
        KEEP(*(.text.patch_section))
    }
}
