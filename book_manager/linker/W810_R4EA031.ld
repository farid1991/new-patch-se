/* Sections placement */
SECTIONS
{
    .tab_icon_1 0x44563FBA :
    {
        KEEP(*(.text.tab_icon_1))
    }
    .tab_icon_2 0x4563E58C :
    {
        KEEP(*(.text.tab_icon_2))
    }
    .tab_focus 0x4563E41C :
    {
        KEEP(*(.text.tab_focus))
    }
    .gui_create 0x4563E3E4 :
    {
        KEEP(*(.text.gui_create))
    }
    .book_close 0x4563E6B4 :
    {
        KEEP(*(.text.book_close))
    }
    .title_events 0x4563FB6C :
    {
        KEEP(*(.text.title_events))
    }
    .internet_tab 0x4563E27C :
    {
        KEEP(*(.text.internet_tab))
    }

    .activetask_tab 0x4563E2AC :
    {
        KEEP(*(.text.activetask_tab))
    }

    .patch_section 0x457F0080 :
    {
        KEEP(*(.text.patch_section))
        KEEP(*(.rodata*))
    }
}