set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(exif_info)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# C510_R1HA035
add_executable("C510_R1HA035_${PROJECT_NAME}" 
                src/nanoexif.c 
                src/tag_list.c 
                src/tag_parser.c 
                src/patch.c 
                src/patch_a2.S 
                )
target_link_libraries("C510_R1HA035_${PROJECT_NAME}" PRIVATE aeabi_runtime)
define_patch(C510 R1HA035 A2 DB3210 0x14000000)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" 
                src/nanoexif.c 
                src/tag_list.c 
                src/tag_parser.c 
                src/patch.c 
                src/patch_a2.S 
                )
target_link_libraries("J108_R7EA011_${PROJECT_NAME}" PRIVATE aeabi_runtime)
define_patch(J108 R7EA011 A2 DB3350 0x14000000)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" 
                src/nanoexif.c 
                src/tag_list.c 
                src/tag_parser.c 
                src/patch.c 
                src/patch_a2.S 
                )
target_link_libraries("W760_R3EM001_${PROJECT_NAME}" PRIVATE aeabi_runtime)
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}" 
                src/nanoexif.c 
                src/tag_list.c 
                src/tag_parser.c 
                src/patch.c 
                src/patch_a1.S 
                )
target_link_libraries("W810_R4EA031_${PROJECT_NAME}" PRIVATE aeabi_runtime)
define_patch(W810 R4EA031 A1 DB2010 0x44140000)