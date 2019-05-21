#pragma once
#include <SFML/Graphics.hpp>
#include "Field.h"
class Bowl
{
private:
	int radius;
	double x, y;

	double vx, vy;
	sf::CircleShape bowl_shape;
	sf::Image image_s;
	sf::Texture texture_s;
public:
	Bowl();
	Bowl(int x, int y, int vx, int vy, int radius = 10);
	int get_size() const;
	double get_x() const;
	double get_y() const;
	double get_vx() const;
	double get_vy() const;
	void set_x(double x_);
	void set_y(double y_);
	void set_vx(double vx_);
	void set_vy(double vy_);
	void draw_bowl(sf::RenderWindow& window) const;

};