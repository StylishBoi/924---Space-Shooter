#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics/RenderWindow.hpp>

#include "projectile_manager.h"
#include "meteorites_manager.h"
#include "starship.h"
#include "enemy.h"
#include "enemy_manager.h"
#include "display.h"
#include "sounds.h"

class Game
{
private:
	sf::RenderWindow window_;

	ProjectileManager player_projectiles_;
	ProjectileManager enemy_projectiles_;
	MeteoritesManager meteorites_;
	EnemyManager enemy_manager_;

	Starship starship_;

	Sound sound_;
	Display display_;

	sf::Clock clock_;

public:
	Game();
	void instructions();
	void loop();
};

#endif
