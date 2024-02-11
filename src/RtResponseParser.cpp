#include "RtResponseParser.hpp"

// doesn't assert size cuz making that work is making me fucking insane (cannot construct an empty LevelResponse without making the constructor, boy oh boy will the constructor be constructing with 5 billion members)
#define SPLIT_AND_ASSERT_SIZE(var, resp, type) \
	utils::split(resp, type::DELIMITER); // \
	// if (var.size() != type::SPLIT_RESPONSE_SIZE) return {}

namespace rtrp
{
	types::LevelResponse RtResponseParser::parseLevelResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE(splitResponse, resp, types::ListResponse);

		std::vector<types::LevelObject> levelObjects;
		auto levelObjectsStrings = utils::split(splitResponse[0], types::LevelObject::DELIMITER_SEARCH);
		for (const auto& levelObjectString : levelObjectsStrings)
			levelObjects.push_back(types::LevelObject::from_vector(utils::split(levelObjectString, types::LevelObject::DELIMITER)));

		std::vector<types::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::split(splitResponse[1], types::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.push_back(types::CreatorObject::from_vector(utils::split(creatorString, types::CreatorObject::DELIMITER)));

		std::vector<types::SongObject> songObjects;
		auto songObjectsStrings = utils::split(splitResponse[2], types::SongObject::DELIMITER_SEARCH);
		for (auto const& songString : songObjectsStrings)
			songObjects.push_back(types::SongObject::from_vector(utils::split(songString, types::SongObject::DELIMITER)));

		auto pageObject = types::PageObject::from_vector(utils::split(splitResponse[3], types::PageObject::DELIMITER));
		auto hash = splitResponse[4];

		return { levelObjects, creatorObjects, songObjects, pageObject, hash };
	}

	types::ListResponse RtResponseParser::parseListResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE(splitResponse, resp, types::ListResponse);

		std::vector<types::ListObject> listObjects;
		auto listObjectsStrings = utils::split(splitResponse[0], types::ListObject::DELIMITER_SEARCH);
		for (const auto& listString : listObjectsStrings)
			listObjects.push_back(types::ListObject::from_vector(utils::split(listString, types::ListObject::DELIMITER)));

		std::vector<types::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::split(splitResponse[1], types::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.push_back(types::CreatorObject::from_vector(utils::split(creatorString, types::CreatorObject::DELIMITER)));

		auto pageObject = types::PageObject::from_vector(utils::split(splitResponse[2], types::PageObject::DELIMITER));
		auto hash = splitResponse[3];

		return { listObjects, creatorObjects, pageObject, hash };
	}
}
