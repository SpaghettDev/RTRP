#pragma once
#include <string>
#include <string_view>
#include <vector>
#include <array>

#include "../fwddec.hpp"

// credit: https://wyliemaster.github.io/gddocs/#/resources/server/level?id=level-structure
namespace rtrp
{
	struct objects::LevelObject
	{
		int ID;
		std::string name;
		int version;
		int creatorID;
		int difficultyDenominator;
		int difficultyNominator;
		int downloads;
		int officialSong;
		int gameVersion;
		int likes;
		bool isDemon;
		int demonDifficulty;
		bool isAuto;
		int stars;
		int featureIdx;
		bool isEpic;
		int objects;
		std::string description;
		int length;
		int originalID;
		int isTwoPlayer;
		int coins;
		bool verifiedCoins;
		int starsRequested;
		int editorTime;
		int copiedEditorTime;
		int customSongID;

		struct HelperFields
		{
			// bool ldm;
			bool featured;
			bool epic;
			bool platformer;
			int orbs;
			std::string length;

		private:
			inline static const std::array<int, 11> orbsArray{
				0, 0, 50, 75, 125, 175, 225, 275, 350, 425, 500
			};
			inline static const std::array<std::string, 6> lengthArray{
				"Tiny", "Short", "Medium", "Long", "XL", "Platformer"
			};
			friend class LevelObject;

			static const HelperFields from_vector(const std::vector<std::string>& vec)
			{
				return {
					vec[19] != "0",
					vec[31] != "0",
					vec[37] == "5",
					orbsArray[std::stoi(vec[27])],
					lengthArray[std::stoi(vec[37])]
				};
			}
		} helperFields;

	private:
		static constexpr std::string_view DELIMITER = ":";
		static constexpr std::string_view DELIMITER_SEARCH = "|";
		static constexpr unsigned int SPLIT_RESPONSE_SIZE = 54;
		friend class RtResponseParser;

		static const LevelObject from_vector(const std::vector<std::string>& vec)
		{
			return {
				std::stoi(vec[1]),
				vec[3],
				std::stoi(vec[5]),
				std::stoi(vec[7]),
				std::stoi(vec[9]),
				std::stoi(vec[11]),
				std::stoi(vec[13]),
				std::stoi(vec[15]),
				std::stoi(vec[17]),
				std::stoi(vec[19]),
				vec[21] == "1",
				std::stoi(vec[23]),
				vec[25] == "1",
				std::stoi(vec[27]),
				std::stoi(vec[29]),
				vec[31] == "1",
				std::stoi(vec[33]),
				vec[35],
				std::stoi(vec[37]),
				std::stoi(vec[39]),
				vec[41] == "1",
				std::stoi(vec[43]),
				vec[45] == "1",
				std::stoi(vec[47]),
				std::stoi(vec[49]),
				std::stoi(vec[51]),
				std::stoi(vec[53]),
				HelperFields::from_vector(vec)
			};
		}
	};
}
