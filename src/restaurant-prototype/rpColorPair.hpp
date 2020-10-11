#pragma once

#include "rpColor.hpp"

namespace rp
{
	class ColorPair
	{
	public:
		           ColorPair(const Color foreground, const Color background);

		void       use() const;
		void       setGlobally() const;

	private:
		static int generateHandle(const Color foreground, const Color background);
		static int colorToNcursesColor(const Color color);

	private:
		const int  m_handle;
	};
}