#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics/Sprite.hpp>

class Entity : public sf::Drawable, protected sf::Transformable
{
protected:
	sf::Vector2f direction_;
	sf::Sprite sprite_;
	sf::FloatRect hit_box_;
	
	bool is_dead_ = false;

public:
	//Entity()
	bool IsDead() const { return is_dead_; }
	void SetDeath() { is_dead_ = true; }

	void Move(float dt, const sf::Vector2u& window_size);
	void SetPosition(float x, float y);
	void SetPosition(sf::Vector2f position);

	bool Intersects(sf::FloatRect hitBox) const;
	sf::FloatRect HitBox() { return hit_box_; };

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif