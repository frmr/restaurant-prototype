#include "rpApp.hpp"
#include "rpColorPair.hpp"
#include "rpVec2.hpp"
#include "rpEntity.hpp"
#include "rpPlayer.hpp"
#include "rpBufferedInput.hpp"
#include "rpSimulation.hpp"
#include "tfTimer.hpp"
#include "tfExternalLibraryException.hpp"
#include <iostream>
#include <thread>
#include <chrono>

rp::App::App()
{
	prepareWindow();
}

rp::App::~App()
{
	endWindow();
}

void rp::App::loop()
{
	bool          running = true;
	Vec2          offset(0, 0);
	BufferedInput inputs;
	Simulation    simulation;

	while (running)
	{
		const tf::Timer frameTimer;

		//Vec2 terminalSize;
		//getmaxyx(m_window, terminalSize.y, terminalSize.x);

		erase();

		simulation.draw(Vec2(0, 0));
		inputs.update();
		simulation.update(inputs.popInputs());
		

		refresh();

		constexpr double targetFrameTime = 16;

		std::this_thread::sleep_for(std::chrono::milliseconds(int(std::max(targetFrameTime - frameTimer.getMilliseconds(), 0.0))));
	}
}

void rp::App::cleanup()
{
	endWindow();
}

void rp::App::prepareWindow()
{
	m_window = initscr();

	start_color();
	curs_set(0);

	if (!has_colors())
	{
		throw tf::ExternalLibraryException("Terminal must support colors");
	}

	cbreak();
	noecho();
	nodelay(m_window, true);
	keypad(m_window, true);
}

void rp::App::endWindow() const
{
	endwin();
}