#include "Player1.h"
float Player1::get_radius() const { return player_shape.getRadius(); }
float Player1::get_y() const { return player_shape.getPosition().y; }
sf::Vector2f Player1:: get_position() const { return player_shape.getPosition(); }
void Player1::y_up(float x) { player_shape.setPosition(sf::Vector2f(player_shape.getPosition().x, player_shape.getPosition().y + x)); }
void Player1::control()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { if(player_shape.getPosition().y - (Field::score_field + Field::d + (Field::h - Field::hole)/2) > Field::d/2 + player_shape.getRadius()) y_up(-5); }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {if(-player_shape.getPosition().y + (Field::score_field + Field::hole + Field::d + (Field::h - Field::hole) / 2) > Field::d / 2 + player_shape.getRadius()) y_up(5); }
}
void Player1::set_y(float y) { player_shape.setPosition(sf::Vector2f(Field::d / 2, y)); }
void Player1:: set_start_position(int x) { player_shape.setPosition(sf::Vector2f(Field::d / 2 + (x-1)*(Field::w+ Field::d), Field::score_field + Field::d + Field::h / 2)); }
void Player1:: draw_player(sf::RenderWindow& window) const { window.draw(player_shape); }
Player1::Player1(int x)
{
	player_shape.setRadius(40);
	player_shape.setOrigin(player_shape.getRadius(), player_shape.getRadius());
	set_start_position(x);
	player_shape.setFillColor(sf::Color::Blue);
}
