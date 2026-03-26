#include "device.h"

#include <libse.h>

#include "patch.h"
#include "tag_list.h"

THUMB16
NEWCODE int tag_list_item_filter(void *elem)
{
	return (elem != NULL);
}

THUMB16
NEWCODE void tag_list_remove_elem(void *item)
{
	TAG_LIST_ELEM *tag_elem = (TAG_LIST_ELEM *)item;
	if (tag_elem)
	{
		mfree(tag_elem->name);
		mfree(tag_elem->value);
		mfree(tag_elem);
	}
}

THUMB16
NEWCODE void tag_list_destroy(LIST **list, void (*free_list)(void *item))
{
	if (*list)
	{
		List_DestroyElements(*list, tag_list_item_filter, free_list);
		List_Destroy(*list);
		*list = NULL;
	}
}

THUMB16
NEWCODE TAG_LIST_ELEM *tag_list_create_elem(int tag, char *name, char *value)
{
	TAG_LIST_ELEM *tag_elem = (TAG_LIST_ELEM *)malloc(sizeof(TAG_LIST_ELEM));
	if (!tag_elem)
		return NULL;

	tag_elem->tag = tag;

	tag_elem->name_len = strlen(name) + 1;
	tag_elem->name = (char *)malloc(tag_elem->name_len);
	memset(tag_elem->name, 0, tag_elem->name_len);
	strncpy(tag_elem->name, name, tag_elem->name_len);

	tag_elem->value_len = strlen(value) + 1;
	tag_elem->value = (char *)malloc(tag_elem->value_len);
	memset(tag_elem->value, 0, tag_elem->value_len);
	strncpy(tag_elem->value, value, tag_elem->value_len);

	return tag_elem;
}
