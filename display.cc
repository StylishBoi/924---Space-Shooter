#include "display.h"

Display::Display()
{
    font_.loadFromFile("assets\\OpenSans.ttf");;

    score_.setFont(font_);
    score_.setString("0");
    score_.setCharacterSize(50);
    score_.setFillColor(sf::Color::Green);
    score_.setPosition(170, 0);

    health_.setFont(font_);
    health_.setString("5");
    health_.setCharacterSize(50);
    health_.setFillColor(sf::Color::Red);
    health_.setPosition(160, 665);

    score_text_.setFont(font_);
    score_text_.setString("Score - ");
    score_text_.setCharacterSize(50);
    score_text_.setFillColor(sf::Color::White);
    score_text_.setPosition(0, 0);

    health_text_.setFont(font_);
    health_text_.setString("Lives - ");
    health_text_.setCharacterSize(50);
    health_text_.setFillColor(sf::Color::White);
    health_text_.setPosition(0, 665);

    T_background_.loadFromFile("assets\\PNG\\background.jpg");
    S_background_.setTexture(T_background_);
    S_background_.scale(0.8f, 0.6f);

    T_instructions.loadFromFile("assets\\PNG\\instructions_manual.png");
    S_instructions.setTexture(T_instructions);

    T_gameover.loadFromFile("assets\\PNG\\gameover.png");
    S_gameover.setTexture(T_gameover);
}