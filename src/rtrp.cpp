#include "rtrp/rtrp.hpp"
#include "utils.hpp"

// doesn't assert size cuz making that work is making me fucking insane (cannot construct an empty LevelResponse without making the constructor, boy oh boy will the constructor be constructing with 5 billion members)
#define SPLIT_AND_ASSERT_SIZE(var, resp, type) \
	utils::split(resp, type::DELIMITER); // \
	// if (var.size() != type::SPLIT_RESPONSE_SIZE) return {}

namespace rtrp
{
	responses::LevelResponse RtResponseParser::parseLevelResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE(splitResponse, resp, responses::ListResponse);

		std::vector<objects::LevelObject> levelObjects;
		auto levelObjectsStrings = utils::split(splitResponse[0], objects::LevelObject::DELIMITER_SEARCH);
		for (const auto& levelObjectString : levelObjectsStrings)
			levelObjects.push_back(objects::LevelObject::from_vector(utils::split(levelObjectString, objects::LevelObject::DELIMITER)));

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::split(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.push_back(objects::CreatorObject::from_vector(utils::split(creatorString, objects::CreatorObject::DELIMITER)));

		std::vector<objects::SongObject> songObjects;
		auto songObjectsStrings = utils::split(splitResponse[2], objects::SongObject::DELIMITER_SEARCH);
		for (auto const& songString : songObjectsStrings)
			songObjects.push_back(objects::SongObject::from_vector(utils::split(songString, objects::SongObject::DELIMITER)));

		auto pageObject = objects::PageObject::from_vector(utils::split(splitResponse[3], objects::PageObject::DELIMITER));
		auto hash = splitResponse[4];

		return { levelObjects, creatorObjects, songObjects, pageObject, hash };
	}

	responses::ListResponse RtResponseParser::parseListResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE(splitResponse, resp, responses::ListResponse);

		std::vector<objects::ListObject> listObjects;
		auto listObjectsStrings = utils::split(splitResponse[0], objects::ListObject::DELIMITER_SEARCH);
		for (const auto& listString : listObjectsStrings)
			listObjects.push_back(objects::ListObject::from_vector(utils::split(listString, objects::ListObject::DELIMITER)));

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::split(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.push_back(objects::CreatorObject::from_vector(utils::split(creatorString, objects::CreatorObject::DELIMITER)));

		auto pageObject = objects::PageObject::from_vector(utils::split(splitResponse[2], objects::PageObject::DELIMITER));
		auto hash = splitResponse[3];

		return { listObjects, creatorObjects, pageObject, hash };
	}
}
