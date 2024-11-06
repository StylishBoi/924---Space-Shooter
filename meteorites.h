#ifndef METEORITES_H
#define METEORITES_H

#include "entity.h"

class Meteorite : public Entity
{

private:
	static sf::Texture texture_;

public:
	Meteorite();
};

#endif