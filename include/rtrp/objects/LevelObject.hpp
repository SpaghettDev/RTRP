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
		int creatorUserID;
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
			friend struct LevelObject;

			static ExtraFields from_map(const kv_response_t& map)
			{
				// at this point its safe to unwrap since everything was checked before reaching here
				return {
					RTRP_VAR_FROM_MAP(19, LevelObject::featureIdx).unwrap() != 0,
					RTRP_VAR_FROM_MAP(42, LevelObject::epic).unwrap() != 0,
					RTRP_VAR_FROM_MAP(15, LevelObject::length).unwrap() == 5,
					orbsArray[RTRP_VAR_FROM_MAP(18, LevelObject::stars).unwrap()],
					lengthArray[RTRP_VAR_FROM_MAP(15, LevelObject::length).unwrap()]
				};
			}
		} extras;

#ifdef __APPLE__
		LevelOLevelObject() = default;
		LevelObject(
			int levelID, std::string&& name, std::string&& description, std::string&& levelString, int version,
			int creatorUserID, int difficultyDenominator, int difficultyNumerator, int downloads, int setCompletes,
			int officialSong, int gameVersion, int likes, int length, int dislikes, bool isDemon, int stars,
			int featureIdx, bool isAuto, std::string&& recordString, std::string&& password, std::string&& uploadDate,
			std::string&& updateDate, int copiedID, bool twoPlayer, int customSongID, std::string&& extraString,
			int coins, bool verifiedCoins, int starsRequested, bool lowDetailMode, int dailyNumber,
			int epic, int demonDifficulty, bool isGauntlet, int objects,
			int editorTime, int copiedEditorTime, std::string&& settingsString,
			ExtraFields&& extras
		)
			: levelID(levelID), name(std::move(name)), description(std::move(description)), levelString(std::move(levelString)),
				version(version), creatorUserID(creatorUserID), difficultyDenominator(difficultyDenominator),
				difficultyNumerator(difficultyNumerator), downloads(downloads), setCompletes(setCompletes),
				officialSong(officialSong), gameVersion(gameVersion), likes(likes), length(length), dislikes(dislikes),
				isDemon(isDemon), stars(stars), featureIdx(featureIdx), isAuto(isAuto), recordString(std::move(recordString)),
				password(std::move(password)), uploadDate(std::move(uploadDate)), updateDate(std::move(updateDate)),
				copiedID(copiedID), twoPlayer(twoPlayer), customSongID(customSongID), extraString(std::move(extraString)),
				coins(coins), verifiedCoins(verifiedCoins), starsRequested(starsRequested),
				lowDetailMode(lowDetailMode), dailyNumber(dailyNumber), epic(epic),
				demonDifficulty(demonDifficulty), isGauntlet(isGauntlet), objects(objects),
				editorTime(editorTime), copiedEditorTime(copiedEditorTime),
				settingsString(std::move(settingsString)), extras(std::move(extras))
		{}
#endif

	private:
		friend class ::rtrp::RtResponseParser;
		static constexpr std::string_view DELIMITER = ":";
		static constexpr std::string_view DELIMITER_SEARCH = "|";
		static constexpr unsigned int SPLIT_RESPONSE_SIZE = 27; // getGJLevels21.php
		static constexpr unsigned int SPLIT_RESPONSE_SIZE2 = 33; // downloadGJLevel22.php

		static result::Result<LevelObject> from_map(kv_response_t&& map)
		{
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto levelID, 1, levelID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto name, 2, name);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto description, 3, description);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto levelString, 4, levelString);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto version, 5, version);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto creatorUserID, 6, creatorUserID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto difficultyDenominator, 8, difficultyDenominator);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto difficultyNumerator, 9, difficultyNumerator);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto downloads, 10, downloads);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto setCompletes, 11, setCompletes);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto officialSong, 12, officialSong);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto gameVersion, 13, gameVersion);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto likes, 14, likes);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto length, 15, length);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto dislikes, 16, dislikes);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto isDemon, 17, isDemon);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto stars, 18, stars);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto featureIdx, 19, featureIdx);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto isAuto, 25, isAuto);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto recordString, 26, recordString);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto password, 27, password);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto uploadDate, 28, uploadDate);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto updateDate, 29, updateDate);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto copiedID, 30, copiedID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto twoPlayer, 31, twoPlayer);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto customSongID, 35, customSongID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto extraString, 36, extraString);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto coins, 37, coins);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto verifiedCoins, 38, verifiedCoins);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto starsRequested, 39, starsRequested);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto lowDetailMode, 40, lowDetailMode);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto dailyNumber, 41, dailyNumber);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto epic, 42, epic);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto demonDifficulty, 43, demonDifficulty);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto isGauntlet, 44, isGauntlet);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto objects, 45, objects);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto editorTime, 46, editorTime);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto copiedEditorTime, 47, copiedEditorTime);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto settingsString, 48, settingsString);

			return {
				levelID,
				std::move(name),
				std::move(description),
				std::move(levelString),
				version,
				creatorUserID,
				difficultyDenominator,
				difficultyNumerator,
				downloads,
				setCompletes,
				officialSong,
				gameVersion,
				likes,
				length,
				dislikes,
				isDemon,
				stars,
				featureIdx,
				isAuto,
				std::move(recordString),
				std::move(password),
				std::move(uploadDate),
				std::move(updateDate),
				copiedID,
				twoPlayer,
				customSongID,
				std::move(extraString),
				coins,
				verifiedCoins,
				starsRequested,
				lowDetailMode,
				dailyNumber,
				epic,
				demonDifficulty,
				isGauntlet,
				objects,
				editorTime,
				copiedEditorTime,
				std::move(settingsString),
				ExtraFields::from_map(map)
			};
		}
	};
}
