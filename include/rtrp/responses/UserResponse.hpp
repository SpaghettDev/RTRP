#pragma once
#include <optional>

#include "../fwddec.hpp"

#include "../objects/UserObject.hpp"
#include "../objects/PageObject.hpp"

namespace rtrp
{
	struct responses::UserResponse
	{
		std::vector<objects::UserObject> users;
		std::optional<objects::PageObject> page;

		UserResponse(std::vector<objects::UserObject>&& users)
			: users(std::move(users)), page(std::nullopt)
		{}

		UserResponse(
			std::vector<objects::UserObject>&& users,
			std::optional<objects::PageObject>&& page
		)
			: users(std::move(users)), page(std::move(page))
		{}

		UserResponse() = default;

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = "#";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 1; // getGJUserInfo20.php & getGJScores20.php
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE2 = 2; // getGJUsers20.php
	};
}
