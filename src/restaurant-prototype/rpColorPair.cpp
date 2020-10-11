#include "rpColorPair.hpp"
#include "rpExternalLibraryException.hpp"
#include <ncurses.h>
#include <iostream>

rp::ColorPair::ColorPair(const Color foreground, const Color background) :
	m_handle(generateHandle(foreground, background))
{
}

void rp::ColorPair::use() const
{
	attron(COLOR_PAIR(m_handle));
}

void rp::ColorPair::setGlobally() const
{
	color_set(m_handle, nullptr);
}

int rp::ColorPair::generateHandle(const Color foreground, const Color background)
{
	static int nextHandle = 1;
	const int  handle     = nextHandle++;
	const int  error      = init_pair(handle, colorToNcursesColor(foreground), colorToNcursesColor(background));

	if (error)
	{
		throw ExternalLibraryException(tf::String("ncurses init_pair failed with error code {}. Foreground is {}, background is {}", { std::to_string(error), std::to_string(colorToNcursesColor(foreground)), std::to_string(colorToNcursesColor(background)) }));
	}

	return handle;
}

int rp::ColorPair::colorToNcursesColor(const Color color)
{
	switch (color)
	{
		case Color::Black:   return COLOR_BLACK;
		case Color::Red:     return COLOR_RED;
		case Color::Green:   return COLOR_GREEN;
		case Color::Yellow:  return COLOR_YELLOW;
		case Color::Blue:    return COLOR_BLUE;
		case Color::Magenta: return COLOR_MAGENTA;
		case Color::Cyan:    return COLOR_CYAN;
		case Color::White:   return COLOR_WHITE;
		default:             return COLOR_WHITE;
	}
}
