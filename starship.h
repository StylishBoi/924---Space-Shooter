#ifndef STARSHIP_H
#define STARSHIP_H

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

#include "meteorites.h"
#include "projectile.h"
#include "enemy.h"

const float kSpeed = 300.0f;

class Starship : public sf::Drawable, private sf::Transformable
{
private:
	sf::Sprite sprite_;
	sf::Texture texture_;
	sf::FloatRect hit_box_;

public:
	Starship();
	void Move(sf::Vector2f direction, float dt);

	void SetPosition(sf::Vector2u direction);
	sf::Vector2f GetPosition() const { return getPosition(); }

	sf::FloatRect Hitbox() const{ return hit_box_; }
	void CheckMeteoritesCollisions(std::vector<Meteorite>& meteorites_);
	void CheckProjectilesCollisions(std::vector<Projectile>& projectiles_);
	void CheckEnemiesCollisions(std::vector<Enemy>& enemies_);
	
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif
