cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(RTRP LANGUAGES CXX VERSION 1.0.1)

file(GLOB SOURCES
    src/*.cpp
    src/*.hpp
    include/types/*.hpp
    include/objects/*.hpp
    include/*.hpp
)

file(GLOB INCLUDE_HEADERS
    include/types/*.hpp
    include/objects/*.hpp
    include/*.hpp
)

add_library(${PROJECT_NAME} SHARED ${SOURCES})
add_library(${PROJECT_NAME}::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

set_target_properties(${PROJECT_NAME} PROPERTIES PUBLIC_HEADER "${INCLUDE_HEADERS}")
target_include_directories(
    ${PROJECT_NAME} PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:$<INSTALL_PREFIX>/${CMAKE_INSTALL_INCLUDEDIR}>"
)
