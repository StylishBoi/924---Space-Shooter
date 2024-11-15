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
sf::Sound S_Starship;
sf::Sound S_Instructions;

Game::Game()
{
    window_.create(sf::VideoMode(1280, 720), "Space Shooter");
}

void Game::instructions() {

    S_Instructions = sound_.GetInstructions();
    S_Instructions.play();

    while (window_.isOpen()) {
        window_.draw(display_.GetInstructions());
        window_.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            S_Instructions.stop();
            window_.close();
            Game game;
            game.loop();
        }
    }
        
}

void Game::loop() {

    float dt = 0.016f;

    S_Projectile = sound_.GetSProjectile();
    S_Meteorite = sound_.GetSMeteorite();
    S_Enemy = sound_.GetSEnemy();
    S_Enemy_Hit = sound_.GetSEnemyHit();
    S_Background = sound_.GetBackground();
    S_Starship = sound_.GetStarship();

    //Play background music
    S_Background.play();

    while (window_.isOpen())
    {

        if (starship_.GetHealth() > 0) {

            //---------WINDOW CLOSING----------

            sf::Event event;
            while (window_.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window_.close();
            }

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

            if (starship_.StarshipCollision() == true) {
                S_Starship.play();
            }

            if (enemy_manager_.GetEnemyDeath() == true) {
                S_Enemy.play();
            }
        }


        //Display the constant UI
        display_.UpdateHealth(starship_.GetHealth());
        display_.UpdateScore(player_projectiles_.GetScore());

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

        if (starship_.GetHealth() <= 0) {
            S_Background.stop();
            display_.GameOverScore();
            window_.draw(display_.GetGameover());
            window_.draw(display_.GetScore());
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::R) && starship_.GetHealth() <= 0) {
            window_.close();
            Game game;
            game.loop();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && starship_.GetHealth() <= 0) {
            return;
        }

        window_.display();

        dt = clock_.restart().asSeconds();
    }
}
#endif