#ifndef SHORTCUT_H
#define SHORTCUT_H

typedef struct SHORTCUT_DESC
{
	wchar_t name[0x31];
	uint16_t null;
	uint16_t shortcut_state;
	uint16_t erasable_flag;
} SHORTCUT_DESC;

typedef struct SHORTCUT_DESC_A2
{
	wchar_t name[0xC8];
	wchar_t vendor_name[0xC8];
	wchar_t entry_point[0xC8];
	uint16_t pos_in_list;
	uint8_t xxx1;
	uint8_t xxx2;
	uint8_t item_type;
	uint8_t lock_type; // 0 - no lock, 1 - locked, 2 - lockedposition
	IMAGEID icon;
} SHORTCUT_DESC_A2;

typedef enum SHORTCUT_STATE
{
	SC_State_None = 0,
	SC_State_OutOfUse = 1,
	SC_State_Activated = 2,
	SC_State_MainMenu = 3
} SHORTCUT_STATE;

typedef enum SHORTCUT_ITEM_TYPE
{
	SC_Type_Standard = 0,
	SC_Type_JavaItem = 1,
	SC_Type_MainMenu = 2,
	SC_Type_AddShortcut = 3
} SHORTCUT_ITEM_TYPE;

#endif // SHORTCUT_H