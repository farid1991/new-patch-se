/* Sections placement */
SECTIONS
{
    .text.standby_sk_text 0x4515BBAC :
    {
        KEEP(*(.text.standby_sk_text))
    }
    .text.standby_sk_link 0x4515BBA8 :
    {
        KEEP(*(.text.standby_sk_link))
    }

    .text.patch_section 0x457030C0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.data*))
        KEEP(*(.rodata*))
    }
}
