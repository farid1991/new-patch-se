cmake_minimum_required(VERSION 3.15)

# -----------------------------------------------------------------------------
# Cross-compile toolchain for Sony Ericsson A1/A2 platform
# -----------------------------------------------------------------------------
set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch-se LANGUAGES C CXX ASM)

# -----------------------------------------------------------------------------
# Global include directory for all patches
# -----------------------------------------------------------------------------
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

# -----------------------------------------------------------------------------
# Compiler configuration
# -----------------------------------------------------------------------------
set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Os)

# -----------------------------------------------------------------------------
# Common modules used by multiple patches
# -----------------------------------------------------------------------------
add_subdirectory(common/aeabi)
add_subdirectory(common/elf_int)
add_subdirectory(common/id3)
add_subdirectory(common/ini)
add_subdirectory(common/sync)

# -----------------------------------------------------------------------------
# Individual patch modules
# Each directory builds its own firmware patch
# -----------------------------------------------------------------------------
add_subdirectory(adv_player)
add_subdirectory(alarm_remaining_time)
add_subdirectory(book_manager)
add_subdirectory(brightness)
add_subdirectory(bt_transmission)
add_subdirectory(db_itemtext)
add_subdirectory(db_pause)
add_subdirectory(db_player)
add_subdirectory(db_redraw)
add_subdirectory(exif_info)
add_subdirectory(flashmenu_picker)
add_subdirectory(fm_record)
add_subdirectory(goto_shortcut)
add_subdirectory(manual_eq)
add_subdirectory(mp3_info)
add_subdirectory(phone_wo_sim)
add_subdirectory(phonebook_title)
add_subdirectory(png_info)
add_subdirectory(recycler)
add_subdirectory(remove_scrollbar)
add_subdirectory(replace_file_bt)
add_subdirectory(shutdown_menu)
add_subdirectory(sleepmode)
add_subdirectory(volume_redraw)
add_subdirectory(volume_slider)
