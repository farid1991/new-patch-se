#pragma once

#define TXT_BYTES 0x59C
#define TXT_KBYTES 0x5E1
#define TXT_MBYTES 0x5F1
#define FILES_TXT 0x5C6
#define NOFILES_TXT 0x138A
#define EMPTYFOLDER_TXT 0x612
#define NOSUBFOLDERS_TXT 0x15BA
#define READ_ONLY_TXT 0x1CDB

#define FILE_ICN 0xF761
#define FOLDER_ICN 0xF766
#define HELP_TEXT_ICN 0xF8F0

#define ADDR_TextID_Create (0x141818E4 | 1)
#define ADDR_TextID_CreateIntegerID (0x1401F5BC | 1)

#define ADDR_w_fstat (0x100A6EA0 | 1)
#define ADDR_w_chdir (0x4BA80C30)
#define ADDR_w_diropen (0x4BA32468)
#define ADDR_w_dirread (0x142E855C | 1)
#define ADDR_w_dirclose (0x4BA80C10)
