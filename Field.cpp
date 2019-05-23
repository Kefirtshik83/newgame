#include "Field.h"
const int Field::d = 20;
const int Field::w = 1200;
const int Field::h = 720;
const int Field::score_field = 40;
const int Field::hole = h/2;
Field::Field()
{
	field_shape.setSize(sf::Vector2f(w, h));
	field_shape.setPosition(sf::Vector2f(d, d + score_field));
	field_shape.setFillColor(sf::Color::Red);
	field_shape.setOutlineThickness(d);
	field_shape.setOutlineColor(sf::Color(250, 150, 100));
	score_field_shape.setSize(sf::Vector2f(w+2*d, score_field));
	score_field_shape.setFillColor(sf::Color(250, 150, 100));
	hole1_shape.setSize(sf::Vector2f(d, hole));
	hole1_shape.setFillColor(sf::Color::Black);
	hole1_shape.setPosition(sf::Vector2f(0, (h-hole)/2 + d+score_field));
	hole2_shape.setSize(sf::Vector2f(d, hole));
	hole2_shape.setFillColor(sf::Color::Black);
	hole2_shape.setPosition(sf::Vector2f(d+w, (h-hole)/2 + d+score_field));
	for (int i = 0; i < 4; ++i)
	{
		circles[i].setRadius(d / 2);
		circles[i].setFillColor(sf::Color(250, 150, 100));
		circles[i].setOrigin(circles[i].getRadius(), circles[i].getRadius());
	}

	circles[0].setPosition(sf::Vector2f(d/2,d +  (h-hole)/2  + score_field));
	circles[1].setPosition(sf::Vector2f(d/2 , (h - hole)/2 + hole + d  + score_field));
	circles[2].setPosition(sf::Vector2f(d + d/2 + w, (h-hole)/2 + d  + score_field));
	circles[3].setPosition(sf::Vector2f(d + d/2 + w, (h - hole) / 2 + hole + d + score_field));
}

int Field::get_d() const{return d;}
int Field::get_w() const{return w;}
int Field::get_score_field() const{return score_field;}

int Field::get_h() const{return h;}
int Field::get_hole() const { return hole; }
sf::RectangleShape Field::get_field_shape() const { return field_shape; }
sf::RectangleShape Field:: get_score_field_shape() const { return score_field_shape; }
sf::Vector2f Field:: get_position(int i) const { return circles[i].getPosition(); }
sf::CircleShape Field::get_circle(int i) const { return circles[i]; }
void Field::draw_field(sf::RenderWindow& window) const
{
	window.draw(field_shape);
	window.draw(score_field_shape);
	window.draw(hole1_shape);
	window.draw(hole2_shape);
	for (int i = 0; i < 4; ++i)
	{
		window.draw(circles[i]);
	}
}
