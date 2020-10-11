#pragma once

#include "rpPlayer.hpp"

namespace rp
{
	class Simulation
	{
	public:
		       Simulation();

		void   draw(const Vec2& offset) const;
		void   update(const Inputs& inputs);

	public:
		Player m_player;
	};
}