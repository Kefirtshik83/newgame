#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
#include <cmath>

class Bowl
{
private:

	sf::Vector2f speed;
	sf::CircleShape bowl_shape;
	int radius;
public:
	//const static int radius;
	Bowl();
	Bowl(sf::Vector2f pos, sf::Vector2f speed, int radius = 10);
	int get_size() const;
	sf::Vector2f get_position() const;
	sf::Vector2f get_speed() const;
	float abs_speed() const;
	float get_radius() const;
	void set_radius(float x);
	void set_color(int r, int g, int b);
	void set_speed(sf::Vector2f sp);
	void set_position(sf::Vector2f pos);
	void move(sf::Vector2f delta);
	void draw_bowl(sf::RenderWindow& window) const;

};