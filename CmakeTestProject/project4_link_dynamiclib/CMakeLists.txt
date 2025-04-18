cmake_minimum_required(VERSION 4.0.1)

set(PROJECTNAME "project4")
set(INC_DIR "./include/")
set(COMMON_DIR "../common")
set(SRC_DIR "./src")
set(COMMON_INC_DIR "${COMMON_DIR}/include")
set(COMMON_SRC_DIR "${COMMON_DIR}/src")

set(LIB_INC_DIR "../dynamiclib/include/"
)

set(SRCS)
set(COMMON_SRCS)

if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR 
    CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    string(APPEND PROJECTNAME "d") 
endif()
    
project(${PROJECTNAME})

aux_source_directory(${SRC_DIR} SRCS)
aux_source_directory(${COMMON_SRC_DIR} COMMON_SRCS)


add_executable(${PROJECTNAME})

target_include_directories( ${PROJECTNAME} 
                            PRIVATE ${INC_DIR} 
                            PRIVATE ${COMMON_INC_DIR}
                            PRIVATE ${LIB_INC_DIR}
)

target_sources( ${PROJECTNAME} 
                PRIVATE ${SRCS}
                PRIVATE ${COMMON_SRCS}
)

target_compile_definitions( ${PROJECTNAME}  PRIVATE
    # "_CRT_SECURE_NO_WARNINGS"
    PUBLIC
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
    $<$<CONFIG:RelWithDebInfo>:DEBUG>
    $<$<CONFIG:MinSizeRel>:RELEASE>
)


set(LIBLISTS)
set(LIBLISTS_TEMP)
set(LIB_DEBUG)
set(LIB_EXTENSION)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  # using Clang
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  # using GCC
    if(WIN32)
        set(LIB_EXTENSION ".dll.a")
    elseif (LINUX)
        set(LIB_EXTENSION ".so.a")
    endif()
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
    set(LIB_EXTENSION ".lib")
endif()

if (CMAKE_BUILD_TYPE STREQUAL "Debug" OR 
    CMAKE_BUILD_TYPE STREQUAL "RelWithDebInfo")
    set(LIB_DEBUG "d") 
endif()

list(APPEND LIBLISTS_TEMP 
                    "${BIN_DIR}/libdynamic"
)

foreach(item ${LIBLISTS_TEMP})
    list(APPEND LIBLISTS "${item}${LIB_DEBUG}${LIB_EXTENSION}")
endforeach()

target_link_libraries(${PROJECTNAME} ${LIBLISTS})

# message(FATAL_ERROR asd="${LIBLISTS}")

