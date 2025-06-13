function(linker _target _obj _direction)

target_include_directories(
    ${_target} PUBLIC
    "${_direction}/${_obj}"
)

if (NOT TARGET ${_obj})
    add_subdirectory(${_direction}/${_obj} ${CMAKE_BINARY_DIR}/${_obj})
endif()

target_link_libraries(${_target} PUBLIC ${_obj})

endfunction()