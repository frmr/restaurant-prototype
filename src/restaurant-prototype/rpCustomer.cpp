#include "rpCustomer.hpp"
#include "tfRandomRange.hpp"
#include "tfUnreachableException.hpp"

rp::Customer::Customer(const Vec2& position) :
	Entity(position, Character::Circle, ColorPair::red),
	m_type(generateRandomType())
{
	switch (m_type)
	{
	case CustomerType::Red:    setColor(ColorPair::red);    break;
	case CustomerType::Blue:   setColor(ColorPair::blue);   break;
	case CustomerType::Yellow: setColor(ColorPair::yellow); break;
	case CustomerType::Green:  setColor(ColorPair::green);  break;
	default:
		throw tf::UnreachableException("Invalid customer type");
	}
}

rp::CustomerType rp::Customer::getType() const
{
	return m_type;
}

void rp::Customer::serve()
{
	// Start animation
}

void rp::Customer::dispatchToSeat(Seat* const seat)
{
}

rp::CustomerType rp::Customer::generateRandomType()
{
	static tf::RandomRange<unsigned int> generator(0, 3);

	switch (generator.get())
	{
	case 0: return CustomerType::Red;
	case 1: return CustomerType::Blue;
	case 2: return CustomerType::Yellow;
	case 3: return CustomerType::Green;
	default:
		throw tf::UnreachableException("Invalid int when generating customer type");
	}
}
