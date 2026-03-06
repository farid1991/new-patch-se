set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(phone_wo_sim)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# C510_R1HA035
add_executable("C510_R1HA035_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(C510 R1HA035 A2 DB3210 0x14000000)

# U10_R7AA071
add_executable("U10_R7AA071_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(U10 R7AA071 A2 DB3350 0x14000000)

# U10_R7BA084
add_executable("U10_R7BA084_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(U10 R7BA084 A2 DB3350 0x14000000)

# W995_R1HA035
add_executable("W995_R1HA035_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W995 R1HA035 A2 DB3210 0x14000000)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W810 R4EA031 A1 DB2010 0x44140000)

# Z780_R3DA028
add_executable("Z780_R3DA028_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(Z780 R3DA028 A2 DB3150v2 0x10000000)

# Z310_R8BA024
add_executable("Z310_R8BA024_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(Z310 R8BA024 A1 PNX5230 0x20100000)

# W760_R3EM001
add_executable("W760_R3EM001_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W760 R3EM001 A2 DB3150v2 0x10000000)

# W550_R4CB020
add_executable("W550_R4CB020_${PROJECT_NAME}" src/patch.c src/patch.S)
define_patch(W550 R4CB020 A1 DB2010 0x440A0000)