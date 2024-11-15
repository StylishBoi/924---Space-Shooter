#ifndef STARSHIP_H
#define STARSHIP_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "meteorites.h"
#include "projectile.h"
#include "enemy.h"
#include "entity.h"

const float kSpeed = 300.0f;

class Starship : public Entity
{
private:
	sf::Sprite sprite_;
	sf::Texture texture_;
	sf::FloatRect hit_box_;
	int health=5;

	bool is_dead_ = false;
	float shoot_dt_ = 0.f;
	bool is_shoot_ready_ = false;

	bool collision = false;

public:
	Starship();
	void Move(sf::Vector2f direction, float dt);

	void SetPosition(sf::Vector2u direction);
	sf::Vector2f GetPosition() const { return getPosition(); }
	int GetHealth() const { return health; }

	sf::FloatRect Hitbox() const{ return hit_box_; }
	void ShipDamage();

	void Refresh(float dt);
	bool IsShootReady() const { return is_shoot_ready_; }
	void ShootConfirm() { is_shoot_ready_ = false; }

	bool StarshipCollision() { return collision; }

	void CheckMeteoritesCollisions(std::vector<Meteorite>& meteorites_);
	void CheckProjectilesCollisions(std::vector<Projectile>& projectiles_);
	void CheckEnemiesCollisions(std::vector<Enemy>& enemies_);
	
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif
