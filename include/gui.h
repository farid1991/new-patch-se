#ifndef GUI_H
#define GUI_H

#include <base.h>
#include <imageid.h>
#include <textid.h>

typedef enum UI_OverlayStyle_t
{
	UI_OverlayStyle_NotDefined = 0,
	UI_OverlayStyle_Default,			  // Use original frame settings
	UI_OverlayStyle_FullScreen,			  // Fullscreen
	UI_OverlayStyle_FullScreenNoStatus,	  // Fullscreen with no statusRow
	UI_OverlayStyle_TrueFullScreen,		  // True fullscreen without softkeys and statusrow
	UI_OverlayStyle_InternalFrameSmall,	  // Fullscreen with small internal frame
	UI_OverlayStyle_InternalFrameLarge,	  // Fullscreen with large internal frame
	UI_OverlayStyle_InternalFrameOutput,  // Informationtext style
	UI_OverlayStyle_PopupFrame,			  // Popup with SW rendered frame
	UI_OverlayStyle_PopupNoFrame,		  // Transparent popup window. Default popup style.
	UI_OverlayStyle_FullScreenNoSoftkeys, // Fullscreen without softkeys but with status row
	UI_OverlayStyle_Last
} UI_OverlayStyle_t;

typedef enum UI_TitleMode_t
{
	UI_TitleMode_Uninitated = 0, // Uninitiated
	UI_TitleMode_None,			 // Show no title
	UI_TitleMode_Normal,		 // Normal title size
	UI_TitleMode_Small,			 // Small title
	UI_TitleMode_Tab,			 // Show tabs instead of title.
	UI_TitleMode_Large,			 // Large two row title( different fonts for 1:st and 2:nd line )
	UI_TitleMode_Desktop,		 // Only for desktop title. Will be removed after hb107.
	UI_TitleMode_Last
} UI_TitleMode_t;

// GUIObject_SetZOrder
typedef enum GuiObjectZOrder_t
{
	GuiObjectZOrderAbove = 0, ///< Sets the GUI Z-order to Above
	GuiObjectZOrderBelow,	  ///< Sets the GUI Z-order to Below
	GuiObjectZOrderTop,		  ///< Sets the GUI Z-order to Top
	GuiObjectZOrderBottom,	  ///< Sets the GUI Z-order to Bottom
} GuiObjectZOrder_t;

/**
 * Display
 *
 * @param UIDisplay_Main    Main display
 * @param UIDisplay_Second  Second display. Used on clam phones
 * @param UIDisplay_Last    End
 */
typedef enum UI_Display_t
{
	UIDisplay_Main = 0,
	UIDisplay_Second,
	UIDisplay_TVOut,
	UIDisplay_Last
} UI_Display_t;

/**
 * Backlight mode.
 *
 * @param UIBacklightMode_On        Always on
 * @param UIBacklightMode_Off       Always off
 * @param UIBacklightMode_Automatic Automatic
 * @param UIBacklightMode_LowOff    Automatic with low instead of off
 * @param UIBacklightMode_LowOn     Automatic with low instead of on
 */
typedef enum
{
	UIBacklightMode_On,
	UIBacklightMode_Off,
	UIBacklightMode_Automatic,
	UIBacklightMode_LowOff,
	UIBacklightMode_LowOn
} UIBacklightMode_t;

/**
 * Backlight status.
 *
 * @param UIBacklightStatus_On    Backlight is on
 * @param UIBacklightStatus_Off   Backlight is off
 * @param UIBacklightStatus_Blink Backlight is blinking
 * @param UIBacklightStatus_Low   Backlight is on with low intensity
 */
typedef enum
{
	UIBacklightStatus_On,
	UIBacklightStatus_Off,
	UIBacklightStatus_Blink,
	UIBacklightStatus_Low
} UIBacklightStatus_t;

/**
 * Display Orientation
 *
 * @param UIDisplayOrientationMode_Vertical           Vertical orientation
 * @param UIDisplayOrientationMode_Horizontal         Horizontal orientation
 * @param UIDisplayOrientationMode_HorizontalReversed Reversed horizontal orientation
 * @param UIDisplayOrientationMode_Last               End
 */
typedef enum
{
	UIDisplayOrientationMode_Vertical = 0,
	UIDisplayOrientationMode_Horizontal,
	UIDisplayOrientationMode_HorizontalReversed,
	UIDisplayOrientationMode_Last
} UIDisplayOrientationMode_t;

typedef struct GUI
{
    char dummy[0x90];
} GUI;


#endif // GUI_H