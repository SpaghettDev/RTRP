#pragma once
#include <array>

#include "../fwddec.hpp"

// credit: https://wyliemaster.github.io/gddocs/#/resources/server/level?id=level-structure
namespace rtrp
{
	struct objects::LevelObject
	{
		int levelID;
		std::string name;
		std::string description;
		std::string levelString;
		int version;
		int creatorID;
		int difficultyDenominator;
		int difficultyNumerator;
		int downloads;
		int setCompletes;
		int officialSong;
		int gameVersion;
		int likes;
		int length;
		int dislikes;
		bool isDemon;
		int stars;
		int featureIdx;
		bool isAuto;
		std::string recordString;
		std::string password;
		std::string uploadDate;
		std::string updateDate;
		int copiedID;
		bool twoPlayer;
		int customSongID;
		std::string extraString;
		int coins;
		bool verifiedCoins;
		int starsRequested;
		bool lowDetailMode;
		int dailyNumber;
		int epic;
		int demonDifficulty;
		bool isGauntlet;
		int objects;
		int editorTime;
		int copiedEditorTime;
		std::string settingsString;

		struct ExtraFields
		{
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

			static const ExtraFields from_map(const impl::kv_response_t& map)
			{
				return {
					RTRP_VAR_FROM_MAP(19, LevelObject::featureIdx) != 0,
					RTRP_VAR_FROM_MAP(42, LevelObject::epic) != 0,
					RTRP_VAR_FROM_MAP(15, LevelObject::length) == 5,
					orbsArray[RTRP_VAR_FROM_MAP(18, LevelObject::stars)],
					lengthArray[RTRP_VAR_FROM_MAP(15, LevelObject::length)]
				};
			}
		} extras;

	private:
		static constexpr std::string_view DELIMITER = ":";
		static constexpr std::string_view DELIMITER_SEARCH = "|";
		static constexpr unsigned int SPLIT_RESPONSE_SIZE = 27; // getGJLevels21.php
		static constexpr unsigned int SPLIT_RESPONSE_SIZE2 = 33; // downloadGJLevel22.php
		friend class RtResponseParser;

		static const LevelObject from_map(const impl::kv_response_t& map)
		{
			return {
				RTRP_VAR_FROM_MAP(1, levelID),
				RTRP_VAR_FROM_MAP(2, name),
				RTRP_VAR_FROM_MAP(3, description),
				RTRP_VAR_FROM_MAP(4, levelString),
				RTRP_VAR_FROM_MAP(5, version),
				RTRP_VAR_FROM_MAP(6, creatorID),
				RTRP_VAR_FROM_MAP(8, difficultyDenominator),
				RTRP_VAR_FROM_MAP(9, difficultyNumerator),
				RTRP_VAR_FROM_MAP(10, downloads),
				RTRP_VAR_FROM_MAP(11, setCompletes),
				RTRP_VAR_FROM_MAP(12, officialSong),
				RTRP_VAR_FROM_MAP(13, gameVersion),
				RTRP_VAR_FROM_MAP(14, likes),
				RTRP_VAR_FROM_MAP(15, length),
				RTRP_VAR_FROM_MAP(16, dislikes),
				RTRP_VAR_FROM_MAP(17, isDemon),
				RTRP_VAR_FROM_MAP(18, stars),
				RTRP_VAR_FROM_MAP(19, featureIdx),
				RTRP_VAR_FROM_MAP(25, isAuto),
				RTRP_VAR_FROM_MAP(26, recordString),
				RTRP_VAR_FROM_MAP(27, password),
				RTRP_VAR_FROM_MAP(28, uploadDate),
				RTRP_VAR_FROM_MAP(29, updateDate),
				RTRP_VAR_FROM_MAP(30, copiedID),
				RTRP_VAR_FROM_MAP(31, twoPlayer),
				RTRP_VAR_FROM_MAP(35, customSongID),
				RTRP_VAR_FROM_MAP(36, extraString),
				RTRP_VAR_FROM_MAP(37, coins),
				RTRP_VAR_FROM_MAP(38, verifiedCoins),
				RTRP_VAR_FROM_MAP(39, starsRequested),
				RTRP_VAR_FROM_MAP(40, lowDetailMode),
				RTRP_VAR_FROM_MAP(41, dailyNumber),
				RTRP_VAR_FROM_MAP(42, epic),
				RTRP_VAR_FROM_MAP(43, demonDifficulty),
				RTRP_VAR_FROM_MAP(44, isGauntlet),
				RTRP_VAR_FROM_MAP(45, objects),
				RTRP_VAR_FROM_MAP(46, editorTime),
				RTRP_VAR_FROM_MAP(47, copiedEditorTime),
				RTRP_VAR_FROM_MAP(48, settingsString),
				ExtraFields::from_map(map)
			};
		}
	};
}
