#ifndef __GUI_H__
#define __GUI_H__

static const wchar_t CONFIG_NAME[] = L"eq.bin";
static const wchar_t CONFIG_PATH[] = L"/usb/other/Equalizer";

static const char GUI_MANUAL_EQ[] = "Manual_Equalizer_Display";

typedef struct IMG
{
	IMAGEID ID;
	uint16_t ImageHandle;
} IMG;

typedef struct
{
	BOOL manual;
	int boost_level;
	int bar1_level;
	int bar2_level;
	int bar3_level;
	int bar4_level;
	int bar5_level;
} EQ_SETTINGS;

static const int redrect_positions[6][4] = {
        /*x    y   w   h*/
        {16,  168, 52, 5},
        {75,  152, 27, 3},
        {106, 152, 27, 3},
        {137, 152, 27, 3},
        {168, 152, 27, 3},
        {199, 152, 27, 3},
};

enum Bar_Level
{
	Bar_Minus_3,
	Bar_Minus_2,
	Bar_Minus_1,
	Bar_Netral,
	Bar_Plus_1,
	Bar_Plus_2,
	Bar_Plus_3,
	LastBarLevel
};

enum Boost_Level
{
	Boost_0,
	Boost_1,
	Boost_2,
	Boost_3,
	LastBoostLevel
};

enum Eq_Band
{
	Eq_Band0,
	Eq_Band1,
	Eq_Band2,
	Eq_Band3,
	Eq_Band4,
	Eq_Band5,
	LastEQBand
};

static const wchar_t BackgroundImage[] = L"MP_EQ_BACKGROUND_V_ICN.png";

static const wchar_t *BoostImage[LastBoostLevel] = {
        L"BOOST_LEVEL1.png", L"BOOST_LEVEL2.png", L"BOOST_LEVEL3.png", L"BOOST_LEVEL4.png"};

static const wchar_t *BarImage[LastBarLevel] = {L"BAR_MINUS3.png",
                                                L"BAR_MINUS2.png",
                                                L"BAR_MINUS1.png",
                                                L"BAR_NORMAL.png",
                                                L"BAR_PLUS1.png",
                                                L"BAR_PLUS2.png",
                                                L"BAR_PLUS3.png"};

typedef struct
{
	DISP_OBJ disp;
	uint16_t height;
	uint16_t width;
	int cursor;
	int boost_level;
	int bar1_level;
	int bar2_level;
	int bar3_level;
	int bar4_level;
	int bar5_level;
	IMG Background;
	IMG Bar_Image[LastBarLevel];
	IMG Boost_Image[LastBoostLevel];
} DISP_OBJ_CLEARBASS;

GUI *Create_ClearbassGUI(BOOK *book);
void GUIObject_Clearbass_SetBarLevel(GUI *gui, int boost_level, int b1, int b2, int b3, int b4, int b5);
void GUIObject_Clearbass_GetBarLevel(GUI *gui, int *boost_level, int *b1, int *b2, int *b3, int *b4, int *b5);

#endif
