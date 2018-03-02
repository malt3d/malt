cmake_minimum_required(VERSION 3.5)
project(malt)

LIST(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../malt_cmake/")
set(CMAKE_CXX_STANDARD 14)

include(Malt)

set(SOURCE_FILES
        main.cpp
        game_impl.cpp
        game_impl.hpp
        core_module.hpp
        core_module.cpp)

add_executable(malt_game ${SOURCE_FILES})

target_include_directories(malt_game PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")

malt_init()

malt_dependency(malt_game malt_core)
malt_dependency(malt_game malt_basic)
malt_dependency(malt_game malt_render)
malt_dependency(malt_game malt_asset)
