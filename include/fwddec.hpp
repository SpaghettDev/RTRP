#pragma once
#include <string>
#include <vector>

namespace rtrp
{
	class RtResponseParser;

	namespace utils
	{
		inline std::vector<std::string> split(const std::string&, std::string_view);

		template<typename T>
		struct Result
		{
			T result;
			bool isError;

			Result(const T& result, bool isError = false)
				: result(result), isError(isError)
			{}

			Result(bool isError)
				: isError(isError)
			{}
		};
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

	class RtResponseParser;
}
