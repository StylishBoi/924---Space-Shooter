#ifndef PROJECTILE_MANAGER_H
#define PROJECTILE_MANAGER_H

#include <vector>
#include <SFML/System/Clock.hpp>

#include "meteorites.h"
#include "projectile.h"
#include "enemy.h"

class ProjectileManager : public sf::Drawable
{
private:
	int score=0;
	std::vector<Projectile> projectiles_;
	sf::Clock cooldown_timer_;
	float cooldown_dt_ = 0;

	bool collision = false;
	bool enemy_collision = false;

public:
	std::vector<Projectile>& GetEntities() { return projectiles_; }

	void Spawn(sf::Vector2f spawn_position, sf::Vector2f direction);
	void Refresh(const float dt, const sf::Vector2u& window_size);

	int GetScore() const { return score; }
	int GetCollision() const { return collision; }
	int GetECollision() const { return enemy_collision; }

	void CheckCollisions(std::vector<Meteorite>& meteorites_);
	void CheckCollisions(std::vector<Enemy>& enemy);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif