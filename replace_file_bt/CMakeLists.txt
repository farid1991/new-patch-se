cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(replace_file_bt)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# C510_R1HA035
add_executable("C510_R1HA035_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(C510 R1HA035 A2 DB3210 0x14000000)

# U10_R7AA071
add_executable("U10_R7AA071_${PROJECT_NAME}" src/patch.c src/db3350.S)
define_patch(U10 R7AA071 A2 DB3350 0x14000000)

# U100_R7AA076
add_executable("U100_R7AA076_${PROJECT_NAME}" src/patch.c src/db3350.S)
define_patch(U100 R7AA076 A2 DB3350 0x14000000)