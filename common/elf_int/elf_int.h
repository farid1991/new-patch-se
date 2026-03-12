#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// #pragma swi_number=0x10D
int elfload_int(const wchar_t *filename, void *param1, void *param2, void *param3);

// #pragma swi_number=0x10E
void* LoadDLL_int( wchar_t* DllName );

// #pragma swi_number=0x10F
int UnLoadDLL_int( void* DllData );

#ifdef __cplusplus
}
#endif
