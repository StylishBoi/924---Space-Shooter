#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H

#include "enemy.h"
#include "projectile_manager.h"

class EnemyManager : public sf::Drawable
{
private:
	std::vector<Enemy> enemies_;
	float spawn_timer_ = 0;

public:
	std::vector<Enemy>& GetEntities() { return enemies_; }
	void Refresh(float dt, const sf::Vector2u& window_size, ProjectileManager& enemy_projectiles_);

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif