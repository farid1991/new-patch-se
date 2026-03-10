#ifndef _DLL_H_
#define _DLL_H_

#include <classes/IMetaData.h>

#ifdef __cplusplus
extern "C" {
#endif

void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, uint32_t pen_color);
int dll_Disp_GetTextIDWidth(int font, TEXTID text_id, int len);
int dll_GetImageWidth(IMAGEID image_id);
int dll_GetImageHeight(IMAGEID image_id);
void dll_GC_PutChar(GC *gc, int x, int y, int width, int height, IMAGEID image_id);

METADATA_DESC *dll_MetaData_Desc_Create(wchar_t *path, wchar_t *name);
void dll_MetaData_Desc_Destroy(METADATA_DESC *MetaData_Desc);
BOOL dll_MetaData_Desc_HasAlbumArt(METADATA_DESC *MetaData_Desc, wchar_t *path, wchar_t *name);
int dll_MetaData_Desc_GetCoverInfo(METADATA_DESC *MetaData_Desc, char *cover_type, int *size, int *cover_offset);

#ifdef __cplusplus
}
#endif

#endif
