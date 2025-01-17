cmake_minimum_required(VERSION 3.15)

set(CMAKE_TOOLCHAIN_FILE ${CMAKE_CURRENT_SOURCE_DIR}/toolchain.cmake)

project(patch-se LANGUAGES C CXX ASM)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 98)
add_compile_options(-Os)

add_subdirectory(alarm_remaining_time)
add_subdirectory(db_pause)
add_subdirectory(phone_wo_sim)
add_subdirectory(phonebook_title)
add_subdirectory(replace_file_bt)
add_subdirectory(shutdown_menu)