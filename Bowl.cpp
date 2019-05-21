#include"Bowl.h"
Bowl::Bowl(int x, int y, int vx, int vy, int radius): x(x), y(y), vx(vx), vy(vy), radius(radius)
{
	bowl_shape.setRadius(radius);
	bowl_shape.setFillColor(sf::Color::Blue);
	bowl_shape.setPosition(sf::Vector2f(x, y));
}
Bowl :: Bowl():radius(50),  x((double)(Field::d + (double)2* radius + rand()%(Field::w - 6*radius +1))), y((double)(Field :: score_field + Field::d + (double)2* radius + rand()%(Field ::h - 6 * radius+1))),vx(rand()) ,vy(rand())
{
		bowl_shape.setRadius(radius);
		bowl_shape.setFillColor(sf::Color::Blue);
		bowl_shape.setPosition(sf::Vector2f(x, y));
}
int Bowl::get_size() const { return radius; }
double Bowl::get_x() const{ return x; }
double Bowl::get_y() const { return y;}
double Bowl::get_vx() const { return vx; }
double Bowl::get_vy() const { return vy; }
void Bowl::set_x(double x_){x = x_;}
void Bowl::set_y(double y_) { y = y_; }
void Bowl::set_vx(double vx_) { vx = vx_; }
void Bowl::set_vy(double vy_) { vy = vy_; }
void Bowl::draw_bowl(sf::RenderWindow& window) const
{
	window.draw(bowl_shape);
}