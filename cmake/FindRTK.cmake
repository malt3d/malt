find_path(RTK_INCLUDE_DIR
        NAMES rtk_fwd.hpp
        PATHS /usr/local/include /usr/include "${RTK_ROOT}")

find_library(RTK_LIBRARIES
        NAMES rtk
        PATHS /usr/local/lib /usr/lib "${RTK_ROOT}/build")

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(RTK DEFAULT_MSG RTK_INCLUDE_DIR)
if (RTK_FOUND)
    find_package(GLFW REQUIRED QUIET)
    find_package(GLM REQUIRED)
    find_package(OpenGL REQUIRED)
    find_package(assimp REQUIRED QUIET)
    find_package(Boost REQUIRED COMPONENTS system QUIET)

    if (NOT RTK_FIND_QUIETLY)
        message(STATUS "Found RTK in ${RTK_INCLUDE_DIR}")
    endif()

    set(GLAD_INCLUDE_DIR "${RTK_INCLUDE_DIR}/../glad/include/")
    message(STATUS "${GLAD_INCLUDE_DIR}")
    set(RTK_INCLUDE_DIRS "")
    list(APPEND RTK_INCLUDE_DIRS "${RTK_INCLUDE_DIR}/..")
    list(APPEND RTK_INCLUDE_DIRS "${GLFW_INCLUDE_DIRS}")
    list(APPEND RTK_INCLUDE_DIRS "${OPENGL_INCLUDE_DIR}")
    list(APPEND RTK_INCLUDE_DIRS "${assimp_INCLUDE_DIRS}")
    list(APPEND RTK_INCLUDE_DIRS "${BOOST_INCLUDE_DIRS}")
    list(APPEND RTK_INCLUDE_DIRS "${GLM_INCLUDE_DIRS}")
    list(APPEND RTK_INCLUDE_DIRS "${GLAD_INCLUDE_DIR}")

    list(APPEND RTK_LIBRARIES "${OPENGL_LIBRARIES}")
    list(APPEND RTK_LIBRARIES "${GLFW_LIBRARIES}")
    list(APPEND RTK_LIBRARIES "${assimp_LIBRARIES}")
    list(APPEND RTK_LIBRARIES "${BOOST_LIBRARIES}")
    list(APPEND RTK_LIBRARIES "m")
    list(APPEND RTK_LIBRARIES "dl")

    set(RTK_COMPILE_FLAGS "GLFW_INCLUDE_NONE=1")
endif()

mark_as_advanced(RTK_INCLUDE_DIR)