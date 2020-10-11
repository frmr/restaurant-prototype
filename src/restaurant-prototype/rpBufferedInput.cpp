#include "rpBufferedInput.hpp"

rp::BufferedInput::BufferedInput() :
	m_up(0),
	m_down(0),
	m_left(0),
	m_right(0)
{

}

rp::Inputs rp::BufferedInput::popInputs()
{
	const Inputs inputs(m_up > 0, m_down > 0, m_left > 0, m_right > 0);

	if (inputs.upPressed()   ) { --m_up;    }
	if (inputs.downPressed() ) { --m_down;  }
	if (inputs.leftPressed() ) { --m_left;  }
	if (inputs.rightPressed()) { --m_right; }

	return inputs;
}

#include <stdlib.h>

void rp::BufferedInput::update()
{
	int ch;

	while ((ch = getch()) != ERR)
	{
		switch (ch)
		{
		case KEY_UP:    ++m_up;    break;
		case KEY_DOWN:  ++m_down;  break;
		case KEY_LEFT:  ++m_left;  break;
		case KEY_RIGHT: ++m_right; break;
		}
	}
}