set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_definitions(_HAS_ITERATOR_DEBUGGING=0)

add_executable(manual-testing manual.cpp)
target_link_libraries(manual-testing PRIVATE RTRP)

# target_compile_options(manual-testing PRIVATE
#     $<$<CXX_COMPILER_ID:MSVC>:/W4>
#     $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wno-gnu-statement-expression-from-macro-expansion -fsanitize=address,undefined>
# )
# target_compile_options(RTRP PRIVATE
#     $<$<CXX_COMPILER_ID:MSVC>:/W4>
#     $<$<NOT:$<CXX_COMPILER_ID:MSVC>>:-Wall -Wextra -Wpedantic -Wno-gnu-statement-expression-from-macro-expansion -fsanitize=address,undefined>
# )

# clang++ -fsanitize="address,undefined" -std=c++20 -g -O0 .\manual.cpp -I..\..\include\ -I..\..\include\rtrp\
