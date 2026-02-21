set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(flashmenu_picker)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" src/patch.c src/file_list.c src/patch.S)
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)