#pragma once
#include <string>
#include <string_view>
#include <vector>

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
		std::string link; // URI encoded
		std::string youtubeChannelID; // the youtube channel ID
		bool isVerified; // 1#9999 or 1

	private:
		inline static constexpr std::string_view DELIMITER = "~|~";
		inline static constexpr std::string_view DELIMITER_SEARCH = "~:~";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 18;
		friend class RtResponseParser;

		static const SongObject from_vector(const std::vector<std::string>& vec)
		{
			return {
				std::stoi(vec[1]),
				vec[3],
				std::stoi(vec[5]),
				vec[7],
				std::stof(vec[9]),
				vec[11],
				vec[13],
				vec[15],
				vec[17] == "1"
			};
		}
	};
}
