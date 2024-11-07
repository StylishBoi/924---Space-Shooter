#ifndef METEORITES_CC
#define METEORITES_CC

#include "meteorites.h"

#include <random>
#include <SFML/Graphics/Texture.hpp>

sf::Texture Meteorite::texture_;

Meteorite::Meteorite()
{
	//Add random PNG
	texture_.loadFromFile("assets\\PNG\\Meteors\\meteorBrown_big1.png");
	sprite_.setTexture(texture_);

	hit_box_.width *= (float)sprite_.getTextureRect().width * getScale().x;
	hit_box_.height *= (float)sprite_.getTextureRect().height * getScale().y;

	std::random_device rn_device;
	std::default_random_engine engine(rn_device());
	std::uniform_real_distribution<float> rnd_x(-250.0, -150.0);
	std::uniform_real_distribution<float> rnd_y(-50.0, 50.0);

	direction_ = { rnd_x(engine), rnd_y(engine) };

}

#endif