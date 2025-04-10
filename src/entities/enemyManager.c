#include "enemyManager.h"
#include <string.h>

Enemy enemy_database[MAX_ENEMY_TYPE][MAX_ENEMY_CLASS];

void AddEnemy(Enemy enemy, EnemyType type, EnemyClass class)
{
    enemy_database[type][class] = enemy;
}

Enemy* GetEnemy(EnemyType type, EnemyClass class)
{
    return &enemy_database[type][class];
}