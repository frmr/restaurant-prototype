#pragma once

namespace rp
{
	class Inputs
	{
	public:
		     Inputs(const bool up, const bool down, const bool left, const bool right);

		bool upPressed() const;
		bool downPressed() const;
		bool leftPressed() const;
		bool rightPressed() const;

	private:
		const bool m_up;
		const bool m_down;
		const bool m_left;
		const bool m_right;
	};
}