#pragma once
#include "fwddec.hpp"

#include "responses/LevelResponse.hpp"
#include "responses/ListResponse.hpp"
#include "responses/UserResponse.hpp"

namespace rtrp
{
	class RtResponseParser
	{
	public:
		static responses::LevelResponse parseLevelResponse(const std::string&);
		static responses::ListResponse parseListResponse(const std::string&);
		inline responses::UserResponse parseUserResponse(const std::string&);
	};
}
