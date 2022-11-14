cmake_minimum_required(VERSION 3.14)

function(format_source_group)
    foreach(_source IN ITEMS ${ARGN})
        if (IS_ABSOLUTE "${_source}")
            file(RELATIVE_PATH _source_rel "${CMAKE_CURRENT_SOURCE_DIR}" "${_source}")
        else()
            set(_source_rel "${_source}")
        endif()
        get_filename_component(_source_path "${_source_rel}" PATH)
        string(REGEX REPLACE "^sources" "" _source_pathp "${_source_path}")
        string(REPLACE "/" "\\" _source_path_msvc "${_source_pathp}")
        source_group("${_source_path_msvc}" FILES "${_source}")
    endforeach()
endfunction(format_source_group)
