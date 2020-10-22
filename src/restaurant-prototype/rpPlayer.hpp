#pragma once

#include "rpEntity.hpp"
#include "rpInputs.hpp"
#include <vector>

namespace rp
{
	class Player : public Entity
	{
	public:
		                        Player(const Vec2& position, const std::vector<Vec2>& validPositions);
		void                    update(const Inputs& inputs);

	private:
		const std::vector<Vec2> m_validPositions;
	};
}