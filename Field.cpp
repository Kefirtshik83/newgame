#include "Field.h"
int Field::d = 20;
int Field::w = 1200;
int Field::h = 720;
int Field::score_field = 40;
int Field::hole = 240;
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
	hole1_shape.setPosition(sf::Vector2f(0, h / 3 + d+score_field));
	hole2_shape.setSize(sf::Vector2f(d, hole));
	hole2_shape.setFillColor(sf::Color::Black);
	hole2_shape.setPosition(sf::Vector2f(d+w, h / 3 + d+score_field));
	circle1.setRadius(d / 2);
	circle2.setRadius(d / 2);
	circle3.setRadius(d / 2);
	circle4.setRadius(d / 2);
	circle1.setFillColor(sf::Color(250, 150, 100));
	circle2.setFillColor(sf::Color(250, 150, 100));
	circle3.setFillColor(sf::Color(250, 150, 100));
	circle4.setFillColor(sf::Color(250, 150, 100));
	circle1.setPosition(sf::Vector2f(0, h / 3 + d/2 + score_field));
	circle2.setPosition(sf::Vector2f(0 , 2*h / 3 + d/2 + score_field));
	circle3.setPosition(sf::Vector2f(d + w, h / 3 + d/2 + score_field));
	circle4.setPosition(sf::Vector2f(d+w, 2*h / 3 + d/2 + score_field));
}

int Field::get_d() const{return d;}
int Field::get_w() const{return w;}
int Field::get_score_field() const{return score_field;}

int Field::get_h() const{return h;}
int Field::get_hole() const { return hole; }
sf::RectangleShape Field::get_field_shape() const { return field_shape; }
sf::RectangleShape Field:: get_score_field_shape() const { return score_field_shape; }
void Field::draw_field(sf::RenderWindow& window) const
{
	window.draw(field_shape);
	window.draw(score_field_shape);
	window.draw(hole1_shape);
	window.draw(hole2_shape);
	window.draw(circle1);
	window.draw(circle2);
	window.draw(circle3);
	window.draw(circle4);
}
