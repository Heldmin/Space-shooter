#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

class Space {
private:
	sf::Texture texture;
	sf::Sprite sprite;
	sf::Vector2f speeds = sf::Vector2f(0.0f, 3.0f);
public:
	Space() {
		texture.loadFromFile(SPACE_F);
		sprite.setTexture(texture);
	}
	sf::Sprite getSprite() { return sprite; }
	void init(float x, float y) { sprite.setPosition(x, y); }
	void update() {
		sprite.move(speeds);
		if (sprite.getPosition().y >= HEIGHT_W) {
			sprite.setPosition(0.f, -HEIGHT_W);
		}
	}
};
