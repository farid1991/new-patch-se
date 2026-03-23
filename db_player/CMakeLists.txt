set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(db_player)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" 
                src/dll.cpp
                src/data.c
                src/draw.c
                src/editor.c
                src/info.c
                src/lang.c
                src/lyric.c
                src/settings.c
                src/str_helper.c
                src/time.c
                src/patch.c
                src/patch_3350.S 
                )
target_link_libraries("J108_R7EA011_${PROJECT_NAME}" PRIVATE 
                       sync 
                       elf_int
                       id3_helper
                       aeabi_runtime 
                       )
define_patch(J108 R7EA011 A2 DB3350 0x14000000)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" 
                src/dll.cpp
                src/data.c
                src/draw.c
                src/editor.c
                src/info.c
                src/lang.c
                src/lyric.c
                src/settings.c
                src/str_helper.c
                src/time.c
                src/patch.c
                src/patch_3150.S 
                )
target_link_libraries("W760_R3EM001_${PROJECT_NAME}" PRIVATE 
                       sync 
                       elf_int
                       id3_helper
                       aeabi_runtime
                       )
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)
