#ifndef ENTITIES_H
#define ENTITIES_H

#include <stdbool.h>

#define MAX_ENEMY_TYPE 3
#define MAX_ENEMY_CLASS 3

typedef enum 
{
    GOBLIN,
    DRAGON,
    SLIME
}EnemyType;

typedef enum 
{
    COMMON,
    ELITE,
    EPIC
}EnemyClass;

typedef struct{
    int y;
    int x;
    
}Position;

typedef struct
{
    Position pos;
    int bank;
    int health;
    int dmg;
    char skin;
    bool isAlive;
    bool checkRespawn;
}Player;

typedef struct
{
    Position pos;
    int health;
    int currentHealth;
    char skin;
    int min_gold;
    int max_gold;
    bool isAlive;
}Enemy;

#endif 