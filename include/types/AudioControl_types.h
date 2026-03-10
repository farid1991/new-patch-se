#ifndef __AUDIOCONTROL_TYPES_H__
#define __AUDIOCONTROL_TYPES_H__

#include <types/Basic_types.h>

// clang-format off

#define MAX_MEDIAVOLUME 15
#define MAX_CALLVOLUME 8
#define MAX_RINGVOLUME 8

// P10C fixes
typedef enum
{
    AUDIO_CHANNEL_SAMPLE_RATE_8_KHZ,
    AUDIO_CHANNEL_SAMPLE_RATE_16_KHZ,
    AUDIO_CHANNEL_SAMPLE_RATE_44_1_KHZ,
    AUDIO_CHANNEL_SAMPLE_RATE_48_KHZ,
    AUDIO_CHANNEL_SAMPLE_RATE_UNSPECIFIED,

    AUDIO_CHANNEL_SAMPLE_RATE_LAST
} TAudioChannelSampleRate;
// P10C end ----

/**
 * @brief Return codes that can be sent from AudioControl
 *
 */
typedef enum
{
    AUDIOCONTROL_UED_GENERAL_ERROR = 0x000, /**< Returned when none of the other error codes are applicable */

    /* AudioPlayer specific return values */
    AUDIOCONTROL_UED_NOT_AUTHORIZED = 0x001, /**< Returned when there are not any available resources, and another ongoing activity has higher priority */
    AUDIOCONTROL_UED_FILE_NOT_FOUND = 0x002, /**< Returned when the specified file is not found */
    AUDIOCONTROL_UED_DRM_ERROR = 0x004,      /**< Returned when the specified file is a DRM file, and the credentials not allows playback */

    /* Internal ac channel return value */
    AUDIOCONTROL_UED_ROUTED_TO_SILENT = 0x008, /**< Returned when no channel delivered due to internal channelsetting
                                                    AUDIOCONTROL_CHANNELSETTING_NO_CHANNEL_IF_SILENT  */

    /* Accessory specific return values */
    AUDIOCONTROL_UED_NO_SUCH_DEVICE = 0x010, /**< Unknown accessory */

    /* General return values, used for all categories */
    AUDIOCONTROL_UED_NOT_SUPPORTED = 0x020,    /**< Returned when some functionality not is supported with the current platform configuration */
    AUDIOCONTROL_UED_OPA_ERROR = 0x040,        /**< Returned when OPA is returning an error of unknown reason */
    AUDIOCONTROL_UED_OUT_OF_MEMORY = 0x080,    /**< Returned when some allocation failed due to lack of memory */
    AUDIOCONTROL_UED_INPUT_PARAM_ERROR = 0x100 /**< Returned when there was some error in the input parameters */
} TAudioControl_ReturnValues;

/**
 * @brief The general handle type for Audio Control
 *
 */
typedef FUint32 TAudioControl_Handle;

/**
 * @brief The handle is not used
 *
 */
#define AUDIOCONTROL_HANDLE_NOT_USED 0

/**
 * @brief Old obsolete handle name
 *
 */
typedef FUint32 TAudioControl_SessionId;

/**
 * @brief Old obsolete. The session identifier is not used
 *
 */
#define AUDIOCONTROL_SESSIONID_NOT_USED 0

/**
 * @brief The request that can be sent from an accessory
 *        Used in Accessory_Request
 *
 * @see IAudioControl::Accessory_Attach4
 *
 */
typedef enum
{
    AUDIOCONTROL_ACCESSORY_REQUEST_AUDIO, /**< The accessory will be considered eligible for audio routing */
    AUDIOCONTROL_ACCESSORY_RELEASE_AUDIO  /**< The accessory will lose Audio and will not be routed audio */
} TAudioControl_AccessoryRequest;

/**
 * @brief The audio_class used in accessory_attach
 *
 * This is the audio_class in the SEAUDIO AT command, see http://spec.sonyericsson.net/pages/at/
 *
 * Also see document # 40/159 35-FCP 101 1989
 * http://METADOC.SONYERICSSON.NET//login_link.asp?DOC_NUMBER=40/15935-FCP1011989Uen&LINK_TO=OfficialRev&CLASS=r1AbcDoc&OBID=ojji15kldpdm0sumti%2D%2D%2DgLT&DBNAME=sumti&FILECLASS=WordDoc&SECCLASS=
 */
typedef enum
{
    // Ordinary accessories
    AUDIOCONTROL_ACCESSORYCLASS_NONE = 0,  /**< No audio capabilities */
    AUDIOCONTROL_ACCESSORYCLASS_PHF = 1,   /**< PHF - Portable Hands Free */
    AUDIOCONTROL_ACCESSORYCLASS_VHF = 2,   /**< VHF - Vehicle Hands Free */
    AUDIOCONTROL_ACCESSORYCLASS_BVHF = 3,  /**< BVHF - Budget Vehicle Hands Free (using phone mic) */
    AUDIOCONTROL_ACCESSORYCLASS_BT = 4,    /**< BT - Bluetooth Headset or Handsfree */
    AUDIOCONTROL_ACCESSORYCLASS_BTC = 5,   /**< BT Car HF - Bluetooth Car Handsfree */
    AUDIOCONTROL_ACCESSORYCLASS_BTL = 6,   /**< Bluetooth leisure headset supporting A2DP profile (like streaming mp3, currently not supported) */
    AUDIOCONTROL_ACCESSORYCLASS_DSS = 9,   /**< Desk speaker Stand */
    AUDIOCONTROL_ACCESSORYCLASS_BDSS = 10, /**< Budget Desk speaker Stand (using phone mic) */
    AUDIOCONTROL_ACCESSORYCLASS_LOA = 11,  /**< Line out signal that uses phone volume and settings*/
    AUDIOCONTROL_ACCESSORYCLASS_LI = 12,   /**< Line in */
    AUDIOCONTROL_ACCESSORYCLASS_LO = 13,   /**< Line out - flat signal */
    AUDIOCONTROL_ACCESSORYCLASS_HEADPHONE,

    // Virtual accessories (for internal Audio Control use only)
    AUDIOCONTROL_ACCESSORY_VIRTUAL_SPEAKER_CLOSED,  /**< Virtual speaker closed accessory (e.g. clam closed, jack closed, etc), only for internal Audio Control use */
    AUDIOCONTROL_ACCESSORY_VIRTUAL_EARPIECE_CLOSED, /**< Virtual earpiece closed accessory (e.g. clam closed, jack closed, etc), only for internal Audio Control use */
    AUDIOCONTROL_ACCESSORY_VIRTUAL_SPEAKER,         /**< Virtual speaker accessory, only for internal Audio Control use */
    AUDIOCONTROL_ACCESSORY_VIRTUAL_EARPIECE,        /**< Virtual earpiece accessory, only for internal Audio Control use */
    AUDIOCONTROL_ACCESSORY_VIRTUAL_SILENT,          /**< Virtual silent accessory, only for internal Audio Control use */
    AUDIOCONTROL_ACCESSORY_VIRTUAL_FMTX,            /**< FM Transmitter */

    // Last enum
    AUDIOCONTROL_ACCESSORYCLASS_LAST /**< Last accessory, only for internal Audio Control use */
} TAudioControl_AccessoryClass;

/**
 * @brief The audio_id used in accessory attach.
 *
 * This is the audio_id in the SEAUDIO AT command, see http://spec.sonyericsson.net/pages/at/
 * or http://spec.sonyericsson.net/pages/at/AT_cmd_specs/03-SI%20S35.htm
 *
 * Also see document # 40/159 35-FCP 101 1989
 *
 * For "dumb" accesories, see 14/159 35-FCP 101 1989. These are identified by a resistor value
 * and mapped to correct ID.
 *
 * Some Bluetooth accessories dont send this, they are identified by a string and mapped to correct id.
 */
typedef enum
{
    AUDIOCONTROL_ACCESSORYID_UNKNOWN = 0, /**< No audio capabilities */

    // Resitive identified:
    AUDIOCONTROL_ACCESSORYID_PHF_CLASS1 = 1,
    AUDIOCONTROL_ACCESSORYID_PHF_CLASS2 = 2,
    AUDIOCONTROL_ACCESSORYID_PHF_CLASS3 = 3,
    AUDIOCONTROL_ACCESSORYID_PHF_CLASS4 = 4,
    AUDIOCONTROL_ACCESSORYID_LINE_IN = 5,
    AUDIOCONTROL_ACCESSORYID_LINE_OUT = 6,
    AUDIOCONTROL_ACCESSORYID_BT_HEADSET = 7,
    AUDIOCONTROL_ACCESSORYID_BT_HANDSFREE = 8,
    AUDIOCONTROL_ACCESSORYID_LINE_OUT_ADJUSTABLE = 9,

    // 3.5 mm jack
    AUDIOCONTROL_ACCESSORYID_PHF_35MM_STEREO_JACK,
    AUDIOCONTROL_ACCESSORYID_HP_35MM_STEREO_JACK,
    AUDIOCONTROL_ACCESSORYID_LO_35MM_STEREO_JACK,
    AUDIOCONTROL_ACCESSORYID_LI_35MM_STEREO_JACK,

    // 1000-1999 PHF - Portable Hands Frees

    AUDIOCONTROL_ACCESSORYID_PHF_HPM_80 = 1001, /**< Accessory id for Remo (Fm radio PHF with remotecontrol and FM radio for Sakura) */
    AUDIOCONTROL_ACCESSORYID_PHF_HPM_82 = 1002, /**< Accessory id for Barret (PHF with remote control)*/

    // 2000-2999 VHF - Vehicle handsfrees
    AUDIOCONTROL_ACCESSORYID_VHF_HCA_60 = 2001, /**< Advanced Vehicle handsfree ("Pooh", "HCA-60") Speech and music in mono speaker */
    AUDIOCONTROL_ACCESSORYID_VHF_HCE_60 = 2002, /**< Advanced Vehicle handsfree ("Pooh", "HCA-60") Speech and music in car stereo speakers*/

    AUDIOCONTROL_ACCESSORYID_PEIKER = 2500,       /**< BMW car kit with no internal EC nor NC */
    AUDIOCONTROL_ACCESSORYID_PEIKER_EC_NR = 2501, /**< BMW car kit with internal EC and NC */

    // 3000-3999 BVHF - Budget Vehicle Hands Free (without accessory mic)
    AUDIOCONTROL_ACCESSORYID_BVHF_HCQ_60 = 3001, /**< HCQ-60, "Tiger" */

    // 4000-4999 BT - Bluetooth Headset, or Handsfree
    AUDIOCONTROL_ACCESSORYID_BT_HBH_10 = 4001,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_15 = 4002,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_20 = 4003,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_200 = 4004,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_30 = 4005,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_300 = 4006,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_35 = 4007,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_60 = 4008,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_600 = 4009,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_605 = 4010,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_65 = 4011,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_660 = 4012,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_670 = 4013,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_610 = 4014,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_620 = 4015,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_662 = 4016,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_602 = 4017,
    AUDIOCONTROL_ACCESSORYID_BT_HBM_30 = 4018,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_608 = 4021,
    AUDIOCONTROL_ACCESSORYID_BT_HBH_PV705 = 4022,
    AUDIOCONTROL_ACCESSORYID_BT_MOTO_T305 = 4600, /**< Accessory id for Motorola T305, see DMS00384781. */
    AUDIOCONTROL_ACCESSORYID_BT_DSP = 4999,       /**< Accessory id for BT headsets with internal DSP. */

    // 5000-5999 BTC - Bluetooth Handsfree for installation in car.
    AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_30 = 5001,
    AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_300 = 5002,
    AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_400 = 5003,
    AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_700 = 5004,
    AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_610 = 5005,
    AUDIOCONTROL_ACCESSORYID_BTVHF_HCB_100 = 5006,

    // 6000-6999 BTL - Bluetooth Leisure (BT headset supporting the Advanced Audio Distribution Profile)
    // 7000-7999 BTBTL - A Bluetooth audio device supporting the Headset or the Handsfree profile and the Advanced Audio Distributionprofile.
    AUDIOCONTROL_ACCESSORYID_BTBTL_HBH_DS970 = 7001, // A.k.a "Hippix"

    // 8000-8999 BTBTLC - A Bluetooth audio device supporting the Headset or the Handsfree profile and the Advanced Audio Distributionprofile for installation in car.
    // 9000-9999 DSS - Desk Speaker Stand
    // 10000-10999 BDSS - Budget Desk Speaker Stand

    // 11000-11999 LO - Line out accesory
    AUDIOCONTROL_ACCESSORYID_MMR_60 = 11001, // Wadner

    // 12000-12999 LI - Line in accesory

    // Last accessory
    AUDIOCONTROL_ACCESSORYID_LAST /**< Last accessory id, only for internal Audio Control use*/
} TAudioControl_AccessoryId;

/**
 * @brief The accessory-events that can be subscribed to.
 *        Used in IAudioControl_Accessory_SubscribeToEvents
 *
 * The events types are encoded as bitmaps.
 * The event AUDIOCONTROL_ACCESSORY_EVENT_ONSPEAKERMODECHANGED shall be coordinated with AUDIOCONTROL_EVENT_ONSPEAKERMODECHANGED.
 *
 * @see IAudioControl::Accessory_SubscribeToEvents
 */
typedef enum
{
    AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYCHANGED = 0x0001,           /**< Event when the active accessory is changed, the active accessory is the accessory that currently has audio routed to */
    AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYMUTE = 0x0002,              /**< Event when the accessory is to bemuted */
    AUDIOCONTROL_ACCESSORY_EVENT_ONACCESSORYCALLVOLUMECHANGED = 0x0004, /**< Event when the the call volume is changed */
    AUDIOCONTROL_ACCESSORY_EVENT_ONREQUIRECCO = 0x0008,                 /**< Obsolete */
    AUDIOCONTROL_ACCESSORY_EVENT_ONVOLUMECHANGED = 0x0010,              /**< Event sent when volume changes*/
    AUDIOCONTROL_ACCESSORY_EVENT_ONSESSIONBEGIN = 0x0020,               /**< Event when a session is started
                                                                             ICBAudioControl::OnSessionBegin */
    AUDIOCONTROL_ACCESSORY_EVENT_ONSPEAKERMODECHANGED = 0x0040,         /**< Event when the speakermode changes. */
    AUDIOCONTROL_ACCESSORY_EVENT_ONSESSIONEND = 0x0080,                 /**< Event when a session is ended
                                                                             ICBAudioControl::OnSessionEnd */
    AUDIOCONTROL_ACCESSORY_EVENT_ONMICROPHONEMUTECHANGED = 0x0100,      /**< Event when the microphone is muted. */
    AUDIOCONTROL_ACCESSORY_EVENT_ONFMTXCHANGED = 0x0200,                /**< Event when fm transmitter is disabled/enabled */
    AUDIOCONTROL_ACCESSORY_EVENT_ALL_EVENTS = 0xFFFF                    /**< All events */
} TAudioControl_AccessoryEvents;

/**
 *  @brief Accessory settings, attributes that can be set on accessories.
 *  Mostly used by BT.
 */
typedef enum
{
    AUDIOCONTROL_ACCESSORYSETTING_NONE = 0x0000,                                 /**< No accessory settings */
    AUDIOCONTROL_ACCESSORYSETTING_BT_REQUIRE_ACK = 0x0001,                       /**< Accessory is BT and requires a ACK when connecting and disconnecting.*/
    AUDIOCONTROL_ACCESSORYSETTING_BT_CAPTURE_BIT_ENABLED = 0x0002,               /**< */
    AUDIOCONTROL_ACCESSORYSETTING_VOLUME_SYNCHRONIZATION_NOT_SUPPORTED = 0x0004, /**< Accessory don't support volume changes, no volume ui will be shown.*/
    AUDIOCONTROL_ACCESSORYSETTING_VOICE_RECOGNITION_NOT_SUPPORTED = 0x0008       /**< Accessory don't support voice recognition, use internal mic/speaker instead.*/
} TAudioControl_AccessorySetting;

/**
 * @brief Audiocontrol events used in IAudioControl_Subscribe
 *
 * @see IAudioControl::Subscribe
 */
typedef enum
{
    AUDIOCONTROL_EVENT_NONE = 0x0000,
    AUDIOCONTROL_EVENT_ONSPEAKERMODECHANGED = 0x0040,    /**< Event when the speaker mode has changed. */
    AUDIOCONTROL_EVENT_ONMICROPHONEMUTECHANGED = 0x0100, /**< Event when the microphone is muted. */
    AUDIOCONTROL_EVENT_ONFMTXCHANGED = 0x0200            /**< Event when fm transmitter is disabled/enabled */
} TAudioControl_Events;

/**
 * @brief The Ericsson Music Mute state corresponding to the *EMIV response command
 */
typedef enum
{
    AUDIOCONTROL_MUSIC_MUTE_STATE_SPEECH, /**< The Ericsson Music Mute Indication Response Parameter for Speech */
    AUDIOCONTROL_MUSIC_MUTE_STATE_MEDIA   /**< The Ericsson Music Mute Indication Response Parameter for Media */
} TAudioControl_MusicMuteState;

/**
 * @brief The speakertypes that can be tested with IAudioControl::ServiceMenu_SpeakerTest_Play.
 *
 */
typedef enum
{
    AUDIOCONTROL_SPEAKERTYPE_EARPIECE, /**< The earpiece speaker */
    AUDIOCONTROL_SPEAKERTYPE_SPEAKER,  /**< The builtin speaker */
    AUDIOCONTROL_SPEAKERTYPE_AUTO      /**< Automatically choose speaker */
} TAudioControl_SpeakerType;

/**
 * @brief The different notification types
 * Keep order with AC_Notifications in ac_notification.c
 */
typedef enum
{
    AUDIOCONTROL_NOTIFICATION_RINGER,
    AUDIOCONTROL_NOTIFICATION_ALARM,
    AUDIOCONTROL_NOTIFICATION_REQUEST,
    AUDIOCONTROL_NOTIFICATION_REQUEST_CALL,
    AUDIOCONTROL_NOTIFICATION_SUCCESS,
    AUDIOCONTROL_NOTIFICATION_FAILURE,
    AUDIOCONTROL_NOTIFICATION_PROGRESS,
    AUDIOCONTROL_NOTIFICATION_NOTIFICATION,
    AUDIOCONTROL_NOTIFICATION_REMINDER,
    AUDIOCONTROL_NOTIFICATION_DISCONNECTED,
    AUDIOCONTROL_NOTIFICATION_DISCREET,
    AUDIOCONTROL_NOTIFICATION_LOWBATTERY,
    AUDIOCONTROL_NOTIFICATION_EMPTYBATTERY,
    AUDIOCONTROL_NOTIFICATION_CHARGING,
    AUDIOCONTROL_NOTIFICATION_VIDEO,
    AUDIOCONTROL_NOTIFICATION_RETRYSUCCESS,
    AUDIOCONTROL_NOTIFICATION_TIMER,
    AUDIOCONTROL_NOTIFICATION_MESSAGEALERT_SILENT,
    AUDIOCONTROL_NOTIFICATION_MESSAGECLICK,
    AUDIOCONTROL_NOTIFICATION_MESSAGEALERT1,
    AUDIOCONTROL_NOTIFICATION_MESSAGEALERT2,
    AUDIOCONTROL_NOTIFICATION_MESSAGEALERT3,
    AUDIOCONTROL_NOTIFICATION_MESSAGEALERT4,
    AUDIOCONTROL_NOTIFICATION_MESSAGEALERT5,
    AUDIOCONTROL_NOTIFICATION_MESSAGEALERT6,

    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER,
    AUDIOCONTROL_NOTIFICATION_CAMERATIMER,
    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER2,
    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER3,
    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER4,
    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER_RER,
    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER2_RER,
    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER3_RER,
    AUDIOCONTROL_NOTIFICATION_CAMERASHUTTER4_RER,
    AUDIOCONTROL_NOTIFICATION_CAMERA_FOCUS_SUCCESS,
    AUDIOCONTROL_NOTIFICATION_CAMERA_BURST,
    AUDIOCONTROL_NOTIFICATION_CAMERA_BESTPIC,

    AUDIOCONTROL_NOTIFICATION_PTT_BUDDY_JOINED,
    AUDIOCONTROL_NOTIFICATION_PTT_BUDDY_LEFT,
    AUDIOCONTROL_NOTIFICATION_PTT_FLOOR_AVAILABLE,
    AUDIOCONTROL_NOTIFICATION_PTT_SPEAK_NOW,
    AUDIOCONTROL_NOTIFICATION_PTT_RINGTONE,
    AUDIOCONTROL_NOTIFICATION_PTT_BARGE_ALERT,
    AUDIOCONTROL_NOTIFICATION_PTT_FLOOR_TAKEN,

    AUDIOCONTROL_NOTIFICATION_SPORT_ABOVE_SPEED,
    AUDIOCONTROL_NOTIFICATION_SPORT_BELOW_SPEED,
    AUDIOCONTROL_NOTIFICATION_SPORT_START,
    AUDIOCONTROL_NOTIFICATION_SPORT_MILESTONE,
    AUDIOCONTROL_NOTIFICATION_SPORT_END,
    AUDIOCONTROL_NOTIFICATION_SPORT_FAILURE,

    AUDIOCONTROL_NOTIFICATION_IM_BUDDY_JOINED,
    AUDIOCONTROL_NOTIFICATION_IM_BUDDY_LEFT,

    AUDIOCONTROL_NOTIFICATION_PHONE_OPEN1,
    AUDIOCONTROL_NOTIFICATION_PHONE_OPEN2,
    AUDIOCONTROL_NOTIFICATION_PHONE_OPEN3,

    AUDIOCONTROL_NOTIFICATION_VIDEOCALLPREFIX,

    AUDIOCONTROL_NOTIFICATION_CALLERNAME,

    AUDIOCONTROL_NOTIFICATION_STARTUP,

    AUDIOCONTROL_NOTIFICATION_ILM_MTCALL,
    AUDIOCONTROL_NOTIFICATION_ILM_ALARM,
    AUDIOCONTROL_NOTIFICATION_ILM_MESSAGING,
    AUDIOCONTROL_NOTIFICATION_ILM_TIMER,
    AUDIOCONTROL_NOTIFICATION_ILM_CALEVENT,
    AUDIOCONTROL_NOTIFICATION_ILM_TEST,
    AUDIOCONTROL_NOTIFICATION_ILM_DEMO,
    AUDIOCONTROL_NOTIFICATION_ILM_INTRO,
    AUDIOCONTROL_NOTIFICATION_ILM_ACCESSORY,
    AUDIOCONTROL_NOTIFICATION_ILM_CHARGEBATT,
    AUDIOCONTROL_NOTIFICATION_ILM_PREVIEW,
    AUDIOCONTROL_NOTIFICATION_ILM_POWERUP,
    AUDIOCONTROL_NOTIFICATION_ILM_POWERDOWN,
    AUDIOCONTROL_NOTIFICATION_ILM_OPENFLIP,
    AUDIOCONTROL_NOTIFICATION_ILM_CLOSEFLIP,
    AUDIOCONTROL_NOTIFICATION_ILM_STARTSLEEP,
    AUDIOCONTROL_NOTIFICATION_ILM_ENDSLEEP,

    AUDIOCONTROL_NOTIFICATION_VT_SNAPSHOT,

    AUDIOCONTROL_NOTIFICATION_VC_FAILURE,
    AUDIOCONTROL_NOTIFICATION_VC_VOICETAG,

    AUDIOCONTROL_NOTIFICATION_MAM_GUIDANCE,

    AUDIOCONTROL_NOTIFICATION_LAST
} TAudioControl_Notification;

/**
 * @brief The different redirections a tone playback can have.
 *
 * @note AUDIOCONTROL_TONE_REDIRECTION_NEAR_AND_FAR_END is only valid during
 *       calls.
 */
typedef enum
{
    AUDIOCONTROL_TONE_REDIRECTION_NEAR_END,         /**< The tone is played in the speaker */
    AUDIOCONTROL_TONE_REDIRECTION_NEAR_AND_FAR_END, /**< The tone is played in the speaker and is also sent to the remote party */
    AUDIOCONTROL_TONE_REDIRECTION_LAST
} TAudioControl_ToneRedirection;

/**
 * @ingroup AC
 * @brief The different tonetypes that can be played
 */
typedef enum
{
    /* Normal Tones, such as DTMF etc. They are directly mapped from OPA, see TTone in IToneManager.idl for more info */
    AUDIOCONTROL_TONE_OFF,
    AUDIOCONTROL_TONE_KEY_1,
    AUDIOCONTROL_TONE_KEY_2,
    AUDIOCONTROL_TONE_KEY_3,
    AUDIOCONTROL_TONE_KEY_4,
    AUDIOCONTROL_TONE_KEY_5,
    AUDIOCONTROL_TONE_KEY_6,
    AUDIOCONTROL_TONE_KEY_7,
    AUDIOCONTROL_TONE_KEY_8,
    AUDIOCONTROL_TONE_KEY_9,
    AUDIOCONTROL_TONE_KEY_0,
    AUDIOCONTROL_TONE_KEY_ASTERISK,
    AUDIOCONTROL_TONE_KEY_NUMBERSIGN,
    AUDIOCONTROL_TONE_KEY_A,
    AUDIOCONTROL_TONE_KEY_B,
    AUDIOCONTROL_TONE_KEY_C,
    AUDIOCONTROL_TONE_KEY_D,
    AUDIOCONTROL_TONE_SILENCE,
    AUDIOCONTROL_RING_TONE,
    AUDIOCONTROL_TRIPLE_TONE_950_HZ,
    AUDIOCONTROL_TRIPLE_TONE_1400_HZ,
    AUDIOCONTROL_TRIPLE_TONE_1800_HZ,
    AUDIOCONTROL_RING_TONE_500_HZ,
    AUDIOCONTROL_RING_TONE_1056_HZ,
    AUDIOCONTROL_RING_TONE_1750_HZ,
    AUDIOCONTROL_RING_TONE_1900_HZ,
    AUDIOCONTROL_RING_TONE_2000_HZ,
    AUDIOCONTROL_RING_TONE_2200_HZ,
    AUDIOCONTROL_RING_TONE_2800_HZ,
    AUDIOCONTROL_RING_TONE_480_620_HZ,
    AUDIOCONTROL_RING_TONE_440_HZ,
    AUDIOCONTROL_RING_TONE_440_480_HZ,

    /* Comfort Tones, directly mapped from OPA */
    AUDIOCONTROL_DIAL,                      /**< 425Hz continuous */
    AUDIOCONTROL_SUBSCRIBER_BUSY,           /**< 425Hz on 500ms, off 500ms continuous */
    AUDIOCONTROL_CONGESTION,                /**< 425Hz on 200ms, off 200ms continuous */
    AUDIOCONTROL_RADIO_PATH_ACKNOWLEDGE,    /**< 425Hz single tone 200ms */
    AUDIOCONTROL_RADIO_PATH_NOT_AVAILABLE,  /**< 425Hz 200ms on/off for 3 burst */
    AUDIOCONTROL_ERROR_SPECIAL_INFORMATION, /**< 950Hz, 1400Hz and 1800Hz triple tone, on 330ms, off 1s continuous */
    AUDIOCONTROL_CALL_WAITING,              /**< 425Hz on 200ms, off 600ms, on 200ms, off 3s continuous */
    AUDIOCONTROL_RINGING,                   /**< 425Hz on 1s, off 4s continuous */

    /* SAT Tones */
    AUDIOCONTROL_SAT_POSITIVEACK,
    AUDIOCONTROL_SAT_NEGATIVEACK,
    AUDIOCONTROL_SAT_GENERALBEEP,

    AUDIOCONTROL_TONE_LAST
} TAudioControl_Tone;

/**
 * @brief The different keysounds that can be played
 */
typedef enum
{
    AUDIOCONTROL_KEYSOUND_CLICK, /**< Keyclick */

    AUDIOCONTROL_KEYSOUND_TONE_KEY_1,          /**< Key 1 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_2,          /**< Key 2 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_3,          /**< Key 3 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_4,          /**< Key 4 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_5,          /**< Key 5 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_6,          /**< Key 6 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_7,          /**< Key 7 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_8,          /**< Key 8 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_9,          /**< Key 9 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_0,          /**< Key 0 */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_ASTERISK,   /**< Key * */
    AUDIOCONTROL_KEYSOUND_TONE_KEY_NUMBERSIGN, /**< Key # */

    AUDIOCONTROL_KEYSOUND_TONE, /**< General key */

    AUDIOCONTROL_KEYSOUND_LAST
} TAudioControl_KeySound;

/**
 * @brief The different sessiontypes used in IAudioControl::AudioSession_Begin.
 */

typedef enum
{
    // aligned with parallellTable and sessionTypePriorities in ac_audiochannel.c
    AUDIOCONTROL_SESSIONTYPE_MEDIAPLAYER /**< An audio session for a media player           */ = 0x00000001,
    AUDIOCONTROL_SESSIONTYPE_CAMERA /**< An audio session for camera application       */ = 0x00000002,
    AUDIOCONTROL_SESSIONTYPE_FM_RADIO /**< An audio session for FM radio                 */ = 0x00000004,
    AUDIOCONTROL_SESSIONTYPE_VOICECALL /**< An audio session for a voicecall              */ = 0x00000008,
    AUDIOCONTROL_SESSIONTYPE_VIDEOTELEPHONY /**< An audio session for video telephony          */ = 0x00000010,
    AUDIOCONTROL_SESSIONTYPE_SOUNDRECORDER /**< An audio session for sound recorder           */ = 0x00000020,
    AUDIOCONTROL_SESSIONTYPE_VIDEORECORDER /**< An audio session for video recorder           */ = 0x00000040,
    AUDIOCONTROL_SESSIONTYPE_MESSAGING /**< An audio session for messaging                */ = 0x00000080,
    AUDIOCONTROL_SESSIONTYPE_JAVA /**< An audio session for a Java Virtual Machine   */ = 0x00000100,
    AUDIOCONTROL_SESSIONTYPE_PTT /**< An audio session for PTT                      */ = 0x00000200,
    AUDIOCONTROL_SESSIONTYPE_SLIDESHOW /**< An audio session for Slide show               */ = 0x00000400,
    AUDIOCONTROL_SESSIONTYPE_VOICETRAINING /**< An audio session for Voice training           */ = 0x00000800,
    AUDIOCONTROL_SESSIONTYPE_VOICECONTROL /**< An audio session for Voice control            */ = 0x00001000,
    AUDIOCONTROL_SESSIONTYPE_ASR_RECOGNITION_CONTINUOUS /**< An audio session for Voice control */ = 0x00002000,

    // Internal, not for external use
    AUDIOCONTROL_SESSIONTYPE_SYSTEM_SOUND /**< An audio session for system sounds            */ = 0x01000000,
    AUDIOCONTROL_SESSIONTYPE_KEYSOUNDS /**< An audio session for Key clicks and Key tones */ = 0x02000000,
    AUDIOCONTROL_SESSIONTYPE_LAST /**< For internal audio control use only           */ = 0x04000000,
    AUDIOCONTROL_SESSIONTYPE_NONE /**< */ = 0x00000000,
    AUDIOCONTROL_SESSIONTYPE_ALL /**< */ = 0xFFFFFFFF
} TAudioControl_SessionType;

/* Without NONE and ALL*/
#define NBROFSESSIONTYPES 17

/**
 * @brief Audio type enums
 *
 * The audio types at the bottom of the list are strictly for internal use.
 */
typedef enum
{
    AUDIOCONTROL_AUDIOTYPE_MEDIAPLAYER,
    AUDIOCONTROL_AUDIOTYPE_SOUNDRECORDER,
    AUDIOCONTROL_AUDIOTYPE_VIDEORECORDER,
    AUDIOCONTROL_AUDIOTYPE_VIDEOTELEPHONY,

    AUDIOCONTROL_AUDIOTYPE_VOICECALL_RX,
    AUDIOCONTROL_AUDIOTYPE_VOICECALL_TX,

    AUDIOCONTROL_AUDIOTYPE_JAVA,
    AUDIOCONTROL_AUDIOTYPE_JAVA_SOUNDRECORDER,

    AUDIOCONTROL_AUDIOTYPE_SPEECHTRAINING,
    AUDIOCONTROL_AUDIOTYPE_SPEECHRECOGNITION,
    AUDIOCONTROL_AUDIOTYPE_MAGIC_WORD,

    AUDIOCONTROL_AUDIOTYPE_FM_RADIO,
    AUDIOCONTROL_AUDIOTYPE_FM_RADIO_ALARM,

    AUDIOCONTROL_AUDIOTYPE_PTT_RX,
    AUDIOCONTROL_AUDIOTYPE_PTT_TX,
    AUDIOCONTROL_AUDIOTYPE_PTT_TX_DECODER,
    AUDIOCONTROL_AUDIOTYPE_PTT_BUFFER,

    // Internal enums.
    AUDIOCONTROL_AUDIOTYPE_RINGER,                 /**< Used for Ringer_Play and for Video CLI, through AudioChannel_Open */
    AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_ALERT,     /**< Used for Notification_Play with high prio sounds, see ac_notification.c*/
    AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_IMPORTANT, /**< Used for Notification_Play with medium prio sounds, see ac_notification.c*/
    AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_GENERAL,   /**< Used for Notification_Play with low prio sounds, see ac_notification.c*/
    AUDIOCONTROL_AUDIOTYPE_AUDIO,                  /**< Used for Play */
    AUDIOCONTROL_AUDIOTYPE_KEYTONE,                /**< Used for KeySound_Play and not AUDIOCONTROL_KEYSOUND_CLICK */
    AUDIOCONTROL_AUDIOTYPE_KEYCLICK,               /**< Used for KeySound_Play and AUDIOCONTROL_KEYSOUND_TONE  */
    AUDIOCONTROL_AUDIOTYPE_ALARM,                  /**< Used for Alarm_Play */
    AUDIOCONTROL_AUDIOTYPE_TONE,                   /**< Used for Tone_Play */
    AUDIOCONTROL_AUDIOTYPE_SPEAKERTEST,            /**< Used for ServiceMenu_SpeakerTest_Play */
    AUDIOCONTROL_AUDIOTYPE_EARPIECETEST,           /**< Used for ServiceMenu_SpeakerTest_Play */
    AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_CAMERA,    /**< Used for camera sounds */
    AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_VOICECTRL, /**< Used for voice control sounds */
    AUDIOCONTROL_AUDIOTYPE_NOTIFICATION_INCALL,    /**< Used for notification that should be played in earpiece during voice call*/

    AUDIOCONTROL_AUDIOTYPE_LAST /**< Keep this last*/

} AC_AudioType_t;

typedef AC_AudioType_t TAudioControl_ChannelType;

/**
 * @brief The different Volumes. Currently there are three scales.
 * Keep order!
 */
typedef enum
{
    AUDIOCONTROL_RINGVOLUME_0,
    AUDIOCONTROL_RINGVOLUME_1,
    AUDIOCONTROL_RINGVOLUME_2,
    AUDIOCONTROL_RINGVOLUME_3,
    AUDIOCONTROL_RINGVOLUME_4,
    AUDIOCONTROL_RINGVOLUME_5,
    AUDIOCONTROL_RINGVOLUME_6,
    AUDIOCONTROL_RINGVOLUME_7,
    AUDIOCONTROL_RINGVOLUME_8,

    AUDIOCONTROL_CALLVOLUME_0,
    AUDIOCONTROL_CALLVOLUME_1,
    AUDIOCONTROL_CALLVOLUME_2,
    AUDIOCONTROL_CALLVOLUME_3,
    AUDIOCONTROL_CALLVOLUME_4,
    AUDIOCONTROL_CALLVOLUME_5,
    AUDIOCONTROL_CALLVOLUME_6,
    AUDIOCONTROL_CALLVOLUME_7,
    AUDIOCONTROL_CALLVOLUME_8,

    AUDIOCONTROL_MEDIAVOLUME_0,
    AUDIOCONTROL_MEDIAVOLUME_1,
    AUDIOCONTROL_MEDIAVOLUME_2,
    AUDIOCONTROL_MEDIAVOLUME_3,
    AUDIOCONTROL_MEDIAVOLUME_4,
    AUDIOCONTROL_MEDIAVOLUME_5,
    AUDIOCONTROL_MEDIAVOLUME_6,
    AUDIOCONTROL_MEDIAVOLUME_7,
    AUDIOCONTROL_MEDIAVOLUME_8,
    AUDIOCONTROL_MEDIAVOLUME_9,
    AUDIOCONTROL_MEDIAVOLUME_10,
    AUDIOCONTROL_MEDIAVOLUME_11,
    AUDIOCONTROL_MEDIAVOLUME_12,
    AUDIOCONTROL_MEDIAVOLUME_13,
    AUDIOCONTROL_MEDIAVOLUME_14,
    AUDIOCONTROL_MEDIAVOLUME_15,

    AUDIOCONTROL_MEDIAVOLUME_LAST
} TAudioControl_VolumeTemp;

/**
 * @brief The abstract volumetype
 */
typedef FUint8 TAudioControl_RingVolume;
typedef FUint8 TAudioControl_CallVolume;
typedef FUint8 TAudioControl_MediaVolume;
typedef FUint8 TAudioControl_Volume;

/**
 * @brief The different volumetypes
 */
typedef enum
{
    AUDIOCONTROL_VOLUMETYPE_CURRENT,     /**< The current volumetype */
    AUDIOCONTROL_VOLUMETYPE_CALLVOLUME,  /**< The call volume */
    AUDIOCONTROL_VOLUMETYPE_RINGVOLUME,  /**< The ring signal volume */
    AUDIOCONTROL_VOLUMETYPE_MEDIAVOLUME, /**< The media volume */
    AUDIOCONTROL_VOLUMETYPE_INPUTVOLUME, /**< FOR AUDIOCONTROL INTERNAL USE ONLY */

    AUDIOCONTROL_VOLUMETYPE_LAST
} TAudioControl_VolumeType;

/**
 * @brief Volume control support. Used by IAudioControl::ShowVolumeControl to return the
 * current volume control support.
 */
typedef enum
{
    AUDIOCONTROL_VOLUME_CHANGE_AVAILABLE,                 /**< Volume control possible, audio playing */
    AUDIOCONTROL_VOLUME_CHANGE_NOT_AVAILABLE,             /**< Volume control not possible, no audio palying */
    AUDIOCONTROL_VOLUME_CHANGE_NOT_SUPPORTED_BY_ACCESSORY /**< Volume control not possible, not suported by current accessory */
} TAudioControl_Volume_Support;

/** @brief Max value for the mediavolume. Use this define since number of steps might change.
 * Also see IAudioControl::AUDIOCONTROL_MEDIAVOLUME_NBROFSTEPS
 */
#define AUDIOCONTROL_MEDIAVOLUME_MAX AUDIOCONTROL_MEDIAVOLUME_15
/** @brief Min value for the mediavolume. Use this define since number of steps might change.
 * Also see IAudioControl::AUDIOCONTROL_MEDIAVOLUME_NBROFSTEPS
 */
#define AUDIOCONTROL_MEDIAVOLUME_MIN AUDIOCONTROL_MEDIAVOLUME_0

/** @brief Max value for the callvolume. Use this define since number of steps might change.
 * Also see IAudioControl::AUDIOCONTROL_CALLVOLUME_NBROFSTEPS
 */
#define AUDIOCONTROL_CALLVOLUME_MAX AUDIOCONTROL_CALLVOLUME_8
/** @brief Min value for the callvolume. Use this define since number of steps might change.
 * Also see IAudioControl::AUDIOCONTROL_CALLVOLUME_NBROFSTEPS
 */
#define AUDIOCONTROL_CALLVOLUME_MIN AUDIOCONTROL_CALLVOLUME_0

/** @brief Max value for the ringvolume. Use this define since number of steps might change.
 * Also see IAudioControl::AUDIOCONTROL_RINGVOLUME_NBROFSTEPS
 */
#define AUDIOCONTROL_RINGVOLUME_MAX AUDIOCONTROL_RINGVOLUME_8;
/** @brief Min value for the ringvolume. Use this define since number of steps might change.
 * Also see IAudioControl::AUDIOCONTROL_RINGVOLUME_NBROFSTEPS
 */
#define AUDIOCONTROL_RINGVOLUME_MIN AUDIOCONTROL_RINGVOLUME_0

/**
 * @brief The equalizer band that you want to set / get the gain of
 */
// typedef TAudioEffectFrequencyBandId TAudioControl_EqualizerBand;

/**
 * @brief The equalizer gain that you want to set / get on a specific band
 */
// typedef TAudioEffectLevel TAudioControl_EqualizerGain;

/**
 * @brief The number of equalizer bands in the current configuration
 */
#define AUDIOCONTROL_EQUALIZER_NBR_OF_BANDS 5

/**
 * @brief The max gain of each equalizer band
 */
#define AUDIOCONTROL_EQUALIZER_MAX_GAIN 20

/**
 * @brief The min gain of each equalizer band
 */
#define AUDIOCONTROL_EQUALIZER_MIN_GAIN -20

/**
 * @brief The clear audio band that you want to set / get the gain of
 */
// typedef TAudioEffectFrequencyBandId TAudioControl_ClearAudioBand;

/**
 * @brief The clear audio gain that you want to set / get on a specific band
 */
// typedef TAudioEffectLevel TAudioControl_ClearAudioGain;

/**
 * @brief The different equalizer presets
 */
typedef enum
{
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_NORMAL,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_HEAVY,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_POPS,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_JAZZ,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_UNIQUE,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_SOUL,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_EASY_LISTENING,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_BASS_BOOST,
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_TREBLE_BOOST,

    // Always have this as the last preset
    AUDIOCONTROL_CLEAR_AUDIO_PRESET_LAST
} TAudioControl_ClearAudioPreset;

/**
 * @brief The number of clear audio bands in the current configuration
 */
#define AUDIOCONTROL_CLEAR_AUDIO_NBR_OF_BANDS = 7;

/**
 * @brief The max gain of each clear audio band
 */
#define AUDIOCONTROL_CLEAR_AUDIO_MAX_GAIN = 10;

/**
 * @brief The min gain of each clear audio band
 */
#define AUDIOCONTROL_CLEAR_AUDIO_MIN_GAIN = -10;

/**
 * @brief Time in milliseconds
 */
typedef FUint32 TAudioControl_TimeInMilliSeconds;

/**
 * @brief Forever time
 *
 */
#define AUDIOCONTROL_TIME_FOREVER 0x7FFFFFFF

/**
 * @brief The current audiorouting
 */
typedef enum
{
    AUDIOCONTROL_ROUTING_PHONE,    /**< The Audio is routed to the phone */
    AUDIOCONTROL_ROUTING_ACCESSORY /**< The Audio is routed to an accessory */
} TAudioControl_AudioRouting;

/**
 * @brief The different vibrator states
 */
typedef enum
{
    AUDIOCONTROL_VIBRATORSTATE_OFF,         /**< The vibrator is always off */
    AUDIOCONTROL_VIBRATORSTATE_ON,          /**< The vibrator is used when appropriate */
    AUDIOCONTROL_VIBRATORSTATE_ON_IF_SILENT /**< The vibrator is used when appropriate, if silentmode is on */
} TAudioControl_VibratorState;

/**
 * @brief The different calltypes
 */
typedef enum
{
    AUDIOCONTROL_CALLTYPE_VOICE, /**< VoiceCall */
    AUDIOCONTROL_CALLTYPE_VIDEO, /**< VideoCall */

    AUDIOCONTROL_CALLTYPE_LAST
} TAudioControl_CallType;

/**
 * @brief The different callstates
 */
typedef enum
{
    AUDIOCONTROL_CALLSTATE_IDLE,      /**< Should be used when no call is active */
    AUDIOCONTROL_CALLSTATE_ANSWERING, /**< Should be used before ICall_Answer to indicate that a call is about to be answered*/
    AUDIOCONTROL_CALLSTATE_ALERTING,  /**< Obsolete, replaced with AUDIOCONTROL_CALLSTATE_ANSWERING*/
    AUDIOCONTROL_CALLSTATE_SETUP,     /**< Should be used before initiating an outgoing call*/
    AUDIOCONTROL_CALLSTATE_ONGOING,   /**< Should be used when a call is active*/
    AUDIOCONTROL_CALLSTATE_HOLDING,   /**< Should be used when all calls are on hold*/

    AUDIOCONTROL_CALLSTATE_LAST
} TAudioControl_CallState;

/**
 * @brief The different reasons why a file playback is stopped
 */
typedef enum
{
    AUDIOCONTROL_STOPCAUSE_EOF,         /**< End of file was reached */
    AUDIOCONTROL_STOPCAUSE_INTERRUPTED, /**< The playback was stopped, for some reason (by calling ::Stop or someone with higher prio started playing) */
    AUDIOCONTROL_STOPCAUSE_ERROR,       /**< There playback was stopped due to an error */

    AUDIOCONTROL_STOPCAUSE_LAST
} TAudioControl_StopCause;

/**
 * @brief Needed for the PM interface
 */
#define AC_MAX_CHARACTERS_IN_PM_RINGTONE_NAME = 20;

/**
 * @brief Needed for the PM interface
 */
// typedef TChar TAudioControl_RingtoneTitle[AC_MAX_CHARACTERS_IN_PM_RINGTONE_NAME + 1];

/**
 * @brief Parameter needed by the AT+NREC command
 *
 */
typedef enum
{
    AUDIOCONTROL_NOISEREDUCTION_AUTO,      /**< Automatically select*/
    AUDIOCONTROL_NOISEREDUCTION_FORCE_ON,  /**< Force on */
    AUDIOCONTROL_NOISEREDUCTION_FORCE_OFF, /**< Force off, acc usually use this when they have their
                                               own noise reduction (E.g. some Blueooth headsets)*/
    AUDIOCONTROL_NOISEREDUCTION_LAST
} TAudioControl_NoiseReduction;

/**
 * @brief Parameter needed by the AT+NREC command
 *
 */
typedef enum
{
    AUDIOCONTROL_ECHOCANCELLER_AUTO,      /**< Automatically select*/
    AUDIOCONTROL_ECHOCANCELLER_FORCE_ON,  /**< Force on */
    AUDIOCONTROL_ECHOCANCELLER_FORCE_OFF, /**< Force off, acc usually use this when they have their
                                               own echo canceller (e.g. some Blueooth headsets)*/
    AUDIOCONTROL_ECHOCANCELLER_LAST
} TAudioControl_EchoCanceller;

/**
 * @brief Parameter to identify the decoding capabilities necessary for audio to be played in a channel.
 */
typedef enum
{
    AUDIOCONTROL_AUDIOFORMAT_WAV,               /**< The audio is a wav file*/
    AUDIOCONTROL_AUDIOFORMAT_AMR,               /**< The audio is a amr file*/
    AUDIOCONTROL_AUDIOFORMAT_TONE,              /**< The audio is a tone*/
    AUDIOCONTROL_AUDIOFORMAT_MIDI,              /**< The audio is a MIDI file*/
    AUDIOCONTROL_AUDIOFORMAT_SMAF,              /**< The audio is a SMAF file*/
    AUDIOCONTROL_AUDIOFORMAT_PMR,               /**< The audio is a Nokia pmr file file*/
    AUDIOCONTROL_AUDIOFORMAT_MFI,               /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_SPEECHRECOGNITION, /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_MP3,               /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_AAC,               /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_AAC_PLUS,          /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_FM_RADIO,          /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_VOICECALL,         /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_VIDEOCALL,         /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_INPUT,             /**< Todo */
    AUDIOCONTROL_AUDIOFORMAT_OTHER              /**< Todo */
} TAudioControl_AudioFormat;

/**
 * Defined audioformats to use in IAudioControl_AudioChannel_Open3 when the audio channel
 * is not to be used for audiofile playback
 *
 * @see IAudioControl::AudioChannel_open3
 *
 */
#define AUDIOFORMAT_FM_RADIO = 101;          /**< Audioformat for FM-radio channels */
#define AUDIOFORMAT_SPEECHRECOGNITION = 102; /**< Audioformat for channel used to play tone. */
#define AUDIOFORMAT_TONE = 103;              /**< Audioformat for channel used to play tone. */
#define AUDIOFORMAT_INPUT = 104;             /**< Audioformat for sound recording channels. */
#define AUDIOFORMAT_VOICECALL = 105;         /**< Audioformat for voicecall channels. */
#define AUDIOFORMAT_VIDEOCALL = 106;         /**< Audioformat for videocall channels. */
#define AUDIOFORMAT_MFISYNTH = 107;
#define AUDIOFORMAT_OMA_PTT = 123;
#define AUDIOFORMAT_KODIAK_PTT = 124;

#define AUDIOCONTROL_DEBUGMENU_STRING_MAXLENGTH = 79;
// typedef TChar TAudioControl_DebugMenuString[AUDIOCONTROL_DEBUGMENU_STRING_MAXLENGTH + 1];

/**
 * @brief Used to create and check the sample rate mask.
 *
 * @see IAudioControl::Accessory_Attach4
 * @see IAudioControl::Accessory_AcknowledgeSetupAudioPath
 * @see ICBAudioControl::OnAccessorySetupAudioPath
 */
typedef enum
{
    AUDIOCONTROL_SAMPLERATE_NONE = 0,
    AUDIOCONTROL_SAMPLERATE_8_KHZ = 1,
    AUDIOCONTROL_SAMPLERATE_16_KHZ = 2,
    AUDIOCONTROL_SAMPLERATE_44_1_KHZ = 4,
    AUDIOCONTROL_SAMPLERATE_48_KHZ = 8,
    AUDIOCONTROL_SAMPLERATE_ALL = 0xFF
} TAudioControl_SampleRate;

/**
 * @brief Used to indicate direction of fade.
 *
 * @see IAudioControl::ChannelVolume_Fade
 */
typedef enum
{
    AUDIOCONTROL_FADE_DIRECTION_NONE,
    AUDIOCONTROL_FADE_DIRECTION_UP,
    AUDIOCONTROL_FADE_DIRECTION_DOWN,

    AUDIOCONTROL_FADE_DIRECTION_LAST
} TAudioControl_FadeDirection;

/**
 * @brief Used to indicate the reason for the fade.
 *
 * @see IAudioControl::ChannelVolume_Fade
 */
typedef enum
{
    AUDIOCONTROL_FADE_REASON_PLAY,
    AUDIOCONTROL_FADE_REASON_STOP,
    AUDIOCONTROL_FADE_REASON_SUSPEND,

    AUDIOCONTROL_FADE_REASON_LAST
} TAudioControl_FadeReason;

/**
 * @brief Used to indicate the fade behaviour in IAudioControl_AudioChannel_Fade and Alarm_Play
 *
 */
typedef enum
{
    // these are to be used for alarm escalation
    AUDIOCONTROL_FADE_ALARM_ESCALATION_LOUD,
    AUDIOCONTROL_FADE_ALARM_ESCALATION_NORMAL,
    AUDIOCONTROL_FADE_ALARM_ESCALATION_MODEST,
    AUDIOCONTROL_FADE_ALARM_ESCALATION_DISCRETE,

    // these are to be used by the media player
    AUDIOCONTROL_FADE_BEHAVIOUR_PLAY,
    AUDIOCONTROL_FADE_BEHAVIOUR_STOP,
    AUDIOCONTROL_FADE_BEHAVIOUR_SUSPEND,

    // these are for internal use only
    AUDIOCONTROL_FADE_BEHAVIOUR_INCREASING_RING,
    AUDIOCONTROL_FADE_BEHAVIOUR_SAFETY_ESCALATION,
    AUDIOCONTROL_FADE_BEHAVIOUR_UNUSED,
    AUDIOCONTROL_FADE_BEHAVIOUR_LAST /**< keep this one last */
} TAudioControl_Fade_Behaviour;

/**
 * @brief Used to inform e.g. mediaplayer that the
 * sound has been audio due to routing change.
 * E.g. when audio has previously been in accessory that has been attached
 * and audio now is about to be played in speaker audio will be muted.
 *
 * @see IAudioControl::OnChannelMuted
 */
typedef enum
{
    AUDIOCONTROL_MUTE_REASON_ACCESSORY_DETACHED,
    AUDIOCONTROL_MUTE_REASON_FMTX_DISABLED
} TAudioControl_MuteReason;

/**
 * @brief Settings for the new channel.
 * The values may be used to create a mask containing all settings.
 *
 * @see IAudioControl::AudioChannel_Open3
 */
typedef enum
{
    AUDIOCONTROL_CHANNELSETTING_NORMAL = 0x00000,
    /**< Empty setting no special settings apply */
    AUDIOCONTROL_CHANNELSETTING_FOLLOWSILENTMODE = 0x00001,
    /**< Silent mode is followed, sound will only be played in discreet accessory */
    AUDIOCONTROL_CHANNELSETTING_MUTE_WHEN_REROUTING_TO_SPEAKER = 0x00002,
    /**< Mutes if sound ends up in speaker if previously in accessory (embarassing transition) */
    AUDIOCONTROL_CHANNELSETTING_DO_NOT_CONNECT = 0x00004,
    /**< Set up channel but don't connect it to the audio device */
    AUDIOCONTROL_CHANNELSETTING_DRM_PROTECTION_LOW = 0x00008,
    /**< Audio is not allowed to be routed to any BT accessory capable of capturing audio */
    AUDIOCONTROL_CHANNELSETTING_DRM_PROTECTION_HIGH = 0x00010,
    /**< Audio is not allowed to be routed to any accessory outside of the phone */
    AUDIOCONTROL_CHANNELSETTING_DO_NOT_FADE_ONGOING_AUDIO = 0x00020,
    /**< If any other channel is suspended to make room, do not wait for fade */
    AUDIOCONTROL_CHANNELSETTING_MUTE_CONNECTION = 0x00040,
    /**< Mutes the connection to the channel (used for PTT when playing buffered audio) */
    AUDIOCONTROL_CHANNELSETTING_ALLOW_FMTX = 0x00080,
    /**< Specifies that the channel allows to be sent over FM */

    // These values are for internal Audio Control use only!
    AUDIOCONTROL_CHANNELSETTING_FAKE_CHANNEL = 0x01000,
    AUDIOCONTROL_CHANNELSETTING_EQUALIZER_ACTIVE = 0x02000,
    AUDIOCONTROL_CHANNELSETTING_CLEAR_AUDIO_ACTIVE = 0x04000,
    AUDIOCONTROL_CHANNELSETTING_NO_CHANNEL_IF_SILENT = 0x08000,
    AUDIOCONTROL_CHANNELSETTING_3DAUDIO_ACTIVE = 0x10000
    /**< Do not deliver channel if routed to virtual silent device,
         this is the case for some notifications during silent mode */
} TAudioControl_ChannelSetting;

/**
 * @brief Power mode enum, can be expanded to a bitmask
 */
typedef enum
{
    AUDIOCONTROL_POWERMODE_BACKLIGHT_ON,  /**< The screen backlight is on*/
    AUDIOCONTROL_POWERMODE_BACKLIGHT_OFF, /**< The screen backlight is off*/

    AUDIOCONTROL_POWERMODE_LAST
} TAudioControl_PowerMode;

/**
 * @brief Speaker mode settings determines if sound should be primarily routed to speaker or not.
 *
 */
typedef enum
{
    AUDIOCONTROL_SPEAKERMODE_OFF,               /**< Speaker mode set to off, normal routing rules apply */
    AUDIOCONTROL_SPEAKERMODE_FORCE_ON,          /**< Speaker mode set forcefully by application and will not be turned off if an accessory is attached */
    AUDIOCONTROL_SPEAKERMODE_USER_ON,           /**< Speaker mode has been set by user but will be turned off when an accessory is attached*/
    AUDIOCONTROL_SPEAKERMODE_ON_IF_NO_ACCESSORY /**< Speaker mode will be active if there is no accessory attached */
} TAudioControl_SpeakerMode;

/**
 * @brief Enum values used for the different HAC settings
 */
typedef enum
{
    AUDIOCONTROL_HACMODE_OFF,
    AUDIOCONTROL_HACMODE_MIC,
    AUDIOCONTROL_HACMODE_TCOIL,

    AUDIOCONTROL_HACMODE_LAST
} TAudioControl_HACMode;

/**
 * @brief Comfort Tone enum for the comfort tone setting,
 */
typedef enum
{
    AUDIOCONTROL_COMFORT_TONE_STANDARD_JAPAN, /**< Japanese comfort tone standard*/
    AUDIOCONTROL_COMFORT_TONE_STANDARD_ANSI,  /**< ANSI comfort tone standard*/
    AUDIOCONTROL_COMFORT_TONE_STANDARD_CEPT,  /**< CEPT comfort tone standard*/

    AUDIOCONTROL_COMFORT_TONE_STANDARD_LAST
} TAudioControl_ComfortToneStandard;

/**
 * @brief Enum values used for different TTY modes
 */
typedef enum
{
    AUDIOCONTROL_TTYMODE_OFF,      /**< TTY mode set to off*/
    AUDIOCONTROL_TTYMODE_STANDARD, /**< TTY mode set to standard*/
    AUDIOCONTROL_TTYMODE_HCO,      /**< TTY mode set to hearing carry over*/
    AUDIOCONTROL_TTYMODE_VCO,      /**< TTY mode set to voice carry over*/

    AUDIOCONTROL_TTYMODE_LAST
} TAudioControl_TTYMode;

// clang-format on

#endif
