#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <unordered_map>

#include <result/result.hpp>

#if !defined(RTRP_CONCAT)
    #define RTRP_CONCAT2(x, y) x##y
    #define RTRP_CONCAT(x, y) RTRP_CONCAT2(x, y)
#endif

// do not use unless you know get<T> will return a valid value!
#define RTRP_VAR_FROM_MAP(idx, member) ::rtrp::utils::get<decltype(member)>(map, idx)

#define RTRP_VAR_FROM_MAP_SAFE_INTO(var, idx, member)                                 \
	auto RTRP_CONCAT(res, __LINE__) = ::rtrp::utils::get<decltype(member)>(map, idx); \
	if (RTRP_CONCAT(res, __LINE__).isErr())                                           \
		return result::Err(std::move(RTRP_CONCAT(res, __LINE__)).unwrapErr());  \
	var = std::move(RTRP_CONCAT(res, __LINE__)).unwrap()

#define RTRP_VAR_FROM_VEC_SAFE_INTO(var, idx, member)                                 \
	auto RTRP_CONCAT(res, __LINE__) = ::rtrp::utils::get<decltype(member)>(vec, idx); \
	if (RTRP_CONCAT(res, __LINE__).isErr())                                           \
		return result::Err(std::move(RTRP_CONCAT(res, __LINE__)).unwrapErr());  \
	var = std::move(RTRP_CONCAT(res, __LINE__)).unwrap()                              \

// get<std::string> can never fail so its safe to always unwrap
#define RTRP_VEC_VAR_FROM_MAP_SAFE_INTO(var, idx, member, delimiter) \
	var = ::rtrp::utils::splitString(utils::get<std::string>(map, idx).unwrap(), delimiter)

namespace rtrp
{
	namespace impl
	{
		using kv_response_t = std::unordered_map<std::size_t, std::string>;
		using v_response_t = std::vector<std::string>;
	}
	
	namespace utils
	{
		using namespace impl;

		//? Also make this Result?
		v_response_t splitString(std::string_view, const std::string_view);
		result::Result<kv_response_t> splitKVP(std::string_view, const std::string_view);

		// template <typename T>
		// Result<T> numFromString(const char*, int = 10);

		// template<typename T>
		// Result<T> get(const kv_response_t&, std::size_t);

		// template<typename T>
		// Result<T> get(const v_response_t&, std::size_t);
	}

	namespace objects
	{
		using namespace impl;

		struct LevelObject;
		struct ListObject;
		struct CreatorObject;
		struct SongObject;
		struct PageObject;
		struct UserObject;
	}

	namespace responses
	{
		using namespace impl;

		struct LevelResponse;
		struct ListResponse;
		struct UserResponse;
	}

	class RtResponseParser;
}

#include "rtrp_utils.hpp" // IWYU pragma: export
