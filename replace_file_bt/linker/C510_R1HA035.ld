/* Sections placement */
SECTIONS
{
    text.ddb_question 0x14CB6FF8 :
    {
        KEEP(*(.text.ddb_question))
    }

    text.ddb_file 0x14DDAAF8 :
    {
        KEEP(*(.text.ddb_file))
    }

    text.ddb_close 0x14CB75FC :
    {
        KEEP(*(.text.ddb_close))
    }

    text.patch_section 0x15DDAD60 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
