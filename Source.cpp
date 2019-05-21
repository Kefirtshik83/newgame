#include "Game.h"
#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
	srand(time(0));
	Game game;
	std::cout << game.get_field().get_w() << " " << game.get_field().get_h() << " " << game.get_field().get_d()<< " "<< game.get_field().get_score_field()<< std::endl;
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(game.get_field().get_w() + 2 * game.get_field().get_d(), game.get_field().get_h() + 2 * game.get_field().get_d() + game.get_field().get_score_field()), "game", sf::Style::Default, settings);
	game.game_draw(window);
	return 0;
}