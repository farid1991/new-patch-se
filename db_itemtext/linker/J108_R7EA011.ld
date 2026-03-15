/* Sections placement */
SECTIONS
{
    .secondline_hook 0x148F3408 :
    {
        KEEP(*(.text.secondline_hook))
    }

    .patch_section 0x15D6BFD0 :
    {
        KEEP(*(.text.patch_section))
    }
}
