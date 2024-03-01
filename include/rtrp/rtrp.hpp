#pragma once
#include "fwddec.hpp"

#include "impl/result.hpp"

#include "responses/LevelResponse.hpp"
#include "responses/ListResponse.hpp"
#include "responses/UserResponse.hpp"

namespace rtrp
{
	class RtResponseParser
	{
	public:
		static impl::Result<responses::LevelResponse> parseLevelResponse(const std::string&);
		static impl::Result<responses::ListResponse> parseListResponse(const std::string&);
		static impl::Result<responses::UserResponse> parseUserResponse(const std::string&);
	};
}
