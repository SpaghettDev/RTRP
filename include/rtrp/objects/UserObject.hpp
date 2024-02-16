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
		impl::v_response_t unk55;

	private:
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		inline static constexpr unsigned int MAX_SIZE = 55;
		friend class RtResponseParser;

		static const UserObject from_map(const impl::kv_response_t& map)
		{
			return {
				RTRP_VAR_FROM_MAP(1, userName),
				RTRP_VAR_FROM_MAP(2, userID),
				RTRP_VAR_FROM_MAP(3, stars),
				RTRP_VAR_FROM_MAP(4, demons),
				RTRP_VAR_FROM_MAP(6, ranking),
				RTRP_VAR_FROM_MAP(7, accountHighlight),
				RTRP_VAR_FROM_MAP(8, creatorPoints),
				RTRP_VAR_FROM_MAP(9, iconID),
				RTRP_VAR_FROM_MAP(10, playerColor),
				RTRP_VAR_FROM_MAP(11, playerColor2),
				RTRP_VAR_FROM_MAP(13, secretCoins),
				RTRP_VAR_FROM_MAP(14, iconType),
				RTRP_VAR_FROM_MAP(15, special),
				RTRP_VAR_FROM_MAP(16, accountID),
				RTRP_VAR_FROM_MAP(17, userCoins),
				RTRP_VAR_FROM_MAP(18, messageState),
				RTRP_VAR_FROM_MAP(19, friendsState),
				RTRP_VAR_FROM_MAP(20, youTube),
				RTRP_VAR_FROM_MAP(21, accIcon),
				RTRP_VAR_FROM_MAP(22, accShip),
				RTRP_VAR_FROM_MAP(23, accBall),
				RTRP_VAR_FROM_MAP(24, accBird),
				RTRP_VAR_FROM_MAP(25, accDart),
				RTRP_VAR_FROM_MAP(26, accRobot),
				RTRP_VAR_FROM_MAP(27, accStreak),
				RTRP_VAR_FROM_MAP(28, accGlow),
				RTRP_VAR_FROM_MAP(29, isRegistered),
				RTRP_VAR_FROM_MAP(30, globalRank),
				RTRP_VAR_FROM_MAP(31, friendState),
				RTRP_VAR_FROM_MAP(38, messages),
				RTRP_VAR_FROM_MAP(39, friendRequests),
				RTRP_VAR_FROM_MAP(40, newFriends),
				RTRP_VAR_FROM_MAP(41, newFriendRequest),
				RTRP_VAR_FROM_MAP(42, age),
				RTRP_VAR_FROM_MAP(43, accSpider),
				RTRP_VAR_FROM_MAP(44, twitter),
				RTRP_VAR_FROM_MAP(45, twitch),
				RTRP_VAR_FROM_MAP(46, diamonds),
				RTRP_VAR_FROM_MAP(48, accExplosion),
				RTRP_VAR_FROM_MAP(49, modLevel),
				RTRP_VAR_FROM_MAP(50, commentHistoryState),
				RTRP_VAR_FROM_MAP(51, unk51),
				RTRP_VAR_FROM_MAP(52, moons),
				RTRP_VAR_FROM_MAP(53, unk53),
				RTRP_VAR_FROM_MAP(54, unk54),
				RTRP_VEC_VAR_FROM_MAP(55, unk55, ",")
			};
		}
	};
}
