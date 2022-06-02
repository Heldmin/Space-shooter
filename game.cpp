#include "game.h"

Game::Game() :
	window(sf::VideoMode(WIDTH_W, HEIGHT_W), TITLE_W,
		sf::Style::Titlebar | sf::Style::Close), player(WIDTH_W / 2 - 100 / 2.f,
			HEIGHT_W - 120.f, "car_blue_1.png"), hp(500, 5, 25, sf::Color::Green),
	score(50, 5, 25, sf::Color::Yellow)
{
	window.setFramerateLimit(FPS);
	space1.init(0.f, 0.f);
	space2.init(0.f, -HEIGHT_W);
	meteor_spr.reserve(METEORS);
	for (auto i{ 0 }; i < METEORS; i++) {
		meteor_spr.push_back(new Meteor());
	}

}

void Game::play() {
	while (window.isOpen()) {
		check_event();
		update();
		draw();
		check_collisions();
	}
}
void Game::check_event() {
	sf::Event event;
	while (window.pollEvent(event)) {
		if (event.type == sf::Event::Closed) window.close();
		else
			if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
				sf::Time elapsed = clock.getElapsedTime();
				if (elapsed.asMilliseconds() > 250) {
					laser_spr.push_back(new Laser(player.getPosition().x + player.getWidth() / 2 - 5,
						player.getPosition().y));
					clock.restart();
				}
			}
	}
}
void Game::update() {
	switch (gamestate) {
	case GameState::INTRO:
		break;
	case GameState::PLAY:
		player.update();
		space1.update();
		space2.update();
		hp.update(std::to_string(static_cast<int>(player.getHp())));
		score.update(std::to_string(static_cast<int>(player.getScore())));
		for (auto i{ 0 }; i < METEORS; i++) {
			meteor_spr[i]->update();
		}
		for (auto it{ laser_spr.begin() }; it != laser_spr.end(); it++) {
			(*it)->update();
		}
		for (auto it{ bonus_spr.begin() }; it != bonus_spr.end(); it++) {
			(*it)->update();
		}
		for (auto it{ exp_spr.begin() }; it != exp_spr.end(); it++) {
			(*it)->update();
		}

		check_collisions();
		break;
	case GameState::GAMEOVER:
		break;
	case GameState::VICTORY:
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gamestate = GameState::PLAY;
			player.resetScore(0);
		}
		break;
	}
}
void Game::draw() {
	window.clear();
	switch (gamestate) {
	case GameState::INTRO:
		window.draw(intro.getSprite_i());
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			gamestate = GameState::PLAY;
		}
		break;
	case GameState::PLAY:
		window.draw(space1.getSprite());
		window.draw(space2.getSprite());
		for (size_t i{ 0 }; i < METEORS; i++) {
			meteor_spr[i]->draw(window);
		}
		for (auto it{ laser_spr.begin() }; it != laser_spr.end(); it++) {
			(*it)->draw(window);
		}
		for (auto it{ laser_spr.begin() }; it != laser_spr.end(); it++) {
			(*it)->draw(window);
		}
		for (auto it{ bonus_spr.begin() }; it != bonus_spr.end(); it++) {
			(*it)->draw(window);
		}
		for (auto it{ exp_spr.begin() }; it != exp_spr.end(); it++) {
			(*it)->draw(window);
		}

		player.draw(window);
		hp.draw(window);
		score.draw(window);

		break;
	case GameState::GAMEOVER:
		window.draw(gameover.getSprite_gg());
		break;
	case GameState::VICTORY:
		window.draw(victory.getSprite());
		break;
	}
	window.display();
}
void Game::check_collisions() {
	for (size_t i = 0; i < METEORS; i++) {
		if (player.getHitBox().intersects(
			meteor_spr[i]->getHitBox()))
		{
			player.reduceHp(meteor_spr[i]->getWidth() / 3);
			meteor_spr[i]->spawn();
		}
	}

	for (auto it = bonus_spr.begin(); it != bonus_spr.end(); it++) {
		if (player.getHitBox().intersects((*it)->getHitBox())) {
			player.reduceHp(-50);
			(*it)->setDel(true);
		}
	}



	bonus_spr.remove_if([](Bonus* bonus) {return bonus->getDel(); });

	if (player.isDead()) gamestate = GameState::GAMEOVER;
	if (player.controlHp()) player.constHp();



	laser_spr.remove_if([](Laser* laser) {return laser->getPosition().y < 0; });

	bonus_spr.remove_if([](Bonus* bonus) {
		return bonus->getPosition().y > HEIGHT_W; });

	for (auto it = laser_spr.begin(); it != laser_spr.end(); it++) {
		for (size_t i = 0; i < METEORS; i++) {
			if ((*it)->getHitBox().intersects(meteor_spr[i]->getHitBox()))
			{
				player.addScore(1);
				if (player.isWin()) {
					gamestate = GameState::VICTORY;
				}
				Explosion* new_explosion =
					new Explosion(meteor_spr[i]->getCenter());
				exp_spr.push_back(new_explosion);
				meteor_spr[i]->spawn();

				size_t chance = rand() % 100;
				if (chance < 10) {

					Bonus* new_bonus = new Bonus(static_cast<Bonus::BonusType>(0),
						meteor_spr[i]->getPosition());
					bonus_spr.push_back(new_bonus);
				}
			}
		}
	}

	exp_spr.remove_if([](Explosion* exp) {return exp->getDel(); });



}