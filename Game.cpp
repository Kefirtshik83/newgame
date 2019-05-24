#include "Game.h"

Game::Game() : field(), pl1(1), text("", font, 20)
{
	b_radius = bowls[0].get_radius();

	font.loadFromFile("pictures/CyrilicOld.TTF");//передаем нашему шрифту файл шрифта
	sf::Text text("", font, 20);//создаем объект текст. закидываем в объект текст строку, шрифт, размер шрифта(в пикселях);//сам объект текст (не строка)
	//text.setColor(sf::Color::Red);//покрасили текст в красный. если убрать эту строку, то по умолчанию он белый
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);//жирный и подчеркнутый текст. по умолчанию он "худой":)) и не подчеркнутый

	start_rect.setSize(sf::Vector2f(2 * Field::d + Field::w, Field::score_field + Field::h + 2 * Field::d));
	start_rect.setFillColor(sf::Color::Red);
	start_circle.setRadius(150);
	start_circle.setOrigin(sf::Vector2f(150,150));
	start_circle.setFillColor(sf::Color::Blue);
	start_circle.setPosition(Field::d + 0.5f * Field::w, Field::score_field + Field::d + 0.5f * Field::h);
}

Field Game::get_field() const { return field; }
Player1 Game::get_pl1() const { return pl1; }
void Game::draw_score(sf::RenderWindow& window) 
{
	std::ostringstream playerScoreString_1, playerScoreString_2;
	playerScoreString_1 << pl1.get_score();
	text.setString("1 score:" + playerScoreString_1.str());
	text.setPosition(field.get_d(), field.get_score_field() - field.get_d());
	window.draw(text);

	playerScoreString_2 << pl2.get_score();
	text.setString("2 score:" + playerScoreString_2.str());
	text.setPosition(field.get_w() / 2, field.get_score_field() - field.get_d());
	window.draw(text);
}
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
		b.set_speed(sf::Vector2f(-(1 + 0.1 * (b.abs_speed() < 500)) * b.get_speed().x, b.get_speed().y));
		if(b.get_position().x - b_radius < Field::d - 1)
			b.set_position(sf::Vector2f(Field::d + b_radius, b.get_position().y));
		if(b.get_position().x + b_radius > Field::d + Field::w + 1)
			b.set_position(sf::Vector2f(Field::d - b_radius + Field::w, b.get_position().y));
	}
	if (b.get_position().y - b_radius < Field::d + Field::score_field || b.get_position().y + b_radius > Field::d + Field::h + Field::score_field)
	{
		b.set_speed(sf::Vector2f(b.get_speed().x, -(1 + 0.1 * (b.abs_speed() < 500)) * b.get_speed().y));
		if(b.get_position().y - b_radius < Field::d + Field::score_field-1)
			b.set_position(sf::Vector2f(b.get_position().x, Field::d + Field::score_field + b_radius));
		if(b.get_position().y + b_radius > Field::d + Field::h + Field::score_field+1)
			b.set_position(sf::Vector2f(b.get_position().x, Field::d + Field::h + Field::score_field - b_radius));
	}
	if (b.get_position().x < -b_radius && b.get_position().x > - 50)
	{
		b.set_speed(sf::Vector2f(0, 0));
		b.set_position(sf::Vector2f(-100, Field::score_field + Field::d + Field::h / 2));
		pl2.score_up();
	}
	if(b.get_position().x > 2 * Field::d + Field::w + b_radius && b.get_position().x < 2 * Field::d + Field::w + b_radius + 50)
	{
		b.set_speed(sf::Vector2f(0, 0));
		b.set_position(sf::Vector2f(2 * Field::d + Field::w + b_radius + 100, Field::score_field + Field::d + Field::h / 2));
		pl1.score_up();
	}
}
void Game::wall_bowls_collision(sf::CircleShape circle, Bowl& bowl)
{
	sf::Vector2f norm = normal(sf::Vector2f(circle.getPosition().x - bowl.get_position().x, circle.getPosition().y - bowl.get_position().y));
	sf::Vector2f v_norm = proection_b_on_a(norm, bowl.get_speed());
	sf::Vector2f v_prod = bowl.get_speed() - v_norm;
	bowl.set_speed(bowl.get_speed() - (float)2 * v_prod);
	if (dist(circle.getPosition(), bowl.get_position()) < circle.getRadius() + b_radius - 1)
	{
		//sf::Vector2f middle = (circle.getPosition() + bowl.get_position()) * 0.5f;
		bowl.set_position(circle.getPosition() + (bowl.get_position() - circle.getPosition()) *(float)(b_radius * 2 / (abs(bowl.get_position() - circle.getPosition()))));
		//std::cout << dist(ci.get_position(), b2.get_position()) << std::endl;
	}
}
void Game::player1_collision(Player1 pl1, Bowl& bowl)
{
	if (dist(pl1.get_position(), bowl.get_position()) < b_radius + pl1.get_radius())
	{
		sf::Vector2f norm = normal(sf::Vector2f(pl1.get_position().x - bowl.get_position().x, pl1.get_position().y - bowl.get_position().y));
		sf::Vector2f v_norm = proection_b_on_a(norm, bowl.get_speed());
		sf::Vector2f v_prod = bowl.get_speed() - v_norm;
		bowl.set_speed(bowl.get_speed() - (float)2 * v_prod);
		if (dist(pl1.get_position(), bowl.get_position()) < b_radius + pl1.get_radius() - 1)
		{
			//sf::Vector2f middle = (pl1.get_position() + bowl.get_position()) * 0.5f;
			bowl.set_position(pl1.get_position() + (bowl.get_position() - pl1.get_position()) * (float)((b_radius+ pl1.get_radius())  / (abs(bowl.get_position() - pl1.get_position()))));
			//std::cout << dist(ci.get_position(), b2.get_position()) << std::endl;
		}
	}
}
//sf::Vector2f Game:: player2_collision(Player2 pl2, Bowl& bowl);


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
			if (dist(field.get_position(j), bowls[i].get_position()) < b_radius + field.get_circle(j).getRadius())
			{
				wall_bowls_collision(field.get_circle(j), bowls[i]);
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		player1_collision(pl1, bowls[i]);
		player1_collision(pl2, bowls[i]);
	}
	
}

void Game::is_start(sf::RenderWindow& window, sf::Event event)
{
	if (game_start == 0)
	{

		sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
		sf::Vector2f pos = (window).mapPixelToCoords(pixelPos);
		if (dist(pos, start_circle.getPosition()) < start_circle.getRadius() && event.type == event.MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
		{
			game_start = 1;
			game_pause = 0;
		}
	}
}

void Game::is_pause()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F5))
		game_pause = 1;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
		game_pause = 0;
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
			is_start(window, event);

		}
		is_pause();
		window.clear();
		if (game_start == 1)
		{
			get_field().draw_field(window);
			pl1.draw_player(window);
			pl2.draw_player(window);
			draw_score(window);
			if (game_pause == 0)
			{
				pl1.control();
				pl2.control();
			}

			//bowls[1].draw_bowl(window);
			const float dt = clock.restart().asSeconds();
			//std::cout << dt << std::endl;
			for (int i = 0; i < n; ++i)
			{

				bowls[i].draw_bowl(window);
				if (game_pause == 0)
				{
					bowls[i].move(bowls[i].get_speed() * dt);
					tick();
				}
			}
		}
		else
		{
			window.draw(start_rect);
			window.draw(start_circle);

		}
		window.display();
	}
}