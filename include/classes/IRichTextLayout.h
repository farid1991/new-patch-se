#ifndef _IUIRICHTEXTLAYOUT_H_
#define _IUIRICHTEXTLAYOUT_H_

#include <base.h>
#include <classes/IUnknown.h>

#include <types/Basic_types.h>
#include <types/OPA_types.h>
#include <types/UIRect_types.h>
#include <types/UIRichText_types.h>

class IRichText;

class IUIRichTextLayoutOptions : public IUnknown
{
public:
    virtual int Set(TUIRichTextLayoutOptionsTag tag, TBool value);
    virtual int SetLineBreakModel(TUILineBreakModel Model);
    virtual int SetTabStop(TFloat position, FUint8 alignment, FUint8 leader);
    virtual int ClearTabStop(char index);
    virtual int SetTabStopPositionDefault(TFloat pos);
    virtual int SetHyphenChar(FUint32 HyphenChar);
    virtual int SetTruncationChar(FUint32 TruncationChar);
    virtual int SetMonospaceMinPadding(TFloat minPadding);
    virtual int SetMonospaceMinWidth(TFloat minWidth);
    virtual int SetHighlightMode(TUIHighlightMode Mode);
    virtual int SetHighlightBackgroundColor(TColour Value);
    virtual int SetHighlightTextColor(TColour Value);
    virtual int Get(TUIRichTextLayoutOptionsTag tag, bool *pValue);
    virtual int GetLineBreakModel(TUILineBreakModel *pModel);
    virtual int GetTabStop(FUint8 index, TFloat *pPosition, FUint8 *pAlignment, FUint16 *pLeader);
    virtual int GetTabStopPositionDefault(TFloat *pPos);
    virtual int GetHyphenChar(FUint32 *pHyphenChar);
    virtual int GetTruncationChar(FUint32 *pTruncationChar);
    virtual int GetHighlightMode(TUIHighlightMode *pMode);
    virtual int GetHighlightBackgroundColor(TColour *pValue);
    virtual int GetHighlightTextColor(TColour *pValue);
    virtual int GetMonospaceMinPadding(TFloat *pMinPadding);
    virtual int GetMonospaceMinWidth(TFloat *pMinWidth);
    virtual int AddDictionary(TUICustomDictionary dictionary, IUnknown *pIFullPath);
    virtual int RemoveDictionary(TUICustomDictionary dictionary);
};

typedef enum
{
    UIRichTextLayoutControlTag_THA, ///< Thai
    UIRichTextLayoutControlTag_ICN, ///< Icons
    UIRichTextLayoutControlTag_EMOT ///< Emoticons
} TUIRichTextLayoutControlTag;

class IUIRichTextLayoutControl : public IUnknown
{
    virtual int AddDictionary(TUIRichTextLayoutControlTag tag, IUnknown *pIFullPath);
    virtual int RemoveDictionary(TUIRichTextLayoutControlTag tag);
};

class IRichTextLayout : public IUnknown
{
public:
    virtual int SetControl(IUIRichTextLayoutControl *pIUIRichTextLayoutControl);                                                                                                                        // 0x10
    virtual int GetControl(IUIRichTextLayoutControl **pIUIRichTextLayoutControl);                                                                                                                       // 0x14
    virtual int SetOptions(IUIRichTextLayoutOptions *pIUIRichTextLayoutOptions);                                                                                                                        // 0x18
    virtual int GetOptions(IUIRichTextLayoutOptions *pIUIRichTextLayoutOptions);                                                                                                                        // 0x1C
    virtual int Subscribe(void *pICBUIRichTextLayout, TMsgBase msgBase, TClientData clientData, THnd *pSubscriptionHandle);                                                                             // 0x20
    virtual int Unsubscribe(THnd SubscriptionHandle);                                                                                                                                                   // 0x24
    virtual int SetText(IRichText *pTextObject);                                                                                                                                                        // 0x28
    virtual int GetText(IRichText **pTextObject);                                                                                                                                                       // 0x2C
    virtual int Compose(TUIDimension lineWidth);                                                                                                                                                        // 0x30
    virtual int ComposeLine(TUIDimension lineWidth, TUIPosition ascenderLimit, TUIPosition descenderLimit, FSint32 lineNumber, FSint32 *pStartIndex, FSint32 *pEndIndex, FSint32 *pCharsLeftToCompose); // 0x34
    virtual int ComposeLineInit(FSint32 x, FSint32 y, FSint32 lineNumber);                                                                                                                              // 0x38
    virtual int PositionLine(FSint32 x, FSint32 y, FSint32 lineNumber);                                                                                                                                 // 0x3C
    virtual int ComposeContainers(TUIRectangle *pComposeRect);                                                                                                                                          // 0x40
    virtual int GetWidthOfLongestRemainingLineBreakSequence(TUIDimension *pWidth, FSint32 *pStartIndex, FSint32 *pEndIndex);                                                                            // 0x44
    virtual int GetLineInfo(FSint32 lineNumber, TUILineInfo *pInfo);                                                                                                                                    // 0x48
    virtual int MapCharIndex(FSint32 index, FSint32 *pLineNumber);                                                                                                                                      // 0x4C
    virtual int GetGlyphInfo(FSint32 lineNumber, FSint32 glyphIndex, TBool needBoundingBox, TUIGlyphInfo *pInfo);                                                                                       // 0x50
    virtual int GetNumberOfLines(FSint32 *pNumberOfLines);                                                                                                                                              // 0x54
    virtual int GetLayoutInfo(TUILayoutInfo *pLayoutInfo);                                                                                                                                              // 0x58
    virtual int GetContainerInfo(FSint32 containerIndex, TUIContainerInfo *pContainerInfo);                                                                                                             // 0x5C
    virtual int Display(IUnknown *pGC, FSint32 x, FSint32 y, TUIRectangle *pInvalidateRect);                                                                                                            // 0x60
    virtual int DisplayContainers(IUnknown *pGC, FSint32 x, FSint32 y, TUIRectangle *pInvalidateRect);                                                                                                  // 0x64
    virtual int DisplayLine(IUnknown *pGC, FSint32 x, FSint32 y, TUIRectangle *pInvalidateRect);                                                                                                        // 0x68
    virtual int AddTextContainer(IUnknown *pIUITextContainer, FSint32 containerID, TUIPoint *pContainerOrigin);                                                                                         // 0x6C
    virtual int RemoveTextContainer(FSint32 containerID);
};

#endif
