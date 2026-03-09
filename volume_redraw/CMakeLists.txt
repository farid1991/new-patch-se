set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(volume_redraw)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# C510_R1HA035
add_executable("C510_R1HA035_${PROJECT_NAME}" src/dll.cpp src/patch.c src/patch.S)
target_link_libraries("C510_R1HA035_${PROJECT_NAME}" PRIVATE aeabi_runtime sync)
define_patch(C510 R1HA035 A2 DB3210 0x14000000)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" src/patch.c src/patch.S)
target_link_libraries("W760_R3EM001_${PROJECT_NAME}" PRIVATE aeabi_runtime sync)
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}" src/patch.c src/patch.S)
target_link_libraries("W810_R4EA031_${PROJECT_NAME}" PRIVATE aeabi_runtime sync)
define_patch(W810 R4EA031 A1 DB2010 0x44140000)