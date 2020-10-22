#include "rpSimulation.hpp"
#include "rpCustomer.hpp"

rp::Simulation::Simulation() :
	m_player(Vec2(4, 7), getValidPlayerPositions())
{
	for (const Vec2& position : getTablePositions())
	{
		m_tables.emplace_back(position);
	}
}

void rp::Simulation::draw(const Vec2& offset) const
{
	m_player.draw(offset);
	m_customerQueue.draw(offset);

	for (const Table& table : m_tables)
	{
		table.draw(offset);
	}
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

std::vector<rp::Vec2> rp::Simulation::getTablePositions()
{
	return {
		Vec2(2, 5),
		Vec2(3, 5),
		Vec2(4, 5),
		Vec2(5, 5),
		Vec2(6, 5),
		Vec2(2, 6),
		Vec2(2, 7),
		Vec2(2, 8),
		Vec2(6, 6),
		Vec2(6, 7),
		Vec2(6, 8)
	};
}

std::vector<rp::Vec2> rp::Simulation::getValidPlayerPositions()
{
	return {
		Vec2(3, 6),
		Vec2(4, 6),
		Vec2(5, 6),
		Vec2(3, 7),
		Vec2(4, 7),
		Vec2(5, 7),
		Vec2(3, 8),
		Vec2(4, 8),
		Vec2(5, 8)
	};
}
