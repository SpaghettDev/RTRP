#include <string>
#include <vector>
#include <map>

namespace rtrp
{
	namespace utils
	{
		inline impl::v_response_t splitString(const std::string& str, const std::string_view delimiter)
		{
			std::size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			std::string token;
			impl::v_response_t res;

			while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
			{
				token = str.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;
				res.push_back(token);
			}

			res.push_back(str.substr(pos_start));
			return res;
		}

		inline impl::kv_response_t splitKVP(const std::string& str, const std::string_view delimiter)
		{
			impl::kv_response_t res;
			std::size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			std::string token;
			std::string key = "";

			while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
			{
				token = str.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;

				if (key.empty())
					key = token;
				else
				{
					res[std::stoi(key)] = token;
					key.clear();
				}
			}

			res[std::stoi(key)] = str.substr(pos_start);
			return res;
		}

		template<typename T>
		inline T getOrDefault(const impl::kv_response_t& map, std::size_t idx)
		{
			if (map.find(idx) != map.end())
			{
				const auto& itm = map.at(idx);

				if constexpr (std::is_same_v<T, bool>)
					return itm == "1";
				else if constexpr (std::is_same_v<T, int>)
					return std::stoi(itm);
				else if constexpr (std::is_same_v<T, float>)
					return std::stof(itm);
				else if constexpr (std::is_same_v<T, std::string>)
					return itm;
				else if constexpr (std::is_enum_v<T>)
					return static_cast<T>(std::stoi(itm));
			}

			return T{};
		}
	}
}
