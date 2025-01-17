cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(phone_wo_sim)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# C510_R1HA035
add_executable("C510_R1HA035_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(C510 R1HA035 A2 DB3210 0x14000000)

# U10_R7AA071
add_executable("U10_R7AA071_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(U10 R7AA071 A2 DB3350 0x14000000)

# U10_R7BA084
add_executable("U10_R7BA084_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(U10 R7BA084 A2 DB3350 0x14000000)

# W995_R1HA035
add_executable("W995_R1HA035_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W995 R1HA035 A2 DB3210 0x14000000)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W810 R4EA031 A1 DB2010 0x44140000)