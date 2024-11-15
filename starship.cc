#ifndef STARSHIP_CC
#define STARSHIP_CC

#include "starship.h"
#include <iostream>

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

constexpr double kShootPeriod = 0.15f;

Starship::Starship()
{
	texture_.loadFromFile("assets\\PNG\\playerShip1_blue.png");
	sprite_.setTexture(texture_);
	sprite_.setOrigin(texture_.getSize().x / 2, texture_.getSize().y / 2);
	sprite_.setRotation(90.f);
	sprite_.scale(0.5f, 1.0f);
	setPosition({150,350});
	hit_box_.width += (float)sprite_.getTextureRect().width * getScale().x;
	hit_box_.height += (float)sprite_.getTextureRect().height * getScale().y;


}

void Starship::Move(sf::Vector2f direction, float dt)
{
	move(direction.x * kSpeed * dt, direction.y * kSpeed * dt);
	hit_box_ = sprite_.getGlobalBounds();
	hit_box_.left += getPosition().x;
	hit_box_.top += getPosition().y;
}

void Starship::SetPosition(sf::Vector2u position)
{
	setPosition(sf::Vector2f(position));
	hit_box_ = sprite_.getGlobalBounds();
	hit_box_.left += getPosition().x;
	hit_box_.top += getPosition().y;
}

void Starship::ShipDamage()
{
	health -= 1;

	if (health <= 0)
	{
		SetDeath();
	}
}

void Starship::Refresh(float dt)
{
	shoot_dt_ += dt;
	if (shoot_dt_ > kShootPeriod)
	{
		is_shoot_ready_ = true;
		shoot_dt_ = 0;
	}
	collision = false;
}

void Starship::CheckMeteoritesCollisions(std::vector<Meteorite>& meteorites_)
{
	for (auto& m : meteorites_)
	{
		if (m.IsDead() == false && hit_box_.intersects(m.HitBox())) {
			m.SetDeath();
			collision = true;
			ShipDamage();
		}
	}
}

void Starship::CheckProjectilesCollisions(std::vector<Projectile>& projectiles_)
{

	for (auto& p : projectiles_)
	{
		if (p.IsDead() == false && hit_box_.intersects(p.HitBox())) {
			p.SetDeath();
			collision = true;
			ShipDamage();
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
			collision = true;
			ShipDamage();
		}
	}
}

void Starship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}

#endif