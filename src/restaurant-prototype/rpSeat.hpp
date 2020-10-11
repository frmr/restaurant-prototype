#pragma once

#include "rpChainCount.hpp"
#include "rpCustomerType.hpp"
#include "rpSeatState.hpp"
#include "rpEntity.hpp"
#include <vector>

namespace rp
{
	class Customer;
	class Simulation;

	class Seat : public Entity
	{
	public:
		                   Seat(const Vec2& position, Simulation& simulation);
		
		void               addNeighbor(Seat* const neighbor);
		void               fill();
		ChainCount         serve();
		void               assignCustomer(Customer* const customer);
		SeatState          getState() const;
		
	private:
		ChainCount         chain(const CustomerType customerType);
		void               serveCustomer();

	private:
		Simulation&        m_simulation;
		std::vector<Seat*> m_neighbors;
		Customer*          m_customer;
		SeatState          m_state;
	};
}