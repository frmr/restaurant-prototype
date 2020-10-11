#include <ncurses.h>
#include <signal.h>
#include <iostream>
#include "rpApp.hpp"
#include "tfString.hpp"

static rp::App app;

void signalHandler(int signum)
{
	app.cleanup();
	exit(signum);
}

int main()
{
	signal(SIGINT, signalHandler);

	try
	{
		app.loop();

		std::cout << "After loop" << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << tf::String("Caught exception: {}", { e.what() }) << std::endl;
	}
	catch (...)
	{
		std::cout << "Caught unknown exception" << std::endl;
	}

	return 0;
} 