#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

class Score {
private:
	sf::Font font;
	sf::Text text;
public:
	Score(float x, float y, int size, sf::Color color) {
		font.loadFromFile(SCORE_F);
		text.setFont(font);
		text.setFillColor(color);
		text.setCharacterSize(size);
		text.setPosition(x, y);
	}
	void draw(sf::RenderWindow& window) { window.draw(text); }
	void update(std::string str) { text.setString(str); }
};
