#ifndef METEORITES_MANAGER_CC
#define METEORITES_MANAGER_CC

#include "meteorites_manager.h"
#include <random>

void MeteoritesManager::Refresh(float dt, const sf::Vector2u& window_size)
{
	time_elapsed_ += dt;
	if (time_elapsed_ > 1.5f) {
		meteorites_.emplace_back();
		std::random_device rn_device;
		std::default_random_engine engine(rn_device());
		std::uniform_real_distribution<float> uniform_dist(0, window_size.y);

		meteorites_.back().SetPosition(window_size.x, uniform_dist(engine));
		
		time_elapsed_ = 0;
	}

	auto remove_elt = std::remove_if(
		meteorites_.begin(),
		meteorites_.end(),
		[](const Meteorite& m) {return m.IsDead(); });

	if (remove_elt != meteorites_.end())
	{
		meteorites_.erase(remove_elt);
	};

	for (Meteorite& p : meteorites_)
	{
		p.Move(dt, window_size);
	}
}

void MeteoritesManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& m : meteorites_)
	{
		target.draw(m);
	}
}

#endif