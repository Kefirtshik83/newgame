#pragma once
#include"SFML/Graphics.hpp"
class Field
{
public:
	Field();
	int get_scale() const;
	int get_d() const;
	int get_w() const;
	int get_score_field() const;
	int get_h() const;
	int get_n() const;
	int get_m() const;
	int get_hole() const;
	sf::RectangleShape get_field_shape() const;
	sf::RectangleShape get_score_field_shape() const;
	void draw_field(sf::RenderWindow& window) const;
	const static int d;
	const static int w;
	const static int h;
	const static int score_field;
	const static int hole;
	sf::Vector2f get_position(int i) const;
	//int score = 0;
private:
	sf::RectangleShape field_shape;
	sf::RectangleShape score_field_shape;
	sf::RectangleShape hole1_shape;
	sf::RectangleShape hole2_shape;
	sf::CircleShape circles[4];
};

