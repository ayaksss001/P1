#include<stdlib.h>
#include <time.h>
#include <ncurses.h>

#include "entities.h"
#include"map.h"

void battle(Player *player, Enemy *enemy, Map *map)
{
    
    if(player->checkRespawn == false && player->health > 0)
    {
        do
        {
            player->pos.y = rand() % map->height;
            player->pos.x = rand() % map->width;  
        } while (map->tiles[player->pos.y][player->pos.x] == '#' || map->tiles[player->pos.y][player->pos.x] == '*');
            player->checkRespawn = true;
        
    }
    if (player->pos.y == enemy->pos.y && player->pos.x == enemy->pos.x && enemy->isAlive == true)
        {
            if(enemy->currentHealth >= 1)
            {
            enemy->currentHealth -= player->dmg;
            }
            if(enemy->currentHealth == 0)
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
            } while (map->tiles[enemy->pos.y][enemy->pos.x] == '#' || map->tiles[enemy->pos.y][enemy->pos.x] == '*' && map->tiles[enemy->pos.y][enemy->pos.x]!= map->tiles[player->pos.y][player->pos.x]  ) ;
                
                enemy->currentHealth = enemy->health;
                enemy->isAlive = true;
        }
        mvaddch(enemy->pos.y,enemy->pos.x, enemy->skin);
}