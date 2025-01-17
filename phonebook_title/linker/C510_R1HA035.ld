/* Sections placement */
SECTIONS
{
    .title_1 0x14EA690C :
    {
        KEEP(*(.text.title_1))
    }

    .title_2 0x14EA663C :
    {
        KEEP(*(.text.title_2))
    }

    .patch_section 0x15DDAD60 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
