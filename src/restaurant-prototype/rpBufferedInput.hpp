#pragma once

#include "rpInputs.hpp"
#include <ncurses.h>

namespace rp
{
	class BufferedInput
	{
	public:
		       BufferedInput();

		Inputs popInputs();
		void   update();

	private:
		int    m_up;
		int    m_down;
		int    m_left;
		int    m_right;
	};
}