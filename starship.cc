#include "starship.h"
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>

Starship::Starship()
{
	texture_.loadFromFile("assets\\PNG\\playerShip1_blue.png");
	sprite_.setTexture(texture_);
	sprite_.setRotation(90.f);
	sprite_.scale(0.5f, 1.0f);

}

void Starship::Move(sf::Vector2f direction, float dt)
{
	move(direction * kSpeed * dt);
}

void Starship::SetPosition(sf::Vector2u position)
{
	setPosition(sf::Vector2f(position));
}

void Starship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	target.draw(sprite_, states);
}