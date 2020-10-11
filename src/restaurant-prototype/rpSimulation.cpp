#include "rpSimulation.hpp"
#include "rpCustomer.hpp"

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

void rp::Simulation::dispatchCustomerToSeat(Seat* const seat)
{
	m_customers.push_back(m_customerQueue.pop());
	m_customers.back().dispatchToSeat(seat);
}
