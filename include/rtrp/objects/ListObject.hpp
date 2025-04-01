#pragma once
#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::ListObject
	{
		int listID;
		std::string name;
		std::string description; // base64 encoded
		int version;
		int difficulty;
		int downloads;
		int likes;
		int featureIdx;
		int uploadTimestamp;
		int editTimestamp;
		int creatorAccountID;
		std::string creatorName;
		std::vector<std::string> levelIDs;
		int diamonds;
		int firstDiamondsGoal;

#ifdef __APPLE__
		ListObject(int listID, std::string&& name, std::string&& description, int version, int difficulty,
			int downloads, int likes, int featureIdx, int uploadTimestamp, int editTimestamp,
			int creatorAccountID, std::string&& creatorName, std::vector<std::string>&& levelIDs,
			int diamonds, int firstDiamondsGoal)
			: listID(listID), name(std::move(name)), description(std::move(description)), version(version),
			  difficulty(difficulty), downloads(downloads), likes(likes), featureIdx(featureIdx),
			  uploadTimestamp(uploadTimestamp), editTimestamp(editTimestamp),
			  creatorAccountID(creatorAccountID), creatorName(std::move(creatorName)),
			  levelIDs(std::move(levelIDs)), diamonds(diamonds), firstDiamondsGoal(firstDiamondsGoal)
		{}
#endif

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 15;

		static result::Result<ListObject> from_map(kv_response_t&& map)
		{
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto listID, 1, listID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto name, 2, name);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto description, 3, description);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto version, 5, version);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto difficulty, 7, difficulty);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto downloads, 10, downloads);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto likes, 14, likes);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto featureIdx, 19, featureIdx);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto uploadTimestamp, 28, uploadTimestamp);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto editTimestamp, 29, editTimestamp);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto creatorAccountID, 49, creatorAccountID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto creatorName, 50, creatorName);
			RTRP_VEC_VAR_FROM_MAP_SAFE_INTO(auto levelIDs, 51, levelIDs, ",");
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto diamonds, 55, diamonds);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto firstDiamondsGoal, 56, firstDiamondsGoal);

			return {
				listID,
				std::move(name),
				std::move(description),
				version,
				difficulty,
				downloads,
				likes,
				featureIdx,
				uploadTimestamp,
				editTimestamp,
				creatorAccountID,
				std::move(creatorName),
				std::move(levelIDs),
				diamonds,
				firstDiamondsGoal
			};
		}
	};
}
