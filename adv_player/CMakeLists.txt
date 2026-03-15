set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(adv_player)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/target/)

# W700_R1CA021
add_executable("W700_R1CA021_${PROJECT_NAME}"
               src/patch.c
               src/data.c
               src/draw.c
               src/edit_tag.c
               src/id3_parser.c
               src/image.c
               src/skin_data.c
               src/skin_list.c
               src/skin_parser.c
               src/skin_selector.c
               src/str_helper.c
               src/timer.c
               src/toplevel.c
               src/track_desc.c
               src/visualizer.c
               src/patch_2010.S)
target_link_libraries("W700_R1CA021_${PROJECT_NAME}" PRIVATE 
                       aeabi_runtime
                       elf_int
                       sync
                       )
define_patch(W700 R1CA021 A1 DB2010 0x44020000)

# W810_R4EA031
add_executable("W810_R4EA031_${PROJECT_NAME}"
               src/patch.c
               src/data.c
               src/draw.c
               src/edit_tag.c
               src/id3_parser.c
               src/image.c
               src/skin_data.c
               src/skin_list.c
               src/skin_parser.c
               src/skin_selector.c
               src/str_helper.c
               src/timer.c
               src/toplevel.c
               src/track_desc.c
               src/visualizer.c
               src/patch_2010.S)
target_link_libraries("W810_R4EA031_${PROJECT_NAME}" PRIVATE 
                       aeabi_runtime
                       elf_int
                       sync
                       )
define_patch(W810 R4EA031 A1 DB2010 0x44140000)