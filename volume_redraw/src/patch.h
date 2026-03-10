#ifndef _pAtCh_H_
#define _pAtCh_H_

#define is_mocallbook ((int (*)(BOOK *))ADDR_is_mocallbook)

#define VolumeControl_OnCreate ((int (*)(DISP_OBJ *))ADDR_VolumeControl_OnCreate)

#define VolumeControl_OnRedraw ((void (*)(DISP_OBJ *, int, int, int))ADDR_VolumeControl_OnRedraw)

#define VolumeControl_OnClose ((void (*)(DISP_OBJ *))ADDR_VolumeControl_OnClose)

#define pg_VolumeControl_Active_EnterEvent ((int (*)(void *, BOOK *))ADDR_pg_VolumeControl_Active_EnterEvent)

#define pg_VolumeControl_Active_ExitEvent ((int (*)(void *, BOOK *))ADDR_pg_VolumeControl_Active_ExitEvent)

#define FREE_IMAGE(img) \
	if (img != NOIMAGE) \
		ImageID_Free(img);

#define MAX_PATH_LEN 256

static const char V_MEM[] = "VMEM";
static const char V_EMP[] = "VEMP";
static const char FMT_PERCENT[] = " %";

enum
{
	BACKGROUND_IMG,
	CALL_IMG,
	MUSIC_IMG,
	OFF_IMG,
	BLOB_IMG,
	LAST_IMG
};

static const wchar_t VOL_CFG[] = L"vol.cfg";
static const wchar_t SKIN_VSF[] = L"skin.vsf";
static const wchar_t BG_PNG[] = L"background.png";
static const wchar_t CALL_PNG[] = L"call.png";
static const wchar_t MUSIC_PNG[] = L"music.png";
static const wchar_t OFF_PNG[] = L"off.png";
static const wchar_t BLOB_PNG[] = L"blob.png";
static const wchar_t *VOLUME_IMGS[LAST_IMG] = {BG_PNG, CALL_PNG, MUSIC_PNG, OFF_PNG, BLOB_PNG};

typedef struct
{
	BOOL anim_enable;
	BOOL manual;
	uint32_t anim_style;
	POINT text_pos;
	int font_size;
	uint32_t text_color;
	BOOL text_enable;
	BOOL percentage_enable;
	POINT bg_image;
	POINT state_image;
	BOOL blob_enable;
	RECT progressbar;
	BOOL progressbar_enable;
	uint32_t progressbar_bg_color;
	uint32_t progressbar_elapsed_color;
	int anim_id[4];
} skin_config_t;

typedef struct
{
	uint16_t id;
	uint16_t handle;
} image_t;

typedef struct
{
	skin_config_t sk_config;
	wchar_t cfg_path[MAX_PATH_LEN];
	bool is_java;
	image_t volume_img[LAST_IMG];
} vdata_t;

static const uint8_t TABLE_VOL_CALL[9] = {0, 12, 25, 37, 50, 62, 75, 87, 100};
static const uint8_t TABLE_VOL_MEDIA[16] = {0, 6, 13, 20, 26, 33, 40, 46, 53, 60, 66, 73, 80, 86, 93, 100};

#endif
