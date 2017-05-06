cmake_minimum_required(VERSION 3.5)
project(malt)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../malt_cmake/")
set(CMAKE_CXX_STANDARD 14)

include(Malt)

set(SOURCE_FILES main.cpp game_impl.cpp)
add_executable(malt_game ${SOURCE_FILES})

malt_init()
malt_add_module(malt_game malt_core)
malt_add_module(malt_game malt_basic)
malt_add_module(malt_game malt_render)
