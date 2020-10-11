#include "rpCustomerQueue.hpp"
#include <stdexcept>

rp::CustomerQueue::CustomerQueue()
{
	fill();
}

rp::Customer rp::CustomerQueue::pop()
{
	if (m_queue.empty())
	{
		throw std::logic_error("Queue is empty");
	}
	else
	{
		const Customer front = m_queue.front();

		m_queue.pop();
		fill();

		return front;
	}
}

void rp::CustomerQueue::fill()
{
	constexpr size_t maxQueueSize = 4;

	while (m_queue.size() < maxQueueSize)
	{
		m_queue.push(Customer(Vec2(0, 0)));
	}
}
