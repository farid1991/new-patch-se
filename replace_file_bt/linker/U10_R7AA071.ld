/* Sections placement */
SECTIONS
{
    text.ddb_question 0x159526C8 :
    {
        KEEP(*(.text.ddb_question))
    }

    text.ddb_filefix 0x15952BD0 :
    {
        KEEP(*(.text.ddb_filefix))
    }

    text.ddb_file 0x15952BDC :
    {
        KEEP(*(.text.ddb_file))
    }

    text.ddb_close 0x159524F0 :
    {
        KEEP(*(.text.ddb_close))
    }

    text.patch_section 0x162BCAA0 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}
