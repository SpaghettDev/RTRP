#include "rtrp/rtrp.hpp"
#include "utils.hpp"

// doesn't assert size cuz making that work is making me fucking insane (cannot construct an empty LevelResponse without making the constructor, boy oh boy will the constructor be constructing with 5 billion members)
#define SPLIT_AND_ASSERT_SIZE(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); // \
	// if (var.size() != type::SPLIT_RESPONSE_SIZE) return {}

namespace rtrp
{
	responses::LevelResponse RtResponseParser::parseLevelResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE(splitResponse, resp, responses::ListResponse);

		std::vector<objects::LevelObject> levelObjects;
		auto levelObjectsStrings = utils::splitString(splitResponse[0], objects::LevelObject::DELIMITER_SEARCH);
		for (const auto& levelObjectString : levelObjectsStrings)
			levelObjects.emplace_back(objects::LevelObject::from_map(utils::splitKVP(levelObjectString, objects::LevelObject::DELIMITER)));

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::splitString(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.emplace_back(objects::CreatorObject::from_vector(utils::splitString(creatorString, objects::CreatorObject::DELIMITER)));

		std::vector<objects::SongObject> songObjects;
		auto songObjectsStrings = utils::splitString(splitResponse[2], objects::SongObject::DELIMITER_SEARCH);
		for (auto const& songString : songObjectsStrings)
			songObjects.emplace_back(objects::SongObject::from_map(utils::splitKVP(songString, objects::SongObject::DELIMITER)));

		auto pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[3], objects::PageObject::DELIMITER));
		auto hash = splitResponse[4];

		return { levelObjects, creatorObjects, songObjects, pageObject, hash };
	}

	responses::ListResponse RtResponseParser::parseListResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE(splitResponse, resp, responses::ListResponse);

		std::vector<objects::ListObject> listObjects;
		auto listObjectsStrings = utils::splitString(splitResponse[0], objects::ListObject::DELIMITER_SEARCH);
		for (const auto& listString : listObjectsStrings)
			listObjects.emplace_back(objects::ListObject::from_map(utils::splitKVP(listString, objects::ListObject::DELIMITER)));

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::splitString(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.emplace_back(objects::CreatorObject::from_vector(utils::splitString(creatorString, objects::CreatorObject::DELIMITER)));

		auto pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[2], objects::PageObject::DELIMITER));
		auto hash = splitResponse[3];

		return { listObjects, creatorObjects, pageObject, hash };
	}

	responses::UserResponse RtResponseParser::parseUserResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE(splitKVP, resp, responses::UserResponse);

		std::vector<objects::UserObject> userObjects;
		auto userObjectsStrings = utils::splitString(splitResponse[0], objects::UserObject::DELIMITER_SEARCH);
		for (const auto& userString : userObjectsStrings)
			if (userString != "") // idk why but both getGJUserInfo20.php and getGJScores20.php return an empty UserObject in the very end ???
				userObjects.emplace_back(objects::UserObject::from_map(utils::splitKVP(userString, objects::UserObject::DELIMITER)));

		std::optional<objects::PageObject> pageObject;
		// if getGJUsers20.php
		if (splitResponse.size() == 2)
			pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[1], objects::PageObject::DELIMITER));

		return { userObjects, pageObject };
	}
}
