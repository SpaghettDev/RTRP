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
			const std::vector<objects::ListObject>& lists,
			const std::vector<objects::CreatorObject>& creators,
			const objects::PageObject& page,
			const std::string& hash
			)
			: lists(lists), creators(creators), page(page), hash(hash)
		{}

		ListResponse() = default;

	private:
		friend class RtResponseParser;
		inline static constexpr std::string_view DELIMITER = "#";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 4;
	};
}
