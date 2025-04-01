#pragma once
#include "../fwddec.hpp"

namespace rtrp
{
	struct objects::CreatorObject
	{
		int userID;
		std::string name;
		int accountID;

#ifdef __APPLE__
		CreaCreatorObject() = default;
		CreatorObject(int userID, std::string&& name, int accountID)
			: userID(userID), name(std::move(name)), accountID(accountID)
		{}
#endif

	private:
		friend class ::rtrp::RtResponseParser;
		inline static constexpr std::string_view DELIMITER = ":";
		inline static constexpr std::string_view DELIMITER_SEARCH = "|";
		inline static constexpr unsigned int SPLIT_RESPONSE_SIZE = 3;

		static result::Result<CreatorObject> from_vector(v_response_t&& vec)
		{
			RTRP_VAR_FROM_VEC_SAFE_INTO(auto userID, 0, userID);
			RTRP_VAR_FROM_VEC_SAFE_INTO(auto name, 1, name);
			RTRP_VAR_FROM_VEC_SAFE_INTO(auto accountID, 2, accountID);

			return { userID, std::move(name), accountID };
		}
	};
}
