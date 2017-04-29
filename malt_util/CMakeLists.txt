cmake_minimum_required(VERSION 3.5)
project(malt)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES util.cpp buffer.hpp)

add_library(malt_util SHARED ${SOURCE_FILES})
