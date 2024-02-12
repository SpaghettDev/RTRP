cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RTRP LANGUAGES CXX VERSION 1.1.0)

set(NAMESPACE_NAME "rtrp")

file(GLOB SOURCES
    src/*.cpp
    src/*.hpp
)

file(GLOB INCLUDE_HEADERS
    include/types/*.hpp
    include/objects/*.hpp
    include/*.hpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(${NAMESPACE_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${INCLUDE_HEADERS}")
target_sources(${PROJECT_NAME} PRIVATE ${INCLUDE_HEADERS} ${SOURCES})
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)
