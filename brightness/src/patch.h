#ifndef __PATCH__H_
#define __PATCH__H_

static const wchar_t BACKGROUND[] = L"Background.png";
static const wchar_t LVL_NORMAL[] = L"Level_Normal.png";
static const wchar_t LVL_UP[] = L"Level_Up_Max.png";
static const wchar_t LVL_DOWM[] = L"Level_Down_Max.png";

static const wchar_t CONFIG_PATH[] = L"/usb/other/ZBin/Config/Brightness";
static const wchar_t CONFIG_NAME[] = L"Brightness.ini";

static const wchar_t BRIGHT_FMT[] = L"Brightness: %d%%";

static const char KEY_BACKGROUND[] = "[Background]";
static const char KEY_LEVEL[] = "[Level]";
static const char KEY_TITLE_POS[] = "[Title]";
static const char KEY_TITLE_COLOR[] = "[TitleColor]";
static const char KEY_TITLE_ALIGN[] = "[TitleAlign]";
static const char KEY_TITLE_FONT[] = "[TitleFont]";
static const char KEY_PERCENT_POS[] = "[Percent]";
static const char KEY_PERCENT_COLOR[] = "[PercentColor]";
static const char KEY_PERCENT_ALIGN[] = "[PercentAlign]";
static const char KEY_PERCENT_FONT[] = "[PercentFont]";

#define BRIGHT_MAX 100
#define BRIGHT_MIN 0

typedef struct GUI GUI_BRIGHT;

static const char GUI_BRIGHT_MEM[] = "BR";
static const char GUI_BRIGHT_NAME[] = "GUI_Bright";

enum
{
	BACKGROUND_ICN,
	LEVEL_NORMAL_ICN,
	LEVEL_UP_ICN,
	LEVEL_DOWN_ICN,
	LAST_ICN
} IMAGE_LIST;

static const wchar_t *const images_names[LAST_ICN] = {BACKGROUND, LVL_NORMAL, LVL_UP, LVL_DOWM};

typedef struct
{
	IMAGEID id;
	uint16_t handle;
} IMAGE_DESC;

typedef struct
{
	uint32_t Percent_Text_Color;
	uint32_t Percent_Text_Border;
	int16_t Percent_Text_x1;
	int16_t Percent_Text_y1;
	int16_t Percent_Text_x2;
	int16_t Percent_Text_y2;
	uint8_t Percent_Text_Align;
	uint8_t Percent_Text_Font;

	uint32_t Title_Text_Color;
	uint32_t Title_Text_Border;
	int16_t Title_Text_x1;
	int16_t Title_Text_y1;
	int16_t Title_Text_x2;
	int16_t Title_Text_y2;
	uint8_t Title_Text_Align;
	uint8_t Title_Text_Font;

	int16_t Icon_Background_x;
	int16_t Icon_Background_y;
	int16_t Icon_Level_x;
	int16_t Icon_Level_y;
} CONFIG_DATA;

typedef struct
{
	DISP_OBJ disp;
	uint16_t bright;
	uint16_t cstep;
	IMAGEID active_image;
	IMAGE_DESC images[LAST_ICN];
	CONFIG_DATA *data;
} DISP_OBJ_BRIGHT;

#define Save_Brightness_Level ((void (*)(int))ADDR_Save_Brightness_Level)

#endif
