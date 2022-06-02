#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

class Meteor {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	int speedx;
	int speedy;
	static std::string meteor_f[];
public:
	Meteor();
	void draw(sf::RenderWindow& window);
	void update();
	void spawn();

	size_t getWidth();
	size_t getHeight();

	sf::FloatRect getHitBox();

	sf::Vector2f getPosition();
	sf::Vector2f getCenter();
};
