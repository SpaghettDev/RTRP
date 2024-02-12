# RTRP

RobTop Response Parser. C++ library that parses Rob's endpoints' responses.

Currently only parses these endpoints' responses:

- getGJLevelLists.php
- getGJLevels21.php

More will be added later.

## Project Structure

- `include/objects` contains common objects between requests, e.g.: PageObject, SongObject. As well as other request specific objects, e.g.: LevelObject, ListObject.
- `include/responses` the types returned by the RtResponseParser parser methods.
- `src/` the source of the RtResponseParser class. And utils.

## How To Include

git.cmake:

```cmake
find_package(Git)

if(Git_FOUND)
    message("Git found: ${GIT_EXECUTABLE}")
endif()
```

rtrp.cmake:

```cmake
include(FetchContent)

FetchContent_Declare(
    RTRP
    GIT_REPOSITORY https://github.com/SpaghettDev/RTRP.git
    GIT_TAG        latest_commit_tag
    GIT_PROGRESS TRUE
)
message("Fetching RTRP")
FetchContent_MakeAvailable(RTRP)
```

CMakeLists.txt:

```cmake
# ...

include(cmake/git.cmake)

message("Getting modules\n")
include(cmake/rtrp.cmake)

target_include_directories(${PROJECT_NAME} PRIVATE ${RTRP_SOURCE_DIR}/include)

target_link_libraries(${PROJECT_NAME} RTRP)
```
