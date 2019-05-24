#pragma once
#include "Field.h"
#include "Bowl.h"
#include "Player1.h"
#include "Player_2.h"
#include "functions.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <sstream>
class Game
{
private:
	sf::Font font;//רנטפע 
	sf::Text text;
	sf::RectangleShape start_rect;
	sf::CircleShape start_circle;
	Field field;
	Bowl bowls[25];
	Player1 pl1;
	Player2 pl2;
	int b_radius;
	int n = 25;
	bool game_start = 0;
	bool game_pause = 0;
public:
	Game();
	void is_start(sf::RenderWindow& window, sf::Event event);
	void is_pause();
	void draw_score(sf::RenderWindow& window);
	void player1_collision(Player1 pl1, Bowl& bowl);
	void player2_collision(Player2 pl2, Bowl& bowl);
	void wall_bowls_collision(sf::CircleShape circle,Bowl& bowl );
	void wall_collision(Bowl& b);
	void bowls_collision(Bowl & b1, Bowl& b2);
	sf::Vector2f players_collision(sf::Vector2f v);
	Player1 get_pl1() const;
	void draw_field(sf::RenderWindow& window) const;
	Field get_field() const ;
	void game_draw(sf::RenderWindow& window);
	void tick();

};