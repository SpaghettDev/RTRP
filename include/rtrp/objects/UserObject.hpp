#pragma once
#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::UserObject
	{
		enum class MessageState
		{
			ALL,
			ONLY_FRIENDS,
			NONE
		};

		enum class FriendsState
		{
			ALL,
			NONE
		};

		enum class FriendState
		{
			NONE,
			ALREADY_FRIEND,
			REQ_SENT_TARGET_HASNT_ACCEPTED_YET = 3,
			TARGET_SENT_REQ_HASNT_ACCEPTED_YET,
		};

		enum class CommentHistoryState
		{
			ALL,
			FRIENDS_ONLY,
			NONE
		};

		enum class ModLevel
		{
			NONE,
			NORMAL,
			ELDER
		};

		std::string userName;
		int userID;
		int stars;
		int demons;
		int ranking;
		int accountHighlight;
		int creatorPoints;
		int iconID;
		int playerColor;
		int playerColor2;
		int secretCoins;
		int iconType;
		int special;
		int accountID;
		int userCoins;
		MessageState messageState;
		FriendsState friendsState;
		std::string youTube;
		int accIcon;
		int accShip;
		int accBall;
		int accBird;
		int accDart;
		int accRobot;
		int accStreak;
		int accGlow;
		int isRegistered;
		int globalRank;
		FriendState friendState;
		int messages;
		int friendRequests;
		int newFriends;
		bool newFriendRequest;
		std::string age;
		int accSpider;
		std::string twitter;
		std::string twitch;
		int diamonds;
		int accExplosion;
		ModLevel modLevel;
		CommentHistoryState commentHistoryState;
		int unk51;
		int moons;
		int unk53;
		int unk54;
		std::vector<std::string> unk55;

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		static constexpr unsigned int SPLIT_RESPONSE_SIZE = 30; // getGJUserInfo20.php
		static constexpr unsigned int SPLIT_RESPONSE_SIZE2 = 15; // getGJScores20.php
		static constexpr unsigned int SPLIT_RESPONSE_SIZE3 = 14; // getGJUsers20.php
		static constexpr unsigned int SPLIT_RESPONSE_SIZE4 = 10; // getGJUserList20.php

		static result::Result<UserObject> from_map(kv_response_t&& map)
		{
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto userName, 1, userName);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto userID, 2, userID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto stars, 3, stars);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto demons, 4, demons);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto ranking, 6, ranking);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accountHighlight, 7, accountHighlight);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto creatorPoints, 8, creatorPoints);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto iconID, 9, iconID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto playerColor, 10, playerColor);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto playerColor2, 11, playerColor2);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto secretCoins, 13, secretCoins);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto iconType, 14, iconType);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto special, 15, special);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accountID, 16, accountID);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto userCoins, 17, userCoins);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto messageState, 18, messageState);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto friendsState, 19, friendsState);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto youTube, 20, youTube);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accIcon, 21, accIcon);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accShip, 22, accShip);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accBall, 23, accBall);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accBird, 24, accBird);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accDart, 25, accDart);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accRobot, 26, accRobot);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accStreak, 27, accStreak);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accGlow, 28, accGlow);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto isRegistered, 29, isRegistered);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto globalRank, 30, globalRank);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto friendState, 31, friendState);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto messages, 38, messages);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto friendRequests, 39, friendRequests);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto newFriends, 40, newFriends);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto newFriendRequest, 41, newFriendRequest);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto age, 42, age);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accSpider, 43, accSpider);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto twitter, 44, twitter);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto twitch, 45, twitch);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto diamonds, 46, diamonds);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto accExplosion, 48, accExplosion);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto modLevel, 49, modLevel);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto commentHistoryState, 50, commentHistoryState);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto unk51, 51, unk51);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto moons, 52, moons);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto unk53, 53, unk53);
			RTRP_VAR_FROM_MAP_SAFE_INTO(auto unk54, 54, unk54);
			RTRP_VEC_VAR_FROM_MAP_SAFE_INTO(auto unk55, 55, unk55, ",");

			return {
				userName,
				userID,
				stars,
				demons,
				ranking,
				accountHighlight,
				creatorPoints,
				iconID,
				playerColor,
				playerColor2,
				secretCoins,
				iconType,
				special,
				accountID,
				userCoins,
				messageState,
				friendsState,
				youTube,
				accIcon,
				accShip,
				accBall,
				accBird,
				accDart,
				accRobot,
				accStreak,
				accGlow,
				isRegistered,
				globalRank,
				friendState,
				messages,
				friendRequests,
				newFriends,
				newFriendRequest,
				age,
				accSpider,
				twitter,
				twitch,
				diamonds,
				accExplosion,
				modLevel,
				commentHistoryState,
				unk51,
				moons,
				unk53,
				unk54,
				unk55
			};
		}
	};
}
