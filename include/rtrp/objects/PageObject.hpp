#pragma once
#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::PageObject
	{
		int pages;
		int currentPage;
		int countPerPage;

#ifdef __APPLE__
		PageObject() = default;
		PageObject(int pages, int currentPage, int countPerPage)
			: pages(pages), currentPage(currentPage), countPerPage(countPerPage)
		{}
#endif

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 3;

		static result::Result<PageObject> from_vector(v_response_t&& vec)
		{
			RTRP_VAR_FROM_VEC_SAFE_INTO(auto pages, 0, pages);
			RTRP_VAR_FROM_VEC_SAFE_INTO(auto currentPage, 1, currentPage);
			RTRP_VAR_FROM_VEC_SAFE_INTO(auto countPerPage, 2, countPerPage);

			return { pages, currentPage, countPerPage };
		}
	};
}
