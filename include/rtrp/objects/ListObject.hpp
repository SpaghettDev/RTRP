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
		int featuredIdx;
		int uploadTimestamp;
		int editTimestamp;
		int creatorAccountID;
		std::string creatorName;
		std::vector<std::string> levelIDs;
		int diamonds;
		int firstDiamondsGoal;

	private:
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 14;
		friend class RtResponseParser;

		static const ListObject from_map(const impl::kv_response_t& map)
		{
			return {
				RTRP_VAR_FROM_MAP(1, listID),
				RTRP_VAR_FROM_MAP(2, name),
				RTRP_VAR_FROM_MAP(3, description),
				RTRP_VAR_FROM_MAP(5, version),
				RTRP_VAR_FROM_MAP(7, difficulty),
				RTRP_VAR_FROM_MAP(10, downloads),
				RTRP_VAR_FROM_MAP(14, likes),
				RTRP_VAR_FROM_MAP(19, featuredIdx),
				RTRP_VAR_FROM_MAP(28, uploadTimestamp),
				RTRP_VAR_FROM_MAP(29, editTimestamp),
				RTRP_VAR_FROM_MAP(49, creatorAccountID),
				RTRP_VAR_FROM_MAP(50, creatorName),
				RTRP_VEC_VAR_FROM_MAP(51, levelIDs, ","),
				RTRP_VAR_FROM_MAP(55, diamonds),
				RTRP_VAR_FROM_MAP(56, firstDiamondsGoal),
			};
		}
	};
}
