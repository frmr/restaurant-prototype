#pragma once

#include "rpColor.hpp"

namespace rp
{
	class ColorPair
	{
	public:
		void             use() const;
		void             setGlobally() const;

		static ColorPair white;
		static ColorPair red;
		static ColorPair blue;
		static ColorPair yellow;
		static ColorPair green;

	private:
		                 ColorPair(const Color foreground, const Color background);

		static int       generateHandle(const Color foreground, const Color background);
		static int       colorToNcursesColor(const Color color);

	private:
		int              m_handle;
	};
}