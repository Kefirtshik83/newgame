#include "Game.h"

Game::Game() : field(), pl1(1)
{
	b_radius = bowls[0].get_radius();
}

Field Game::get_field() const { return field; }
Player1 Game::get_pl1() const { return pl1; }

void Game:: bowls_collision(Bowl& b1, Bowl& b2)
{
	//std::cout << "kek" << std::endl; i-1, j - 2
//std::cout <<"begin" << std::endl << "vx1 = " << w[0].vx << " vy1 = " << w[0].vy << std::endl;
//std::cout << "vx2 = " << w[1].vx<< " vy2 = " << w[1].vy << std::endl;
	double alpha = (b2.get_position().y - b1.get_position().y) / (b2.get_position().x - b1.get_position().x); //преобразование скоростей при соударении
	alpha = atan(alpha);
	double vx2 = b2.get_speed().x * cos(alpha) + b2.get_speed().y * sin(alpha);
	double vy2 = b2.get_speed().x * -sin(alpha) + b2.get_speed().y * cos(alpha);
	double vx1 = b1.get_speed().x * cos(alpha) + b1.get_speed().y * sin(alpha);
	double vy1 = b1.get_speed().x * -sin(alpha) + b1.get_speed().y * cos(alpha);
	double xax = vx1;
	vx1 = vx2;
	vx2 = xax;
	b2.set_speed(sf::Vector2f(vx2 * cos(-alpha) + vy2 * sin(-alpha), vx2 * -sin(-alpha) + vy2 * cos(-alpha)));
	//bowls[j].vx = vx2 * cos(-alpha) + vy2 * sin(-alpha); //vx2 = w[j].vx * cos(-alpha) - w[j].vx * sin(-alpha); 
	//bowls[j].vy = vx2 * -sin(-alpha) + vy2 * cos(-alpha);//vy2 = w[j].vx * sin(-alpha) + w[j].vy * cos(-alpha);
	b1.set_speed(sf::Vector2f(vx1 * cos(-alpha) + vy1 * sin(-alpha), vx1 * -sin(-alpha) + vy1 * cos(-alpha)));
	//bowls[i].vx = vx1 * cos(-alpha) + vy1 * sin(-alpha);//vx1 = w[i].vx * cos(-alpha) - w[i].vx * sin(-alpha);
	//bowls[i].vy = vx1 * -sin(-alpha) + vy1 * cos(-alpha);//vy1 = w[i].vx * sin(-alpha) + w[i].vy * cos(-alpha);
	if (dist(b1.get_position(), b2.get_position()) < 2 * b_radius - 1)
	{
		sf::Vector2f middle = (b1.get_position() + b2.get_position()) * 0.5f;
		b2.set_position(middle + (b2.get_position() - middle) * (float)b_radius / (abs(b2.get_position() - middle)));
		b1.set_position(middle + (b1.get_position() - middle) * (float)b_radius / (abs(b1.get_position() - middle) ));
		std::cout << dist(b1.get_position(), b2.get_position()) << std::endl;
	}
}
void Game::wall_collision(Bowl& b)
{
	if ((b.get_position().x - b_radius < Field::d || b.get_position().x + b_radius > Field::d + Field::w) && !(b.get_position().y > (Field::h - Field::hole) / 2 + Field::d + Field::score_field && b.get_position().y < (Field::h - Field::hole) / 2 + Field::d + Field::score_field + Field::hole))
	{
		b.set_speed(sf::Vector2f(-(1 + 0.1 * (b.abs_speed() < 1000)) * b.get_speed().x, b.get_speed().y));
		if(b.get_position().x - b_radius < Field::d - 1)
			b.set_position(sf::Vector2f(Field::d + b_radius, b.get_position().y));
		if(b.get_position().x + b_radius > Field::d + Field::w + 1)
			b.set_position(sf::Vector2f(Field::d - b_radius + Field::w, b.get_position().y));
	}
	if (b.get_position().y - b_radius < Field::d + Field::score_field || b.get_position().y + b_radius > Field::d + Field::h + Field::score_field)
	{
		b.set_speed(sf::Vector2f(b.get_speed().x, -(1 + 0.1 * (b.abs_speed() < 1000)) * b.get_speed().y));
		if(b.get_position().y - b_radius < Field::d + Field::score_field-1)
			b.set_position(sf::Vector2f(b.get_position().x, Field::d + Field::score_field + b_radius));
		if(b.get_position().y + b_radius > Field::d + Field::h + Field::score_field+1)
			b.set_position(sf::Vector2f(b.get_position().x, Field::d + Field::h + Field::score_field - b_radius));
	}
	if (b.get_position().x < -b_radius || b.get_position().x > 2 * Field::d + Field::w + b_radius)
	{
		b.set_speed(sf::Vector2f(0, 0));
		b.set_position(sf::Vector2f(-50, Field::score_field+Field::d+Field::h/2));
	}
}


void Game::tick()
{
	//соударения со стенами
	for (int i = 0; i < n; ++i)
	{
		wall_collision(bowls[i]);
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (dist(bowls[i].get_position(), bowls[j].get_position()) < 2*b_radius)
			{
				bowls_collision(bowls[i], bowls[j]);
			}


		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (dist(field.get_position(j), bowls[i].get_position()) < 2 * b_radius)
			{
				sf::Vector2f norm = normal(sf::Vector2f(field.get_position(j).x - bowls[i].get_position().x, field.get_position(j).y - bowls[i].get_position().y));
				sf::Vector2f v_norm = proection_b_on_a(norm, bowls[i].get_speed());
				sf::Vector2f v_prod = bowls[i].get_speed() - v_norm;
				bowls[i].set_speed(bowls[i].get_speed() - (float)2 * v_prod);
			}
		}
	}
	
	
}

void Game::game_draw(sf::RenderWindow& window)
{
	sf::Clock clock;
	std::cout << bowls[0].get_position().x <<" "<< bowls[0].get_position().y << std::endl;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		//bowls[1].set_x(Field::w / 2);
		//bowls[1].set_y(Field::h / 2);

		get_field().draw_field(window);
		pl1.draw_player(window);
		pl2.draw_player(window);
		pl1.control();
		pl2.control();
		//bowls[1].draw_bowl(window);
		const float dt = clock.restart().asSeconds();
		//std::cout << dt << std::endl;
		for (int i = 0; i < n; ++i)
		{
			
			bowls[i].draw_bowl(window);
			bowls[i].move(bowls[i].get_speed() * dt);
			tick();
		}
		window.display();
	}
}