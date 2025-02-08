#pragma once
#include "rtrp/fwddec.hpp"

#include <type_traits>
#include <cstdlib>

namespace rtrp
{
	namespace utils
	{
		template <typename T>
		inline result::Result<T> numFromString(const char* str, int base = 10) requires(std::is_arithmetic_v<T> || std::is_enum_v<T>)
		{
			errno = 0;
			static char* p_end = nullptr;

			T res;

			if constexpr (std::is_same_v<T, int> || std::is_enum_v<T>)
				res = static_cast<T>(std::strtol(str, &p_end, base));
			else if constexpr (std::is_same_v<T, float>)
				res = std::strtof(str, &p_end);
			else if constexpr (std::is_same_v<T, double>)
				res = std::strtof(str, &p_end);
			else
				static_assert(!sizeof(T*), "Invalid type passed to numFromString!");

			if (*p_end != 0)
			{
				p_end = nullptr;
				return result::Err("Couldn't convert string to number");
			}

			return res;
		}

		template <typename T>
		inline result::Result<T> get(const kv_response_t& map, std::size_t idx)
		{
			if (map.find(idx) != map.end())
			{
				const auto& itm = map.at(idx);

				if (itm == "")
					return T{};

				if constexpr (std::is_same_v<T, std::string>)
					return itm;
				else if constexpr (std::is_same_v<T, bool>)
					return itm == "1";
				else
					return numFromString<T>(itm.c_str());
			}

			return T{};
		}

		template <typename T>
		inline result::Result<T> get(const v_response_t& vec, std::size_t idx)
		{
			if (vec.size() < idx)
			{
				const auto& itm = vec.at(idx);

				if (itm == "")
					return T{};

				if constexpr (std::is_same_v<T, std::string>)
					return itm;
				else if constexpr (std::is_same_v<T, bool>)
					return itm == "1";
				else
					return numFromString<T>(itm.c_str());
			}

			return T{};
		}
	}
}
