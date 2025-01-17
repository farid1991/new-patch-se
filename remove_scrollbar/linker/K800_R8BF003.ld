/* Sections placement */
SECTIONS
{
    .scrollbar_hook 0x45484C90 :
    {
        KEEP(*(.text.scrollbar_hook))
    }

    .patch_section 0x45DB6E40 :
    {
        KEEP(*(.text.patch_section))
    }
}
