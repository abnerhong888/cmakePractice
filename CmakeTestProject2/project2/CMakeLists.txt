cmake_minimum_required(VERSION 3.0)

set(PROJECTNAME "project2")
set(INC_DIR ".")
set(SRC_DIR ".")
set(COMMON_DIR "../common/")

set(SRCS)

#aux_source_directory(${SRC_DIR} SRCS)
file(GLOB SRCS CONFIGURE_DEPENDS "${SRC_DIR}/*.cpp" "${SRC_DIR}/*.cxx")

SET_SOURCE_FILES_PROPERTIES($(SRCS) PROPERTIES LANGUAGE CXX)

project(${PROJECTNAME})

add_executable(${PROJECTNAME})

target_include_directories( ${PROJECTNAME} 
                            PUBLIC ${INC_DIR} 
                            PUBLIC ${COMMON_DIR}
)

target_sources( ${PROJECTNAME} 
                PUBLIC ${SRCS}
)

include(../global.cmake)

include(${LINKER_DIR})
linker(${PROJECTNAME} common_module1 ${SOLUTION_DIR}/common)
linker(${PROJECTNAME} common_module2 ${SOLUTION_DIR}/common)

linker(${PROJECTNAME} test_module1 .)
linker(${PROJECTNAME} test_module2 .)

target_compile_definitions( ${PROJECTNAME}  PUBLIC
    # "_CRT_SECURE_NO_WARNINGS"
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
    $<$<CONFIG:RelWithDebInfo>:DEBUG>
    $<$<CONFIG:MinSizeRel>:RELEASE>
)