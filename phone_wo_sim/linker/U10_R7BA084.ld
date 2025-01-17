SECTIONS
{
    .initbook_enter 0x15C32530 :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x161EE700  :
    {
        KEEP(*(.text.patch_section))
    }
}
