#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>
#include "projectile_manager.h"
#include "meteorites_manager.h"
#include "starship.h"

class Game
{
private:
	sf::RenderWindow window_;

	ProjectileManager projectiles_;
	MeteoritesManager meteorites_;
	Starship starship_;

	sf::Clock clock_;

public:
	Game();
	void loop();
};

#endif
