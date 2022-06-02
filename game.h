#pragma once
#include <SFML/Graphics.hpp>
#include <list>
#include <vector> 
#include "const.h"
#include "player.h"
#include "laser.h"
#include "space.h"
#include "meteors.h"
#include "splash.h"
#include "hp.h"
#include "bonus.h"
#include "explosion.h"
#include "score.h"

class Game {
public:
	enum class GameState { INTRO, PLAY, GAMEOVER, VICTORY };
	Game();
	void play();
private:
	void check_event();
	void update();
	void draw();
	void check_collisions();

	sf::RenderWindow window;
	Player player;
	sf::Clock clock;
	Space space1, space2;
	std::list<Laser*> laser_spr;
	std::vector<Meteor*> meteor_spr;
	GameState gamestate = GameState::INTRO;
	Splash intro, gameover, victory;
	Hp hp;
	std::list<Bonus*> bonus_spr;
	std::list<Explosion*> exp_spr;
	Score score;


};
