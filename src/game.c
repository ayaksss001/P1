#include <stdio.h>//printf(),getchar()
#include<stdlib.h>
#include <time.h>
#include<stdbool.h>
#include <ncurses.h>

#include "game.h"
#include "ui.h"
#include "entities.h"
#include "battle.h"
#include "map.h"

int dungeon(Map *map, Enemy *goblin, Player *player)
{
    drawBorder(map);
    

    for(int height = 0 ; height <= map->height - 1; height++)
        {
            for(int width = 0 ; width <= map->width - 1; width++)
            {
                if(map->tiles[height][width] != '#')
                {
                    map->tiles[height][width] = '*';
                    mvaddch(height, width,'*');
                }
            }
        }
            
        for(int height = 11 ; height <= map->height / 2; height++)
        {
            for(int width = 11 ; width <= map->width / 2 ; width++)
            {
                map->tiles[height][width] = ' ';
                mvaddch(height, width,' ');
            }
        }
    
        battle(player, goblin, map);
        mvaddch(player->pos.y,player->pos.x, '@');
        draw_ui_window(0, 0, 10, 16);
        mvprintw(1,2,"Gold : %d", player->bank);
        draw_ui_window(0 ,map->width - 30, 6, 30);
        mvprintw(1,map->width - 28,"Hp : %d", goblin->health);
}

void move_player(int c, Player *player, Map *map)
{
        if(c == KEY_UP && map->tiles[player->pos.y - 1][player->pos.x] == ' ') player->pos.y--;
        else if(c == KEY_DOWN && map->tiles[player->pos.y + 1][player->pos.x] == ' ') player->pos.y++;
        else if(c == KEY_LEFT && map->tiles[player->pos.y][player->pos.x - 1] == ' ') player->pos.x--;
        else if(c == KEY_RIGHT && map->tiles[player->pos.y][player->pos.x + 1] == ' ') player->pos.x++;
}

int gameLoop()   
{   
    int max_height , max_width;
    int c;
    Player player = 
    {
        .pos = {14, 14},
        .health = 3,
        .dmg = 1,
        .bank = 0,
        .skin = '@',
        .isAlive = true
        
    };
    
    Enemy goblin = 
    {
        .pos = {0,0},
        .health = 3,
        .skin = 'o',
        .min_gold = 3,
        .max_gold = 6,
        .isAlive = false
    };

    Enemy dragon = 
    {
        .pos = {0,0},
        .health = 20,
        .skin = 'D',
        .min_gold = 30,
        .max_gold = 80,
        .isAlive = false
    };
    initscr();
    keypad(stdscr,1);//allow arrows
    noecho();//don't display input
    curs_set(0);//hide cursur
    
    getmaxyx(stdscr, max_height, max_width);
    srand(time(NULL));
    Map map = createMap(max_height, max_width);
    
do
{
    dungeon(&map, &goblin, &player);  
    refresh();
    c = getch();
    move_player(c, &player, &map);
    
}
 while (c != 27);// 27 - ESC

    freeMap(&map);

    endwin();
    return 0;
}