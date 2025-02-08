#pragma once

#if !defined(RTRP_CONCAT)
    #define RTRP_CONCAT2(x, y) x##y
    #define RTRP_CONCAT(x, y) RTRP_CONCAT2(x, y)
#endif

// yeah...

#ifdef RTRP_DONT_RESERVE_CONTAINER_SIZES
#define RESIZE_CONTAINER(container, other) (void)0
#else
#define RESIZE_CONTAINER(container, other) container.reserve(other.size())
#endif

#define SPLIT_AND_ASSERT_SIZE_1(var, resp, type)                                    \
	utils::splitString(resp, type::DELIMITER);                                      \
	if (var.size() != type::SPLIT_RESPONSE_SIZE)                                    \
		return result::Err("Response has invalid size after splitting")
#define SPLIT_AND_ASSERT_SIZE_KVP_1(var, resp, type)                                \
	auto RTRP_CONCAT(res, __LINE__) = utils::splitKVP(resp, type::DELIMITER);       \
	if (RTRP_CONCAT(res, __LINE__).isErr())                                         \
		return result::Err(std::move(RTRP_CONCAT(res, __LINE__).unwrapErr()));      \
	if (RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE)    \
		return result::Err("Response has invalid size after splitting");            \
	var = std::move(RTRP_CONCAT(res, __LINE__).unwrap())

#define SPLIT_AND_ASSERT_SIZE_2(var, resp, type)                                    \
	utils::splitString(resp, type::DELIMITER);                                      \
	if (                                                                            \
		var.size() != type::SPLIT_RESPONSE_SIZE &&                                  \
		var.size() != type::SPLIT_RESPONSE_SIZE2                                    \
		) return result::Err("Response has invalid size after splitting")
#define SPLIT_AND_ASSERT_SIZE_KVP_2(var, resp, type)                                \
	auto RTRP_CONCAT(res, __LINE__) = utils::splitKVP(resp, type::DELIMITER);       \
	if (RTRP_CONCAT(res, __LINE__).isErr())                                         \
		return result::Err(std::move(RTRP_CONCAT(res, __LINE__).unwrapErr()));      \
	if (                                                                            \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE &&  \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE2    \
		) return result::Err("Response has invalid size after splitting");          \
	var = std::move(RTRP_CONCAT(res, __LINE__).unwrap())

#define SPLIT_AND_ASSERT_SIZE_3(var, resp, type)                                    \
	utils::splitString(resp, type::DELIMITER);                                      \
	if (                                                                            \
		var.size() != type::SPLIT_RESPONSE_SIZE &&                                  \
		var.size() != type::SPLIT_RESPONSE_SIZE2 &&                                 \
		var.size() != type::SPLIT_RESPONSE_SIZE3                                    \
		) return result::Err("Response has invalid size after splitting")
#define SPLIT_AND_ASSERT_SIZE_KVP_3(var, resp, type)                                \
	auto RTRP_CONCAT(res, __LINE__) = utils::splitKVP(resp, type::DELIMITER);       \
	if (RTRP_CONCAT(res, __LINE__).isErr())                                         \
		return result::Err(std::move(RTRP_CONCAT(res, __LINE__).unwrapErr()));      \
	if (                                                  \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE &&  \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE2 && \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE3    \
		) return result::Err("Response has invalid size after splitting");          \
	var = std::move(RTRP_CONCAT(res, __LINE__).unwrap())

#define SPLIT_AND_ASSERT_SIZE_4(var, resp, type)                                    \
	utils::splitString(resp, type::DELIMITER);                                      \
	if (                                                                            \
		var.size() != type::SPLIT_RESPONSE_SIZE &&                                  \
		var.size() != type::SPLIT_RESPONSE_SIZE2 &&                                 \
		var.size() != type::SPLIT_RESPONSE_SIZE3 &&                                 \
		var.size() != type::SPLIT_RESPONSE_SIZE4                                    \
		) return result::Err("Response has invalid size after splitting")
#define SPLIT_AND_ASSERT_SIZE_KVP_4(var, resp, type)                                \
	auto RTRP_CONCAT(res, __LINE__) = utils::splitKVP(resp, type::DELIMITER);       \
	if (RTRP_CONCAT(res, __LINE__).isErr())                                         \
		return result::Err(std::move(RTRP_CONCAT(res, __LINE__).unwrapErr()));      \
	if (                                                                            \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE &&  \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE2 && \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE3 && \
		RTRP_CONCAT(res, __LINE__).unwrap().size() != type::SPLIT_RESPONSE_SIZE4    \
		) return result::Err("Response has invalid size after splitting");          \
	var = std::move(RTRP_CONCAT(res, __LINE__).unwrap())
