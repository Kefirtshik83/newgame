#include "Game.h"

Game::Game() : field()
{
	
}

Field Game::get_field() const { return field; }



void Game::tick()
{
	//соударения со стенами
	for (int i = 0; i < n; ++i)
	{
		if ((bowls[i].get_position().x - Bowl::radius < Field::d || bowls[i].get_position().x + Bowl::radius > Field::d + Field::w) && !(bowls[i].get_position().y > (Field::h - Field::h/3)/2+ Field::d + Field::score_field && bowls[i].get_position().y < (Field::h - Field::h / 3) / 2 + Field::d + Field::score_field + Field::h/3))
		{
			bowls[i].set_speed(sf::Vector2f(-(1+0.1*(bowls[i].abs_speed() < 1000))*bowls[i].get_speed().x, bowls[i].get_speed().y));
		}
		if (bowls[i].get_position().y - Bowl::radius < Field::d+ Field::score_field || bowls[i].get_position().y + Bowl::radius > Field::d + Field::h + Field::score_field)
		{
			bowls[i].set_speed(sf::Vector2f(bowls[i].get_speed().x, -(1 + 0.1 * (bowls[i].abs_speed() < 1000)) *bowls[i].get_speed().y));
		}
		if (bowls[i].get_position().x < -Bowl::radius || bowls[i].get_position().x > 2 * Field::d + Field::w + Bowl::radius)
		{
			bowls[i].set_speed(sf::Vector2f(0, 0));
			bowls[i].set_position(sf::Vector2f(-50, -50));
		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (dist(bowls[i].get_position(), bowls[j].get_position()) < 2*Bowl::radius)
			{
				//std::cout << "kek" << std::endl;
				//std::cout <<"begin" << std::endl << "vx1 = " << w[0].vx << " vy1 = " << w[0].vy << std::endl;
				//std::cout << "vx2 = " << w[1].vx<< " vy2 = " << w[1].vy << std::endl;
				double alpha = (bowls[j].get_position().y - bowls[i].get_position().y) / (bowls[j].get_position().x - bowls[i].get_position().x); //преобразование скоростей при соударении
				alpha = atan(alpha);
				double vx2 = bowls[j].get_speed().x * cos(alpha) + bowls[j].get_speed().y * sin(alpha);
				double vy2 = bowls[j].get_speed().x * -sin(alpha) + bowls[j].get_speed().y * cos(alpha);
				double vx1 = bowls[i].get_speed().x * cos(alpha) + bowls[i].get_speed().y * sin(alpha);
				double vy1 = bowls[i].get_speed().x * -sin(alpha) + bowls[i].get_speed().y * cos(alpha);
				double xax = vx1;
				vx1 = vx2;
				vx2 = xax;
				bowls[j].set_speed(sf::Vector2f(vx2 * cos(-alpha) + vy2 * sin(-alpha), vx2 * -sin(-alpha) + vy2 * cos(-alpha)));
					//bowls[j].vx = vx2 * cos(-alpha) + vy2 * sin(-alpha); //vx2 = w[j].vx * cos(-alpha) - w[j].vx * sin(-alpha); 
					//bowls[j].vy = vx2 * -sin(-alpha) + vy2 * cos(-alpha);//vy2 = w[j].vx * sin(-alpha) + w[j].vy * cos(-alpha);
				bowls[i].set_speed(sf::Vector2f(vx1 * cos(-alpha) + vy1 * sin(-alpha), vx1 * -sin(-alpha) + vy1 * cos(-alpha)));
				//bowls[i].vx = vx1 * cos(-alpha) + vy1 * sin(-alpha);//vx1 = w[i].vx * cos(-alpha) - w[i].vx * sin(-alpha);
				//bowls[i].vy = vx1 * -sin(-alpha) + vy1 * cos(-alpha);//vy1 = w[i].vx * sin(-alpha) + w[i].vy * cos(-alpha);
			}


		}
	}
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (dist(field.get_position(j), bowls[i].get_position()) < 2 * Bowl::radius)
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
		//bowls[1].draw_bowl(window);
		const float dt = clock.restart().asSeconds();
		std::cout << dt << std::endl;
		for (int i = 0; i < n; ++i)
		{
			
			bowls[i].draw_bowl(window);
			bowls[i].move(bowls[i].get_speed() * dt);
			tick();
		}
		window.display();
	}
}