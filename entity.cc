#ifndef ENTITY_CC
#define ENTITY_CC

#include "entity.h"

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>

void Entity::Move(float dt, const sf::Vector2u& window_size)
{
	setPosition(getPosition() + direction_ * dt);

	hit_box_ = sprite_.getGlobalBounds();
	hit_box_.left += getPosition().x;
	hit_box_.top += getPosition().y;
	
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
	hit_box_.width = (float)sprite_.getTextureRect().width * getScale().x;
	hit_box_.height = (float)sprite_.getTextureRect().height * getScale().y;
}

void Entity::SetPosition(sf::Vector2f position)
{
	setPosition(position.x, position.y);
	hit_box_.width = (float)sprite_.getTextureRect().width * getScale().x;
	hit_box_.height = (float)sprite_.getTextureRect().height * getScale().y;
}

bool Entity::Intersects(sf::FloatRect hitbox) const
{
	return hit_box_.intersects(hitbox);
}



void Entity::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}

#endif