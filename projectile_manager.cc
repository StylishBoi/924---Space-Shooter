#include "projectile_manager.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <iostream>

#include "meteorites.h"

constexpr float kCooldown_limit_ = 0.05f;

void ProjectileManager::Spawn(sf::Vector2f spawn_position)
{
	if (cooldown_dt_ < kCooldown_limit_) {
		return;
	}

	projectiles_.emplace_back();
	projectiles_.back().setPosition(spawn_position);
	cooldown_dt_ = 0;
}


void ProjectileManager::Refresh(float dt, const sf::Vector2u& window_size)
{
	cooldown_dt_ += cooldown_timer_.restart().asSeconds();

	auto remove_elt = std::remove_if(
		projectiles_.begin(),
		projectiles_.end(),
		[](const Projectile& p){return p.IsDead(); });

	if (remove_elt != projectiles_.end()) {
		projectiles_.erase(remove_elt);
	};

	for (Projectile& p : projectiles_)
	{
		p.Move(dt, window_size);
		p.UpdateAnimation(dt);
	}
}

void ProjectileManager::CheckCollisions(std::vector<Meteorite>& meteorites_) {
	for (auto& p : projectiles_)
	{
		for (auto& m : meteorites_)
		{
			if (p.IsDead()==false && m.IsDead()==false && p.Intersects(m.HitBox())) {
				p.SetDeath();
				m.SetDeath();
			}
		}
	}
}

void ProjectileManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (const Projectile& p : projectiles_)
	{
		target.draw(p);
	}
}