/* Sections placement */
SECTIONS
{
    .softkey_action 0x1187ACF8 :
    {
        KEEP(*(.text.softkey_action))
    }
    .softkey_text 0x1187ACFC :
    {
        KEEP(*(.text.softkey_text))
    }

    .add_new_softkeys 0x1187AB64 :
    {
        KEEP(*(.text.add_new_softkeys))
    }

    .patch_section 0x1281ACB0 :
    {
        KEEP(*(.text.patch_section))
    }
}
