SECTIONS
{
    .initbook_enter 0x11F66AEC :
    {
        KEEP(*(.text.initbook_enter))
    }

    .patch_section 0x12817A40 :
    {
        KEEP(*(.text.patch_section))
    }
}
