add_library(aeabi_runtime STATIC
    aeabi_i2f.S
    aeabi_idiv.c
    aeabi_idivmod.S
    aeabi_uidiv.c
    aeabi_uidivmod.S
    udivmodsi4.c
)

set_source_files_properties(
    aeabi_i2f.S
    aeabi_idiv.c
    aeabi_idivmod.S
    aeabi_uidiv.c
    aeabi_uidivmod.S
    udivmodsi4.c
    PROPERTIES COMPILE_FLAGS "-marm"
)
