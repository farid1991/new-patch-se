#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#endif

#include <libse.h>

#include <classes/IImageManager.h>
#include <classes/IFontManager.h>
#include <classes/IRichTextLayout.h>
#include <classes/ITextRenderingManager.h>

#include "dll.h"

// SetFont ----------------------------------------------------
extern "C" THUMB16 NEWCODE int dll_SetFont(int font, IFont **ppFont)
{
    if (!ppFont)
        return -1;

    *ppFont = 0;

    IFontManager *mgr = 0;
    IFontFactory *factory = 0;

    if (CoCreateInstance(CID_CUIFontManager, IID_IUIFontManager, PPINTERFACE(&mgr)) < 0 || !mgr)
        return -1;

    if (mgr->GetFontFactory(&factory) < 0 || !factory)
        goto cleanup_mgr;

    TUIFontData data;
    memset(&data, 0, sizeof(data));
    factory->GetDefaultFontSettings(UIFontSizeLarge, &data);
    data.size = (float)(font & 0xFF);
    data.emphasis = (TUIEmphasisStyle)(font >> 8);
    factory->CreateDefaultFont(&data, ppFont);
    factory->Release();

cleanup_mgr:
    mgr->Release();
    return (*ppFont) ? 0 : -1;
}

// DrawString ----------------------------------------------------
extern "C" THUMB16 NEWCODE void dll_DrawString(int font, TEXTID text, int align,
                                               int x1, int y1, int x2, int y2,
                                               uint32_t pen_color)
{
    ITextRenderingManager *mgr = 0;
    ITextRenderingFactory *factory = 0;
    IUIRichTextLayoutOptions *layoutOpts = 0;
    IRichTextLayout *layout = 0;
    IRichText *textObj = 0;
    IUnknown *canvas = 0;
    IFont *fontObj = 0;

    TUIRectangle rect;

    int lineWidth = 0;

    if (CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&mgr)) < 0 || !mgr)
        return;

    if (mgr->GetTextRenderingFactory(&factory) < 0 || !factory)
        goto cleanup_mgr;

    factory->CreateRichText(&textObj);
    factory->CreateRichTextLayoutOptions(&layoutOpts);
    factory->CreateRichTextLayout(textObj, 0, 0, &layout);

    if (!textObj || !layoutOpts || !layout)
        goto cleanup_factory;

    if (dll_SetFont(font, &fontObj) < 0)
        goto cleanup_factory;

    TextObject_SetText(textObj, text);
    TextObject_SetFont(textObj, fontObj, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
    textObj->SetTextColor(pen_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
    textObj->SetAlignment((TUITextAlignment)align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

    layoutOpts->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);

    lineWidth = x2 - x1;
    layout->Compose(lineWidth);

    rect.Point.X = x1;
    rect.Point.Y = y1;
    rect.Size.Width = lineWidth;
    rect.Size.Height = y2 - y1;

    DisplayGC_AddRef(get_DisplayGC(), &canvas);
    if (canvas)
    {
        layout->Display(canvas, x1, y1, &rect);
        canvas->Release();
    }

    fontObj->Release();

cleanup_factory:
    if (layout)
        layout->Release();
    if (layoutOpts)
        layoutOpts->Release();
    if (textObj)
        textObj->Release();
    if (factory)
        factory->Release();

cleanup_mgr:
    if (mgr)
        mgr->Release();
}

// GC_PutChar ----------------------------------------------------
extern "C" THUMB16 NEWCODE int GetImageManagerObj(IUIImageManager **ppMgr)
{
    return CoCreateInstance(CID_CUIImageManager, IID_IUIImageManager,
                            PPINTERFACE(ppMgr));
}

extern "C" THUMB16 NEWCODE void dll_GC_PutChar(GC *gc_ctx,
                                               int x, int y,
                                               int width, int height,
                                               IMAGEID imageID)
{
    IUIImageManager *mgr = 0;
    IUIImage *img = 0;
    IUnknown *canvas = 0;

    if (GetImageManagerObj(&mgr) < 0 || !mgr)
        return;

    if (mgr->CreateFromIcon(imageID, &img) >= 0 && img)
    {
        DisplayGC_AddRef(gc_ctx, &canvas);

        if (canvas)
        {
            TUIRectangle rect = {
                {x, y},
                {width, height}};

            mgr->Draw(img, canvas, rect);
            canvas->Release();
        }

        img->Release();
    }

    mgr->Release();
}

// GetImageWidthHeight ----------------------------------------------------
extern "C" THUMB16 NEWCODE int GetImageDimension(IMAGEID imageID, int wantWidth)
{
    IUIImageManager *mgr = 0;
    IUIImage *img = 0;
    int value = 0;

    if (GetImageManagerObj(&mgr) < 0 || !mgr)
        return 0;

    if (mgr->CreateFromIcon(imageID, &img) >= 0 && img)
    {
        if (wantWidth)
            img->GetDimensions(&value, 0, 0, 0);
        else
            img->GetDimensions(0, 0, &value, 0);

        img->Release();
    }

    mgr->Release();
    return value;
}

extern "C" THUMB16 NEWCODE int dll_GetImageWidth(IMAGEID imageID)
{
    return GetImageDimension(imageID, 1);
}

extern "C" THUMB16 NEWCODE int dll_GetImageHeight(IMAGEID imageID)
{
    return GetImageDimension(imageID, 0);
}
