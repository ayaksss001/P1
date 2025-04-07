#ifndef ENTITIES_H
#define ENTITIES_H

#include <stdbool.h>

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
}Player;

typedef struct
{
    Position pos;
    int health;
    char skin;
    int min_gold;
    int max_gold;
    bool isAlive;
}Enemy;

#endif 