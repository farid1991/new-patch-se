SECTIONS
{
    .initbook_enter 0x44564AE0 :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x456CF5C0 :
    {
        KEEP(*(.text.patch_section))
    }
}
