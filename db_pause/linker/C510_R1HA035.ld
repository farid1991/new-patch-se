/* Sections placement */
SECTIONS
{
    .softkey_action 0x14CC0EB0 :
    {
        KEEP(*(.text.softkey_action))
    }
    .softkey_text 0x14CC0EB4 :
    {
        KEEP(*(.text.softkey_text))
    }

    .add_new_softkeys 0x14CC0E24 :
    {
        KEEP(*(.text.add_new_softkeys))
    }

    .patch_section 0x15D80000 :
    {
        KEEP(*(.text.patch_section))
    }
}
