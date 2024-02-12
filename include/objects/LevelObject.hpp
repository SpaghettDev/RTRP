#pragma once
#include <string>
#include <string_view>
#include <vector>

#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::LevelObject
	{
		int ID;
		int levelID;
		int unk3;
		std::string name;
		int unk5;
		int version;
		int unk7;
		int creatorUserID;
		int unk9;
		int ratings;
		int unk11;
		int ratingsSum;
		int unk13;
		int downloads;
		int unk15;
		int audioTrack;
		int unk17;
		int gameVersion;
		int unk19;
		int likes;
		int unk21;
		bool isDemon; // empty when false, 1 when true
		int unk23;
		int difficulty;
		int unk25;
		bool isAutoLevel; // empty when false, 1 when true
		int unk27;
		int stars;
		int unk29;
		int featured;
		int unk31;
		bool isEpic;
		int unk33;
		int objectCount;
		int unk35;
		std::string description;
		int unk37;
		int length;
		int unk39;
		int originalLevelID;
		int unk41;
		bool isTwoPlayerMode;
		int unk43;
		int coins;
		int unk45;
		bool areCoinsVerified;
		int unk47;
		int starsRequested;
		int unk49;
		int unk50;
		int unk51;
		int unk52;
		int unk53;
		int customSongID; // 0 (not empty cuz rob!) when it isn't a custom song

	private:
		static constexpr std::string_view DELIMITER = ":";
		static constexpr std::string_view DELIMITER_SEARCH = "|";
		static constexpr unsigned int SPLIT_RESPONSE_SIZE = 54;
		friend class RtResponseParser;

		static const LevelObject from_vector(const std::vector<std::string>& vec)
		{
			return {
				std::stoi(vec[0]),
				std::stoi(vec[1]),
				std::stoi(vec[2]),
				vec[3],
				std::stoi(vec[4]),
				std::stoi(vec[5]),
				std::stoi(vec[6]),
				std::stoi(vec[7]),
				std::stoi(vec[8]),
				std::stoi(vec[9]),
				std::stoi(vec[10]),
				std::stoi(vec[11]),
				std::stoi(vec[12]),
				std::stoi(vec[13]),
				std::stoi(vec[14]),
				std::stoi(vec[15]),
				std::stoi(vec[16]),
				std::stoi(vec[17]),
				std::stoi(vec[18]),
				std::stoi(vec[19]),
				std::stoi(vec[20]),
				vec[21] == "1",
				std::stoi(vec[22]),
				std::stoi(vec[23]),
				std::stoi(vec[24]),
				vec[25] == "1",
				std::stoi(vec[26]),
				std::stoi(vec[27]),
				std::stoi(vec[28]),
				std::stoi(vec[29]),
				std::stoi(vec[30]),
				vec[31] == "1",
				std::stoi(vec[32]),
				std::stoi(vec[33]),
				std::stoi(vec[34]),
				vec[35],
				std::stoi(vec[36]),
				std::stoi(vec[37]),
				std::stoi(vec[38]),
				std::stoi(vec[39]),
				std::stoi(vec[40]),
				vec[41] == "1",
				std::stoi(vec[42]),
				std::stoi(vec[43]),
				std::stoi(vec[44]),
				vec[45] == "1",
				std::stoi(vec[46]),
				std::stoi(vec[47]),
				std::stoi(vec[48]),
				std::stoi(vec[49]),
				std::stoi(vec[50]),
				std::stoi(vec[51]),
				std::stoi(vec[52]),
				std::stoi(vec[53]),
			};
		}
	};
}
