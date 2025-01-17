#ifndef MENU_H
#define MENU_H

typedef struct
{
	char unk[0x30];
} DYNAMIC_MENU_ELEMENT;

enum DYNAMIC_MENU_ELEMENT_MSG
{
	DYNAMIC_MENU_onCall = 0,
	DYNAMIC_MENU_onText,
	DYNAMIC_MENU_onState,
	DYNAMIC_MENU_onUnk1,
	DYNAMIC_MENU_onUnk2,
	DYNAMIC_MENU_last
};

#endif // MENU_H