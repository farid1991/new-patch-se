#ifndef GVI_GC_H
#define GVI_GC_H

#include <base.h>

typedef void *PCANVAS;

typedef struct POINT
{
	int32_t x;
	int32_t y;
} POINT;

typedef struct UISIZE
{
	int32_t x;
	int32_t y;
} UISIZE;

typedef struct POINT3D
{
	int32_t x;
	int32_t y;
	int32_t z;
} POINT3D;

typedef struct UIRECT
{
	POINT Point;
	UISIZE Size;
} UIRECT;

typedef struct RECT
{
	int16_t x1;
	int16_t x2;
	int16_t y1;
	int16_t y2;
} RECT;

typedef struct CANVAS_DESC
{
	int unk0;
	int unk1;
	int width;
	int height;
	uint8_t *pixel_data;
	int size;
} CANVAS_DESC;

typedef struct GC
{
	PCANVAS *pcanvas;
	char unk1[0x8];
	PCANVAS *pcanvas_pen;
	int pen_color;
	char unk3[0x4];
	PCANVAS *pcanvas_brush;
	int brush_color;
	uint8_t XX;
	char unk[0x3];
	PCANVAS *pcanvas_text;
	int unk2;
	PCANVAS *pcanvas_icon;
} GC;

typedef struct GVI_BITMAP
{
	int unk0;
	int unk1;
	int unk2;
	void *unk3;
	void *unk4;
	CANVAS_DESC *pcanvas_desc;
	int unk6;
	int unk7;
} GVI_BITMAP;

typedef void *GVI_OBJ;
typedef GVI_OBJ GVI_GC;
typedef GVI_OBJ GVI_BMP;
typedef GVI_OBJ GVI_PEN;
typedef GVI_OBJ GVI_BRUSH;

#endif // GVI_GC_H