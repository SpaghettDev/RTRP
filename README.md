# RTRP

RobTop Response Parser. C++ library that parses Rob's endpoints' responses.

Currently only parses some endpoints. The functions that do so are:

- RtResponseParser::parseListResponse
  - getGJLevelLists.php
- RtResponseParser::parseLevelResponse
  - getGJLevels21.php
  - downloadGJLevel22.php (currently broken)
- RtResponseParser::parseUserInfoResponse
  - getGJUserInfo20.php
  - getGJScores20.php
  - getGJUsers20.php
  - getGJUserList20.php

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

## Example

```cpp
#include <rtrp/rtrp.hpp>

// get the server's response as a std::string using some kind of web library. (e.g.: curl)
std::string serverLevelResponse = getFromUrl("https://www.boomlings.com/database/getGJLevelLists.php");

/**
 * Now, we parse the result using the correct RtResponseParser method.
 * Notice the `.unwrap()` in the end!
 * If you `.unwrap()` a parsed result that is wrong, an std::runtime_error will be raised.
 */
const auto& parsedResponse = RtResponseParser::parseListResponse(serverLevelResponse).unwrap();

// Now we can access conveniently named members directly instead of relying on some random index robert chose!
int listID = parsedResponse.lists[0].listID;
std::string creatorName = parsedResponse.lists[0].creatorName;
// ...

// Looping through the fetched lists
for (const auto& list : parsedResponse.lists)
    std::cout << list.name << " has ID: " << list.listID << '\n';
```
