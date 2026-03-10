#if defined(J108_R7EA011)
#include <J108_R7EA011.h>
#elif defined(W760_R3EM001)
#include <W760_R3EM001.h>
#endif

#include <libse.h>
#include <types/UIRichText_types.h>

#include <book/ObExReceiveBook.h>
#include <book/ObExSendBook.h>

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
#include "dll.h"
#endif

extern int is_obexreceivebook(BOOK *book);
extern void refresh_statusrow();

// --- Status Row ------------------------------------------------------------

#define Default_StatusRow_OnRedraw ((void (*)(DISP_OBJ *, int, RECT *, int))ADDR_StatusRow_OnRedraw)

// --- ObEx pages ------------------------------------------------------------

#define pg_ObEx_ReceiveFile ((int (*)(void *, BOOK *))ADDR_pg_ObEx_ReceiveFile)

#define pg_ObEx_SendFile ((int (*)(void *, BOOK *))ADDR_pg_ObEx_SendFile)
#define pg_ObEx_SendMultipleFiles ((int (*)(void *, BOOK *))ADDR_pg_ObEx_SendMultipleFiles)

#define pg_ObEx_FileSent ((int (*)(void *, BOOK *))ADDR_pg_ObEx_FileSent)

#define IsObExSendBook ((int (*)(BOOK *))ADDR_IsObExSendBook)

static const wchar_t output_fmt[] = L"%d/%d KB";

THUMB16
NEWCODE int New_ObEx_ReceiveFile(void *obexdata, BOOK *book)
{
	pg_ObEx_ReceiveFile(obexdata, book);
	refresh_statusrow();
	return 1;
}

THUMB16
NEWCODE int New_ObEx_SendFile(void *data, BOOK *book)
{
	pg_ObEx_SendFile(data, book);
	refresh_statusrow();
	return 1;
}

#if defined(DB3350)
THUMB16
NEWCODE int New_ObEx_SendMultipleFiles(void *data, BOOK *book)
{
	pg_ObEx_SendMultipleFiles(data, book);
	refresh_statusrow();
	return 1;
}
#endif

THUMB16
NEWCODE int New_ObEx_FileSent(void *data, BOOK *book)
{
	pg_ObEx_FileSent(data, book);
	refresh_statusrow();
	return 1;
}

THUMB16
NEWCODE void display_to_statusrow(int current_kb, int total_kb)
{
	wchar_t buffer[32];

	// Format progress text
	snwprintf(buffer, MAXELEMS(buffer), output_fmt, current_kb, total_kb);

	// Background rectangle
	DrawRect(RECT_X1,    // x1
	         RECT_Y1,    // y1
	         RECT_X2,    // x2
	         RECT_Y2,    // y2
	         0xFF959595, // pen_color
	         0x80000000  // brush_color
	);

	TEXTID text_id = TextID_Create(buffer, ENC_UCS2, 32);

#if defined(DB3200) || defined(DB3210) || defined(DB3350)
	dll_DrawString(FONT_E_14B,
	               text_id,
	               AlignCenter, // align
	               STR_X1,      // x1
	               STR_Y1,      // y1
	               STR_X2,      // x2
	               STR_Y2,      // y2
	               0xFF000000   // pen_color
	);
#else
	SetFont(FONT_E_14B);
	DrawString(text_id,
	           AlignCenter, // align
	           STR_X1,      // x1
	           STR_Y1,      // y1
	           STR_X2,      // x2
	           STR_Y2,      // y2
	           0,           // unk text wrap?
	           1,           // unk1 text margin?
	           0xFF000000,  // pen_color
	           0xFF000000   // brush_color
	);
#endif
	TextID_Destroy(text_id);
}

THUMB16
NEWCODE void New_StatusRow_OnRedraw(DISP_OBJ *disp_obj, int r1, RECT *rect, int r3)
{
#if defined(A1)
	Default_StatusRow_OnRedraw(disp_obj, r1, rect, r3);
#endif

	BOOK *top_book = Display_GetTopBook(UIDisplay_Main);
	ObExSendBook *send_book = (ObExSendBook *)FindBook(IsObExSendBook);
	if (send_book)
	{
		if (top_book != (BOOK *)send_book)
			display_to_statusrow(send_book->file_sent / 1024, send_book->file_size / 1024);
	}

	ObExReceiveBook *receive_book = (ObExReceiveBook *)FindBook(is_obexreceivebook);
	if (receive_book)
	{
		if (top_book != (BOOK *)receive_book)
			display_to_statusrow(receive_book->file_received / 1024, receive_book->file_size / 1024);
	}
}
