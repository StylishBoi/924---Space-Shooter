#ifndef STARSHIP_CC
#define STARSHIP_CC

#include "starship.h"
#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Starship::Starship()
{
	texture_.loadFromFile("assets\\PNG\\playerShip1_blue.png");
	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
	sprite_.setRotation(90.f);
	sprite_.scale(0.5f, 1.0f);

}

void Starship::Move(sf::Vector2f direction, float dt)
{
	move(direction * kSpeed * dt);
	hit_box_.left += getPosition().x;
	hit_box_.top += getPosition().y;
}

void Starship::SetPosition(sf::Vector2u position)
{
	setPosition(sf::Vector2f(position));
	hit_box_.left += getPosition().x;
	hit_box_.top += getPosition().y;
}

void Starship::CheckMeteoritesCollisions(std::vector<Meteorite>& meteorites_)
{
	for (auto& m : meteorites_)
	{
		if (m.IsDead() == false && hit_box_.intersects(m.HitBox())) {
			std::cout << "It hit the meteorites.";
			m.SetDeath();
		}
	}
}

void Starship::CheckProjectilesCollisions(std::vector<Projectile>& projectiles_)
{

	for (auto& p : projectiles_)
	{
		if (p.IsDead() == false && hit_box_.intersects(p.HitBox())) {
			p.SetDeath();
		}
	}
}

void Starship::CheckEnemiesCollisions(std::vector<Enemy>& enemies_)
{

	for (auto& e : enemies_)
	{
		if (e.IsDead() == false && hit_box_.intersects(e.HitBox()))
		{
			e.Damage(5);
		}
	}
}

void Starship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}

#endif