cmake_minimum_required(VERSION 3.15)

set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(shutdown_menu)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# J20_R7CA064
add_executable("J20_R7CA064_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(J20 R7CA064 A2 DB3350 0x14000000)

# J108_R7EA011
add_executable("J108_R7EA011_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(J108 R7EA011 A2 DB3350 0x14000000)

# U10_R7AA071
add_executable("U10_R7AA071_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(U10 R7AA071 A2 DB3350 0x14000000)

# U100_R7AA076
add_executable("U100_R7AA076_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(U100 R7AA076 A2 DB3350 0x14000000)

# W20_R7DA062
add_executable("W20_R7DA062_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W20 R7DA062 A2 DB3350 0x14000000)