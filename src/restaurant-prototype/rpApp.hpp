#pragma once

#include <ncurses.h>

namespace rp
{
	class App
	{
	public:
		     App();
		     ~App();

		void loop();
		void cleanup();

	private:
		void prepareWindow();
		void endWindow() const;

	private:
		WINDOW* m_window;
	};
}