#pragma once

#define TXT_BYTES 0x778
#define TXT_KBYTES 0x5A0
#define TXT_MBYTES 0x5A1
#define FILES_TXT 0x7A3
#define NOFILES_TXT 0x16B8
#define EMPTYFOLDER_TXT 0x7F3
#define NOSUBFOLDERS_TXT 0x18E7
#define READ_ONLY_TXT 0x2309

#define FILE_ICN 0xF761
#define FOLDER_ICN 0xF766
#define HELP_TEXT_ICN 0xF8F0

#define ADDR_TextID_Create (0x145B8610 | 1)
#define ADDR_TextID_CreateIntegerID (0x1427B854 | 1)

#define ADDR_w_fstat (0x1003091C | 1)
#define ADDR_w_chdir (0x4BFB8A98)
#define ADDR_w_diropen (0x4BC00164)
#define ADDR_w_dirread (0x14A6A6B4 | 1)
#define ADDR_w_dirclose (0x4BFB8A78)
