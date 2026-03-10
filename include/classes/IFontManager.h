#ifndef _IFONTMANAGER_H_
#define _IFONTMANAGER_H_

#include <base.h>
#include <classes/IUnknown.h>
#include <types/UIFont_types.h>

// clang-format off
class IFontResource : public IUnknown
{
public:
    virtual int GetName(IUnknown **ppIString);
    virtual int GetStyle(TUIFontResourceStyle *pStyle);
};

class IFontResourceManager : public IUnknown
{
public:
    virtual int GetDefaultFont(TUIFontResourceStyle style, IFontResource **ppIFontResource);
    virtual int GetFontFromFamilyName(IUnknown *pIFamilyName, TUIFontResourceStyle style, IFontResource **ppIFontResource);
    virtual int AddFontResource(IUnknown *pIFamilyName, IUnknown *pIFontPath, TUIFontResourceStyle style, IFontResource **ppIFontResource);
    virtual int SetDefaultFont(IUnknown *pIFamilyName);
    virtual int GetFontFromFile(IUnknown *pIPath, IFontResource **ppIFontResource);
};

class IFontStyle : public IUnknown
{
public:
    virtual int GetAscender(float *pAscender);
    virtual int GetDescender(float *pDescender);
    virtual int GetLeading(float *pLeading);
    virtual int GetXSize(float *pXSize);
    virtual int GetYSize(float *pYSize);
    virtual int MapChar(int32_t charID, int32_t *pGlyphID);
    virtual int GetGlyphMetrics(int32_t glyphID, IUnknown *pMetrics);
    virtual int GetFont(IFontResource **ppIFontResource);
    virtual int GetFontParams(TUIFontData *pFontData);
};

class IFontStyleManager : public IUnknown
{
public:
    virtual int GetDefaultFontSettings(TUIFontParamSize size, TUIFontData *pFontData);
    virtual int GetFontStyle(IFontResource *pIFontResource, TUIFontData *pFontData, IFontStyle **ppIFontStyle);
};

class IFont : public IUnknown
{
public:
    virtual int GetFace(TUIFontFace *buf);
    virtual int GetSize(TUIFontSize *buf);
    virtual int GetStyle(TUIFontStyle *buf);
    virtual int GetFontAscent(int32_t *pAscent);
    virtual int GetFontHeight(int32_t *font_size);
    virtual int IsBold();
    virtual int IsItalic();
    virtual int IsPlain();
    virtual int IsUnderlined();
    virtual int GetFontStyle(IFontStyle *pIUIFontStyle);
};

class IFontFactory : public IUnknown
{
public:
    virtual int GetFont(TUIFontFace Face, TUIFontSize Size, TUIFontStyle Style, IFont **pFont);
    virtual int GetDefaultFont(IFont **pFont);
    virtual int GetDefaultFontSettings(TUIFontSize Size, TUIFontData *pFontData);
    virtual int CreateDefaultFont(TUIFontData *pfontData, IFont **pFont);
    virtual int CreateFontFromFamilyName(IUnknown *pIFamilyName, TUIFontData *pfontData, IFont **pFont);
    virtual int CreateFontFromFile(IUnknown *pIFullPath, TUIFontData *pfontData, IFont **pFont);
};

class IFontManager : public IUnknown
{
public:
    virtual int GetFontFactory(IFontFactory **pFontFactory);
};
// clang-format on

#endif
