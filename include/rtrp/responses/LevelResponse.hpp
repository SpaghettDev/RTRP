#pragma once
#include "../fwddec.hpp"

#include "../objects/LevelObject.hpp"
#include "../objects/CreatorObject.hpp"
#include "../objects/SongObject.hpp"
#include "../objects/PageObject.hpp"

namespace rtrp
{
	struct responses::LevelResponse
	{
		std::vector<objects::LevelObject> levels;
		std::vector<objects::CreatorObject> creators;
		std::vector<objects::SongObject> songs;
		objects::PageObject page;
		std::string hash;

		LevelResponse(
			const std::vector<objects::LevelObject>& levels,
			const std::vector<objects::CreatorObject>& creators,
			const std::vector<objects::SongObject>& songs,
			const objects::PageObject& page,
			const std::string& hash
			)
			: levels(levels), creators(creators), songs(songs), page(page), hash(hash)
		{}

		LevelResponse() = default;

	private:
		inline static const std::string_view DELIMITER = "#";
		static constexpr unsigned int SPLIT_RESPONSE_SIZE = 5;
		friend class RtResponseParser;
	};
}
