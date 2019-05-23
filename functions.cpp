#include"functions.h"
float scal(sf::Vector2f a, sf::Vector2f b) { return a.x* b.x + a.y * b.y; }
float abs(sf::Vector2f a)  { return sqrt(scal(a, a)); }
float dist(sf::Vector2f a1, sf::Vector2f a2){ return abs(a1-a2); }
sf::Vector2f proection_b_on_a(sf::Vector2f a, sf::Vector2f b) { return a * (float)(scal(a,b)/scal(a,a)) ; }
sf::Vector2f normal(sf::Vector2f a) { return sf::Vector2f(a.y/scal(a,a), -a.x/scal(a,a)); }