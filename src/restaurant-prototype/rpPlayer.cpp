#include "rpPlayer.hpp"

rp::Player::Player(const Vec2& position, const std::vector<Vec2>& validPositions) :
	Entity(position, Character::Diamond, ColorPair::white),
	m_validPositions(validPositions)
{
}

void rp::Player::update(const Inputs& inputs)
{
	if (inputs.upPressed()   ) { move(Direction::Up   ); }
	if (inputs.downPressed() ) { move(Direction::Down ); }
	if (inputs.leftPressed() ) { move(Direction::Left ); }
	if (inputs.rightPressed()) { move(Direction::Right); }
}