include(FetchContent)

FetchContent_Declare(
    LTResult
    GIT_REPOSITORY https://github.com/SpaghettDev/result.git
    GIT_TAG        5405507e568b143ed96367fa41b7bc72c78b5fef
    GIT_PROGRESS TRUE
)
message("Fetching LTResult")
FetchContent_MakeAvailable(LTResult)

target_include_directories(${PROJECT_NAME} PRIVATE ${RESULT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC LTResult)
