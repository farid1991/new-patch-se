SECTIONS
{
    .initbook_enter 0x2149430C :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x21570000 :
    {
        KEEP(*(.text.patch_section))
    }
}
