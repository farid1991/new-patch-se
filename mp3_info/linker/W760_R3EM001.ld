/* Sections placement */
SECTIONS
{
    .brw_mp3_hook 0x1187BDD4 :
    {
        KEEP(*(.text.brw_mp3_hook))
    }

    .patch_section 0x12818380 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
