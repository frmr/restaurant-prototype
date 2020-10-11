#pragma once

namespace rp
{
	class Vec2
	{
	public:
		      Vec2();
		      Vec2(const int x, const int y);

		Vec2& operator+=(const Vec2& rhs);
		Vec2  operator/(const int rhs) const;

		int   x;
		int   y;
	};
}