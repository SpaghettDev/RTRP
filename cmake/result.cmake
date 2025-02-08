include(FetchContent)

FetchContent_Declare(
    Result
    GIT_REPOSITORY https://github.com/SpaghettDev/result.git
    GIT_TAG        8d9bb7ebbd76d6f985150d6806ba7449492f4fd1
    GIT_PROGRESS TRUE
)
message("Fetching Result")
FetchContent_MakeAvailable(Result)

target_include_directories(${PROJECT_NAME} PRIVATE ${RESULT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC Result)
