#include "Game.h"

Game::Game() : field()
{
	
}

Field Game::get_field() const { return field; }



void Game::game_draw(sf::RenderWindow& window)
{
	std::cout << bowls[1].get_x() <<" "<< bowls[1].get_y() << std::endl;
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
		for (int i = 0; i < 9; ++i)
			bowls[i].draw_bowl(window);
		window.display();
	}
}