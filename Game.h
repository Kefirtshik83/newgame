#pragma once
#include "Field.h"
#include "Bowl.h"
#include "SFML/Graphics.hpp"
#include <iostream>
class Game
{
private:
	Field field;
	Bowl bowls[9];
public:
	Game();
	void draw_field(sf::RenderWindow& window) const;
	Field get_field() const ;
	void game_draw(sf::RenderWindow& window);
};