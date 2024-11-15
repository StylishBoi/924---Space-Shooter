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

	sf::Sprite S_instructions;
	sf::Texture T_instructions;

	sf::Sprite S_gameover;
	sf::Texture T_gameover;

public:
	Display();

	//Helps to draw the text
	sf::Text GetScore() { return score_; }
	sf::Text GetHealth() { return health_; }
	sf::Text GetScoreText() { return score_text_; }
	sf::Text GetHealthText() { return health_text_; }
	sf::Sprite GetBackground() { return S_background_; }
	sf::Sprite GetInstructions() { return S_instructions; }
	sf::Sprite GetGameover() { return S_gameover; }

	//Update the text
	void UpdateScore(int score) {
		score_.setString(std::to_string(score));
	}
	void UpdateHealth(int health) {
		health_.setString(std::to_string(health));
	}
	void GameOverScore() {
		score_.setPosition(645, 442);
		score_.setOutlineThickness(4);
		score_.setOutlineColor(sf::Color::White);
		score_.setFillColor(sf::Color::Black);
		score_.Bold;
	}
};

#endif