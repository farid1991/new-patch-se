set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(goto_shortcut)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}"
                src/editor.c 
                src/fs_browser.c 
                src/patch.c 
                src/utils.c 
                src/wstr_helper.c 
                src/patch.S
                )
target_link_libraries("W760_R3EM001_${PROJECT_NAME}" PRIVATE 
                       sync
                       async
                       elf_int
                       )
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}"
                src/editor.c 
                src/fs_browser.c 
                src/patch.c 
                src/utils.c 
                src/wstr_helper.c 
                src/patch.S
                )
target_link_libraries("W810_R4EA031_${PROJECT_NAME}" PRIVATE 
                       sync
                       async
                       elf_int
                       )
define_patch(W810 R4EA031 A1 DB2010 0x44140000)
