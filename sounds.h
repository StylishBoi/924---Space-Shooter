#ifndef SOUNDS_H
#define SOUNDS_H

#include <SFML/Audio.hpp>
#include "entity.h"
#include <iostream>

class Sound
{
private:
	sf::SoundBuffer b_projectile;
	sf::Sound s_projectile;

	sf::SoundBuffer b_meteorite;
	sf::Sound s_meteorite;

	sf::SoundBuffer b_enemy;
	sf::Sound s_enemy;

	sf::SoundBuffer b_enemy_hit;
	sf::Sound s_enemy_hit;

	sf::SoundBuffer b_background;
	sf::Sound s_background;

public:
	Sound();

	//Gives back sound
	sf::Sound GetSProjectile() { return s_projectile; }
	sf::Sound GetSMeteorite() { return s_meteorite; }
	sf::Sound GetSEnemy() { return s_enemy; }
	sf::Sound GetSEnemyHit() { return s_enemy_hit; }
	sf::Sound GetBackground() { return s_background; }
};

#endif
