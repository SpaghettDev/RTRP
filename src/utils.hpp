#include <string>
#include <vector>

namespace rtrp
{
	namespace utils
	{
		inline std::vector<std::string> split(const std::string& str, std::string_view delimiter)
		{
			std::size_t pos_start = 0, pos_end, delim_len = delimiter.length();
			std::string token;
			std::vector<std::string> res;

			while ((pos_end = str.find(delimiter, pos_start)) != std::string::npos)
			{
				token = str.substr(pos_start, pos_end - pos_start);
				pos_start = pos_end + delim_len;
				res.push_back(token);
			}

			res.push_back(str.substr(pos_start));
			return res;
		}
	}
}
