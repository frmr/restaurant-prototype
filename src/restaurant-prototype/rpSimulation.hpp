#pragma once

#include "rpPlayer.hpp"
#include "rpCustomerQueue.hpp"

namespace rp
{
	class Seat;

	class Simulation
	{
	public:
		                      Simulation();

		void                  draw(const Vec2& offset) const;
		void                  update(const Inputs& inputs);
		void                  dispatchCustomerToSeat(Seat* const seat);

	public:
		Player                m_player;
		CustomerQueue         m_customerQueue;
		std::vector<Customer> m_customers;
	};
}