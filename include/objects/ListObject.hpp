#pragma once
#include <string>
#include <string_view>
#include <vector>

#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::ListObject
	{
		int ID;
		int listID;
		int unk3;
		std::string name;
		int unk5;
		std::string description; // base64 encoded
		int unk7;
		int version;
		int unk9;
		int creatorAccountID;
		int unk11;
		std::string creatorName;
		int unk13;
		int downloads;
		int unk15;
		int unk16;
		int unk17;
		int likes;
		int unk19;
		int featuredIdx;
		int unk21;
		std::vector<std::string> levelIDs;
		int unk23;
		int diamonds;
		int unk25;
		int unk26;
		int unk27;
		int unk28;
		int unk29;
		int unk30;

	private:
		inline static constexpr std::string_view DELIMITER = "#";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 30;
		friend class RtResponseParser;

		static const ListObject from_vector(const std::vector<std::string>& vec)
		{
			return {
				std::stoi(vec[0]),
				std::stoi(vec[1]),
				std::stoi(vec[2]),
				vec[3],
				std::stoi(vec[4]),
				vec[5],
				std::stoi(vec[6]),
				std::stoi(vec[7]),
				std::stoi(vec[8]),
				std::stoi(vec[9]),
				std::stoi(vec[10]),
				vec[11],
				std::stoi(vec[12]),
				std::stoi(vec[13]),
				std::stoi(vec[14]),
				std::stoi(vec[15]),
				std::stoi(vec[16]),
				std::stoi(vec[17]),
				std::stoi(vec[18]),
				vec[19] == "" ? 0 : std::stoi(vec[19]),
				std::stoi(vec[20]),
				utils::split(vec[21], ","),
				std::stoi(vec[22]),
				std::stoi(vec[23]),
				std::stoi(vec[24]),
				std::stoi(vec[25]),
				std::stoi(vec[26]),
				std::stoi(vec[27]),
				std::stoi(vec[28]),
				std::stoi(vec[29]),
			};
		}
	};
}
