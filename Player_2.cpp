#include "Player_2.h"
void Player2::control() 
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) { if (player_shape.getPosition().y - (Field::score_field + Field::d + (Field::h - Field::hole) / 2) > Field::d / 2 + player_shape.getRadius()) y_up(-5); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) { if (-player_shape.getPosition().y + (Field::score_field + Field::hole + Field::d + (Field::h - Field::hole) / 2) > Field::d / 2 + player_shape.getRadius()) y_up(5); }
}

Player2::Player2():Player1(2)
{

}