/* Sections placement */
SECTIONS
{
    .tab_icon_1 0x144B21C0 :
    {
        KEEP(*(.text.tab_icon_1))
    }
    .tab_icon_2 0x144B21F0 :
    {
        KEEP(*(.text.tab_icon_2))
    }
    .tab_focus 0x14E05988 :
    {
        KEEP(*(.text.tab_focus))
    }
    .gui_create 0x14E057B0 :
    {
        KEEP(*(.text.gui_create))
    }
    .book_close 0x14D5F2D0 :
    {
        KEEP(*(.text.book_close))
    }
    .title_events 0x14C8278C :
    {
        KEEP(*(.text.title_events))
    }
    .internet_tab 0x14C826FC :
    {
        KEEP(*(.text.internet_tab))
    }
    .shortcuts_tab 0x14C82718 :
    {
        KEEP(*(.text.shortcuts_tab))
    }
    .activetask_tab 0x14C8273C :
    {
        KEEP(*(.text.activetask_tab))
    }

    .patch_section 0x15DD6F00 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}