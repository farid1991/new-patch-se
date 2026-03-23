add_library(id3_helper STATIC 
            id3_header.c
            id3_cover.c
            )

target_include_directories(id3_helper PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
