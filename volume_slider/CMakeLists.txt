set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(volume_slider)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" 
                src/patch.c 
                src/dll.cpp
                src/slider.c
                src/patch.S 
                )
target_link_libraries("J108_R7EA011_${PROJECT_NAME}" PRIVATE aeabi_runtime)
define_patch(J108 R7EA011 A2 DB3350 0x14000000)