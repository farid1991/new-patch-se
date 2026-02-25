set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(bt_transmission)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" 
                src/dll.cpp 
                src/patch.c 
                src/patch.S 
                )
target_link_libraries("J108_R7EA011_${PROJECT_NAME}" PRIVATE  aeabi_runtime)
define_patch(J108 R7EA011 A2 DB3350 0x14000000)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" 
                src/patch.c 
                src/patch.S 
                )
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)