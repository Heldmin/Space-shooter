#pragma once
#include <SFML/Graphics.hpp>
#include "const.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float hp{ HP_P };
	float score{ SCORE_P };
	sf::Color color;
public:
	Player(float x, float y, std::string texture_file_name);
	void draw(sf::RenderWindow& window);
	void update();
	void reduceHp(float dmg);
	void addScore(float score_);
	void resetScore(float score_) { score = score_; }


	size_t getWidth();
	size_t getHeight();
	size_t controlHp();
	size_t constHp();

	sf::Vector2f getPosition();

	sf::FloatRect getHitBox();

	bool isDead();
	bool isWin();


	float getHp();
	float getScore();
};
