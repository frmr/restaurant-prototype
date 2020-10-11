#pragma once

#include <queue>
#include "rpCustomer.hpp"

namespace rp
{
	class CustomerQueue
	{
	public:
		                     CustomerQueue();
		Customer             pop();

	private:
		void                 fill();

	private:
		std::queue<Customer> m_queue;
	};
}