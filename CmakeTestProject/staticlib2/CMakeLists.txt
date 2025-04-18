cmake_minimum_required(VERSION 4.0.1)
set(PROJECTNAME "static2")
set(INC_DIR "./include/")
set(SRC_DIR "./src")

set(SRCS)

if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR 
    CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    string(APPEND PROJECTNAME "d") 
endif()

project(${PROJECTNAME})

aux_source_directory(${SRC_DIR} SRCS)

# library [ STATIC | SHARED | MODULE ]
add_library(${PROJECTNAME} STATIC)

target_include_directories( ${PROJECTNAME} 
                            PRIVATE ${INC_DIR} 
)

target_sources( ${PROJECTNAME} 
                PRIVATE ${SRCS}
)

target_compile_definitions( ${PROJECTNAME}  PRIVATE
    #""
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
    $<$<CONFIG:RelWithDebInfo>:DEBUG>
    $<$<CONFIG:MinSizeRel>:RELEASE>
)
