#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <map>

#define RTRP_VAR_FROM_MAP(idx, member) utils::getOrDefault<decltype(member)>(map, idx)
#define RTRP_VEC_VAR_FROM_MAP(idx, member, delimiter) utils::splitString(utils::getOrDefault<std::string>(map, idx), delimiter)

namespace rtrp
{
	namespace impl
	{
		using kv_response_t = std::map<std::size_t, std::string>;
		using v_response_t = std::vector<std::string>;

		template<typename T>
		class Result;
	}

	namespace utils
	{
		inline impl::v_response_t splitString(const std::string&, std::string_view);
		inline impl::kv_response_t splitKVP(const std::string&, const std::string_view);

		template<typename T>
		inline T getOrDefault(const impl::kv_response_t&, std::size_t);
	}

	namespace objects
	{
		struct LevelObject;
		struct ListObject;
		struct CreatorObject;
		struct SongObject;
		struct PageObject;
		struct UserObject;
	}

	namespace responses
	{
		struct LevelResponse;
		struct ListResponse;
		struct UserResponse;
	}

	class RtResponseParser;
}
