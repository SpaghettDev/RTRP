#pragma once

#include "fwddec.hpp"

namespace rtrp
{
	template<typename T>
	struct impl::Result
	{
		T result;
		bool isError;

		Result(const T& result, bool isError = false)
			: result(result), isError(isError)
		{}

		Result(bool isError)
			: isError(isError)
		{}
	};
}
