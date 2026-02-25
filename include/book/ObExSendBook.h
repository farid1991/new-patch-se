#ifndef ObExSendBook_H
#define ObExSendBook_H

typedef struct OBEX_REFRESH_SEND_PROGRESS_DATA
{
    char dummy[0x24];
    int sent_bytes;
} OBEX_REFRESH_SEND_PROGRESS_DATA;

#if defined(DB2010)
typedef struct ObExSendBook
{
    BOOK book;               // 0x00
    GUI *ProgressBar;        // 0x18
    void *unk_1C;            // 0x1C Interface?
    char unk_20[0x14];       // 0x20
    BT_FILE_2010 bt_file;    // 0x34
    char unk_424[0x10];      // 0x424
    uint32_t file_sent;      // 0x434
    uint32_t file_size;      // 0x438
    uint16_t timer_id;       // 0x43C
    uint16_t unk_43E;        // 0x43E
    int current_percent;     // 0x440
    IMAGEID Receiver_ICN;    // 0x444
    wchar_t short_name[0xE]; // 0x446
} ObExSendBook;

#elif defined(DB3150v1) || defined(DB3150v2) || defined(DB3350)
typedef struct ObExSendBook
{
    BOOK book;                // 0x00
    GUI *ProgressBar;         // 0x18
    void *unk_1C;             // 0x1C Interface?
    char unk_20[0x14];        // 0x20
    wchar_t fname[255];       // 0x34
    wchar_t fpath[255];       // 0x232
    char unk_430[0x10];       // 0x430
    uint32_t file_sent;       // 0x440
    uint32_t file_size;       // 0x444
    char unk_448[0x8];        // 0x448
    IMAGEID Receiver_ICN;     // 0x450
    wchar_t short_name[0x1F]; // 0x452
} ObExSendBook;

#elif defined(DB3200) || defined(DB3210)
typedef struct ObExSendBook
{
    BOOK book;                // 0x00
    GUI *ProgressBar;         // 0x18
    void *unk_1C;             // 0x1C Interface?
    char unk_20[0x18];        // 0x20
    wchar_t fname[255];       // 0x38
    wchar_t fpath[255];       // 0x236
    char unk_434[0x10];       // 0x434
    uint32_t file_sent;       // 0x444
    uint32_t file_size;       // 0x448
    char unk_44C[0x8];        // 0x44C
    IMAGEID Receiver_ICN;     // 0x454
    wchar_t short_name[0x1F]; // 0x456
} ObExSendBook;

#endif

#endif
