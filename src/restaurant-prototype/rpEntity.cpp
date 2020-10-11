#include "rpEntity.hpp"
#include "rpUnreachableException.hpp"
#include <ncurses.h>

rp::Entity::Entity(const Vec2& position, const Character character, const ColorPair& color) :
	m_position(position),
	m_character(characterToNcursesCharacter(character)),
	m_color(color)
{
}

void rp::Entity::draw(const Vec2& offset) const
{
	m_color.use();
	mvaddch(offset.y + m_position.y, offset.x + m_position.x, m_character);
}

void rp::Entity::move(const Direction direction)
{
	switch (direction)
	{
	case Direction::Up:    --m_position.y; break;
	case Direction::Down:  ++m_position.y; break;
	case Direction::Left:  --m_position.x; break;
	case Direction::Right: ++m_position.x; break;
	default:
		throw UnreachableException("Invalid direction");
	}
}

int rp::Entity::characterToNcursesCharacter(const Character character)
{
	switch (character)
	{
	case Character::Diamond: return ACS_DIAMOND;
	default:
		throw UnreachableException("Invalid character");
	}
}