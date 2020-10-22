#pragma once

#include <list>
#include "rpCustomer.hpp"

namespace rp
{
	class CustomerQueue
	{
	public:
		                    CustomerQueue();
		Customer            pop();
		void                draw(const Vec2& offset) const;

	private:
		void                shift();
		void                fill();

	private:
		std::list<Customer> m_queue;
	};
}