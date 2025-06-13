function(linker _target _obj_name _direction)

target_include_directories(
    ${_target} PUBLIC
    "${_direction}"
)

if (NOT TARGET ${_obj_name})
    add_subdirectory(${_direction} ${CMAKE_BINARY_DIR}/${_obj_name})
endif()

target_link_libraries(${_target} PUBLIC ${_obj_name})

endfunction()