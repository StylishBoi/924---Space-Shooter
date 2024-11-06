#include "projectile.h"

#include <iostream>
#include <array>
#include <SFML/Graphics/RenderTarget.hpp>

sf::Texture Projectile::texture_;
std::array<sf::Texture, 4> Projectile::animation_;

Projectile::Projectile()
{
	texture_.loadFromFile("assets\\PNG\\Lasers\\laserGreen12.png");

	animation_[0].loadFromFile("assets\\PNG\\Lasers\\laserGreen01.png");
	animation_[1].loadFromFile("assets\\PNG\\Lasers\\laserGreen07.png");
	animation_[2].loadFromFile("assets\\PNG\\Lasers\\laserGreen06.png");
	animation_[3].loadFromFile("assets\\PNG\\Lasers\\laserGreen05.png");

	sprite_.setTexture(texture_);

	setOrigin(0, texture_.getSize().y / 2);
	setRotation(90);
	setScale(0.5f, 0.5f);

	direction_ = { 500 , 0 };

}

void Projectile::UpdateAnimation(float dt) {
	time_elapsed_ += dt;
	if (time_elapsed_ > 0.25f) {
		idx_texture_++;
		if (idx_texture_ >= animation_.size()) {
			idx_texture_ = 0;
		}
	}
	time_elapsed_ = 0;
	sprite_.setTexture(animation_[idx_texture_]);
}