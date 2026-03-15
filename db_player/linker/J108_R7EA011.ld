/* Sections placement */
SECTIONS
{
    text.sound_run_hook_fix 0x14816C6A :
    {
        KEEP(*(.text.sound_run_hook_fix))
    }
    text.sound_run_hook 0x14816C6C :
    {
        KEEP(*(.text.sound_run_hook))
    }
    text.mme_data_fix 0x1579CC8C :
    {
        KEEP(*(.text.mme_data_fix))
    }

    text.patch_section 0x15D65E80 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}