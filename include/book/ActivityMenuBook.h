#ifndef ActivityMenuBook_H
#define ActivityMenuBook_H

typedef struct ActivityMenuBook
{
    BOOK book;
#if defined(DB3150v1)
    void *unk_0x18;
    void *unk_0x1C;
    void *unk_0x20;
    void *unk_0x24;
    GUI_TABMENUBAR *main_tab;
    GUI_LIST *first_tab;
    char unk_0x30[0x4];
    char unk_0x34[0x4];
    GUI_LIST *fourth_tab;
    GUI_LIST *third_tab;
    GUI_LIST *second_tab;
#elif defined(DB3150v2) || defined(DB3200) || defined(DB3210) || defined(DB3350)
    LIST *list1;
    LIST *EventsList;
    LIST *InternetList;
    GUI_TABMENUBAR *main_tab;
    GUI_LIST *first_tab;
    char unk_0x2C[0x4];
    char unk_0x30[0x4];
    GUI_LIST *fourth_tab;
    GUI_LIST *third_tab;
    GUI_LIST *second_tab;
#endif
} ActivityMenuBook;

#endif
