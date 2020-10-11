#include "rpSeat.hpp"
#include "rpCustomer.hpp"
#include "rpSimulation.hpp"
#include <stdexcept>

rp::Seat::Seat(const Vec2& position, Simulation& simulation) :
	Entity(position, Character::Dot, ColorPair(Color::White, Color::Black)),
	m_simulation(simulation)
{
}

void rp::Seat::addNeighbor(Seat* const neighbor)
{
	if (neighbor == nullptr)
	{
		throw std::logic_error("Tried to add nullptr neighbor to seat");
	}
	else
	{
		m_neighbors.push_back(neighbor);
	}
}

void rp::Seat::fill()
{
	if (m_state == SeatState::Free)
	{
		m_simulation.dispatchCustomerToSeat(this);

		m_state = SeatState::WaitingForCustomer;
	}
	else
	{
		throw std::logic_error("Tried to fill seat that isn't free");
	}
}

rp::ChainCount rp::Seat::serve()
{
	if (m_state == SeatState::Filled)
	{
		if (m_customer)
		{
			const CustomerType customerType = m_customer->getType();
			ChainCount         chain        = 1;

			serveCustomer();

			for (const auto neighbor : m_neighbors)
			{
				if (neighbor)
				{
					chain += neighbor->chain(customerType);
				}
				else
				{
					throw std::logic_error("Seat neighbor is nullptr");
				}
			}

			return chain;
		}
		else
		{
			throw std::logic_error("Seat filled but customer is nullptr");
		}
	}
	else
	{
		throw std::logic_error("Tried to serve a seat without a customer");
	}
}

void rp::Seat::assignCustomer(Customer* const customer)
{
	if (m_customer)
	{
		throw std::logic_error("Cannot assign customer to seat because it already has one");
	}
	else if (m_state == SeatState::WaitingForCustomer)
	{
		m_customer = customer;
	}
	else
	{
		throw std::logic_error("Cannot assign customer to seat because it's not waiting for one");
	}
}

rp::SeatState rp::Seat::getState() const
{
	return m_state;
}

rp::ChainCount rp::Seat::chain(const CustomerType customerType)
{
	if (m_state == SeatState::Filled)
	{
		if (!m_customer)
		{
			throw std::logic_error("Seat filled but customer is nullptr");
		}
		else if (m_customer->getType() == customerType)
		{
			serveCustomer();

			ChainCount chain = 1;

			for (const auto neighbor : m_neighbors)
			{
				chain += neighbor->chain(customerType);
			}

			return chain;
		}
	}

	return 0;
}

void rp::Seat::serveCustomer()
{
	if (m_customer)
	{
		m_customer->serve();
		m_customer = nullptr;
		m_state = SeatState::Free;
	}
	else
	{
		throw std::logic_error("Seat cannot serve nullptr customer");
	}
}
