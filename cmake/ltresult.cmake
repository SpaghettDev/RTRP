include(FetchContent)

FetchContent_Declare(
    LTResult
    GIT_REPOSITORY https://github.com/SpaghettDev/result.git
    GIT_TAG        fa5c01de77837fa068d1d85214cd0aa6e929eb0c
    GIT_PROGRESS TRUE
)
message("Fetching LTResult")
FetchContent_MakeAvailable(LTResult)

target_include_directories(${PROJECT_NAME} PRIVATE ${RESULT_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} PUBLIC LTResult)
