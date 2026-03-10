#ifndef _DLL_H_
#define _DLL_H_

#define MAKE_FONT(style, size) (((style) << 8) | (size))

#ifdef __cplusplus
extern "C" {
#endif

void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, uint32_t pen_color);
int dll_GetImageWidth(IMAGEID image_id);
int dll_GetImageHeight(IMAGEID image_id);
void dll_GC_PutChar(GC *gc_ctx, int x, int y, int width, int height, IMAGEID image_id);

#ifdef __cplusplus
}
#endif

#endif
