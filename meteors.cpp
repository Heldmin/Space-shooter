#include "meteors.h"
#include "const.h"

std::string Meteor::meteor_f[]
{ "meteorBrown_big1.png", "meteorBrown_big2.png", "meteorBrown_big3.png", "meteorBrown_big4.png",
"meteorBrown_med1.png", "meteorBrown_med3.png", "meteorBrown_small1.png", "meteorBrown_small2.png",
"meteorBrown_tiny1.png", "meteorBrown_tiny2.png", "meteorGrey_big1.png", "meteorGrey_big2.png",
"meteorGrey_big3.png", "meteorGrey_big4.png", "meteorGrey_med1.png", "meteorGrey_med2.png",
"meteorGrey_small1.png", "meteorGrey_small2.png", "meteorGrey_tiny1.png", "meteorGrey_tiny2.png" };

Meteor::Meteor() {
	size_t type = rand() % 20;
	texture.loadFromFile(Meteor::meteor_f[type]);
	sprite.setTexture(texture);
	spawn();
}

void Meteor::draw(sf::RenderWindow& window) {
	window.draw(sprite);
}
void Meteor::update() {
	sprite.move(speedx, speedy);
	if (sprite.getPosition().x < 0.f - getWidth() || sprite.getPosition().x > WIDTH_W ||
		sprite.getPosition().y > HEIGHT_W) {
		spawn();
	}
}
void Meteor::spawn() {
	float startx = rand() % (static_cast<size_t>(WIDTH_W) - getWidth() + 1);
	float starty = rand() % (static_cast<size_t>(HEIGHT_W) + 1) - HEIGHT_W;
	sprite.setPosition(startx, starty);
	speedx = rand() % 5 - 2;
	speedy = rand() % 8 + 3;
}

size_t Meteor::getWidth() { return sprite.getLocalBounds().width; }
size_t Meteor::getHeight() { return sprite.getLocalBounds().height; }

sf::FloatRect Meteor::getHitBox() { return sprite.getGlobalBounds(); }

sf::Vector2f Meteor::getPosition() { return sprite.getPosition(); }
sf::Vector2f Meteor::getCenter()
{
	return sf::Vector2f(sprite.getPosition().x + getWidth() / 2.0, sprite.getPosition().y + getHeight() / 2.0);
}