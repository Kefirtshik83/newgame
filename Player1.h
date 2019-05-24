#pragma once
#include "Field.h"

class Player1
{
protected:
	sf::CircleShape player_shape;
	int score = 0;

public:

	int get_score() const;
	void score_up();
	float get_radius() const;
	float get_y() const;
	sf::Vector2f get_position() const;
	void y_up(float x);
	virtual void control();
	void set_y(float y);
	void set_start_position(int x);
	void draw_player(sf::RenderWindow& window) const;
	Player1(int x);
};