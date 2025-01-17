/* Sections placement */
SECTIONS
{
    text.ddb_question 0x1571472C :
    {
        KEEP(*(.text.ddb_question))
    }

    text.ddb_filefix 0x15714C34 :
    {
        KEEP(*(.text.ddb_filefix))
    }

    text.ddb_file 0x15714C40 :
    {
        KEEP(*(.text.ddb_file))
    }

    text.ddb_close 0x15714554 :
    {
        KEEP(*(.text.ddb_close))
    }

    text.patch_section 0x1602F4F0:
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
