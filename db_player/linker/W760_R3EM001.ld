/* Sections placement */
SECTIONS
{
    text.sound_run_hook 0x1187AB3C :
    {
        KEEP(*(.text.sound_run_hook))
    }

    text.patch_section 0x1281C3E0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
