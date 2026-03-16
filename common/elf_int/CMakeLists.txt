add_library(elf_int STATIC 
            dll_int.c 
            elf_int.c 
            elf_check.c
            )

target_include_directories(elf_int PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
