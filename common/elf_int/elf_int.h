#pragma once

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
	PROCESS (*current_process_int)(void);
	PROCESS (*get_bid_int)(PROCESS);
	OSADDRESS (*get_envp_int)(PROCESS, const char *);
} ose_func_t;

bool is_elfpack_installed(const ose_func_t *ose);

// #pragma swi_number=0x10D
int elfload_int(const wchar_t *filename, void *param1, void *param2, void *param3);

// #pragma swi_number=0x10E
void *LoadDLL_int(wchar_t *DllName);

// #pragma swi_number=0x10F
int UnLoadDLL_int(void *DllData);

#ifdef __cplusplus
}
#endif
