cmake_minimum_required(VERSION 3.5)
project(malt)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES component_mgr.cpp component_mgr.hpp component.cpp component.hpp entity.cpp entity.hpp module.cpp module.hpp malt_fwd.hpp game.cpp game.hpp)
add_library(malt SHARED ${SOURCE_FILES})

target_include_directories(malt PUBLIC ../)