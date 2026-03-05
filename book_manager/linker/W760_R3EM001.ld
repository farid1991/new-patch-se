/* Sections placement */
SECTIONS
{
    .tab_icon_1 0x10BD1084 :
    {
        KEEP(*(.text.tab_icon_1))
    }
    .tab_icon_2 0x10BD10B8 :
    {
        KEEP(*(.text.tab_icon_2))
    }
    .tab_focus 0x10BD04FC :
    {
        KEEP(*(.text.tab_focus))
    }
    .gui_create 0x10BD0764 :
    {
        KEEP(*(.text.gui_create))
    }
    .book_close 0x10BD0218 :
    {
        KEEP(*(.text.book_close))
    }
    .title_events 0x10BD669C :
    {
        KEEP(*(.text.title_events))
    }
    .internet_tab 0x10BD06A4 :
    {
        KEEP(*(.text.internet_tab))
    }
    .shortcuts_tab 0x10BD06C0 :
    {
        KEEP(*(.text.shortcuts_tab))
    }
    .activetask_tab 0x10BD06E4 :
    {
        KEEP(*(.text.activetask_tab))
    }

    .patch_section 0x1281AF30 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}