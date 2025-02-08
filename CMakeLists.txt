cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RTRP LANGUAGES CXX VERSION 5.0.1)

file(GLOB SOURCES
    src/*.cpp
)

file(GLOB INCLUDE_HEADERS
    include/rtrp/types/*.hpp
    include/rtrp/objects/*.hpp
    include/rtrp/*.hpp
)

add_library(${PROJECT_NAME} SHARED STATIC ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${INCLUDE_HEADERS}")
target_sources(${PROJECT_NAME} PRIVATE ${SOURCES})
target_include_directories(${PROJECT_NAME}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(cmake/git.cmake)
message("Getting modules\n")
include(cmake/ltresult.cmake)

if (PROJECT_IS_TOP_LEVEL)
    if (NOT CMAKE_GENERATOR MATCHES "Visual Studio")
        add_compile_options("$<$<CONFIG:DEBUG>:-fsanitize=address,undefined>")
        add_link_options("$<$<CONFIG:DEBUG>:-fsanitize=address,undefined>")
    endif()
    target_compile_options(RTRP PRIVATE
        $<$<CXX_COMPILER_ID:MSVC>:/W4>
        $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wno-gnu-statement-expression-from-macro-expansion>
    )
    add_subdirectory(tests)
    # add_subdirectory(tests/manual)
endif()
