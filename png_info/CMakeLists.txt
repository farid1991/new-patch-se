set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(png_info)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" src/patch.c src/patch_a2.S)
define_patch(J108 R7EA011 A2 DB3350 0x14000000)

# K600_R2BB001
add_executable("K600_R2BB001_${PROJECT_NAME}" src/patch.c src/patch_a1.S)
define_patch(K600 R2BB001 A1 DB2000 0x20020000)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" src/patch.c src/patch_a2.S)
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}" src/patch.c src/patch_a1.S)
define_patch(W810 R4EA031 A1 DB2010 0x44140000)
