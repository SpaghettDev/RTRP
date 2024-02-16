# RTRP

RobTop Response Parser. C++ library that parses Rob's endpoints' responses.

Currently only parses some endpoints. The functions that do so are:

- RtResponseParser::parseListResponse
  - getGJLevelLists.php
- RtResponseParser::parseLevelResponse
  - getGJLevels21.php
  - downloadGJLevel22.php
- RtResponseParser::parseUserInfoResponse
  - getGJUserInfo20.php
  - getGJScores20.php
  - getGJUsers20.php

More will be added later.

## Project Structure

- `include/objects` contains common, as well as request specific objects.
- `include/responses` the types returned by the RtResponseParser parser methods.
- `src/` the source of the RtResponseParser class. And utils.

## How To Include

CMakeLists.txt:

```cmake
# ...

include(FetchContent)
find_package(Git)

message("Getting modules\n")
FetchContent_Declare(
    RTRP
    GIT_REPOSITORY https://github.com/SpaghettDev/RTRP.git
    GIT_TAG        latest_commit_tag
    GIT_PROGRESS TRUE
)
message("Fetching RTRP")
FetchContent_MakeAvailable(RTRP)

target_include_directories(${PROJECT_NAME} PRIVATE ${RTRP_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} RTRP)
```
