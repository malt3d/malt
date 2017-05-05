cmake_minimum_required(VERSION 3.5)
project(malt)

set(MALT_BUILD_IN_SOURCE True)

set(CMAKE_PREFIX_PATH "${CMAKE_SOURCE_DIR}/malt_modules/")

add_subdirectory(malt)
add_subdirectory(sample)
add_subdirectory(malt_basic)
add_subdirectory(malt_util)
add_subdirectory(malt_render)
add_subdirectory(malt_game)
