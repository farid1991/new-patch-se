set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(db_pause)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# C510_R1HA035
add_executable("C510_R1HA035_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(C510 R1HA035 A2 DB3210 0x14000000)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(J108 R7EA011 A2 DB3350 0x14000000)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)