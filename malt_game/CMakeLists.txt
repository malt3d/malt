cmake_minimum_required(VERSION 3.5)
project(malt_test)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp)
add_executable(malt_game ${SOURCE_FILES})

target_include_directories(malt_test PUBLIC "../")

target_link_libraries(malt_game malt)
target_link_libraries(malt_game malt_test)
