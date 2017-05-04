cmake_minimum_required(VERSION 3.5)

function(malt_find_module module_name)
    list(APPEND MALT_SEARCH_DIRS "${CMAKE_BINARY_DIR}/../")
    list(APPEND MALT_SEARCH_DIRS "${CMAKE_BINARY_DIR}/../../")
    list(APPEND MALT_SEARCH_DIRS "${CMAKE_BINARY_DIR}/../../")

    if (${module_name} MATCHES "malt_core")
        foreach(DIR ${MALT_SEARCH_DIRS})
            list(APPEND MALT_LIB_SEARCH_DIRS "${DIR}/malt_core/")
        endforeach()
        find_library(MODULE_DIR malt_core ${MALT_LIB_SEARCH_DIRS} NO_DEFAULT_PATH)
    else()
        find_path(
            MODULE_DIR
            "malt_modules/${module_name}/module.json"
            PATHS ${MALT_SEARCH_DIRS}
            NO_DEFAULT_PATH
            NO_CMAKE_FIND_ROOT_PATH
        )
        set(MODULE_DIR "${MODULE_DIR}/malt_modules/${module_name}")
    endif()

    if (NOT MODULE_DIR MATCHES "NOTFOUND")
        message(STATUS "${module_name} path: ${MODULE_DIR}")

        find_library(MODULE_LIB ${module_name} ${MODULE_DIR})
        set(${module_name}_INCLUDE_DIRS "${MODULE_DIR}/include" PARENT_SCOPE)
        set(${module_name}_LIBRARIES "${MODULE_LIB}" PARENT_SCOPE)
    else()
        message(STATUS "${module_name} not found")
    endif()

    unset(MALT_SEARCH_DIRS)
    unset(MALT_LIB_SEARCH_DIRS)
    unset(MODULE_DIR CACHE)
endfunction()

function(malt_def_module module_name)
    configure_file(${CMAKE_CURRENT_SOURCE_DIR}/module.json ${CMAKE_BINARY_DIR}/module.json COPYONLY)
endfunction()

function(malt_init)
    add_custom_target(
        init_build
        COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/../malt_tooling/build_init.py
    )
    add_dependencies(malt_game init_build)
endfunction()

function(malt_add_module to module_name)
    find_package(${module_name} REQUIRED)

    add_custom_target(
        preprocess_${module_name}
        COMMAND python3 ${CMAKE_CURRENT_SOURCE_DIR}/../malt_tooling/list_messages.py $<TARGET_FILE:${module_name}> ${CMAKE_BINARY_DIR}/msg_list.txt
    )

    target_link_libraries(${to} PUBLIC ${module_name})
    add_dependencies(${to} preprocess_${module_name})
endfunction()

function(malt_install _target HEADER_PATH)
    set(INCLUDE_DEST "include")
    set(LIB_DEST "lib/${_target}")

    target_include_directories(${_target} PUBLIC
            $<BUILD_INTERFACE:${HEADER_PATH}/../>
            $<INSTALL_INTERFACE:${INCLUDE_DEST}>)

    install(TARGETS ${_target} DESTINATION "${LIB_DEST}")
    install(FILES ${_target}-config.cmake DESTINATION ${LIB_DEST})
    install(DIRECTORY ${HEADER_PATH} DESTINATION "${INCLUDE_DEST}")

    install(TARGETS ${_target} EXPORT ${_target} DESTINATION "${LIB_DEST}")
    install(EXPORT ${_target} DESTINATION "${LIB_DEST}")
endfunction()