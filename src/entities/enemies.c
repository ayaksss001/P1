#include "entities.h"
#include "enemyManager.h"

void InitEnemies()
{
    Enemy goblin = 
    {
        .pos = {0,0},
        .health = 3,
        .currentHealth = 3,
        .skin = 'o',
        .min_gold = 3,
        .max_gold = 6,
        .isAlive = false
    };
    
    Enemy dragon = 
    {
        .pos = {0,0},
        .health = 20,
        .currentHealth = 20,
        .skin = 'D',
        .min_gold = 30,
        .max_gold = 80,
        .isAlive = false
    }; 
    AddEnemy(goblin, GOBLIN, COMMON);
    AddEnemy(dragon, DRAGON, COMMON);
}