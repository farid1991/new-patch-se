/* Sections placement */
SECTIONS
{
    .fm_sk_hook 0x1554AB40 :
    {
        KEEP(*(.text.fm_sk_hook))
    }

    .fm_sk_vis_hook 0x1554AC80 :
    {
        KEEP(*(.text.fm_sk_vis_hook))
    }

    .patch_section 0x15D20DD0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
