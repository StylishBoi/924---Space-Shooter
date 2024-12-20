#ifndef ENEMY_H
#define ENEMY_H

#include <SFML/Graphics/Texture.hpp>

#include "entity.h"

class Enemy : public Entity
{
private:
	static sf::Texture texture_;
	int hp_ = 5;

	float shoot_dt_=0.f;
	float burst_dt_=0.f;
	bool wait_shoot_ = false;

	void SetDeath();

public:
	Enemy();

	sf::Vector2f GetPosition() const {return getPosition();}
	int GetEHealth() { return hp_; }

	void Refresh(const float dt);
	void Damage(int damage);
	bool ShootReady();
};

#endif