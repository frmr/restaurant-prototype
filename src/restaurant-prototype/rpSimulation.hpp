#pragma once

#include "rpPlayer.hpp"
#include "rpCustomerQueue.hpp"
#include "rpTable.hpp"
#include <vector>

namespace rp
{
	class Seat;

	class Simulation
	{
	public:
		                         Simulation();

		void                     draw(const Vec2& offset) const;
		void                     update(const Inputs& inputs);
		void                     dispatchCustomerToSeat(Seat* const seat);

	private:
		static std::vector<Vec2> getTablePositions();
		static std::vector<Vec2> getValidPlayerPositions();

	public:
		Player                   m_player;
		CustomerQueue            m_customerQueue;
		std::vector<Customer>    m_customers;
		std::vector<Table>       m_tables;
	};
}