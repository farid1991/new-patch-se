#ifndef _EDITOR_H_
#define _EDITOR_H_

static const char GuiColor_Name[] = "GUI_Color";

#define FONT_STEP 1
#define MAX_SIZE 100
#define BOLD 1
#define ITALIC 2

typedef struct DISP_OBJ_COLOR
{
	DISP_OBJ disp;
	uint8_t r, g, b, a;
	uint8_t type;
	uint8_t need_str;
	uint8_t current_column;
	uint8_t cstep;
	TEXTID buf_text;
} DISP_OBJ_COLOR;

void SetActivate(BOOK *m_bk, int count);
void OneOfMany_SetMode(BOOK *m_bk, int type);
void SetColor(BOOK *m_bk, int type);
void SetActiveSoftkeys(BOOL mode);
const wchar_t *Font_GetNameByFontId(int id);
int GetIdByFontId(int id);
void SetVisual(BOOK *m_bk);

#endif
