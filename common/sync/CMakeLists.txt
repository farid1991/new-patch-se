add_library(sync STATIC sync.S)
add_library(async STATIC async.S)

target_include_directories(sync PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(async PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})