cmake_minimum_required(VERSION 3.5)
project(malt)

LIST(APPEND CMAKE_MODULE_PATH "../cmake/")
set(CMAKE_CXX_STANDARD 14)

find_package(GLM REQUIRED)

message(STATUS "${CMAKE_CXX_COMPILER_ID}")
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

set(SOURCE_FILES mesh.hpp mesh.cpp)
add_library(malt_geometry SHARED ${SOURCE_FILES})

set_target_properties(malt_geometry PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(malt_geometry PUBLIC "../")
target_include_directories(malt_geometry PUBLIC "../3rd_party/gsl/include")
target_link_libraries(malt_geometry malt_core)

target_compile_definitions(malt_geometry PUBLIC GLM_ENABLE_EXPERIMENTAL=1)