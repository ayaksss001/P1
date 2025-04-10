#ifndef ENEMY_MANAGER_H
#define ENEMY_MANAGER_H
#include "entities.h"

extern Enemy enemy_database[MAX_ENEMY_TYPE][MAX_ENEMY_CLASS];

void AddEnemy(Enemy enemy, EnemyType type, EnemyClass class);

Enemy* GetEnemy(EnemyType type, EnemyClass class);

#endif