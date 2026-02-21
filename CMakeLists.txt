cmake_minimum_required(VERSION 3.15)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch-se LANGUAGES C CXX ASM)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Os)

add_subdirectory(common/aeabi)
add_subdirectory(alarm_remaining_time)
add_subdirectory(db_pause)
add_subdirectory(flashmenu_picker)
add_subdirectory(fm_record)
add_subdirectory(phone_wo_sim)
add_subdirectory(phonebook_title)
add_subdirectory(remove_scrollbar)
add_subdirectory(replace_file_bt)
add_subdirectory(shutdown_menu)
add_subdirectory(volume_slider)