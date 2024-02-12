#pragma once
#include <string>
#include <vector>

#include "fwddec.hpp"

#include "objects/LevelObject.hpp"
#include "objects/ListObject.hpp"
#include "objects/CreatorObject.hpp"
#include "objects/SongObject.hpp"
#include "objects/PageObject.hpp"

#include "responses/LevelResponse.hpp"
#include "responses/ListResponse.hpp"

namespace rtrp
{
	class RtResponseParser
	{
	public:
		static responses::LevelResponse parseLevelResponse(const std::string&);
		static responses::ListResponse parseListResponse(const std::string&);
	};
}
