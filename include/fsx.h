#ifndef FILE_H
#define FILE_H

#include <base.h>
#include <databrowser.h>

typedef struct FSTAT
{
    uint16_t st_ino;
    uint16_t st_nlink;
    uint32_t st_mode; // was unk1
    uint32_t fsize;   // st_size
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
    uint32_t st_attr;
} FSTAT;

typedef struct W_FSTAT
{
    int attr;
    int unk_0x4;
    int unk_0x8;
    int unk_0xC;
    int unk_0x10;
    int unk_0x14;
    int st_size;
    unsigned int unk_0x1C;
    unsigned int unk_0x20;
    unsigned int unk_0x24;
} W_FSTAT;

typedef struct FILELISTITEM
{
    int unk;
    wchar_t *path;
    wchar_t *fname;
    char *content_type;
    char unk1[0x2F0];
} FILELISTITEM; // FSX_dirent?

typedef struct DIR_HANDLE
{
    int unk_0;
    uint16_t unk_4;
    uint16_t unk_6;
    int unk_8;
    char unk_C;
    char unk_D;
    char ena_hidden;
} DIR_HANDLE; // FSX_DIR?

typedef struct VOLUMESIZE
{
    uint32_t TotalSpace;            /* Total size of FS in bytes */
    uint32_t FreeSpace;             /* Number of free bytes */
    uint32_t BytesPerCluster;       /* File system block size */
    uint32_t TotalClusters;         /* Logical file system size */
    uint32_t TotalFreeClusters;     /* Number of free blocks, both phyical and logical */
    uint32_t free_reserved_blocks;  /* Number of free reserved blocks. */
    uint32_t used_oversize_blocks;  /* Number of used oversize blocks. */
    uint32_t total_oversize_blocks; /* Number of available oversize blocks. */
} VOLUMESIZE;                       // old FSX_freespace

typedef struct VOLUMESIZE_A2
{
    uint64_t TotalSpace;            /* Total size of FS in bytes */
    uint64_t FreeSpace;             /* Number of free bytes */
    uint32_t BytesPerCluster;       /* File system block size */
    uint32_t TotalClusters;         /* Logical file system size */
    uint32_t TotalFreeClusters;     /* Number of free blocks, both phyical and logical */
    uint32_t free_reserved_blocks;  /* Number of free reserved blocks. */
    uint32_t used_oversize_blocks;  /* Number of used oversize blocks. */
    uint32_t total_oversize_blocks; /* Number of available oversize blocks. */
} VOLUMESIZE_A2;                    // FSX_freespace

// w_fopen
typedef enum W_OPEN_ATTR
{
    WA_Read = 1,
    WA_Write = 2,
    WA_Append = 4,
    WA_Create = 8,
    WA_Truncate = 0x40
} W_OPEN_ATTR;

// fopen/_fopen (mode)
#define FSX_O_RDONLY 0x0001     /// Open for reading only.
#define FSX_O_WRONLY 0x0002     /// Open for writing only.
#define FSX_O_RDWR 0x0004       /// Open for reading and writing.
#define FSX_O_APPEND 0x0008     /// Writes done at eof.
#define FSX_O_SINGLEUSER 0x0010 /// Set file locking mechanism on
#define FSX_O_CREAT 0x0100      /// Create and open file.
#define FSX_O_TRUNC 0x0200      /// Open and truncate.
#define FSX_O_EXCL 0x0400       /// Open only if file doesn't already exist.
#define FSX_O_MULT 0x0800       /// Open for reading or writing the already opened file.
#define FSX_O_ENCRYPT 0x1000    /// Secure Storage flag.
#define FSX_O_DECRYPT 0x2000    /// Secure Storage flag.
#define FSX_O_CHKPATH 0x4000    /// Check the path length considering its subfolders.
#define FSX_O_NOROLLBACK 0x8000 /// Prevent rollback if write fails due to ENOSPC.
#define FSX_O_FS_MASK (0xF70F)  /* MASK for normal file's open mode*/

// fopen/_fopen (mode), FSTAT.st_mode
#define FSX_S_IRUSR 0x00000100 /// Read access, owner.
#define FSX_S_IWUSR 0x00000080 /// Write access, owner.
#define FSX_S_IXUSR 0x00000040 /// Execute/search access, owner.
#define FSX_S_IREAD FSX_S_IRUSR
#define FSX_S_IWRITE FSX_S_IWUSR
#define FSX_S_IEXEC FSX_S_IXUSR
#define FSX_FILE_MODE_MASK (FSX_S_IRUSR | FSX_S_IWUSR | FSX_S_IXUSR)

// FSTAT.st_mode
#define FSX_S_IFUNKNOWN 0x00000000
#define FSX_S_IFREG 0x00001000
#define FSX_S_IFVOL 0x00002000
#define FSX_S_IFDIR 0x00010000
#define FSX_S_IFLINK 0x00040000

// for pAttr
#define FSX_EXT_ATTR_NONE 0x00000000       /* No attributs */
#define FSX_FILE_ATTR_CORRUPTED 0x00000001 /* If set, the file is corrupted */
#define FSX_FILE_ATTR_PRIVATE 0x00000002   /* If set, the file is copyright protected */
#define FSX_FILE_ATTR_DECODED 0x00000004   /* If set, the file can be decoded */
#define FSX_FILE_ATTR_ENCRYPT 0x00000008   /* If set, the file will be encrypted */
#define FSX_FILE_ATTR_HIDDEN 0x10000000    /* If set, the file will be hidden */

// for lseek mode
#define FSX_SEEK_SET 0 /// Seek to an absolute position
#define FSX_SEEK_CUR 1 /// Seek relative to current position
#define FSX_SEEK_END 2 /// Seek relative to end of file

// for action
#define FSX_ATTR_CLR 0 /// Clear attribute
#define FSX_ATTR_SET 1 /// Set attribute
#define FSX_ATTR_GET 2 /// Get attribute

#endif // FILE_H