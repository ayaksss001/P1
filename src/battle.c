#include<stdlib.h>
#include <time.h>
#include <ncurses.h>

#include "entities.h"
#include"map.h"

void battle(Player *player, Enemy *enemy, Map *map)
{
    srand(time(NULL));
    if (player->pos.y == enemy->pos.y && player->pos.x == enemy->pos.x && enemy->isAlive == true)
        {
            enemy->health -= player->dmg;
            if(enemy->health < 0)
            {
                enemy->isAlive = false;
                player->bank += rand() % enemy->max_gold + enemy->min_gold; 
            }
            
        }
        if(!enemy->isAlive)
        {
            do
            {
                enemy->pos.y = rand() % map->height;
                enemy->pos.x = rand() % map->width;
            } while (map->tiles[enemy->pos.y][enemy->pos.x] == '#' || map->tiles[enemy->pos.y][enemy->pos.x] == '*');
                enemy->isAlive = true;
        }
        mvaddch(enemy->pos.y,enemy->pos.x, enemy->skin);
}