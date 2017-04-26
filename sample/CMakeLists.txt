cmake_minimum_required(VERSION 3.5)
project(malt_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES components/simple.cpp components/simple.hpp sample_module.cpp sample_module.hpp components/test.cpp components/test.hpp)
add_library(malt_test SHARED ${SOURCE_FILES})

target_include_directories(malt_test PUBLIC "../")
target_link_libraries(malt_test malt)