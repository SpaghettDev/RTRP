#pragma once
#include <string>
#include <vector>

namespace rtrp
{
	namespace utils
	{
		inline std::vector<std::string> split(const std::string&, std::string_view);
	}

	namespace objects
	{
		struct LevelObject;
		struct ListObject;
		struct CreatorObject;
		struct SongObject;
		struct PageObject;
	}

	namespace responses
	{
		struct LevelResponse;
		struct ListResponse;
	}

	template<typename T>
	struct Result;

	class RtResponseParser;
}
