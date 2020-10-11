#include "rpInputs.hpp"

rp::Inputs::Inputs(const bool up, const bool down, const bool left, const bool right) :
	m_up(up),
	m_down(down),
	m_left(left),
	m_right(right)
{
}

bool rp::Inputs::upPressed() const
{
	return m_up;
}

bool rp::Inputs::downPressed() const
{
	return m_down;
}

bool rp::Inputs::leftPressed() const
{
	return m_left;
}

bool rp::Inputs::rightPressed() const
{
	return m_right;
}