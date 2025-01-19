cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(fm_record)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# C510_R1HA035
add_executable("C510_R1HA035_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(C510 R1HA035 A2 DB3210 0x14000000)