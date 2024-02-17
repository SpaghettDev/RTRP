#include "rtrp/rtrp.hpp"
#include "utils.hpp"

#define SPLIT_AND_ASSERT_SIZE1(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if (var.size() != type::SPLIT_RESPONSE_SIZE) return {}

#define SPLIT_AND_ASSERT_SIZE2(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE || \
		var.size() != type::SPLIT_RESPONSE_SIZE2 \
		) return {}

#define SPLIT_AND_ASSERT_SIZE3(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE || \
		var.size() != type::SPLIT_RESPONSE_SIZE2 || \
		var.size() != type::SPLIT_RESPONSE_SIZE3 \
		) return {}

#define SPLIT_AND_ASSERT_SIZE4(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE || \
		var.size() != type::SPLIT_RESPONSE_SIZE2 || \
		var.size() != type::SPLIT_RESPONSE_SIZE3 || \
		var.size() != type::SPLIT_RESPONSE_SIZE4 \
		) return {}

namespace rtrp
{
	impl::Result<responses::LevelResponse> RtResponseParser::parseLevelResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE1(splitResponse, resp, responses::LevelResponse);

		std::vector<objects::LevelObject> levelObjects;
		auto levelObjectsStrings = SPLIT_AND_ASSERT_SIZE2(levelObjectsStrings, splitResponse[0], objects::LevelObject);
		for (const auto& levelObjectString : levelObjectsStrings)
			levelObjects.emplace_back(objects::LevelObject::from_map(utils::splitKVP(levelObjectString, objects::LevelObject::DELIMITER)));

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = SPLIT_AND_ASSERT_SIZE1(creatorObjectsStrings, splitResponse[1], objects::CreatorObject);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.emplace_back(objects::CreatorObject::from_vector(utils::splitString(creatorString, objects::CreatorObject::DELIMITER)));

		std::vector<objects::SongObject> songObjects;
		auto songObjectsStrings = SPLIT_AND_ASSERT_SIZE1(songObjectsStrings, splitResponse[2], objects::SongObject);
		for (auto const& songString : songObjectsStrings)
			songObjects.emplace_back(objects::SongObject::from_map(utils::splitKVP(songString, objects::SongObject::DELIMITER)));

		auto pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[3], objects::PageObject::DELIMITER));
		auto hash = splitResponse[4];

		return { { levelObjects, creatorObjects, songObjects, pageObject, hash } };
	}

	impl::Result<responses::ListResponse> RtResponseParser::parseListResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE1(splitResponse, resp, responses::ListResponse);

		std::vector<objects::ListObject> listObjects;
		auto listObjectsStrings = SPLIT_AND_ASSERT_SIZE1(listObjectsStrings, splitResponse[0], objects::ListObject);
		for (const auto& listString : listObjectsStrings)
			listObjects.emplace_back(objects::ListObject::from_map(utils::splitKVP(listString, objects::ListObject::DELIMITER)));

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = SPLIT_AND_ASSERT_SIZE1(creatorObjectsStrings, splitResponse[1], objects::CreatorObject);
		for (const auto& creatorString : creatorObjectsStrings)
			creatorObjects.emplace_back(objects::CreatorObject::from_vector(utils::splitString(creatorString, objects::CreatorObject::DELIMITER)));

		auto pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[2], objects::PageObject::DELIMITER));
		auto hash = splitResponse[3];

		return { { listObjects, creatorObjects, pageObject, hash } };
	}

	impl::Result<responses::UserResponse> RtResponseParser::parseUserResponse(const std::string& resp)
	{
		auto splitResponse = SPLIT_AND_ASSERT_SIZE2(splitResponse, resp, responses::UserResponse);

		std::vector<objects::UserObject> userObjects;
		auto userObjectsStrings = SPLIT_AND_ASSERT_SIZE4(userObjectsStrings, splitResponse[0], objects::UserObject);
		for (const auto& userString : userObjectsStrings)
			if (userString != "") // idk why but both getGJUserInfo20.php and getGJScores20.php return an empty UserObject in the very end ???
				userObjects.emplace_back(objects::UserObject::from_map(utils::splitKVP(userString, objects::UserObject::DELIMITER)));

		std::optional<objects::PageObject> pageObject;
		// if getGJUsers20.php
		if (splitResponse.size() == 2)
			pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[1], objects::PageObject::DELIMITER));

		return { { userObjects, pageObject } };
	}
}
