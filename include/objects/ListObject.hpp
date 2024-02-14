#pragma once
#include <string>
#include <string_view>
#include <vector>

#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::ListObject
	{
		int listID;
		std::string name;
		std::string description; // base64 encoded
		int version;
		int creatorAccountID;
		std::string creatorName;
		int downloads;
		int difficulty;
		int likes;
		int featuredIdx;
		std::vector<std::string> levelIDs;
		int diamonds;
		int firstDiamondsGoal;
		int uploadTimestamp;
		int editTimestamp;

	private:
		inline static constexpr std::string_view DELIMITER = "#";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 30;
		friend class RtResponseParser;

		static const ListObject from_vector(const std::vector<std::string>& vec)
		{
			return {
				std::stoi(vec[1]),
				vec[3],
				vec[5],
				std::stoi(vec[7]),
				std::stoi(vec[9]),
				vec[11],
				std::stoi(vec[13]),
				std::stoi(vec[15]),
				std::stoi(vec[17]),
				vec[19] == "" ? 0 : std::stoi(vec[19]),
				utils::split(vec[21], ","),
				std::stoi(vec[23]),
				std::stoi(vec[25]),
				std::stoi(vec[27]),
				std::stoi(vec[29]),
			};
		}
	};
}
