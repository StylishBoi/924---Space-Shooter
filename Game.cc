#ifndef GAME_CC
#define GAME_CC

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

constexpr float kCooldown_limit_ = 0.15f;

sf::Sprite S_background_;
sf::Texture T_background_;

Game::Game()
{
    window_.create(sf::VideoMode(1280, 720), "Space Shooter");
    T_background_.loadFromFile("assets\\PNG\\background.jpg");
    S_background_.setTexture(T_background_);
    S_background_.scale(0.8f, 0.6f);
}

void Game::loop() {

    float dt = 0.016f;

    while (window_.isOpen())
    {

        display_.UpdateHealth(starship_.GetHealth());
        display_.UpdateScore(player_projectiles_.GetScore());

        //---------CONTROLS----------

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            player_projectiles_.Spawn(starship_.GetPosition(),{1500,0});
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

        //---------WINDOW CLOSING----------

        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window_.close();
        }

        //---------REFRESH----------

        player_projectiles_.Refresh(dt, window_.getSize());
        meteorites_.Refresh(dt, window_.getSize());
        enemy_projectiles_.Refresh(dt, window_.getSize());
        enemy_manager_.Refresh(dt, window_.getSize(), enemy_projectiles_);

        //---------COLLISIONS----------

        starship_.CheckMeteoritesCollisions(meteorites_.GetEntities());
        starship_.CheckEnemiesCollisions(enemy_manager_.GetEntities());
        starship_.CheckProjectilesCollisions(enemy_projectiles_.GetEntities());

        player_projectiles_.CheckCollisions(meteorites_.GetEntities());
        player_projectiles_.CheckCollisions(enemy_manager_.GetEntities());

        //---------SCREEN DRAWINGS----------

        window_.clear();
        window_.draw(S_background_);
        window_.draw(player_projectiles_);
        window_.draw(enemy_projectiles_);
        window_.draw(meteorites_);
        window_.draw(enemy_manager_);
        window_.draw(starship_);

        window_.draw(display_.GetHealth());
        window_.draw(display_.GetScore());

        window_.display();

        dt = clock_.restart().asSeconds();
    }
}

#endif


/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    menu_.MoveUp();
    break;
}

if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    menu_.MoveDown();
    break;
}*/