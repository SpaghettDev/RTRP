// #include "../equality.hpp"

#include <string_view>
#include <iostream>

#define private public
#include <rtrp/rtrp.hpp>
#undef private

#include "../../src/rtrp_utils.cpp"
#include "../../src/rtrp.cpp"

static constexpr std::string_view SEARCH_RESPONSE = \
	"1:106749466:2:Drowsy:5:7:6:10143327:8:10:9:20:10:37165:12:0:13:22:14:3085:17::43:4:25::18:3:19:25067:42:0:45:17233:3:eW91IGxvb2sgdGlyZWQuIGhlcmUsIHRha2UgYSBicmVhay4u:15:3:30:0:31:0:37:1:38:1:39:3:46:1:47:2:35:1272705#10143327:TeeeJify:2723422#1~|~1272705~|~2~|~Windows96 - Hypnosis~|~3~|~10000168~|~4~|~whitegavriel~|~5~|~9.67~|~6~|~~|~10~|~https%3A%2F%2Faudio.ngfiles.com%2F1272000%2F1272705_Windows96---Hypnosis.mp3%3Ff1703190904~|~7~|~~|~8~|~1#9999:0:10#f3b3c99922de38105071e6def6db2eae92a1ef9f";

int main()
{
    const auto parsed = rtrp::RtResponseParser::parseLevelResponse(SEARCH_RESPONSE);

    std::cout << std::boolalpha << parsed.isOk() << '\n';
}
