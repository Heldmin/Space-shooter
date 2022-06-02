#include "player.h"
#include "const.h"


Player::Player(float x, float y, std::string texture_file_name) {
	texture.loadFromFile(texture_file_name);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}

void Player::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Player::update() {
	float speedx{ SPEEDX_P };
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sprite.getPosition().x > 0) {
		sprite.move(-speedx, 0);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && sprite.getPosition().x < WIDTH_W - getWidth()) {
		sprite.move(speedx, 0);
	}
}
void Player::reduceHp(float dmg) { hp -= dmg; }
void Player::addScore(float score_) { score += score_; }


size_t Player::getWidth() { return sprite.getLocalBounds().width; }
size_t Player::getHeight() { return sprite.getLocalBounds().height; }
size_t Player::controlHp() { return hp > 100; }
size_t Player::constHp() { return hp = 100; }


sf::Vector2f Player::getPosition() { return sprite.getPosition(); }

sf::FloatRect Player::getHitBox() { return sprite.getGlobalBounds(); }

bool Player::isDead() { return hp < 0; }
bool Player::isWin() { return score > score_limite; }


float Player::getHp() { return hp; }
float Player::getScore() { return score; }