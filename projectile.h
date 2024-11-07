#ifndef PROJECTILE_H
#define PROJECTILE_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Transformable.hpp>

#include "entity.h"

class Projectile : public Entity
{

private:
	static sf::Texture texture_;

	static std::array<sf::Texture, 4> animation_;
	float time_elapsed_ = 0.f;
	int idx_texture_ = 0;

public:
	Projectile(sf::Vector2f direction);
	void UpdateAnimation(float dt);
};

#endif