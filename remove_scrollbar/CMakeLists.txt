cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(remove_scrollbar)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# K800_R8BF003
add_executable("K800_R8BF003_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(K800 R8BF003 A1 DB2020 0x44140000)