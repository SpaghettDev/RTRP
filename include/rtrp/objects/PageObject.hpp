#pragma once
#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::PageObject
	{
		int pages;
		int currentPage;
		int countPerPage;

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 3;

		static const PageObject from_vector(const impl::v_response_t& vec)
		{
			return { std::stoi(vec[0]), std::stoi(vec[1]), std::stoi(vec[2]) };
		}
	};
}
