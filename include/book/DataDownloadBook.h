#ifndef DATA_DOWNLOAD_BOOK_H
#define DATA_DOWNLOAD_BOOK_H

#include <bookobj.h>

typedef struct DataDownloadBook
{
    BOOK book;
    void *unk_0x18; // 0x18
    FILEITEM *fi;   // 0x1C
    void *unk_0x20; // 0x20
    GUI *gui;       // 0x24
} DataDownloadBook;

#endif // DATA_DOWNLOAD_BOOK_H