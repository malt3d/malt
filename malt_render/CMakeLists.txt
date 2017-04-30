cmake_minimum_required(VERSION 3.5)
project(malt)

LIST(APPEND CMAKE_MODULE_PATH "../cmake/")
set(CMAKE_CXX_STANDARD 14)

set(RTK_ROOT "/home/fatih/rtk/rtk")
find_package(RTK REQUIRED)

message(STATUS "${CMAKE_CXX_COMPILER_ID}")
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

set(SOURCE_FILES components/mesh_renderer.cpp components/mesh_renderer.hpp render_module.cpp render_module.hpp render_global.cpp render_global.hpp messages.hpp components/material.cpp components/material.hpp)
add_library(malt_render SHARED ${SOURCE_FILES})

set_target_properties(malt_render PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(malt_render PUBLIC "../")
target_include_directories(malt_render PUBLIC "../3rd_party/gsl/include")

message(STATUS "${RTK_INCLUDE_DIRS}")
target_include_directories(malt_render PUBLIC "${RTK_INCLUDE_DIRS}")
target_link_libraries(malt_render "${RTK_LIBRARIES}")
target_compile_definitions(malt_render PRIVATE "${RTK_COMPILE_FLAGS}")

target_link_libraries(malt_render malt_core)
target_link_libraries(malt_render malt_geometry)
