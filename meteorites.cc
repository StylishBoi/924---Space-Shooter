#include "meteorites.h"

#include <random>
#include <SFML/Graphics/Texture.hpp>

sf::Texture Meteorite::texture_;

Meteorite::Meteorite()
{
	texture_.loadFromFile("assets\\PNG\\Meteors\\meteorBrown_big1.png");
	sprite_.setTexture(texture_);
	setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);

	std::random_device rn_device;
	std::default_random_engine engine(rn_device());
	std::uniform_real_distribution<float> rnd_x(-250.0, -150.0);
	std::uniform_real_distribution<float> rnd_y(-150.0, 150.0);

	direction_ = { rnd_x(engine), rnd_y(engine) };

}