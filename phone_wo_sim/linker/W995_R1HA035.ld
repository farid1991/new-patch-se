SECTIONS
{
    .initbook_enter 0x15D148EC :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x15E71DD0 :
    {
        KEEP(*(.text.patch_section))
    }
}
