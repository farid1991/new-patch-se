/* Sections placement */
SECTIONS
{
    .brw_mp3_hook 0x152A0D84 :
    {
        KEEP(*(.text.brw_mp3_hook))
    }

    .patch_section 0x15D62F60 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
