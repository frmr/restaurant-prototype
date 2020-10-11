#pragma once

#include <stdexcept>
#include "tfString.hpp"

namespace rp
{
	class ExternalLibraryException : public std::runtime_error
	{
	public:
		ExternalLibraryException(const tf::String& what) :
			std::runtime_error("ExternalLibraryException: " + what)
		{
		}
	};
}