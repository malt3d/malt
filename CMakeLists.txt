cmake_minimum_required(VERSION 3.5)
project(malt)

set(MALT_BUILD_IN_SOURCE True)

list(APPEND CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/malt_modules/")
list(APPEND CMAKE_PREFIX_PATH "/home/fatih/rtk_build/")

add_subdirectory(malt_core)
add_subdirectory(malt_basic)
add_subdirectory(malt_util)
add_subdirectory(malt_asset)
add_subdirectory(malt_render)
add_subdirectory(malt_anim)
add_subdirectory(malt_game)
