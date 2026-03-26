#include "device.h"

#include <libse.h>
#include <sync.h>

#include "data.h"
#include "image.h"
#include "skin_data.h"

THUMB16
NEWCODE void image_register(IMAGE_DESC *img_desc, const wchar_t *path, const wchar_t *fname)
{
	char err;
	img_desc->id = NOIMAGE;
	img_desc->handle = NOIMAGE;
	img_desc->exist = TRUE;

	if (!REQUEST_IMAGEHANDLER_INTERNAL_GETHANDLE(&SYNC, &img_desc->handle, &err))
		if (!REQUEST_IMAGEHANDLER_INTERNAL_REGISTER(
		            &SYNC, img_desc->handle, path, fname, 0, &img_desc->id, &err))
			if (err)
				img_desc->exist = FALSE;
}

THUMB16
NEWCODE void image_unregister(IMAGE_DESC *img_desc)
{
	if ((img_desc->id != NOIMAGE) && img_desc->exist)
	{
		char err;
		REQUEST_IMAGEHANDLER_INTERNAL_UNREGISTER(&SYNC, img_desc->handle, NULL, NULL, img_desc->id, 1, &err);
		img_desc->id = NOIMAGE;
		img_desc->handle = NOIMAGE;
		img_desc->exist = FALSE;
	}
}
