#include "display.h"

Display::Display()
{
    font_.loadFromFile("assets\\OpenSans.ttf");;

    score_.setFont(font_);
    score_.setString("0");
    score_.setCharacterSize(50);
    score_.setFillColor(sf::Color::White);
    score_.setPosition(0, 0);

    health_.setFont(font_);
    health_.setString("5");
    health_.setCharacterSize(50);
    health_.setFillColor(sf::Color::Red);
    health_.setPosition(0, 665);
}