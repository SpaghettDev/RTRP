cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RTRP LANGUAGES CXX VERSION 2.2.0)

set(NAMESPACE_NAME "rtrp")

file(GLOB SOURCES
    src/*.cpp
    src/*.hpp
)

file(GLOB INCLUDE_HEADERS
    include/rtrp/impl/*.hpp
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
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)
