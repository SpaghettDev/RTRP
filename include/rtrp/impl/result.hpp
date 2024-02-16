#pragma once
#include <stdexcept>

#include "fwddec.hpp"

namespace rtrp
{
	template<typename T>
	struct impl::Result
	{
	private:
		T m_result;
		bool m_error;

	public:
		Result(const T& result, bool isError = false)
			: m_result(result), m_error(isError)
		{}

		Result(bool isError = true)
			: m_error(isError)
		{}

		T& unwrap()
		{
			if (m_error)
				throw std::runtime_error("Tried unwrapping an erroneous Result<T>!");

			return m_result;
		}

		bool isError() const { return m_error; }
	};
}
