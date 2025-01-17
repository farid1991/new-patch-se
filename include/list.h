#ifndef LIST_H
#define LIST_H

#include <base.h>

typedef struct LIST
{
	uint16_t unk;
	uint16_t FirstFree;
	void **listdata;
} LIST;

typedef int (*LISTFINDCALLBACK)(void *listitem, void *itemtofind);

#define LIST_ERROR 0xFFFF

#ifdef __cplusplus
template <typename T, typename T2>
LISTFINDCALLBACK MKLISTFINDCALLBACK(int (*param)(T, T2))
{
	return reinterpret_cast<LISTFINDCALLBACK>(param);
}
#else
#define MKLISTFINDCALLBACK(fn) (LISTFINDCALLBACK) fn
#endif

#define LIST_FIND(lst, itemtofind, cmp_proc) List_Find(lst, (void *)itemtofind, MKLISTFINDCALLBACK(cmp_proc))

#endif // LIST_H