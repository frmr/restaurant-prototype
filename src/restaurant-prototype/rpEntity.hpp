#pragma once

#include "rpEntity.hpp"
#include "rpColorPair.hpp"
#include "rpVec2.hpp"
#include "rpDirection.hpp"
#include "rpCharacter.hpp"

namespace rp
{
	class Entity
	{
	public:
		           Entity(const Vec2& position, const Character character, const ColorPair& color);
		
	public:
		void       draw(const Vec2& offset) const;

	protected:
		void       move(const Direction direction);

	private:
		static int characterToNcursesCharacter(const Character character);

	private:
		Vec2       m_position;
		int        m_character;
		ColorPair  m_color;
	};
}