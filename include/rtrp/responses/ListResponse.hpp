#pragma once
#include "../fwddec.hpp"

#include "../objects/ListObject.hpp"
#include "../objects/CreatorObject.hpp"
#include "../objects/PageObject.hpp"

namespace rtrp
{
	struct responses::ListResponse
	{
		std::vector<objects::ListObject> lists;
		std::vector<objects::CreatorObject> creators;
		objects::PageObject page;
		std::string hash;

		ListResponse(
			std::vector<objects::ListObject>&& lists,
			std::vector<objects::CreatorObject>&& creators,
			objects::PageObject&& page,
			std::string&& hash
		)
			: lists(std::move(lists)), creators(std::move(creators)),
				page(std::move(page)), hash(std::move(hash))
		{}

		ListResponse() = default;

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = "#";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 4;
	};
}
