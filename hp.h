#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

class Hp {
private:
	sf::Font font;
	sf::Text text;
public:
	Hp(float x, float y, int size, sf::Color color) {
		font.loadFromFile(HP_F);
		text.setFont(font);
		text.setFillColor(color);
		text.setCharacterSize(size);
		text.setPosition(x, y);
	}

	void draw(sf::RenderWindow& window) { window.draw(text); }
	void update(std::string str) { text.setString(str); }


};
