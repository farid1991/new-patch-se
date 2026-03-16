#include <base.h>
#include <ose.h>

#include "elf_int.h"

static const char ELFPACK_DATA[] = "elfpackdata";

THUMB16
NEWCODE bool is_elfpack_installed(const ose_func_t *ose)
{
	return ose->get_envp_int(ose->get_bid_int(ose->current_process_int()), ELFPACK_DATA) != NULL;
}
