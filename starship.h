#ifndef STARSHIP_H
#define STARSHIP_H


#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Starship : public sf::Drawable, public sf::Transformable
{
private:
	sf::Sprite sprite_;
	sf::Texture texture_;

	const float kSpeed = 300.0f;

public:

	Starship();
	void Move(sf::Vector2f direction, float dt);

	void SetPosition(sf::Vector2u direction);
	sf::Vector2f GetPosition() { return getPosition(); };
	
protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

};

#endif
