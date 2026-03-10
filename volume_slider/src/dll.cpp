#if defined(J108_R7EA011)
#include <J108_R7EA011.h>
#define DB3350_R2
#endif

#include <libse.h>

#include <classes/IFontManager.h>
#include <classes/IRichTextLayout.h>
#include <classes/ITextRenderingManager.h>

#include "dll.h"

// SetFont ----------------------------------------------------
extern "C" THUMB16
NEWCODE void dll_SetFont(int font, IFont **ppFont)
{
	IFontManager *pFontManager = 0;
	IFontFactory *pFontFactory = 0;
	TUIFontData pFontData;
	memset(&pFontData, 0, sizeof(TUIFontData));

	CoCreateInstance(CID_CUIFontManager, IID_IUIFontManager, PPINTERFACE(&pFontManager));
	pFontManager->GetFontFactory(&pFontFactory);
	pFontFactory->GetDefaultFontSettings(UIFontSizeLarge, &pFontData);

	int font_size = font & 0xFF;
	int font_style = font >> 8;
	pFontData.size = (float)font_size;
	pFontData.emphasis = (TUIEmphasisStyle)font_style;
	pFontFactory->CreateDefaultFont(&pFontData, ppFont);

	if (pFontManager)
		pFontManager->Release();
	if (pFontFactory)
		pFontFactory->Release();
}

// DrawString ----------------------------------------------------
extern "C" THUMB16
NEWCODE void dll_DrawString(int font, TEXTID text_id, int align, int x1, int y1, int x2, int y2, int text_color)
{
	ITextRenderingManager *pTextRenderingManager = 0;
	ITextRenderingFactory *pTextRenderingFactory = 0;
	IUIRichTextLayoutOptions *pRichTextLayoutOptions = 0;
	IRichTextLayout *pRichTextLayout = 0;
	IRichText *pRichText = 0;
	IUnknown *pCanvas = 0;
	IFont *pFont = 0;

	dll_SetFont(font, &pFont);

	CoCreateInstance(CID_CTextRenderingManager, IID_ITextRenderingManager, PPINTERFACE(&pTextRenderingManager));
	pTextRenderingManager->GetTextRenderingFactory(&pTextRenderingFactory);
	pTextRenderingFactory->CreateRichText(&pRichText);
	pTextRenderingFactory->CreateRichTextLayoutOptions(&pRichTextLayoutOptions);
	pTextRenderingFactory->CreateRichTextLayout(pRichText, 0, pRichTextLayoutOptions, &pRichTextLayout);

	TextObject_SetText(pRichText, text_id);
	TextObject_SetFont(pRichText, pFont, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
	pRichText->SetTextColor(text_color, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);
	pRichText->SetAlignment((TUITextAlignment)align, UITEXTSTYLE_START_OF_TEXT, UITEXTSTYLE_END_OF_TEXT);

	pRichTextLayoutOptions->SetLineBreakModel(UILineBreakBit_OK_To_Break_On_Glyph);

	TUIRectangle rect;
	rect.Point.X = x1;
	rect.Point.Y = y1;
	rect.Size.Width = x2 - x1;
	rect.Size.Height = y2 - y1;
	pRichTextLayout->Compose(rect.Size.Width);
	DisplayGC_AddRef(get_DisplayGC(), &pCanvas);
	pRichTextLayout->Display(pCanvas, x1, y1, &rect);

	if (pTextRenderingManager)
		pTextRenderingManager->Release();
	if (pTextRenderingFactory)
		pTextRenderingFactory->Release();
	if (pRichTextLayoutOptions)
		pRichTextLayoutOptions->Release();
	if (pRichTextLayout)
		pRichTextLayout->Release();
	if (pRichText)
		pRichText->Release();
	if (pCanvas)
		pCanvas->Release();
	if (pFont)
		pFont->Release();
}