#ifndef DATETIME_H
#define DATETIME_H

#include <base.h>

typedef struct DATE
{
	uint16_t year;
	uint8_t mon;
	uint8_t day;
} DATE;

typedef struct WEEK
{
	uint8_t type;
	uint8_t days[7];
} WEEK;

typedef struct TIME
{
	uint8_t hour;
	uint8_t min;
	uint8_t sec;
	uint8_t msec;
} TIME;

typedef struct DATETIME
{
	DATE date;
	TIME time;
} DATETIME;

#endif // DATETIME_H