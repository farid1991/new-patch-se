#ifndef __UIRICHTEXT_TYPES_H__
#define __UIRICHTEXT_TYPES_H__

#include <types/Basic_types.h>
#include <types/UIRect_types.h>

// clang-format off
#define UIRICHTEXTLAYOUT_CONTAINER_NO_SIZE_LIMIT FSINT32_MAX
#define UIRICHTEXTLAYOUT_MAX_LINE_WIDTH 0x00007FFF

/**
 *  Macro to indicate an index that is always less than or equal to the
 *  start of the text.
 *
 */
#define UITEXTSTYLE_START_OF_TEXT (FSINT32_MIN + 10) /* +- 10 to avoid wrapping edge */

/**
 *  Macro to indicate an index that is always greater than or equal to the
 *  end of the text.
 *
 */
#define UITEXTSTYLE_END_OF_TEXT (FSINT32_MAX - 10)

/**
 *
 *  Enumeration of text encodings.
 *
 */
typedef enum
{
    UIEncoding_Encoding_Not_Specified = 0,
    UIEncoding_ASCII, ///< plain ASCII text
    UIEncoding_UTF8,  ///< text encoded in UTF-8
    UIEncoding_UTF16, ///< text encoded in UTF-16
    UIEncoding_UTF32  ///< text encoded in UTF-32
} TUIEncoding;

/**
 *  Typedef for text alignment type.
 *
 */

typedef enum
{
	AlignLeft = 0,
	AlignRight,
	AlignCenter,
	Alignment_LeftDynamic,
	Alignment_RightDynamic
} UITextAlignment_t;

typedef enum
{
    UIText_alignLeft,        ///< left aligned
    UIText_alignRight,       ///< center aligned
    UIText_alignCenter,      ///< right aligned
    UIText_alignLeftDynamic, ///< left aligned but first character can override
    UIText_alignRightDynamic ///< right aligned but first character can override
} TUITextAlignment;

/**
 *
 *  Typedef for text flow direction.
 */
typedef enum
{
    UITextDirection_Netural, ///< text with no inherent direction
    UITextDirection_LTR,     ///< left-to-right text
    UITextDirection_RTL      ///< right-to-left text
} TUITextDirection;

/**
 *
 *  Typedef for line spacing settings.
 *
 */
typedef enum
{
    UILineSpacing_Single_Line,        ///< single spacing
    UILineSpacing_150_Line,           ///< one and a half line spacing
    UILineSpacing_Double_Line,        ///< double spacing
    UILineSpacing_Exact_Line_Spacing, ///< line spacing set to lineSpacingAmount
    UILineSpacing_Multiple_Line       ///< line spacing set to multiple of line spacing * lineSpacingAmount
} TUILineSpacing;

/**
 *
 *  Typedef for line styles.
 */
typedef enum
{
    UILine_None,       ///< no line
    UILine_SingleSolid ///< single solid line
} TUILineStyle;

/**
 *
 *  A structure that defines inline image metrics needed for layout
 *
 */
typedef struct
{
    TFloat xAdvance;          ///< x-dimension advance width
    TFloat yAdvance;          ///< y-dimension advance width
    TUIRectangle boundingBox; ///< bounding box of image, with respect to its origin
} TUIInlineObjectMetrics;

typedef struct
{
    FSint32 numLines;          ///< number of lines in the layout
    FSint32 numContainersUsed; ///< number of containers actually used
    TUIRectangle boundingBox;  ///< text layout bounding box
    TUIRectangle advanceBox;   ///< text layout advance box
} TUILayoutInfo;

typedef struct
{
    FSint32 numLines;         ///< count of lines in the container
    FSint32 firstLineNumber;  ///< index of first line in container
    TUIRectangle boundingBox; ///< text container bounding box
    TUIRectangle advanceBox;  ///< text container advance box
} TUIContainerInfo;

typedef struct
{
    FSint32 numGlyphs;          ///< number of glyphs on the line
    FSint32 startIndex;         ///< IUIRichText character index of first character in line
    FSint32 endIndex;           ///< IUIRichText character index of last character in line
    TUIRectangle boundingBox;   ///< actual "inked" area of the line -- relative to line's origin
    TUIRectangle advanceBox;    ///< box spanning origin to next advance point -- relative to line's origin
    FUint8 bidiBaseLevel;       ///< bidi base level for line -- odd if Right-To-Left, even if Left-To-Right
    TUIPoint lineOrigin;        ///< absolute coordinates for line's origin, only meaningful if lineFlags has UI_LINE_DISPLAYED set
    FSint32 lineFlags;          ///< flags like UI_LINE_COMPOSED and UI_LINE_DISPLAYED
    FSint32 baseline;           ///< amount to add to lineOrigin.y to get baseline
    FSint32 top;                ///< amount to add to lineOrigin.y to get top of line (used for overline, and background color)
    FSint32 bottom;             ///< amount to add to lineOrigin.y to get bottom of line (used for background color)
    TUITextAlignment alignment; ///< alignment of line (UIText_alignLeft, UIText_alignRight, or UIText_alignCenter)
} TUILineInfo;

typedef struct
{
    FSint32 sourceIndex;      ///< character index in �UIRichText block
    FSint32 glyphID;          ///< glyph index in font
    TUIPosition x;            ///< the x coordinate relative to the line's origin
    TUIPosition y;            ///< the y coordinate relative to the line's origin
    TUIRectangle boundingBox; ///< bounding box relative to the glyph's position (x,y)
} TUIGlyphInfo;

// IUIRichTextLayoutOptions ----------------------------------------------------

typedef enum
{
    /* layout algorithm options */
    UIRichTextLayoutOptionsTag_Disable_BiDi,                              ///< Disables the bidirectional algorithm
    UIRichTextLayoutOptionsTag_Disable_Complex_Shaping,                   ///< Disables all complex shaping
    UIRichTextLayoutOptionsTag_Disable_Diacritics_Postitioning,           ///< Disables the diacritics positioning system
    UIRichTextLayoutOptionsTag_Disable_Normalization,                     ///< Disables Unicode text normalization
    UIRichTextLayoutOptionsTag_Disable_OpenType_Layout,                   ///< Disables OpenType layout table processing
    UIRichTextLayoutOptionsTag_Disable_Thai_Line_Breaking,                ///< Disables the Thai line breaking algorithm
    UIRichTextLayoutOptionsTag_Enable_Kerning,                            ///< Enables pairwise kerning if supported by font engine (not yet supported by layout engine)
    UIRichTextLayoutOptionsTag_Limit_Bounding_Box_To_Comp_Width,          ///< nsures that the text bounding box does not exceed the width of the text container
    UIRichTextLayoutOptionsTag_Enable_Forced_Monospace,                   ///< Enables forced monospace mode, for use in spacing grapheme choices for multi-tap input
    UIRichTextLayoutOptionsTag_Limit_Width_To_Longest_LineBreak_Sequence, /// z Limits composition width to that of longest linebreak sequence (for use in block layout mode only)

    /* substituion dictionaries */
    UIRichTextLayoutOptionsTag_Enable_Icons,            ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutControl)
    UIRichTextLayoutOptionsTag_Enable_Emoticons,        ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutControl)
    UIRichTextLayoutOptionsTag_Enable_Custom_Icons,     ///< Enable substitution dictionary Icons (owned by \ref IUIRichTextLayoutOptions)
    UIRichTextLayoutOptionsTag_Enable_Custom_Emoticons, ///< Enable substitution dictionary Emotcons (owned by \ref IUIRichTextLayoutOptions)

    /* Enable draw options - used for layout diagnostics */
    UIRichTextLayoutOptionsTag_Draw_Line_Advance_Box,      ///< For each text line draw a rectangle showing its advance box
    UIRichTextLayoutOptionsTag_Draw_Line_Bounding_Box,     ///< For each text line draw a rectangle showing the bounding box
    UIRichTextLayoutOptionsTag_Draw_Text_Direction,        ///< For each line draw the text baseline
    UIRichTextLayoutOptionsTag_Draw_Potential_Line_Breaks, ///< Draw a colored line indicating the text direction
    UIRichTextLayoutOptionsTag_Draw_Word_Boundaries,       ///< Draw a vertical line between graphemes where line breaks can occur
    UIRichTextLayoutOptionsTag_Draw_Shaping_Boundaries,    ///< Draw a vertical line at each word boundary
    UIRichTextLayoutOptionsTag_Draw_Baseline,              ///< Draw a vertical line at each shaping boundary
    UIRichTextLayoutOptionsTag_Draw_Text_Containers,       ///< Draw a rectangle at edge of text containers
    UIRichTextLayoutOptionsTag_Draw_Anchored_Objects       ///< Draw a rectangle at edge of anchored objects

} TUIRichTextLayoutOptionsTag;

typedef enum
{
    UIHighlight_ReverseVideoMode = 0, ///< selected text displayed reverse video
    UIHighlight_ColorMode,            ///< selected text displayed with user-specified colors
    UIHighlight_Disabled              ///< selected text displayed without highlighting
} TUIHighlightMode;

typedef enum
{
    UICustomDictionary_Icons = 0, ///< icons dictionary
    UICustomDictionary_Emoticons  ///< emoticons dictionary
} TUICustomDictionary;

typedef FUint32 TColour;
typedef FUint32 TUILineBreakModel;

#define UILineBreakBit_Use_Legal_Line_Break_If_Able 0x0001
#define UILineBreakBit_OK_To_Break_On_Grapheme 0x0002
#define UILineBreakBit_OK_To_Break_On_Glyph 0x0004
#define UILineBreakBit_Korean_Uses_East_Asian_Style 0x0008
#define UILineBreakBit_Wrap_WhiteSpaces 0x0010
#define UILineBreakBit_Hide_Initial_Wrapped_WhiteSpace 0x0020

// clang-format on

#endif
