#include "Game.h"

Game::Game() : field()
{
	
}

Field Game::get_field() const { return field; }

void Game::tick()
{
	/*
	for (int i = 0; i < n; ++i)
	{
		for (int j = i + 1; j < n; ++j)
		{
			if (s(i, j) < w[i].get_r() + w[j].get_r())
			{
				//std::cout << "kek" << std::endl;
				//std::cout <<"begin" << std::endl << "vx1 = " << w[0].vx << " vy1 = " << w[0].vy << std::endl;
				//std::cout << "vx2 = " << w[1].vx<< " vy2 = " << w[1].vy << std::endl;
				double alpha = (w[j].get_y() - w[i].get_y()) / (w[j].get_x() - w[i].get_x()); //преобразование скоростей при соударении
				alpha = atan(alpha);
				double vx2 = w[j].vx * cos(alpha) + w[j].vy * sin(alpha);
				double vy2 = w[j].vx * -sin(alpha) + w[j].vy * cos(alpha);
				double vx1 = w[i].vx * cos(alpha) + w[i].vy * sin(alpha);
				double vy1 = w[i].vx * -sin(alpha) + w[i].vy * cos(alpha);
				double xax = vx1;
				vx1 = vx2;
				vx2 = xax;
				w[j].vx = vx2 * cos(-alpha) + vy2 * sin(-alpha); //vx2 = w[j].vx * cos(-alpha) - w[j].vx * sin(-alpha); 
				w[j].vy = vx2 * -sin(-alpha) + vy2 * cos(-alpha);//vy2 = w[j].vx * sin(-alpha) + w[j].vy * cos(-alpha);
				w[i].vx = vx1 * cos(-alpha) + vy1 * sin(-alpha);//vx1 = w[i].vx * cos(-alpha) - w[i].vx * sin(-alpha);
				w[i].vy = vx1 * -sin(-alpha) + vy1 * cos(-alpha);//vy1 = w[i].vx * sin(-alpha) + w[i].vy * cos(-alpha);
			}


		}
	}
	*/
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
		for (int i = 0; i < 1; ++i)
		{
			
			bowls[i].draw_bowl(window);
			bowls[i].move(bowls[i].get_speed() * dt);
		}
		window.display();
	}
}