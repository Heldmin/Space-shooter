#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

class Splash {
private:
	sf::Texture texture_gg;
	sf::Sprite sprite_gg;
	sf::Texture texture_i;
	sf::Sprite sprite_i;
	sf::Texture texture;
	sf::Sprite sprite;
public:
	Splash() {
		texture_i.loadFromFile("intro.jpg");
		sprite_i.setTexture(texture_i);
		texture_gg.loadFromFile("gameover.jpg");
		sprite_gg.setTexture(texture_gg);
		texture.loadFromFile("istockphoto-1184395227-640x640.jpg");
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite_gg() { return sprite_gg; }
	sf::Sprite getSprite_i() { return sprite_i; }
	sf::Sprite getSprite() { return sprite; }
};
