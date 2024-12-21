cmake_minimum_required(VERSION 3.11)
project(large_bit_mask)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/out)

if ("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_CURRENT_SOURCE_DIR}")
  set(API_IS_MAIN TRUE)
else()
  set(API_IS_MAIN FALSE)
endif()

option(BUILD_SHARED_LIBS "Build shared lib" OFF)
option(BUILD_TEST "Build unit test" ON)
option(BUILD_EXAMPLES "Build examples" ${API_IS_MAIN})

set(large_bit_mask_headers
    include/large_bit_mask.h
)

set(large_bit_mask_sources
    src/large_bit_mask.c
)

add_library(large_bit_mask ${large_bit_mask_headers} ${large_bit_mask_sources})

if(BUILD_SHARED_LIBS)
    message(STATUS "Build shared lib for extended api")
    if (WIN32)
        target_compile_definitions(large_bit_mask
                                   PRIVATE $<BUILD_INTERFACE:BUILD_LIBTYPE_SHARED>
                                   INTERFACE $<INSTALL_INTERFACE:USE_LIBTYPE_SHARED>
                                   )
    endif ()
    set_property(TARGET large_bit_mask PROPERTY POSITION_INDEPENDENT_CODE ON)
else()
    message(STATUS "Build static lib for extended api")
endif()

target_include_directories(large_bit_mask
    PUBLIC 
        $<INSTALL_INTERFACE:include>
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>

)

if(${BUILD_EXAMPLES})
    add_subdirectory(examples)
endif(${BUILD_EXAMPLES})

if(${BUILD_TEST})
enable_testing()
add_subdirectory(test)
endif(${BUILD_TEST})