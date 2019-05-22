#pragma once
#include "Field.h"
class Player1
{
protected:
	float len;
	sf::RectangleShape player_shape;
	Player1();
	virtual void control();
public:
	float get_len() const;
	float get_y() const;
	int get_d() const;
	void y_up(int x);
};