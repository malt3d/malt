cmake_minimum_required(VERSION 3.5)
project(malt)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES components/simple.cpp components/simple.hpp sample_module.cpp sample_module.hpp components/test.cpp components/test.hpp)
add_library(malt_sample SHARED ${SOURCE_FILES})

set_target_properties(malt_sample PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(malt_sample PUBLIC "../")
target_link_libraries(malt_sample malt_core)