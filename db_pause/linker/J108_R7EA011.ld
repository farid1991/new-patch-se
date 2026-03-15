/* Sections placement */
SECTIONS
{
    .softkey_action 0x14816D04 :
    {
        KEEP(*(.text.softkey_action))
    }
    .softkey_text 0x14816C82 :
    {
        KEEP(*(.text.softkey_text))
    }

    .add_new_softkeys 0x14816C94 :
    {
        KEEP(*(.text.add_new_softkeys))
    }

    .patch_section 0x15D65E80 :
    {
        KEEP(*(.text.patch_section))
    }
}
