#pragma once

#include "rpEntity.hpp"
#include "rpInputs.hpp"

namespace rp
{
	class Player : public Entity
	{
	public:
		     Player(const Vec2& position);
		void update(const Inputs& inputs);
	};
}