#pragma once

#include "rpCustomerType.hpp"
#include "rpEntity.hpp"

namespace rp
{
	class Seat;

	class Customer : public Entity
	{
	public:
		                    Customer(const Vec2& position);
		CustomerType        getType() const;
		void                serve();
		void                dispatchToSeat(Seat* const seat);

	private:
		static CustomerType generateRandomType();

	private:
		const CustomerType  m_type;
	};
}