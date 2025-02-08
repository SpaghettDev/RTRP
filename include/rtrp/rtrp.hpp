#pragma once
#include "fwddec.hpp"

#include <result/result.hpp>

#include "responses/LevelResponse.hpp"
#include "responses/ListResponse.hpp"
#include "responses/UserResponse.hpp"

namespace rtrp
{
	class RtResponseParser
	{
	public:
		static result::Result<responses::LevelResponse> parseLevelResponse(const std::string_view);
		static result::Result<responses::ListResponse> parseListResponse(const std::string_view);
		static result::Result<responses::UserResponse> parseUserResponse(const std::string_view);
	};
}
