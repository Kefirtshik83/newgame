#pragma once
#include "Field.h"
#include "Bowl.h"
#include "functions.h"
#include "SFML/Graphics.hpp"
#include <iostream>
class Game
{
private:
	Field field;
	Bowl bowls[25];
	int n = 25;
public:
	Game();
	void draw_field(sf::RenderWindow& window) const;
	Field get_field() const ;
	void game_draw(sf::RenderWindow& window);
	void tick();

};