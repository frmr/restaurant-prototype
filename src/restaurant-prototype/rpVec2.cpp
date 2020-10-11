#include "rpVec2.hpp"

rp::Vec2::Vec2() :
	x(0),
	y(0)
{
}

rp::Vec2::Vec2(const int x, const int y) :
	x(x),
	y(y)
{

}

rp::Vec2& rp::Vec2::operator+=(const Vec2& rhs)
{
	x += rhs.x;
	y += rhs.y;

	return *this;
}

rp::Vec2 rp::Vec2::operator/(const int rhs) const
{
	return Vec2(
		x / rhs,
		y / rhs
	);
}