cmake_minimum_required(VERSION 3.0)

set(OBJ_NAME "common_module2")
set(INC_DIR ".")
set(SRC_DIR ".")
set(COMMON_DIR "../")

set(SRCS)

#aux_source_directory(${SRC_DIR} SRCS)
file(GLOB SRCS CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.cxx")

SET_SOURCE_FILES_PROPERTIES($(SRCS) PROPERTIES LANGUAGE CXX)

project(${OBJ_NAME})

# library [ STATIC | SHARED | MODULE ]
add_library(${OBJ_NAME} SHARED)

target_include_directories( 
    ${OBJ_NAME} 
    PUBLIC ${INC_DIR} 
    PUBLIC ${COMMON_DIR} 
)

target_sources( ${OBJ_NAME} PUBLIC ${SRCS} )

target_compile_definitions( ${OBJ_NAME}  PUBLIC
    #""
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
    $<$<CONFIG:RelWithDebInfo>:DEBUG>
    $<$<CONFIG:MinSizeRel>:RELEASE>
)