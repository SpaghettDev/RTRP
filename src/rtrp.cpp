#include "rtrp/rtrp.hpp"
#include "macros.hpp"

#include <result/result.hpp>

namespace rtrp
{
	result::Result<responses::LevelResponse> RtResponseParser::parseLevelResponse(std::string_view resp)
	{
		auto&& splitResponse = SPLIT_AND_ASSERT_SIZE_1(splitResponse, resp, responses::LevelResponse);

		auto&& levelObjectsStrings = utils::splitString(splitResponse[0], objects::LevelObject::DELIMITER_SEARCH);
		std::vector<objects::LevelObject> levelObjects{};
		RESIZE_CONTAINER(levelObjects, levelObjectsStrings);
		for (const auto& levelObjectString : levelObjectsStrings)
		{
			SPLIT_AND_ASSERT_SIZE_KVP_2(auto&& levelObjectMap, levelObjectString, objects::LevelObject);
			auto&& levelObject = objects::LevelObject::from_map(std::move(levelObjectMap));

			if (levelObject.isErr())
				return result::Err("Malformed LevelObject string");

			levelObjects.emplace_back(levelObject.unwrap());
		}

		auto&& creatorObjectsStrings = utils::splitString(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		std::vector<objects::CreatorObject> creatorObjects{};
		RESIZE_CONTAINER(creatorObjects, creatorObjectsStrings);
		for (const auto& creatorString : creatorObjectsStrings)
		{
			auto&& creatorObjectMap = SPLIT_AND_ASSERT_SIZE_1(creatorObjectMap, creatorString, objects::CreatorObject);
			auto&& creatorObject = objects::CreatorObject::from_vector(std::move(creatorObjectMap));

			if (creatorObject.isErr())
				return result::Err("Malformed CreatorObject string");

			creatorObjects.emplace_back(creatorObject.unwrap());
		}

		std::vector<objects::SongObject> songObjects{};
		if (!splitResponse[2].empty())
		{
			auto&& songObjectsStrings = utils::splitString(splitResponse[2], objects::SongObject::DELIMITER_SEARCH);
			RESIZE_CONTAINER(songObjects, songObjectsStrings);

			for (auto const& songString : songObjectsStrings)
			{
				SPLIT_AND_ASSERT_SIZE_KVP_2(auto&& songObjectMap, songString, objects::SongObject);
				auto&& songObject = objects::SongObject::from_map(std::move(songObjectMap));

				if (songObject.isErr())
					return result::Err("Malformed SongObject string");

				songObjects.emplace_back(songObject.unwrap());
			}
		}

		auto&& pageObjectStrings = utils::splitString(splitResponse[3], objects::PageObject::DELIMITER);
		auto&& pageObject = objects::PageObject::from_vector(std::move(pageObjectStrings));
		if (pageObject.isErr())
			return result::Err("Malformed PageObject string");

		auto& hash = splitResponse[4];

		return result::Ok<responses::LevelResponse>(
			std::move(levelObjects), std::move(creatorObjects),
			std::move(songObjects), std::move(pageObject.unwrap()),
			std::move(hash)
		);
	}

	result::Result<responses::ListResponse> RtResponseParser::parseListResponse(const std::string_view resp)
	{
		auto&& splitResponse = SPLIT_AND_ASSERT_SIZE_1(splitResponse, resp, responses::ListResponse);

		auto&& listObjectsStrings = utils::splitString(splitResponse[0], objects::ListObject::DELIMITER_SEARCH);
		std::vector<objects::ListObject> listObjects{};
		RESIZE_CONTAINER(listObjects, listObjectsStrings);
		for (const auto& listString : listObjectsStrings)
		{
			SPLIT_AND_ASSERT_SIZE_KVP_1(auto&& listObjectMap, listString, objects::ListObject);
			auto&& listObject = objects::ListObject::from_map(std::move(listObjectMap));

			if (listObject.isErr())
				return result::Err("Malformed ListObject string");

			listObjects.emplace_back(listObject.unwrap());
		}

		auto&& creatorObjectsStrings = utils::splitString(splitResponse[1], objects::CreatorObject::DELIMITER_SEARCH);
		std::vector<objects::CreatorObject> creatorObjects{};
		RESIZE_CONTAINER(creatorObjects, creatorObjectsStrings);
		for (const auto& creatorString : creatorObjectsStrings)
		{
			auto&& creatorObjectMap = SPLIT_AND_ASSERT_SIZE_1(creatorObjectMap, creatorString, objects::CreatorObject);
			auto&& creatorObject = objects::CreatorObject::from_vector(std::move(creatorObjectMap));

			if (creatorObject.isErr())
				return result::Err("Malformed CreatorObject string");

			creatorObjects.emplace_back(creatorObject.unwrap());
		}

		auto&& pageObjectStrings = utils::splitString(splitResponse[2], objects::PageObject::DELIMITER);
		auto&& pageObject = objects::PageObject::from_vector(std::move(pageObjectStrings));
		if (pageObject.isErr())
			return result::Err("Malformed PageObject string");

		auto& hash = splitResponse[3];

		return result::Ok<responses::ListResponse>(
			std::move(listObjects), std::move(creatorObjects),
			std::move(pageObject.unwrap()), std::move(hash)
		);
	}

	result::Result<responses::UserResponse> RtResponseParser::parseUserResponse(const std::string_view resp)
	{
		auto&& splitResponse = SPLIT_AND_ASSERT_SIZE_2(splitResponse, resp, responses::UserResponse);

		auto&& userObjectsStrings = utils::splitString(splitResponse[0], objects::UserObject::DELIMITER_SEARCH);
		std::vector<objects::UserObject> userObjects{};
		RESIZE_CONTAINER(userObjects, userObjectsStrings);
		for (const auto& userString : userObjectsStrings)
			if (userString != "") // idk why but both getGJUserInfo20.php and getGJScores20.php return an empty UserObject in the very end ???
			{
				SPLIT_AND_ASSERT_SIZE_KVP_4(auto&& userObjectMap, userString, objects::UserObject);
				auto&& userObject = objects::UserObject::from_map(std::move(userObjectMap));

				if (userObject.isErr())
					return result::Err("Malformed UserObject string");

				userObjects.emplace_back(userObject.unwrap());
			}

		std::optional<objects::PageObject> pageObject;
		if (splitResponse.size() == 2) // if getGJUsers20.php
		{
			auto&& pageObjectRes = objects::PageObject::from_vector(
				utils::splitString(splitResponse[1], objects::PageObject::DELIMITER)
			);

			if (pageObjectRes.isErr())
				return result::Err("Malformed PageObject string");

			pageObject.emplace(std::move(pageObjectRes.unwrap()));
		}

		return result::Ok<responses::UserResponse>(std::move(userObjects), std::move(pageObject));
	}
}
