#ifndef DISPLAY_H
#define DISPLAY_H

#include <SFML/Graphics.hpp>
#include "entity.h"
#include <iostream>

class Display
{
private:
	sf::Font font_;
	sf::Text score_;
	sf::Text health_;

public:
	Display();

	//Helps to draw the text
	sf::Text GetScore() { return score_; }
	sf::Text GetHealth() { return health_; }

	//Update the text
	void UpdateScore(int score) {
		score_.setString(std::to_string(score));
	}
	void UpdateHealth(int health) {
		health_.setString(std::to_string(health));
	}
};

#endif