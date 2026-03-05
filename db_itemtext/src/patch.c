#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#endif

#include <libse.h>

#define KBYTE (1 << 10)
#define MBYTE (1 << 20)

#define X2ID(X) 0x78000000 + X

THUMB16 NEWCODE inline size_t TO_KBYTE(size_t i) { return i >> 10; }
THUMB16 NEWCODE inline size_t TO_MBYTE(size_t i) { return i >> 20; }
THUMB16 NEWCODE inline BOOL is_readonly(int attr) { return ((attr & ~FSX_O_ENCRYPT) & (0x100 >> 1)) ? FALSE : TRUE; }

THUMB16 NEWCODE BOOL is_directory(const wchar_t *path)
{
    W_FSTAT fs;
    if (w_fstat(path, &fs) != -1)
        return fs.attr & FSX_O_CHKPATH;
    return FALSE;
}

THUMB16 NEWCODE void read_directory(const wchar_t *fullpath, int *files_count, int *dir_count)
{
    int files = 0, folders = 0;
    void *dir = w_diropen(fullpath);
    if (dir)
    {
        wchar_t *next;
        w_chdir(fullpath);
        while ((next = w_dirread(dir)) != NULL)
        {
            if (is_directory(next))
                folders++;
            else
                files++;
        }
        w_dirclose(dir);
    }
    *files_count = files;
    *dir_count = folders;
}

THUMB16 NEWCODE TEXTID file_count_to_textid(const wchar_t *fullpath, TEXTID space)
{
    W_FSTAT fs;
    w_fstat(fullpath, &fs);
    BOOL readonly = is_readonly(fs.attr);

    size_t size = 0;
    TEXTID txt[5];

    if (fs.st_size < KBYTE)
    {
        size = fs.st_size;
        txt[2] = TXT_BYTES;
    }
    else if (fs.st_size < MBYTE)
    {
        size = TO_KBYTE(fs.st_size);
        txt[2] = TXT_KBYTES;
    }
    else
    {
        size = TO_MBYTE(fs.st_size);
        txt[2] = TXT_MBYTES;
    }

    txt[0] = TextID_CreateIntegerID(size);
    txt[1] = space;
    txt[3] = space;

    if (readonly)
        txt[4] = READ_ONLY_TXT;
    else
        txt[4] = space;

    return TextID_Create(txt, ENC_TEXTID, 5);
}

THUMB16 NEWCODE TEXTID dir_count_to_textid(const wchar_t *fullpath, TEXTID space)
{
    int files, folders;
    read_directory(fullpath, &files, &folders);

    if (!files && !folders)
        return EMPTYFOLDER_TXT;

    TEXTID ret;
    if (files && folders)
    {
        TEXTID txt[7];
        txt[0] = TextID_CreateIntegerID(folders);
        txt[1] = X2ID(FOLDER_ICN);
        txt[2] = space;
        txt[3] = X2ID('&');
        txt[4] = space;
        txt[5] = TextID_CreateIntegerID(files);
        txt[6] = X2ID(FILE_ICN);
        ret = TextID_Create(txt, ENC_TEXTID, 7);
    }
    else if (folders)
    {
        TEXTID txt[3];
        txt[0] = TextID_CreateIntegerID(folders);
        txt[1] = space;
        txt[2] = X2ID(FOLDER_ICN);
        ret = TextID_Create(txt, ENC_TEXTID, 3);
    }
    else if (files)
    {
        TEXTID txt[3];
        txt[0] = TextID_CreateIntegerID(files);
        txt[1] = space;
        txt[2] = X2ID(FILE_ICN);
        ret = TextID_Create(txt, ENC_TEXTID, 3);
    }
    return ret;
}

THUMB16 NEWCODE TEXTID db_set_secondline_text(const wchar_t *fullpath, TEXTID space)
{
    if (is_directory(fullpath))
        return dir_count_to_textid(fullpath, space);

    TEXTID txt[3];
    txt[0] = X2ID(HELP_TEXT_ICN);
    txt[1] = space;
    txt[2] = file_count_to_textid(fullpath, space);
    return TextID_Create(txt, ENC_TEXTID, 3);
}
