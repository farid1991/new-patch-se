set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(manual_eq)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" 
                src/dll.cpp
                src/eq.cpp
                src/gui.c
                src/patch.c
                src/patch.S
                )
target_link_libraries("J108_R7EA011_${PROJECT_NAME}" PRIVATE
                       aeabi_runtime
                       sync
                       )
define_patch(J108 R7EA011 A2 DB3350 0x14000000)
