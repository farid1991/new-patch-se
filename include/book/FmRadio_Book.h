#ifndef FmRadio_Book_H
#define FmRadio_Book_H

#include <base.h>
#include <bookobj.h>
#include <gui.h>

#define NBR_OF_PS_NAME_CHARS 8

typedef struct FmRadio_Settings
{
    bool SpeakerMode;
    bool StereoReception; // true=stereo //false=mono
} FmRadio_Settings;

typedef struct FmRadio_Channel
{
    uint16_t Frequency;
    uint16_t FmRadio_Channel;
    wchar_t Name[0x11];
} FmRadio_Channel;

#if defined(W980_R3EG004) || defined(DB3200)
typedef struct FmRadio_Book
{
    BOOK book;
    GUI *FmRadio_Gui;                                     // 0x18
    int unk_1C;                                           // 0x1C
    GUI *FmRadio_Gui_Submenu1;                            // 0x20
    GUI *FmRadio_Gui_Submenu2;                            // 0x24
    uint32_t parent_book_id;                              // 0x28
    uint8_t CurrentChannel;                               // 0x2C
    uint8_t unk_29;                                       // 0x2D
    uint16_t CurrentFrequency;                            // 0x2E
    uint16_t unk_2C;                                      // 0x30
    wchar_t ProgramServiceName[NBR_OF_PS_NAME_CHARS + 1]; // 0x32
    uint16_t unk_40;                                      // 0x44
    FmRadio_Channel Channel[20];                          // 0x46
    uint16_t unk_33E;                                     // 0x33E
    int RadioVal;                                         // 0x340
    int unk_344;                                          // 0x344
    int unk_348;                                          // 0x348
    void *pIAudioControl;                                 // 0x34C
    int unk_350;                                          // 0x350
    void *pIFMRadio;                                      // 0x354
    int unk_358;                                          // 0x358
    void *pIAccessoryServer;                              // 0x35C
    FmRadio_Settings Settings;                            // 0x360
    uint16_t unk_0x366;                                   // 0x364
    uint16_t TimerID;                                     // 0x366
    uint16_t FrequencySearch;                             // 0x368
    uint16_t unk_36A;                                     // 0x36A
    char unk_36C[0x2E];                                   // 0x36C
    bool RDS;                                             // 0x39A
    bool AF;                                              // 0x39B
    uint8_t unk_0x39C;                                    // 0x39C
} FmRadio_Book;
#else
typedef struct FmRadio_Book
{
    BOOK book;
    GUI *FmRadio_Gui;                                     // 0x18
    GUI *FmRadio_Gui_Submenu1;                            // 0x1C
    GUI *FmRadio_Gui_Submenu2;                            // 0x20
    uint32_t parent_book_id;                              // 0x24
    uint8_t CurrentChannel;                               // 0x28
    uint8_t unk_29;                                       // 0x29
    uint16_t CurrentFrequency;                            // 0x2A
    uint16_t unk_2C;                                      // 0x2C
    wchar_t ProgramServiceName[NBR_OF_PS_NAME_CHARS + 1]; // 0x2E
    uint16_t unk_40;                                      // 0x40
    FmRadio_Channel Channel[20];                          // 0x42
    uint16_t unk_33A;                                     // 0x33A
    uint32_t RadioVal;                                    // 0x33C
    uint32_t unk_340;                                     // 0x340
    uint32_t unk_344;                                     // 0x344
    void *pIAudioControl;                                 // 0x348
    uint32_t unk_34C;                                     // 0x34C
    void *pIFMRadio;                                      // 0x350
    uint32_t unk_354;                                     // 0x354
    void *pIAccessoryServer;                              // 0x358
    FmRadio_Settings Settings;                            // 0x35C
    uint16_t TimerID;                                     // 0x35E
    uint16_t unk_360;                                     // 0x360
    uint16_t unk_362;                                     // 0x362
    uint16_t FrequencySearch;                             // 0x364
    uint16_t unk_366;                                     // 0x366
    char unk_368[0x2E];                                   // 0x368
    bool RDS;                                             // 0x396
    bool AF;                                              // 0x397
    uint8_t unk_398;                                      // 0x398
} FmRadio_Book;
#endif

#endif
