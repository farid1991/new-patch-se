SECTIONS
{
    .initbook_enter 0x15D0D050 :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x162CC550 :
    {
        KEEP(*(.text.patch_section))
    }
}
