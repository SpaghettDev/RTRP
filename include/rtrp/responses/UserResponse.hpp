#pragma once
#include <optional>

#include "../fwddec.hpp"

#include "../objects/UserObject.hpp"

namespace rtrp
{
	struct responses::UserResponse
	{
		std::vector<objects::UserObject> users;
		std::optional<objects::PageObject> page;

		UserResponse(const std::vector<objects::UserObject>& users)
			: users(users), page(std::nullopt)
		{}

		UserResponse(const std::vector<objects::UserObject>& users, const std::optional<objects::PageObject>& page)
			: users(users), page(page)
		{}

	private:
		inline static constexpr std::string_view DELIMITER = "#";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 4;
		friend class RtResponseParser;
	};
}
