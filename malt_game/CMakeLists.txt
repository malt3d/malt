cmake_minimum_required(VERSION 3.5)
project(malt)

LIST(APPEND CMAKE_MODULE_PATH "../cmake/")
set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp game_impl.cpp game_impl.hpp)
add_executable(malt_game ${SOURCE_FILES})

target_include_directories(malt_game PUBLIC "../")

target_link_libraries(malt_game malt_core)
target_link_libraries(malt_game malt_sample)
target_link_libraries(malt_game malt_basic)
target_link_libraries(malt_game malt_render)
