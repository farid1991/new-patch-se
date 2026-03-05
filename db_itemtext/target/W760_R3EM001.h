#pragma once

#define TXT_BYTES 0x665
#define TXT_KBYTES 0x6B1
#define TXT_MBYTES 0x6C0
#define FILES_TXT 0x7A3
#define NOFILES_TXT 0x6E4
#define EMPTYFOLDER_TXT 0x1B18
#define NOSUBFOLDERS_TXT 0x1866
#define READ_ONLY_TXT 0x2663

#define FILE_ICN 0xF761
#define FOLDER_ICN 0xF766
#define HELP_TEXT_ICN 0xF8F0

#define ADDR_TextID_Create (0x10FFBF40 | 1)
#define ADDR_TextID_CreateIntegerID (0x10FFBD6C | 1)

#define ADDR_w_fstat (0x11331024 | 1)
#define ADDR_w_chdir (0x4BB003AC)
#define ADDR_w_diropen (0x4BB00354)
#define ADDR_w_dirread (0x11AE39C4 | 1)
#define ADDR_w_dirclose (0x4BB0038C)
