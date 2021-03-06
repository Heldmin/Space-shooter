#include "laser.h"
#include "const.h"

Laser::Laser(float x, float y) {
	texture.loadFromFile(LASER_F);
	sprite.setTexture(texture);
	sprite.setPosition(x, y);
}
void Laser::draw(sf::RenderWindow& window) { window.draw(sprite); }
void Laser::update() {
	sprite.move(0.f, -LASER_SPEED);
}


size_t Laser::getWidth() { return sprite.getLocalBounds().width; }
size_t Laser::getHeight() { return sprite.getLocalBounds().height; }

sf::FloatRect Laser::getHitBox() { return sprite.getGlobalBounds(); }
sf::Vector2f Laser::getPosition() { return sprite.getPosition(); }
