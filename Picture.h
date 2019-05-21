#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
class Picture
{
public:
	void Create_Mask(int r, int g, int b, int a);
	Picture(std::string pic_name, int x_position = 0, int y_position = 0, int x1_im = -1, int y1_im = -1, int x2_im = -1, int y2_im = -1);
	void Set_Scale(float x, float y);
	void Set_Position(int x, int y);
	sf::Sprite get_sprite() const;
private:
	float x_position, y_position;
	int x1_im, x2_im, y1_im, y2_im; //size of cut out rectangle
	sf::Image image;
	sf::Texture texture;
	sf::Sprite sprite;
	std::string pic_name; //name of picture
};