set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(db_redraw)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}"
                src/config_parser.c
                src/id3_parser.c
                src/patch.c
                src/patch.S
                )
target_link_libraries("W810_R4EA031_${PROJECT_NAME}" PRIVATE 
                       id3_helper
                       ini_helper
                       sync
                       aeabi_runtime
                       )
define_patch(W810 R4EA031 A1 DB2010 0x44140000)
