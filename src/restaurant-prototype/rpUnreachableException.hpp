#pragma once

#include <stdexcept>
#include "tfString.hpp"

namespace rp
{
	class UnreachableException : public std::runtime_error
	{
	public:
		UnreachableException(const tf::String& what) :
			std::runtime_error("UnreachableException: " + what)
		{
		}
	};
}