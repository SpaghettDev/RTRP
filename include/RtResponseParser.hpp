#pragma once
#include <string>
#include <vector>
#include "utils.hpp"

namespace rtrp
{
	class RtResponseParser;

	namespace types
	{
		struct LevelObject
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

		struct ListObject
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

		struct CreatorObject
		{
			int userID;
			std::string name;
			int accountID;

		private:
			inline static constexpr std::string_view DELIMITER = ":";
			inline static constexpr std::string_view DELIMITER_SEARCH = "|";
			inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 3;
			friend class RtResponseParser;

			static const CreatorObject from_vector(const std::vector<std::string>& vec)
			{
				return { std::stoi(vec[0]), vec[1], std::stoi(vec[2]) };
			}
		};

		struct SongObject
		{
			std::string unk1; // format: levelCreatorAccountID#1
			int ID;
			int unk3; // always 2?
			std::string name;
			int unk5; // always 3?
			int unk6;
			int unk7; // always 4?
			std::string creatorName;
			int unk9; // always 5?
			float size; // e.g.: 2.47 (MB)
			int unk11; // always 6?
			int unk12; // always empty in my testing
			int unk13; // always 10?
			std::string ngLink; // URI encoded
			int unk15; // always 7?
			std::string unk16; // not empty only when there are sfx
			int unk17; // always 8?
			std::string unk18; // 1#9999 or 1

		private:
			inline static constexpr std::string_view DELIMITER = "~|~";
			inline static constexpr std::string_view DELIMITER_SEARCH = ":";
			inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 18;
			friend class RtResponseParser;

			static const SongObject from_vector(const std::vector<std::string>& vec)
			{
				return {
					vec[0],
					std::stoi(vec[1]),
					std::stoi(vec[2]),
					vec[3],
					std::stoi(vec[4]),
					std::stoi(vec[5]),
					std::stoi(vec[6]),
					vec[7],
					std::stoi(vec[8]),
					std::stof(vec[9]),
					std::stoi(vec[10]),
					std::stoi(vec[11]),
					std::stoi(vec[12]),
					vec[13],
					std::stoi(vec[14]),
					vec[15],
					std::stoi(vec[16]),
					vec[17]
				};
			}
		};

		struct PageObject
		{
			int pages;
			int currentPage;
			int countPerPage;

		private:
			inline static constexpr std::string_view DELIMITER = ":";
			inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 3;
			friend class RtResponseParser;

			static const PageObject from_vector(const std::vector<std::string>& vec)
			{
				return { std::stoi(vec[0]), std::stoi(vec[1]), std::stoi(vec[2]) };
			}
		};


		struct LevelResponse
		{
			std::vector<LevelObject> levels;
			std::vector<CreatorObject> creators;
			std::vector<SongObject> songs;
			PageObject page;
			std::string hash;

			LevelResponse(
				const std::vector<LevelObject>& levels,
				const std::vector<CreatorObject>& creators,
				const std::vector<SongObject>& songs,
				const PageObject& page,
				const std::string& hash
				)
				: levels(levels), creators(creators), songs(songs), page(page), hash(hash)
			{}

		private:
			inline static const std::string_view DELIMITER = "#";
			static constexpr unsigned int SPLIT_RESPONSE_SIZE = 5;
			inline friend class RtResponseParser;
		};

		struct ListResponse
		{
			std::vector<ListObject> lists;
			std::vector<CreatorObject> creators;
			PageObject page;
			std::string hash;

			ListResponse(
				const std::vector<ListObject>& lists,
				const std::vector<CreatorObject>& creators,
				const PageObject& page,
				const std::string& hash
				)
				: lists(lists), creators(creators), page(page), hash(hash)
			{}

		private:
			inline static constexpr std::string_view DELIMITER = "#";
			inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 4;
			friend class RtResponseParser;
		};
	}

	class RtResponseParser
	{
	public:
		static types::LevelResponse parseLevelResponse(const std::string&);
		static types::ListResponse parseListResponse(const std::string&);
	};
}
