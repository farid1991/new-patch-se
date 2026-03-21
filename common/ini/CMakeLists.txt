add_library(ini_helper STATIC ini_parser.c)

target_include_directories(ini_helper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
