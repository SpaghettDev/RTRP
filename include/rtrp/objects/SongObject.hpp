#pragma once
#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::SongObject
	{
		int ID;
		std::string name;
		int artistID;
		std::string artistName;
		float size; // e.g.: 2.47 (MB)
		std::string videoID;
		std::string youtubeChannelID; // the youtube channel ID
		bool isVerified; // 1#9999 or 1
		int songPriority;
		std::string link; // URI encoded

#ifdef __APPLE__
		SongObject(int ID, std::string&& name, int artistID, std::string&& artistName, float size,
			std::string&& videoID, std::string&& youtubeChannelID, bool isVerified, int songPriority,
			std::string&& link)
			: ID(ID), name(std::move(name)), artistID(artistID), artistName(std::move(artistName)),
			  size(size), videoID(std::move(videoID)), youtubeChannelID(std::move(youtubeChannelID)),
			  isVerified(isVerified), songPriority(songPriority), link(std::move(link))
		{}
#endif

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = "~|~";
		inline static constexpr std::string_view DELIMITER_SEARCH = "~:~";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 9;
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE2 = 10;

		static result::Result<SongObject> from_map(kv_response_t&& map)
		{
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto ID, 1, ID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto name, 2, name);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto artistID, 3, artistID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto artistName, 4, artistName);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto size, 5, size);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto videoID, 6, videoID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto youtubeChannelID, 7, youtubeChannelID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto isVerified, 8, isVerified);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto songPriority, 9, songPriority);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto link, 10, link);

			return {
				ID,
				std::move(name),
				artistID,
				std::move(artistName),
				size,
				std::move(videoID),
				std::move(youtubeChannelID),
				isVerified,
				songPriority,
				std::move(link)
			};
		}
	};
}
