#ifndef ENTITY_CC
#define ENTITY_CC

#include "entity.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

void Entity::Move(float dt, const sf::Vector2u& window_size)
{
	setPosition(getPosition() + direction_ * dt);

	hit_box_.left = getPosition().x;
	hit_box_.top = getPosition().y;
	
	sf::Vector2f position = getPosition();
	sf::Vector2f borders = sf::Vector2f(sprite_.getGlobalBounds().width / 2, sprite_.getGlobalBounds().height / 2);

	if (position.x<-1 * borders.x ||
		position.x>window_size.x + borders.x ||
		position.y<-1 * borders.y ||
		position.y>window_size.y + borders.y)
	{
		is_dead_ = true;
	}
}

void Entity::SetPosition(float x, float y)
{
	setPosition(x, y);
}

void Entity::SetPosition(sf::Vector2f position)
{
	setPosition(position.x, position.y);
}

bool Entity::Intersects(sf::FloatRect hitBox) const
{
	return hit_box_.intersects(hitBox);
}

void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}

#endif