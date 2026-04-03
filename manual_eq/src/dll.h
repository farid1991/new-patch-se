#ifndef _DLL_H_
#define _DLL_H_

#define MAKE_FONT(style, size) (((style) << 8) | (size))

#ifdef __cplusplus
extern "C" {
#endif

void dll_DrawString(uint16_t font,
                    TEXTID text_id,
                    uint8_t align,
                    int16_t x1,
                    int16_t y1,
                    int16_t x2,
                    int16_t y2,
                    uint32_t pen_color);
int dll_GetImageWidth(IMAGEID image_id);
int dll_GetImageHeight(IMAGEID image_id);
void dll_GC_PutChar(int16_t x, int16_t y, uint16_t width, uint16_t height, IMAGEID image_id);

#ifdef __cplusplus
}
#endif

#endif
