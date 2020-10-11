#include "rpSimulation.hpp"

rp::Simulation::Simulation() :
	m_player(Vec2(0, 0))
{

}

void rp::Simulation::draw(const Vec2& offset) const
{
	m_player.draw(offset);
}

void rp::Simulation::update(const Inputs& inputs)
{
	m_player.update(inputs);
}