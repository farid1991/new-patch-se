#ifndef _WSTR_HELPER_H_
#define _WSTR_HELPER_H_

wchar_t *WStringAlloc(int Length);
void WStringAllocEx(wchar_t **Str, int Size);
void WStringReallocEx(wchar_t *Src, wchar_t **Dest, int Size);
void WStringRealloc(wchar_t *Src, wchar_t **Dest);
void WStringFilenameUnion(wchar_t **Filename, wchar_t *Path, wchar_t *Name);
void WStringExtractFileName(wchar_t *Str, wchar_t **Name);
void WStringStripExt(wchar_t *s);

#endif // _WSTR_HELPER_H_
