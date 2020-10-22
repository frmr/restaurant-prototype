#include "rpCustomerQueue.hpp"
#include <stdexcept>
#include <array>

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

		m_queue.pop_front();
		shift();
		fill();

		return front;
	}
}

void rp::CustomerQueue::draw(const Vec2& offset) const
{
	for (const Customer& customer : m_queue)
	{
		customer.draw(offset);
	}
}

void rp::CustomerQueue::shift()
{
	for (Customer& customer : m_queue)
	{
		customer.move(Direction::Down);
	}
}

void rp::CustomerQueue::fill()
{
	constexpr size_t                            maxQueueSize = 3;
	static const std::array<Vec2, maxQueueSize> positions{ Vec2(4, 2), Vec2(4, 1), Vec2(4, 0)};

	while (m_queue.size() < maxQueueSize)
	{
		try
		{
			m_queue.emplace_back(positions.at(m_queue.size()));
		}
		catch (const std::out_of_range& e)
		{
			throw std::logic_error("Tried to access invalid queue customer position");
		}
		
	}
}
