#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#endif

#include <libse.h>

/* ================= Colorspace  ================= */
static const char STR_COLORSPACE_SRGB[] = "sRGB";
static const char STR_COLORSPACE_ADOBE_RGB[] = "Adobe RGB";
static const char STR_COLORSPACE_WG_RGB[] = "Wide Gamut RGB";
static const char STR_COLORSPACE_ICCP[] = "ICC Profile";
static const char STR_COLORSPACE_UNCAL[] = "Uncalibrated";

/* ================= Contrast/Saturation ================= */
static const char STR_CONTRAST_LOW[] = "Low";
static const char STR_CONTRAST_HIGH[] = "High";
static const char STR_CONTRAST_NORMAL[] = "Normal";

/* ================= Custom Render =================  */
static const char STR_RENDER_CUSTOM[] = "Custom";
static const char STR_RENDER_HDR_NO_ORIG[] = "HDR (no original saved)";
static const char STR_RENDER_HDR_ORIG[] = "HDR (original saved)";
static const char STR_RENDER_ORIGINAL_HDR[] = "Original (for HDR)";
static const char STR_RENDER_PANORAMA[] = "Panorama";
static const char STR_RENDER_PORTRAIT_HDR[] = "Portrait HDR";
static const char STR_RENDER_PORTRAIT[] = "Portrait";
static const char STR_RENDER_NORMAL[] = "Normal";

/* ================= Exposure Mode ================= */

static const char STR_EXPMODE_AUTO[] = "Auto";
static const char STR_EXPMODE_MANUAL[] = "Manual";
static const char STR_EXPMODE_AUTO_BRACKET[] = "Auto bracket";

/* ================= Exposure Program ================= */

static const char STR_EXPPROG_MANUAL[] = "Manual";
static const char STR_EXPPROG_PROGRAM_AE[] = "Program AE";
static const char STR_EXPPROG_APERTURE[] = "Aperture-priority AE";
static const char STR_EXPPROG_SHUTTER[] = "Shutter speed priority AE";
static const char STR_EXPPROG_CREATIVE[] = "Creative (Slow speed)";
static const char STR_EXPPROG_ACTION[] = "Action (High speed)";
static const char STR_EXPPROG_PORTRAIT[] = "Portrait";
static const char STR_EXPPROG_LANDSCAPE[] = "Landscape";
static const char STR_EXPPROG_BULB[] = "Bulb";
static const char STR_EXPPROG_NOT_DEFINED[] = "Not Defined";

/* ================= Flash Mode ================= */

static const char STR_FLASH_FIRED[] =
    "Fired";
static const char STR_FLASH_FIRED_RET_NOT_DET[] =
    "Fired, Return not detected";
static const char STR_FLASH_FIRED_RET_DET[] =
    "Fired, Return detected";
static const char STR_FLASH_ON_NO_FIRE[] =
    "On, Did not fire";
static const char STR_FLASH_ON_FIRED[] =
    "On, Fired";
static const char STR_FLASH_ON_RET_NOT_DET[] =
    "On, Return not detected";
static const char STR_FLASH_ON_RET_DET[] =
    "On, Return detected";
static const char STR_FLASH_OFF_NO_FIRE[] =
    "Off, Did not fire";
static const char STR_FLASH_OFF_NO_FIRE_RET_NOT_DET[] =
    "Off, Did not fire, Return not detected";
static const char STR_FLASH_AUTO_NO_FIRE[] =
    "Auto, Did not fire";
static const char STR_FLASH_AUTO_FIRED[] =
    "Auto, Fired";
static const char STR_FLASH_AUTO_FIRED_RET_NOT_DET[] =
    "Auto, Fired, Return not detected";
static const char STR_FLASH_AUTO_FIRED_RET_DET[] =
    "Auto, Fired, Return detected";
static const char STR_FLASH_NO_FUNCTION[] =
    "No flash function";
static const char STR_FLASH_OFF_NO_FUNCTION[] =
    "Off, No flash function";
static const char STR_FLASH_FIRED_REDEYE[] =
    "Fired, Red-eye reduction";
static const char STR_FLASH_FIRED_REDEYE_RET_NOT_DET[] =
    "Fired, Red-eye reduction, Return not detected";
static const char STR_FLASH_FIRED_REDEYE_RET_DET[] =
    "Fired, Red-eye reduction, Return detected";
static const char STR_FLASH_ON_REDEYE[] =
    "On, Red-eye reduction";
static const char STR_FLASH_ON_REDEYE_RET_NOT_DET[] =
    "On, Red-eye reduction, Return not detected";
static const char STR_FLASH_ON_REDEYE_RET_DET[] =
    "On, Red-eye reduction, Return detected";
static const char STR_FLASH_OFF_REDEYE[] =
    "Off, Red-eye reduction";
static const char STR_FLASH_AUTO_NO_FIRE_REDEYE[] =
    "Auto, Did not fire, Red-eye reduction";
static const char STR_FLASH_AUTO_FIRED_REDEYE[] =
    "Auto, Fired, Red-eye reduction";
static const char STR_FLASH_AUTO_FIRED_REDEYE_RET_NOT_DET[] =
    "Auto, Fired, Red-eye reduction, Return not detected";
static const char STR_FLASH_AUTO_FIRED_REDEYE_RET_DET[] =
    "Auto, Fired, Red-eye reduction, Return detected";
static const char STR_FLASH_NO_FLASH[] =
    "No Flash";

/* ================= Light Source ================= */

static const char STR_LIGHT_DAYLIGHT[] = "Daylight";
static const char STR_LIGHT_FLUORESCENT[] = "Fluorescent";
static const char STR_LIGHT_TUNGSTEN[] = "Tungsten (Incandescent)";
static const char STR_LIGHT_FLASH[] = "Flash";
static const char STR_LIGHT_FINE_WEATHER[] = "Fine Weather";
static const char STR_LIGHT_CLOUDY[] = "Cloudy";
static const char STR_LIGHT_SHADE[] = "Shade";
static const char STR_LIGHT_DAYLIGHT_FLUO[] = "Daylight Fluorescent";
static const char STR_LIGHT_DAY_WHITE_FLUO[] = "Day White Fluorescent";
static const char STR_LIGHT_COOL_WHITE_FLUO[] = "Cool White Fluorescent";
static const char STR_LIGHT_WHITE_FLUO[] = "White Fluorescent";
static const char STR_LIGHT_WARM_WHITE_FLUO[] = "Warm White Fluorescent";
static const char STR_LIGHT_STD_A[] = "Standard Light A";
static const char STR_LIGHT_STD_B[] = "Standard Light B";
static const char STR_LIGHT_STD_C[] = "Standard Light C";
static const char STR_LIGHT_D55[] = "D55";
static const char STR_LIGHT_D65[] = "D65";
static const char STR_LIGHT_D75[] = "D75";
static const char STR_LIGHT_D50[] = "D50";
static const char STR_LIGHT_ISO_STUDIO[] = "ISO Studio Tungsten";

/* ================= Metering Mode ================= */

static const char STR_METER_UNKNOWN[] = "Unknown";
static const char STR_METER_AVERAGE[] = "Average";
static const char STR_METER_CENTER_WEIGHT[] = "Center-weighted average";
static const char STR_METER_SPOT[] = "Spot";
static const char STR_METER_MULTI_SPOT[] = "Multi-spot";
static const char STR_METER_MULTI_SEG[] = "Multi-segment";
static const char STR_METER_PARTIAL[] = "Partial";
static const char STR_METER_OTHER[] = "Other";

/* ================= Orientation ================= */

static const char STR_ORIENT_NORMAL[] = "Normal";
static const char STR_ORIENT_FLIP_H[] = "Flip Horizontal";
static const char STR_ORIENT_ROT_180[] = "Rotate 180";
static const char STR_ORIENT_FLIP_V[] = "Flip Vertical";
static const char STR_ORIENT_TRANSPOSE[] = "Transpose";
static const char STR_ORIENT_ROT_90_CW[] = "Rotate 90 CW";
static const char STR_ORIENT_TRANSVERSE[] = "Transverse";
static const char STR_ORIENT_ROT_90_CCW[] = "Rotate 90 CCW";

/* ================= Resolution Unit ================= */

static const char STR_RES_NONE[] = "none";
static const char STR_RES_INCH[] = "inches";
static const char STR_RES_CM[] = "cm";

/* ================= Sensing Method ================= */

static const char STR_SENSE_ONE_CHIP[] = "One-chip color area";
static const char STR_SENSE_TWO_CHIP[] = "Two-chip color area";
static const char STR_SENSE_THREE_CHIP[] = "Three-chip color area";
static const char STR_SENSE_SEQ_AREA[] = "Color sequential area";
static const char STR_SENSE_TRILINEAR[] = "Trilinear";
static const char STR_SENSE_SEQ_LINEAR[] = "Color sequential linear";
static const char STR_SENSE_NOT_DEFINED[] = "Not defined";

/* ================= Scene Capture ================= */

static const char STR_SCENE_STANDARD[] = "Standard";
static const char STR_SCENE_LANDSCAPE[] = "Landscape";
static const char STR_SCENE_PORTRAIT[] = "Portrait";
static const char STR_SCENE_NIGHT[] = "Night";
static const char STR_SCENE_OTHER[] = "Other";

/* ================= Sharpness ================= */

static const char STR_SHARP_SOFT[] = "Soft";
static const char STR_SHARP_HARD[] = "Hard";
static const char STR_SHARP_NORMAL[] = "Normal";

THUMB16 NEWCODE const char *get_colorspace(int color)
{
    switch (color)
    {
    case 1:
        return STR_COLORSPACE_SRGB;
    case 2:
        return STR_COLORSPACE_ADOBE_RGB;
    case 0xfffd:
        return STR_COLORSPACE_WG_RGB;
    case 0xfffe:
        return STR_COLORSPACE_ICCP;
    default:
        return STR_COLORSPACE_UNCAL;
    }
}

THUMB16 NEWCODE const char *get_contrast_saturation(int val)
{
    switch (val)
    {
    case 1:
        return STR_CONTRAST_LOW;
    case 2:
        return STR_CONTRAST_HIGH;
    default:
        return STR_CONTRAST_NORMAL;
    }
}

THUMB16 NEWCODE const char *get_custom_render(int render)
{
    switch (render)
    {
    case 1:
        return STR_RENDER_CUSTOM;
    case 2:
        return STR_RENDER_HDR_NO_ORIG;
    case 3:
        return STR_RENDER_HDR_ORIG;
    case 4:
        return STR_RENDER_ORIGINAL_HDR;
    case 6:
        return STR_RENDER_PANORAMA;
    case 7:
        return STR_RENDER_PORTRAIT_HDR;
    case 8:
        return STR_RENDER_PORTRAIT;
    default:
        return STR_RENDER_NORMAL;
    }
}

THUMB16 NEWCODE const char *get_exposure_mode(int mode)
{
    switch (mode)
    {
    case 0:
        return STR_EXPMODE_AUTO;
    case 1:
        return STR_EXPMODE_MANUAL;
    default:
        return STR_EXPMODE_AUTO_BRACKET;
    }
}

THUMB16 NEWCODE const char *get_exposure_program(int program)
{
    switch (program)
    {
    case 1:
        return STR_EXPPROG_MANUAL;
    case 2:
        return STR_EXPPROG_PROGRAM_AE;
    case 3:
        return STR_EXPPROG_APERTURE;
    case 4:
        return STR_EXPPROG_SHUTTER;
    case 5:
        return STR_EXPPROG_CREATIVE;
    case 6:
        return STR_EXPPROG_ACTION;
    case 7:
        return STR_EXPPROG_PORTRAIT;
    case 8:
        return STR_EXPPROG_LANDSCAPE;
    case 9:
        return STR_EXPPROG_BULB;
    default:
        return STR_EXPPROG_NOT_DEFINED;
    }
}

THUMB16 NEWCODE const char *get_flash_mode(int flash)
{
    switch (flash)
    {
    case 0x1:
        return STR_FLASH_FIRED;
    case 0x5:
        return STR_FLASH_FIRED_RET_NOT_DET;
    case 0x7:
        return STR_FLASH_FIRED_RET_DET;
    case 0x8:
        return STR_FLASH_ON_NO_FIRE;
    case 0x9:
        return STR_FLASH_ON_FIRED;
    case 0xd:
        return STR_FLASH_ON_RET_NOT_DET;
    case 0xf:
        return STR_FLASH_ON_RET_DET;
    case 0x10:
        return STR_FLASH_OFF_NO_FIRE;
    case 0x14:
        return STR_FLASH_OFF_NO_FIRE_RET_NOT_DET;
    case 0x18:
        return STR_FLASH_AUTO_NO_FIRE;
    case 0x19:
        return STR_FLASH_AUTO_FIRED;
    case 0x1d:
        return STR_FLASH_AUTO_FIRED_RET_NOT_DET;
    case 0x1f:
        return STR_FLASH_AUTO_FIRED_RET_DET;
    case 0x20:
        return STR_FLASH_NO_FUNCTION;
    case 0x30:
        return STR_FLASH_OFF_NO_FUNCTION;
    case 0x41:
        return STR_FLASH_FIRED_REDEYE;
    case 0x45:
        return STR_FLASH_FIRED_REDEYE_RET_NOT_DET;
    case 0x47:
        return STR_FLASH_FIRED_REDEYE_RET_DET;
    case 0x49:
        return STR_FLASH_ON_REDEYE;
    case 0x4d:
        return STR_FLASH_ON_REDEYE_RET_NOT_DET;
    case 0x4f:
        return STR_FLASH_ON_REDEYE_RET_DET;
    case 0x50:
        return STR_FLASH_OFF_REDEYE;
    case 0x58:
        return STR_FLASH_AUTO_NO_FIRE_REDEYE;
    case 0x59:
        return STR_FLASH_AUTO_FIRED_REDEYE;
    case 0x5d:
        return STR_FLASH_AUTO_FIRED_REDEYE_RET_NOT_DET;
    case 0x5f:
        return STR_FLASH_AUTO_FIRED_REDEYE_RET_DET;
    default:
        return STR_FLASH_NO_FLASH;
    }
}

THUMB16 NEWCODE const char *get_light_source(int light_source)
{
    switch (light_source)
    {
    case 0:
        return STR_METER_UNKNOWN;
    case 1:
        return STR_LIGHT_DAYLIGHT;
    case 2:
        return STR_LIGHT_FLUORESCENT;
    case 3:
        return STR_LIGHT_TUNGSTEN;
    case 4:
        return STR_LIGHT_FLASH;
    case 9:
        return STR_LIGHT_FINE_WEATHER;
    case 10:
        return STR_LIGHT_CLOUDY;
    case 11:
        return STR_LIGHT_SHADE;
    case 12:
        return STR_LIGHT_DAYLIGHT_FLUO;
    case 13:
        return STR_LIGHT_DAY_WHITE_FLUO;
    case 14:
        return STR_LIGHT_COOL_WHITE_FLUO;
    case 15:
        return STR_LIGHT_WHITE_FLUO;
    case 16:
        return STR_LIGHT_WARM_WHITE_FLUO;
    case 17:
        return STR_LIGHT_STD_A;
    case 18:
        return STR_LIGHT_STD_B;
    case 19:
        return STR_LIGHT_STD_C;
    case 20:
        return STR_LIGHT_D55;
    case 21:
        return STR_LIGHT_D65;
    case 22:
        return STR_LIGHT_D75;
    case 23:
        return STR_LIGHT_D50;
    case 24:
        return STR_LIGHT_ISO_STUDIO;
    default:
        return STR_METER_OTHER;
    }
}

THUMB16 NEWCODE const char *get_metering_mode(int mode)
{
    switch (mode)
    {
    case 0:
        return STR_METER_UNKNOWN;
    case 1:
        return STR_METER_AVERAGE;
    case 2:
        return STR_METER_CENTER_WEIGHT;
    case 3:
        return STR_METER_SPOT;
    case 4:
        return STR_METER_MULTI_SPOT;
    case 5:
        return STR_METER_MULTI_SEG;
    case 6:
        return STR_METER_PARTIAL;
    default:
        return STR_METER_OTHER;
    }
}

THUMB16 NEWCODE const char *get_orientation(int orientation)
{
    switch (orientation)
    {
    case 1:
        return STR_ORIENT_NORMAL;
    case 2:
        return STR_ORIENT_FLIP_H;
    case 3:
        return STR_ORIENT_ROT_180;
    case 4:
        return STR_ORIENT_FLIP_V;
    case 5:
        return STR_ORIENT_TRANSPOSE;
    case 6:
        return STR_ORIENT_ROT_90_CW;
    case 7:
        return STR_ORIENT_TRANSVERSE;
    case 8:
        return STR_ORIENT_ROT_90_CCW;
    default:
        return STR_METER_UNKNOWN;
    }
}

THUMB16 NEWCODE const char *get_resolution_unit(int unit)
{
    switch (unit)
    {
    case 1:
        return STR_RES_NONE;
    case 2:
        return STR_RES_INCH;
    default:
        return STR_RES_CM;
    }
}

THUMB16 NEWCODE const char *get_sensing(int sense)
{
    switch (sense)
    {
    case 2:
        return STR_SENSE_ONE_CHIP;
    case 3:
        return STR_SENSE_TWO_CHIP;
    case 4:
        return STR_SENSE_THREE_CHIP;
    case 5:
        return STR_SENSE_SEQ_AREA;
    case 7:
        return STR_SENSE_TRILINEAR;
    case 8:
        return STR_SENSE_SEQ_LINEAR;
    default:
        return STR_SENSE_NOT_DEFINED;
    }
}

THUMB16 NEWCODE const char *get_scene(int scene)
{
    switch (scene)
    {
    case 0:
        return STR_SCENE_STANDARD;
    case 1:
        return STR_SCENE_LANDSCAPE;
    case 2:
        return STR_SCENE_PORTRAIT;
    case 3:
        return STR_SCENE_NIGHT;
    default:
        return STR_SCENE_OTHER;
    }
}

THUMB16 NEWCODE const char *get_sharpness(int sharp)
{
    switch (sharp)
    {
    case 1:
        return STR_SHARP_SOFT;
    case 2:
        return STR_SHARP_HARD;
    default:
        return STR_SHARP_NORMAL;
    }
}