/* Sections placement */
SECTIONS
{
    text.ddb_question 0x1188CC5C :
    {
        KEEP(*(.text.ddb_question))
    }

    text.ddb_file 0x1188D228 :
    {
        KEEP(*(.text.ddb_file))
    }

    text.ddb_close 0x1188D07C :
    {
        KEEP(*(.text.ddb_close))
    }

    text.patch_section 0x12792900 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
