#ifndef METEORITES_MANAGER_H
#define METEORITES_MANAGER_H

#include <vector>
#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Vector2.hpp>

#include "meteorites.h"

class MeteoritesManager : public sf::Drawable
{
private:
	std::vector<Meteorite> meteorites_;
	sf::Clock timer_;
	float time_elapsed_ = 0;

public:
	void Refresh(float dt, const sf::Vector2u& window_size);
	std::vector<Meteorite>& GetEntities() { return meteorites_; };

protected:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

#endif