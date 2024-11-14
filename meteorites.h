#ifndef METEORITES_H
#define METEORITES_H

#include "entity.h"
#include "SFML/Audio.hpp"

class Meteorite : public Entity
{

private:
	static sf::Texture texture_;
	sf::SoundBuffer m_soundbuffer;
	sf::Sound m_sound;

public:
	Meteorite();
	//void PlaySound() { m_sound.play(); }
};

#endif