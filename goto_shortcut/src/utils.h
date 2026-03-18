#ifndef _UTILS_H_
#define _UTILS_H_

static const wchar_t MAINMENU_STR[] = L"MainMenu";

void RunShortcut(SC_LIST_ELEM *Shortcut);
void list_destroy(LIST **List, void (*FreeProc)(void *Item));
void java_list_free_item(void *item);
LIST *java_list_create();
void SaveConfig(LIST *List);
LIST *LoadConfig();

#endif // _UTILS_H_
