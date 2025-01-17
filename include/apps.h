#ifndef APPS_H
#define APPS_H

#include <ose.h>
#include <bookobj.h>

typedef struct APP_DESC
{
	int (*SigHandler)(union SIGNAL **sig);
	PAGE_DESC *default_page;
	char *name;
	int (*MsgHandler)(void *msg);
	char *(*GetMsgName)(int);
} APP_DESC;

#endif // APPS_H