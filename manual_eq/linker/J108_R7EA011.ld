/* Sections placement */
SECTIONS
{
    .text.patch_fix_set_eq_hook1 0x14797AFC :
    {
        KEEP(*(.text.patch_fix_set_eq_hook1))
    }
    .text.patch_fix_set_eq_hook2 0x14797B00 :
    {
        KEEP(*(.text.patch_fix_set_eq_hook2))
    }
    .text.patch_set_eq_hook 0x14797B50 :
    {
        KEEP(*(.text.patch_set_eq_hook))
    }

    .text.patch_eq_set_gain 0x14797ED4 :
    {
        KEEP(*(.text.patch_eq_set_gain))
    }

    .text.patch_eq_softkeys 0x14A07678 :
    {
        KEEP(*(.text.patch_eq_softkeys))
    }

    .text.patch_section 0x15D6C1A0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
