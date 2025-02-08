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
		std::vector<objects::SongObject> songs; // optional
		objects::PageObject page;
		std::string hash;

		LevelResponse(
			std::vector<objects::LevelObject>&& levels,
			std::vector<objects::CreatorObject>&& creators,
			std::vector<objects::SongObject>&& songs,
			objects::PageObject&& page,
			std::string&& hash
		)
			: levels(std::move(levels)), creators(std::move(creators)),
				songs(std::move(songs)), page(std::move(page)),
				hash(std::move(hash))
		{}

		LevelResponse() = default;

	private:
		friend class ::rtrp::RtResponseParser;
		inline static const std::string_view DELIMITER = "#";
		static constexpr unsigned int SPLIT_RESPONSE_SIZE = 5;
	};
}
