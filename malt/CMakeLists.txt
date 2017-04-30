cmake_minimum_required(VERSION 3.5)
project(malt)

set(CMAKE_CXX_STANDARD 14)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

set(SOURCE_FILES component_mgr.cpp component_mgr.hpp component.cpp component.hpp entity.cpp entity.hpp module.cpp module.hpp malt_fwd.hpp game.cpp game.hpp list.hpp engine.hpp message.hpp utilities.hpp)
add_library(malt_core SHARED ${SOURCE_FILES})

target_include_directories(malt_core PUBLIC ../)