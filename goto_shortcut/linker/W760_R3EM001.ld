/* Sections placement */
SECTIONS
{
    .text.standby_sk_text 0x10E2C5DC :
    {
        KEEP(*(.text.standby_sk_text))
    }
    .text.standby_sk_link 0x10E2C5E0 :
    {
        KEEP(*(.text.standby_sk_link))
    }

    .text.patch_section 0x127900A0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.data*))
        KEEP(*(.rodata*))
    }
}
