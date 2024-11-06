#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>

#include "asteroides.h"
#include "asteroidesManager.h"
#include "Background.h"
#include "ennemiShipManager.h"
#include "space_ship.h"
#include "projectileManager.h"



class Game
{
	sf::RenderWindow window_;
	space_ship ship1;
	Background background1;
	Background background2;
	projectileManager projectiles_;
	asteroidesManager asteroides_;
	projectileManager ennemi_projectiles_;
	ennemiShipManager ennemi_ships_;

	sf::Clock clock;
	float dt = 0.f;

public:
	Game();
	void Loop();
};

#endif // GAME_H
