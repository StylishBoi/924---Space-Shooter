#include "enemy_manager.h"
#include "projectile.h"

#include <random>
#include <SFML/Graphics/RenderTarget.hpp>

void EnemyManager::Refresh(float dt, const sf::Vector2u& window_size, ProjectileManager& enemy_projectiles_)
{
	spawn_timer_ += dt;
	if (spawn_timer_ > 5.f) {
		enemies_.emplace_back();

		std::random_device rn_device;
		std::default_random_engine engine(rn_device());
		std::uniform_real_distribution<float> uniform_dist(0, window_size.y);

		enemies_.back().SetPosition(window_size.x, uniform_dist(engine));

		spawn_timer_ = 0;
	}

	auto remove_elt = std::remove_if(
		enemies_.begin(),
		enemies_.end(),
		[](const Enemy& e) {return e.IsDead(); });

	if (remove_elt != enemies_.end()) {
		enemies_.erase(remove_elt);
	};

	for (auto& e : enemies_)
	{
		e.Move(dt, window_size);
		e.Refresh(dt);

		if (e.ShootReady()) {
			enemy_projectiles_.Spawn(e.GetPosition(), { -750, 0 });
		}
	}

}

void EnemyManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& e : enemies_)
	{
		target.draw(e);
	}
}