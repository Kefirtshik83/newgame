#include"Bowl.h"
const int Bowl:: radius = 10;
Bowl::Bowl(sf::Vector2f pos,  sf::Vector2f speed, int radius): speed(speed)
{
	bowl_shape.setRadius(radius);

	bowl_shape.setFillColor(sf::Color::Blue);

	bowl_shape.setPosition(pos);

}
Bowl :: Bowl()
{
	double x((double)(Field::d + (double)2 * radius + rand()% (Field::w - 4 * radius + 1)));
	double y((double)(Field::score_field + Field::d + (double)2 * radius + rand()% (Field::h - 4 * radius + 1)));
	bowl_shape.setOrigin(radius, radius);
	speed = sf::Vector2f(rand() % 100*pow(-1, rand()%2), rand() % 100*pow(-1, rand()%2));
	bowl_shape.setRadius(radius);
	bowl_shape.setFillColor(sf::Color::Blue);
	bowl_shape.setPosition(sf::Vector2f(x, y));
}

sf::Vector2f Bowl::get_position() const{ return bowl_shape.getPosition();}
sf::Vector2f Bowl::get_speed() const{return speed;}
void Bowl::set_position(sf::Vector2f pos){bowl_shape.setPosition(pos);}
void Bowl::set_speed(sf::Vector2f sp){speed = sp;}
void Bowl::move(sf::Vector2f delta){bowl_shape.move(delta);}
int Bowl::get_size() const { return radius; }
void Bowl::draw_bowl(sf::RenderWindow& window) const{window.draw(bowl_shape);}
double Bowl::abs_speed() const
{
	return sqrt(speed.x * speed.x + speed.y * speed.y);
}