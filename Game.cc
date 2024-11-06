#ifndef GAME_CC
#define GAME_CC

#include "Game.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <iostream>

Game::Game() {
    window_.create(sf::VideoMode(1280, 720), "Space Shooter");
}

void Game::loop() {

    float dt = 0.016f;

    while (window_.isOpen())
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            projectiles_.Spawn(starship_.GetPosition());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            starship_.Move(sf::Vector2f(0, -1), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            starship_.Move(sf::Vector2f(-1, 0), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            starship_.Move(sf::Vector2f(0, 1), dt);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            starship_.Move(sf::Vector2f(1, 0), dt);
        }

        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        projectiles_.Refresh(dt, window_.getSize());
        meteorites_.Refresh(dt, window_.getSize());

        projectiles_.CheckCollisions(meteorites_.GetEntities());

        window_.clear();
        window_.draw(projectiles_);
        window_.draw(meteorites_);
        window_.draw(starship_);
        window_.display();

        dt = clock_.restart().asSeconds();
    }
}

#endif