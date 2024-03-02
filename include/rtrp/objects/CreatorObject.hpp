#pragma once
#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::CreatorObject
	{
		int userID;
		std::string name;
		int accountID;

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 3;

		static const CreatorObject from_vector(const impl::v_response_t& vec)
		{
			return { std::stoi(vec[0]), vec[1], std::stoi(vec[2]) };
		}
	};
}
