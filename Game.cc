#ifndef GAME_CC
#define GAME_CC

#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

constexpr float kCooldown_limit_ = 0.15f;

sf::Sound S_Projectile;
sf::Sound S_Meteorite;
sf::Sound S_Enemy;
sf::Sound S_Enemy_Hit;
sf::Sound S_Background;

Game::Game()
{
    window_.create(sf::VideoMode(1280, 720), "Space Shooter");
}

void Game::loop() {

    float dt = 0.016f;

    S_Projectile= sound_.GetSProjectile();
    S_Meteorite=sound_.GetSMeteorite();
    S_Enemy = sound_.GetSEnemy();
    S_Enemy_Hit = sound_.GetSEnemyHit();
    S_Background = sound_.GetBackground();

    //Play background music
    S_Background.play();

    while (window_.isOpen())
    {
        //Display the constant UI
        display_.UpdateHealth(starship_.GetHealth());
        display_.UpdateScore(player_projectiles_.GetScore());

        //---------CONTROLS----------

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            if (starship_.IsShootReady())
            {
                player_projectiles_.Spawn(starship_.GetPosition(), { 1500,0 });
                S_Projectile.play();
                starship_.ShootConfirm();
            }
            
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
        starship_.Refresh(dt);

        //---------COLLISIONS----------

        starship_.CheckMeteoritesCollisions(meteorites_.GetEntities());
        starship_.CheckEnemiesCollisions(enemy_manager_.GetEntities());
        starship_.CheckProjectilesCollisions(enemy_projectiles_.GetEntities());

        player_projectiles_.CheckCollisions(meteorites_.GetEntities());
        player_projectiles_.CheckCollisions(enemy_manager_.GetEntities());

        //------------SOUND EFFECTS-------

        if (player_projectiles_.GetCollision() == true) {
            S_Meteorite.play();
        }
        if (player_projectiles_.GetECollision() == true) {
            S_Enemy_Hit.play();
        }

        if (enemy.GetDeath() == true) {
            std::cout << "Hello";
            S_Enemy.play();
        }

        //---------SCREEN DRAWINGS----------

        //Game
        window_.clear();
        window_.draw(display_.GetBackground());
        window_.draw(player_projectiles_);
        window_.draw(enemy_projectiles_);
        window_.draw(meteorites_);
        window_.draw(enemy_manager_);
        window_.draw(starship_);

        //UI
        window_.draw(display_.GetScoreText());
        window_.draw(display_.GetHealthText());
        window_.draw(display_.GetHealth());
        window_.draw(display_.GetScore());

        //---------GAME OVER-------------

        if (starship_.GetHealth() <= 0) {
            starship_.SetDeath();
        }

        window_.display();

        dt = clock_.restart().asSeconds();
    }
}

#endif