/* Sections placement */
SECTIONS
{
    .secondline_hook 0x157470D0 :
    {
        KEEP(*(.text.secondline_hook))
    }

    .patch_section 0x15DD90A0 :
    {
        KEEP(*(.text.patch_section))
    }
}
