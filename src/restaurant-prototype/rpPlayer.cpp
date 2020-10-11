#include "rpPlayer.hpp"

rp::Player::Player(const Vec2& position) :
	Entity(position, Character::Diamond, ColorPair(Color::White, Color::Black))
{
}

void rp::Player::update(const Inputs& inputs)
{
	if (inputs.upPressed()   ) { move(Direction::Up   ); }
	if (inputs.downPressed() ) { move(Direction::Down ); }
	if (inputs.leftPressed() ) { move(Direction::Left ); }
	if (inputs.rightPressed()) { move(Direction::Right); }
}