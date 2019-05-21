#include "Picture.h"
Picture::Picture(std::string pic_name, int x_position, int y_position, int x1_im, int y1_im, int x2_im, int y2_im) : x_position(x_position), y_position(y_position),
x1_im(x1_im), x2_im(x2_im), y1_im(y1_im), y2_im(y2_im), pic_name(pic_name)
{
	image.loadFromFile("pictures/" + pic_name);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(x1_im, y1_im, x2_im, y2_im));
	sprite.setPosition(x_position, y_position);
}
void Picture::Create_Mask(int r, int g, int b, int a)
{
	image.createMaskFromColor(sf::Color(r, g, b, a), 0);
	texture.loadFromImage(image);
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(x1_im, y1_im, x2_im, y2_im));
	sprite.setPosition(x_position, y_position);
}

void Picture::Set_Scale(float x, float y)
{
	sprite.setScale(x, y);
}

void Picture::Set_Position(int x, int y)
{
	sprite.setPosition((float)x, (float)y);
}

sf::Sprite Picture::get_sprite() const
{
	return sprite;
}