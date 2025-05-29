SECTIONS
{
    .initbook_enter 0x11E70A14 :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x125C9000 :
    {
        KEEP(*(.text.patch_section))
    }
}
