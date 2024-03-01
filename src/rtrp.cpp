#include "rtrp/rtrp.hpp"
#include "utils.hpp"

#define SPLIT_AND_ASSERT_SIZE_1(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if (var.size() != type::SPLIT_RESPONSE_SIZE) return {}
#define SPLIT_AND_ASSERT_SIZE_KVP_1(var, resp, type) \
	utils::splitKVP(resp, type::DELIMITER); \
	if (var.size() != type::SPLIT_RESPONSE_SIZE) return {}

#define SPLIT_AND_ASSERT_SIZE_2(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE && \
		var.size() != type::SPLIT_RESPONSE_SIZE2 \
		) return {}
#define SPLIT_AND_ASSERT_SIZE_KVP_2(var, resp, type) \
	utils::splitKVP(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE && \
		var.size() != type::SPLIT_RESPONSE_SIZE2 \
		) return {}

#define SPLIT_AND_ASSERT_SIZE_3(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE && \
		var.size() != type::SPLIT_RESPONSE_SIZE2 && \
		var.size() != type::SPLIT_RESPONSE_SIZE3 \
		) return {}
#define SPLIT_AND_ASSERT_SIZE_KVP_3(var, resp, type) \
	utils::splitKVP(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE && \
		var.size() != type::SPLIT_RESPONSE_SIZE2 && \
		var.size() != type::SPLIT_RESPONSE_SIZE3 \
		) return {}

#define SPLIT_AND_ASSERT_SIZE_4(var, resp, type) \
	utils::splitString(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE && \
		var.size() != type::SPLIT_RESPONSE_SIZE2 && \
		var.size() != type::SPLIT_RESPONSE_SIZE3 && \
		var.size() != type::SPLIT_RESPONSE_SIZE4 \
		) return {}
#define SPLIT_AND_ASSERT_SIZE_KVP_4(var, resp, type) \
	utils::splitKVP(resp, type::DELIMITER); \
	if ( \
		var.size() != type::SPLIT_RESPONSE_SIZE && \
		var.size() != type::SPLIT_RESPONSE_SIZE2 && \
		var.size() != type::SPLIT_RESPONSE_SIZE3 && \
		var.size() != type::SPLIT_RESPONSE_SIZE4 \
		) return {}

#define RTRP_TRY_PARSE_BEGIN try {
#define RTRP_TRY_PARSE_END } catch (...) { return {}; }

namespace rtrp
{
	impl::Result<responses::LevelResponse> RtResponseParser::parseLevelResponse(const std::string& resp)
	{
		RTRP_TRY_PARSE_BEGIN;
		auto splitResponse = SPLIT_AND_ASSERT_SIZE_1(splitResponse, resp, responses::LevelResponse);

		std::vector<objects::LevelObject> levelObjects;
		auto levelObjectsStrings = utils::splitString(splitResponse[0], objects::LevelObject::DELIMITER_SEARCH);
		for (const auto& levelObjectString : levelObjectsStrings)
		{
			auto levelObject = SPLIT_AND_ASSERT_SIZE_KVP_2(levelObject, levelObjectString, objects::LevelObject);
			levelObjects.emplace_back(objects::LevelObject::from_map(levelObject));
		}

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::splitString(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
		{
			auto creatorObject = SPLIT_AND_ASSERT_SIZE_1(creatorObject, creatorString, objects::CreatorObject);
			creatorObjects.emplace_back(objects::CreatorObject::from_vector(creatorObject));
		}

		std::optional<std::vector<objects::SongObject>> songObjects;
		if (!splitResponse[2].empty())
		{
			auto songObjectsStrings = utils::splitString(splitResponse[2], objects::SongObject::DELIMITER_SEARCH);
			for (auto const& songString : songObjectsStrings)
			{
				auto songObject = SPLIT_AND_ASSERT_SIZE_KVP_2(songObject, songString, objects::SongObject);
				songObjects->emplace_back(objects::SongObject::from_map(songObject));
			}
		}

		auto pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[3], objects::PageObject::DELIMITER));
		auto hash = splitResponse[4];

		return { { levelObjects, creatorObjects, songObjects, pageObject, hash } };
		RTRP_TRY_PARSE_END;
	}

	impl::Result<responses::ListResponse> RtResponseParser::parseListResponse(const std::string& resp)
	{
		RTRP_TRY_PARSE_BEGIN;
		auto splitResponse = SPLIT_AND_ASSERT_SIZE_1(splitResponse, resp, responses::ListResponse);

		std::vector<objects::ListObject> listObjects;
		auto listObjectsStrings = utils::splitString(splitResponse[0], objects::ListObject::DELIMITER_SEARCH);
		for (const auto& listString : listObjectsStrings)
		{
			auto listObject = SPLIT_AND_ASSERT_SIZE_KVP_1(listObject, listString, objects::ListObject);
			listObjects.emplace_back(objects::ListObject::from_map(listObject));
		}

		std::vector<objects::CreatorObject> creatorObjects;
		auto creatorObjectsStrings = utils::splitString(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		for (const auto& creatorString : creatorObjectsStrings)
		{
			auto creatorObject = SPLIT_AND_ASSERT_SIZE_1(creatorObject, creatorString, objects::CreatorObject);
			creatorObjects.emplace_back(objects::CreatorObject::from_vector(creatorObject));
		}

		auto pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[2], objects::PageObject::DELIMITER));
		auto hash = splitResponse[3];

		return { { listObjects, creatorObjects, pageObject, hash } };
		RTRP_TRY_PARSE_END;
	}

	impl::Result<responses::UserResponse> RtResponseParser::parseUserResponse(const std::string& resp)
	{
		RTRP_TRY_PARSE_BEGIN;
		auto splitResponse = SPLIT_AND_ASSERT_SIZE_2(splitResponse, resp, responses::UserResponse);

		std::vector<objects::UserObject> userObjects;
		auto userObjectsStrings = utils::splitString(splitResponse[0], objects::UserObject::DELIMITER_SEARCH);
		for (const auto& userString : userObjectsStrings)
			if (userString != "") // idk why but both getGJUserInfo20.php and getGJScores20.php return an empty UserObject in the very end ???
			{
				auto userObject = SPLIT_AND_ASSERT_SIZE_KVP_4(userObject, userString, objects::UserObject);
				userObjects.emplace_back(objects::UserObject::from_map(userObject));
			}

		std::optional<objects::PageObject> pageObject;
		if (splitResponse.size() == 2) // if getGJUsers20.php
			pageObject = objects::PageObject::from_vector(utils::splitString(splitResponse[1], objects::PageObject::DELIMITER));

		return { { userObjects, pageObject } };
		RTRP_TRY_PARSE_END;
	}
}
