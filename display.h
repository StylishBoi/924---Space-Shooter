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
	sf::Text score_text_;
	sf::Text health_text_;

	sf::Sprite S_background_;
	sf::Texture T_background_;

public:
	Display();

	//Helps to draw the text
	sf::Text GetScore() { return score_; }
	sf::Text GetHealth() { return health_; }
	sf::Text GetScoreText() { return score_text_; }
	sf::Text GetHealthText() { return health_text_; }
	sf::Sprite GetBackground() { return S_background_; }

	//Update the text
	void UpdateScore(int score) {
		score_.setString(std::to_string(score));
	}
	void UpdateHealth(int health) {
		health_.setString(std::to_string(health));
	}
};

#endif