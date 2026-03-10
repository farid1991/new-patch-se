#ifndef __UIFONT_TYPES_H__
#define __UIFONT_TYPES_H__

#include <types/Basic_types.h>

// clang-format off

typedef FUint16 TUIRenderStyle;

/**
 *
 *  Typedef for text emphasis style
 *
 */
typedef enum
{
    UI_Emphasis_Normal,    ///< normal
    UI_Emphasis_Bold,      ///< bold
    UI_Emphasis_Italic,    ///< italic
    UI_Emphasis_BoldItalic ///< bold italic
} TUIEmphasisStyle;

/**
 *
 *  Typedef for baseline style.
 *
 */
typedef enum
{
    UI_Baseline_Normal,      ///< normal baseline
    UI_Baseline_Superscript, ///< superscript
    UI_Baseline_Subscript    ///< subscript
} TUIBaselineStyle;

/**
 *
 *  Typedef for text edge style.
 *
 */
typedef enum
{
    UI_Edge_Normal,      ///< normal text without any edge effect
    UI_Edge_Embossed,    ///< text has a raised appearance
    UI_Edge_Engrayed,    ///< text has a depressed appearance
    UI_Edge_Outlined,    ///< text is just an outline
    UI_Edge_Drop_Shadow, ///< text has a shadow
    UI_Edge_Raised,      ///< similar to embossed, but more of a shadow effect
    UI_Edge_Depressed,   ///< similar to engraved, but more of a shadow effect
    UI_Edge_Uniform      ///< normal text with a colored edge around it, "cartoon style"
} TUIEdgeStyle;

typedef struct
{
    TFloat size;           ///< height in ppem (20.0 ppem)
    TFloat width;          ///< width in ppem; (0 - treated as equal to size)
    TFloat skew;           ///< skew angle (0)
    TFloat orientation;    ///< glyph rotation, degrees clockwise (0.0)
    TFloat bold_pct;       ///< boldness value (0)
    TFloat stroke_pct;     ///< stroke width (0)
    TFloat edgeThickness;  ///< edge thickness in pixels (0)
    TFloat shadowLength_x; ///< x-direction length of shadow in pixels (0)
    TFloat shadowLength_y; ///< y-direction length of shadow in pixels (0)
#ifdef DB3350_R2
    TFloat unk1;
    TFloat unk2;
#endif
    FUint16 emphasis; ///< emphasis such as bold/italics (UI_Emphasis_Normal)
    FUint16 baseline; ///< text baseline style (UI_Baseline_Normal)
    FUint16 edge;     ///< text edge style (UI_Edge_Normal)
    FUint16 render;   ///< rendering style (UI_Render_Default)
} TUIFontData;

typedef uint8_t TUIFontStyle;

#define UIFontStylePlain 0      ///< The plain style enum
#define UIFontStyleBold 1       ///< The bold style enum.
#define UIFontStyleItalic 2     ///< The italic style enum
#define UIFontStyleBoldItalic 3 ///< The bold italic style enum
#define UIFontStyleUnderlined 4 ///< The underlined style enum

typedef enum
{
    UIFontSizeMedium = 0, ///< The "medium" system-dependent font size
    UIFontSizeSmall = 8,  ///< The "small" system-dependent font size
    UIFontSizeLarge = 16  ///< The "large" system-dependent font size
} TUIFontSize;

typedef enum
{
    UIFontFaceSystem = 0,       ///< The "system" font face
    UIFontFaceMonoSpace = 32,   ///< The "monospace" font face.
    UIFontFaceProportional = 64 ///< The "proportional" font face.
} TUIFontFace;

typedef enum
{
    UIFontResourceStylePlain,     ///< Regular system font
    UIFontResourceStyleBold,      ///< Bold system font
    UIFontResourceStyleItalic,    ///< Italic system font
    UIFontResourceStyleBoldItalic ///< Bold italic system font
} TUIFontResourceStyle;

typedef enum
{
    UIFontParamSizeNone,
    UIFontParamSizeMedium,
    UIFontParamSizeSmall,
    UIFontParamSizeLarge
} TUIFontParamSize;

// clang-format on

#endif
