cmake_minimum_required(VERSION 3.5)
project(malt)

LIST(APPEND CMAKE_MODULE_PATH "../cmake/")
set(CMAKE_CXX_STANDARD 14)

set(RTK_ROOT "/home/fatih/rtk/rtk")
find_package(RTK REQUIRED)
find_package(SOIL REQUIRED)

message(STATUS "${CMAKE_CXX_COMPILER_ID}")
if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    set(CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS "${CMAKE_SHARED_LIBRARY_CREATE_CXX_FLAGS} -undefined dynamic_lookup")
endif()

set(SOURCE_FILES components/mesh_renderer.cpp components/mesh_renderer.hpp render_module.cpp render_module.hpp
        render_global.cpp render_global.hpp messages.hpp components/material.cpp components/material.hpp
        components/render_test.cpp components/render_test.h components/lights/directional_light.cpp
        components/lights/directional_light.hpp components/lights/point_light.cpp components/lights/point_light.hpp
        render_ctx.hpp
        components/camera.cpp components/camera.hpp texture/tex2d.cpp texture/tex2d.hpp)

add_library(malt_render SHARED ${SOURCE_FILES})

set_target_properties(malt_render PROPERTIES POSITION_INDEPENDENT_CODE ON)
target_include_directories(malt_render PUBLIC "../")
target_include_directories(malt_render PUBLIC "../3rd_party/gsl/include")

message(STATUS "${RTK_INCLUDE_DIRS}")
target_include_directories(malt_render PUBLIC "${RTK_INCLUDE_DIRS}")
target_link_libraries(malt_render "${RTK_LIBRARIES}")
target_compile_definitions(malt_render PRIVATE "${RTK_COMPILE_FLAGS}")

target_include_directories(malt_render PUBLIC "${SOIL_INCLUDE_DIR}")
target_link_libraries(malt_render "${SOIL_LIBRARY}")

target_compile_definitions(malt_render PUBLIC GLM_ENABLE_EXPERIMENTAL=1)

target_link_libraries(malt_render malt_core)
target_link_libraries(malt_render malt_basic)
