#ifndef RightNowBook_h
#define RightNowBook_h

typedef struct ActivityMenuBook
{
	BOOK book;
#if defined(DB2010)
	char unk_18[0x2A58];
	GUI_TABMENUBAR *main_tab;
	int unk_2A74;
	GUI_LIST *first_tab;
	int unk_2A7C;
	int unk_2A80;
	GUI_LIST *third_tab;
	GUI_LIST *second_tab;
	char unk_2A8C[0x14];
#elif defined(DB2020) || defined(PNX5230)
	char unk_18[0x2934];
	GUI *main_tab;
	void *unk_2950[0x4];
	GUI_LIST *first_tab;
	void *unk_2958;
	void *unk_295C;
	GUI_LIST *second_tab;
	GUI_LIST *third_tab;
	GUI_LIST *fourth_tab;
	char unk_296C[0x28];
#endif
} ActivityMenuBook;

#endif
