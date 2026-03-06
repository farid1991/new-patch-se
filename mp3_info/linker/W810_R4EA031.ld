/* Sections placement */
SECTIONS
{
    .brw_mp3_hook 0x455C3760 :
    {
        KEEP(*(.text.brw_mp3_hook))
    }

    .patch_section 0x456D22B0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
