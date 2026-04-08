set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(recycler)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}"
                src/patch.c
                src/patch_3350.S
                )
define_patch(J108 R7EA011 A2 DB3350 0x14000000)
