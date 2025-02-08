Include(FetchContent)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.2
)

FetchContent_MakeAvailable(Catch2)
list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)

# target_compile_options(Catch2 PRIVATE
#     $<$<CXX_COMPILER_ID:MSVC>:/W4>
#     $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wno-gnu-statement-expression-from-macro-expansion -fsanitize=address,undefined>
# )

add_executable(tests test.cpp)
target_link_libraries(tests PRIVATE RTRP Catch2::Catch2 Catch2::Catch2WithMain)

include(CTest)
include(Catch)
catch_discover_tests(tests)
