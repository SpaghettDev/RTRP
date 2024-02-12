#pragma once
#include <string>
#include <string_view>
#include <vector>

#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::SongObject
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
}
