#if defined(C510_R1HA035)
#include <C510_R1HA035.h>
#elif defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#endif

#define USE_LIBPNG
#include <libse.h>

#include "patch.h"

THUMB16 NEWCODE void *malloc(int size)
{
#if defined(DB2020)
    return memalloc(NULL, size, 1, 5, DEF_PNG_LIBPNG_VER_STRING, NULL);
#elif defined(A2)
    return memalloc(-1, size, 1, 5, DEF_PNG_LIBPNG_VER_STRING, NULL);
#else
    return memalloc(size, 1, 5, DEF_PNG_LIBPNG_VER_STRING, NULL);
#endif
}

THUMB16 NEWCODE void mfree(void *mem)
{
    if (mem)
#if defined(DB2020) || defined(A2)
        memfree(NULL, mem, DEF_PNG_LIBPNG_VER_STRING, NULL);
#else
        memfree(mem, DEF_PNG_LIBPNG_VER_STRING, NULL);
#endif
}

#if defined(PNG_EXTRA_SUPPORTED)
THUMB16 NEWCODE int text_list_item_filter(void *elem)
{
    return (elem != NULL);
}

THUMB16 NEWCODE void text_list_destroy(LIST **list, void (*free_list)(void *item))
{
    if (*list)
    {
        List_DestroyElements(*list, text_list_item_filter, free_list);
        List_Destroy(*list);
        *list = NULL;
    }
}

THUMB16 NEWCODE void text_list_remove_item(void *item)
{
    TEXT_LIST *text = (TEXT_LIST *)item;
    if (text)
    {
        mfree(text->key);
        mfree(text->value);
        mfree(text);
    }
}

THUMB16 NEWCODE TEXT_LIST *text_list_create(char *key, char *value)
{
    TEXT_LIST *text = (TEXT_LIST *)malloc(sizeof(TEXT_LIST));

    text->key_len = strlen(key) + 1;
    text->key = (char *)malloc(text->key_len);
    memset(text->key, 0, text->key_len);
    strncpy(text->key, key, text->key_len);

    text->value_len = strlen(value) + 1;
    text->value = (char *)malloc(text->value_len);
    memset(text->value, 0, text->value_len);
    strncpy(text->value, value, text->value_len);

    return text;
}
#endif

THUMB16 NEWCODE void *my_png_malloc(png_structp png_ptr, png_size_t size)
{
    return malloc(size);
}

THUMB16 NEWCODE void my_png_free(png_structp png_ptr, png_voidp ptr)
{
    mfree(ptr);
}

THUMB16 NEWCODE void my_png_read(png_structp png_ptr, png_bytep data, png_size_t length)
{
    int *io_ptr = (int *)png_get_io_ptr(png_ptr);
    fread(*io_ptr, data, length);
}

THUMB16 NEWCODE int my_png_get_text(png_infop info_ptr, png_textp *text_ptr, int *num_text)
{
    if (info_ptr->num_text > 0)
    {
        if (text_ptr != NULL)
            *text_ptr = info_ptr->text;

        if (num_text != NULL)
            *num_text = info_ptr->num_text;

        return info_ptr->num_text;
    }
    if (num_text != NULL)
        *num_text = 0;
    return 0;
}

THUMB16 NEWCODE CHUNK_DATA *png_read_chunk_data(const wchar_t *path, const wchar_t *name)
{
    CHUNK_DATA *png_data = (CHUNK_DATA *)malloc(sizeof(CHUNK_DATA));
    if (!png_data)
        return 0;

    memset(png_data, 0, sizeof(CHUNK_DATA));

    int file = _fopen(path, name, FSX_O_RDONLY, FSX_S_IREAD, NULL);
    if (file == -1)
    {
        mfree(png_data);
        return 0;
    }

    png_structp png_ptr = png_create_read_struct_2(DEF_PNG_LIBPNG_VER_STRING,
                                       NULL, NULL, NULL, NULL,
                                       my_png_malloc, my_png_free);
    if (!png_ptr)
    {
        mfree(png_data);
        fclose(file);
        return 0;
    }

    png_infop info_ptr = png_create_info_struct(png_ptr);
    if (!info_ptr)
    {
        mfree(png_data);
        fclose(file);
        png_destroy_read_struct(&png_ptr, NULL, NULL);
        return 0;
    }

    png_set_read_fn(png_ptr, &file, my_png_read);

    png_read_info(png_ptr, info_ptr);

    png_get_IHDR(png_ptr, info_ptr,
                 &png_data->width,
                 &png_data->height,
                 &png_data->bit_depth,
                 &png_data->color,
                 &png_data->interlace,
                 &png_data->compression,
                 &png_data->filter);
#if defined(DB2000)
    if (png_data->color == PNG_COLOR_TYPE_PALETTE)
        png_data->channels = 1;
    else if (png_data->color & PNG_COLOR_MASK_COLOR)
        png_data->channels = 3;
    else
        png_data->channels = 1;
    if (png_data->color & PNG_COLOR_MASK_ALPHA)
        png_data->channels++;
#else
    png_data->channels = info_ptr->channels;
#endif
    png_data->pixel_depth = png_data->bit_depth * png_data->channels;

#if defined(PNG_EXTRA_SUPPORTED)
    png_textp text_ptr = NULL;

    if (my_png_get_text(info_ptr, &text_ptr, &png_data->num_text) > 0)
    {
        png_data->texts = List_Create();
        for (int i = 0; i < png_data->num_text; i++)
        {
            TEXT_LIST *text = text_list_create(text_ptr[i].key, text_ptr[i].text);
            if (text)
                List_InsertLast(png_data->texts, text);
        }
    }
#endif
    png_destroy_read_struct(&png_ptr, &info_ptr, NULL);

    fclose(file);

    return png_data;
}

THUMB16 NEWCODE void png_destroy_chunk_data(CHUNK_DATA *png_data)
{
#if defined(PNG_EXTRA_SUPPORTED)
    if (png_data->num_text > 0)
        text_list_destroy(&png_data->texts, text_list_remove_item);
#endif
    mfree(png_data);
}

/* ---- Color type strings ---- */
static const char STR_GRAY[] = "Grayscale";
static const char STR_PALETTE[] = "Paletted color";
static const char STR_RGB[] = "RGB";
static const char STR_RGBA[] = "RGB with alpha";
static const char STR_GA[] = "Grayscale with alpha";
static const char STR_UNKNOWN_COLOR[] = "Unknown color type";

/* ---- Interlace strings ---- */
static const char STR_NON_INTERLACED[] = "Non-interlaced image";
static const char STR_ADAM7[] = "Adam7 interlacing";
static const char STR_INVALID[] = "Not a valid";

/* ---- Filter strings ---- */
static const char STR_MNG[] = "MNG datastreams";
static const char STR_SINGLE_ROW[] = "Single row per-byte";

THUMB16 NEWCODE const char *get_color_type(int color_type)
{
    switch (color_type)
    {
    case PNG_COLOR_TYPE_GRAY:
        return STR_GRAY;
    case PNG_COLOR_TYPE_PALETTE:
        return STR_PALETTE;
    case PNG_COLOR_TYPE_RGB:
        return STR_RGB;
    case PNG_COLOR_TYPE_RGBA:
        return STR_RGBA;
    case PNG_COLOR_TYPE_GA:
        return STR_GA;
    default:
        return STR_UNKNOWN_COLOR;
    }
}

THUMB16 NEWCODE const char *get_interlace_type(int interlace)
{
    switch (interlace)
    {
    case PNG_INTERLACE_NONE:
        return STR_NON_INTERLACED;
    case PNG_INTERLACE_ADAM7:
        return STR_ADAM7;
    default:
        return STR_INVALID;
    }
}

THUMB16 NEWCODE const char *get_filter_type(int filter)
{
    if (filter == PNG_INTRAPIXEL_DIFFERENCING)
        return STR_MNG;

    return STR_SINGLE_ROW;
}

/* ---- PNG Info Format ---- */
static const char STR_PNG_INFO_FMT[] =
    "\n=Extra PNG Info=\n"
    "Bit Depth: %d\n"
    "Channels: %d\n"
    "Pixel Depth: %d\n"
    "Color: %s\n"
    "Interlace: %s\n"
    "Filter: %s\n"
    "libpng: %s";

/* Small reusable literals */
static const char STR_NEWLINE[] = "\n";
static const char STR_COLON_SPACE[] = ": ";

THUMB16 NEWCODE TEXTID patch_brw_png_info(TEXTID text_id, SUB_EXECUTE *sub_exec)
{
    wchar_t *path = FILEITEM_GetPath(sub_exec->file_item);
    wchar_t *name = FILEITEM_GetFname(sub_exec->file_item);

    CHUNK_DATA *png_data = png_read_chunk_data(path, name);
    if (!png_data)
        return text_id;

    char *png_info = (char *)malloc(MAX_PNGINFO_SIZE);
    if (!png_info)
    {
        png_destroy_chunk_data(png_data);
        return text_id;
    }

#if defined(DB2000) || defined(DB2010)
    sprintf(png_info,
#else
    snprintf(png_info, MAX_PNGINFO_SIZE,
#endif
            STR_PNG_INFO_FMT,
            png_data->bit_depth,
            png_data->channels,
            png_data->pixel_depth,
            get_color_type(png_data->color),
            get_interlace_type(png_data->interlace),
            get_filter_type(png_data->filter),
            DEF_PNG_LIBPNG_VER_STRING);

#if defined(PNG_EXTRA_SUPPORTED)
    if (png_data->num_text > 0)
    {
        for (int i = 0; i < png_data->num_text; i++)
        {
            TEXT_LIST *text = (TEXT_LIST *)List_Get(png_data->texts, i);

            strncat(png_info, STR_NEWLINE, sizeof(STR_NEWLINE));
            strncat(png_info, text->key, text->key_len);
            strncat(png_info, STR_COLON_SPACE, sizeof(STR_COLON_SPACE));
            strncat(png_info, text->value, text->value_len);
        }
    }
#endif

    TEXTID new_textid[2];
    new_textid[0] = text_id;
    new_textid[1] = TextID_Create(png_info, ENC_LAT1, TEXTID_ANY_LEN);

    mfree(png_info);
    png_destroy_chunk_data(png_data);

    return TextID_Create(new_textid, ENC_TEXTID, 2);
}