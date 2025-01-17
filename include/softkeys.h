#ifndef SOFTKEYS_H
#define SOFTKEYS_H

#include <bookobj.h>
#include <gui.h>
#include <list.h>
#include <textid.h>

typedef void (*SKACTIONPROC)(BOOK *, GUI *);

typedef enum
{
	UNDEFINED_SOFTKEY = -1,	  // See documentation for CreateSoftkey
	ABORT_SOFTKEY = 4011,	  // Predefined softkey for abort
	ACCEPT_SOFTKEY,			  // Predefined master softkey for the accept family: ok, save, done, continue...
	ADD_SOFTKEY,			  // Predefined softkey for add
	ADDITEM_SOFTKEY,		  // Predefined softkey for add item
	CANCEL_SOFTKEY,			  // Predefined softkey for cancel
	CHECK_SOFTKEY,			  // Predefined softkey for check
	CONTINUE_SOFTKEY,		  // Predefined softkey for continue
	CREATE_MORELIST_SOFTKEY,  // Predefined softkey for create more list
	DESTROY_MORELIST_SOFTKEY, // Predefined softkey for destroy more list
	DELETE_SOFTKEY,			  // Predefined softkey for delete
	DONE_SOFTKEY,			  // Predefined softkey for done
	EDIT_SOFTKEY,			  // Predefined softkey for edit
	HELP_SOFTKEY,			  // Predefined softkey for help
	HYPERLINK_SOFTKEY,		  // Predefined softkey for hyperlink
	INFO_SOFTKEY,			  // Predefined softkey for info
	INPUT_EMPTY_SOFTKEY,	  // Predefined softkey for empty input
	INPUT_NOT_EMPTY_SOFTKEY,  // Predefined softkey for not empty input
	KEYLOCK_SOFTKEY,		  // Predefined softkey for key lock
	MARKSEVERAL_SOFTKEY,	  // Predefined softkey for abort
	NO_SOFTKEY,				  // Predefined softkey for no
	OK_SOFTKEY,				  // Predefined softkey for OK
	PREVIOUS_SOFTKEY,		  // Predefined softkey for previous
	SAVE_SOFTKEY,			  // Predefined softkey for save
	SELECT_SOFTKEY,			  // Predefined softkey for select
	UNCHECK_SOFTKEY,		  // Predefined softkey for uncheck
	UNMARK_ALL_SOFTKEY,		  // Predefined softkey for unmark all
	YES_SOFTKEY,			  // Predefined softkey for yes
	LAST_SOFTKEY			  // Last softkey
} PredefinedSoftKeys;

typedef struct SKLABEL
{
	TEXTID text;
	uint16_t unk1;
	uint8_t unk2;
} SKLABEL;

typedef struct SOFTKEY_DESC_A2
{
	uint16_t action;
	uint16_t unk1;
	BOOK *book;
	DISP_OBJ *disp_object;
	void *IUIImage;
	TEXTID ButtonText;
	TEXTID MenuText;
	TEXTID DisabledMessage;
	TEXTID HelpText;
	TEXTID LongSKButtonText;
	uint16_t parent_action;
	uint16_t SubItemHighlight_action;
	LIST *subitems_list;
	void (*proc)(BOOK *, GUI *);
	void (*DisabledAction)(BOOK *, GUI *);
	uint8_t unk2[8];
	bool enable;
	bool visible;
	uint8_t SuppressDefaultAction;
	uint8_t unk3[49];
} SOFTKEY_DESC_A2;

typedef struct SOFTKEY_DESC
{
	uint16_t action;
	uint16_t unk1;
	BOOK *book;
	DISP_OBJ *disp_object;
	IMAGEID Icon;
	uint16_t unk2;
	TEXTID ButtonText;
	TEXTID MenuText;
	TEXTID DisabledMessage;
	TEXTID HelpText;
	uint16_t parent_action;
	uint16_t SubItemHighlight_action;
	LIST *subitems_list;
	void (*proc)(BOOK *, GUI *);
	void (*DisabledAction)(BOOK *, GUI *);
	uint8_t unk3[8];
	bool enable;
	bool visible;
	uint8_t SuppressDefaultAction;
	uint8_t unk4[49];
} SOFTKEY_DESC;

#ifdef __cplusplus
template <typename T, typename T2>
SKACTIONPROC MKSKACTIONPROC(void (*param)(T *, T2 *))
{
	INHERITANCECHECK<BOOK, T>();
	INHERITANCECHECK<GUI, T2>();
	return reinterpret_cast<SKACTIONPROC>(param);
}
#else
#define MKSKACTIONPROC(fn) (SKACTIONPROC) fn
#endif

#endif // SOFTKEYS_H