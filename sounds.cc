#include "sounds.h"

Sound::Sound()
{
    b_projectile.loadFromFile("assets\\Audio\\laserSmall_004.OGG");
    s_projectile.setBuffer(b_projectile);

    b_meteorite.loadFromFile("assets\\Audio\\explosionCrunch_000.OGG");
    s_meteorite.setBuffer(b_meteorite);

    b_enemy.loadFromFile("assets\\Audio\\explosionCrunch_002.OGG");
    s_enemy.setBuffer(b_enemy);

    b_enemy_hit.loadFromFile("assets\\Audio\\impactMetal_004.OGG");
    s_enemy_hit.setBuffer(b_enemy_hit)
        ;
    b_background.loadFromFile("assets\\Audio\\background_music.OGG");
    s_background.setBuffer(b_background);
}