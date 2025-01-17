#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include <base.h>

typedef struct AB_NUM_ITEM
{
	uint16_t RecordID;
	char num[41]; // 2
	char xx[0x35];
} AB_NUM_ITEM;

typedef struct AB_STR_ITEM
{
	uint16_t len;
	uint8_t encodingID;
	char str[255];
} AB_STR_ITEM;

typedef struct AB_GET_STRUCT
{
	uint16_t unk_02;
	uint32_t rec_num;
} AB_GET_STRUCT;

typedef struct AB_ITEM_DESC_A2
{
	uint16_t num;
	uint16_t icon;
	uint32_t name;
	uint32_t name2;
	uint16_t field_C;
	uint16_t field_D;
	uint16_t big_icon;
	uint16_t field_10;
	uint16_t ID;
	uint16_t null;
} AB_ITEM_DESC_A2;

typedef struct AB_ITEM_DESC_2020
{
	uint16_t num;
	uint16_t tab;
	uint16_t num_in_tab;
	uint16_t icon;
	uint32_t name;
	char field_C;
	char field_D;
	uint16_t big_icon;
	uint16_t field_10;
	uint16_t ID;
} AB_ITEM_DESC_2020;

typedef struct AB_ITEM_DESC
{
	uint16_t num;
	uint16_t field_2;
	uint16_t field_4;
	uint16_t icon;
	uint32_t name;
	uint16_t field_C;
	uint16_t field_E;
	uint16_t field_10;
	char field_12;
	char field_13;
	char field_14;
	char field_15;
	uint16_t field_16l;
	uint8_t ID;
	char field_19;
	char field_1A;
	char field_1B;
} AB_ITEM_DESC;

#endif // ADDRESSBOOK_H