#include "rtrp/fwddec.hpp"

#include <algorithm>
#include <ranges>

namespace rtrp
{
	namespace utils
	{
		v_response_t splitString(const std::string_view str, const std::string_view delimiter)
		{
			std::size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			std::string token;
			v_response_t res;
#ifndef RTRP_DONT_RESERVE_CONTAINER_SIZES
			res.reserve(
				static_cast<std::size_t>(std::ranges::count_if(
					std::ranges::views::iota(0, static_cast<int>(str.length() - delim_len + 1)),
					[&](auto i) { return str.substr(i, delim_len) == delimiter; }
				)) + 1
			);
#endif

			while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
			{
				token = str.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;
				res.emplace_back(std::move(token));
			}

			res.emplace_back(std::string(str.substr(pos_start)));
			return res;
		}

		result::Result<kv_response_t> splitKVP(const std::string_view str, const std::string_view delimiter)
		{
			std::size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			std::string token;
			std::string key = "";
			kv_response_t res;
#ifndef RTRP_DONT_RESERVE_CONTAINER_SIZES
			res.reserve(
				static_cast<std::size_t>(std::ranges::count_if(
					std::ranges::views::iota(0, static_cast<int>(str.length() - delim_len + 1)),
					[&](auto i) { return str.substr(i, delim_len) == delimiter; }
				))
			);
#endif

			while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
			{
				token = str.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;

				if (key.empty())
					key = token;
				else
				{
					auto&& keyNum = numFromString<int>(key.c_str());
					if (keyNum.isErr())
						return result::Err("Couldn't convert key string to int");

					res[keyNum.unwrap()] = token;
					key.clear();
				}
			}

			// false if the count of the delimiter in str is pair
			if (!key.empty())
			{
				auto&& keyNum = numFromString<int>(key.c_str());
				if (keyNum.isErr())
					return result::Err("Couldn't convert key string to int");

				res[keyNum.unwrap()] = str.substr(pos_start);
			}
			return res;
		}
	}
}
