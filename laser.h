#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

class Laser {
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Laser(float x, float y);
	void draw(sf::RenderWindow& window);
	void update();
	size_t getWidth();
	size_t getHeight();
	sf::FloatRect getHitBox();
	sf::Vector2f getPosition();

};
